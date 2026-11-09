#include <iostream>
#include <deque>
#include <cstdlib> 
#include <ctime>   
#include "Car.h"

using namespace std;

int main() {
    // Seed the random number generator so we get different results each run
    srand(time(0));

    // Constants based on the lab requirements
    const int NUM_LANES = 4;
    const int INITIAL_CARS = 2;
    const int TIME_PERIODS = 20;

    const int PROB_PAY = 46;
    const int PROB_JOIN = 39;
    const int PROB_SWITCH = 15;

    // Create an array of 4 toll booth lanes
    deque<Car> lanes[NUM_LANES];

    // Pre-populate all 4 lanes with 2 cars each
    for (int i = 0; i < NUM_LANES; i++) {
        for (int j = 0; j < INITIAL_CARS; j++) {
            Car newCar;
            lanes[i].push_back(newCar);
        }
    }

    // Display the initial state of all lanes
    cout << "Initial queue:\n";
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << " Queue:\n";
        for (Car c : lanes[i]) {
            cout << "    "; 
            c.print(); 
        }
    }

    // Start tracking the time cycles
    int time = 1;

    // Run the simulation until the queue is empty
    while (!tollLine.empty()) {
        
        // Generate a random number from 1 to 100 to determine the operation
        int probability = rand() % 100 + 1;

        if (probability <= 55) {
            // 55% probability: Car at the front pays its toll and leaves
            cout << "Time: " << time << " Operation: Car paid: ";
            tollLine.front().print();
            tollLine.pop_front();
        }
        else {
            // 45% probability: A new car joins the back of the line
            Car newCar;
            cout << "Time: " << time << " Operation: Joined lane: ";
            newCar.print();
            tollLine.push_back(newCar);
        }
        cout << "Queue:\n";
        if (tollLine.empty()) {
            cout << "    Empty\n";
        } else {
            // Loop through and print every car currently in the lane
            for (Car c : tollLine) {
                cout << "    ";
                c.print();
            }
        }

        // Advance to the next time cycle
        time++;
    }
}