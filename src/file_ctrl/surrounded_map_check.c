# include "../../includes/cube3d.h"


int converter_tab_space(t_cubfile *file, int i, int j, int k)

{
	if (file->map_s->map_matrix[i][j] == '\t')
		k = j + 3;
	return k;
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
	if ((i == (file->map_s->map_height - 1)) || (j > (int)(ft_strlen(file->map_s->map_matrix[i + 1]) - 1)))
		return 1;
	return 0;
}
int	left_edge(t_cubfile *file, int i, int j)
{
	(void) i;
	(void) file;
	//bordo sinistro
	if ((j == 0 && i == 0) || (j == 0 && !((file->file_matrix[i][j] == 9) || (file->file_matrix[i][j] > 10 && file->file_matrix[i][j] <= 13) || (file->file_matrix[i][j] == 32))))
		return 1;
	return 0;
}

//gestisco tutte le condizioni possibili quando un 1 ha un char spazio ai lati o un edge
int		find_matrix_edge(t_cubfile *file, int i, int j)
{
	if (left_top_right_ed(file, i, j))
		return 1;
	if (left_bott_right_ed(file, i, j))
		return 1;
	//SINISTRO INFERIORE E DESTRO
	// else if (left_edge(file, i, j) && bottom_edge(file, i, j) && right_edge(file, i, j) && ! top_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 1;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE LEFT BOTTOM RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_bott_right_ed);
	// 	return 1;
	// }

	//SUPERIORE DESTRO E INFERIORE
	// else if(top_edge(file, i, j) && right_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 1;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE TOP RIGHT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_right_bott_ed);
	// 	return 1;
	// }
	//SINISTRO E DESTRO
	// else if(left_edge(file, i, j) && right_edge(file, i, j) && !bottom_edge(file, i, j) && !top_edge(file,i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 1;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE LEFT RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_right_ed);
	// 	return 1;
	// }
	//SUPERIORE E SINISTRO
	// else if(top_edge(file, i, j) && left_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 1;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE TOP LEFT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_left_ed);
	// 	return 1;
	// }
	// //SUPERIORE E DESTRO
	// else if(top_edge(file, i, j) && right_edge(file, i, j) && !left_edge(file, i, j) && !bottom_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 1;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE TOP RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_right_ed);
	// 	return 1;
	// }
	// //SUPERIORE E INFERIORE
	// //!IN QUESTO CASO NON STO GESTENDO LA PROBLEMATICA DEL TAB CHE NE SLITTA 4 MA VIENE CONTATO COME 1. DOVENDO SEMPRE CONTROLLARE DA SOPRA FORSE È UN PROBLEMA CHE NON MI SI PRESENTERÀ MAI. UNA SOLUZIONE POSSIBILE È NON CONSIDERARE I TAB COME CHAR VALIDI
	// else if(top_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j) && !(right_edge(file, i, j)))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 1;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE TOP BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_bott_ed);
	// 	return 1;
	// }
	//DESTRO E INFERIORE
	// else if(right_edge(file, i, j) && bottom_edge(file, i, j) && !top_edge(file, i, j) && !left_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 1;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE RIGHT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->right_bott_ed);
	// 	return 1;
	// }
	//SINISTRO E INFERIORE
	// else if(left_edge(file, i, j) && bottom_edge(file, i, j) && !right_edge(file, i, j) && !top_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 1;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE LEFT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_bott_ed);
	// 	return 1;
	// }
	//SUPERIORE
	// else if (top_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !right_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 1;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE TOP\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_ed);
	// 	return 1;
	// }
	//DESTRO
	// else if(right_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 1;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->right_ed);
	// 	return 1;	
	// }
	//INFERIORE
	// else if(bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 1;
	// 	file->map_s->value_s->left_ed = 0;
	// 	printf("EDGE BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->bott_ed);
	// 	return 1;
	// }
	//SINISTRO
	// else if(left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
	// {
	// 	file->map_s->value_s->left_top_right_ed = 0;
	// 	file->map_s->value_s->left_bott_right_ed = 0;
	// 	file->map_s->value_s->top_right_bott_ed = 0;
	// 	file->map_s->value_s->left_right_ed = 0;
	// 	file->map_s->value_s->top_left_ed = 0;
	// 	file->map_s->value_s->top_right_ed = 0;
	// 	file->map_s->value_s->top_bott_ed = 0;
	// 	file->map_s->value_s->right_bott_ed = 0;
	// 	file->map_s->value_s->left_bott_ed = 0;
	// 	file->map_s->value_s->top_ed = 0;
	// 	file->map_s->value_s->right_ed = 0;
	// 	file->map_s->value_s->bott_ed = 0;
	// 	file->map_s->value_s->left_ed = 1;
	// 	printf("EDGE LEFT\t*****%d-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_ed);
	// 	return 1;
	// }
	printf("VALORE %d(%c) NON HA EDGE INTORNO---BOTTOMVALUE %d\n", file->map_s->map_matrix[i][j], file->map_s->map_matrix[i][j], file->map_s->value_s->bott_ed);
	printf("I-->%d\tJ-->%d\tMAPHEIGHT-->%d\tLENMAPT-->%d\tLENMAPD-->%d\n",i, j, (file->map_s->map_height - 1), (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1), (int)(ft_strlen(file->map_s->map_matrix[i + 1]) - 1));
	return 0;
}

// void	print_edge(t_map *s_map, int i, int j)
// {
// 	if (s_map->value_s->left_top_right_ed)
// 		printf("EDGE LEFT TOP RIGHT\t*****%c*****\n", s_map->map_matrix[i][j]);
// 	else if(s_map->value_s->left_ed)
// 		printf("EDGE LEFT\t*****%c*****\n", s_map->map_matrix[i][j]);
// 	else if(s_map->value_s->top_bott_ed)
// 		printf("EDGE TOP\t*****%c*****\n", s_map->map_matrix[i][j]);
// }
int	print_flag(t_value *value_s)
{
	printf("left_top_right_ed = %d\nleft_bott_right_ed = %d\ntop_right_bott_ed = %d\nleft_right_ed = %d\ntop_left_ed = %d\ntop_right_ed = %d\ntop_bott_ed = %d\nright_bott_ed = %d\nleft_bott_ed = %d\ntop_ed = %d\nright_ed = %d\nbott_ed = %d\nleft_ed = %d\n" , value_s->left_top_right_ed, value_s->left_bott_right_ed, value_s->top_right_bott_ed, value_s->left_right_ed, value_s->top_left_ed, value_s->top_right_ed, value_s->top_bott_ed, value_s->right_bott_ed, value_s->left_bott_ed, value_s->top_ed, value_s->right_ed, value_s->bott_ed, value_s->left_ed);
	return 0;
}

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

// int first_line_check(t_cubfile *file, int i, int j)
// {
// 	j = 0;
// 	if (i == 0)
// 	{
// 		if (left_top_right_ed(file, i, j))
// 		{
// 			file->map_s->value_s->ver_dir = 0;
// 			file->map_s->value_s->ver_coming_dir = 0;
// 			i++;
// 			return 0;
// 		}
// 		else if (top_left_ed(file, i, j))
// 		{
// 			j++;
// 			file->map_s->value_s->or_dir = 0;
// 			file->map_s->value_s->or_coming_dir = 0;
// 			while (file->map_s->map_matrix[i][j] && (top_ed(file, i, j) || top_bott_ed(file, i, j)))
// 			{
// 				j++;
// 			}
// 			if (top_right_bott_ed(file, i, j))
// 			{
// 				file->map_s->value_s->or_dir = 1;
// 				file->map_s->value_s->or_coming_dir = 1;
// 				return 0;
// 			}
// 			else if (top_right_ed(file, i, j))
// 			{
// 				file->map_s->value_s->ver_dir = 0;
// 				file->map_s->value_s->ver_coming_dir = 0;
// 				return 0;
// 			}
// 		}
// 		else
// 		{
// 			printf("errore\n");
// 			return 1;
// 		}
// 	}
// 	return 0;
// }

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
            while (file->map_s->map_matrix[*i][*j] && (top_ed(file, *i, *j) || top_bott_ed(file, *i, *j)))
            {
                (*j)++;
            }
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
				printf("CIA\n");
				(*j)++;
			}
			if (right_bott_ed(file, *i, *j))
			{
				file->map_s->value_s->or_dir = 1;
				file->map_s->value_s->or_coming_dir = 1;
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

	// if (!first_line_check(file, i, j))
	// {
	// 	if (file->map_s->value_s->ver_dir == 0 && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_coming_dir == 0)
	// 	{		
	// 		while (file->map_s->map_matrix[i])
	// 		{
	// 			printf("VALUE %d\tJ--> %d\tI--> %d\n", file->map_s->map_matrix[i][j], j, i);
	// 			i++;
	// 		}
	// 	}
		
	// }

	while (file->map_s->map_matrix[i])
	{
		if (!first_line_check(file, &i, &j))
		{
			// j = 0;

			if (file->map_s->value_s->ver_dir == 0 && file->map_s->map_matrix[i][j] && file->map_s->value_s->ver_coming_dir == 0)
			{
				move_to_down_check(file, &i, &j);
				printf("VALUE %d\tJ--> %d\tI--> %d\n", file->map_s->map_matrix[i][j], j, i);
			}
			j++;
			i++;
			
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
		printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	}
}