# include "../../includes/cube3d.h"

void	check_id_file(t_cubfile *file)
{
	int i;
	int j;

	i = 0;
	while (i < file->map_start_index)
	{
		j = 0;
		//ciclo tutti gli eventuali spazi, tab e simili prima dell' identificatore (NO, SO, WE, SA). 
		while ((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32))
			j++;
		if (file->file_matrix[i][j] == '\0')
    	{
        // La riga è vuota, passa alla successiva
        	i++;
        	continue;
   		}
		//controllo se gli identificatori che ci sono sono quelli corretti
		if ((file->file_matrix[i][j] == 'N' && file->file_matrix[i][j + 1] == 'O') || (file->file_matrix[i][j] == 'S' && file->file_matrix[i][j + 1] == 'O') || (file->file_matrix[i][j] == 'W' && file->file_matrix[i][j + 1] == 'E') || (file->file_matrix[i][j] == 'E' && file->file_matrix[i][j + 1] == 'A')|| file->file_matrix[i][j] == 'F' || file->file_matrix[i][j] == 'C')
		{
				// printf("F FLAG %d\n", file->F_flag);

			//mi segno l'index di tutti gli identificatori che ho trovato, mi serviranno in seguito per le texture. Flaggo l'identificatore, per controllare i doppi
			if (file->file_matrix[i][j] == 'F')
			{
				file->floor_index = i;
				file->F_flag += 1;
			}
			if (file->file_matrix[i][j] == 'C')
			{
				file->ceiling_index = i;
				file->C_flag += 1;
			}
			if (file->file_matrix[i][j] == 'N')
			{
				file->NO_text_index = i;
				file->NO_flag += 1;
			}
			if (file->file_matrix[i][j] == 'S')
			{
				file->SO_text_index = i;
				file->SO_flag += 1;
			}
			if (file->file_matrix[i][j] == 'W')
			{
				file->WE_text_index = i;
				file->WE_flag += 1;
			}
			if (file->file_matrix[i][j] == 'E')
			{
				file->EA_text_index = i;
				file->EA_flag += 1;
			}
				printf("SONO QUI E LA I = %d \n", i);

			i++;
		}
		else
		{
			printf("SONO QUI E LA I = %d \n", i);
			print_err(IDENTIFIER_SYNT_ERR);
			exit(1);
		}
	}
	
	if (file->F_flag == 0  || file->C_flag == 0  || file->NO_flag == 0  || file->SO_flag == 0  || file->WE_flag == 0  || file->EA_flag == 0 )
	{
		print_err(MISSING_IDENTIFIER_ERR);
		exit(1);
	}
	if (file->F_flag > 1  || file->C_flag > 1  || file->NO_flag > 1  || file->SO_flag > 1  || file->WE_flag > 1  || file->EA_flag > 1 )
	{
		print_err(MORE_IDENTIFIER_ERR);
		exit(1);
	}
}
