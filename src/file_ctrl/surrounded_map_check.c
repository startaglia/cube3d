# include "../../includes/cube3d.h"


int converter_tab_space(t_cubfile *file, int i, int j, int k)
{
	if (file->map_s->map_matrix[i][j] == '\t')
		k = j + 3;
	return k;
}



//gestisco tutte le condizioni possibili quando un 1 ha un char spazio ai lati o un edge
// int		find_matrix_edge(t_cubfile *file, int i, int j)
// {
// 	if (left_top_right_ed(file, i, j))
// 		return 1;
// 	if (left_bott_right_ed(file, i, j))
// 		return 1;
// 	printf("VALORE %d(%c) NON HA EDGE INTORNO---BOTTOMVALUE %d\n", file->map_s->map_matrix[i][j], file->map_s->map_matrix[i][j], file->map_s->value_s->bott_ed);
// 	printf("I-->%d\tJ-->%d\tMAPHEIGHT-->%d\tLENMAPT-->%d\tLENMAPD-->%d\n",i, j, (file->map_s->map_height - 1), (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1), (int)(ft_strlen(file->map_s->map_matrix[i + 1]) - 1));
// 	return 0;
// }

// void	print_edge(t_map *s_map, int i, int j)
// {
// 	if (s_map->value_s->left_top_right_ed)
// 		printf("EDGE LEFT TOP RIGHT\t*****%c*****\n", s_map->map_matrix[i][j]);
// 	else if(s_map->value_s->left_ed)
// 		printf("EDGE LEFT\t*****%c*****\n", s_map->map_matrix[i][j]);
// 	else if(s_map->value_s->top_bott_ed)
// 		printf("EDGE TOP\t*****%c*****\n", s_map->map_matrix[i][j]);
// }

//il mov a destra deve solo controllare cosa c'è sopra e a destra
int	right_mov_check(t_cubfile *file, int i, int j)
{
	// find_matrix_edge(file, i, j);
	if (top_ed(file, i, j))
	{
		printf("QUELLO DOPO HA UNA EDGE SOPRA\n");
		// j++;
		return 1;
	}
	return 0;
}

int first_line_check(t_cubfile *file, int *i, int *j)
{
    *j = 0;
    if (*i == 0)
    {
        if (left_top_right_ed(file, *i, *j))
        {
            file->map_s->value_s->ver_dir = 0;
            file->map_s->value_s->ver_coming_dir = 0;
            (*i)++;
            return 0;
        }
        else if (top_left_ed(file, *i, *j))
        {
            (*j)++;
            file->map_s->value_s->or_dir = 0;
            file->map_s->value_s->or_coming_dir = 0;
            while (file->map_s->map_matrix[*i][*j] && file->map_s->map_matrix[*i][*j + 1] != 32 && ((top_ed(file, *i, *j)) || (top_bott_ed(file, *i, *j))))
            {
                (*j)++;
            }
			// printf("VALORE MAP %d\tJ--> %d\n", file->map_s->map_matrix[*i][*j], *j);
            if (top_right_bott_ed(file, *i, *j))
            {
                file->map_s->value_s->or_dir = 1;
                file->map_s->value_s->or_coming_dir = 1;
                return 0;
            }
            else if (top_right_ed(file, *i, *j))
            {
                file->map_s->value_s->ver_dir = 0;
                file->map_s->value_s->ver_coming_dir = 0;
				file->map_s->concave_corner = 1;
				file->map_s->convex_corner = 0;

                return 0;
            }
        }
        else
        {
            printf("errore\n");
            return 1;
        }
    }
    return 0;
}

int		move_to_right_check(t_cubfile *file, int *i, int *j)
{
    if (left_top_right_ed(file, *i, *j))
    {
        file->map_s->value_s->ver_dir = 0;
        file->map_s->value_s->ver_coming_dir = 0;
		(*i)++;
		return 0;
	}
	else if (top_left_ed(file, *i, *j))
	{
		(*j)++;
		file->map_s->value_s->or_dir = 0;
		file->map_s->value_s->or_coming_dir = 0;
		while (file->map_s->map_matrix[*i][*j] && file->map_s->map_matrix[*i][*j + 1] != 32 && ((top_ed(file, *i, *j)) || (top_bott_ed(file, *i, *j))))
		{
			(*j)++;
		}

		// printf("VALORE MAP %d\tJ--> %d\n", file->map_s->map_matrix[*i][*j], *j);
		if (top_right_bott_ed(file, *i, *j))
		{
			file->map_s->value_s->or_dir = 1;
			file->map_s->value_s->or_coming_dir = 1;
			return 0;
		}
		else if (top_right_ed(file, *i, *j))
		{
			file->map_s->value_s->ver_dir = 0;
			file->map_s->value_s->ver_coming_dir = 0;
			file->map_s->concave_corner = 1;
			file->map_s->convex_corner = 0;

			return 0;
		}
	}
	else
	{
		printf("VALUE %d\n", file->map_s->map_matrix[*i][*j]);
		printf("errore\n");
		return 1;
	}
	return 0;
}

int		move_to_down_check(t_cubfile *file, int *i, int *j)
{
		if (left_top_right_ed(file, *i, *j))
		{
			file->map_s->value_s->ver_dir = 0;
			file->map_s->value_s->ver_coming_dir = 0;
			(*i)++;
			return 0;
		}
		else if (top_right_ed(file, *i, *j))
		{
			(*i)++;
			file->map_s->value_s->or_dir = 0;
			file->map_s->value_s->or_coming_dir = 0;
			while (file->map_s->map_matrix[*i][*j] && right_ed(file, *i, *j))
			{
				// printf("I %d e J %d\n", *i, *j);
				(*i)++;
			}
			//ogni volta in questo punto ho bisogno di resettare tutte le flag perchè sennò mi rimane salvata quella vecchia
			reset_ed_flags(file);
			//!CAPIRE PERCHE QUI TORNA 0 AI FLAG, DOVREBBE TORNARE 1 A TUTTI
			printf("VASUE-->%d\n", file->map_s->map_matrix[*i][*j]);
			printf("BEBE %d\n", top_edge(file, *i, *j));
			printf("BEBE %d\n", right_edge(file, *i, *j));
			printf("BEBE %d\n", bottom_edge(file, *i, *j));
			printf("BEBE %d\n", left_edge(file, *i, *j));

			if (left_top_right_bot_ed(file, *i, *j))
			{
				printf("GE\n");

				return 0;
			}
			if (right_bott_ed(file, *i, *j))
			{

				file->map_s->value_s->or_dir = 1;
				file->map_s->value_s->or_coming_dir = 1;
				file->map_s->concave_corner = 1;
				file->map_s->convex_corner = 0;
				return 0;
			}
		}
		else
		{
			printf("errore\n");
			return 1;
		}

	return 0;	
}

int		move_to_left_check(t_cubfile *file, int *i, int *j)
{
	
		if (top_right_bott_ed(file, *i, *j))
		{
			file->map_s->value_s->or_dir = 1;
			file->map_s->value_s->or_coming_dir = 1;
			(*j)--;
			return 0;
		}
		else if (right_bott_ed(file, *i, *j))
		{
			(*j)--;
			file->map_s->value_s->or_dir = 1;
			file->map_s->value_s->or_coming_dir = 1;
			while (file->map_s->map_matrix[*i][*j] && bott_ed(file, *i, *j))
			{
				// printf("I %d e J %d\n", *i, *j);
				(*j)--;
			}
			if (left_bott_ed(file, *i, *j))
			{
				file->map_s->value_s->ver_dir = 1;
				file->map_s->value_s->ver_coming_dir = 1;
				file->map_s->concave_corner = 1;
				file->map_s->convex_corner = 0;
				return 0;
			}
		}
		else
		{
			printf("errore\n");
			return 1;
		}
	return 0;	
}

int		move_to_top_check(t_cubfile *file, int *i, int *j)
{
	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);
		if (left_bott_right_ed(file, *i, *j))
		{
			file->map_s->value_s->or_dir = 1;
			file->map_s->value_s->or_coming_dir = 1;
			(*j)--;
			return 0;
		}
		else if (left_bott_ed(file, *i, *j))
		{
			(*i)--;
			file->map_s->value_s->ver_dir = 1;
			file->map_s->value_s->ver_coming_dir = 1;
			// printf("I %d e J %d\tVALUE %d\n", *i, *j, file->map_s->map_matrix[*i][*j]);
			// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);
			// printf("LEFTED %d\n", left_ed(file, *i, *j));
			//!IL PROBL È CHE LEFTED MI RITORNA 0, DOVREBBE TORNARE 1
			while ((file->map_s->map_matrix[*i][*j] && left_ed(file, *i, *j)) || (file->map_s->map_matrix[*i][*j] && left_right_ed(file, *i, *j)))
			{
				(*i)--;
			}
			// printf("NENE\n");
			if (top_left_ed(file, *i, *j))
			{
				file->map_s->value_s->or_dir = 0;
				file->map_s->value_s->or_coming_dir = 0;
				file->map_s->concave_corner = 1;
				file->map_s->convex_corner = 0;
				return 0;
			}
		}
		else
		{
			printf("errore\n");
			return 1;
		}
	return 0;	
}

void	surrounded_map_check(t_cubfile *file)
{
	printf("*************SURROUNDED CONTROL***************\n");
	print_matrix(file->map_s->map_matrix);

	//creo funzioni che mi indicano se mi trovo in un bordo della map matrix				OK
	//creo struttura che mi segna tutti i flag del momento									OK
	int i;
	int j;

	i = 0;
	j = 0;
	//ciclo finchè curr_ind_coord non è == a check_start_coord
	/*faccio prima di tutto il controllo sulla first line check che può arrivare ad un angolo esterno, un angolo interno o una pipe di 1. quindi controllo in questo ordine, le 3 casistiche:
	- pipe di 1
		se sono in una pipe di 1 per forza di cose arrivato all'ultimo 1 devo tornare indietro
	- angolo esterno
		qui inizio ad andare verso il basso, quindi ciclo finche non finisce lo spazio o l'edge alla destra dell'1
	- angolo interno


	mi flaggo il tipo di angolo che ha trovato e in base a quello e la direzione mi muovo
	


	*/
	file->map_s->check_curr_ind_coord[0] = i;
	file->map_s->check_curr_ind_coord[1] = j;
	//gestisco la prima linea

	// if (!first_line_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]))
	// {
		if (file->map_s->map_matrix[i][j])
		{

			while (file->map_s->map_matrix[i][j] && ((file->map_s->map_matrix[i][j] == 9) || (file->map_s->map_matrix[i][j] > 10 && file->map_s->map_matrix[i][j] <= 13) || (file->map_s->map_matrix[i][j] == 32)))
			{
				printf("valore %d\n", file->map_s->map_matrix[i][j]);
				j++;
			}
			//qui controllo dove ho gli spazi e in base a quelli mi muovo
			move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			//ciclo finchè le coordinate di start e di dove sono rimangono diverse
			// while (file->map_s->check_start_coord[0] != file->map_s->check_curr_ind_coord[0] || file->map_s->check_start_coord[1] != file->map_s->check_curr_ind_coord[1])
			// {
				//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso destra
				if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->or_dir && !file->map_s->value_s->or_coming_dir)
				{
					move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				}
				//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso il basso
				if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->ver_dir && !file->map_s->value_s->ver_coming_dir)
				{
					move_to_down_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				}
				//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso sinistra
				if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && file->map_s->value_s->or_dir && file->map_s->value_s->or_coming_dir)
				{
					move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				}
				//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso l'alto
				if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_dir && file->map_s->value_s->ver_coming_dir)
				{
				// printf("CORNER-->%d\tVALUE-->%d\tVER_DIR%d\tVER_COM_DIR%d\n\n", file->map_s->concave_corner, file->map_s->map_matrix[i][j], file->map_s->value_s->ver_dir, file->map_s->value_s->ver_coming_dir);
					// printf("ERR\n");
					move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				}
				printf("START COORD: I-->%d\t J-->%d\nCURR COORD: I-->%d\t J-->%d\n", file->map_s->check_start_coord[0], file->map_s->check_start_coord[1], file->map_s->check_curr_ind_coord[0], file->map_s->check_curr_ind_coord[1]);
				//controllo se sono arrivato ad un angolo convesso(angolo interno) e la direzione attuale è verso destra
				// if (file->map_s->convex_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->or_dir && !file->map_s->value_s->or_coming_dir)
				// {
				// 	move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				// }
			// }
		// }
			printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
		}
			// //controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione era verso sinistra
			// if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_dir && file->map_s->value_s->ver_coming_dir)
			// 	move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			
			
			

			// if (!first_line_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]))
			// {
				// j = 0;

			// if (file->map_s->value_s->ver_dir == 0 && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_coming_dir == 0)
			// {
			// 	move_to_down_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	// printf("VALUE %d\tJ--> %d\tI--> %d\n", file->map_s->map_matrix[i][j], j, i);
			// }
			// if (file->map_s->map_matrix[i][j] && file->map_s->value_s->or_dir && file->map_s->value_s->or_coming_dir)
			// {
			// 	move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// }
			// if (file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_dir && file->map_s->value_s->ver_coming_dir)
			// {
			// 	move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// }
			// break;
				// j++;
				// i++;
				
				// j = 0;
				// //qui controllo la direzione in cui devo andare
				// while (file->map_s->map_matrix[i][j])
				// {
				// 	if (file->map_s->value_s->ver_dir == 0 && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_coming_dir == 0)
				// 	{
				// 		// while (move_to_down_check(file, i, j))
				// 		// {
				// 		// 	i++;
				// 		// }
						
				// 	}
				// 	// find_matrix_edge(file, i, j);
				// 	// print_flag(file->map_s->value_s);
				// 	printf("VALUE FUORI %d\tJ--> %d\n", file->map_s->map_matrix[i][j], j);
				// 	// while (file->map_s->map_matrix[i][j] && right_mov_check(file, i, j))
				// 	// {
				// 	// 	printf("VALUE %d\tJ--> %d\tI--> %d\n", file->map_s->map_matrix[i][j], j, i);
				// 	// 	j++;
				// 	// }
				// 	// print_flag(file->map_s->value_s);
				// 	j++;
				// }
}