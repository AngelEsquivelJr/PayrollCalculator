#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Employee
{
public:
    //vars for employees
    string name;
    double payrate;
    int hours;
    double gross, tax, realtax, net;

    //function to get info for an employee
    void getInfo() {
        cout << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter pay rate: ";
        cin >> payrate;
        cout << "Enter hours worked: ";
        cin >> hours;
        calculate();
    }
    //function to calculate pay
    void calculate() {
        tax = .0825;

        if (hours > 40) {
            gross = (payrate * 1.5) * hours;
            realtax = gross * tax;
            net = gross - realtax;

        }
        else {
            gross = payrate * hours;
            realtax = gross * tax;
            net = gross - realtax;
        }
    }
    //function to display payroll
    void display()
    {
        cout << setprecision(2) << fixed << endl;
        cout << "__________________" << endl;
        cout << "Name: " << name << endl;
        cout << "Hours: " << hours << endl;
        cout << "Hourly pay rate: " << payrate << endl;
        cout << "Gross: " << gross << endl;
        cout << "Taxes: " << realtax << endl;
        cout << "Net Pay: " << net << endl;
        cout << "__________________" << endl;
    }
};

int main(int argc, char** argv) {
    //ask how many employees you need to calculate
    int intEmployees;
    cout << "How many employees would you like to calculate pay for? ";
    cin >> intEmployees;

    //vector pointer
    vector<Employee*> e;

    //create employee in vector and get and display info
    for (int i = 0; i < intEmployees; i++)
    {
        e.push_back(new Employee());
        e[i]->getInfo();
        e[i]->display();
    }

    //prevent memory leaks
    for (int i = 0; i < e.size(); i++)
    {
        delete e[i];
    }

    e.clear();

    return 0;
}