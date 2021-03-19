class ParkingSystem {
public:
    int car_space[4];
    ParkingSystem(int big, int medium, int small) {
        car_space[0] = big;
        car_space[1] = medium;
        car_space[2] = small;
    }

    bool addCar(int carType) {
        carType--;
        if (car_space[carType] > 0) {
            car_space[carType]--;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
