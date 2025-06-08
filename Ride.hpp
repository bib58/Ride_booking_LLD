#ifndef RIDE_H
#define RIDE_H

#include <string>
#include "User.hpp"
#include "FareCalculator.hpp"
#include "NotificationService.hpp"
using namespace std;

class Ride {
private:
    Rider* rider;
    Driver* driver;
    Location pickup;
    Location drop;
    string vehicleType;
    string status;
    float fare;
    FareCalculator* fareCalculator;
    CustomerNotifier customerNotifier;
    DriverNotifier driverNotifier;

public:
    Ride(Rider* rider, Location pickup, Location drop, string type , FareCalculator* fareCalculator)
        : rider(rider), pickup(pickup), drop(drop), vehicleType(type), driver(nullptr), fare(0), status("REQUESTED") , fareCalculator(fareCalculator){}

    void assignDriver(Driver* drv) {
        driver = drv;
        status = "DRIVER_ASSIGNED";
        customerNotifier.send(rider->getName(), "Driver " + driver->getName() + " mila hai apko");
        driverNotifier.send(driver->getName(), "Driver " + driver->getName() + " Sahab sawari mil gyi apko ab chaliye");
    }

    void startRide() {
        status = "IN_PROGRESS";
    }

    void completeRide() {
        status = "COMPLETED";
        float distance = pickup.distanceTo(drop);
        fare = fareCalculator->calculate(distance);
        customerNotifier.send(rider->getName(), "Ride completed. Fare: ₹" + to_string(fare) + " to be paid");
        driverNotifier.send(driver->getName(), "Ride completed. ₹" + to_string(fare) + " milenge driver sahab");
    }

    void cancelRide() {
        status = "CANCELLED";
    }

    Rider* getRider() { 
        return rider; 
    }
    Driver* getDriver() { 
        return driver; 
    }
    string getStatus() { 
        return status; 
    }
    float getFare() { 
        return fare; 
    }

    Location getPickupLocation() { 
        return pickup; 
    }
    Location getDropLocation() { 
        return drop; 
    }
};

#endif
