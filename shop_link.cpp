//链表实现商品的录入
#include<iostream>
using namespace std;
struct ITEMS
{
    int number;
    float price;
    ITEMS* next;
};
ITEMS m_head = { 0 };
int add(ITEMS* obj)
{
    ITEMS* cur = m_head.next;   //当前节点current
    ITEMS* pre = &m_head;       //上一个节点previous
    while (cur)
    {
        if (obj->number < cur->number)    //找到这个位置
            break;
        pre = cur;
        cur = cur->next;         //找到最后一个对象
    }
    //插入到pre节点的后面
    obj->next = pre->next;
    pre->next = obj;
    return 0;
}

void add1(int a, float b)
{
    ITEMS* obj = (ITEMS*)malloc(sizeof(ITEMS));
    obj->number = a;
    obj->price = b;
    add(obj);
}
void show_all()   //遍历
{
    ITEMS* p = m_head.next;
     cout << "---------------------------\n";
    while (p!=NULL)
    {
        
        cout << "number:" << p->number;
        cout << "\t";
        cout << "price:" << p->price;
        p = p->next;
        cout << "\n";
        
    }
     cout << "---------------------------\n";
}
int remove(int number)
{
    ITEMS* cur = m_head.next;   //当前节点current
    ITEMS* pre = &m_head;       //上一个节点previous
    while (cur!=NULL)
    {
        if (number == cur->number)        //找到这个位置
        {   //删除该节点
            pre->next = cur->next;
            free(cur);
            cur = NULL;
            break;
        }
        pre = cur;
        cur = cur->next;         //找到最后一个对象
    }
    return 0;
}
void sum(float s)
{
    
    ITEMS* cur = m_head.next;     //当前节点current
    ITEMS* pre = &m_head;         //上一个节点previous
    while (cur!=NULL)  
    {

        s = s + cur->price;
        cur = cur->next;
    }
    cout << "---------------------------\n" ;
    cout << "总价格为:" << s << "\n";
    cout << "---------------------------\n";
}
int main()
{
    int x;
    int a,m;
    float b,n=0;     
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
         case 1:
             cout << "请输入number：";
             cin >> a;
             cout << "请输入price：";
             cin >> b;
             add1( a,b);

             break;
         case 2:
             sum(n);
             break;
         case 3:
             cout << "请输入要删除的number：";
             cin >> m;
             remove(m);
             break;
         case 4:
             show_all();
             break;
         case 5:break;
         default:
             printf("错误的输入，再来一次\n");
         }
     } while (x != 5);
    system("pause");
    return 0;
}