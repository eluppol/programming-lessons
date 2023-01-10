#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;


int isNumber(string &exp, string::iterator & it)
{
    vector<int> digits;
    int number = 0;
    
    for (; it != exp.end(); ++it)
    {
        if (*it >= '0' && *it <= '9')
            digits.push_back(*it - '0');
        else
            break;
    }
    while (digits.size())
    {
        number += *digits.begin() * pow(10, digits.size() - 1);
        digits.erase(digits.begin());
    }
    return number;
}

double CountResult(vector<int> &numbers, vector<char> &operations)
{
    if (numbers.size() == operations.size())
    {
        numbers[0] = numbers[0] * -1;
        operations.erase(operations.begin());
    }
    double result = numbers[0];
    numbers.erase(numbers.begin());
    int i;
    int size = numbers.size();
    for (i = 0; i < size; i++)
    {
        if (operations[i] == '+')
            result += numbers[i];
        else if (operations[i] == '-')
            result -= numbers[i];
        else if (operations[i] == '*')
            result *= numbers[i];
        else if (!numbers[i])
            result /= numbers[i];
        else
        {
            cout << endl << "Dividing by 0. Donkey's mistake!!! Good bye... ";
            return 0;
        }
    }
    return result;
}


int main()
{
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    if (!((expression[0] >= '0' && expression[0] <= '9') || expression[0] == '-'))
    {
        cout << endl << "INVALID EXPRESSION!";
        return false;
    }
    int size = expression.size();
    int i;
    vector<int> numbers;
    vector<char> signs;
    string::iterator it;
    string::iterator prev;
    for (it = expression.begin(); it != expression.end(); ++it)
    {
        if (*it >= '0' && *it <= '9')
        {
            prev = it;
            numbers.push_back(isNumber(expression, it));
            it--;
        }
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
        {
            if (*prev == '+' || *prev == '-' || *prev == '*' || *prev == '/')
                return 0;
            prev = it;
            signs.push_back(*it);
        }
        else
            return 0;
    }
    double result = CountResult(numbers, signs);
    cout << expression << " = " << result;
    return 0;
}