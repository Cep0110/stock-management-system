#include<iostream>
using namespace std;

class StockItem {
    private:
        string itemName;
        int quantity;
        float price;
    
    public:
        StockItem(string name, int qty, float pr) {
            itemName = name;
            quantity = qty;
            price = pr;
        }
        
        string getItemName() {
            return itemName;
        }
        
        int getQuantity() {
            return quantity;
        }
        
        float getPrice() {
            return price;
        }
        
        void display() {
            cout << "Item Name: " << itemName << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: $" << price << endl;
            cout << endl;
        }
};

int main() {
    // Create StockItem objects
    StockItem item1("Item 1", 5, 10.99);
    StockItem item2("Item 2", 10, 4.99);
    StockItem item3("Item 3", 2, 19.99);
    
    // Display initial stock items
    cout << "Initial Stock Items:" << endl;
    item1.display();
    item2.display();
    item3.display();
    
    // Remove StockItem
    string itemNameToRemove;
    cout << "Enter the name of the item you want to remove: ";
    getline(cin, itemNameToRemove);
    
    if (itemNameToRemove == item1.getItemName()) {
        item1 = StockItem("", 0, 0.0);
    } else if (itemNameToRemove == item2.getItemName()) {
        item2 = StockItem("", 0, 0.0);
    } else if (itemNameToRemove == item3.getItemName()) {
        item3 = StockItem("", 0, 0.0);
    } else {
        cout << "Item not found!" << endl;
    }
    
    // Display remaining stock items
    cout << "Remaining Stock Items:" << endl;
    item1.display();
    item2.display();
    item3.display();
    
    return 0;
