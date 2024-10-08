#include <iostream>
#include <cmath>
#include <complex>
#include <Eigen/Dense>
#include <vector>

using namespace std;

// Define constants
const double PI   = 3.141592653589793;
const double c0   = 3e8;                // [m/s] Vacuum Speed of Light
const double eps0 = 8.8541878188e-12;   // Vacuum Electric Permittivity
const double mu0  = 1.25663706127e-6;   // Vacuum Magnetic Permeability 
const double Z0   = 120 * PI;           // [Ohm] Impedance of free space

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

//========================================================================================
// Define 4x4 Complex Valued Matrix Layer 1
Eigen::Matrix<complex<double>, 4, 4> Omega_L1
{
    {complex<double>(0,0), complex<double>(0,0), complex<double>(0,0), complex<double>(1,0)},
    {complex<double>(0,0), complex<double>(0,0), complex<double>(-1,0), complex<double>(0,0)},
    {complex<double>(0,0), complex<double>(eps_r1,0), complex<double>(0,0), complex<double>(0,0)},
    {complex<double>(-eps_r1,0), complex<double>(0,0), complex<double>(0,0), complex<double>(0,0)}
};

// Define 4x4 Complex Valued Matrix Layer 2
Eigen::Matrix<complex<double>, 4, 4> Omega_L2
{
    {complex<double>(0,0), complex<double>(0,0), complex<double>(0,0), complex<double>(1,0)},
    {complex<double>(0,0), complex<double>(0,0), complex<double>(-1,0), complex<double>(0,0)},
    {complex<double>(0,0), complex<double>(eps_r2,0), complex<double>(0,0), complex<double>(0,0)},
    {complex<double>(-eps_r2,0), complex<double>(0,0), complex<double>(0,0), complex<double>(0,0)}
};
//========================================================================================




//========================================================================================
// Use EigenSolver to compute the eigenvalues and eigenvectors for Layer I
Eigen::ComplexEigenSolver<Eigen::Matrix<std::complex<double>, 4, 4>> solver_L1(Omega_L1);

// Get the eigenvector matrix
Eigen::Matrix<std::complex<double>, 4, 4> W_L1 = solver_L1.eigenvectors();

// Get the eigenvalues matrix
Eigen::Matrix<std::complex<double>, 4,1> Lambda_L1 = solver_L1.eigenvalues();
//========================================================================================




//========================================================================================
// Use EigenSolver to compute the eigenvalues and eigenvectors for Layer II
Eigen::ComplexEigenSolver<Eigen::Matrix<std::complex<double>, 4, 4>> solver_L2(Omega_L2);

// Get the eigenvector matrix
Eigen::Matrix<std::complex<double>, 4, 4> W_L2 = solver_L2.eigenvectors();

// Get the eigenvalues matrix
Eigen::Matrix<std::complex<double>, 4,1> Lambda_L2 = solver_L2.eigenvalues();
//========================================================================================




//========================================================================================
// Define the linspace function
vector<double> linspace(double start, double end, int num) {
    vector<double> result;
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
//========================================================================================




int main(){

    // HERE STARTS MY LINSPACE TEST CODE
    // Example usage: generate 11 values between 1500 and 1600
    //vector<double> arr = linspace(1500, 1600, 11);

    // Print the array to confirm the values
    //for (double value : arr) {
    //    cout << value << " ";
    //}
    //cout << endl;
    // HERE ENDS MY LINSPACE TEST CODE

    std::cout << Lambda_L2 << std::endl;
    std::cout << W_L2 << std::endl;

    return 0;
}