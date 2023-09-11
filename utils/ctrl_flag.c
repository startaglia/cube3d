# include "../includes/cube3d.h"







int	print_flags(t_value *value_s)
{
	printf("left_top_right_ed = %d\nleft_bott_right_ed = %d\ntop_right_bott_ed = %d\nleft_right_ed = %d\ntop_left_ed = %d\ntop_right_ed = %d\ntop_bott_ed = %d\nright_bott_ed = %d\nleft_bott_ed = %d\ntop_ed = %d\nright_ed = %d\nbott_ed = %d\nleft_ed = %d\n" , value_s->left_top_right_ed, value_s->left_bott_right_ed, value_s->top_right_bott_ed, value_s->left_right_ed, value_s->top_left_ed, value_s->top_right_ed, value_s->top_bott_ed, value_s->right_bott_ed, value_s->left_bott_ed, value_s->top_ed, value_s->right_ed, value_s->bott_ed, value_s->left_ed);
	return 0;
}

// int	print_one_flag(t_value *value_s, char c)
// {
// 	if ()
// }