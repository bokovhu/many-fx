#include "effectlib/sin.h"

/** Parses command line options for sin effect, non-zero return indicates parse error. */
int manyfx_parse_sin_params(
    int argc,
    char** argv,
    sin_params_t* params
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
    params->amp = 0.0;

    /* Look for --amp <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--amp") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --amp requires a float argument\n");
                return 1;
            }
            params->amp = atof(argv[i + 1]);
            i++;
        }
    }

    return 0;
}

/** Applies the sin effect */
void manyfx_apply_sin(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    sin_params_t* params
) {
    float freq = params->freq;
// Sample rate is constant 44.1 kHz
#pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  audio_out->left_data[i] = audio_in->left_data[i] + params->amp * sinf(2.0 * 3.141592 * freq * i / 44100.0);
  audio_out->right_data[i] = audio_in->right_data[i] + params->amp * sinf(2.0 * 3.141592 * freq * i / 44100.0);
}

}