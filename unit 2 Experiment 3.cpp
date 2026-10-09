#include <iostream>
#include <string>
using namespace std;

// Static member example
class StaticExample {
private:
    static int count;
    int id;

public:
    StaticExample() {
        count++;
        id = count;
    }

    static void showCount() {
        cout << "Total objects created: "
             << count << endl;
    }

    void display() const {
        cout << "Object ID: " << id << endl;
    }
};

int StaticExample::count = 0;

// Forward declarations
class ClassA;
class ClassB;

// Class A
class ClassA {
private:
    int valueA;

public:
    ClassA(int v) : valueA(v) {}

    friend void compareValues(ClassA &a, ClassB &b);
};

// Class B
class ClassB {
private:
    int valueB;

public:
    ClassB(int v) : valueB(v) {}

    friend void compareValues(ClassA &a, ClassB &b);
};

// Friend function
void compareValues(ClassA &a, ClassB &b) {
    cout << "Value in ClassA: " << a.valueA << endl;
    cout << "Value in ClassB: " << b.valueB << endl;

    if (a.valueA > b.valueB)
        cout << "ClassA value is greater" << endl;
    else if (a.valueA < b.valueB)
        cout << "ClassB value is greater" << endl;
    else
        cout << "Both values are equal" << endl;
}

// Friend class example
class SecretData {
private:
    string password;
    int secretNumber;

public:
    SecretData(string p, int n)
        : password(p), secretNumber(n) {}

    friend class FriendClassExample;
};

class FriendClassExample {
public:
    void displaySecret(SecretData &s) {
        cout << "Password: " << s.password << endl;
        cout << "Secret Number: "
             << s.secretNumber << endl;
    }
};

int main() {
    cout << "=== Static Members ===" << endl;

    StaticExample s1, s2, s3;
    StaticExample::showCount();

    cout << "\n=== Friend Function ===" << endl;

    ClassA a(50);
    ClassB b(30);

    compareValues(a, b);

    cout << "\n=== Friend Class ===" << endl;

    SecretData secret("myPassword123", 999);
    FriendClassExample friendObj;

    friendObj.displaySecret(secret);

    return 0;
}