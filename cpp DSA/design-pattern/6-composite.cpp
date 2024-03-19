#include <iostream>
#include <string>
#include <vector>

// Component interface
class Employee {
public:
    virtual void showDetails() const = 0;
    virtual ~Employee() {}
};

// Leaf class representing individual employees
class IndividualEmployee : public Employee {
private:
    std::string name;
    std::string position;

public:
    IndividualEmployee(const std::string& name, const std::string& position)
        : name(name), position(position) {}

    void showDetails() const override {
        std::cout << "Name: " << name << ", Position: " << position << std::endl;
    }
};

// Composite class representing departments
class Department : public Employee {
private:
    std::string name;
    std::vector<Employee*> employees;

public:
    Department(const std::string& name) : name(name) {}

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void showDetails() const override {
        std::cout << "Department: " << name << std::endl;
        for (const auto& employee : employees) {
            employee->showDetails();
        }
    }
};

int main() {
    // Individual employees
    Employee* emp1 = new IndividualEmployee("John Doe", "Manager");
    Employee* emp2 = new IndividualEmployee("Jane Smith", "Engineer");

    // Department with employees
    Department* engineering = new Department("Engineering");
    engineering->addEmployee(emp1);
    engineering->addEmployee(emp2);

    // Another individual employee
    Employee* emp3 = new IndividualEmployee("Alice Johnson", "HR Manager");

    // Top-level department
    Department* company = new Department("Company");
    company->addEmployee(engineering);
    company->addEmployee(emp3);

    // Show company structure
    company->showDetails();

    // Cleanup
    delete emp1;
    delete emp2;
    delete emp3;
    delete engineering;
    delete company;

    return 0;
}
