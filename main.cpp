#include <iostream>
using namespace std;

// abstract class
// Contract
class AbstractEmployee{
    virtual void AskforPromotion() = 0; //abstract function
};

class Employee:AbstractEmployee{        // -> Employee class inherits AbstractEmployee class by Employee:AbstractEmployee
private: // accessible within this class
//    string Name;
    string Company;
    int Age;

protected:  // accessible to all of its subclasses
    string Name;

public: // accessible to global

    void setName(string name){// -> setter
        Name = name;
    }
    string getName(){// -> getter
        return Name;
    }
    void setCompany(string company){// -> setter
        Company = company;
    }
    string getCompany(){// -> getter
        return Company;
    }
    void setAge(int age){// -> setter
        Age = age;
    }
    int getAge(){// -> getter
        return Age;
    }

    void intro(){
        cout << "Name - " << Name << "\n";
        cout << "Company - " << Company << "\n";
        cout << "Age - " << Age << "\n";
    }

    // Constructor
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }


    void AskforPromotion(){
        if(Age > 22){
            cout << Name << " got promoted!" << "\n";
        }
        else cout << Name << ", sorry NO promotion for you!" << "\n";
    }
    virtual void Work(){
        cout << Name << " is preparing task and doing some other stuff" << "\n";
    }
};

// Inheritance
// subclass of employee
// by default developer class will be private and thus its object will not get access to its parents class method
class Developer: public Employee{
public:
    string FavProgrammingLang;
    // constructor
    Developer(string name, string company, int age, string favprogramminglang) : Employee(name, company, age){
        FavProgrammingLang = favprogramminglang;
    }
    void  FixBug(){
//      cout << getName() << " fixed bug using " << FavProgrammingLang << "\n";
        cout << Name << " fixed bug using " << FavProgrammingLang << "\n";
    }
    void Work(){
        cout << Name << " is writing " <<  FavProgrammingLang << " code" << "\n";
    }
};

class Teacher : public Employee{
public:
    string Subject;
    void Preparelesson(){
        cout << Name  << " is preparing " << Subject << " lesson" << "\n";
    }
    // Constructor
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age){
        Subject = subject;
    }

    void Work(){
        cout << Name << " is preparing " <<  Subject << " lesson" << "\n";
    }
};

// Polymorphism - The most common use of polymorphism is when a parent
//                class reference is used to refer to a child class object!

int main() {

//    object1 -> emp1 from class Employee
//    Employee emp1 = Employee("Priyanshu","Coding_Py",20);
//    emp1.intro();
//    object2 -> emp2 from class Employee
//    Employee emp2 = Employee("Deepanshu", "Amazon" , 24);
//    emp2.intro();
//
//    emp1.setAge(21);
//    cout << emp1.getName() << " is " << emp1.getAge() << " years old";
//
//    emp1.AskforPromotion();
//    emp2.AskforPromotion();
//
    Developer d = Developer("Priyanshu","Coding_Py",20,"C++");
//    d.FixBug();
//    d.AskforPromotion();

    Teacher t = Teacher("Pinchu", "Coding School", 20, "DSA");
//    d.Work();
//    t.Work();
    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
    return 0;
}
