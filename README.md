# Restaurant Management System 🍽️🏨

A comprehensive **Restaurant Management System** built with **C++** demonstrating core **Object-Oriented Programming (OOP)** principles. This console-based application manages restaurant operations including employee management, inventory tracking, room services, and billing systems.

## 🌟 Features

### 👥 Employee Management
- **Add Employees**: Register new staff members (Chef, Receptionist, Housekeeping)
- **Delete Employees**: Remove staff from the system
- **View All Employees**: Display complete employee roster
- **Role-based Operations**: Different functionalities for different employee types

### 📦 Inventory Management
- **Food Items**: Track food inventory with categories
- **Drink Items**: Manage beverage stock with types
- **Stock Checking**: Real-time availability verification
- **Stock Reduction**: Automatic inventory updates after orders

### 🏠 Room & Service Management
- **Room Tracking**: Monitor available rooms (10 rooms)
- **Room Service**: Customer service in rooms
- **Housekeeping**: Room cleaning and maintenance

### 🔐 Authentication System
- **Manager Login**: Secure access with username/password
- **Manager Sign-up**: New manager registration
- **File-based Storage**: Persistent credential storage

### 💰 Billing System
- **Bill Generation**: Calculate order totals
- **Payment Processing**: Handle customer transactions
- **Order Management**: Track customer orders

## 🛠️ Technology Stack

- **Language**: C++
- **Programming Paradigm**: Object-Oriented Programming (OOP)
- **Data Storage**: File-based system (`.txt` files)
- **Architecture**: Console-based application
- **Compilation**: Standard C++ compiler (g++, Visual Studio, etc.)

## 📁 Project Structure

```
├── c.cpp              # Main application source code
├── c.exe              # Compiled executable (Windows)
├── employees.txt      # Employee data storage
├── managers.txt       # Manager credentials storage
└── README.md          # Project documentation
```

## 🏗️ OOP Concepts Demonstrated

### 🔒 **Encapsulation**
- **Private Data Members**: Protected class attributes
- **Public Interfaces**: Controlled access to functionality
- **Data Hiding**: Internal implementation details concealed

### 🧬 **Inheritance**
- **User Base Class**: Common authentication interface
- **Manager Class**: Inherits from User with management capabilities
- **Employee Hierarchy**: Chef, Receptionist, Housekeeping inherit from Employee
- **MenuItem Hierarchy**: FoodItem and DrinkItem inherit from MenuItem

### 🎭 **Polymorphism**
- **Virtual Functions**: Runtime method resolution
- **Function Overriding**: Specialized behavior in derived classes
- **Dynamic Casting**: Safe type conversion for polymorphic objects

### 🎯 **Abstraction**
- **Abstract Classes**: Employee as pure abstract base class
- **Pure Virtual Functions**: Enforced implementation in derived classes
- **Interface Definition**: Clear contracts for derived classes

### 🤝 **Association & Aggregation**
- **Composition**: Bill class composed within the system
- **Aggregation**: Inventory contains FoodItem and DrinkItem collections
- **Association**: Customer, Rooms, and Service relationships

## 🚀 Installation & Setup

### Prerequisites
- C++ compiler (GCC, Clang, MSVC, etc.)
- Standard C++ library support
- Text editor or IDE (VS Code, Visual Studio, Code::Blocks, etc.)

### Compilation

**Using g++**:
```bash
g++ -o restaurant_management c.cpp
```

**Using Visual Studio**:
```bash
cl c.cpp /Fe:restaurant_management.exe
```

**Using Code::Blocks/Dev-C++**:
- Open `c.cpp` in your IDE
- Build and compile the project

### Running the Application

**Windows**:
```cmd
restaurant_management.exe
```

**Linux/macOS**:
```bash
./restaurant_management
```

## 📱 How to Use

### Initial Setup

1. **First Time Users**:
   - Choose option 1 for Sign Up
   - Create manager credentials
   - Login with new credentials

2. **Existing Users**:
   - Choose option 2 for Log In
   - Enter existing username and password

### Manager Operations

Once logged in, managers can access:

1. **Add Employee**:
   - Enter employee name, ID, and role
   - Employee data saved to `employees.txt`

2. **Delete Employee**:
   - Enter employee name to remove
   - System updates employee records

3. **Check Food Stock**:
   - View current inventory levels
   - Display food and drink items

4. **Check Number of Rooms**:
   - View available room count
   - Room capacity information

5. **View All Employees**:
   - Display complete employee roster
   - Show names, IDs, and roles

6. **Exit**:
   - Safe program termination

## 🎯 Class Structure

### Core Classes

```cpp
// Base Classes
class User                  // Authentication base class
class Employee             // Abstract employee base class
class MenuItem            // Menu item base class

// Derived Classes
class Manager : public User              // Manager functionality
class Chef : public Employee            // Chef operations
class Receptionist : public Employee    // Reception duties
class Housekeeping : public Employee    // Cleaning services
class FoodItem : public MenuItem        // Food inventory
class DrinkItem : public MenuItem       // Beverage inventory

// Utility Classes
class Inventory           // Stock management
class Customer           // Customer operations
class Rooms             // Room services
class Bill              // Billing system
```

### Key Methods

```cpp
// Authentication
bool login(const string& user, const string& pass)
void signUp(const string& user, const string& pass)

// Employee Management
void addEmployee()
void deleteEmployee()
void viewAllEmployees()

// Inventory Operations
void addFoodItem(const FoodItem& item)
bool checkAvailability(const MenuItem& item, int quantity)
void reduceStock(const MenuItem& item, int quantity)

// Service Operations
void prepareFood()        // Chef function
void receiveOrder()       // Receptionist function
void cleanRoom()          // Housekeeping function
```

## 🗃️ Data Storage

### File Structure

**managers.txt**:
```
username password
Abdullah 123456
```

**employees.txt**:
```
name id role
Ahmed 1 Chef
Talha 2 Housekeeping
Abdullah 3 Receptionist
```

### Data Management
- **File I/O Operations**: Read/write to text files
- **Data Persistence**: Information saved between sessions
- **Error Handling**: File operation exception management

## 🔧 Configuration

### Default Settings
```cpp
// Room Configuration
const int TOTAL_ROOMS = 10;

// File Names
const string MANAGERS_FILE = "managers.txt";
const string EMPLOYEES_FILE = "employees.txt";

// Sample Inventory
FoodItem burger("Burger", 5.99, "Fast Food");
DrinkItem coke("Coke", 1.99, "Soda");
```

## 🎨 Features Breakdown

### Employee Role System
- **Chef**: Food preparation and kitchen management
- **Receptionist**: Order taking and customer service
- **Housekeeping**: Room cleaning and maintenance

### Inventory Categories
- **Food Items**: Categorized by type (Fast Food, Italian, etc.)
- **Drink Items**: Categorized by type (Soda, Juice, etc.)
- **Stock Levels**: Real-time availability tracking

### Authentication Security
- **Encrypted Storage**: Secure credential management
- **Session Management**: Login state tracking
- **Access Control**: Role-based permissions

## 🔮 Future Enhancements

- [ ] **Database Integration**: MySQL/SQLite support
- [ ] **GUI Interface**: Windows/Qt-based interface
- [ ] **Advanced Billing**: Tax calculation and receipts
- [ ] **Report Generation**: Sales and inventory reports
- [ ] **Multi-location**: Support for multiple restaurant branches
- [ ] **Online Ordering**: Web-based ordering system
- [ ] **Mobile App**: Android/iOS companion app
- [ ] **Analytics Dashboard**: Business intelligence features

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🎓 Educational Value

This project demonstrates:
- **OOP Principles**: Complete implementation of inheritance, polymorphism, encapsulation, and abstraction
- **File I/O**: Reading and writing data to files
- **Exception Handling**: Error management and recovery
- **Memory Management**: Proper object lifecycle management
- **Software Design**: Modular and maintainable code structure

## 📞 Support

For questions, bug reports, or support:

**Abdullah Khan**
- GitHub: [@Abdullahkhan1010](https://github.com/Abdullahkhan1010)
- Email: abdullah.khan1010@gmail.com

---

⭐ **Star this repository if you found it helpful!**

Made with ❤️ using C++ & OOP Principles
