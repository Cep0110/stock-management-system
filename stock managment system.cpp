#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Class to represent a stock item
class StockItem {
private:
    string name;
    int quantity;
    double price;

public:
    StockItem(string name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}

    string getName()   {
        return name;
    }

    int getQuantity()   {
        return quantity;
    }

    double getPrice()   {
        return price;
    }

    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }
    void setPrice(int newPrice) {
        quantity = newPrice ;
    }

    double getItemPrice()   {
        return quantity * price;
    }
};

// Stock Management System class
class StockManagementSystem {
private:
    vector<StockItem> inventory;

public:
    // Function to add a new stock item to the inventory
    void addStockItem() {
        string name;
        int quantity;
        double price;

        cout << "Enter the name of the item: ";
        cin >> name;

        cout << "Enter the quantity of the item: ";
        cin >> quantity;

        cout << "Enter the price of the item: ";
        cin >> price;

        StockItem newItem(name, quantity, price);
        inventory.push_back(newItem);

        cout << "Item added successfully!" << endl;
    }

    // Function to display the current inventory
    void displayInventory()   {
        cout << "Current Inventory:" << endl;

        for (  StockItem& item : inventory) {
            cout << "Name: " << item.getName() << ", Quantity: " << item.getQuantity() << ", Price: $" << item.getPrice() << endl;
        }
    }

    // Function to calculate the price of each item in the inventory
    void calculateItemPrices() {
        cout << "Item Prices:" << endl;

        for ( StockItem& item : inventory) {
            cout << "Name: " << item.getName() << ", Item Price: $" << item.getItemPrice() << endl;
        }
    }

    // Function to calculate the total price of all items in the inventory
    double calculateTotalPrice()   {
        double totalPrice = 0.0;

        for (  StockItem& item : inventory) {
            totalPrice += item.getItemPrice();
        }

        return totalPrice;
    }

   

public:
    

    // Function to update the quantity and price of a stock item
    void updateItem() {
        string name;
        int newQuantity;
        double newPrice;

        cout << "Enter the name of the item to update: ";
        cin >> name;

        cout << "Enter the new quantity: ";
        cin >> newQuantity;

        cout << "Enter the new price: ";
        cin >> newPrice;

        bool found = false;

        for (StockItem& item : inventory) {
            if (item.getName() == name) {
                item.setQuantity(newQuantity);
                item.setPrice(newPrice);
                found = true;
                break;
            }
        }
       
        if (found) {
            cout << "Item updated successfully!" << endl;
        } else {
            cout << "Item not found!" << endl;
        }
    } 


    // Function to remove a stock item from the inventory
    void removeStockItem() {
        string name;

        cout << "Enter the name of the item to remove: ";
        cin >> name;

        bool found = false;

        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getName() == name) {
                inventory.erase(it);
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Item removed successfully!" << endl;
        } else {
            cout << "Item not found!" << endl;
        }
    }

    // Function to save the inventory to a file
    void saveToFile()  {
        ofstream file("inventory.txt");

        for ( StockItem& item : inventory 
) {
            file << item.getName() << "," << item.getQuantity() << "," << item.getPrice() << endl;
        }

        file.close();
        cout << "Inventory saved to file successfully!" << endl;
    }
};
int main() {
    StockManagementSystem system;
    int choice;

    while (true) {
        // Display menu options
        cout << "Stock Management System" << endl;
        cout << "1. Add a new stock item" << endl;
        cout << "2. Display current inventory" << endl;
        cout << "3. Calculate item prices" << endl;
        cout << "4. Calculate total price" << endl;
        cout << "5. Update the stock item" << endl;
        cout << "6. Remove stock item" << endl;
        cout << "7. Save inventory to file" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addStockItem();
                break;
            case 2:
                system.displayInventory();
                break;
            case 3:
                system.calculateItemPrices();
                break;
            case 4:
                cout << "Total Price: $" << system.calculateTotalPrice() << endl;
                break;
            case 5:
                system.updateItem();
                break;
            case 6:
                system.removeStockItem();
                break;
            case 7:
                system.saveToFile();
                break;
            case 8:
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
