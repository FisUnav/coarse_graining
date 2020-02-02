#ifndef GRID2D_H_
#define GRID2D_H_

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;

namespace coarse_graining{
    class grid2D { 
    public:
        double x, y, density, volFrac;
        vector<int> neighbors;
        static double areaTerm;        
        Vector2d momentum, velocity;
        Matrix2d kstress;
        bool momentum_check, velocity_check;

        grid2D();
        grid2D(double _x, double _y, double gridRes, vector<int> _neighbors);
        ~grid2D();

        void density_field(const MatrixXd &data, double (*cg_function)(double, double, double, double));
        void momentum_field(const MatrixXd &data, double (*cg_function)(double, double, double, double));
        void velocity_field(const MatrixXd &data, double (*cg_function)(double, double, double, double));
        void kstress_field(const MatrixXd &data, double (*cg_function)(double, double, double, double));
    };    
}

#endif