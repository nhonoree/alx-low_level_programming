#!/bin/bash
export CFILE=3-main.c ; ./3-name

#include <unistd.h>

int main(void)
{
	char *msg ="and that piece of the art is useful\" -Dora korpar, 2015-10-19\n";
	write(2, msg, 59);
	return (1);
}

