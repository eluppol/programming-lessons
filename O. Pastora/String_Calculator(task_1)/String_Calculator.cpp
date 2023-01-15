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

vector<double> MultAndDivide(vector<double>& numbers, vector<char> operations)
{
    int i;
    int j;
    vector<double>::iterator itN;
    vector<char>::iterator itS;
    for (i = 0, j = 0; i < operations.size(); )
    {
        if (operations[i] == '*')
        {
            numbers[j] *= numbers[j + 1];
            itN = numbers.begin() + j + 1;
            numbers.erase(itN);
            itS = operations.begin() + i;
            operations.erase(itS);
        }
        else if (operations[i] == '/')
        {
            if (numbers[j + 1])
            {
                numbers[j] /= numbers[j + 1];
                itN = numbers.begin() + j + 1;
                numbers.erase(itN);
                itS = operations.begin() + i;
                operations.erase(itS);
            }
            else
            {
                cout << "Dividing by 0!!!";
                EXIT_FAILURE;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    return numbers;
}

double CountResult(vector<double> numbers, vector<char> operations)
{

    if (numbers.size() == operations.size())
    {
        numbers[0] = numbers[0] * -1;
        operations.erase(operations.begin());
    }
    numbers = MultAndDivide(numbers, operations);
    double result = numbers[0];
    numbers.erase(numbers.begin());
    int i;
    int size = numbers.size();
    for (i = 0; i < size; i++)
    {
        if (operations[i] == '+')
            result += numbers[i];
        else
            result -= numbers[i];
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
    vector<double> numbers;
    vector<char> signs;
    string::iterator it = expression.begin();
    string::iterator prev;
    if (*it == '-')
    {   
        signs.push_back(*it);
        prev = it;
        it++;
    }
    for (it; it != expression.end(); it++)
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
            else
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