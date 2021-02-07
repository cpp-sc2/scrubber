# Scrubber
Scrub type ids from a running Starcraft II game client and print JSON to stdout.

## Build requirements
1. A compiler with C++17 support.
2. Cmake >= 3.1.

## Build instructions

### OS X (cmdline)
```bash
# Get the project.
$ git clone --recursive git@github.com:cpp-sc2/scrubber.git && cd scrubber

# Create build directory.
$ mkdir build && cd build

# Generate a Makefile.
# Use 'cmake -DCMAKE_BUILD_TYPE=Debug ../' if debuginfo is needed
$ cmake ../

# Build the project.
$ make

# Launch a game client, e.g. using Docker.
# See: https://github.com/cpp-sc2/docker-sc2

# Launch.
$ ./bin/Scrubber -p 8167 -m 2020S2/DeathAuraLE.SC2Map > out.json
```

## License
Copyright (c) 2021 Alexander Kurbatov

Licensed under the [MIT license](LICENSE).
