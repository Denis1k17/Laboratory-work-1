#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // Добавляем заголовочный файл для функции rand()

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);

    // Заполняем массив случайными числами от 0 до 999
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000; // Генерируем случайное число от 0 до 999
    }

    unsigned int start_time = clock();
    quickSort(arr, 0, n - 1);
    unsigned int end_time = clock();

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nTime taken for processing data: " << end_time - start_time << " ms\n";

    return 0;
}