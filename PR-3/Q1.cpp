#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle() {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int y) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
        totalVehicles++;
    }

    virtual ~Vehicle() { totalVehicles--; }

    virtual void display() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    int getID() { return vehicleID; }
};

int Vehicle::totalVehicles = 0;

class Car : virtual public Vehicle {
protected:
    string fuelType;

public:
    Car() {}
    Car(int id, string manu, string mod, int y, string fuel)
        : Vehicle(id, manu, mod, y), fuelType(fuel) {}

    void display() override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int y, string fuel, int battery)
        : Car(id, manu, mod, y, fuel), batteryCapacity(battery) {}

    void display() override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft : virtual public Vehicle {
protected:
    int flightRange;

public:
    Aircraft(int id, string manu, string mod, int y, int range)
        : Vehicle(id, manu, mod, y), flightRange(range) {}

    void display() override {
        Vehicle::display();
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string manu, string mod, int y, string fuel, int range)
        : Vehicle(id, manu, mod, y), Car(id, manu, mod, y, fuel),
          Aircraft(id, manu, mod, y, range) {}

    void display() override {
        cout << "--- Flying Car ---" << endl;
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class SportCar : public ElectricCar {
    int topSpeed;

public:
    SportCar(int id, string manu, string mod, int y, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, y, fuel, battery), topSpeed(speed) {}

    void display() override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan(int id, string manu, string mod, int y, string fuel)
        : Car(id, manu, mod, y, fuel) {}
};

class SUV : public Car {
public:
    SUV(int id, string manu, string mod, int y, string fuel)
        : Car(id, manu, mod, y, fuel) {}
};

class VehicleRegistry {
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }

    void displayAll() {
        if (vehicles.empty()) {
            cout << "No vehicles found!" << endl;
            return;
        }

        cout << "\n--- Vehicle List ---\n";
        for (auto v : vehicles) {
            v->display();
            cout << "---------------------\n";
        }
    }

    void searchByID(int id) {
        bool found = false;
        for (auto v : vehicles) {
            if (v->getID() == id) {
                v->display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Vehicle with ID " << id << " not found!" << endl;
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n========= Vehicle Management System =========\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. Add Flying Car\n";
        cout << "4. Add Sport Car\n";
        cout << "5. View All Vehicles\n";
        cout << "6. Search Vehicle by ID\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, year;
            string manu, mod, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, FuelType: ";
            cin >> id >> manu >> mod >> year >> fuel;
            registry.addVehicle(new Car(id, manu, mod, year, fuel));
        }
        else if (choice == 2) {
            int id, year, battery;
            string manu, mod, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, FuelType, BatteryCapacity: ";
            cin >> id >> manu >> mod >> year >> fuel >> battery;
            registry.addVehicle(new ElectricCar(id, manu, mod, year, fuel, battery));
        }
        else if (choice == 3) {
            int id, year, range;
            string manu, mod, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, FuelType, FlightRange: ";
            cin >> id >> manu >> mod >> year >> fuel >> range;
            registry.addVehicle(new FlyingCar(id, manu, mod, year, fuel, range));
        }
        else if (choice == 4) {
            int id, year, battery, speed;
            string manu, mod, fuel;
            cout << "Enter ID, Manufacturer, Model, Year, FuelType, BatteryCapacity, TopSpeed: ";
            cin >> id >> manu >> mod >> year >> fuel >> battery >> speed;
            registry.addVehicle(new SportCar(id, manu, mod, year, fuel, battery, speed));
        }
        else if (choice == 5) {
            registry.displayAll();
        }
        else if (choice == 6) {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchByID(id);
        }
        else if (choice == 7) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    cout << "\nTotal Vehicles Remaining: " << Vehicle::totalVehicles << endl;
    return 0;
}