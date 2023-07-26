#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define F_MINUS (1 << 0)
#define F_PLUS (1 << 1)
#define F_ZERO (1 << 2)
#define F_HASH (1 << 3)
#define F_SPACE (1 << 4)

/**
 * struct fmt - the structure we are using in our codes
 *
 * @fmt: the type of format
 * @fn: the function to call/point to
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;
int _printf(const char *format, ...);
int hPrint(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);
/****FUNCTIONS IN THE CODE****/
int pChar(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pString(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pPercent(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int pInt(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pBinary(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pUnsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pOctal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pHexadecimal(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pHexaUpper(va_list types, char buffer[], int flags, int width,
		int precision, int size);
int pHexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

int pNonPrintable(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int pPointer(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int gFlag(const char *format, int *i);
int gWidth(const char *format, int *i, va_list list);
int gPrecision(const char *format, int *i, va_list list);
int gSize(const char *format, int *i);

int pReverse(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int pRot13string(va_list types, char buffer[], int flags, int width,
		int precision, int size);

int handleWriteChar(char c, char buffer[], int flags, int width,
		int precision, int size);
int writeNumber(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int writeNum(int ind, char bff[], int flags, int width,
		int precision, int length, char padd, char extra_c);
int writePointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_c, int padd_start);
int writeUnsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size);

int isPrintable(char c);
int appendHexaCode(char asciiCode, char buffer[], int i);
int isDigit(char c);
long int convertSizeNumber(long int num, int size);
long int convertSizeUnsgnd(unsigned long int num, int size);

#endif
