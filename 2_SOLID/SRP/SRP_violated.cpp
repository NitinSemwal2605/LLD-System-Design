#include <iostream>
#include <vector>

using namespace std;

// Product entity representing an item in eCommerce
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) : name(name), price(price) {}
};

// Violating SRP: ShoppingCart handles business logic, presentation, and persistence
class ShoppingCart {
private:
    vector<Product> products;

public:
    // 1. Business Logic
    void addProduct(const Product& p) { 
        products.push_back(p);
    }

    const vector<Product>& getProducts() const { 
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (const auto& p : products) {
            total += p.price;
        }
        return total;
    }

    // 2. Violating SRP: Presentation should not be in the cart class
    void printInvoice() const {
        cout << "Shopping Cart Invoice:\n";
        for (const auto& p : products) {
            cout << p.name << " - Rs " << p.price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP: Persistence should not be in the cart class
    void saveToDatabase() const {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart cart;
    
    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    cart.printInvoice();  
    cart.saveToDatabase();

    return 0;
}
