#include <iostream>

class Pair{
    private:
        int* first = new int;
        int* second = new int;
    public:
        Pair(int  &first, int &second) {
            *this->first = first;
            *this->second = second;
        };
        ~Pair() {
            std::cout << "Пара чисел " <<*this->first << " и " << *this->second << " удалена" << '\n';
        };

        void setFirst(int &first) {
            *this->first = first;
        };

        void setSecond(int &second) {
            *this->second = second;
        };

        void mult() {
            std::cout << "Произведение значений полей = " << (*this->first) * (*this->second) << '\n'; 
        }

};

class Rectangle : public Pair {
    private:
        int* length = new int;
        int* height = new int;
    public:
        Rectangle(int &first, int &second) : Pair(first, second) {
            *this->height = first;
            *this->length = second;
        };
        ~Rectangle() {
            std::cout << "Прямоугольник со сторонами " <<*this->height << " и " << *this->length  << " удален" << '\n';
        };
        void square() {
            std::cout << "Площадь прямоугольника = " << *this->height * *this->length << '\n';
        };
        void perimeter() {
            std::cout << "Периметр прямоугольнка = " << ((*this->length * 2) + (*this->height * 2)) << '\n';
        }
};

int main() {
    int first = 4;
    int second = 5;

    Pair pair(first, second);
    pair.mult();

    Rectangle rect(first, second);

    rect.square();
    rect.mult();

    int change = 10;

    rect.setFirst(change);

    rect.perimeter();
    rect.square();

}