#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

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

// Non-recursive merge sort function
void nonRecursiveMergeSort(std::vector<int>& arr, int left, int right) {
    int n = arr.size();
    for (int currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);
            merge(arr, leftStart, mid, rightEnd);
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
    std::vector<int> inputSizes = {100, 500, 1000, 1500, 2000};
    std::vector<double> recursiveTiming(inputSizes.size()); // Timing results for recursive merge sort
    std::vector<double> nonRecursiveTiming(inputSizes.size()); // Timing results for non-recursive merge sort

    // Perform sorting and measure time for each input size
    for (size_t i = 0; i < inputSizes.size(); ++i) {
        int size = inputSizes[i];
        std::vector<int> dataset(size);

        // Generate random dataset
        for (int j = 0; j < size; ++j) {
            dataset[j] = rand() % 10000; // Random integers between 0 and 9999
        }

        // Measure time taken by recursive merge sort
        recursiveTiming[i] = measureTime(recursiveMergeSort, dataset, 0, size - 1);

        // Measure time taken by non-recursive merge sort
        nonRecursiveTiming[i] = measureTime(nonRecursiveMergeSort, dataset, 0, size - 1);
    }

    // Write input sizes and timing results to a file
    std::ofstream outputFile("timing_results.txt");
    if (outputFile.is_open()) {
        for (size_t i = 0; i < inputSizes.size(); ++i) {
            outputFile << inputSizes[i] << " " << recursiveTiming[i] << " " << nonRecursiveTiming[i] << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
        return 1;
    }

    // Plotting using gnuplot
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Merge Sort Performance'\n");
        fprintf(gnuplotPipe, "set xlabel 'Number of Elements in Array'\n");
        fprintf(gnuplotPipe, "set ylabel 'Time (seconds)'\n");
        fprintf(gnuplotPipe, "set grid\n");
        fprintf(gnuplotPipe, "plot 'timing_results.txt' using 1:2 with linespoints title 'Recursive Merge Sort' linecolor 'orange', \
            'timing_results.txt' using 1:3 with linespoints title 'Non-Recursive Merge Sort' linecolor 'blue'\n");
        fflush(gnuplotPipe);
        fclose(gnuplotPipe);
    } else {
        std::cerr << "Error opening gnuplot pipe" << std::endl;
        return 1;
    }

    return 0;
}
