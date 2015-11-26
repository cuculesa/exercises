#include<iostream>
using namespace::std;

/*//lux1
int f()
{
    int i=10;
    i++;
    {
      int i=5;
      i++;
    }
    return i;
}
int main()
{
    int g=f();
    cout<<g<<endl;
    return 1;
}
*/

//lux2
/*char* alloc(char& rf)//passing char by refence
{
    char x[256]="bubu";
    x[0] = rf;
    cout<<"x[0] "<<x[0]<<endl;//set x by reference
    char* px;
    px=&x[0];
    cout<<"px "<<&px<<" "<<*px<<endl;
    return x;
}

int main()
{
    char* p;
    char g='h';
    p=alloc(g);
    cout<<"p= "<<&p<<" "<<*p<<endl;
    return 1;
}*/

//lux3


//lux4
/*int main()
{
    int i;
    for(i=0;i<10;i++);
    cout<<i<<endl;
}*/

/*//lux5
void f()
{
    int x=0;
    static int y=0;
    x++;
    y++;
    cout<<x<<" "<<y<<endl;
}

int main()
{
    f();
    f();
    return 1;
}*/

/*
//lux6
class A
{
    public:
    A()
    {
        cout<<"A::A\n";
    }
    ~A()
    {
        cout<<"delete A::A\n";
    }
};


int main()
{
    A*p = new A[10];
    delete[] p; // called defined constructor to delete the array
    return 1;
}*/
