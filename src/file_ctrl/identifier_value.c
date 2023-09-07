# include "../../includes/cube3d.h"

int		textr_condition(t_cubfile *file, int i, int j, char t1, char t2)
{
	if ((file->file_matrix[i][j] == t1 && file->file_matrix[i][j + 1] == t2) && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13)))
		return 1;
	else
		return 0;
}
int		FC_condition(t_cubfile *file, int i, int j, char t)
{
	if (file->file_matrix[i][j] == t && ((file->file_matrix[i][j + 1] == 32) || (file->file_matrix[i][j + 1] >= 9 && file->file_matrix[i][j + 1] <= 13)))
		return 1;
	else
		return 0;
}

void	put_FC_flag(t_cubfile *file, int i, int j, char t)
{
	if (file->file_matrix[i][j] == t)
	{
		if (t == 'F')
		{
			file->F_text_index = i;
			file->F_flag += 1;
			file->F_text_y = j;
		}
		if (t == 'C')
		{
			file->C_text_index = i;
			file->C_flag += 1;
			file->C_text_y = j;
		}
	}
}

void	put_NS_flag(t_cubfile *file, int i, int j, char t)
{
	if (file->file_matrix[i][j] == t)
	{
		if (t == 'N')
		{
			file->NO_text_index = i;
			file->NO_flag += 1;
			file->NO_text_y = j;
		}
		if (t == 'S')
		{
			file->SO_text_index = i;
			file->SO_flag += 1;
			file->SO_text_y = j;
		}
	}
}
void	put_WE_flag(t_cubfile *file, int i, int j, char t)
{
	if (file->file_matrix[i][j] == t)
	{
		if (t == 'W')
		{
			file->WE_text_index = i;
			file->WE_flag += 1;
			file->WE_text_y = j;
		}
		if (t == 'E')
		{
			file->EA_text_index = i;
			file->EA_flag += 1;
			file->EA_text_y = j;
		}
	}
}

int	check_space_before_id(t_cubfile *file)
{
	int i;
	int j;

	i = 0;
	while (i < file->map_s->map_start_index)
	{
		j = 0;
		if (!ft_strempt(file->file_matrix[i]))
			i++;
		else
		{
			//ciclo tutti gli spazi e i tab che ci sono prima dell'id
			while (((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32)))
				j++;
			if ((textr_condition(file, i, j, 'N', 'O')) || (textr_condition(file, i, j, 'S', 'O')) || (textr_condition(file, i, j, 'W', 'E')) || (textr_condition(file, i, j, 'E', 'A'))|| FC_condition(file, i, j, 'F') || FC_condition(file, i, j, 'C'))
			{
				//controllo i char e metto le flag corrispondenti
				put_FC_flag(file, i, j, 'C');
				put_FC_flag(file, i, j, 'F');
				put_NS_flag(file, i, j, 'N');
				put_NS_flag(file, i, j, 'S');
				put_WE_flag(file, i, j, 'W');
				put_WE_flag(file, i, j, 'E');
				i++;
			}
			else
			{
				print_err(IDENTIFIER_SYNT_ERR);
				exit(1);
			}
		}
	}
	return 1;
}

int	check_id_num(t_cubfile *file)
{
	// printf("FLAG NO %d\nFLAG SO %d\nFLAG WE %d\nFLAG EA %d\nFLAG C %d\nFLAG F %d\n", file->NO_flag, file->SO_flag, file->WE_flag, file->EA_flag, file->C_flag, file->F_flag);
	if (file->NO_flag == 1 && file->SO_flag == 1 && file->WE_flag == 1 && file->EA_flag == 1 && file->C_flag == 1 && file->F_flag == 1)
		return 1;
	else
	{
		print_err(MORE_IDENTIFIER_ERR);
		exit(1);
	}
}

	void	check_id_values(t_cubfile *file)
	{
		//controllo i valori prima dell 'ID e flaggo gli id che ci sono
		check_space_before_id(file);

		//controllo se ci sono tutti gli id
		check_id_num(file);

		//

	}
	
	// while (i < file->map_s->map_start_index)
	// {
	// 	j = 0;
	// 	//ciclo tutti gli eventuali spazi, tab e simili prima dell' identificatore (NO, SO, WE, SA).
	// 	while (((file->file_matrix[i][j] >= 9 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32)))
	// 		j++;
    //     // La riga è vuota, passa alla successiva
	// 	if (file->file_matrix[i][j] == '\0' )
    // 	{
    //     	i++;
    //     	continue;
   	// 	}
	// 	//controllo se gli identificatori che ci sono sono quelli corretti, controllo solo che ci sia un spazio dopo. La path per ora non mi interessa.
	// 	if (((file->file_matrix[i][j] == 'N' && file->file_matrix[i][j + 1] == 'O') && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'S' && file->file_matrix[i][j + 1] == 'O' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'W' && file->file_matrix[i][j + 1] == 'E' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13))) || (file->file_matrix[i][j] == 'E' && file->file_matrix[i][j + 1] == 'A' && ((file->file_matrix[i][j + 2] == 32) || (file->file_matrix[i][j + 2] >= 9 && file->file_matrix[i][j + 2] <= 13)))|| (file->file_matrix[i][j] == 'F' && ((file->file_matrix[i][j + 1] == 32) || (file->file_matrix[i][j + 1] >= 9 && file->file_matrix[i][j + 1] <= 13))) || (file->file_matrix[i][j] == 'C' && ((file->file_matrix[i][j + 1] == 32) || (file->file_matrix[i][j + 1] >= 9 && file->file_matrix[i][j + 1] <= 13))))
	// 	{
			
	// 		//mi segno l'index e la posizione y di tutti gli identificatori che ho trovato, mi serviranno in seguito per le texture. Flaggo l'identificatore, per controllare i doppi
	// 		if (file->file_matrix[i][j] == 'F')
	// 		{
	// 			file->F_text_index = i;
	// 			file->F_flag += 1;
	// 			file->F_text_y = j;
	// 		}
	// 		if (file->file_matrix[i][j] == 'C')
	// 		{
	// 			file->C_text_index = i;
	// 			file->C_flag += 1;
	// 			file->C_text_y = j;
	// 		}
	// 		if (file->file_matrix[i][j] == 'N')
	// 		{
	// 			file->NO_text_index = i;
	// 			file->NO_flag += 1;
	// 			file->NO_text_y = j;
	// 		}
	// 		if (file->file_matrix[i][j] == 'S')
	// 		{
	// 			file->SO_text_index = i;
	// 			file->SO_flag += 1;
	// 			file->SO_text_y = j;
	// 		}
	// 		if (file->file_matrix[i][j] == 'W')
	// 		{
	// 			file->WE_text_index = i;
	// 			file->WE_flag += 1;
	// 			file->WE_text_y = j;
	// 		}
	// 		if (file->file_matrix[i][j] == 'E')
	// 		{
	// 			file->EA_text_index = i;
	// 			file->EA_flag += 1;
	// 			file->EA_text_y = j;
	// 		}
	// 		i++;
	// 	}
	// 	//questo per "distinguere" la prima linea della mappa una volta trovati tutti gli ID 
	// 	else if ((file->F_flag == 1  && file->C_flag == 1 && file->NO_flag == 1  && file->SO_flag == 1  && file->WE_flag == 1  && file->EA_flag == 1) && (file->file_matrix[i][j] == '1'))
	// 		break;
	// 	else
	// 	{
	// 		print_err(IDENTIFIER_SYNT_ERR);
	// 		exit(1);
	// 	}
	// }
	// // controllo se manca un ID
	// if (file->F_flag == 0  || file->C_flag == 0  || file->NO_flag == 0  || file->SO_flag == 0  || file->WE_flag == 0  || file->EA_flag == 0 )
	// {
	// 	print_err(MISSING_IDENTIFIER_ERR);
	// 	exit(1);
	// }
	// //controllo se c'è un flag in più
	// if (file->F_flag > 1  || file->C_flag > 1  || file->NO_flag > 1  || file->SO_flag > 1  || file->WE_flag > 1  || file->EA_flag > 1 )
	// {
	// 	print_err(MORE_IDENTIFIER_ERR);
	// 	exit(1);
	// }
