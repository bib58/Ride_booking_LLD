#ifndef RIDEMANAGER_HPP
#define RIDEMANAGER_HPP

#include <vector>
#include <algorithm>
#include "User.hpp"
#include "Ride.hpp"
#include "Strategy.hpp"

class RideManager {
private:
    vector<Driver*> drivers;
    vector<Rider*> riders;
    vector<Ride*> ongoingRides;
    MatchingStrategy* strategy;
    vector<Driver*> availableDrivers;
    vector<Ride*> completedRides;
    FareCalculator* fareCalculator;

public:
    RideManager(MatchingStrategy* strat) {  // SINGLETON DESIGN PATTERN
        strategy = strat;
    }

    Driver* registerDriver(string name, string vehicleNumber, string type, Location loc, float rating) {
        Driver* driver = new Driver(name, vehicleNumber, type, loc, rating);
        drivers.push_back(driver);
        return driver;
    }
    Rider* registerRider(string name, string phone, Location loc) {
        Rider* rider = new Rider(name, phone, loc);
        riders.push_back(rider);
        return rider;
    }

    // Memory management for rides
    void driverGoesOffline(Driver* driver) {
        driver->setAvailability(false);
        availableDrivers.erase(remove(availableDrivers.begin(), availableDrivers.end(), driver), availableDrivers.end());
    }

    void driverComesOnline(Driver* driver) {
        driver->setAvailability(true);
        if (find(availableDrivers.begin(), availableDrivers.end(), driver) == availableDrivers.end()) {
            availableDrivers.push_back(driver);
        }
    }

    Driver* requestRide(Rider* rider, Location pickup, Location drop, string vehicleType) {
        Ride* ride = new Ride(rider, pickup, drop, vehicleType, fareCalculator);
        Driver* matchedDriver = strategy->match(rider, drivers, vehicleType);

        if (matchedDriver) {
            return matchedDriver;
        } 
        else {
            cout << "No driver available for the ride." << endl;
            delete ride;
            return nullptr;
        }
    }

    ~RideManager() {
        delete strategy;
    }
};

#endif
