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

        double remainingDemand = totalDemand;
        double solarOutput = solar->getOutput();

        if (solarOutput >= remainingDemand) {
            cout << "-> Solar Panel supplied all " << remainingDemand << " kW. (100% Clean Energy)\n";
            remainingDemand = 0;
        } else {
            cout << "-> Solar Panel supplied " << solarOutput << " kW.\n";
            remainingDemand -= solarOutput;
        }

        if (remainingDemand > 0) {
            double batterySupplied = battery->discharge(remainingDemand);
            cout << "-> Battery supplied " << batterySupplied << " kW. (Remaining charge: " << battery->getCharge() << " kWh)\n";
            remainingDemand -= batterySupplied;
        }

        if (remainingDemand > 0) {
            double gridSupplied = grid->drawPower(remainingDemand);
            cout << "-> Power Grid supplied the remaining " << gridSupplied << " kW. (Billable Grid usage)\n";
            remainingDemand = 0; 
        }

        cout << "\n[Status] Energy allocation complete. Smart Grid stable.\n";
    }
};

int main() {
    cout << "=========================================================\n";
    cout << "   SDG 7: Smart Home Energy Grid Simulation System\n";
    cout << "=========================================================\n";

    SolarPanel mySolar(3.0);
    Battery myBattery(10.0, 2.5);
    PowerGrid mainGrid;

    SmartGrid homeGrid(&mySolar, &myBattery, &mainGrid);

    HeavyAppliance ac("Air Conditioner", 2.5);
    LightAppliance lights("LED Lighting System", 0.5);
    HeavyAppliance heater("Water Heater", 4.0);

    homeGrid.addAppliance(&ac);
    homeGrid.addAppliance(&lights);
    homeGrid.addAppliance(&heater);

    homeGrid.simulateEnergyFlow();

    return 0;
}
