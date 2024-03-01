#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // Добавляем заголовочный файл для функции rand()
#include <algorithm>

void bucketSort(std::vector<int>& arr) {
    const int n = arr.size();

    // Создаем ведра (buckets)
    std::vector<std::vector<int>> buckets(n);

    // Распределяем элементы по ведрам
    for (int i = 0; i < n; ++i) {
        int index = static_cast<int>(static_cast<double>(arr[i]) / n);
        buckets[index].push_back(arr[i]);
    }

    // Сортируем элементы внутри каждого ведра
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // Собираем отсортированный массив
    int index = 0;
    for (const auto& bucket : buckets) {
        for (const auto& num : bucket) {
            arr[index++] = num;
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
        arr[i] = rand() % 1000; // Генерируем случайное число от 0 до 999
    }

    unsigned int start_time = clock();
    bucketSort(arr);
    unsigned int end_time = clock();

    std::cout << "Sorted array: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nTime taken for processing data: " << end_time - start_time << " ms\n";

    return 0;
}