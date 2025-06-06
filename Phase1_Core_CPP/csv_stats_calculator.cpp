#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

double mean(const std::vector<double>& data) {
    double sum = 0;
    for (double d : data) sum += d;
    return sum / data.size();
}

double median(std::vector<double> data) {
    std::sort(data.begin(), data.end());
    size_t n = data.size();
    return n % 2 == 0 ? (data[n/2 - 1] + data[n/2]) / 2 : data[n/2];
}

double stddev(const std::vector<double>& data, double mu) {
    double sum = 0;
    for (double d : data) sum += (d - mu) * (d - mu);
    return std::sqrt(sum / data.size());
}

int main() {
    std::ifstream file("data.csv");
    std::vector<double> numbers;
    double val;

    while (file >> val) {
        numbers.push_back(val);
        if (file.peek() == ',') file.ignore();  // skip commas
    }

    if (numbers.empty()) {
        std::cerr << "No data found in file.\n";
        return 1;
    }

    double mu = mean(numbers);
    std::cout << "Mean: " << mu << '\n';
    std::cout << "Median: " << median(numbers) << '\n';
    std::cout << "Standard Deviation: " << stddev(numbers, mu) << '\n';

    return 0;
}// Placeholder for Phase1_Core_CPP/csv_stats_calculator.cpp
