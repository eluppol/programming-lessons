#include <iostream>

using namespace std;

int main()
{
    double x , y , result ;
    char op ;
    cout << "Enter first number:" << endl;
    cin >> x;
    cout << "Enter second number:" << endl;
    cin >> y;
    cout << "Enter operation:" << endl;
    cin >> op;
    if (op == '-') 
    {
        result = x - y;
    }
    else
    {
        if (op == '+') 
        {
            result = x + y;
        }
        else
        {
            if (op == '*') 
            {
                result = x * y;
            }
            else
            {
                if (op == '/') 
                {
                    result = x / y;
                }
                else
                {
                    cout << "Error" << endl;
                    return 1;
                }
            }






            
        }



    }
    cout << "Result:" << endl << x << op << y << "=" << result << endl;
    return 0;
}