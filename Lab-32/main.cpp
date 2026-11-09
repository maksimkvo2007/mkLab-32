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

    // Run the simulation for 20 time periods
    for (int time = 1; time <= TIME_PERIODS; time++) { //just rewriting code from scratch while taking pieces from before
        cout << "\nTime: " << time << "\n";
        
        for (int i = 0; i < NUM_LANES; i++) {
            
            // If the lane is empty, it's a 50/50 chance a car joins
            if (lanes[i].empty()) {
                int prob = rand() % 100 + 1;
                if (prob <= 50) {
                    Car newCar;
                    lanes[i].push_back(newCar);
                    cout << "Lane " << i + 1 << ": Joined: ";
                    newCar.print();
                }
            }
            else {
                int prob = rand() % 100 + 1;

                if (prob <= PROB_PAY) {
                    // 46%: Car at the front pays and leaves
                    cout << "Lane " << i + 1 << ": Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front(); 
                } 
                else if (prob <= PROB_PAY + PROB_JOIN) {
                    // 39%: A new car joins the back of the queue
                    Car newCar;
                    cout << "Lane " << i + 1 << ": Joined: ";
                    newCar.print();
                    lanes[i].push_back(newCar);
                }
                else {
                    // 15%: The car at the back switches to a different random lane
                    Car switchingCar = lanes[i].back();
                    lanes[i].pop_back(); // Remove from current lane

                    // Pick a random target lane that is NOT the current lane
                    int targetLane = i;
                    while (targetLane == i) {
                        targetLane = rand() % NUM_LANES;
                    }

                    // Add the car to the back of the new lane
                    lanes[targetLane].push_back(switchingCar);
                    
                    cout << "Lane " << i + 1 << ": Switched: ";
                    switchingCar.print();
                }
            }
        }

        for (int i = 0; i < NUM_LANES; i++) {
            cout << "Lane " << i + 1 << " Queue:\n";
            if (lanes[i].empty()) {
                cout << "    Empty\n";
            } else {
                for (Car c : lanes[i]) {
                    cout << "    ";
                    c.print();
                }
            }
        }
    }
}