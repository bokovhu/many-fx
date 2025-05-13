#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for multiply effect */
typedef struct {
    float scale;
} multiply_params_t;

/** Parses command line options for multiply effect, non-zero return indicates parse error. */
int manyfx_parse_multiply_params(
    int argc,
    char** argv,
    multiply_params_t* params
);

/** Applies the multiply effect */
void manyfx_apply_multiply(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    multiply_params_t* params
);


#endif