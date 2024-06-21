#include <unistd.h>

int main(void)
{
	char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(2, msg, sizeof(msg) -1);
	return (1);
}

gcc -Wall -Werror -Wextra -pedantic -std=gnus89 -0 qoute 101-qoute.c
