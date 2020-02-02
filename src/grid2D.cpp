#include "../headers/grid2D.h"

namespace coarse_graining{
    grid2D::grid2D() {

    }


    grid2D::grid2D(double _x, double _y, double gridRes, vector<int> _neighbors): x(_x), y(_y), 
    areaTerm(gridRes*gridRes), neighbors(_neighbors),  nNeighbors(_neighbors.size()), 
    momentum_check(false), velocity_check(false) {
    }


    void grid2D::density_field(const MatrixXd &data,
            double (*cg_function)(double, double, double, double)) {
        double phi;

        Matrix<double, Dynamic, Dynamic> relData = data(neighbors, Eigen::all);
        density = 0;
        volFrac = 0;
        for (int i = 0; i < nNeighbors; i++){
            phi = cg_function(x, y, relData(i, 1), relData(i, 2));
            volFrac += phi;
            density += relData(i, 0) * phi / areaTerm; //Mass of the particle should be in 1st column
        }
    }

    
    void grid2D::momentum_field(const MatrixXd &data,
            double (*cg_function)(double, double, double, double)) {

        Matrix<double, Dynamic, Dynamic> relData = data(neighbors, Eigen::all);
        double densityP, phi;
        density = 0;
        volFrac = 0;
        momentum(0) = 0;
        momentum(1) = 0;
        for (int i = 0; i < nNeighbors; i++){
            phi = cg_function(x, y, relData(i, 1), relData(i, 2));
            densityP = relData(i, 0) * phi / areaTerm;
            volFrac += phi;   
            density += densityP;
            momentum(0) += densityP * relData(i, 3);
            momentum(1) += densityP * relData(i, 4);
        }
        momentum_check = true;
    }

    
    void grid2D::velocity_field(const MatrixXd &data, 
            double (*cg_function)(double, double, double, double)) {

        if (!momentum_check) momentum_field(data, *cg_function);
        velocity(0) = momentum(0) / density;
        velocity(1) = momentum(1) / density;
        velocity_check = true;
    }

    
    void grid2D::kstress_field(const MatrixXd &data, 
            double (*cg_function)(double, double, double, double)) {

        if (!velocity_check) velocity_field(data, *cg_function);
        Matrix<double, Dynamic, Dynamic> relData = data(neighbors, Eigen::all);
        double densityP, phi, vxx, vxy, vyy;
        kstress(0) = 0;
        kstress(1) = 0;
        kstress(2) = 0;
        kstress(3) = 0;
        for (int i = 0; i < nNeighbors; i++){
            phi = cg_function(x, y, relData(i, 1), relData(i, 2));
            densityP = relData(i, 0) * phi / areaTerm;
            vxx = (relData(i, 3) - velocity(0)) * (relData(i, 3) - velocity(0));
            vxy = (relData(i, 3) - velocity(0)) * (relData(i, 4) - velocity(1));
            vyy = (relData(i, 4) - velocity(1)) * (relData(i, 4) - velocity(1));
            kstress(0) += densityP * vxx;
            kstress(1) += densityP * vxy;
            kstress(2) += densityP * vxy;
            kstress(3) += densityP * vyy;
        }        
    }
}