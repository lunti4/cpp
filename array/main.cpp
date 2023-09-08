#include <iostream>
#include <array>
using namespace std;

void printMas(int arr[]) {
    int len;
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

}

int main()
{
    int temp;
    int mas[5]{42, 10, 5, 51, 2};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    printMas (mas);
}

