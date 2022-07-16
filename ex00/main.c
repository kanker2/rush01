#include <stdlib.h>

int valid_args(int argc, char *argv[]);
int just_valid_numbers(char *str);

int	main(int argc, char *argv[])
{
	if(valid_args(argc, argv))
}

int	valid_args(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	if (!just_valid_numbers(argv[1]))
}

int	just_valid_numbers(char *str)
{
	int last_is_num;

	last_is_num = 0;
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
		{
			if (last_is_num
		}
		str++;
	}
}
