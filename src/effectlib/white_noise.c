#include "effectlib/white_noise.h"

/** Parses command line options for white-noise effect, non-zero return indicates parse error. */
int manyfx_parse_white_noise_params(
    int argc,
    char** argv,
    white_noise_params_t* params
) {
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

/** Applies the white-noise effect */
void manyfx_apply_white_noise(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    white_noise_params_t* params
) {
    #pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  audio_out->left_data[i] = audio_in->left_data[i] * (1.0 - params->mix) + (rand() / (float)RAND_MAX) * params->mix;
  audio_out->right_data[i] = audio_in->right_data[i] * (1.0 - params->mix) + (rand() / (float)RAND_MAX) * params->mix;
}

}