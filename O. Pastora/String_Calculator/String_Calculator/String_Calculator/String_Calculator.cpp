#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Pair
{
    int number = 0;
    int numOfDigits = 0;
};

bool isValid(string checkedString)
{
    if (checkedString[0] == '+' || checkedString[0] == '*' || checkedString[0] == '/')
        return false;
    int i;
    int size = checkedString.size();
    for (i = 0; i < size; i++)
    {
        if (checkedString[i] != '0' || checkedString[i] != '1' || checkedString[i] != '2' || checkedString[i] != '3' || 
            checkedString[i] != '4' || checkedString[i] != '5' || checkedString[i] != '6' || checkedString[i] != '7' || 
            checkedString[i] != '8' || checkedString[i] != '9' || checkedString[i] != '*' || checkedString[i] != '/' || 
            checkedString[i] != '-' || checkedString[i] != '+' )
        {
            cout << "This expression was declined! Invalid symbol(s)" << endl;
            return false;
        }
    }
    cout << "Expression has been accepted!" << endl;
    return true;
}

Pair getNumber(Pair pair, string expression, int pos)
{
    vector<int> numbers;
    while (expression[pos] != '+' || expression[pos] != '-' || expression[pos] != '/' || expression[pos] != '*' || expression[pos] != '\0')
    {
        numbers.push_back(expression[pos] - '0');
        pos++;
    }
    int i = 0;
    pair.numOfDigits = numbers.size();
    while (numbers.size() > 0)
        pair.number = pair.number + numbers[i] * pow(10, numbers.size() - 1);
    return pair;
}

void printExpAndCountRes(vector<int> nums, vector<char> signs)
{
    double res = nums[0];
    cout << "Expression" << nums[0];
    nums.erase(nums.begin());
    int i = 0;
    while (i < signs.size())
    {
        cout << signs[i] << nums[i];
        if (signs[i] == '+')
            res += nums[i];
        else if (signs[i] == '-')
            res -= nums[i];
        else if (signs[i] == '/' && nums[i + 1] != 0)
            res /= nums[i];
        else if (signs[i] == '*')
            res *= nums[i];
        i++;
    }
    cout << "=" << res << endl;
}

int main()
{
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    if (isValid(expression))
        cout << "Your expression: " << expression;
    int size = expression.size();
    int i;
    vector<int> numbers;
    vector<char> signs;
    Pair tmp;
    for (i = 0; i < size; i++)
    {
        if (expression[i] == '0' || expression[i] == '1' || expression[i] == '2' || expression[i] == '3' || expression[i] == '4' ||
            expression[i] == '5' || expression[i] == '6' || expression[i] == '7' || expression[i] == '8' || expression[i] == '9' ||
            (expression[0] == '-' && (expression[1] == '1' || expression[1] == '2' || expression[1] == '3' || expression[1] == '4' || 
            expression[1] == '5' || expression[1] == '6' || expression[1] == '7' || expression[1] == '8' || expression[1] == '9')))
        {
            tmp = getNumber(tmp, expression, i);
            numbers.push_back(tmp.number);
            i = i + tmp.numOfDigits - 1;
        }
        else if (expression[i] == '-' || expression[i] == '+' || expression[i] == '/' || expression[i] == '*' && (expression[i+1] != '-' ||
            expression[i + 1] != '+' || expression[i + 1] != '-' || expression[i + 1] != '/' || expression[i + 1] != '*' || expression[i + 1] != '\0'))
            signs.push_back(expression[i]);
        else
        {
            cout << "Invalid expression! Stop it!!!" << endl;
            return 0;
        }
 
    }
    return 0;
}
