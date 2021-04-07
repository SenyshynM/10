#include <iostream>
#include <fstream>


using namespace std;
bool firstletter();

int main()
{
    cout << "Word starts with \'a\': ";
    if (firstletter())
        cout << "Yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}

bool firstletter()
{
    ifstream f;
    char words[100];
    f.open("t.txt");

    while (f >> words)
    {
        if (words[0] == 'a')
        {
            f.close();
            return true;
        }
    }

    f.close();
    return false;
}

