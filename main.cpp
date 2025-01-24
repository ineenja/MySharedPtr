#include "mysharedptr/mysharedptr.h"
#include <iostream>

int main()
{
//    std::shared_ptr<int> ptr {std::make_shared<int>(1)};

    MySharedPtr<int> ptr1(new int(2));

    MySharedPtr<int> ptr2 = ptr1;

    ptr1.~MySharedPtr();

    int * check = ptr1.getPtr();
    std::cout << *check << '\n' << '\n';

    ptr2.~MySharedPtr();

    std::cout << *check << '\n' << '\n';

    std::cout << "test" << '\n';



    //MySharedPtr<int> myptr {makeShared<int>(2)};
    return 1;
}
