#include <iostream>
#include <vector>

std::vector<double> linspace(double start, double end, int num) {
    std::vector<double> result;
    if (num == 0) return result; // Handle case where num is 0
    if (num == 1) {
        result.push_back(start);  // If num is 1, just return the start value
        return result;
    }

    double step = (end - start) / (num - 1);
    for (int i = 0; i < num; ++i) {
        result.push_back(start + i * step);
    }
    return result;
}


int main(){

    // Example usage: generate 11 values between 1500 and 1600
    std::vector<double> arr = linspace(1500, 1600, 11);

    // Print the array to confirm the values
    for (double value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}