#include <iostream>
#include <string>

using namespace std;

class StockItem {
private:
    string name;
    int quantity;
    float price;

public:
    StockItem() {
        name = "";
        quantity = 0;
        price = 0.0;
    }

    void setName(string itemName) {
        name = itemName;
    }

    void setQuantity(int itemQuantity) {
        quantity = itemQuantity;
    }

    void setPrice(float itemPrice) {
        price = itemPrice;
    }

    string getName()  {
        return name;
    }

    int getQuantity() {
        return quantity;
    }

    float getPrice()  {
        return price;
    }
};

int main() {
    StockItem item;

    string name;
    int quantity;
    float price;

    cout << "Enter the name of the stock item: ";
    getline(cin, name);
    item.setName(name);

    cout << "Enter the quantity of the stock item: ";
    cin >> quantity;
    item.setQuantity(quantity);

    cout << "Enter the price of the stock item: ";
    cin >> price;
    item.setPrice(price);

    // Displaying the stock item details
    cout << "\nStock Item Details:" << endl;
    cout << "Name: " << item.getName() << endl;
    cout << "Quantity: " << item.getQuantity() << endl;
    cout << "Price: " << item.getPrice() << endl;

    return 0;}
