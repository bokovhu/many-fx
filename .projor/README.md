# Many-FX Software Model

This project uses [ProJor](https://projor.io) to render boilerplate code.

## Schemas

* EffectParameter - a parameter of an audio effect
* Effect - an implemented audio effect

## Data Collections

* Effects - a collection of effects

## Templates

* `effect-h.ptemplate.mustache` - renders the header file for an effect into `include/effectlibrary/{{snakeCase name}}.h`
* `effect-c.ptemplate.mustache` - renders the effect function implementation into `src/effectlibrary/{{snakeCase name}}.c`
* `effect-cli.ptemplate.mustache` - renders the CLI program for an effect into `src/cli/{{snakeCase name}}/main.c`
* `makefile.ptemplate.mustache` - renders the `Makefile` at the repository root that builds all effects
* `readme.ptemplate.mustache` - renders the `README.md` at the repository root