#ifndef TREMOLO_H
#define TREMOLO_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for tremolo effect */
typedef struct {
    float freq;
    float depth;
} tremolo_params_t;

/** Parses command line options for tremolo effect, non-zero return indicates parse error. */
int manyfx_parse_tremolo_params(
    int argc,
    char** argv,
    tremolo_params_t* params
);

/** Applies the tremolo effect */
void manyfx_apply_tremolo(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    tremolo_params_t* params
);


#endif