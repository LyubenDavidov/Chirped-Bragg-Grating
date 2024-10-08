#include <iostream>
#include <cmath>
#include <vector>

// Define constants
const double PI   = 3.141592653589793;
const double c0   = 3e8;
const double eps0 = 8.8541878188e-12;
const double mu0  = 1.25663706127e-6;

// Define test variables
double lambda0 = 1550e-9;   // [m] central wavelength
double omega0  = 2 * PI * c0 / lambda0;
double n1      = 3.229;     // [-] effective refractive index with layer II-3
double n2      = 3.225;     // [-] effective refractive index without layer II-3

// Calculate the vacuum wave number
double k0      = omega0 * sqrt(mu0 * eps0);

// Calculate relative permittivity (assume mu_r = 1)
double eps_r1 = pow(n1, 2);
double eps_r2 = pow(n2, 2);


// Define the linspace function
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

    // HERE STARTS MY LINSPACE TEST CODE
    // Example usage: generate 11 values between 1500 and 1600
    //std::vector<double> arr = linspace(1500, 1600, 11);

    // Print the array to confirm the values
    //for (double value : arr) {
    //    std::cout << value << " ";
    //}
    //std::cout << std::endl;
    // HERE ENDS MY LINSPACE TEST CODE

    std::cout << k0 << std::endl;

    return 0;
}