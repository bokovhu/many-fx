#include "effectlib/ring_modulator.h"

/** Parses command line options for ring-modulator effect, non-zero return indicates parse error. */
int manyfx_parse_ring_modulator_params(
    int argc,
    char** argv,
    ring_modulator_params_t* params
) {
    params->freq = 0.0;

    /* Look for --freq <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--freq") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --freq requires a float argument\n");
                return 1;
            }
            params->freq = atof(argv[i + 1]);
            i++;
        }
    }
    params->mix = 0.0;

    /* Look for --mix <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--mix") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --mix requires a float argument\n");
                return 1;
            }
            params->mix = atof(argv[i + 1]);
            i++;
        }
    }

    return 0;
}

/** Applies the ring-modulator effect */
void manyfx_apply_ring_modulator(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    ring_modulator_params_t* params
) {
    float freq = params->freq;
// Sample rate is constant 44.1 kHz
#pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  float carrier = sinf(2.0 * 3.141592 * freq * i / 44100.0);
  audio_out->left_data[i] = audio_in->left_data[i] * (1.0 - params->mix) + 
                           audio_in->left_data[i] * carrier * params->mix;
  audio_out->right_data[i] = audio_in->right_data[i] * (1.0 - params->mix) + 
                            audio_in->right_data[i] * carrier * params->mix;
}

}