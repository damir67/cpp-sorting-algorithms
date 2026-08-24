#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <memory>

#include "sorting.hpp"

void printVector(const std::vector<int>& vec, const std::string& label = "") {
    if (!label.empty()) {
        std::cout << label << ": ";
    }
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void demonstrateSorting() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    
    std::cout << "=== Modern C++ Sorting Algorithms ===\n\n";
    
    printVector(data, "Original Array");
    
    // Bubble Sort
    auto bubbleData = data;
    auto start = std::chrono::high_resolution_clock::now();
    Sorting::bubbleSort(bubbleData);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(bubbleData, "Bubble Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // Selection Sort
    auto selectionData = data;
    start = std::chrono::high_resolution_clock::now();
    Sorting::selectionSort(selectionData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(selectionData, "Selection Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // Insertion Sort
    auto insertionData = data;
    start = std::chrono::high_resolution_clock::now();
    Sorting::insertionSort(insertionData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(insertionData, "Insertion Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // Merge Sort
    auto mergeData = data;
    start = std::chrono::high_resolution_clock::now();
    Sorting::mergeSort(mergeData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(mergeData, "Merge Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // Quick Sort
    auto quickData = data;
    start = std::chrono::high_resolution_clock::now();
    Sorting::quickSort(quickData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(quickData, "Quick Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // Heap Sort
    auto heapData = data;
    start = std::chrono::high_resolution_clock::now();
    Sorting::heapSort(heapData);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(heapData, "Heap Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
    
    // STL Sort
    auto stlData = data;
    start = std::chrono::high_resolution_clock::now();
    std::sort(stlData.begin(), stlData.end());
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    printVector(stlData, "STL Sort");
    std::cout << "Time: " << duration.count() << " µs\n\n";
}

void performanceTest() {
    std::cout << "\n=== Performance Test (1000 elements) ===\n\n";
    
    // Generate random data
    std::vector<int> data(1000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    
    for (int& num : data) {
        num = dis(gen);
    }
    
    // Bubble Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::bubbleSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Bubble Sort: " << duration.count() << " ms\n";
    }
    
    // Selection Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::selectionSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Selection Sort: " << duration.count() << " ms\n";
    }
    
    // Insertion Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::insertionSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Insertion Sort: " << duration.count() << " ms\n";
    }
    
    // Merge Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::mergeSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Merge Sort: " << duration.count() << " ms\n";
    }
    
    // Quick Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::quickSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Quick Sort: " << duration.count() << " ms\n";
    }
    
    // Heap Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        Sorting::heapSort(testData);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Heap Sort: " << duration.count() << " ms\n";
    }
    
    // STL Sort
    {
        auto testData = data;
        auto start = std::chrono::high_resolution_clock::now();
        std::sort(testData.begin(), testData.end());
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "STL Sort: " << duration.count() << " ms\n";
    }
}

int main() {
    try {
        demonstrateSorting();
        performanceTest();
        std::cout << "\n=== All tests completed successfully ===\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
