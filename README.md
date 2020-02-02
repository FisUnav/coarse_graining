# Coarse-graining #

A coarse-graining implementation in C++ and using built-in thread for parallel computing. The linear algebra required 
for the matrix operations are base on [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page). 

## Eigen ##

We are using the linear algebra methods and classes implemented with Eigen. A short tutorial can be found [here](http://eigen.tuxfamily.org/dox/GettingStarted.html) and a more comprehensive discussion [here](http://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html).

Some basic functionalities that will be extensively used are detailed below:

- [Matrix and vector arithmetic](http://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html)
- [Array class and coefficient-wise operations](http://eigen.tuxfamily.org/dox/group__TutorialArrayClass.html)
- [Block operations](http://eigen.tuxfamily.org/dox/group__TutorialBlockOperations.html)
- [Advanced variable initialization](http://eigen.tuxfamily.org/dox/group__TutorialAdvancedInitialization.html)
- [Reductions, visitors and broadcasting](http://eigen.tuxfamily.org/dox/group__TutorialReductionsVisitorsBroadcasting.html)
- [Reshaping and slicing](http://eigen.tuxfamily.org/dox/group__TutorialReshapeSlicing.html)


## TODO ##
- [X] Create classes to handle matrices in a simple fashion. Methods that should be added shall be discussed further. (Ilberto)
- [ ] Implement a class/set of methods to read input files for 2D and 3D scenarios (Claudia)
- [ ] Some proposal should be presented to handle input data that comes from different files (for example, if we have the forces acting on particles, we should read those forces in a separate file and handle particle assignment to the rest of the data) (Claudia)
- [ ] Implement a class/set of methods to write coarse-graining fields from calculated fields (Iñaki)
- [ ] Create pre-processing classes or methods to stream data properly (it should allow data to be select by regions). (Iñaki)
- [ ] Pre-processing should also handle memory, variable units and consider the number of fields to be calculated (reducing the number of variables or increasing it in case more fields are needed) (Iñaki)
- [ ] Create a grid class or structure to store the variables of its position and coarse-graining fields (it should create more variables for the fields if needed) (Gella)
- [ ] Add a coarse-graining method in order to execute the calculations. It should have as input the data and the coarse-graining parameters (coarse-graining function, grid resolution, etc) (Ilberto or Dariel)
- [ ] Some functions to be used in the coarse-graining: heavyside, gaussian and lucy (Ilberto or Dariel)
- [ ] This should calculate the fields: density, volume fraction, momentum and kinetic stress. (Tivadar)
- [ ] Parallelize code. (Ilberto)
