#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
int fun(char* s)
{
    char* lp, *rp;
    lp = s;
    rp = s + strlen(s) - 1;
    while ((toupper(*lp) == toupper(*rp)) && (lp < rp))
    {
        lp++;
        rp--;
    }
    if (lp < rp)
        return 0;
    else 
        return 1;
}
int main()
{
    char s[81];
    printf("enter a string:");
    scanf_s("%s",s,-1);
    if (fun(s))
        printf("\n\"%s\" is a palindrome.\n\n",s);
    else
        printf("\n\"%s\" is not a palindrome.\n\n", s);
    system("pause");
    return 0;
}