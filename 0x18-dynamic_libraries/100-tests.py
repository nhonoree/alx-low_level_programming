import random
import ctypes

# Load the shared library
cops = ctypes.CDLL('./100-operations.so')

# Random test values
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))

# Handle division and modulus carefully to avoid divide by zero
if b != 0:
    print("{} / {} = {}".format(a, b, cops.div(a, b)))
    print("{} % {} = {}".format(a, b, cops.mod(a, b)))
else:
    print("Division and modulus by zero are not allowed")
