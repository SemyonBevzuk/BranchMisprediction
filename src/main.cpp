#include <iostream>
#include <time.h>
#include <algorithm>

void FillData(int* array, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        array[i] = std::rand() % 256;
    }
}

long long int BranchMisprediction(int* data, unsigned int size) {
    long long int sum = 0;
    for (unsigned int i = 0; i < 10000; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (data[j] >= 128)
                sum += data[j];
        }
    }
    return sum;
}

long long int NoBranchMisprediction(int* data, unsigned int size) {
    long long int sum = 0;
    std::sort(data, data + size);
    for (unsigned int i = 0; i < 10000; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (data[j] >= 128)
                sum += data[j];
        }
    }
    return sum;
}

int main(int argc, char* argv[]) {
    const unsigned int size = 32768;
    int data[size];
    FillData(data, size);

    clock_t start;
    double time;
    long long int sum = 0;

    int benchmark_status = INT_MAX;
    if (argc > 1)
        benchmark_status = atoi(argv[1]);

    switch (benchmark_status) {
        case 0:
            std::cout << "Branch misprediction: on\n";
            start = clock();
            sum =  BranchMisprediction(data, size);
            time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
            std::cout << "Time = " << time << std::endl;
            std::cout << "sum = " << sum << std::endl;
            break;
        case 1:
            std::cout << "Branch misprediction: off\n";
            start = clock();
            sum = NoBranchMisprediction(data, size);
            time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
            std::cout << "Time = " << time << std::endl;
            std::cout << "sum = " << sum << std::endl;
            break;
        default:
            std::cout << "Enter 0 - with branch misprediction or 1 - without branch misprediction.\n";
            break;
    }
}