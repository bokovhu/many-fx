.RECIPEPREFIX = >
CC = gcc
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LDFLAGS = -lm -lgomp
    EXE_EXT =
else
    LDFLAGS = -lgomp
    EXE_EXT = .exe
endif
CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude -fopenmp
all : cli-binaries
>   echo "Full build complete."

cli-binaries : dist/multiply dist/white-noise dist/sin dist/simple-delay dist/tremolo dist/bitcrusher dist/ring-modulator
>   echo "Built CLI binaries."

dist/multiply : build/cli/multiply/multiply$(EXE_EXT) dist
>   cp build/cli/multiply/multiply$(EXE_EXT) dist/multiply$(EXE_EXT)

build/cli/multiply/multiply$(EXE_EXT) : src/cli/multiply/main.c build/cli/multiply build/effectlib/multiply.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/multiply/main.c build/effectlib/multiply.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/multiply/multiply$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/multiply.o : src/effectlib/multiply.c build/effectlib
>   $(CC) -c src/effectlib/multiply.c -o build/effectlib/multiply.o $(CFLAGS)

build/cli/multiply :
>   mkdir -p build/cli/multiply

dist/white-noise : build/cli/white_noise/white-noise$(EXE_EXT) dist
>   cp build/cli/white_noise/white-noise$(EXE_EXT) dist/white-noise$(EXE_EXT)

build/cli/white_noise/white-noise$(EXE_EXT) : src/cli/white_noise/main.c build/cli/white_noise build/effectlib/white_noise.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/white_noise/main.c build/effectlib/white_noise.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/white_noise/white-noise$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/white_noise.o : src/effectlib/white_noise.c build/effectlib
>   $(CC) -c src/effectlib/white_noise.c -o build/effectlib/white_noise.o $(CFLAGS)

build/cli/white_noise :
>   mkdir -p build/cli/white_noise

dist/sin : build/cli/sin/sin$(EXE_EXT) dist
>   cp build/cli/sin/sin$(EXE_EXT) dist/sin$(EXE_EXT)

build/cli/sin/sin$(EXE_EXT) : src/cli/sin/main.c build/cli/sin build/effectlib/sin.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/sin/main.c build/effectlib/sin.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/sin/sin$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/sin.o : src/effectlib/sin.c build/effectlib
>   $(CC) -c src/effectlib/sin.c -o build/effectlib/sin.o $(CFLAGS)

build/cli/sin :
>   mkdir -p build/cli/sin

dist/simple-delay : build/cli/simple_delay/simple-delay$(EXE_EXT) dist
>   cp build/cli/simple_delay/simple-delay$(EXE_EXT) dist/simple-delay$(EXE_EXT)

build/cli/simple_delay/simple-delay$(EXE_EXT) : src/cli/simple_delay/main.c build/cli/simple_delay build/effectlib/simple_delay.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/simple_delay/main.c build/effectlib/simple_delay.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/simple_delay/simple-delay$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/simple_delay.o : src/effectlib/simple_delay.c build/effectlib
>   $(CC) -c src/effectlib/simple_delay.c -o build/effectlib/simple_delay.o $(CFLAGS)

build/cli/simple_delay :
>   mkdir -p build/cli/simple_delay

dist/tremolo : build/cli/tremolo/tremolo$(EXE_EXT) dist
>   cp build/cli/tremolo/tremolo$(EXE_EXT) dist/tremolo$(EXE_EXT)

build/cli/tremolo/tremolo$(EXE_EXT) : src/cli/tremolo/main.c build/cli/tremolo build/effectlib/tremolo.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/tremolo/main.c build/effectlib/tremolo.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/tremolo/tremolo$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/tremolo.o : src/effectlib/tremolo.c build/effectlib
>   $(CC) -c src/effectlib/tremolo.c -o build/effectlib/tremolo.o $(CFLAGS)

build/cli/tremolo :
>   mkdir -p build/cli/tremolo

dist/bitcrusher : build/cli/bitcrusher/bitcrusher$(EXE_EXT) dist
>   cp build/cli/bitcrusher/bitcrusher$(EXE_EXT) dist/bitcrusher$(EXE_EXT)

build/cli/bitcrusher/bitcrusher$(EXE_EXT) : src/cli/bitcrusher/main.c build/cli/bitcrusher build/effectlib/bitcrusher.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/bitcrusher/main.c build/effectlib/bitcrusher.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/bitcrusher/bitcrusher$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/bitcrusher.o : src/effectlib/bitcrusher.c build/effectlib
>   $(CC) -c src/effectlib/bitcrusher.c -o build/effectlib/bitcrusher.o $(CFLAGS)

build/cli/bitcrusher :
>   mkdir -p build/cli/bitcrusher

dist/ring-modulator : build/cli/ring_modulator/ring-modulator$(EXE_EXT) dist
>   cp build/cli/ring_modulator/ring-modulator$(EXE_EXT) dist/ring-modulator$(EXE_EXT)

build/cli/ring_modulator/ring-modulator$(EXE_EXT) : src/cli/ring_modulator/main.c build/cli/ring_modulator build/effectlib/ring_modulator.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o
>   $(CC) src/cli/ring_modulator/main.c build/effectlib/ring_modulator.o build/preprocess/preprocess.o build/wavwrite/wavwrite.o -o build/cli/ring_modulator/ring-modulator$(EXE_EXT) $(CFLAGS) $(LDFLAGS)

build/effectlib/ring_modulator.o : src/effectlib/ring_modulator.c build/effectlib
>   $(CC) -c src/effectlib/ring_modulator.c -o build/effectlib/ring_modulator.o $(CFLAGS)

build/cli/ring_modulator :
>   mkdir -p build/cli/ring_modulator

build/preprocess/preprocess.o : src/preprocess/preprocess.c build/preprocess
>   $(CC) -c src/preprocess/preprocess.c -o build/preprocess/preprocess.o $(CFLAGS)

build/wavwrite/wavwrite.o : src/wavwrite/wavwrite.c build/wavwrite
>   $(CC) -c src/wavwrite/wavwrite.c -o build/wavwrite/wavwrite.o $(CFLAGS)

build/effectlib :
>   mkdir -p build/effectlib

build/preprocess :
>   mkdir -p build/preprocess

build/wavwrite :
>   mkdir -p build/wavwrite

dist :
>   mkdir -p dist