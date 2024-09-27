#include <stdio.h>
#include <stdlib.h>

// This function will be loaded with LD_PRELOAD and override the original random number generator.
int rand(void) {
    static int count = 0;
    int numbers[] = {9, 8, 10, 24, 75, 9};  // The winning numbers you picked
    int result = numbers[count];
    count = (count + 1) % 6;  // Cycle through the numbers
    return result;
}

// Override the srand function to avoid affecting our custom rand implementation
void srand(unsigned int seed) {
    (void)seed;  // Do nothing
}
