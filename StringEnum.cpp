//.......................................................STRINGS , ENUMS...................................................................
//String - is array of character. It can be created by 3 ways:
//      - 1. char str[] = "hello" : String is created in stack and can be changed.
//                              Count of string terminates at null character('\0') "hel\0lo" -> hel.
//      - 2. const char* str= "hello" : string is created in data segment's read only part & it is also called STRING LITERALS. 
//                             reads till end of string, thus address issue of terminating at null character.
//                      Read-only is constant part so string created cannot be changed and const pointer can give compiler error.
//      - 3. string str = "hello" (from string class, by including <string> library). 
//                          Methods from string class can be used for string manipulation.

//ENUM - It is a special class representing group of contants.
//      It is a user defined data type which assigns integer value to its members/custom identifiers/enumerators.
//      Objects of enum data type can only take values that are defined as enum members/custom identifiers/enumerators.
// enum class - for type safety , scopes the value assigned to object of enum type
//Although enum implicitly assigns integer values to its enumerators making it consume int size memory , that can be changed.
//       //To specificy size of enum object; enum class level : char{ low =1, medium, high}; --> 1byte


#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    // char str1[] = "hello1";
    // std::cout<<str1<<std::endl;  //hello1

    // const char* str2 = "hello2";
    //std::cout<<str2<<std::endl;  //hello2

    // std::cout<<*str2<<std::endl;  //h
    //std::puts(str2); //hello2

    // for (int i=0 ; str2[i] != '\0' ;i++)
    // {
    //     std::cout<<str2[i];   
    // }                        //hello2
    // std::cout<<std::endl;

    // string str3 = "hello3";
    // std::cout<<str3<<std::endl;  

    // enum level
    // {
    //     low =1,
    //     medium,
    //     high,
    // };

    // level var1 = low;
    // std::cout<<var1<<std::endl;

    // level var2 = medium;
    // std::cout<<var2<<std::endl;

    // level var3 = high;
    // std::cout<<var3<<std::endl;

    //enum class - for type safety , scopes the value assigned to object of enum type
    // enum class level
    // {
    //     low =1,
    //     medium,
    //     high,
    // };

    // level cvar = level::low;

    //To specificy size of enum object;
    // enum class level : char{ low =1, medium, high};
    // level svar = level::medium ;  // svar will be of 1 byte

    char* name1 = new char[100];  
    char* name2 = new char[100]; 

   // std::cin.get(name1, 100, '\n');  //defining delimiter character as size of array or newline which ever come fist .
   // By default cin has space ' ' and '\n' as delimiter character. i.e. it processes input until these characters.

     std::cin>>name1>>name2;
   
    std::cout<<name1<<name2<<std::endl;


    return 0;
}