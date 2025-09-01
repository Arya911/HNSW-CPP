#include <iostream>
#include <memory>
#include "include/CSVLoader.cpp"
#include "include/Naive.cpp"

int32_t main(int argc, char** argv){
    CSVLoader csv("dataset1k.csv");

    std::vector<std::vector<float>> points = csv.loadPointsFromCSV();

    std::cout<<"Printing CSV......"<<std::endl;
    std::vector<float> query = {0,0};

    Naive knn(std::make_unique<CosineSimilarity>());  

    auto result = knn.KNN(points, query, 2);

    for (auto &r : result) {
        std::cout << "(" << r[0] << "," << r[1] << ")\n";
    }
}