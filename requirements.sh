git clone https://gitlab.com/libeigen/eigen
mv eigen eigen_installation
mkdir eigen
cd eigen 
cmake ../eigen_installation
sudo make install
cd ..
sudo rm -R eigen eigen_installation