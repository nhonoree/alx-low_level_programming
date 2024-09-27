#!/bin/bash
gcc -shared -o libhack.so -fPIC hack_gm.c  # Compile the shared library
LD_PRELOAD=./libhack.so ./gm 9 8 10 24 75 9  # Run gm with LD_PRELOAD
