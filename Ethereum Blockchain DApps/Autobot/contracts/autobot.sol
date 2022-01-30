// SPDX-License-Identifier: MIT
pragma solidity ^0.8.11;
import "./users.sol";

contract autoBot {

    struct Car { //struct including all the details on each individual car created
        string name;
        uint distanceUntilService;
        uint status;
        uint totalTimeDriven;
        uint totalMilesDriven;
        uint timeStart;
        uint timeStop;
        uint milesDriven;
        uint totalMoney;
    }

    address public autoBot_;
    uint price = 0; //starting price, will increment as details of the ride are provided
    uint distance;
    
    User[] users; //array including all the user 
    Car[] cars; //array including all the cars

    constructor() { // constructor connecting autobots to the contract
        autoBot_ = msg.sender;
    }
    //function to add a new car
    function addCar(string memory name_) public { //adds atttributes to a car and adds it to the car array
        Car memory temp = Car(name_, 3000, 0, 0, 0, 0, 0, 0, 0);
        cars.push(temp);
    }

    //Function to add new users
    function addUser(string memory password_) public { //adds the password arttribute to the user and then adds user to the arry
        User temp = new User(password_);
        users.push(temp);
    }
    
    //Function to order new rides
    function summonRide(uint userNumber, string memory password, uint car, uint distance_) public {
        if (cars[car].status == 0 && users[userNumber].authenticator(password)) { // Checks if the car is available and the password is correct
            cars[car].status = 1; // Sets the car status to busy
            cars[car].timeStart = 0; // Sets the begin time to 0
            cars[car].timeStop = 0; // Sets the end time to 0
            price += 20; // Adds the inital fee
            for (uint i = 0; i < distance; i++) { // Loops through the miles
                cars[car].timeStop++; // Increases time
            }
            cars[car].totalMilesDriven += distance_; // total miles driven
            cars[car].totalTimeDriven += cars[car].timeStop; //total time driven
            cars[car].distanceUntilService -= distance_; // The distance until a service variable
            cost(distance_); // Updates the cost
            cars[car].totalMoney += price; // Increasees the car's total revenue generated
            cars[car].status = 0; // Sets the car's status to available
            if (cars[car].distanceUntilService <= 0) { // Checks if the car needs service
                cars[car].status = 2; // Sets the car status to being serviced
                for (uint i = 0; i < 20; i++) { // Loops through the distance to the shop
                    cars[car].totalMilesDriven++; // Updates the cars total miles
                    cars[car].totalTimeDriven++; // Updates the total drive time
                }
                cars[car].status = 0; // Sets the car status to available
            }
        }
        if (cars[car].distanceUntilService <= 0) { // Checks if the car needs to be serviced
            cars[car].status = 2; // Sets the car status to being serviced
            for (uint i = 0; i < 20; i++) { // Loops through the miles needed to get to the shop
                cars[car].totalMilesDriven++; // Increments the total miles driven
                cars[car].totalTimeDriven++; // Increments the total time driven
            }
            cars[car].status = 0; // Sets the car status to available
        }
    }
   
   //The cost for each car according to miles driven 
    function cost(uint miles_) public { 
        price += miles_ * 5; // Price according to miles driven will be incremented by 5
    } 

    //Function to display vechile status  
    function displayVehicleStatus(uint i) public view returns (string memory) {
        string memory status = "fdsafdsa"; // Initializes the return variable
        if (cars[i].status == 0) { status = "Available"; } // Sets the return variable to available
        else if (cars[i].status == 1) { status  = "Busy"; } // Sets the return varilable to busy
        else if (cars[i].status == 2) { status = "Being Serviced At Shop"; } // Sets the return varilable to being serviced
        return status;
    }

    // Function to display when the next service is needed
    function displayNextService(uint car) public view returns (uint nextService) {
        nextService = cars[car].distanceUntilService; // Sets the return variable to the distance until next serivce
    }

    // Function to display vehicle totals
    function displayTotals(uint car) public view returns (uint totalMilesDriven_, uint totalTimeDriven_, uint totalMoney_) {
        totalMoney_ = cars[car].totalMoney; // Sets the first return variable to the total Money earned
        totalMilesDriven_ = cars[car].totalMilesDriven; // Sets the second return variable to the total miles driven
        totalTimeDriven_ = cars[car].totalTimeDriven; // Sets the third return variable to the total time driven
    }

    // Function to output all the users
    function displayUserProfiles() public view returns (User[] memory users_) {
        users_ = users; // Sets the return variable to the list of users
    }

    // Function to ouput all cars
    function displayCarProfiles() public view returns (Car[] memory cars_) {
        cars_ = cars; // Sets the return variable to the list of cars
    }
}