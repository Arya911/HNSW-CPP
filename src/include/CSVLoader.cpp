#include <vector>
#include <fstream>
#include <iostream>

class CSVLoader{
private:
    std::ifstream ifs;
public:
    explicit CSVLoader(const std::string &filename) : ifs(filename){
        if(!ifs.is_open()){
            std::cout<<"Could not Open file"<<std::endl;
        }
    }

    ~CSVLoader(){
        if(ifs.is_open()){
            ifs.close();
        }
    }

    std::vector<std::vector<float>> loadPointsFromCSV(){
        std::vector<std::vector<float>> Points;
        float f;
        char ch;
        while(ifs>>f){
            std::vector<float>Point(2);
            ifs>>ch; // for the comma
            Point[0] = f;
            ifs>>f;
            Point[1] = f;
            Points.push_back(Point);
        }
        std::cout<<Points.size()<<std::endl;
        return Points;
    }

};