#include <iostream>
#include <cstdlib>
#include <ctime>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int mirror_number(int num) {
    int result = 0;
    while (num > 0) {
        result = result * 10 + num % 10;
        num /= 10;
    }
    return result;
}
int findAndSort(int arr[], int length, int N) {
    int position = -1;
    for (int i = 0; i < length; i++) {
        if (arr[i] == N) {
            position = i;
            break;
        }
    }
    if (position != -1) {
        for (int i = position + 1; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (arr[j] < arr[i]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    return position;
}
void fillArray(int arr[], int length, int A, int B) {
    std::srand(std::time(0)); 
    for (int i = 0; i < length; i++) {
        arr[i] = A + std::rand() % (B - A + 1); 
    }
}


    int main() {
    setlocale(LC_ALL, "Russian");



    //Задача1.
    int num1, num2;
    std::cout << "Введите два числа: ";
    std::cin >> num1 >> num2;
    int result = gcd(num1, num2);
    std::cout << "Наибольший общий делитель: " << result << std::endl;


    //Задача 2.   
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    int mirroredNumber = mirror_number(number);
    std::cout << "Число в отражённом виде: " << mirroredNumber << std::endl;

    //Задача 3.
    int arr[] = { 5, 8, 2, 10, 3 };
    int length = 5;
    int N = 2;
    int position = findAndSort(arr, length, N);
    std::cout << "Первая позиция " << N << " в массиве: " << position << std::endl;
    std::cout << "Отортированный массив: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;




    //Задача 4.
    int size = 10;    
    int A = 1;
    int B = 100;
    fillArray(arr, length, A, B);
    std::cout << "Случайно заполненный массив: ";
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;





    return 0;
    }
   

