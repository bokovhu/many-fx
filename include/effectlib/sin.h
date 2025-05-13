#ifndef SIN_H
#define SIN_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for sin effect */
typedef struct {
    float freq;
    float amp;
} sin_params_t;

/** Parses command line options for sin effect, non-zero return indicates parse error. */
int manyfx_parse_sin_params(
    int argc,
    char** argv,
    sin_params_t* params
);

/** Applies the sin effect */
void manyfx_apply_sin(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    sin_params_t* params
);


#endif