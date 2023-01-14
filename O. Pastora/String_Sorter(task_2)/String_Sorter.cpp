// String_Sorter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int N;

struct SignsAndPos
{
    string signs;
    int wordsBefore;
};

vector<string> GetOutWords(string sentence)
{
    unsigned int i;
    vector<string> words;
    string word;
    unsigned int size = sentence.size();
    unsigned int startPos;
    unsigned int endPos;
    for (i = 0; i < size; i++)
    {
        startPos = sentence.find_first_not_of(" ,.;:-", i);
        endPos = sentence.find_first_of(" ,.;:-", startPos);
        words.push_back(sentence.substr(startPos, endPos - startPos));
        i = endPos;
        if (sentence.find_first_not_of(" ,.;:-", i) == string::npos)
            return words;
    }
    return words;
}

vector<SignsAndPos> GetOutSigns(string sentence)
{
    int i;
    int size = sentence.size();
    SignsAndPos signsBtwnWords;
    vector<SignsAndPos> signs;
    int posOfNextWord = 0;
    int wordsFore = 0;
    if (sentence.find_first_of(" ,.;:-", 0) == 0)
    {
        posOfNextWord = sentence.find_first_not_of(" ,.;:-", 0);
        signsBtwnWords.signs = sentence.substr(0, posOfNextWord);
        signsBtwnWords.wordsBefore = wordsFore;
        signs.push_back(signsBtwnWords);
    }
    int posOfSignsBegin;
    for (i = posOfNextWord; i < size; i = posOfNextWord)
    {
        posOfSignsBegin = sentence.find_first_of(" ,.;:-", i);
        if (posOfSignsBegin != string::npos)
        {
            wordsFore++;
            posOfNextWord = sentence.find_first_not_of(" ,.;:-", posOfSignsBegin);
            signsBtwnWords.signs = sentence.substr(posOfSignsBegin, posOfNextWord - posOfSignsBegin);
            signsBtwnWords.wordsBefore = wordsFore;
            signs.push_back(signsBtwnWords);
        }
        else
            return signs;
    }
    return signs;
}

void PrintSortedSentence(vector<string> words, vector<SignsAndPos> signs)
{
    vector<string>::iterator itW;
    vector<SignsAndPos>::iterator itS;
    if (signs[0].wordsBefore == 0)
    {
        cout << signs[0].signs;
        signs.erase(signs.begin());
    }   
    for (itW = words.begin(), itS = signs.begin(); itW != words.end() && itS != signs.end(); itW++, itS++)
        cout << *itW << (*itS).signs;
    if (words.size() > signs.size())
    {
        cout << *(--words.end());
    }
}

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
    else if (stringToSort.find_first_of(" ,.;:-", 0) == string::npos)
    {
        cout << "There is only one word in this string!";
        return 0;
    }
    vector<string> words = GetOutWords(stringToSort);
    vector<SignsAndPos> signs = GetOutSigns(stringToSort);
    sort(words.begin(), words.end(), [](string a, string b)
        {
            unsigned int i;
            unsigned int aSize = a.size();
             unsigned int bSize = b.size();
            for (i = 0; i < aSize && i < bSize && i < N; i++)
            {
                if (a[i] > b[i])
                    return false;
                else if (a[i] < b[i])
                    return true;
            }
            if (aSize >= bSize)
                return false;
            else
                return true;
        });
    PrintSortedSentence(words, signs);
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
