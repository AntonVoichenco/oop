#include<iostream>
#include<string>
using namespace std;

// Базовый класс: Транспорт
class Transport {
public:
    Transport(const string& brand, int year) : brand(brand), year(year) {}

    void displayInfo() const {
        cout << "Марка: " << brand << ", Рік випуску: " << year << endl;
    }

private:
    string brand;
    int year;
};

// Похідний клас: Автомобіль
class Car : public Transport {
public:
    Car(const string& brand, int year, const string& model) : Transport(brand, year), model(model) {}

    void displayModel() const {
        cout << "Модель автомобіля: " << model << endl;
    }

private:
    string model;
};

// Похідний клас: СпортивнийАвтомобіль
class Sportcar : public Car {
public:
    Sportcar(const string& brand, int year, const string& model, int maxSpeed)
        : Car(brand, year, model), maxSpeed(maxSpeed) {}

    void displayMaxSpeed() const {
        cout << "Максимальна швидкість: " << maxSpeed << " км/год" << endl;
    }

private:
    int maxSpeed;
};

// Похідний клас: ГоночнийАвтомобіль
class Racingcar : public Sportcar {
public:
    Racingcar(const string& brand, int year, const string& model, int maxSpeed, const string& team)
        : Sportcar(brand, year, model, maxSpeed), team(team) {}

    void displayTeam() const {
        cout << "Гоночна команда: " << team << endl;
    }

private:
    string team;
};

// Похідний клас: Мотоцикл
class Motorcycle : public Transport {
public:
    Motorcycle(const string& brand, int year, bool hasSideCar)
        : Transport(brand, year), hasSideCar(hasSideCar) {}

    void displaySideCar() const {
        if (hasSideCar) {
            cout << "Мотоцикл має бічний каретний візок" << endl;
        }
        else {
            cout << "Мотоцикл без бічного каретного візка" << endl;
        }
    }

private:
    bool hasSideCar;
};

// Похідний клас: СпортивнийМотоцикл
class Sportmotorcycle : public Motorcycle {
public:
    Sportmotorcycle(const string& brand, int year, bool hasSideCar, bool hasFairing)
        : Motorcycle(brand, year, hasSideCar), hasFairing(hasFairing) {}

    void displayFairing() const {
        if (hasFairing) {
            cout << "Спортивний мотоцикл має обтекатель" << endl;
        }
        else {
            cout << "Спортивний мотоцикл без обтекателя" << endl;
        }
    }

private:
    bool hasFairing;
};

// Похідний клас: Велосипед
class Bicycle : public Transport {
public:
    Bicycle(const string& brand, int year, int numOfGears)
        : Transport(brand, year), numOfGears(numOfGears) {}

    void displayGears() const {
        cout << "Кількість передач у велосипеда: " << numOfGears << endl;
    }

private:
    int numOfGears;
};

// Похідний клас: ГірськийВелосипед
class Mountainbike : public Bicycle {
public:
    Mountainbike(const string& brand, int year, int numOfGears, bool hasSuspension)
        : Bicycle(brand, year, numOfGears), hasSuspension(hasSuspension) {}

    void displaySuspension() const {
        if (hasSuspension) {
            cout << "Гірський велосипед має амортизацію" << endl;
        }
        else {
            cout << "Гірський велосипед без амортизації" << endl;
        }
    }

private:
    bool hasSuspension;
};

int main() {
    Racingcar raceCar("Ferrari", 2022, "SF90", 350, "Scuderia Ferrari");
    raceCar.displayInfo();
    raceCar.displayModel();
    raceCar.displayMaxSpeed();
    raceCar.displayTeam();

    Sportmotorcycle sportBike("Yamaha", 2022, false, true);
    sportBike.displayInfo();
    sportBike.displaySideCar();
    sportBike.displayFairing();

    Mountainbike mountainBike("Trek", 2022, 21, true);
    mountainBike.displayInfo();
    mountainBike.displayGears();
    mountainBike.displaySuspension();

    return 0;
}
