#include "../includes/cube3d.h"
//SE SI METTE UN ESTENSIONE .CU NON MI ENTRA NELL'ERRORE DEL TIPO DI ESTENSIONE MA MI VA IN ERRORE L'OPEN. CAPIRE SE DA PROBLEMI


//CONTROLLI SUL NUM DI ARG											OK
//CONTROLLI SUL TIPO DI FILE										OK
//CONTROLLI SULL'ORDINE DEGLI ELEMENTI NEL FILE						OK
//CONTROLLI SUI TIPI DI IDENTIFICATORI								OK
//CONTROLLI CHE LA PATH DOPO L'IDENTIFICATORE SIA CORRETTA?			
//CONTROLLI CHE IL CODICE RGB SIA CORRETTO range [0,255]			OK

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
	if (file == NULL)
	{
    	print_err(MEM_ERROR);
    	exit(1);
	}
	//inizializzo i valori delle structs
	init_structs(file, av[1]);
	//faccio i dovuti controlli sul file.cub
	check_file(file, av[1]);
	//trasformo la mappa in una matrice
	// matrix_map(file);
	// printf("INDEX START MAP: %d\tINDEX END MAP: %d\n", file->map_s->map_start_index, file->map_s->map_end_index);


	// free_matrix(file->map_s->map_matrix);
	free(file->map_s);
	free(file->file_path);
	// free(file->map_s);
	free_matrix(file->file_matrix);
	free(file);

	return 0;
}