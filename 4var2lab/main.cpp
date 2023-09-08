#include <iostream>
#include <string>


class Wallet {
    private:
        
        int* first = new int;
        int* second = new int;

    public:

        Wallet(int &first, int &second) {
            
            if ((first == 50) | (first == 100) | (first == 200) | (first == 500) | (first == 1000) | (first == 2000) | (first == 5000)) { 

                *this->first = first;
                *this->second = second;

                std::cout << "Создан кошелек\nНоминал купюр - " << *this->first << "\nКоличество купюр- " << *this->second << '\n';   
            }

            else {
                std::cout << "Неверный номинал купюры\n";
                exit;
            }
        };

        ~Wallet() {
            std::cout << "Экземпляр класса удален(использован деструктор класса int)\n";
        };

        void display() {
            std::cout << "Номинал купюры - " << *this->first << "\nКоличество купюр - " << *this->second << '\n';
        };

        void summa() {
            std::cout << "Денежная сумма купюр составляет " << ((*this->first) * (*this->second)) << " руб.\n";
        };
};


int main() {

    int first = 1000;
    int second = 20;
    Wallet a(first, second);
    
    first = 50;
    second = 1;
    Wallet b(first, second);

    // a.display();
    // b.display();

    a.summa();
    b.summa();
    
}