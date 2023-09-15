# include "../../includes/cube3d.h"

int		move_to_right_check(t_cubfile *file, int *i, int *j)
{
	//controllo trova subito un angolo concavo
	if (file->map_s->map_matrix[*i][*j] && top_right_ed(file, *i, *j))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↴)====================\n", file->map_s->map_matrix[*i][*j]);
		(*i)++;
		file->map_s->value_s->ver_dir = 0;
		file->map_s->value_s->or_dir = -1;
		file->map_s->concave_corner = 1;
		file->map_s->convex_corner = 0;
		return 0;
	}
	//controllo trova subito un angolo convesso
	else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
	{
		printf("*****%c*****\t====================QUI C'è UN ANGOLO CONVESSO(⤴ )====================\n", file->map_s->map_matrix[*i][*j]);
		(*i)--;
		file->map_s->value_s->ver_dir = 1;
		file->map_s->value_s->or_dir = -1;
		file->map_s->concave_corner = 0;
		file->map_s->convex_corner = 1;
		return 0;
	}
	//se non ci sono angoli scorre verso destra
	else if (file->map_s->map_matrix[*i][*j] && top_ed_cond(file, *i, *j))
	{
		(*j)++;
		while (file->map_s->map_matrix[*i][*j] && top_ed(file, *i, *j))
		{
			(*j)++;
		}
		if (file->map_s->map_matrix[*i][*j] && top_right_ed(file, *i, *j))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↴)====================\n", file->map_s->map_matrix[*i][*j]);
			(*i)++;
			file->map_s->value_s->ver_dir = 0;
			file->map_s->value_s->or_dir = -1;
			file->map_s->concave_corner = 1;
			file->map_s->convex_corner = 0;
			return 0;
		}
		else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
		{
			printf("*****%c*****\t====================QUI C'è UN ANGOLO CONVESSO(⤴ )====================\n", file->map_s->map_matrix[*i][*j]);
			(*i)--;
			file->map_s->value_s->ver_dir = 1;
			file->map_s->value_s->or_dir = -1;
			file->map_s->concave_corner = 0;
			file->map_s->convex_corner = 1;
			return 0;
		}
	}
	else
	{
		printf("ferrore\n");
		return 1;
	}
	return 0;
}

int		move_to_down_check(t_cubfile *file, int *i, int *j)
{
	//controllo se trova subito un angolo concavo
	if (file->map_s->map_matrix[*i][*j] && right_bott_ed(file, *i, *j))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↲)====================\n", file->map_s->map_matrix[*i][*j]);
		(*j)--;
		file->map_s->value_s->ver_dir = -1;
		file->map_s->value_s->or_dir = 1;
		file->map_s->concave_corner = 1;
		file->map_s->convex_corner = 0;
		return 0;
	}
	//controllo se trova subito un angolo convesso
	else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(↳)====================\n", file->map_s->map_matrix[*i][*j]);
		(*j)++;
		file->map_s->value_s->ver_dir = -1;
		file->map_s->value_s->or_dir = 0;
		file->map_s->concave_corner = 0;
		file->map_s->convex_corner = 1;
		return 0;
	}
	//se non ci sono angoli subito scorre verso il basso
	else if (file->map_s->map_matrix[*i][*j] && right_ed_cond(file, *i, *j))
	{
		while ((file->map_s->map_matrix[*i][*j] && (right_ed(file, *i, *j))))
		{
			(*i)++;
		}
		if (file->map_s->map_matrix[*i][*j] && right_bott_ed(file, *i, *j))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↲)====================\n", file->map_s->map_matrix[*i][*j]);
			(*j)--;
			file->map_s->value_s->ver_dir = -1;
			file->map_s->value_s->or_dir = 1;
			file->map_s->concave_corner = 1;
			file->map_s->convex_corner = 0;
			return 0;
		}
		else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j)))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(↳)====================\n", file->map_s->map_matrix[*i][*j]);
			(*j)++;
			file->map_s->value_s->ver_dir = -1;
			file->map_s->value_s->or_dir = 0;
			file->map_s->concave_corner = 0;
			file->map_s->convex_corner = 1;
			return 0;
		}
	}
	else
	{
		printf("errlore\n");
		return 1;
	}
	return 0;
}

int		move_to_left_check(t_cubfile *file, int *i, int *j)
{
	//controllo se trova subito un angolo concavo
	if (file->map_s->map_matrix[*i][*j] && left_bott_ed(file, *i, *j))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(⬑ )====================\n", file->map_s->map_matrix[*i][*j]);
		(*i)--;
		file->map_s->value_s->ver_dir = 1;
		file->map_s->value_s->or_dir = -1;
		file->map_s->concave_corner = 1;
		file->map_s->convex_corner = 0;
		return 0;
	}
	//controllo se trova subito un angolo convesso
	else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(⬐ )====================\n", file->map_s->map_matrix[*i][*j]);
		(*i)++;
		file->map_s->value_s->ver_dir = 0;
		file->map_s->value_s->or_dir = -1;
		file->map_s->concave_corner = 0;
		file->map_s->convex_corner = 1;
		return 0;
	}
	//se non ci sono angoli subito scorre verso sinistra
	else if (file->map_s->map_matrix[*i][*j] && bott_ed(file, *i, *j))
	{
		while ((file->map_s->map_matrix[*i][*j] && (bott_ed(file, *i, *j))))
		{
			(*j)--;
		}
		if (file->map_s->map_matrix[*i][*j] && left_bott_ed(file, *i, *j))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(⬑ )====================\n", file->map_s->map_matrix[*i][*j]);
			(*i)--;
			file->map_s->value_s->ver_dir = 1;
			file->map_s->value_s->or_dir = -1;
			file->map_s->concave_corner = 1;
			file->map_s->convex_corner = 0;
			return 0;
		}
		else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(⬐ )====================\n", file->map_s->map_matrix[*i][*j]);
			(*i)++;
			file->map_s->value_s->ver_dir = 0;
			file->map_s->value_s->or_dir = -1;
			file->map_s->concave_corner = 0;
			file->map_s->convex_corner = 1;
			return 0;
		}
	}
	else
	{
		printf("errorbe\n");
		return 1;
	}
	return 0;
}

int		move_to_top_check(t_cubfile *file, int *i, int *j)
{
	//controllo se trova subito un angolo concavo
	if (file->map_s->map_matrix[*i][*j] && top_left_ed(file, *i, *j))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↱ )====================\n", file->map_s->map_matrix[*i][*j]);
		(*j)++;
		file->map_s->value_s->ver_dir = -1;
		file->map_s->value_s->or_dir = 0;
		file->map_s->concave_corner = 1;
		file->map_s->convex_corner = 0;
		return 0;
	}
	//controllo se trova subito un angolo convesso
	else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
	{
		printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(↰ )====================\n", file->map_s->map_matrix[*i][*j]);
		(*j)--;
		file->map_s->value_s->ver_dir = -1;
		file->map_s->value_s->or_dir = 1;
		file->map_s->concave_corner = 0;
		file->map_s->convex_corner = 1;
		return 0;
	}
	//se non ci sono angoli subito scorre verso l'alto
	else if (file->map_s->map_matrix[*i][*j] && left_ed(file, *i, *j))
	{
		while ((file->map_s->map_matrix[*i][*j] && (left_ed(file, *i, *j))))
		{
			(*i)--;
		}
		if (file->map_s->map_matrix[*i][*j] && top_left_ed(file, *i, *j))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONCAVO(↱ )====================\n", file->map_s->map_matrix[*i][*j]);
			(*j)++;
			file->map_s->value_s->ver_dir = -1;
			file->map_s->value_s->or_dir = 0;
			file->map_s->concave_corner = 1;
			file->map_s->convex_corner = 0;
			return 0;
		}
		else if (file->map_s->map_matrix[*i][*j] && (!top_ed_cond(file, *i, *j) && !right_ed_cond(file, *i, *j) && !bott_ed_cond(file, *i, *j) && !left_ed_cond(file, *i, *j)))
		{
			printf("*****%c*****\t====================QUI C'È UN ANGOLO CONVESSO(↰ )====================\n", file->map_s->map_matrix[*i][*j]);
			(*j)--;
			file->map_s->value_s->ver_dir = -1;
			file->map_s->value_s->or_dir = 1;
			file->map_s->concave_corner = 0;
			file->map_s->convex_corner = 1;
			return 0;
		}
	}
	else
	{
		printf("errorbe\n");
		return 1;
	}
	return 0;
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
				file->map_s->check_curr_ind_coord[1]++;
			}
			if (i == 0 && j == 0 && file->map_s->map_matrix[i][j])
			{
				file->map_s->check_curr_ind_coord[1]+= 1;
				move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			}
			move_to_down_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
					
			move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
		}





			// move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// if (file->map_s->concave_corner && !file->map_s->convex_corner &&  !file->map_s->value_s->ver_dir)
			// {
			// 	move_to_down_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// }
			// printf("CONC-->%d\tCONV-->%d\tVERDIR-->%d\tORDIR-->%d\n", file->map_s->concave_corner, file->map_s->convex_corner, file->map_s->value_s->ver_dir, file->map_s->value_s->or_dir);
			// if ((file->map_s->concave_corner && !file->map_s->convex_corner && file->map_s->value_s->ver_dir) || (file->map_s->convex_corner && !file->map_s->concave_corner && file->map_s->value_s->or_dir))
			// 	move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// if ((file->map_s->concave_corner && !file->map_s->convex_corner &&  !file->map_s->value_s->ver_dir) || (file->map_s->convex_corner && !file->map_s->concave_corner && file->map_s->value_s->or_dir))
			// if ((file->map_s->concave_corner && !file->map_s->convex_corner && file->map_s->value_s->ver_dir) || (file->map_s->convex_corner && !file->map_s->concave_corner && file->map_s->value_s->or_dir))

			//while finche le coordinate iniziali e quelle dove sto non sono diverse
			//dentro provo a farla ricorsiva

				// if (file->map_s->convex_corner && !file->map_s->concave_corner)
				// 	move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
				// else if (file->map_s->concave_corner && file->map_s->convex_corner)
				// 	move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// else if (file->map_s->convex_corner && !file->map_s->concave_corner &&  !file->map_s->value_s->ver_coming_dir)
			// {
			// 	move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	if (file->map_s->convex_corner && !file->map_s->concave_corner)
			// 		move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	else if (file->map_s->concave_corner && file->map_s->convex_corner)
			// 		move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// }
				

			
			// move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);

			//ciclo finchè le coordinate di start e di dove sono rimangono diverse
			// while (file->map_s->check_start_coord[0] != file->map_s->check_curr_ind_coord[0] || file->map_s->check_start_coord[1] != file->map_s->check_curr_ind_coord[1])
			// {
			// 	// controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso destra
			// 	if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->or_dir && !file->map_s->value_s->or_coming_dir)
			// 	{
			// 		move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	}
			// 	//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso il basso
			// 	if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->ver_dir && !file->map_s->value_s->ver_coming_dir)
			// 	{
			// 		move_to_down_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	}
			// 	//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso sinistra
			// 	if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && file->map_s->value_s->or_dir && file->map_s->value_s->or_coming_dir)
			// 	{
			// 		move_to_left_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	}
			// 	//controllo se sono arrivato ad un angolo concavo(angolo esterno) e la direzione attuale è verso l'alto
			// 	if (file->map_s->concave_corner && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_dir && file->map_s->value_s->ver_coming_dir)
			// 	{
			// 	// printf("CORNER-->%d\tVALUE-->%d\tVER_DIR%d\tVER_COM_DIR%d\n\n", file->map_s->concave_corner, file->map_s->map_matrix[i][j], file->map_s->value_s->ver_dir, file->map_s->value_s->ver_coming_dir);
			// 		// printf("ERR\n");
			// 		move_to_top_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	}

			// 	//controllo se sono arrivato ad un angolo convesso(angolo interno) e la direzione attuale è verso destra
			// 	// if (file->map_s->convex_corner && file->map_s->map_matrix[i][j] && !file->map_s->value_s->or_dir && !file->map_s->value_s->or_coming_dir)
			// 	// {
			// 	// 	move_to_right_check(file, &file->map_s->check_curr_ind_coord[0], &file->map_s->check_curr_ind_coord[1]);
			// 	}
			// }
		// }
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