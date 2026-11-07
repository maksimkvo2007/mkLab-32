#include <iostream>
#include <deque>
#include <cstdlib> 
#include <ctime>   
#include "Car.h"

using namespace std;

int main() {
    // Seed the random number generator so we get different results each run
    srand(time(0));

    // Create the deque for the toll booth line and define the initial amount
    deque<Car> tollLine;
    const int INITIAL_CARS = 2;

    // Populate the initial queue with 2 cars
    for (int i = 0; i < INITIAL_CARS; i++) {
        Car newCar;
        tollLine.push_back(newCar);
    }

    // Display the initial queue
    cout << "Initial queue:\n";
    for (Car c : tollLine) {
        cout << "    "; 
        c.print(); // The print method in Car.h handles the formatting and the newline
    }

    
}