# include "../../includes/cube3d.h"
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
		printf("EDGE LEFT RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_right_ed);
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
		printf("EDGE TOP LEFT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_left_ed);
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

		printf("EDGE TOP RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_right_ed);
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
		printf("EDGE TOP\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->top_ed);
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
		printf("EDGE RIGHT\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->right_ed);
		return 1;	
	}
	return 0;
}

int	bott_ed(t_cubfile *file, int i, int j)
{
	//INFERIORE
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
		printf("EDGE BOTTOM\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->bott_ed);
		return 1;
	}
	return 0;
}

int left_ed(t_cubfile *file, int i, int j)
{
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
		printf("EDGE LEFT\t*****%d-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_ed);
		return 1;
	}
	return 0;
}