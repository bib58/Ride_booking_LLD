#include <iostream>
#include "RideManager.hpp"
#include "pay.hpp"
#include <ctime> 
using namespace std;

int main() {
    int choice;
    cout << "Choose Matching Strategy:\n";
    cout << "1. Nearest Driver\n";
    cout << "2. Best Rated Driver\n";
    cin >> choice;

    MatchingStrategy* strategy = nullptr;
    if (choice == 1) strategy = new NearestDriverStrategy();
    else if (choice == 2)  strategy = new BestRatedDriverStrategy();
    else {
        cout << "Invalid choice. Defaulting to Nearest Driver Strategy.\n";
        strategy = new NearestDriverStrategy();
    }

    RideManager manager(strategy);

    Location loc("Connaught Place", 2, 2);
    manager.registerDriver("Amit", "DL1234", "SUV", Location("Saket", 1, 1), 1.8);
    manager.registerDriver("Ravi", "DL9876", "Sedan", Location("Hauz Khas", 5, 5), 4.2);
    manager.registerDriver("Piyush", "DL4567", "SUV", Location("Saket", 2, 2), 3.6);

    Rider* rider = manager.registerRider("Rohan", "9876543210", Location("Ajmeri Gate", 0, 0));
    manager.requestRide(rider, Location("Ajmeri Gate", 0, 0), Location("Rohini", 8, 8), "SUV");

    // SIR, if you chooes 2 (bestrated) amit being close to rohan but piyush will be selected as he has better rating
    // If you choose 1 (nearest) then amit will be selected as he is closest to rohan

    float base = 236;

    time_t now = time(0);            // Get current time as time_t
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;         // Extract hour (0-23)

    FareCalculator* calculator = nullptr;
    if ((hour >= 9 && hour <= 11) || (hour >= 18 && hour <= 20))  calculator = new SurgeFareCalculator(base);
    else  calculator = new BaseFareCalculator(base);
    
    Ride* ride = new Ride(rider, Location("Ajmeri Gate", 0, 0), Location("Whitefield", 8, 8), "SUV", calculator);
    
    Driver* driver = manager.requestRide(rider, Location("Ajmeri Gate", 0, 0), Location("Whitefield", 8, 8), "SUV");
    if(driver) {ride->assignDriver(driver);}

    ride->startRide();

    if(driver)  ride->completeRide();

    PaymentStrategy* payment = new UpiPayment();
    payment->pay(ride->getFare(), ride->getRider()->getName());
    
    delete payment;

    return 0;
}
