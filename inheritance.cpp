#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Set up the base class
class Employee {
    
    private: // cannot be directly accessed by the derived class, this can be done by using protected members
        
    protected: // can be directly accessed by the derived class if inheritance is public [solution to access level problems]
        string name; 
        double pay;

    public: 
        // Set up default constructor
        Employee() {
            name = "";
            pay = 0;
        }
        // Set up parametrized constructor
        Employee(string empName, double payRate) {
            name = empName; 
            pay = payRate;
        }
        // Destructor called automatically when object deleted from the program
        ~ Employee() {
            // Free allocated resources
        }

        // Getter and Setters
        string getName() {
            return name; 
        }
        void setName(string empName) {
            name = empName;
        }
        double getPay() {
            return pay;
        }
        void setPay(double payRate) {
            pay = payRate;
        }
        
        // String Tostring
        string toString() {
            // Create a string stream object <sstream>
            stringstream stm; 
            stm << name << ": " << pay;
            return stm.str();
        }

        // The following function will be overwritten because it is not applicable for salaried employees
        double grossPay(int hours) {
            return pay * hours; 
        }
};

// Set up Derived classes [inheritance] 
class Manager : public Employee {

    private: 
        bool salaried; // indicate if the manager is a salary employee
    
    public: 

        // Default constructor [constructor for the base class is called automatically]
        Manager() : salaried(true) { }

        // Parametrized constructor
        Manager (string name, double payRate, bool isSalaried) 
            : Employee(name, payRate) // call to the base class contrucotr following a colon
        {
            salaried = isSalaried;
        }

        // Destructor to deallocate the resource upon deletion [preceded by tilda ~]
        ~Manager() {
            // Free allocated resources

        }
        // Create a getter
        bool getSalaried() {
            return salaried;
        } 

        // Create a gross pay function [will be the same as the salary ifSalaried]
        double grossPay(int hours) {
            if (salaried) {
                return pay;
            }
            else {
                return pay * hours; 
            }
        }

        string toString() {
            stringstream stm; 
            string salary;
            if (salaried) {
                salary = "Salaried";
            }
            else {
                salary = "hourly";
            }
            stm << name << ": " << pay << ": " << salary << endl;
            return stm.str();
        }
};


int main() {

    Employee emp1("Mary Smith", 15.00);
    cout << "Employee Name: " << emp1.getName() << endl; 
    cout << "Employee Pay Rate: " << emp1.getPay() << endl;
    cout << "Employee Gross pay: " << emp1.grossPay(40) << endl << endl;   

    Manager emp2("Boby Brown", 1500, true);
    cout << emp2.toString();
    cout << "Employee Groos pay: " << emp2.grossPay(40) << endl; // The number of hours would not matter since the employee is salaried
    return 0;
}