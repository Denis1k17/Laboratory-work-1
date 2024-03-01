#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // Добавляем заголовочный файл для функции rand()

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);

    // Заполняем массив случайными числами от 0 до 999
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // Генерируем случайное число от 0 до 999
    }

    unsigned int start_time = clock();
    bubbleSort(arr);
    unsigned int end_time = clock();

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nTime taken for processing data: " << end_time - start_time << " ms\n";

    return 0;
}