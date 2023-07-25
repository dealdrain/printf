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
void _recursionint(int e);
char *convert(unsigned long int number, int ib, int lcase);
int _printintbinary(va_list args);
int _printspec(char format, va_list args);
void _recursionintbinary(int l);
int _printform(const char *form, va_list args);
int _printinvalidspec(char old_form, char format, int n);
int _validatechar(char meth);

#endif
