#include "main.h"

/**
 * _printf_string_special - handles %S specifier
 * @S: string to be handled
 * Return: length of string
 */

int _printf_string_special(const char *S)
{
	int i = 0, j, len = 0, buff = 0, dec;
	char *literal = "\\x";
	char str[2];

	if (S == NULL)
                return (0);

	while (S[i] != '\0')
	{
		if ((S[i] > 0 && S[i] < 32) || S[i] >= 127)
		{
			for (j = 0; literal[j] != '\0'; j++)
				_putchar(literal[j]);
			len += 2;
			dec = S[i];
			for (j = 0; j < 2; j++)
			{
				buff = dec % 16;
				if (buff < 10)
					buff += '0';
				else
					buff += ('0' + 7);
				str[j] = buff;
				dec /= 16;
			}
			while (j >= 0)
			{
				_putchar(str[j]);
				j--;
			}
			len += 2;
			i++;
			
		}
		else
		{
			_putchar(S[i]);
			len++;
			i++;
		}
	}
	return (len);
}
