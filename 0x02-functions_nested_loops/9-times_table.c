#include "main.h"

void times_table(void)
{
    int x, y, z, u;

    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            z = x * y;
            if (z > 9)
            {
                u = z % 10;
                z = z / 10;
                _putchar('0' + z);
                _putchar('0' + u);
            }
            else
            {
                if (y != 0)
                {
                    _putchar(' ');
                }
                _putchar('0' + z);
            }

            if (y != 9)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
        _putchar('\n');
    }
}
