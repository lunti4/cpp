#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct bankClient {         /// структура в которой все храним
    string fio;
    string accountNumber;
    int balance;
    string changeDate;

};

void split(string const &str, const char delitel, vector<string> &result) {     /// функция разделения строки по делителю, результат помещаем в вектор резал(которые передаем)
    
    stringstream ss(str);              /// создаем ss stringline (поток строк) для работы с гетлайном

    string s;                           /// строка куда будем помещать строки, на которые поделили

    while(getline(ss, s, delitel)) {       /// пока делится ss в s по delitel, записываем результат в s и эту строку s добавляем ко всем остальным в вектор result
        result.push_back(s);
    }

}

void alphabeticOrderPrint(vector <bankClient> &clients) {           /// функция печати в алфавитном порядке, которая принимает на вход вектор с клиентами

    vector<string> firstNames;                      /// сюда положим фамилии
    

    for (int i = 0; i < clients.size(); i++) {      
        vector<string> tmp;         
        split(clients[i].fio, ' ', tmp);            /// прооходимся по каждому фио и делим его на [ф, и, о]


        firstNames.push_back(tmp[0]);               /// кладем фамилию в вектор фамилий
    }

    sort(firstNames.begin(), firstNames.end());     /// сортируем

    cout << "Количество человек - " << firstNames.size() << '\n';

    for (int i = 0; i < firstNames.size(); i++) {
        cout << i+1 << ". " << firstNames[i] << "\n";
    }

}


void getResult(vector<bankClient> &clients, string &date, int balance) {        /// основная рабочая функция, принимает клиентов которых мы положили в вектор, строку с датой и баланс который мы ввели

    vector<bankClient> validClients;                /// вектор, где будут храниться клиенты, которые нам подходят по условию

    for(int i=0; i < clients.size(); i++) {
        
        vector<string> tmp;
        split(clients[i].changeDate, '.', tmp);     /// из поля changedate мы хотим получить месяц, поэтому бьем строку

        string clientDate = tmp[1];                 /// клиентская дата = месяц, которые мы получили

        if ((clientDate == date) & (balance < clients[i].balance)) {        /// если дата клиента == дата введенная и введенный баланс < баланс клиента => клиент валидный
            validClients.push_back(clients[i]);
        }
    }

    alphabeticOrderPrint(validClients);             /// передаем на печать подходящих клиентов

}


int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file;                     
    file.open("test.txt");
    
    vector<bankClient> clients;                     /// здесь у нас хранятся все клиенты

    string str;
    
    while (getline(file, str)) {                    /// пока можем получить строку из файла, пишем ее в стр

        if (str.size() > 0) {                       /// если строка не пустая, то делим ее по запятой и создаем экземпляр структуры
            vector<string> tmp;            
            split(str, ',', tmp);

            bankClient client;

            client.fio = tmp[0];                    /// устанавливаем поля, после чего добавляем ко всем остальным клиентам
            client.accountNumber = tmp[1];
            client.balance = stoi(tmp[2]);
            client.changeDate = tmp[3];

            clients.push_back(client);
    
        }
    }

    string date;
    int balance;

    cout << "Введите интересующий месяц в формате XX \n";       /// вводим нужные даты и балансы
    cin >> date;

    if ((stoi(date) > 12) | (date.size() != 2)) {
        
        cout << "Введен неверный формат даты \n"; 
        return 0;

    }

    cout << "Введите минимальный баланс \n";
    cin >> balance;

    getResult(clients, date, balance);                      /// имея клиентов и балансы вызываем функцию получения результатов

}