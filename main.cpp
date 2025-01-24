#include "mysharedptr/mysharedptr.h"
#include <iostream>

int main()
{
    std::shared_ptr<int> ptr {std::make_shared<int>(1)};

    MySharedPtr<int> ptr1(new int(2));
    std::cout << ptr1.getPtr() << '\n';
    std::cout << ptr1.getPtrObj() << '\n';
    std::cout << ptr1.getPtrCounter() << '\n';

    MySharedPtr<int> ptr2 = ptr1;
    std::cout << ptr2.getPtr() << '\n';
    std::cout << ptr2.getPtrObj() << '\n';
    std::cout << ptr2.getPtrCounter() << '\n';

    ptr1.~MySharedPtr();

    std::cout << ptr2.getPtr() << '\n';
    std::cout << ptr2.getPtrObj() << '\n';
    std::cout << ptr2.getPtrCounter() << '\n';

    std::cout << "test" << '\n';

    ptr2.~MySharedPtr();

    //MySharedPtr<int> myptr {makeShared<int>(2)};

    return 1;
}
