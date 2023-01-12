// String_Sorter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> GetOutWords(string sentence)
{
    int i;
    vector<string> words;
    string word;
    int prevSpacePos;
    for (i = 0; i < sentence.size(); i++)
    {
        prevSpacePos = sentence.find(' ', i);
        word = sentence.substr(i, prevSpacePos - i);
        words.push_back(word);
        i = prevSpacePos;
        if (sentence.find(' ', i + 1) == -1)
        {
            word = sentence.substr(i + 1, sentence.size() - prevSpacePos + 1);
            words.push_back(word);
            return words;
        }
    }
    return words;
}

unsigned int N;

int main()
{
    string stringToSort;
    cout << "Enter the string which I will sort: ";
    getline(cin, stringToSort);
    cout << "Enter the integer sorting accuracy(0 and upper)";
    cin >> N;
    int i = 0;
    if (!stringToSort.size())
    {
        cout << "This string is empty!";
        return 0;
    }
    else if (stringToSort.find(' ', 0) == -1)
    {
        cout << "There is only one word in this string!";
        return 0;
    }
    vector<string> words = GetOutWords(stringToSort);
    sort(words.begin(), words.end(), [](string a, string b)
        {
            int i;
            int aSize = a.size();
            int bSize = b.size();
            for (i = 0; i < aSize && i < bSize && i < N; i++)
            {
                if (a[i] > b[i])
                    return false;
                else if (a[i] < b[i])
                    return true;
            }
            if (aSize > bSize)
                return false;
            else if (aSize < bSize)
                return true;
            return true;
        });
    vector<string>::iterator it;
    for (it = words.begin(); it != words.end(); it++)
        cout << *it << " ";
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
