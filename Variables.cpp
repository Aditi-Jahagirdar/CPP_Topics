
//........................................VARIABLES........................................................................
//Variable  - is a name given to a piece of data.
//Local Variable - Scope: within parenthesis, lifetime: within parenthesis
//Global Variable - Scope:anywhere in program, not part of function or class  , lifetime: program start to program end
//Static Variable - Outside class - 1.Globally- Scope-within that translation unit , lifetime-program start to program end 
//                                  2.Inside a function - within braces, lifetime: program start to program end
//                  Inside class - It is common variable for all objects of class.It is created at the time of class creation and does not require object creation, so memory has to be allocated separately even before any objects are created.
//                                 1.Outside function - Initialize outside class for separate memory allocation of static variable which is independent of object creation.
//                                                      Scope- within class, lifetime: program start to program end
//                                 2.Inside function - Initialized within function, not required outside class because its Scope- within function (and not for class),lifetime: program start to program end
//                                   Static variable can directly be accessed by  "class name :: "
//Member Variables/Attributes g++- are the variables defined inside a class.
//Constant variables - whose value cannot be changed
//                  - const variables inside class :
//Variable declaration and definition both are same eg. int x. 
//"Extern" keyword is used for pure declaration of variables.
//One definition rule - a class can be defined only once in one translation unit. A variable or function can be define only once throughout the program.
//                    - Header guard are used to avoid copies of header files and maintain 1-definition rule. #pragma once - at beginning of header file OR #ifndef variables_h #define variables_h  at beginning of header file and #endif at the end of header file
//"auto" keyword automatically deduces type of variable based on assigned value.




#include <iostream>
#include "variables.h"        //int x=10 , y=20;   //x,y are global variables
#include "var.h"    //will cause redifinition of class A without header guard
using namespace std;

static int s =10;
extern int x;  //pure declaration of x which will be declared and defined already in other file.

int add (int& a , int& b)
{
    return a+b*s;   //a, b are local variables 
}

void empID()
{
    static int count = 1;
    count++;
    cout<<count<<endl;
}

class Test
{
    public:
        static int grade;
        char section = 'A';
        int numOfStudents = 40 ;
        const int points = 100;
    public:
        void setGrade (int x)
        {
            grade = x;
        }

        void getGrade()
        {
            cout<<"grade:"<<grade<<"points:"<<points <<endl;
        }

        void printRollNo()
        {
            static int rollNo = 21;
            rollNo++;
            cout<<rollNo<<endl;
        }
        
};

int Test :: grade = 10;

int main()
{
    x=20; //This is the problem with global variables, it can be changed anywhere making tracebility a challenge.
    int z = add(x,y);
    cout<<z+s<<endl;
    const int c_num = 8;  //const variable
    //c_num = 9;

    empID();
    empID();
    empID();
    empID();

    Test obj;
    obj.setGrade(10);
    obj.getGrade();
    obj.printRollNo();
    obj.printRollNo();
    obj.printRollNo();
    obj.setGrade(20);
    cout<<Test::grade<<endl;  //accessing static variable directly

     //auto varAuto = 2.5f;
     auto varAuto = 2.5;
     cout<<typeid(varAuto).name()<<endl;

    return 0;
}

