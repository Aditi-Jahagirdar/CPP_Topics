//...............................................MEMORY ALLOCATION...................................................................

//Program memory: Text segment->Data segment->Heap->Stack->OS Kernel
//Static memory allocation- organized alloc and delloc
//                        - decided at compile time eg. for variables in stack
//Stack  - Once scope of variable or function is complete, the stack is destroyed and memory allocated is freed.
//       - Main function is the base (i.e. when main is executed , program ends,memory freed), and each function call builds stack  if it further calls other function.
//       - This stack height represents memory allocated eg. 8MB max limit, beyond which stack overflows and program crashes.
//Dynamic memory allocation- unorganized alloc and delloc)- memory allocation in heap (treated as resource, extra memory to use)
//                         - Programmer ensures memory allocation and that it is freed propely and there are no memory leaks. RAII principle(resource allocation is initialization)
//                         - Memory leak occurs when memory still belongs to a program and cannot be used for other purpose.Eventually heap memory will be full(limit reached).
//                         - Memory allocation- pointer variable is created that points to heap memory and , allocates using new. For array, new int[]. For value, new int(5)
//                         - Memory Deallocation - using delete keyword after memory is used. For array delete []arrName, For variable delete varName.
//ARROW operator (->) - is used to access class/struct/union varibles using pointers.
//                    - also used in map STL to access its key and value using iterator(pointer) traversing through map eg. iteratorName->first , iteratorName->second .
//SMART Pointer - used for automatic memory management to avoid memory leaks. Include <memory> class.
//UNIQUE Pointer - based on RAII principle. Memory is freed when scope is complete. It cannot be copied, Copy constructor is deleted.
//SHARED Pointer - based on Resource counter. When pointer is copied , resource count is incremented by one and with scope end of each pointer it is decremented by one.
//               - Memory is freed when resource count is 0 i.e. all pointer's scope is completed.
//WEAK Pointer - is to track if shared pointer is alive or destroyed. It is created by assigning shared pointer but resource count is not incremented.

#include <iostream>
#include <memory>
using namespace std;

/*
void printRes(int res)
{
    cout<<res<<endl;
}

void add(int a , int b)
{
    int result = a+b;
    printRes(result);
}

int main()
{
    add(2,5);  //forms a stack : main->add->printRes where res,a,b are local variables that gets destroyed(scope completes) once its respective function is executed and stack is removed.
  
    printRes(50); //when above 'add' function is executed & 'add' stack destroyed , we are again at main stack, 'printRes' function is called such that stack created is main->printRes
    
    return 0;
}
*/

/*
class A
{
    public:
    int x =5;

};

int main()
{

    int N;   //size of array
    std::cin>>N;

    int* arr = new int [N];   //allocating memory on heap using pointer and new keyword


    for (int i=0 ; i<N; i++)
    {
        arr[i] = i+1;
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    delete [] arr; //freeing memory after use , with delete keyword. 


A* obj = new A ();
int res = obj->x;   //accessing pointer variable obj of A type

cout<<res<<endl;

    

    return 0;
}
*/

class Entity
{


};

int main()
{
    {
        std::unique_ptr<Entity> p1 = std::make_unique <Entity> ();
    }
    

    

    return 0;
}