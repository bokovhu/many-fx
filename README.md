# Many-FX

This repository contains many simple CLI programs, written in ANSI C, that implement a single audio effect. When you run the CLI, it will read a `.wav` file, apply the effect in memory, and write the result to a new `.wav` file.

For example, the `mfx-multiply` can be used like this to scale the signal strength with a constant:

```
$ ls -la
-rw-r--r-- 1 user user  44K Jan  1  1970 input.wav
$ mfx-multiply input.wav output.wav --scale 0.25
$ ls -la
-rw-r--r-- 1 user user  44K Jan  1  1970 input.wav
-rw-r--r-- 1 user user  44K Jan  1  1970 output.wav
```

## Building

Just run `make` (or `mingw32-make`) in the root directory. This will build all the effects and put them in the `dist` directory.

## Supported effects

### **multiply**

Multiplies the audio signal by a constant

Parameters:

```
--scale <float> - The scale factor | default: 0.0
```

### **white-noise**

Mixes the audio signal with a random white noise

Parameters:

```
--mix <float> - The mix factor | default: 0.0
```

### **sin**

Mixes the audio signal with a sine wave

Parameters:

```
--freq <float> - The frequency of the sine wave | default: 0.0
--amp <float> - The amplitude of the sine wave | default: 0.0
```

### **simple-delay**

Adds a simple delay to the audio signal

Parameters:

```
--delay <float> - The delay in seconds | default: 0.0
--amp <float> - The amplitude of the delayed signal | default: 0.0
```

### **tremolo**

Applies a tremolo effect (amplitude modulation)

Parameters:

```
--freq <float> - The frequency of the tremolo | default: 0.0
--depth <float> - The depth of the tremolo (0-1) | default: 0.0
```

### **bitcrusher**

Reduces the bit depth of the audio signal

Parameters:

```
--bits <int> - The number of bits to use (1-16) | default: 0
```

### **ring-modulator**

Applies ring modulation to the audio signal

Parameters:

```
--freq <float> - The frequency of the carrier wave | default: 0.0
--mix <float> - The mix factor (0-1) | default: 0.0
```


## License

This project is licensed under the [MIT license](LICENSE).

This project uses [ProJor](https://projor.io) to generate the code. ProJor is [licensed](https://license.projor.io) under the **ProJor Free License**, or the **ProJor Commercial License**.