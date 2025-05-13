#include "preprocess/preprocess.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sound_file_44k_stereo_t *manyfx_preprocess_wav_44k_stereo(
    const char *wav_file_path)
{
    FILE *file = fopen(wav_file_path, "rb");
    if (!file) {
        printf("Failed to open WAV file: %s\n", wav_file_path);
        return NULL;
    }

    // Read WAV header
    char header[44];
    if (fread(header, sizeof(char), 44, file) != 44) {
        printf("Failed to read WAV header: %s\n", wav_file_path);
        fclose(file);
        return NULL;
    }

    // Check if WAV file is PCM
    if (header[20] != 1) {
        printf("Unsupported WAV format: %s\n", wav_file_path);
        fclose(file);
        return NULL;
    }

    // Check if WAV file is mono or stereo
    int channels = header[22];
    if (channels != 1 && channels != 2) {
        printf("Unsupported WAV channels: %s\n", wav_file_path);
        fclose(file);
        return NULL;
    }

    // Read WAV data
    int sample_count = *(int *)(header + 40) / sizeof(float) / channels;
    float *data = malloc(sample_count * sizeof(float) * channels);
    if (fread(data, sizeof(float), sample_count * channels, file) != sample_count * channels) {
        printf("Failed to read WAV data: %s\n", wav_file_path);
        free(data);
        fclose(file);
        return NULL;
    }

    fclose(file);

    // Create sound file
    sound_file_44k_stereo_t *result = malloc(sizeof(sound_file_44k_stereo_t));
    result->sample_count = sample_count;
    if (channels == 1) {
        // Convert mono to stereo
        result->left_data = data;
        result->right_data = malloc(sample_count * sizeof(float));
        memcpy(result->right_data, data, sample_count * sizeof(float));
    } else {
        // Split stereo
        result->left_data = malloc(sample_count * sizeof(float));
        result->right_data = malloc(sample_count * sizeof(float));
        for (int i = 0; i < sample_count; i++) {
            result->left_data[i] = data[i * 2];
            result->right_data[i] = data[i * 2 + 1];
        }
        free(data);
    }

    printf("Loaded WAV file: %s\n", wav_file_path);

    return result;
}

sound_file_44k_stereo_t *manyfx_clone_44k_stereo(
    const sound_file_44k_stereo_t *sound_file)
{
    sound_file_44k_stereo_t *result = malloc(sizeof(sound_file_44k_stereo_t));

    result->left_data = malloc(sound_file->sample_count * sizeof(float));
    result->right_data = malloc(sound_file->sample_count * sizeof(float));
    result->sample_count = sound_file->sample_count;

    memcpy(result->left_data, sound_file->left_data, sound_file->sample_count * sizeof(float));
    memcpy(result->right_data, sound_file->right_data, sound_file->sample_count * sizeof(float));

    return result;
}