#ifndef FARECALCULATOR_H
#define FARECALCULATOR_H

class FareCalculator {  // INTERFACE SEGREGATION PRINCIPLE
protected:
    float baseFare;
public:
    FareCalculator(float base) : baseFare(base) {}
    virtual float calculate(float distance) = 0;
    virtual ~FareCalculator() = default;
};
class BaseFareCalculator : public FareCalculator {  // Normal Hours
public:
    BaseFareCalculator(float base) : FareCalculator(base) {}  
    float calculate(float distance) override {
        return baseFare + (distance * 10);
    }
};

class SurgeFareCalculator : public FareCalculator {  // Peak Hours
public:
    SurgeFareCalculator(float base) : FareCalculator(base) {}  
    float calculate(float distance) override {
        return (baseFare + (distance * 10)) * 1.75;
    }
};

#endif
