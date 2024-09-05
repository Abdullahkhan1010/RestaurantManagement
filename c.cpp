#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Forward declaration of Inventory class
class Inventory;

// Base class for User demonstrating Encapsulation
class User {
protected:
    string username;
    string password;

public:
    User(const string& user, const string& pass) : username(user), password(pass) {}

    virtual bool login(const string& user, const string& pass) const = 0;
};

// Derived class for Manager demonstrating Inheritance and Function Overriding
class Manager : public User {
public:
    Manager(const string& user, const string& pass) : User(user, pass) {}

    bool login(const string& user, const string& pass) const override {
        ifstream file("managers.txt");
        string storedUser, storedPass;

        while (file >> storedUser >> storedPass) {
            if (storedUser == user && storedPass == pass) {
                return true;
            }
        }
        return false;
    }

    void manage() const {
        cout << "Manager managing..." << endl;
    }

    static void signUp(const string& user, const string& pass) {
        ofstream file("managers.txt", ios::app);
        file << user << " " << pass << endl;
    }

    // Function to display manager menu
    void displayMenu() const {
        cout << "\nManager Menu:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Check Food Stock" << endl;
        cout << "4. Check Number of Rooms" << endl;
        cout << "5. View All Employees" << endl;
        cout << "6. Exit" << endl;
    }

    // Function to add an employee
    void addEmployee() const {
        string name, role;
        int id;

        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Role (Chef/Receptionist/Housekeeping): ";
        cin >> role;

        ofstream file("employees.txt", ios::app);
        file << name << " " << id << " " << role << endl;

        cout << "Employee added successfully." << endl;
    }

    // Function to delete an employee
    void deleteEmployee() const {
        string name;
        vector<string> employees;
        string line;

        cout << "Enter Employee Name to Delete: ";
        cin >> name;

        ifstream infile("employees.txt");
        while (getline(infile, line)) {
            if (line.find(name) == string::npos) {
                employees.push_back(line);
            }
        }
        infile.close();

        ofstream outfile("employees.txt");
        for (const auto& emp : employees) {
            outfile << emp << endl;
        }

        cout << "Employee deleted successfully." << endl;
    }

    // Function to check food stock
    void checkFoodStock(const Inventory& inventory) const;

    // Function to check the number of rooms
    void checkRooms() const {
        cout << "Number of rooms: 10" << endl;  // This is a placeholder, you can implement room management logic
    }

    // Function to view all employees
    void viewAllEmployees() const {
        ifstream file("employees.txt");
        string name, role;
        int id;

        cout << "\nAll Employees:" << endl;
        while (file >> name >> id >> role) {
            cout << "Name: " << name << ", ID: " << id << ", Role: " << role << endl;
        }
    }
};

// Abstract class for Employee demonstrating Abstraction
class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& n, int i) : name(n), id(i) {}

    virtual void display() const = 0;  // Pure virtual function
};

// Derived class for Chef demonstrating Inheritance and Function Overriding
class Chef : public Employee {
public:
    Chef(const string& n, int i) : Employee(n, i) {}

    void display() const override {
        cout << "Chef Name: " << name << ", ID: " << id << endl;
    }

    void prepareFood() const {
        cout << "Chef preparing food..." << endl;
    }
};

// Derived class for Receptionist demonstrating Inheritance and Function Overriding
class Receptionist : public Employee {
public:
    Receptionist(const string& n, int i) : Employee(n, i) {}

    void display() const override {
        cout << "Receptionist Name: " << name << ", ID: " << id << endl;
    }

    void receiveOrder() const {
        cout << "Receptionist receiving order..." << endl;
    }
};

// Derived class for Housekeeping demonstrating Inheritance and Function Overriding
class Housekeeping : public Employee {
public:
    Housekeeping(const string& n, int i) : Employee(n, i) {}

    void display() const override {
        cout << "Housekeeping Name: " << name << ", ID: " << id << endl;
    }

    void cleanRoom() const {
        cout << "Housekeeping cleaning room..." << endl;
    }
};

// Base class for MenuItem with virtual functions demonstrating Polymorphism
class MenuItem {
protected:
    string name;
    double price;

public:
    MenuItem(const string& n, double p) : name(n), price(p) {}

    virtual void display() const {
        cout << "Name: " << name << ", Price: $" << price << endl;
    }

    virtual double getPrice() const {
        return price;
    }

    string getName() const {
        return name;
    }
};

// Derived class for FoodItem demonstrating Inheritance and Function Overriding
class FoodItem : public MenuItem {
private:
    string category;

public:
    FoodItem(const string& n, double p, const string& c) : MenuItem(n, p), category(c) {}

    void display() const override {
        cout << "Category: " << category << ", ";
        MenuItem::display();
    }
};

// Derived class for DrinkItem demonstrating Inheritance and Function Overriding
class DrinkItem : public MenuItem {
private:
    string type;

public:
    DrinkItem(const string& n, double p, const string& t) : MenuItem(n, p), type(t) {}

    void display() const override {
        cout << "Type: " << type << ", ";
        MenuItem::display();
    }
};

// Class for Inventory demonstrating Aggregation
class Inventory {
private:
    vector<FoodItem> foodItems;
    vector<DrinkItem> drinkItems;

public:
    void addFoodItem(const FoodItem& item) {
        foodItems.push_back(item);
    }

    void addDrinkItem(const DrinkItem& item) {
        drinkItems.push_back(item);
    }

    bool checkAvailability(const MenuItem& item, int quantity) const {
        if (const FoodItem* foodItem = dynamic_cast<const FoodItem*>(&item)) {
            for (const auto& f : foodItems) {
                if (f.getName() == foodItem->getName() && quantity <= 1) {
                    return true;
                }
            }
        } else if (const DrinkItem* drinkItem = dynamic_cast<const DrinkItem*>(&item)) {
            for (const auto& d : drinkItems) {
                if (d.getName() == drinkItem->getName() && quantity <= 1) {
                    return true;
                }
            }
        }
        return false;
    }

    void reduceStock(const MenuItem& item, int quantity) {
        if (const FoodItem* foodItem = dynamic_cast<const FoodItem*>(&item)) {
            for (auto it = foodItems.begin(); it != foodItems.end(); ++it) {
                if (it->getName() == foodItem->getName() && quantity <= 1) {
                    foodItems.erase(it);
                    break;
                }
            }
        } else if (const DrinkItem* drinkItem = dynamic_cast<const DrinkItem*>(&item)) {
            for (auto it = drinkItems.begin(); it != drinkItems.end(); ++it) {
                if (it->getName() == drinkItem->getName() && quantity <= 1) {
                    drinkItems.erase(it);
                    break;
                }
            }
        }
    }

    void displayStock() const {
        cout << "Food Items:" << endl;
        for (const auto& item : foodItems) {
            item.display();
        }
        cout << "Drink Items:" << endl;
        for (const auto& item : drinkItems) {
            item.display();
        }
    }
};

// Function definition for checking food stock
void Manager::checkFoodStock(const Inventory& inventory) const {
    cout << "\nFood Stock:" << endl;
    inventory.displayStock();
}

// Class for Customer demonstrating Association
class Customer {
public:
    void placeOrder() const {
        cout << "Customer placing order..." << endl;
    }

    void eat() const {
        cout << "Customer eating..." << endl;
    }
};

// Class for Rooms demonstrating Association
class Rooms {
public:
    void serveCustomer() const {
        cout << "Serving customer in the room..." << endl;
    }
};

// Class for Bill demonstrating Composition
class Bill {
private:
    double amount;

public:
    Bill(double amt) : amount(amt) {}

    void generateBill() const {
        cout << "Generating bill for amount: $" << amount << endl;
    }
};

// Function for manager login with error handling using exceptions
bool managerLogin() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    try {
        Manager manager(username, password);
        if (manager.login(username, password)) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cerr << "Login failed. Invalid credentials." << endl;
            return false;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}

// Function for manager sign-up
void managerSignUp() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    Manager::signUp(username, password);
    cout << "Sign-up successful! Please log in." << endl;
}

int main() {
    int choice;
    cout << "1. Sign Up\n2. Log In\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        managerSignUp();
    }

    if (!managerLogin()) {
        return 1;
    }

    // Dummy data
    FoodItem burger("Burger", 5.99, "Fast Food");
    DrinkItem coke("Coke", 1.99, "Soda");

    Inventory inventory;
    inventory.addFoodItem(burger);
    inventory.addDrinkItem(coke);

    Receptionist receptionist("Alice", 1);
    Rooms roomService;
    Customer customer;
    Chef chef("Bob", 2);
    Housekeeping housekeeping("Charlie", 3);
    Bill bill(0.0);

    // Main manager menu loop
    Manager manager("dummy", "dummy");  // Dummy manager for accessing menu functions
    int managerChoice;
    do {
        manager.displayMenu();
        cout << "Enter your choice: ";
        cin >> managerChoice;

        switch (managerChoice) {
            case 1:
                manager.addEmployee();
                break;
            case 2:
                manager.deleteEmployee();
                break;
            case 3:
                manager.checkFoodStock(inventory);
                break;
            case 4:
                manager.checkRooms();
                break;
            case 5:
                manager.viewAllEmployees();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (true);

    return 0;
}
