#include <iostream>
using namespace std;

class Car {
public:
    char* brand;    
    char* model;   
    int year;
    double mileage;

    
    Car(const char* brand, const char* model, int year, double mileage) {
        this->brand = new char[strlen(brand) + 1];  
        this->model = new char[strlen(model) + 1];  
        strcpy(this->brand, brand);                  
        strcpy(this->model, model);                  
        this->year = year;
        this->mileage = mileage;
    }

    
    ~Car() {
        delete[] this->brand;  
        delete[] this->model;  
    }

    
    void drive(double distance) {
        this->mileage += distance;  
    }

    
    void displayInfo() {
        cout  << this->brand << endl;
        cout << this->model<< endl;
        cout << this->year<< endl;
        cout <<this->mileage<<endl;
        
    }

    
    int getYear() {
        return this->year;
    }

    double getMileage() {
        return this->mileage;
    }
};

int main() {
    Car myVehicle("Toyota", "Corolla", 2020, 15000);
    
    
    myVehicle.displayInfo();

    
    myVehicle.drive(100);
    
 
    myVehicle.displayInfo();

    return 0;
}
