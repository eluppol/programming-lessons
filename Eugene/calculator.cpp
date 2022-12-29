
#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter number x: ";
    int x;
    cin>>x;
    
    cout<<"Enter number y: ";
    int y;
    cin>>y;
    
    char op;
    cout<<"Enter operation: ";
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
