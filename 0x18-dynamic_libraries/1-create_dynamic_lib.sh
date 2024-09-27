#!/bin/bash
gcc -c -fPIC *.c    # Compile all .c files into position-independent object files
gcc -shared -o liball.so *.o  # Link the object files into a shared library liball.so
