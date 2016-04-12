#include<string.h>
#include<stdio.h>
#include<iostream>
#include<ctype.h>
void fun(char* a)
{
    if (*a)
    {
        fun(a + 1);
        printf("%c", *a);
    }
}

int main()
{
    char s[5] = "abcd";
    printf("%s\n", s);
    fun(s);
    printf("\n");
    system("pause");
    return 0;
}