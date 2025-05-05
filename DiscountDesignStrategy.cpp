#include <iostream>
using namespace std;

class Discount {
public:
    virtual double apply(double price) = 0;
    virtual ~Discount() {}
};

class NoDiscount : public Discount {
public:
    double apply(double price) override {
        return price;
    }
};

class TenPercentDiscount : public Discount {
public:
    double apply(double price) override {
        return price * 0.90;
    }
};

class TwentyPercentDiscount : public Discount {
public:
    double apply(double price) override {
        return price * 0.80;
    }
};


class DiscountCalculator {
private:
    Discount* discount;
public:
    DiscountCalculator() : discount(nullptr) {}

    void setDiscount(Discount* newDiscount) {
        delete discount;
        discount = newDiscount;
    }

    double calculate(double price) {
        if (discount) {
            return discount->apply(price);
        } else {
            cout << "No discount type selected." << endl;
            return price;
        }
    }

    ~DiscountCalculator() {
        delete discount;
    }
};

int main() {
    DiscountCalculator calc;
    int choice;
    double price;

    do {
        cout << "\nDiscount Calculator | Enter an option.\n";
        cout << "1. No Discount\n";
        cout << "2. 10% Discount\n";
        cout << "3. 20% Discount\n";
        cout << "4. Exit\n";
        cout << "Choose a discount option (1-4): ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter original price: ";
            cin >> price;
        }

        switch (choice) {
            case 1:
                calc.setDiscount(new NoDiscount());
                cout << "Final Price: " << calc.calculate(price) << endl;
                break;
            case 2:
                calc.setDiscount(new TenPercentDiscount());
                cout << "Final Price: " << calc.calculate(price) << endl;
                break;
            case 3:
                calc.setDiscount(new TwentyPercentDiscount());
                cout << "Final Price: " << calc.calculate(price) << endl;
                break;
            case 4:
                cout << "Exiting. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);
    return 0;
}
