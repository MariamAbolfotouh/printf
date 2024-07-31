#ifndef _printf_h
#define _printf_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define op_buffer_size 1024
#define buffer_flush -1

#define null_string null
#define parameters_initiation {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define lowercase_convert 1
#define unsinged_convert 2

/**
 * struct parameters - the parameters of struct
 *
 * @unsign: if unsigned value
 * @plus_flag: if [+] flag specified
 * @minus_flag: if [-] flag specified
 * @space_flag: if [space] flag specified
 * @hashtag_flag: if [#] flag specified
 * @zero_flag: if [zero] flag specified
 * @width: width of field specified
 * @precision: precision of field specified
 * @h_mod: if [h] specified
 * @l_mod: if [l] specified
 */

typedef struct parameters
{
	unsigned int unsign	: 1;
	unsigned int plus_flag	: 1;
	unsigned int minus_flag	: 1;
	unsigned int space_flag	: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag	: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_mod	: 1;
	unsigned int l_mod	: 1;
} parameters_t;

/**
 * struct specifier - specifier
 *
 * @spec: format
 * @f: function
 */

typedef struct specifier
{
	char *spec;
	int (*f)(va_list, parameters_t *);
} spec_t;

int _puts(char *str);
int _putchar(int c);

int int_print(va_list p, parameters_t *parameters);
int char_print(va_list p, parameters_t *parameters);
int string_print(va_list p, parameters_t *parameters);
int percent_print(va_list p, parameters_t *parameters);
int S_print(va_list p, parameters_t *parameters);

int unsigned_print(va_list p, parameters_t *parameters);
int address_print(va_list p, parameters_t *parameters);
char *conv(long int number, int base, int flag, parameters_t *parameters);

int (*got_spec(char *s))(va_list p, parameters_t *parameters);
int got_print(char *s, va_list p, parameters_t *parameters);
int got_flag(char *s, parameters_t *parameters);
int got_modifier(char *s, parameters_t *parameters);
char *got_width(char *s, parameters_t *parameters, va_list p);

int hex_print(va_list p, parameters_t *parameters);
int HEX_print(va_list p, parameters_t *parameters);
int bin_print(va_list p, parameters_t *parameters);
int oct_print(va_list p, parameters_t *parameters);

int _strlen(char *s);
int num_print(char *str, parameters_t *parameters);
int _isdigit(int c);
int num_print_right(char *str, parameters_t *parameters);
int num_print_left(char *str, parameters_t *parameters);

void parameters_initial(parameters_t *parameters, va_list p);

int from_to(char *start, char *stop, char *exec);
int rev_print(va_list p, parameters_t *parameters);
int rot13_print(va_list p, parameters_t *parameters);

char *prec(char *ptr, parameters_t *parameters, va_list p);

int _printf(const char *format, ...);

#endif
