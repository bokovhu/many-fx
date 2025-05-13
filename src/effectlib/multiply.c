#include "effectlib/multiply.h"

/** Parses command line options for multiply effect, non-zero return indicates parse error. */
int manyfx_parse_multiply_params(
    int argc,
    char** argv,
    multiply_params_t* params
) {
    params->scale = 0.0;

    /* Look for --scale <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--scale") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --scale requires a float argument\n");
                return 1;
            }
            params->scale = atof(argv[i + 1]);
            i++;
        }
    }

    return 0;
}

/** Applies the multiply effect */
void manyfx_apply_multiply(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    multiply_params_t* params
) {
    #pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  audio_out->left_data[i] = audio_in->left_data[i] * params->scale;
  audio_out->right_data[i] = audio_in->right_data[i] * params->scale;
}

}