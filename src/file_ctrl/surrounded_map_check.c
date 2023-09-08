# include "../../includes/cube3d.h"


int converter_tab_space(char c, int cont)
{
	if (c == '\t') {
		// Se il carattere è una tabulazione, aggiungi 4 al contatore
		cont += 4;
	} 
	else if (c == ' ')
	{
		// Se il carattere è uno spazio, aggiungi 1 al contatore
		cont++;
	}
	return cont;
}
	
int		one_space_on_right(t_cubfile *file, int i, int j)
{
	if (file->map_s->map_matrix[i][j + 1] == 0)
	{
		printf("\nLAST 1 ON THE RIGHT");
		printf("\n\tI->\t%d0 ON THE RIGHT\n", i);
		printf("\tVALUES-->%d\n", file->map_s->map_matrix[i][j + 1]);

	}
	else if (file->map_s->map_matrix[i][j + 1] == 32)
	{
		printf("\nSPACE CHAR ON THE RIGHT");
		printf("\n\tI->\t%dSPACE ON THE RIGHT\n", i);
		printf("\tVALUES-->%d\n", file->map_s->map_matrix[i][j + 1]);
	}
	return (1);
}
int	top_edge(t_cubfile *file, int i, int j)
{
	// bordo superiore
	if ((i == 0) || (i > 0 && j > (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1)))
		return 1;
	return 0;
}
int	right_edge(t_cubfile *file, int i, int j)
{
	//bordo destro
	if (j == (int)(ft_strlen(file->map_s->map_matrix[i]) - 1))
		return 1;
	return 0;
}
int	bottom_edge(t_cubfile *file, int i, int j)
{
	//bordo inferiore
	if ((i == (file->map_s->map_height - 1)) || ((file->map_s->map_height - 1) > i && j > (int)(ft_strlen(file->map_s->map_matrix[i + 1]) - 1)))
		return 1;
	return 0;
}
int	left_edge(t_cubfile *file, int i, int j)
{
	(void) i;
	(void) file;
	//bordo sinistro
	if (j == 0 && i == 0)
		return 1;
	return 0;
}

//gestisco tutte le condizioni possibili quando un 1 ha un char spazio ai lati o un edge
int		find_matrix_edge(t_cubfile *file, int i, int j)
{
	//SINISTRO SUPERIORE E DESTRO
	if (left_edge(file, i, j) && top_edge(file, i, j) && right_edge(file, i, j) && !bottom_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 1;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SINISTRO INFERIORE E DESTRO
	else if (left_edge(file, i, j) && bottom_edge(file, i, j) && right_edge(file, i, j) && ! top_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 1;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SUPERIORE DESTRO E INFERIORE
	else if(top_edge(file, i, j) && right_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 1;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SINISTRO E DESTRO
	else if(left_edge(file, i, j) && right_edge(file, i, j) && !bottom_edge(file, i, j) && !top_edge(file,i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 1;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SUPERIORE E SINISTRO
	else if(top_edge(file, i, j) && left_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 1;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SUPERIORE E DESTRO
	else if(top_edge(file, i, j) && right_edge(file, i, j) && !left_edge(file, i, j) && !bottom_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 1;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SUPERIORE E INFERIORE
	else if(top_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j) && !(right_edge(file, i, j)))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 1;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//DESTRO E INFERIORE
	else if(right_edge(file, i, j) && bottom_edge(file, i, j) && !top_edge(file, i, j) && !left_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 1;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SINISTRO E INFERIORE
	else if(left_edge(file, i, j) && bottom_edge(file, i, j) && !right_edge(file, i, j) && !top_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 1;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SUPERIORE
	else if (top_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !right_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 1;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//DESTRO
	else if(right_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 1;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 0;
		return 1;	
	}
	//INFERIORE
	else if(bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 1;
		file->map_s->value_s->left_ed = 0;
		return 1;
	}
	//SINISTRO
	else if(left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_ed = 0;
		file->map_s->value_s->left_bott_right_ed = 0;
		file->map_s->value_s->top_right_bott_ed = 0;
		file->map_s->value_s->left_right_ed = 0;
		file->map_s->value_s->top_left_ed = 0;
		file->map_s->value_s->top_right_ed = 0;
		file->map_s->value_s->top_bott_ed = 0;
		file->map_s->value_s->right_bott_ed = 0;
		file->map_s->value_s->left_bott_ed = 0;
		file->map_s->value_s->top_ed = 0;
		file->map_s->value_s->right_ed = 0;
		file->map_s->value_s->bott_ed = 0;
		file->map_s->value_s->left_ed = 1;
		return 1;
	}
	return 0;
}

void	print_edge(t_map *s_map, int i, int j)
{
	if (s_map->value_s->left_top_right_ed)
		printf("EDGE LEFT TOP RIGHT\t*****%c*****\n", s_map->map_matrix[i][j]);
	else if(s_map->value_s->left_ed)
		printf("EDGE LEFT\t*****%c*****\n", s_map->map_matrix[i][j]);
	else if(s_map->value_s->top_bott_ed)
		printf("EDGE TOP\t*****%c*****\n", s_map->map_matrix[i][j]);
}

void	surrounded_map_check(t_cubfile *file)
{
	(void) file;
	int test = 0;
	(void) test;
	printf("*************SURROUNDED CONTROL***************\n");
	print_matrix(file->map_s->map_matrix);

	//creo funzioni che mi indicano se mi trovo in un bordo della map matrix				OK
	// ORA HO UNA STRUTTURA CHE CONTIENE TUTTI I FLAG CHE MI SERVONO PER I VALORI
	/*CONTROLLANDO LA DIREZIONE IN CUI STO ANDANDO MI CONTROLLO LE EDGE CHE MI POSSONO SERVIRE:
	SE STO ANDANDO DA SINISTRA A DESTRA LE EDGE CHE MI POSSONO SERVIRE SONO QUELLA DI SINISTRA E QUELLA DI SOPRA */
	
	
	//! CONTROLLARE BENE LE FLAG. CONTROLLARE BENE LA CONDIZIONE DEL SOLO LEFT, DOVREBBE ESSERE GIUSTO MA MANCA UNA COSETTAN DA CAPIRE
	int i;
	int j;

	i = -1;
	j = 0;
	while (file->map_s->map_matrix[++i])
	{
		j = 0;
		while (file->map_s->map_matrix[i][j])
		{
			printf("KKIKI %d\n", file->map_s->map_matrix[i][j]);
			find_matrix_edge(file, i, j);
			printf("TERE %d\n", file->map_s->value_s->left_top_right_ed);
			printf("GERE %d\n", file->map_s->value_s->left_ed);

			print_edge(file->map_s, i, j);

			// top_right_left_sp(file, i, j);
			// one_space_on_right(file, i, j);
			j++;
		}
		printf("*************\n");
	}
}