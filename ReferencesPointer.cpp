//.........................................REFERENCE & POINTER.......................................................................

//Reference variable is alias or nickname of existing variable.It has to be initiatized at the time of creation & reference cannot be changed.
//Pointer - is a address variable , it stores address of other variable.By dereferencing(*) the pointer , we get the value at that memory address.
//        - pointer can change what it points to.
//        - On most 32-bit systems, the size of a pointer is typically 4 bytes, while on most 64-bit systems, the size of a pointer is 8 bytes.
//Constant Pointers - 1. const after star* :  cannot change what it points to
//                    2.const before star* : of read-only type, it cannot be assigned value directly.
//                    3.const after and before star* : it can change what it points to, nor cannot be assigned a value.
//Array as pointer- name of array is a pointer and holds address of first element of array. By dereferencing it, we get the value.
//                  - *arr is same as arr[0] and *(arr+1) is same as arr[1]
//NULL pointer - points to nowhere (zero). Dereferencing it can give runtime error.
//Invalid pointer - when pointer is uninitialized or stores invalid address.Dereferencing causes runtime error or accessing random values.
//VOID pointer - points to address that does not holds value of specific data type. Its cannot be accessed(dereferenced) directly.
//             -It has to be casted to specific type during derencing to access its value.
//             -It cannot be directly dereferenced since it is generic type. First, cast void pointer to pointer of assigned data type.Then dereference this pointer.
//FUNCTION pointer- for passing function as an argument in another function. void func2 (int x, int y, (*func1)(arg1,arg2)) and to access , directly use func2(2,3,func1)
//                 -here func1 is function pointer with 2 parameters arg1 and arg2


#include <iostream>
using namespace std;

void printSum(int x, int y,int (*add)(int,int))
{
    int result = (*add)(x,y);
    cout<<result<<endl;
}

int add(int a, int b)
{
    return a+b;
}

int main()
{
    /*
    int x =10;
    int& refX = x;    //refX is reference variable of variable x. int& means the type of variable it is referencing to.
    cout<<refX<<endl;   //10
    refX = 20;        
    cout<<x<<endl;     //20

    int b=30;
    refX = b;    //refX is only assigned the value of b , its reference is not changed
    cout<<"refX:" <<refX<<"x:"<<x<<endl;  //30
    refX = 40;
    cout<<b<<endl;     //30      b doesn't change to refX(40) becasue refX still references a

    cout<<&refX<<endl;  //address of refX and address of x is same because refX is nickname of same variable(same memory address)
    cout<<&x<<endl;
    */

    /*
    int num = 5;
    int* ptr = &num; //int* means the type of variable it is pointing to.(num is int type)

    cout<<ptr<<endl;   
    cout<<&num<<endl;  
    cout<<*ptr<<endl;  //5

    *ptr =10;
    cout<<num<<endl;  //10

    int newNum = 2;
    ptr = &newNum;     //pointer can change what it points to
    cout<<ptr<<endl;   //now holds new  address of newNum
    cout<<&newNum<<endl;  
    cout<<*ptr<<endl;  //2
    */ 

   /* 
   int y = 4;
   int* const p1 = &y; 
   int z= 9;
   //p1 = &z; //p1 is constant pointer (const after star*) , cannot change what it points to

   const int* p2 = &y;   //p2 holds value 4
   p2 = &z;  //p2 holds value 9

   //*p2 = 5;  //p2 is const pointer (const before star *) of read-only type, it cannot be assigned value directly.

   const int* const p3 = &y;
   //p3 = &z;  //p3 cannot change what it points to 
   //*p3 = 11; //p3 cannot be assigned a value.
   */

    /*
    int arr[5] = {1,2,3,4,5};
    cout<<arr<<endl;
    cout<<*arr<<endl;  //1

    cout<<arr+1<<endl;
    cout<<*(arr+1)<<endl; //2

    int* arrPtr = &arr[5] ;
    cout<<*arrPtr<<endl; //1 but arrPtr will hold different address than first element of arr.
    cout<<*arrPtr+1<<endl; //2
    */

   /*
    int* ptrN = NULL;  //or nullptr or 0
    cout<<ptrN<<endl;   //0x0 empty memory address 
    cout<<*ptrN<<endl;  //segmentation fault ,as there's no value to extract.
    */

   /*
    char test = 'a';
    void* ptrV = &test ; //points to a value that has no type. To use its value , it has to be casted with a type while dereferencing.

    //cout<< *ptrV<< endl;  //void pointer cannot be dereferenced directly
    cout<<(char*)ptrV<<endl;
    cout<<*(int*)ptrV<<endl;
    */

    printSum(2,3,add);



    return 0;
}