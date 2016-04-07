#include<stdio.h>
#include<iostream>
//输出基数位上的数
void fun(long s, long* t)
{
    long s1 = 10;
    *t = s % 10;
    while (s > 0)
    {
        s = s / 100;
        *t = s % 10 * s1 + *t;
        s1 = s1 * 10;
    }
}
int main()
{
    long s, t;
    scanf_s("%ld",&s,0);
    fun(s,&t);
    printf("the result is %ld\n",t);
    system("pause");
    return 0;
}
