#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
typedef unsigned char byte;
const byte Patch[] = { 0x56,0x90 };
int main()
{
	FILE* pfile; 
	if ((pfile = fopen("matrix_test.exe", "r+b")) == NULL)
	{
		printf("Error on openning file\n");
		_getch();
		return EXIT_FAILURE;		
	}
	fseek(pfile, 1122, SEEK_SET);
	fwrite(Patch, sizeof(byte), 2, pfile);
	fclose(pfile);
	printf("Patched successful\n");
	_getch();
	return EXIT_SUCCESS;
}
