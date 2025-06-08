#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <string>
using namespace std;

class Notifier {   // SINGLE RESPONSIBILITY PRINCIPLE
public:
    virtual void send(const string& user, const string& message) = 0;
    virtual ~Notifier() = default;
};

class CustomerNotifier : public Notifier {
public:
    void send(const string& user, const string& message) override {
        cout << "[Notification to Customer " << user << "]: " << message << endl;
    }
};

class DriverNotifier : public Notifier {
public:
    void send(const string& user, const string& message) override {
        cout << "[Notification to Driver " << user << "]: " << message << endl;
    }
};

#endif