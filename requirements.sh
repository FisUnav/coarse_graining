wget https://gitlab.com/libeigen/eigen/-/archive/3.3.7/eigen-3.3.7.tar.bz2
tar xvf eigen-3.3.7.tar.bz2
mkdir eigen
cd eigen 
cmake ../eigen-3.3.7
sudo make install
cd ..
sudo rm -R eigen eigen-3.3.7 eigen-3.3.7.tar.bz2