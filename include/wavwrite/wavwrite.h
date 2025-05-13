#ifndef WAVWRITE_H
#define WAVWRITE_H

#include "preprocess/preprocess.h"

void manyfx_write_wav_44k_stereo(
    sound_file_44k_stereo_t* audio,
    const char* filename
);

#endif