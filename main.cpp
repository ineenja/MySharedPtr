#include "mysharedptr/mysharedptr.h"
#include <iostream>

int main()
{
    //std::shared_ptr<int> ptr {std::make_shared<int>(1)};
    int *a;

    for (int i = 0; i != 1; i++){
        MySharedPtr<int> ptr1(new int(1));

        a = ptr1.getPtr();

        std::cout << ptr1.getPtr() << '\n';
        std::cout << ptr1.getPtrObj() << '\n';
        std::cout << *a << '\n' << '\n';

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> ptr2 = ptr1;
            std::cout << ptr2.getPtr() << '\n';
            std::cout << ptr2.getPtrObj() << '\n';
            std::cout << *a << '\n' << '\n';
        }

        std::cout << ptr1.getPtr() << '\n';
        std::cout << ptr1.getPtrObj() << '\n';
        std::cout << *a << '\n' << '\n';
    }

    std::cout << *a << '\n';

    std::cout << "test" << '\n';



    //MySharedPtr<int> myptr {makeShared<int>(2)};
    return 1;
}
