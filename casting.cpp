//.......................................................CASTING............................................................
//Type of conversions: 1.Implicit 2.Explicit
//Implicit conversion - automatically performed when value is copied to compatible type.
//                   -eg. char->int , int->float , float->double promotion
//                   - bool: false->0 , Pointer: nullptr->0 , all other are 1
//                   - Derived -> base class pointer (Pointer upcast)
//                   - nullptr->any pointer , any pointer->void pointer
//Explicit conversion - explicit keyword in constructors restricts the usage to that class object
//                  - eg.a function defined for argument of class with "explicit constructor" cannot take other types as argument.
//                  - Explicit constructors cannot be called with assignment operator eg. B objB = objA; is not allowed
//Type Casting -  is used to treat/interpret one type of data as another type.There are 4 specific casting operators:
//        - 1.Static casting - conversion between pointers of related classes.
//                          - No checks , allows both upcast and downcast.
//                          - inavalid conversions can give runtime errors when pointers are dereferenced                   
//        - 2.Dynamic casting - Only for pointers and references conversions in polymorphc classws.
//                 -checks is conversion is valid at runtime and only then it converts otherwise returns nullptr.
//                 -RTTI If type of destination pointer and type of object is same , valid conversion(downcast, base->derived is also allowed)
//        - 3.Const casting - add/remove constant to object pointed by pointer.
//                          -To treat a variable as constant or to remove constant from a const variable.
//        - 4.Reinterpret casting - converts pointer of one type to other type of unrelated classes.
//                               - No checks for valid conversion. Value of pointer is copied.


#include <iostream>
#include <typeinfo>

int main()
{
    // int x =4;
    // float y = x;  //implicit conversion of int to float
 
    // std::cout<<y<<std::endl;   //4
    // std::cout<<typeid(y).name()<<std::endl;  //f 

    
    // int* p1 = nullptr;  //implicit conversion of nullptr to int*
    // char* p2 = nullptr;  //implicit conversion of nullptr to char*

    // int x = 10;
    // void* ptr = &x;

    // int* pti = static_cast<int*>(ptr);
    // std::cout<< *pti <<std::endl;  //10

    // class A       //base class
    // {
    //     int x;
    // };
    // class B : public A    //derived class
    // {
    //     int y;
    //     int z;
    // };
   // Pointer upcast : Derived to base - implicit possible
    // A oBase;
    // B oDer;
    // oBase = oDer; //oDer is implicitly converted to oBase. Since oDer has 12bytes,oBase has 4 bytes object slicing will happen and y,z( 8bytes data )gets sliced off.

    // oDer = oBase; //implicit downcast not allowed

   //A objA;
  // B* objB = new B ();   //Derived pointer can contain derived object
   //B* objB = new A (); //Derived pointer cannot contain base object  , base to derived implicit conversion not allowed

   //B objB1;
  // A* objA1 = new A ();
   //A* objA1 = new B ();   //derived to base implicit conversion allowed

    // class Base
    // {
    //     public:
    //     int x;
    //     virtual void getX(){std::cout<<x<<std::endl;}
    // };
    // class Derived : public Base
    // {
    //     protected:
    //     int y, z;
    // };
    
    //Derived* d = new Derived () ;
    //Base* b = static_cast<Base*> (d); //convert Derived* d to Base* b. Pointer upcast allowed, no runtime error expected

    //Base* b = new Base ();
    //Derived* d = static_cast<Derived*> (b);  //convert Base* b to Derived* b. Pointer downcast allowed,runtime error/ unexpected results
    
    //Base* b = new Derived ();
    //Derived* d = static_cast<Derived*> (b);  //downcast but destination pointer and object type is same. 


    // Derived* d = new Derived ();
    // Base* b = dynamic_cast<Base*> (d);  //derived to base - pointer upcast allowed
    // std::cout<<sizeof(b)<<std::endl;  //8bytes - size of pointer for 62 bit system

    // Base* b = new Base ();
    // Derived* d = dynamic_cast<Derived*> (b);  //base to derived downcast should return nullptr;
    // std::cout<<d<<std::endl;   //0x0 

    // Base* b = new Derived ();
    // Derived* d = dynamic_cast<Derived*> (b);  //base to derived downcast but destination pointer and object data type same, conversion valid
    // std::cout<<d<<std::endl;   //some memory address 

    
    // class one
    // {
    //     public:
    //     char c ;
    // };
    // class two
    // {
    //     public:
    //     int k;
    // };

    // one* obj1 = new one ();
    // two* obj2 = reinterpret_cast<two*> (obj1);  //convert one type obj1 (1byte) to two type obj2 (4byte)
    // std::cout<<sizeof(*obj1)<<std::endl;  //1
    // std::cout<<sizeof(*obj2)<<std::endl;  //4  //sizes are different, it indicates that the reinterpretation has affected the size

    const char* name = "Hope";
    char* p = const_cast<char*> (name);

    //std::cout<<p<<std::endl;

    const char* p1 = const_cast<const char*> (p);
    std::cout<<p1<<std::endl;  

   // std::cout<<typeid(p1).name()<<std::endl;  //Pkc
   std::cout<<typeid(p).name()<<std::endl; //Pc

    return 0;
}
