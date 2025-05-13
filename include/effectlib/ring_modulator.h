#ifndef RING_MODULATOR_H
#define RING_MODULATOR_H

#include "preprocess/preprocess.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/** Parameters for ring-modulator effect */
typedef struct {
    float freq;
    float mix;
} ring_modulator_params_t;

/** Parses command line options for ring-modulator effect, non-zero return indicates parse error. */
int manyfx_parse_ring_modulator_params(
    int argc,
    char** argv,
    ring_modulator_params_t* params
);

/** Applies the ring-modulator effect */
void manyfx_apply_ring_modulator(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    ring_modulator_params_t* params
);


#endif