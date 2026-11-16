#include <iostream>
using namespace std;

class Employee
{
public:
    virtual double calculateSalary() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee
{
private:
    double fixedSalary;

public:
    FullTimeEmployee(double salary)
    {
        fixedSalary = salary;
    }

    double calculateSalary()
    {
        return fixedSalary;
    }
};

class PartTimeEmployee : public Employee
{
private:
    double hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(double hours, double rate)
    {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{
    FullTimeEmployee fullTime(80000);
    PartTimeEmployee partTime(80, 500);

    cout << "Full-Time Employee Salary: " << fullTime.calculateSalary() << endl;
    cout << "Part-Time Employee Salary: " << partTime.calculateSalary() << endl;

    return 0;
}
