#include "effectlib/tremolo.h"

/** Parses command line options for tremolo effect, non-zero return indicates parse error. */
int manyfx_parse_tremolo_params(
    int argc,
    char** argv,
    tremolo_params_t* params
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
    params->depth = 0.0;

    /* Look for --depth <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--depth") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --depth requires a float argument\n");
                return 1;
            }
            params->depth = atof(argv[i + 1]);
            i++;
        }
    }

    return 0;
}

/** Applies the tremolo effect */
void manyfx_apply_tremolo(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    tremolo_params_t* params
) {
    float freq = params->freq;
// Sample rate is constant 44.1 kHz
#pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  float mod = 1.0 - params->depth * (0.5 + 0.5 * sinf(2.0 * 3.141592 * freq * i / 44100.0));
  audio_out->left_data[i] = audio_in->left_data[i] * mod;
  audio_out->right_data[i] = audio_in->right_data[i] * mod;
}

}