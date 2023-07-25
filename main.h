#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
  * struct specifiers - Struct .......
  * @sp: conversion spec
  * @fp: function ptr
  */

typedef struct sp
{
	char *sp;
	int (*fp)(va_list args);
} ald;


int _printf(const char *format, ...);
int _printchar(va_list args);
int _pwrite(char k);
int _printstr(va_list args);
int _printint(va_list args);
void _recursionint(int a);
int _printintbinary(va_list args);
int _printspec(char format, va_list args);
void _recursionintbinary(int a);
int _printfor(const char *format, va_list args);
int _print_invalid_spec(char prev_format, char format, int count);
int _validate_char(char _type);

#endif
