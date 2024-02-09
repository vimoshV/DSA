#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

// Merge function for merge sort
void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> temp(r - l + 1);
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[l + p] = temp[p];
    }
}

// Recursive merge sort function
void recursiveMergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        recursiveMergeSort(arr, left, mid);
        recursiveMergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Iterative merge sort function
void iterativeMergeSort(std::vector<int>& arr, int left, int right) {
    for (int currSize = 1; currSize <= right - left; currSize *= 2) {
        for (int start = left; start < right; start += 2 * currSize) {
            int mid = std::min(start + currSize - 1, right);
            int end = std::min(start + 2 * currSize - 1, right);
            merge(arr, start, mid, end);
        }
    }
}

// Measure time taken by merge sort
double measureTime(void (*sortFunction)(std::vector<int>&, int, int), std::vector<int>& arr, int left, int right) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortFunction(arr, left, right);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

int main() {
    std::vector<int> inputSizes = {200, 700, 1500, 2000, 3000};
    std::vector<double> recursiveExecutionTimes;
    std::vector<double> iterativeExecutionTimes;

    for (int size : inputSizes) {
        // Generate a dataset of random integers for the current input size
        std::vector<int> dataset(size);
        for (int i = 0; i < size; ++i) {
            dataset[i] = rand() % 10000; // Random integers between 0 and 9999
        }

        // Make copies of the dataset for both sorting algorithms
        std::vector<int> datasetCopy(dataset);

        // Measure time taken by recursive merge sort
        double recursiveTime = measureTime(recursiveMergeSort, dataset, 0, size - 1);
        recursiveExecutionTimes.push_back(recursiveTime);

        // Measure time taken by non-recursive merge sort
        double iterativeTime = measureTime(iterativeMergeSort, datasetCopy, 0, size - 1);
        iterativeExecutionTimes.push_back(iterativeTime);
    }

    // Print execution times
    std::cout << "Recursive Merge Sort Time:" << std::endl;
    std::cout << "[" ;
    for (size_t i = 0; i < recursiveExecutionTimes.size(); ++i) {
        std::cout << recursiveExecutionTimes[i];
        if (i < recursiveExecutionTimes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl << std::endl;

    std::cout << "Iterative Merge Sort Time:" << std::endl;
    std::cout << "[" ;
    for (size_t i = 0; i < iterativeExecutionTimes.size(); ++i) {
        std::cout << iterativeExecutionTimes[i];
        if (i < iterativeExecutionTimes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
