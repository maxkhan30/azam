#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.1416 * radius * radius;
    }
    double perimeter() override {
        return 2 * 3.1416 * radius;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }
    double perimeter() override {
        return 2 * (length + width);
    }
};


class BankAccount {
protected:
    double balance;
    string accountNumber;
public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() = 0;
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double bal) : BankAccount(accNum, bal) {}
    void deposit(double amount) override {
        balance += amount;
    }
    void withdraw(double amount) override {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Not enough balance\n";
    }
    void display() override {
        cout << "Savings Account " << accountNumber << ", Balance: " << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double bal) : BankAccount(accNum, bal) {}
    void deposit(double amount) override {
        balance += amount;
    }
    void withdraw(double amount) override {
        balance -= amount;
    }
    void display() override {
        cout << "Current Account " << accountNumber << ", Balance: " << balance << endl;
    }
};

class Student {
protected:
    string name;
    int rollNo;
public:
    virtual void input() = 0;
    virtual void display() = 0;
    virtual ~Student() {}
};

class Undergraduate : public Student {
    string major;
public:
    void input() override {
        cout << "Enter name: "; getline(cin, name);
        cout << "Enter roll number: "; cin >> rollNo; cin.ignore();
        cout << "Enter major: "; getline(cin, major);
    }
    void display() override {
        cout << "Undergraduate Student\nName: " << name << "\nRoll No: " << rollNo << "\nMajor: " << major << endl;
    }
};

class Graduate : public Student {
    string researchTopic;
public:
    void input() override {
        cout << "Enter name: "; getline(cin, name);
        cout << "Enter roll number: "; cin >> rollNo; cin.ignore();
        cout << "Enter research topic: "; getline(cin, researchTopic);
    }
    void display() override {
        cout << "Graduate Student\nName: " << name << "\nRoll No: " << rollNo << "\nResearch Topic: " << researchTopic << endl;
    }
};

int main() {

    Shape* s1 = new Circle(3);
    Shape* s2 = new Rectangle(4, 5);

    cout << "Circle Area: " << s1->area() << ", Perimeter: " << s1->perimeter() << endl;
    cout << "Rectangle Area: " << s2->area() << ", Perimeter: " << s2->perimeter() << endl;

    delete s1;
    delete s2;


    BankAccount* b1 = new SavingsAccount("S001", 1000);
    BankAccount* b2 = new CurrentAccount("C001", 500);

    b1->deposit(200);
    b1->withdraw(100);
    b2->withdraw(600);

    b1->display();
    b2->display();

    delete b1;
    delete b2;


    Student* st1 = new Undergraduate();
    Student* st2 = new Graduate();

    cout << "\nInput details for Undergraduate student:\n";
    st1->input();

    cout << "\nInput details for Graduate student:\n";
    st2->input();

    cout << "\nDisplaying Student details:\n";
    st1->display();
    st2->display();

    delete st1;
    delete st2;

    return 0;
}
