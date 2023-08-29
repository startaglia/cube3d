#include "../includes/cube3d.h"

//CONTROLLI SUL NUM DI ARG											OK
//CONTROLLI SUL TIPO DI FILE										OK
//CONTROLLI SULL'ORDINE DEGLI ELEMENTI NEL FILE						OK
//CONTROLLI SUGLI IDENTIFICATORI						
//CONTROLLI CHE LA PATH DOPO L'IDENTIFICATORE SIA CORRETTA?		
//CONTROLLI CHE IL CODICE RGB SIA CORRETTO		
//CONTROLLI CHE LA MAPPA SIA SHIELDATA								
//CONTROLLI CHE NON CI SIANO BUCHI NELLA MAPPA						
//CONTROLLI SUI TIPI DI VALORI NELLA MAPPA							



int main(int ac, char **av)
{
	t_cubfile *file;

	if (ac != 2)
	{
		print_err(ARG_ERR);
		exit(1);
	}
	file = malloc(sizeof(t_cubfile));
	init_structs(file, av[1]);
	check_file(file, av[1]);
	free(file);

	return 0;
}