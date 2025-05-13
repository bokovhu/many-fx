#ifndef SIMPLE_DELAY_H
#define SIMPLE_DELAY_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for simple-delay effect */
typedef struct {
    float delay;
    float amp;
} simple_delay_params_t;

/** Parses command line options for simple-delay effect, non-zero return indicates parse error. */
int manyfx_parse_simple_delay_params(
    int argc,
    char** argv,
    simple_delay_params_t* params
);

/** Applies the simple-delay effect */
void manyfx_apply_simple_delay(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    simple_delay_params_t* params
);


#endif