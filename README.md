# Coarse-graining #

A coarse-graining implementation in C++ and using OPENMPI for parallel computing

## TODO ##
- [ ] Create classes to handle matrices in a simple fashion. Methods that should be added shall be discussed further. (Ilberto)
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
