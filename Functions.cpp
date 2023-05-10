//............................................FUNCTIONS.............................................................................................................

//MAIN function - special function that returns 0 when program ended successfully.
//              -It is good practice to write return 0 explicitly.
//               Although, compiler can assume this return statement implictly(without writing) if program ends successfully.

//Function - It takes input, processes it/operates on it and returns a output.
//         -Function declaration - informs compiler that function exists and linker will search for the definition(if in different cpp files).
//                               - Consists of return type, function name and parameters.It can return a data type or void(no type, eg only prints to console)
//         -Function definition-contains body of function.
//         -Function call- used to invoke the function.It consists of function name and arguments.
//         -STATIC function OUTSIDE CLASS can access static(global scope) and other global,local variables.Non-static function can also access static variables under global scope.
//         -Methods-function inside class.STATIC method INSIDE CLASS can access only static variables defined in that class or static variables in global scope.
//Pass by value - copy of arguments/original variable are created in function
//Pass by reference- reference of original variable created in function, no copies, modifies original.Syntatic sugar to pointers.
//Pass by pointer - pointer to original variable createdin function, address of original variable passed in argument.No copies, modifies original
//Return by value - Copy of returned value is stored in a variable.
//Return by reference- returns a reference to function output variable. Hence, returned variable should be global/static/created on heap .
//                  -because variables in function scope will be destroyed after function is executed and its reference value cannot be
//Return by pointer- returns a pointer. Another pointer is created to hold the returned pointer.By dereferencing this new pointer, we access the value of function output.
//                 -Since pointer is to be returned, only address of heap allocated, static or global variable is processed in function.As local variable's scope ends with function execution.
//INLINE function - for smaller functions where execution time is lesser than overhead, compiler is requested to make inline function. 
//                - Code of inline function gets inserted/copied at place of function call.
//                - For complex functions (loops,static variables,recursive,switch,return type except void), compiler may reject the inline request.
//                - Inside class, functions are implicitly inline.Good practice-declare without inline keyword inside class. Define with inline outside class.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
static int sNum = 2;


class Func
{
    private:
        int x;
        string name;
        static int y;
    public:
        void setX(int a)   //methods 
        {
            x=a;
            cout<<x<<endl;

        }
        static void setY()   //static method 
        {
            y++;
            cout<<y<<endl;
            cout<<sNum<<endl;
        }

        string getName()
        {
            return name;
        }

};
int Func::y=5;

int add(int a, int b);   //function declaration
int& subtract(int& a, int& b);
void square(int* k);
int* incrementNum();
void printVect(vector<int>& v);

static void mult(int a, int b); //static function outside class
int result; //global variable for return by reference
inline void getName(){cout<<"aditi"<<endl;}   //inline function
int main()
{
    /* static variable in non-static function
    int x=2, y=5;
    int z;
    z = add(x,y);   //function call 
    cout<<z<<endl;  //21
    
    z = add(x,y);   //function call
    cout<<z<<endl;  //28

    z = add(x,y);   //function call
    cout<<z<<endl;  //35
    */

    /* static variable in static function
    mult(3,2);  //9  , sNum=3
    mult(3,2);  //10 ,sNum=4
    mult(3,2);  //11 , sNum=5
    */

   /*
    Func obj;
    obj.setX(10);  //10
    obj.setY();    //6
    */

   /*
    int x=5, y=2;
    int& subt = subtract(x,y);   
    cout<<subt<<endl;  //3
   */
   /*
   int number = 3;
   square(&number);
    */

   /*
   int* retptr = incrementNum();
   cout<<*retptr<<endl; //501
    */ 

   //getName();  //code of this function gets inserted here 

    std::vector<int> myvector = {10,20,30};
    myvector.push_back(10);

   printVect(myvector);

    return 0;
}

int add(int a, int b)   //function definition //arguments are pass by value (copy created)
{
    sNum++;
    return (a+b)*sNum ;  //return by value
}

static void mult(int a, int b)
{
    sNum++;
    cout<<(a*b)+sNum<<endl;
}
int& subtract(int& a, int& b) //pass by reference   //Return by reference
{
    result = a-b;
    return result;
}

void square(int* k) //pass by pointer
{
    int res;
    res = (*k)*(*k);
    cout<<res<<endl;
}

int* incrementNum()
{
    int* p =  new int (500);
    (*p)++;
    return p;
}

void printVect(vector<int>& v)
{
    for_each(v.begin(), v.end(), [](int i){cout<<i<<" ";});
    cout<<endl;
}

