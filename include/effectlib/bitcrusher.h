#ifndef BITCRUSHER_H
#define BITCRUSHER_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for bitcrusher effect */
typedef struct {
    int bits;
} bitcrusher_params_t;

/** Parses command line options for bitcrusher effect, non-zero return indicates parse error. */
int manyfx_parse_bitcrusher_params(
    int argc,
    char** argv,
    bitcrusher_params_t* params
);

/** Applies the bitcrusher effect */
void manyfx_apply_bitcrusher(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    bitcrusher_params_t* params
);


#endif