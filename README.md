# psleep

Generates random time intervals from an exponential distribution. Given a number
of iterations and a mean interval, it seeds a pseudorandom number generator,
draws that many values from the distribution, and prints the run parameters along
with the current date and time.

Written for CSCI 40300 ("Project Two") by Group Swan: Tyler Phillips, Kevin
Kolcheck, Benjamin Fulkerson-Bird, and Daniel Adams.

## Build

```
make
```

This compiles main.cpp, random.cpp, and time.cpp into a psleep executable with
g++. Run `make clean` to remove the build artifacts.

## Usage

```
./psleep <iterations> <mean>
```

- iterations (int): how many values to generate
- mean (double): the mean interval, in seconds

Example:

```
./psleep 1000 0.5
```

The program prints the parameters you passed and the current time, then draws the
requested number of values, each with the given mean.

## Source layout

- main.cpp: parses the arguments and runs the main loop
- random.cpp / random.hpp: seeds the generator and samples the distribution
- time.cpp / time.hpp: formats the date and time
- makefile: defines the all, run, and clean targets

## Status

Archived and no longer maintained. It began as a university group project and is
kept here for reference.
