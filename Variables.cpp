//Variable  - is a name given to a piece of data.
//Local Variable - Scope: within parenthesis, lifetime: within parenthesis
//Global Variable - Scope:anywhere in program, not part of function or class  , lifetime: program start to program end
//Static Variable - Outside class - 1.Globally- Scope-within that translation unit , lifetime-program start to program end 
//                                  2.Inside a function - within braces, lifetime: program start to program end
//                  Inside class - It is common variable for all objects of class.
//                                 1.Outside function - Initialize outside class. Scope- within class, lifetime: program start to program end
//                                 2.Inside function - Initialized within function, not required outside class.Scope- within function,lifetime: program start to program end
//                                   Static variable can directly be accessed by  "class name :: "
//Member Variables/Attributes - are the variables defined inside a class.
//Constant variables - whose value cannot be changed

#include <iostream>
#include "variables.h"
using namespace std;

static int s =10;

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
    public:
        void setGrade (int x)
        {
            grade = x;
        }

        void getGrade()
        {
            cout<<grade<<endl;
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

    return 0;
}

