#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list a_list;
	int i = 0, flag;
	char *str, *sep = "";

	va_start(a_list, format);
	while (format && format[i])
	{
		flag = 1;
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(a_list, int));
			break;
		case 'i':
			printf("%s%d", sep, va_arg(a_list, int));
			break;
		case 'f':
			printf("%s%f", sep, va_arg(a_list, double));
			break;
		case 's':
			str = va_arg(a_list, char *);
			if (!str)
				str = "(nil)";
			printf("%s%s", sep, str);
			break;
		default:
			flag = 0;
			break;
		}
		if (flag)
			sep = ", ";
		i++;
	}
	printf("\n");
	va_end(a_list);
}
