#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// 1. Follows SRP: Solely responsible for Cart business logic
class ShoppingCart {
private:
    vector<Product> products;

public:
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
};

// 2. Follows SRP: Solely responsible for printing invoices
class ShoppingCartPrinter {
private:
    const ShoppingCart& cart;

public:
    ShoppingCartPrinter(const ShoppingCart& cart) : cart(cart) {}

    void printInvoice() const {
        cout << "Shopping Cart Invoice:\n";
        for (const auto& p : cart.getProducts()) {
            cout << p.name << " - Rs " << p.price << endl;
        }
        cout << "Total: Rs " << cart.calculateTotal() << endl;
    }
};

// 3. Follows SRP: Solely responsible for saving cart to database
class ShoppingCartStorage {
private:
    const ShoppingCart& cart;

public:
    ShoppingCartStorage(const ShoppingCart& cart) : cart(cart) {}

    void saveToDatabase() const {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    ShoppingCartPrinter printer(cart);
    printer.printInvoice();

    ShoppingCartStorage db(cart);
    db.saveToDatabase();

    return 0;
}
