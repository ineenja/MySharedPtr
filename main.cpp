#include "mysharedptr/mysharedptr.h"
#include <iostream>

int main()
{
    //std::shared_ptr<int> ptr {std::make_shared<int>(1)};

    int b = 1;
    int *a;
    int *c;

    for (int i = 0; i != 1; i++){
//        MySharedPtr<int> ptr1(makeShared<int>(b));
//        std::shared_ptr<int> ptr {std::make_shared<int>(b)};
        MySharedPtr<int> ptr1(new int(b));
        std::shared_ptr<int> ptr {new int(b)};

        a = ptr1.getPtr();
        c = ptr.get();

        MySharedPtr<int> ptrt(new int(2));

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> ptr2 = ptr1;
            std::shared_ptr<int> ptr3 = ptr;

            ptrt = ptr1;
        }
        std::cout << ptrt.getPtrObj() << '\n';
    }



//    MySharedPtr<int> ptr {makeShared<int>(2)};
//    std::cout << ptr.getPtr() << '\n';
//    std::cout << ptr.getPtrObj() << '\n';
//    std::cout << ptr.getPtrCounter() << '\n' << '\n';

//    MySharedPtr<int> myptr {makeShared<int>(b)};
//    std::shared_ptr<int> ptr {std::make_shared<int>(b)};


    return 1;
}
