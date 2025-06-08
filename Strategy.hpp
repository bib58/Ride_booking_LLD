#ifndef STRATEGY_H
#define STRATEGY_H

#include "User.hpp"
#include <vector>
#include <limits>
using namespace std;

class MatchingStrategy {  
public:
    virtual Driver* match(Rider* rider, vector<Driver*>& drivers, string vehicleType) = 0;
    virtual ~MatchingStrategy() {}
};
class NearestDriverStrategy : public MatchingStrategy {
public:
    Driver* match(Rider* rider, vector<Driver*>& drivers, string vehicleType) {
        Driver* nearest = nullptr;
        float minDistance = numeric_limits<float>::max();  // initialize to maximum float value

        for (Driver* d : drivers) {
            if (d->isAvailable() && d->getVehicleType() == vehicleType) {
                float distance = rider->getLocation().distanceTo(d->getLocation());
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = d;
                }
            }
        }
        return nearest;
    }
};


class BestRatedDriverStrategy : public MatchingStrategy {
public:
    Driver* match(Rider* rider, vector<Driver*>& drivers, string vehicleType) {
        Driver* bestRated = nullptr;
        float maxRating = 3.0;  // initialize to minimum possible rating

        for (Driver* d : drivers) {
            if (d->isAvailable() && d->getVehicleType() == vehicleType) {
                if (d->getRating() > maxRating) {
                    maxRating = d->getRating();
                    bestRated = d;
                }
            }
        }
        return bestRated;
    }
};

#endif
