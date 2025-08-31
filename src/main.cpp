#include <iostream>
#include "include/CSVLoader.cpp"

int32_t main(int argc, char** argv){
    CSVLoader csv("dataset1k.csv");

    std::vector<std::vector<float>> pts = csv.loadPointsFromCSV();

    std::cout<<"Printing CSV......"<<std::endl;

    
}