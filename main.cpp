#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
class Car {
public:
    std::string car_plate;

    Car() {
        car_plate = "not_set";
    }

    Car(std::string plate){
        this->car_plate = plate;
    }
};

class Parking {
private:
    int free_places;
    LinkedList<Car> *list = new LinkedList<Car>;
public:
    Parking() {
        free_places = 10;
    }

    void AddCars(Car *car) {
        if (free_places == 0) {
            std::cout << "Parking have not free places\n";
            return;
        }
        list->pushFront(*car);
        free_places--;
    }

    int getCarsCount() {
        return list->getSize();
    }

    void printParkedCars() {
        for(int i = 0; i < list->getSize(); i++) {
            std::cout << list->get(i).car_plate << std::endl;
        }
    }

    ~Parking() {
        delete list;
    }
};

int main() {
    Parking parking;
    Car car1("Y077MC116");
    parking.AddCars(&car1);

    parking.printParkedCars();
}