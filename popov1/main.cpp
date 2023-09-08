#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct info
{
    string aname, name, year;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file;
    file.open("test.txt");
    
    const int amountofbooks = 3;
    info books[3];
    bool a;

    string searchname;

    cout << "Insert some info";
    cout << "\n";

    cin >> searchname;
    cout << "\n";

    cout << "Look what we found:";

    cout << "\n";

    for (int i = 0; i < amountofbooks; i++)
    {

        getline(file, books[i].aname, ',');
        getline(file, books[i].name, ',');
        getline(file, books[i].year, '\n');

        // cout << books[i].aname << '\n';

        if (books[i].name.find(searchname) != string::npos)
        {
            cout << books[i].aname << ", ";
            cout << books[i].name << ", ";
            cout << books[i].year << '\n';
        }
    }

    return 0;
}