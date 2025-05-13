#ifndef PREPROCESS_H
#define PREPROCESS_H

/** Pre-processed audio data for Many FX effect functions. Always 44.1kHz, PCM 32-bit signed float, stereo. */
typedef struct sound_file_44k_stereo_t {
    float* left_data;
    float* right_data;
    unsigned int sample_count;
} sound_file_44k_stereo_t;

/** Loads a WAV file, and converts it into the appropriate format via up/downsampling, optional mono->stereo conversion, and data type conversion. */
sound_file_44k_stereo_t* manyfx_preprocess_wav_44k_stereo(
    const char* wav_file_path
);

/** Clones a sound file. */
sound_file_44k_stereo_t* manyfx_clone_44k_stereo(
    const sound_file_44k_stereo_t* sound_file
);

#endif