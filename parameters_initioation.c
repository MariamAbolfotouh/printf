#include "main.h"

/**
 * parameters_initial - clears struct fields and reset buffer
 * @params: parameters struct
 * @p: pointer to arguments
 * Return: void
 */

void parameters_initial(params_t *params, va_list p)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->minus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_mod = 0;
	params->l_mod = 0;
	(void)p;
}
