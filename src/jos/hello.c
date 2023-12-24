/*
    hello.C
    formatting text and printing to the console with printf function in C language
    Copyright (c) 2022 Jos Vermoesen.
*/
#include <stdio.h>
#include <conio.h>

int main() /* Entry point of the program */
{
  /*
  A function that prints to the console
  Use printf("") to print a string, end always with a semicolon
  \n is a newline, \t is a tab
  Return success(0) or failure(-1) to the OS
  */

  clrscr();
  printf("Hello, World!");
  printf("I like pizza!\n");
  printf("It's really good!\n");
  printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n\n");

  printf("   /|\n");
  printf("  / |\n");
  printf(" /  |\n");
  printf("/___|\n");

  return 0;
}
/*
Source code origin: https://www.youtube.com/watch?v=KJgsSFOSQv0
Works with GCC and HITEC C, check the changes for MECC
*/
