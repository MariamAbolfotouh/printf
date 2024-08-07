#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define op_buffer_size 1024
#define buffer_flush -1

#define NULL_STRING "(null)"
#define PARAMETERS_INITIATION {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

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
} params_t;

/**
 * struct specifier - specifier
 *
 * @specifier: format
 * @f: function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int int_print(va_list p, params_t *params);
int char_print(va_list p, params_t *params);
int string_print(va_list p, params_t *params);
int percent_print(va_list p, params_t *params);
int S_print(va_list p, params_t *params);

int unsigned_print(va_list p, params_t *params);
int address_print(va_list p, params_t *params);
char *conv(long int number, int base, int flag, params_t *params);

int (*got_spec(char *s))(va_list p, params_t *params);
int got_print(char *s, va_list p, params_t *params);
int got_flag(char *s, params_t *params);
int got_modifier(char *s, params_t *params);
char *got_width(char *s, params_t *params, va_list p);

int hex_print(va_list p, params_t *params);
int HEX_print(va_list p, params_t *params);
int bin_print(va_list p, params_t *params);
int oct_print(va_list p, params_t *params);

int _strlen(char *s);
int num_print(char *str, params_t *params);
int _isdigit(int c);
int num_print_right(char *str, params_t *params);
int num_print_left(char *str, params_t *params);

void parameters_initial(params_t *params, va_list p);

int from_to(char *from, char *to, char *except);
int rev_print(va_list p, params_t *params);
int rot13_print(va_list p, params_t *params);

char *got_prec(char *s, params_t *params, va_list p);

int _printf(const char *format, ...);

#endif
