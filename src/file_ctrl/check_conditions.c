# include "../../includes/cube3d.h"

//!IMPLEMENTARE GLI ANGOLI CONVESSI

//le condizioni in cui devo controllare oltre gli edge anche gli spazi sono tutti e 4 i lati
//! DA FARE BOTTOM E TESTARLI BENE TUTTI E 4

int	space_ch(char c)
{
		if ((c == 9) || (c > 10 && c <= 13) || (c == 32))
			return 1;
		return 0;
}

int	top_ed_cond(t_cubfile *file, int i, int j)
{
	if ((i == 0) || (i > 0 && (j > (int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1) || space_ch(file->map_s->map_matrix[i - 1][j]))))
	{
		return 1;
	}
	return 0;
}
int	right_ed_cond(t_cubfile *file, int i, int j)
{
	//condizioni bordo destro
	if (j == (int)(ft_strlen(file->map_s->map_matrix[i]) - 1)
		|| (j == (int)(ft_strlen(file->map_s->map_matrix[i]) - 1) && i == (file->map_s->map_height - 1))
		|| (!file->map_s->value_s->ver_dir && i > 0  && (j < ((int)(ft_strlen(file->map_s->map_matrix[i - 1]) - 1) && (space_ch(file->map_s->map_matrix[i][j + 1])))))
		|| (j < (int)(ft_strlen(file->map_s->map_matrix[i]) - 1) && (space_ch(file->map_s->map_matrix[i][j + 1]) && (file->map_s->value_s->ver_dir == -1)))
		|| (j < (int)(ft_strlen(file->map_s->map_matrix[i]) - 1) && (space_ch(file->map_s->map_matrix[i][j + 1]) && (!file->map_s->value_s->ver_dir))))
	{
		return 1;
	}
	return 0;
}
int	bott_ed_cond(t_cubfile *file, int i, int j)
{
	//bordo inferiore
	if ((i == (file->map_s->map_height - 1)) || (i > 0 && space_ch(file->map_s->map_matrix[i + 1][j])))
		return 1;
	return 0;
}
int	left_ed_cond(t_cubfile *file, int i, int j)
{
	//bordo sinistro
	if ((j == 0 && i == 0) || (j > 0 && (space_ch(file->map_s->map_matrix[i][j - 1]))))
	{
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
	//SINISTRO SUPERIORE DESTRO E INFERIORE
	if (left_ed_cond(file, i, j) && top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && bott_ed_cond(file, i, j))
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
		return 1;
	}
	return 0;
}


int	left_top_right_ed(t_cubfile *file, int i, int j)
{
	//SINISTRO SUPERIORE E DESTRO
	if (left_ed_cond(file, i, j) && top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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
	if (left_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && right_ed_cond(file, i, j) && ! top_ed_cond(file, i, j))
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
	// printf("\tVALORE-->%d\tTOP-->%d\tRIGHT-->%d\tLEFT-->%d\tBOTTOM-->%d\n", file->map_s->map_matrix[i][j], top_ed_cond(file, i, j), right_ed_cond(file, i, j), left_ed_cond(file, i, j), bott_ed_cond(file, i, j));
	if(top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j))
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
	if(left_ed_cond(file, i, j) && right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !top_ed_cond(file,i, j))
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
	if(top_ed_cond(file, i, j) && left_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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
	// printf("TOP-->%d\tRIGHT-->%d\tLEFT-->%d\tBOTTOM-->%d\n", top_ed_cond(file, i, j), right_ed_cond(file, i, j), left_ed_cond(file, i, j), bott_ed_cond(file, i, j));
	return 0;
}

int top_right_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE E DESTRO
	if(top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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
		return 1;
	}
	return 0;
}

int top_bott_ed(t_cubfile *file, int i, int j)
{
	//SUPERIORE E INFERIORE
	//!IN QUESTO CASO NON STO GESTENDO LA PROBLEMATICA DEL TAB CHE NE SLITTA 4 MA VIENE CONTATO COME 1. DOVENDO SEMPRE CONTROLLARE DA SOPRA FORSE È UN PROBLEMA CHE NON MI SI PRESENTERÀ MAI. UNA SOLUZIONE POSSIBILE È NON CONSIDERARE I TAB COME CHAR VALIDI
	if(top_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !(right_ed_cond(file, i, j)))
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
	if(right_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !left_ed_cond(file, i, j))
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
	// printf("TOP-->%d\tRIGHT-->%d\tLEFT-->%d\tBOTTOM-->%d\n", top_ed_cond(file, i, j), right_ed_cond(file, i, j), left_ed_cond(file, i, j), bott_ed_cond(file, i, j));
	//SINISTRO E INFERIORE
	if(left_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !top_ed_cond(file, i, j))
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
	// printf("\tVALORE-->%d\tTOP-->%d\tRIGHT-->%d\tLEFT-->%d\tBOTTOM-->%d\n", file->map_s->map_matrix[i][j], top_ed_cond(file, i, j), right_ed_cond(file, i, j), left_ed_cond(file, i, j), bott_ed_cond(file, i, j));	
	if (top_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !right_ed_cond(file, i, j))
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
	// printf("VALORE %d\tTOP-->%d\tRIGHT-->%d\tLEFT-->%d\tBOTTOM-->%d\n", file->map_s->map_matrix[i][j], top_ed_cond(file, i, j), right_ed_cond(file, i, j), left_ed_cond(file, i, j), bott_ed_cond(file, i, j));

	//DESTRO
	if(right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !top_ed_cond(file, i, j))
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
	// printf("VALUE %d\n", file->map_s->map_matrix[i][j]);
	// printf("TOP %d\n", top_ed_cond(file, i, j));
	// printf("RIGHT %d\n", right_ed_cond(file, i, j));
	// printf("BOTT %d\n", bott_ed_cond(file, i, j));
	// printf("LEFT %d\n", left_ed_cond(file, i, j));
	// printf("CONC %d\n", file->map_s->concave_corner);
	// printf("CONV %d\n", file->map_s->convex_corner);
	// printf("VERDIR %d\n", file->map_s->value_s->ver_dir);
	// printf("ORDIR %d\n\n", file->map_s->value_s->or_dir);
	//INFERIORE
	if(bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !right_ed_cond(file, i, j))
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
	// printf("VALUE %d\n", file->map_s->map_matrix[i][j]);
	// printf("TOP %d\n", top_ed_cond(file, i, j));
	// printf("RIGHT %d\n", right_ed_cond(file, i, j));
	// printf("BOTT %d\n", bott_ed_cond(file, i, j));
	// printf("LEFT %d\n", left_ed_cond(file, i, j));
	// printf("CONC %d\n", file->map_s->concave_corner);
	// printf("CONV %d\n", file->map_s->convex_corner);
	// printf("VERDIR %d\n", file->map_s->value_s->ver_dir);
	// printf("ORDIR %d\n\n", file->map_s->value_s->or_dir);
	//SINISTRO
	// printf("leftflag-->%d\ttopflag-->%d\trightflag-->%d\tbottflag-->%d\n", file->map_s->value_s->left_ed, file->map_s->value_s->top_ed, file->map_s->value_s->right_ed, file->map_s->value_s->bott_ed);
	if(left_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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

		printf("EDGE LEFT\t\t*****%c-->%d*****\n", file->map_s->map_matrix[i][j], file->map_s->value_s->left_ed);

		return 1;
	}
	// printf("LEFTEDGE %d\n", left_ed_cond(file, i, j));
	// printf("TOPEDGE %d\n", top_ed_cond(file, i, j));
	// printf("RIGHTEDGE %d\n", right_ed_cond(file, i, j));
	// printf("BOTTOMEDGE %d\n", bott_ed_cond(file, i, j));

	return 0;
}


	//SINISTRO INFERIORE E DESTRO
	// else if (left_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && right_ed_cond(file, i, j) && ! top_ed_cond(file, i, j))
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
	// else if(top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j))
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
	// else if(left_ed_cond(file, i, j) && right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !top_ed_cond(file,i, j))
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
	// else if(top_ed_cond(file, i, j) && left_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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
	// else if(top_ed_cond(file, i, j) && right_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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
	// else if(top_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !(right_ed_cond(file, i, j)))
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
	// else if(right_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !left_ed_cond(file, i, j))
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
	// else if(left_ed_cond(file, i, j) && bott_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !top_ed_cond(file, i, j))
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
	// else if (top_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !right_ed_cond(file, i, j))
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
	// else if(right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !top_ed_cond(file, i, j))
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
	// else if(bott_ed_cond(file, i, j) && !left_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !right_ed_cond(file, i, j))
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
	// else if(left_ed_cond(file, i, j) && !top_ed_cond(file, i, j) && !right_ed_cond(file, i, j) && !bott_ed_cond(file, i, j))
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