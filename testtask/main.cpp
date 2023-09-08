#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct info
{
    string nc;
    string ny;
    string ns;
    string nb;
    string fio;
    string ki;
};

int main()
{

    setlocale(LC_ALL, "Russian");
    ifstream file;
    file.open("test.txt");

    // vector<info> zapis;
    // int len;

    info zapis[2];
    int len = 2;


    cout << "для получения инфы 1  для изменеения 2 " << endl;
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        int vibor;
        cout << "1-рабочий, 2-участок, 3-цех" << endl;
        cin >> vibor;
        string input;
        switch (vibor)
        {
        case 1:

            cout << "введите фио" << endl;
            cin >> input;

            for (int i = 0; i < len; i++)
            {
                getline(file, zapis[i].nc, ',');
                getline(file, zapis[i].ny, ',');
                getline(file, zapis[i].ns, ',');
                getline(file, zapis[i].nb, ',');
                getline(file, zapis[i].fio, ',');
                getline(file, zapis[i].ki, '\n');

                if (zapis[i].fio.find(input) != string::npos)
                {
                    cout << "выработка- " << zapis[i].ki;
                }

                else
                {
                }
            }

        case 2:

        case 3:

        default:
            break;
        }
    }

    else if (choice == 2)
    {
    }
    else
        cout << "ты дурак";
}