#include "effectlib/simple_delay.h"

/** Parses command line options for simple-delay effect, non-zero return indicates parse error. */
int manyfx_parse_simple_delay_params(
    int argc,
    char** argv,
    simple_delay_params_t* params
) {
    params->delay = 0.0;

    /* Look for --delay <float> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--delay") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --delay requires a float argument\n");
                return 1;
            }
            params->delay = atof(argv[i + 1]);
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

/** Applies the simple-delay effect */
void manyfx_apply_simple_delay(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    simple_delay_params_t* params
) {
    // Sample rate is constant 44.1 kHz
unsigned int delay = (unsigned int)(params->delay * 44100.0);
#pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  if(i < delay) {
    audio_out->left_data[i] = audio_in->left_data[i];
    audio_out->right_data[i] = audio_in->right_data[i];
  } else {
    audio_out->left_data[i] = audio_in->left_data[i] + audio_in->left_data[i - delay] * params->amp;
    audio_out->right_data[i] = audio_in->right_data[i] + audio_in->right_data[i - delay] * params->amp;
  }
}

}