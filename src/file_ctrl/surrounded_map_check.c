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

// int	first_line_pipe(t_cubfile *file)
// {
// 	int	i;
// 	int first_1_index;
	
// 	first_1_index = 0;
// 	i = 0;
// 	printf("VALORE DI QUELLO SOTTO STRINGA %s\n", file->map_s->map_matrix[0]);
	
// 	// controllo se sotto c'è una linea vuota, in questo caso è sempre una mappa non valida
// 	if (file->map_s->map_matrix[1] == NULL)
// 	{
// 		printf("MAPPA ERRATA\n");
// 		return 1;
// 	}


// 	//ciclo per trovare l'indice del primo 1 utile nella prima stringa
// 	while (file->map_s->map_matrix[0][first_1_index])
// 	{
// 		//scorro tutti i char spazi
// 		while ((file->map_s->map_matrix[0][first_1_index] >= 9 && file->map_s->map_matrix[0][first_1_index] <=13) || (file->map_s->map_matrix[0][first_1_index] == 32))
// 		{
// 		first_1_index += converter_tab_space(file->map_s->map_matrix[0][first_1_index], first_1_index);
// 			printf("PS-->VALORE DI QUELLO DOVE STO %d\tfirst 1 index-->%d\n", file->map_s->map_matrix[0][first_1_index], first_1_index);
// 			first_1_index++;
// 		}
// 		// prima controllo se è diverso da 1, quindi escludo ogni altro char.
// 		if (file->map_s->map_matrix[0][first_1_index] != '1')
// 		{
// 			printf("PS-->NON C'È UN 1 ALLA PRIMA CASELLA UTILE A SINISTRA, MAPPA NON VALIDA\n");
// 			return 1;
// 		}
// 		if (file->map_s->map_matrix[0][first_1_index] == '1')
// 			break;
// 		first_1_index++;
// 	}
// 	printf("PS-->VALORE DI QUELLO DOVE STO FUORI %d\tfirst 1 index-->%d\n\n", file->map_s->map_matrix[0][first_1_index], first_1_index);
// 	// ora ho l'index dove si trova il primo 1 utile della prima stringa, lo devo confrontare con il primo 1 utile della seconda stringa per vedere se è una pipe fluttuante

// 	//ciclo per trovare l'indice del primo 1 utile nella seconda stringa
// 	while (file->map_s->map_matrix[1][i])
// 	{
// 		//scorro tutti i char spazi
// 		while ((file->map_s->map_matrix[1][i] >= 9 && file->map_s->map_matrix[1][i] <=13) || (file->map_s->map_matrix[1][i] == 32))
// 		{
// 			printf("SS-->VALORE DI QUELLO DOVE STO %d\tfirst 1 index-->%d\n", file->map_s->map_matrix[1][i], i);
// 			i++;
// 		}
// 		// prima controllo se è diverso da 1, quindi escludo ogni altro char.
// 		if (file->map_s->map_matrix[1][i] != '1')
// 		{
// 			printf("SS-->NON C'È UN 1 ALLA PRIMA CASELLA UTILE A SINISTRA, MAPPA NON VALIDA\n");
// 			return 1;
// 		}
// 		if (file->map_s->map_matrix[1][i] == '1')
// 			break;
// 		i++;
// 	}
// 	printf("SS-->VALORE DI QUELLO DOVE STO FUORI %d\tfirst 1 index-->%d\n\n", file->map_s->map_matrix[1][i], i);
// 	printf("IND FIRST 1--> %d\tIND SECOND 1--> %d\n\n", first_1_index, i);

// 	if (first_1_index > i)
// 	{
// 		printf("PIPE FLUTTUANTE\n");
// 	}
// 	else
// 	{
// 		printf("PIPE BUONA\n");
// 	}
	
		

// 	// //ciclo per trovare l'indice del primo 1
// 	// while (file->map_s->map_matrix[1][first_1_index])
// 	// {
// 	// 	//scorro tutti i char spazi
// 	// 	while ((file->map_s->map_matrix[1][first_1_index] >= 9 && file->map_s->map_matrix[1][first_1_index] <=13) || (file->map_s->map_matrix[1][first_1_index] == 32))
// 	// 	{
// 	// 		printf("VALORE DI QUELLO DOVE STO %d\tfirst 1 index-->%d\n", file->map_s->map_matrix[0][first_1_index], first_1_index);
// 	// 		first_1_index++;
// 	// 	}
// 	// 	printf("VALORE DI QUELLO DOVE STO %d\tfirst 1 index-->%d\n", file->map_s->map_matrix[0][first_1_index], first_1_index);
		
// 	// 	//lo aumento ancora di 1 perchè ora punta all'ultimo char spazio
// 	// 	first_1_index++;
// 	// 	printf("VALORE DI QUELLO DOVE STO %d\tfirst 1 index-->%d\n", file->map_s->map_matrix[0][first_1_index], first_1_index);
		
// 	// 	//controllo se è diverso da 1, quindi escludo ogni altro char.
// 	// 	if (file->map_s->map_matrix[0][first_1_index] != '1')
// 	// 	{
// 	// 		printf("NON C'È UN 1 ALLA PRIMA CASELLA UTILE A SINISTRA, MAPPA NON VALIDA\n");
// 	// 		return 1;
// 	// 	}
// 	// 	// ora ho l'index dove si trova il primo 1 utile della prima stringa
// 	// 	// lo devo confrontare con il primo 1 utile della seconda stringa per vedere se è una pipe fluttuante




// 		// if (((file->map_s->map_matrix[1][i] >= 9 && file->map_s->map_matrix[1][i] <=13) || (file->map_s->map_matrix[1][i] == 32)))
// 		// {
// 		// 	// printf("VALORE DI QUELLO SOTTO STRINGA %d\n", file->map_s->map_matrix[1][i]);
// 		// 	// printf("SOTTO C'È UNO SPAZIO. PUÒ ESSERE UNA PIPE VOLANTE %d\n", file->map_s->map_matrix[i][1]);
// 		// 	i++;
// 		// }
// 		// else
// 		// {
// 		// 	printf("C'È QUALCOSA, NON È UNA PIPE VOLANTE\n");
// 		// 	return 0;
// 		// }


// 	return 1;
// 	}


// int	flying_pipe_check(t_cubfile *file)
// {
// 	int	i;
// 	int	j;
// 	// int	up;
// 	// int	down;
// 	// int	temp_i_index;
// 	// // int	temp_j_index;


// 	i = 0;
// 	int lele = 0;
// 	while (file->map_s->map_matrix[i])
// 	{
// 		j = 0;
// 		(void) j;
// 		if (i == 0)
// 		{
// 			lele = first_line_pipe(file);
// 			printf("RISULTATO--> %d\n", lele);
// 		}
// 		printf("STRINGA--> %s\n", file->map_s->map_matrix[i]);
// 		if (file->map_s->map_matrix[i] == NULL)
// 		{
// 			printf("MAPPA ERRATA\n");
// 			return 1;
// 		}
// 		i++;
// 	}
// 	return 3;
	
// 	// up = 0;
// 	// down = 0;
// 	// temp_i_index = 0;
// 	// // temp_j_index = 0;

// 	// while (file->map_s->map_matrix[i])
// 	// {
// 	// 	j = 0;
// 	// 	while (file->map_s->map_matrix[i][j])
// 	// 	{
// 	// 		//controllo se sono alla prima linea della matrix. qui non devo controllare se sopra ci sono spazi
// 	// 		if (i == 0)
// 	// 		{
// 	// 			temp_i_index = i;
// 	// 			temp_i_index = temp_i_index +1;
// 	// 			if (file->map_s->map_matrix[i][j] == '1')
// 	// 			{
// 	// 				if (((file->map_s->map_matrix[temp_i_index][j] >= 9 && file->map_s->map_matrix[temp_i_index][j] <=13) || (file->map_s->map_matrix[temp_i_index][j] == 32)))
// 	// 					printf("SOTTO C'È UNO SPAZIO. PUÒ ESSERE UNA PIPE VOLANTE %d\n", file->map_s->map_matrix[temp_i_index][j]);
// 	// 				else
// 	// 				{
// 	// 					printf("NON È UNA PIPE VOLANTE\n");
// 	// 					i++;
// 	// 					continue;
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 		else if (i > 0)
// 	// 		{
// 	// 			// printf("I--> %d\n", i);
				
// 	// 			// se sto puntando a 1 o 0, inizio a controllare sopra e sotto
// 	// 			if (file->map_s->map_matrix[i][j] && (file->map_s->map_matrix[i][j] == '1' || file->map_s->map_matrix[i][j] == '0'))
// 	// 			{
// 	// 				printf("I--> %d\n", i);

// 	// 				printf("J--> %d\tVALUE--> %c\n", j, file->map_s->map_matrix[i][j]);
// 	// 				temp_i_index = i;
// 	// 				// temp_j_index = j;
// 	// 				temp_i_index--;
// 	// 				printf("TEMP INDEX--> %d\n", temp_i_index);
// 	// 				printf("VALUE SOPRA DIO--> %c\n", file->map_s->map_matrix[0][j]);
// 	// 				printf("STRINGA--> %s\n", file->map_s->map_matrix[temp_i_index]);
// 	// 				printf("VALUE SOPRA--> %c\n", file->map_s->map_matrix[temp_i_index][j]);

					
// 	// 				for (j = 0; j < (int)ft_strlen(file->map_s->map_matrix[i]); j++)
// 	// 				{
// 	// 					if (((file->map_s->map_matrix[temp_i_index - 1][j] >= 9 && file->map_s->map_matrix[temp_i_index - 1][j] <=13) || (file->map_s->map_matrix[temp_i_index - 1][j] == 32)))
// 	// 							up = 1;
// 	// 					else if (j == (int)ft_strlen(file->map_s->map_matrix[i]) - 1)
// 	// 					{
// 	// 						if (((file->map_s->map_matrix[temp_i_index + 1][j] >= 9 && file->map_s->map_matrix[temp_i_index + 1][j] <=13) || (file->map_s->map_matrix[temp_i_index + 1][j] == 32)))
// 	// 							down = 1;
// 	// 					}
// 	// 					if (up == 1 && down == 1)
// 	// 					{
// 	// 						printf("C'È UNA PIPE VOLANTE, MAPPA ERRATA ESCI\n");
// 	// 						return (1);
// 	// 					}
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// 	return (0);
// }







// int	flying_pipe_check(t_cubfile *file)
// {
// 	int	i;
// 	int j;
// 	int	up;
// 	int down;
// 	int	temp_i_index;
// 	// int	temp_j_index;


// 	i = 0;
// 	up = 0;
// 	down = 0;
// 	temp_i_index = 0;
// 	// temp_j_index = 0;

// 	while (file->map_s->map_matrix[i])
// 	{
// 		j = 0;
// 		// if(file->map_s->map_matrix[i + 1])
// 			// printf("SOTTO C'È %d\n", file->map_s->map_matrix[i + 1][j]);
// 		// printf("SOTTO C'È %d\n", file->map_s->map_matrix[i + 1][j]);
// 		while (file->map_s->map_matrix[i][j])
// 		{
// 			//controllo se sono alla prima linea della matrix. qui non devo controllare se sopra ci sono spazi
// 			if (i == 0)
// 			{
// 				if (file->map_s->map_matrix[i][j] == '1')
// 				{
// 					temp_i_index = i + 1;
// 					if (((file->map_s->map_matrix[temp_i_index][j] >= 9 && file->map_s->map_matrix[temp_i_index][j] <=13) || (file->map_s->map_matrix[temp_i_index][j] == 32)))
// 						printf("SOTTO C'È UNO SPAZIO. PUÒ ESSERE UNA PIPE VOLANTE %d\n", file->map_s->map_matrix[temp_i_index][j]);
// 				}
// 			}
// 			else if (i > 0)
// 			{
// 				printf("I--> %d\n", i);
// 				printf("VALORE--> %c\n", file->map_s->map_matrix[i][j]);

// 				if (file->map_s->map_matrix[i][j] && (file->map_s->map_matrix[i][j] == '1' || file->map_s->map_matrix[i][j] == '0'))
// 				{
// 					printf("J--> %d\n", j);
// 					printf("TEMP I INDEX--> %d\n", temp_i_index);


// 					// temp_i_index = i--;

// 					printf("ENTRO--> %c\n", file->map_s->map_matrix[i--][j]);
// 					if (((file->map_s->map_matrix[i][j] >= 9 && file->map_s->map_matrix[i][j] <=13) || (file->map_s->map_matrix[i][j] == 32)))
// 						up = 1;
// 					temp_i_index = i + 1;
// 					if (((file->map_s->map_matrix[i++][j] >= 9 && file->map_s->map_matrix[i++][j] <=13) || (file->map_s->map_matrix[i++][j] == 32)))
// 						down = 1;
// 				}
// 			}
// 			if (up == 1 || down == 1)
// 			{
// 				printf("C'È UNA PIPE VOLANTE, MAPPA ERRATA ESCI\n");
// 			}
// 			// printf("%c", file->map_s->map_matrix[i][j]);
// 			j++;
// 		}
// 		printf("\t	len della stringa --> %ld", ft_strlen(file->map_s->map_matrix[i]));
// 		printf("\n");
// 	i++;
// 	}
// 	return 6;
// }


int		space_on_right(t_cubfile *file, int i, int j)
{
	if (file->map_s->map_matrix[i][j + 1] == 0)
		printf("\nLINEA INDEX %d C'È UN 1 ALL'ULTIMO POSTO J, POSSO GIRARE VERSO IL BASSO\n", i);
	else if (file->map_s->map_matrix[i][j + 1] == 32)
		printf("\nLINEA INDEX %d POSTO INDEX %d L'UNO HA UNO SPAZIO SUL SUO LATO DESTRO, GIRO VERSO IL BASSO\n", i, j);
	return (1);
}


void	surrounded_map_check(t_cubfile *file)
{
	(void) file;
	int test = 0;
	// test = flying_pipe_check(file);
	(void) test;
	printf("*************SURROUNDED CONTROL***************\n");
	print_matrix(file->map_s->map_matrix);
	int i = -1;
	int j = 0;
	while (file->map_s->map_matrix[++i])
	{
		j = 0;
		printf("VALUE SOTTO\n");
		while (file->map_s->map_matrix[i][j])
		{
			space_on_right(file, i, j);
			printf("%d", file->map_s->map_matrix[i][j]);
			j++;
		}
		printf("\n");
		// i++;
	}
	i = 0;
	//caso prima linea
	//solo so la i di dove sto controllando è == 0 (o -1 prima del ciclo) devo semplicemte scorrere finchè un uno non trova uno spazio alla sua destra

	//faccio le funzioni degli spazi:

	// print_matrix_char(file->map_s->map_matrix);
	// int	i;
	// int j;

	// i = 0;
	// while (file->map_s->map_matrix[i])
	// {
	// 	j = 0;
	// 	while (file->map_s->map_matrix[i][j])
	// 	{
	// 		j++;
	// 	}
	// 	i++;
	// 	printf("LENGHT STRING_CHAR--> %d\n", j);
	// 	printf("LENGHT STRING--> %ld\n", ft_strlen(file->map_s->map_matrix[i]));
	// }
	

}