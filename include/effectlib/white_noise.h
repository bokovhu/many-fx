#ifndef WHITE_NOISE_H
#define WHITE_NOISE_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for white-noise effect */
typedef struct {
    float mix;
} white_noise_params_t;

/** Parses command line options for white-noise effect, non-zero return indicates parse error. */
int manyfx_parse_white_noise_params(
    int argc,
    char** argv,
    white_noise_params_t* params
);

/** Applies the white-noise effect */
void manyfx_apply_white_noise(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    white_noise_params_t* params
);


#endif