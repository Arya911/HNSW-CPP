#include "Metric.cpp"
#include <iostream>
#include <memory>
#include <queue>

class Naive{
private:
    std::unique_ptr<Metric> m;
public:
    Naive(std::unique_ptr<Metric> metric) : m(std::move(metric)){}

    std::vector<std::vector<float>> KNN(const std::vector<std::vector<float>> &Points, const std::vector<float>& queryPoint, const std::size_t k) const {
        auto comparator = [this, &queryPoint](const std::vector<float>& pt1, const std::vector<float>& pt2){
            int m1 = m->metric(pt1, queryPoint);
            int m2 = m->metric(pt2, queryPoint);
            return m2 > m1; // Max Heap 

        };
        std::priority_queue<std::vector<float>, std::vector<std::vector<float>>, decltype(comparator)> pq(comparator);

        for(auto& point : Points){
            pq.push(point);

            if(pq.size() > k){
                pq.pop();
            }
        }

        std::vector<std::vector<float>> KNearest;
        while(!pq.empty()){
            KNearest.push_back(pq.top());
            pq.pop();
        }

        return KNearest;
    }
    // We can make this part of the constructor
    void doFinal(const std::vector<std::vector<float>> &Points, const std::vector<float>& queryPoint, const std::size_t k) const{
        std::vector<std::vector<float>> nearestNeighbours = KNN(Points, queryPoint, k);

        std::cout<<"K Nearest Neighbours : "<<std::endl;
        for(auto& point : nearestNeighbours){
            std::cout<<point[0]<<" "<<point[1]<<std::endl;
        }

    }
};