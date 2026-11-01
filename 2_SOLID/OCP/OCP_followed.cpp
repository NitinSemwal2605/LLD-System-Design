#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {}
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
    ShoppingCartPrinter(const ShoppingCart& cart) : cart(cart) {}

    void printInvoice() const {
        cout << "Shopping Cart Invoice:\n";
        for (const auto& p : cart.getProducts()) {
            cout << p.name << " - Rs " << p.price << endl;
        }
        cout << "Total: Rs " << cart.calculateTotal() << endl;
    }
};

// Follows OCP: Abstract interface open for extension, closed for modification
class Persistence {
public:
    virtual void save(const ShoppingCart& cart) = 0;
    virtual ~Persistence() = default;
};

class SQLPersistence : public Persistence {
public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistence : public Persistence {
public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public Persistence {
public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 2000));

    ShoppingCartPrinter printer(cart);
    printer.printInvoice();

    SQLPersistence sqlDb;
    MongoPersistence mongoDb;
    FilePersistence fileDb;

    sqlDb.save(cart);
    mongoDb.save(cart);
    fileDb.save(cart);

    return 0;
}
