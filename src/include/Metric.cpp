#include <vector>
#include <cmath>
#include <cassert>

class Metric
{
public:
    virtual ~Metric() = default;
    virtual float metric(const std::vector<float> &pt1, const std::vector<float> &pt2) const = 0;
};

class EuclideanDistance : public Metric{
    float metric(const std::vector<float>& pt1, const std::vector<float>& pt2) const override{
        assert(pt1.size()==pt2.size());
        float dist = 0.0f;
        for(std::size_t i=0;i<pt1.size();i++){
            float d = abs(pt2[i] - pt1[i]);
            dist+=d*d;
        }
        return std::sqrt(dist);
    }
};

class CosineSimilarity : public Metric {
public:
    float metric(const std::vector<float> &pt1, const std::vector<float> &pt2) const override {
        assert(pt1.size()==pt2.size());
        float dot = 0, normA = 0, normB = 0;
        for (size_t i = 0; i < pt1.size(); i++) {
            dot += pt1[i] * pt2[i];
            normA += pt1[i] * pt1[i];
            normB += pt2[i] * pt2[i];
        }
        return dot / (std::sqrt(normA) * std::sqrt(normB));
    }
};



