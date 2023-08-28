#include "../includes/cube3d.h"



int main(int ac, char **av)
{
	if (ac != 2)
		print_err(ARG_ERR);
	check_map(av);
	printf("%s\n", av[1]);
	return 0;
}