#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
#include <string>
using namespace std;

class PaymentStrategy {  // Interface Segregation Principle
public:
    virtual void pay(float amount, const string& riderName) = 0;
    virtual ~PaymentStrategy() = default;
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(float amount, const string& riderName) override {
        cout << "[UPI] ₹" << amount << " paid successfully by " << riderName << endl;
    }
};

class CashPayment : public PaymentStrategy {
public:
    void pay(float amount, const string& riderName) override {
        cout << "[CASH] ₹" << amount << " paid successfully by " << riderName << endl;
    }
}; 

#endif
