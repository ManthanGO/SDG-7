#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Appliance {
protected:
    string name;
    double powerDemand;
public:
    Appliance(string n, double p) : name(n), powerDemand(p) {}
    virtual ~Appliance() {}
    
    virtual double consumePower() = 0; 
    
    string getName() { return name; }
};

class HeavyAppliance : public Appliance {
public:
    HeavyAppliance(string n, double p) : Appliance(n, p) {}
    
    double consumePower() override {
        cout << "[Heavy Load] " << name << " is drawing " << powerDemand << " kW." << endl;
        return powerDemand;
    }
};

class LightAppliance : public Appliance {
public:
    LightAppliance(string n, double p) : Appliance(n, p) {}
    
    double consumePower() override {
        cout << "[Light Load] " << name << " is drawing " << powerDemand << " kW." << endl;
        return powerDemand;
    }
};

class SolarPanel {
    double currentOutput;
public:
    SolarPanel(double output) : currentOutput(output) {}
    double getOutput() { return currentOutput; }
};

class Battery {
    double capacity;
    double currentCharge;
public:
    Battery(double cap, double charge) : capacity(cap), currentCharge(charge) {}
    
    double discharge(double demand) {
        if (currentCharge >= demand) {
            currentCharge -= demand;
            return demand;
        } else {
            double provided = currentCharge;
            currentCharge = 0;
            return provided;
        }
    }
    double getCharge() { return currentCharge; }
};

class PowerGrid {
public:
    double drawPower(double demand) {
        return demand; 
    }
};

class SmartGrid {
    SolarPanel* solar;
    Battery* battery;
    PowerGrid* grid;
    vector<Appliance*> appliances;
public:
    SmartGrid(SolarPanel* s, Battery* b, PowerGrid* g) : solar(s), battery(b), grid(g) {}

    void addAppliance(Appliance* app) {
        appliances.push_back(app);
    }

    void simulateEnergyFlow() {
        double totalDemand = 0;
        cout << "\n--- Appliance Power Demand ---\n";
        
        for (auto* app : appliances) {
            totalDemand += app->consumePower(); 
        }

        cout << "\n--- Energy Allocation (SDG 7 Priority) ---\n";
        cout << "Total Demand: " << totalDemand << " kW\n";


    
