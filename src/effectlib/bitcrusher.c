#include "effectlib/bitcrusher.h"

/** Parses command line options for bitcrusher effect, non-zero return indicates parse error. */
int manyfx_parse_bitcrusher_params(
    int argc,
    char** argv,
    bitcrusher_params_t* params
) {
    params->bits = 0;

    /* Look for --bits <int> */
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "--bits") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: --bits requires an int argument\n");
                return 1;
            }
            params->bits = atoi(argv[i + 1]);
            i++;
        }
    }

    return 0;
}

/** Applies the bitcrusher effect */
void manyfx_apply_bitcrusher(
    sound_file_44k_stereo_t* audio_in,
    sound_file_44k_stereo_t* audio_out,
    bitcrusher_params_t* params
) {
    float max_val = (1 << (params->bits - 1)) - 1;
float scale = max_val;
#pragma omp parallel for
for(unsigned int i = 0; i < audio_in->sample_count; i++) {
  audio_out->left_data[i] = roundf(audio_in->left_data[i] * scale) / scale;
  audio_out->right_data[i] = roundf(audio_in->right_data[i] * scale) / scale;
}

}