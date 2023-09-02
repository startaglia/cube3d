# include "../../includes/cube3d.h"

void	check_id_file(t_cubfile *file)
{
	int i;
	int j;

	i = 0;
	while (i < file->map_s->map_start_index)
	{
		j = 0;
		//ciclo tutti gli eventuali spazi, tab e simili prima dell' identificatore (NO, SO, WE, SA).
		while (((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32)))
		{
			j++;
			// printf("CHE SUCCEDE QUI %c\n", file->file_matrix[i][j]);
		}
        // La riga è vuota, passa alla successiva
		// printf("\tVALORE CHAR----> %c\n\tVALORE ASCII %d\n", file->file_matrix[i][j], file->file_matrix[i][j]);
		//vai avanti di riga se la riga è vuota o ci sono solo spazi e tab
		if (file->file_matrix[i][j] == '\0' )
    	{
        	i++;
        	continue;
   		}
		// printf("DOPO VALORE CHAR----> %c\nDOPO VALORE ASCII %d\n", file->file_matrix[i][j], file->file_matrix[i][j]);

		//controllo se gli identificatori che ci sono sono quelli corretti, controllo solo che ci sia un spazio dopo. La path per ora non mi interessa.
		if (((file->file_matrix[i][j] == 'N' && file->file_matrix[i][j + 1] == 'O') && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'S' && file->file_matrix[i][j + 1] == 'O' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'W' && file->file_matrix[i][j + 1] == 'E' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'E' && file->file_matrix[i][j + 1] == 'A' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13)))|| (file->file_matrix[i][j] == 'F' && ((file->file_matrix[i][j + 1] == 32) || (file->file_matrix[i][j + 1] >= 9 && file->file_matrix[i][j + 1] <= 13))) || (file->file_matrix[i][j] == 'C' && ((file->file_matrix[i][j + 1] == 32) || (file->file_matrix[i][j + 1] >= 9 && file->file_matrix[i][j + 1] <= 13))))
		{
			
			//mi segno l'index e la posizione y di tutti gli identificatori che ho trovato, mi serviranno in seguito per le texture. Flaggo l'identificatore, per controllare i doppi
			if (file->file_matrix[i][j] == 'F')
			{
				file->F_text_index = i;
				file->F_flag += 1;
				file->F_text_y = j;
			}
			if (file->file_matrix[i][j] == 'C')
			{
				file->C_text_index = i;
				file->C_flag += 1;
				file->C_text_y = j;
			}
			if (file->file_matrix[i][j] == 'N')
			{
				file->NO_text_index = i;
				file->NO_flag += 1;
				file->NO_text_y = j;
			}
			if (file->file_matrix[i][j] == 'S')
			{
				file->SO_text_index = i;
				file->SO_flag += 1;
				file->SO_text_y = j;
			}
			if (file->file_matrix[i][j] == 'W')
			{
				file->WE_text_index = i;
				file->WE_flag += 1;
				file->WE_text_y = j;
			}
			if (file->file_matrix[i][j] == 'E')
			{
				file->EA_text_index = i;
				file->EA_flag += 1;
				file->EA_text_y = j;
			}
			i++;
			// printf("F FLAG %d\n", file->F_flag);
			// printf("C FLAG %d\n", file->C_flag);
			// printf("NO FLAG %d\n", file->NO_flag);
			// printf("SO FLAG %d\n", file->SO_flag);
			// printf("WE FLAG %d\n", file->WE_flag);
			// printf("EA FLAG %d\n", file->EA_flag);
		}
		else if ((file->F_flag == 1  && file->C_flag == 1 && file->NO_flag == 1  && file->SO_flag == 1  && file->WE_flag == 1  && file->EA_flag == 1) && (file->file_matrix[i][j] == '1'))
		{
			break;
		}
		else
		{
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
