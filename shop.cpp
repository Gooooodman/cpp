//商品的录入
#include<iostream>
using namespace std;
const int m = 50;
class ITEMS
{
private:
    int number[m];
    float price[m];
    int count;
public:
    void CNT(void)
    {
        count = 0;
    }
    void getitem(void);
    void displaySum(void);
    void move(void);
    void displayItem(void);

};
//给商品赋予编号与价格
void ITEMS::getitem(void)
{
    if (count == 0)
    {
        printf("请输入商品的号码:");
        cin >> number[count];
        printf("请输入商品的价格:");
        cin >> price[count];
    }
    else
    {
        printf("请输入商品的号码:");
        cin >> number[count];
    }
    for (int i = 0;i < count;i++)
    {
        if (number[count] == number[i])
        {
            printf("----------------------------------\n");
            printf("号码重复，请重新选择\n");
            count--;
            printf("----------------------------------\n");
        }
        else
        {
            printf("请输入商品的价格:");
            cin >> price[count];
        }
        break;
    }
    count++;
}
//显示所有商品的总价格
void ITEMS::displaySum(void)
{
    float sum = 0;
    for (int i = 0;i < count;i++)
    {
        sum = sum + price[i];
    }
    printf("----------------------------------\n");
    printf("总价格为:%f\n", sum);
    printf("----------------------------------\n");
}
//删除某个商品
void ITEMS::move(void)
{
    int a;
    printf("输入要删除的商品编号:");
    cin >> a;
    for (int i = 0;i < count;i++)
    {
        if (number[i] == a)
            price[i] = 0;
    }
}
//显示所以商品
void ITEMS::displayItem(void)
{
    printf("\n商品清单\n");
    printf("----------------------------------\n");
    for (int i = 0;i < count;i++)
        if(price[i]!=0) 
        {
        printf("\n%d\t", number[i]);
        printf("%f", price[i]);
    }
    printf("\n");
    printf("----------------------------------\n");
    printf("\n");
}
int main()
{
    ITEMS order;
    order.CNT();
    int x;
    do
    {
        printf("输入号码:");
        printf("\n1:增加一个商品");
        printf("\n2显示总价格");
        printf("\n3删除一个商品");
        printf("\n4显示所有的商品");
        printf("\n5退出");
        printf("\n\n你的选择是什么:");
        cin >> x;
        switch (x)
        {
        case 1:order.getitem();break;
        case 2:order.displaySum();break;
        case 3:order.move();break;
        case 4:order.displayItem();break;
        case 5:break;
        default:
            printf("错误的输入，再来一次\n");
        }
    } while (x != 5);
    system("pause");
    return 0;
}