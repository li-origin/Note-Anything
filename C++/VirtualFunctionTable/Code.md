### Code
---
```
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "string.h"
#include <cstdlib>
#include <functional>

using namespace std;

class base
{
public:
    explicit base(){
        cout << "base construct function!!" << endl;
    }

    virtual void function_1(){ cout << "base : virtual function_1 call !!" << endl; }
    virtual void function_2(){ cout << "base : virtual function_2 call !!" << endl; }
    virtual void function_3(){ cout << "base : virtual function_3 call !!" << endl; }

    virtual ~base(){}

// private:
    int x;
};

class derive : public base
{
public:
    explicit derive(){ cout << "Derive construct function!!" << endl; }
    virtual void function_2(){ cout << "Derive : virtual function_2 call !!" << endl; }
    ~derive(){}
};


// int main()
// {
//     typedef void (*funcType)();
//     base *basePointer = new base;
    
//     cout << "base pointer: " << basePointer << endl;
//     cout << "the pointer of member variable x : " << &basePointer->x << endl;
//     long* temp = (long*)(basePointer);
//     long* vptr = (long*)(*temp);

//     for(int i=0; i < 3; i++)
//     {
//         cout << "virtual function table ! : " << vptr[i] << endl;
//     }

//     funcType func1 = (funcType)vptr[0];
//     funcType func2 = (funcType)vptr[1];
//     funcType func3 = (funcType)vptr[2];
//     func1(); func2(); func3();
//     //----------------------derive------------------------
//     derive *derivePointer = new derive;
    
//     cout << "base pointer: " << derivePointer << endl;
//     long* temp1 = (long*)(derivePointer);
//     long* vptr1 = (long*)(*temp1);

//     for(int i=0; i < 3; i++)
//     {
//         cout << "virtual function table ! : " << vptr1[i] << endl;
//     }

//     funcType func1D = (funcType)vptr1[0];
//     funcType func2D = (funcType)vptr1[1];
//     funcType func3D = (funcType)vptr1[2];
//     func1D(); func2D(); func3D();

//     delete basePointer;
// }


int main()
{
    typedef void (*funcType)();

    base *basePointer = new base;
    
    cout << "base pointer: " << basePointer << endl;
    cout << "the pointer of member variable x : " << &basePointer->x << endl;
    long* temp = (long*)(basePointer);
    long* vptr = (long*)(*temp);

    for(int i=0; i < 3; i++)
    {
        cout << "virtual function table ! : " << vptr[i] << endl;
    }

    funcType func1 = (funcType)vptr[0];
    funcType func2 = (funcType)vptr[1];
    funcType func3 = (funcType)vptr[2];
    func1(); func2(); func3();

    cout << endl << "-------------------------------" << endl;
    derive *derivePointer = new derive;
    cout << "derive pointer: " << derivePointer << endl; 
    base *basePointerTest = derivePointer;
    cout << "base pointer: " << basePointerTest << endl;
    derivePointer->function_2();
    basePointerTest->function_2();
    cout << "base->derive Function: -------"  << endl;
    cout << endl << "-------------------------------" << endl;

    long* tempD = (long*)(derivePointer);
    long* vptrD = (long*)(*tempD);

    for(int i=0; i < 3; i++)
    {
        cout << "virtual function table ! : " << vptrD[i] << endl;
    }

    cout << endl << "-------------------------------" << endl;
    funcType func1D = (funcType)vptrD[0];
    funcType func2D = (funcType)vptrD[1];
    funcType func3D = (funcType)vptrD[2];
    func1D(); func2D(); func3D();

    cout << endl << "-------------------------------" << endl;
    long* temp1 = (long*)(basePointerTest);
    long* vptr1 = (long*)(*temp1);

    for(int i=0; i < 3; i++)
    {
        cout << "virtual function table ! : " << vptr1[i] << endl;
    }

    cout << endl << "-------------------------------" << endl;
    funcType func1B = (funcType)vptr1[0];
    funcType func2B = (funcType)vptr1[1];
    funcType func3B = (funcType)vptr1[2];
    func1B(); func2B(); func3B();

    delete basePointer;
}
```
---
### console out
---
```
base construct function!!
base pointer: 0x601000000000
the pointer of member variable x : 0x601000000008
virtual function table ! : 94360034432128
virtual function table ! : 94360034432184
virtual function table ! : 94360034432240
base : virtual function_1 call !!
base : virtual function_2 call !!
base : virtual function_3 call !!

-------------------------------
base construct function!!
Derive construct function!!
derive pointer: 0x601000000010
base pointer: 0x601000000010
Derive : virtual function_2 call !!
Derive : virtual function_2 call !!
base->derive Function: -------

-------------------------------
virtual function table ! : 94360034432128
virtual function table ! : 94360034432480
virtual function table ! : 94360034432240

-------------------------------
base : virtual function_1 call !!
Derive : virtual function_2 call !!
base : virtual function_3 call !!

-------------------------------
virtual function table ! : 94360034432128
virtual function table ! : 94360034432480
virtual function table ! : 94360034432240

-------------------------------
base : virtual function_1 call !!
Derive : virtual function_2 call !!
base : virtual function_3 call !!
```
