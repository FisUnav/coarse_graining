#include <cmath>
#include <Eigen/Dense>
#include <iostream>
#include <vector>

#include "../headers/grid2D.h"

using namespace coarse_graining;
using namespace Eigen;
using namespace std;


int main() {
    Matrix<double, 3, 6> data;
    data << 0.001, 0.0, 0.0, 0.02, 0.2, 0.3,
             0.001, 0.2, 0.2, 0.03, 0.3, 0.3,
             0.001, 0.4, 0.4, 0.025, 0.25, 0.3;
    vector<int> neighbors = {0, 1}, count_neighbors = {3, 3};
    double x = 0.1, y = 0.1, gridRes = 0.15;
    auto heavyside2D = [](double xGrid, double yGrid, double xPart, double yPart, double radius, double count) -> double {
        return sqrt(pow(xGrid - xPart, 2) + pow(yGrid - yPart, 2)) <= radius ? 1 / count: 0;
    };
    grid2D grid1(x, y, gridRes, neighbors, count_neighbors);
    grid1.velocity_field(data, heavyside2D);
    cout << "My grid Volume Fraction is: " << grid1.volFrac << endl; 
    cout << "My grid density is: " << grid1.density << endl;
    cout << "My grid velocity vector is: " << endl << grid1.velocity << endl; 
    return 0;
}