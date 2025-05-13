#include "wavwrite/wavwrite.h"

#include <stdio.h>

float clip(float v) {
    if (v < -1.0f) {
        return -1.0f;
    }
    if (v > 1.0f) {
        return 1.0f;
    }
    return v;
}

void manyfx_write_wav_44k_stereo(
    sound_file_44k_stereo_t *audio,
    const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file for writing: %s\n", filename);
        return;
    }

    // Write the RIFF header
    fwrite("RIFF", 1, 4, file);
    unsigned int fileSize = 44 + audio->sample_count * 4; // 44 for header, 4 bytes per sample
    fwrite(&fileSize, 4, 1, file);
    fwrite("WAVE", 1, 4, file);

    // Write the fmt subchunk
    fwrite("fmt ", 1, 4, file);
    unsigned int fmtChunkSize = 16; // for PCM
    fwrite(&fmtChunkSize, 4, 1, file);
    unsigned short audioFormat = 1; // for PCM
    fwrite(&audioFormat, 2, 1, file);
    unsigned short numChannels = 2; // stereo
    fwrite(&numChannels, 2, 1, file);
    unsigned int sampleRate = 44100; // 44.1kHz
    fwrite(&sampleRate, 4, 1, file);
    unsigned int byteRate = sampleRate * numChannels * 2; // SampleRate * NumChannels * BitsPerSample/8
    fwrite(&byteRate, 4, 1, file);
    unsigned short blockAlign = numChannels * 2; // NumChannels * BitsPerSample/8
    fwrite(&blockAlign, 2, 1, file);
    unsigned short bitsPerSample = 16; // 16 bits per sample
    fwrite(&bitsPerSample, 2, 1, file);

    // Write the data subchunk
    fwrite("data", 1, 4, file);
    unsigned int dataChunkSize = audio->sample_count * numChannels * 2; // NumSamples * NumChannels * BitsPerSample/8
    fwrite(&dataChunkSize, 4, 1, file);

    // Write the audio data
    for (unsigned int i = 0; i < audio->sample_count; i++) {
        short leftSample = clip(audio->left_data[i]) * 32767; // convert from float [-1, 1] to 16-bit PCM
        fwrite(&leftSample, 2, 1, file);
        short rightSample = clip(audio->right_data[i]) * 32767; // convert from float [-1, 1] to 16-bit PCM
        fwrite(&rightSample, 2, 1, file);
    }

    fclose(file);
    printf("Wrote WAV file: %s\n", filename);
}