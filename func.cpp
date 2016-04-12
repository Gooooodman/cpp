//函数的递归使用
//递归应用  迷宫 象棋 
#include<stdio.h>
#include<stdlib.h>

int a[10][3] = {0};
void show(int a[10][3]);//显示的作用
void hanno(int n, char A, char B, char C);//移动的过程，控制control
void move(char X,char Y); //移动，链接数据，视图

void hanno(int n, char A, char B, char C)
{
    if (n<1)
    {
        return;
    }
    else if(n==1)
    {
        printf("\n%c-->%c\n",A,C);//n=1时，直接将A移动到C 直接移动
        move(A,C); //调用move函数
        show(a);
    }
    else 
    {
        hanno(n - 1, A, C, B);//A->B
        printf("\n%c-->%c\n", A, C);//直接移动
        move(A, C);
        show(a);
        hanno(n - 1, B, A, C);

    }

}
void move(char X, char Y)   //X=A=65; Y=B=66;
{
    int m = X - 65;//0  [9][m]
    int n = Y - 65;//1   [9][n]
    int imove = -1;
    for (int i = 0;i < 10;i++)
    {
        if (a[i][m] != 0)  //从a[0][0]-->a[i][0],知道找到第一个不为0的数
        {
            imove = i;
            break;
        }
    }
    int jmove;
    if (a[9][n] == 0)     //判断a[9][1]是否为0
    {
        jmove = 9;
    }
    else
    {
        jmove = 10;
        for (int i = 0;i < 10;i++)
        {
            if (a[i][n] != 0)//检索第一个不为零
            {
                jmove = i;
                break;
            }
        }
        jmove -= 1;
    }
    int temp = a[imove][m];
    a[imove][m] = a[jmove][n];
    a[jmove][n] = temp;
}

void show(int a[10][3]) 
{
    printf("A\tB\tC\t\n");
    printf("-------------------\n");
    for (int i = 0;i < 10;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            printf("%d\t", a[i][j]);

        }
        printf("\n");
    }
}
void main()
{
    int n=0;
    scanf_s("%d", &n, -1);
    /*printf("A\tB\tC\t\n");
    printf("-------------------\n");*/
    for (int i = 0;i < n;i++)    //实现对a数组的赋值
    {
        a[10 - 1 - i][0] = n - i;
    }
    show(a);//将a数组中的值全部打印出来
    hanno(n,'A','B','C');

    system("pause");
}
