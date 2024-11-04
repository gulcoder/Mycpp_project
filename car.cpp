#include <iostream>
using namespace std;

class Car{
    public:
    string brand;
    string model;
    int year;
    double mileage;

    Car(string brand, string model, int year, double mileage){
        this -> brand = brand;
        this -> model = model;
        this -> year = year;
        this ->mileage = mileage;
    }

    void drive(double distance){
        mileage += distance;
        cout <<mileage<<endl;
        cout << distance<<endl;

    }

    void displayInfo(){
        cout << brand << endl;
        cout << model << endl;
        cout << year << endl;
        cout << mileage << endl;
    }

    int getYear(){
        return year;
    }

    double getMileage(){
        return mileage;
    }
};

int main()
{
    Car myVehicle("Toyota", "Aygo", 2016, 25000);
    myVehicle.displayInfo();
    myVehicle.drive(100);

    cout<<"efter körningen: " << endl;

    myVehicle.displayInfo();

    cout<<myVehicle.getYear()<< endl;
    cout<<myVehicle.getMileage()<<endl;






}