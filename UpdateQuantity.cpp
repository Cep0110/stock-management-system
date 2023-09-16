#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    string name;
    float price;
    int quantity;

public:
    Item(string name, float price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    void updatePrice(float newPrice) {
        this->price = newPrice;
    }

    void updateQuantity(int newQuantity) {
        this->quantity = newQuantity;
    }

    void displayItem() {
        cout << "Item: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    // Create an item object
    Item item("Car", 800.0, 5);

    // Display item details
    item.displayItem();

    // Update price and quantity
    item.updatePrice(1600.0);
    item.updateQuantity(10);

    // Display updated item details
    item.displayItem();

    return 0;
}
