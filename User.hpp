#ifndef USER_H
#define USER_H

#include<iostream>
#include<cmath>
using namespace std;

class Location {
public:
    string name;
    float x, y; 
    Location(string name, float x = 0, float y = 0): name(name), x(x), y(y) {}
    float distanceTo(const Location& other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class User {   // SINGLE RESPONSIBILITY PRINCIPLE
protected:
    string name;
    Location location;
public:
    User(string name, Location loc): name(name), location(loc) {}
    string getName() {
        return name; 
    }
    Location getLocation() {
        return location; 
    }
    void updateLocation(Location loc) {
        location = loc; 
    }
};

class Rider : public User {
private:
    string phone;
    Location defaultDrop;
public:
    Rider(string name, string phone, Location loc,Location drop = Location("Default", 0, 0))
        : User(name, loc), phone(phone), defaultDrop(drop) {}

};

class Driver : public User {
private:
    string vehicleNumber;
    string vehicleType;
    float rating;
    bool available;
public:
    Driver(string name, string vehicleNumber, string type, Location loc, float rating):
        User(name, loc), vehicleNumber(vehicleNumber), vehicleType(type), rating(rating), available(true) {}
        
    void setAvailability(bool val) {
        available = val; 
    }
    string getVehicleType() {
        return vehicleType; 
    }
    float getRating() { 
        return rating; 
    }
    bool isAvailable() {
        return available; 
    }
};


#endif
