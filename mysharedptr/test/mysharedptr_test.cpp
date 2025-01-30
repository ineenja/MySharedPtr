#include <gtest/gtest.h>
#include <iostream>
#include <mysharedptr/mysharedptr.h>


TEST(ObjectValueTest, MySharedPtrTests) {
    int test = 1;
    MySharedPtr<int> myptr {makeShared<int>(test)};
    std::shared_ptr<int> ptr {std::make_shared<int>(test)};

    ASSERT_EQ(myptr.getPtrObj(), *ptr.get());
}

TEST(CounterTest1, MySharedPtrTests) {
    int test = 1;
    MySharedPtr<int> myptr {makeShared<int>(test)};
    std::shared_ptr<int> ptr {std::make_shared<int>(test)};

    ASSERT_EQ(myptr.getPtrCounter(), ptr.use_count());

    MySharedPtr<int> myptrcopy = myptr;
    std::shared_ptr<int> ptrcopy = ptr;

    ASSERT_EQ(myptrcopy.getPtrCounter(), ptrcopy.use_count());
}

TEST(DestructorTest11, MySharedPtrTests) {

    int test = 1;
    int *a;
    int *b;

    for (int i = 0; i != 1; i++){
        MySharedPtr<int> myptr (new int(test));
        std::shared_ptr<int> ptr {new int(test)};

        a = myptr.getPtr();
        b = ptr.get();

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> myptr2 = myptr;
            std::shared_ptr<int> ptr2 = ptr;
        }

    }

    ASSERT_NE(*a, test);
    ASSERT_NE(*b, test);
}



