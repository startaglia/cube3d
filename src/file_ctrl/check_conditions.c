# include "../../includes/cube3d.h"

//!IMPLEMENTARE GLI ANGOLI CONVESSI

//le condizioni in cui devo controllare oltre gli edge anche gli spazi sono tutti e 4 i lati
//! DA FARE BOTTOM E TESTARLI BENE TUTTI E 4



int	top_edge(t_cubfile *file, int i, int j)
{

	// bordo superiore
	if ((i == 0) || (i > 0 && j > (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1)) || ((i > 0 && j > (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1)) && ((file->map_s->map_matrix[i - 1][j] == 9) || (file->map_s->map_matrix[i - 1][j] > 10 && file->map_s->map_matrix[i - 1][j] <= 13) || (file->map_s->map_matrix[i - 1][j] == 32))))
		return 1;
	// printf("\t\tDENTRO\n");
	return 0;
}
int	right_edge(t_cubfile *file, int i, int j)
{
	//bordo destro
	if (j == (int)(ft_strlen(file->map_s->map_matrix[i]) - 1) || ((file->map_s->map_matrix[i][j + 1] == 9) || (file->map_s->map_matrix[i][j + 1] > 10 && file->map_s->map_matrix[i][j + 1] <= 13) || (file->map_s->map_matrix[i][j + 1] == 32)))
	{
		return 1;
	}
	return 0;
}
int	bottom_edge(t_cubfile *file, int i, int j)
{
	//bordo inferiore
	if (((i == (file->map_s->map_height - 1)) || (j > (int)(ft_strlen(file->map_s->map_matrix[i + 1]) - 1))) || ((file->map_s->map_matrix[i + 1][j] == 9) || (file->map_s->map_matrix[i + 1][j] > 10 && file->map_s->map_matrix[i + 1][j] <= 13) || (file->map_s->map_matrix[i + 1][j] == 32)))
		return 1;
	return 0;
}
int	left_edge(t_cubfile *file, int i, int j)
{
	//bordo sinistro
	if ((j == 0 && i == 0) || (j == 0 && !((file->map_s->map_matrix[i][j] == 9) || (file->map_s->map_matrix[i][j] > 10 && file->map_s->map_matrix[i][j] <= 13) || (file->map_s->map_matrix[i][j] == 32))))
	{
		// printf("VALORE %d\n", file->map_s->map_matrix[i][j]);
		return 1;
	}
	return 0;
}

int	reset_ed_flags(t_cubfile *file)
{
	file->map_s->value_s->left_top_right_bott_ed = 0;
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
	file->map_s->value_s->left_ed = 0;
	return 0;
}

int	left_top_right_bot_ed(t_cubfile *file, int i, int j)
{
	// printf("\ntoprightbotlefted-->%d\n", file->map_s->value_s->left_top_right_bott_ed);
	// printf("lefttoprighted-->%d\tleftbottrighted-->%d\ttoprightbotted-->%d", file->map_s->value_s->left_top_right_ed, file->map_s->value_s->left_bott_right_ed, file->map_s->value_s->top_right_bott_ed);
	// printf("\nleftrighted-->%d\t\ttoplefted-->%d\t\ttoprighted-->%d", file->map_s->value_s->left_right_ed, file->map_s->value_s->top_left_ed, file->map_s->value_s->top_right_ed);
	// printf("\ntopbotted-->%d\t\trightbotted-->%d\t\ttopped-->%d", file->map_s->value_s->top_bott_ed, file->map_s->value_s->right_bott_ed, file->map_s->value_s->top_ed);
	// printf("\nrighted-->%d\t\tbotted-->%d\t\tlefted-->%d\n", file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed, file->map_s->value_s->left_ed);

	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);

	//SINISTRO SUPERIORE DESTRO E INFERIORE
	if (left_edge(file, i, j) && top_edge(file, i, j) && right_edge(file, i, j) && bottom_edge(file, i, j))
	{
		file->map_s->value_s->left_top_right_bott_ed = 1;
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
		file->map_s->value_s->left_ed = 0;
		printf("EDGE LEFT TOP RIGHT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_top_right_bott_ed);
		printf("\ntoprightbotlefted-->%d\n", file->map_s->value_s->left_top_right_bott_ed);
	// printf("lefttoprighted-->%d\tleftbottrighted-->%d\ttoprightbotted-->%d", file->map_s->value_s->left_top_right_ed, file->map_s->value_s->left_bott_right_ed, file->map_s->value_s->top_right_bott_ed);
	// printf("\nleftrighted-->%d\t\ttoplefted-->%d\t\ttoprighted-->%d", file->map_s->value_s->left_right_ed, file->map_s->value_s->top_left_ed, file->map_s->value_s->top_right_ed);
	// printf("\ntopbotted-->%d\t\trightbotted-->%d\t\ttopped-->%d", file->map_s->value_s->top_bott_ed, file->map_s->value_s->right_bott_ed, file->map_s->value_s->top_ed);
	// printf("\nrighted-->%d\t\tbotted-->%d\t\tlefted-->%d\n", file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed, file->map_s->value_s->left_ed);
		return 1;
	}
	return 0;
}


int	left_top_right_ed(t_cubfile *file, int i, int j)
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
		printf("EDGE LEFT TOP RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_top_right_ed);
		return 1;
	}
	return 0;
}

int	left_bott_right_ed(t_cubfile *file, int i, int j)
{
	//SINISTRO INFERIORE E DESTRO
	if (left_edge(file, i, j) && bottom_edge(file, i, j) && right_edge(file, i, j) && ! top_edge(file, i, j))
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
		printf("EDGE LEFT BOTTOM RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_bott_right_ed);
		return 1;
	}
	return 0;
}

int	top_right_bott_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE DESTRO E INFERIORE
	if(top_edge(file, i, j) && right_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j))
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
		printf("EDGE TOP RIGHT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_right_bott_ed);
		return 1;
	}
	return 0;
}

int	left_right_ed(t_cubfile *file, int i, int j)
{
	//SINISTRO E DESTRO
	if(left_edge(file, i, j) && right_edge(file, i, j) && !bottom_edge(file, i, j) && !top_edge(file,i, j))
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
		printf("EDGE LEFT RIGHT\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_right_ed);
		return 1;
	}
	return 0;
}

int	top_left_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE E SINISTRO
	if(top_edge(file, i, j) && left_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
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
		printf("EDGE TOP LEFT\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_left_ed);
		return 1;
	}
	return 0;
}

int top_right_ed(t_cubfile *file, int i, int j)
{

	//SUPERIORE E DESTRO
	if(top_edge(file, i, j) && right_edge(file, i, j) && !left_edge(file, i, j) && !bottom_edge(file, i, j))
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

		file->map_s->value_s->or_dir = -1;
		file->map_s->value_s->ver_dir = 0;
		printf("EDGE TOP RIGHT\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_right_ed);

		// printf("lefttoprighted-->%d\tleftbottrighted-->%d\ttoprightbotted-->%d", file->map_s->value_s->left_top_right_ed, file->map_s->value_s->left_bott_right_ed, file->map_s->value_s->top_right_bott_ed);
		// printf("\nleftrighted-->%d\t\ttoplefted-->%d\t\ttoprighted-->%d", file->map_s->value_s->left_right_ed, file->map_s->value_s->top_left_ed, file->map_s->value_s->top_right_ed);
		// printf("\ntopbotted-->%d\t\trightbotted-->%d\t\ttopped-->%d", file->map_s->value_s->top_bott_ed, file->map_s->value_s->right_bott_ed, file->map_s->value_s->top_ed);
		// printf("\nrighted-->%d\t\tbotted-->%d\t\tlefted-->%d\n", file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed, file->map_s->value_s->left_ed);

		return 1;
	}
	return 0;
}

int top_bott_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE E INFERIORE
	//!IN QUESTO CASO NON STO GESTENDO LA PROBLEMATICA DEL TAB CHE NE SLITTA 4 MA VIENE CONTATO COME 1. DOVENDO SEMPRE CONTROLLARE DA SOPRA FORSE È UN PROBLEMA CHE NON MI SI PRESENTERÀ MAI. UNA SOLUZIONE POSSIBILE È NON CONSIDERARE I TAB COME CHAR VALIDI
	if(top_edge(file, i, j) && bottom_edge(file, i, j) && !left_edge(file, i, j) && !(right_edge(file, i, j)))
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
		printf("EDGE TOP BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_bott_ed);
		return 1;
	}
	return 0;
}

int right_bott_ed(t_cubfile *file, int i, int j)
{
	//DESTRO E INFERIORE
	if(right_edge(file, i, j) && bottom_edge(file, i, j) && !top_edge(file, i, j) && !left_edge(file, i, j))
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
		printf("EDGE RIGHT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->right_bott_ed);
		return 1;
	}
	return 0;
}

int	left_bott_ed(t_cubfile *file, int i, int j)
{
	//SINISTRO E INFERIORE
	if(left_edge(file, i, j) && bottom_edge(file, i, j) && !right_edge(file, i, j) && !top_edge(file, i, j))
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
		printf("EDGE LEFT BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_bott_ed);
		return 1;
	}
	return 0;
}

int	top_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE
	if (top_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !right_edge(file, i, j))
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
		printf("EDGE TOP\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_ed);
		return 1;
	}
	return 0;
}

int	right_ed(t_cubfile *file, int i, int j)
{
	//DESTRO
	if(right_edge(file, i, j) && !bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j))
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
		printf("EDGE RIGHT\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->right_ed);
		return 1;	
	}
	return 0;
}

int	bott_ed(t_cubfile *file, int i, int j)
{
	//INFERIORE
	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);

	if(bottom_edge(file, i, j) && !left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j))
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
		printf("EDGE BOTTOM\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->bott_ed);
	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);
		return 1;
	}
	return 0;
}

int left_ed(t_cubfile *file, int i, int j)
{
	//SINISTRO
	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);
	if(left_edge(file, i, j) && !top_edge(file, i, j) && !right_edge(file, i, j) && !bottom_edge(file, i, j))
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

		printf("EDGE LEFT\t\t*****%d-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_ed);

		return 1;
	}
	// printf("LEFTEDGE %d\n", left_edge(file, i, j));
	// printf("TOPEDGE %d\n", top_edge(file, i, j));
	// printf("RIGHTEDGE %d\n", right_edge(file, i, j));
	// printf("BOTTOMEDGE %d\n", bottom_edge(file, i, j));

	return 0;
}


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