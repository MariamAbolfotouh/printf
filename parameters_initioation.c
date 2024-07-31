#include "main.h"

/**
 * parameters_initiation - clears struct fields and reset buffer
 * @parameters: parameters struct
 * @arg: pointer to aruments
 * Return: void
 */

void parameters_initiation(parameters_t *parameters, va_list arg)
{
	parameters->unsign = 0;
	parameters->plus_flag = 0;
	parameters->minus_flag = 0;
	parameters->space_flag = 0;
	parameters->hashtag_flag = 0;
	parameters->zero_flag = 0;
	parameters->width = 0;
	parameters->precision = UNIT_MAX;
	parameters->h_mod = 0;
	parameters->l_mod = 0;
	(void)arg;
}
