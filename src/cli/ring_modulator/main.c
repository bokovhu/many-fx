#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "effectlib/ring_modulator.h"
#include "preprocess/preprocess.h"
#include "wavwrite/wavwrite.h"

/* TODO */

void print_usage() {
    printf("Usage: ring-modulator <input.wav> <output.wav> [options]\n\n");
    printf("Applies ring modulation to the audio signal\n\n");
    printf("Options:\n");
    printf("  -h, --help, -?, --?  Show this help message and exit\n");
    printf("  --freq <float> - The frequency of the carrier wave | default: 0.0\n");
    printf("  --mix <float> - The mix factor (0-1) | default: 0.0\n");
}

int main(
    int argc,
    char** argv
) {
    char* input_file = NULL;
    char* output_file = NULL;

    /* Look for -h or --help or -? or --? */
    for(int i = 1; i < argc; i++) {
        if(
            strcmp(argv[i], "-h") == 0 ||
            strcmp(argv[i], "--help") == 0 ||
            strcmp(argv[i], "-?") == 0 ||
            strcmp(argv[i], "--?") == 0
        ) {
            print_usage();
            return 0;
        }
    }

    /* Find input and output files */
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-') {  // Not an option
            // Check if this is a parameter value
            if(i > 1 && argv[i-1][0] == '-' && argv[i-1][1] == '-') {
                // This is a parameter value, skip it
                continue;
            }
            // This is a file argument
            if(input_file == NULL) {
                input_file = argv[i];
            } else if(output_file == NULL) {
                output_file = argv[i];
            }
        }
    }

    /* Validate we have both input and output files */
    if(input_file == NULL || output_file == NULL) {
        printf("Error: Both input and output WAV files must be specified\n\n");
        print_usage();
        return 1;
    }

    // Seed the random generator with the current time
    srand(time(NULL));

    sound_file_44k_stereo_t* audio_in = manyfx_preprocess_wav_44k_stereo(input_file);
    if(audio_in == NULL) {
        printf("Error: Failed to open input WAV file: %s\n", input_file);
        return 1;
    }
    sound_file_44k_stereo_t* audio_out = manyfx_clone_44k_stereo(audio_in);

    ring_modulator_params_t fx_params;
    int parse_result = manyfx_parse_ring_modulator_params(
        argc,
        argv,
        &fx_params
    );
    if(parse_result != 0) {
        return parse_result;
    }
    manyfx_apply_ring_modulator(
        audio_in,
        audio_out,
        &fx_params
    );

    manyfx_write_wav_44k_stereo(audio_out, output_file);

    return 0;
}