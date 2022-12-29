
#include <iostream>

using namespace std;

int main()
{
    cout<<"Введите число: ";
    int x;
    cin>>x;
    
    cout<<"Введите второе число: ";
    int y;
    cin>>y;
    
    char op;
    cout<<"Введите операцию: ";
    cin>>op;
    
    int r;
    if ( op == '+')
    {
        r = x + y;
    }
    
    if ( op == '-')
    {
        r = x - y;
    }
    
    cout<<x<<op<<y<<'='<<r<<endl;
    cout<<"r = " << r;
    
    return 0;
}
