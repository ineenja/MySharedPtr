#include "mysharedptr/mysharedptr.h"
#include <iostream>

int main()
{
    //std::shared_ptr<int> ptr {std::make_shared<int>(1)};
    int *a;

    int b = 1;

    for (int i = 0; i != 1; i++){
        MySharedPtr<int> ptr1(new int(b));

        a = ptr1.getPtr();

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> ptr2 = ptr1;
        }

    }

    MySharedPtr<int> ptr {makeShared<int>(2)};
    std::cout << ptr.getPtr() << '\n';
    std::cout << ptr.getPtrObj() << '\n';
    std::cout << ptr.getPtrCounter() << '\n' << '\n';

    std::cout << "endof" << '\n';



    //MySharedPtr<int> myptr {makeShared<int>(2)};
    return 1;
}
