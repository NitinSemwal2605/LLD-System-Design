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

class ShoppingCartPrinter {
private:
    const ShoppingCart& cart;

public:
    ShoppingCartPrinter(const ShoppingCart& cart){
        this->cart = cart;
    }

    void printInvoice() const {
        cout << "Shopping Cart Invoice:\n";
        for (const auto& p : cart.getProducts()) {
            cout << p.name << " - Rs " << p.price << endl;
        }
        cout << "Total: Rs " << cart.calculateTotal() << endl;
    }
};

// Violating OCP: Adding a new storage type requires modifying this class
class ShoppingCartStorage {
private:
    const ShoppingCart& cart;

public:
    ShoppingCartStorage(const ShoppingCart& cart) : cart(cart) {}

    void saveToSQLDatabase() const {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }

    void saveToMongoDatabase() const {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile() const {
        cout << "Saving shopping cart to File..." << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    ShoppingCartPrinter printer(cart);
    printer.printInvoice();

    ShoppingCartStorage db(cart);
    db.saveToSQLDatabase();

    return 0;
}
