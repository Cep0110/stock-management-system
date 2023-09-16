#include <iostream>
#include<string>
using namespace std;
class Item {
private:
    string name;
    double price;
    int quantity;

public:
    Item(string itemName, double itemPrice, int itemQuantity) {
        name = itemName;
        price = itemPrice;
        quantity = itemQuantity;
    }

    double calculateItemPrice() {
        return price * quantity;
    }

    string getName() {
        return name;
    }
};

int main() {
    int numOfItems;
    cout << "Enter the number of items: ";
    cin >> numOfItems;

    Item** items = new Item*[numOfItems];

    for (int i = 0; i < numOfItems; i++) {
        cout << "Enter the name of item " << i + 1 << ": ";
        string name;
        cin >> name;

        double price;
        cout << "Enter the price of item " << i + 1 << ": ";
        cin >> price;

        int quantity;
       cout << "Enter the quantity of item " << i + 1 << ": ";
        cin >> quantity;

        // Create a new Item object
        items[i] = new Item(name, price, quantity);
    }
  double totalPrice=0.0;
    cout << "\nItem\t\tPrice" << endl;
    cout << "----------------------------" << endl;

    // Calculate and display the price for each item
    for (int i = 0; i < numOfItems; i++) {
        double itemPrice = items[i]->calculateItemPrice();
        cout << items[i]->getName() << "\t\t" << itemPrice << endl;
        totalPrice += itemPrice;
    }

    cout << "----------------------------" << endl;
    cout << "Total Price:\t" << totalPrice << endl;

    // Free memory for each Item object
    for (int i = 0; i < numOfItems; i++) {
        delete items[i];
    }
    delete[ ] items;

    return 0;
}
