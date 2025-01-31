#include <gtest/gtest.h>
#include <iostream>
#include <mysharedptr/mysharedptr.h>

TEST(ObjectValueTest, MySharedPtrTests) {
    int test1 = 1;
    MySharedPtr<int> myptr {makeShared<int>(test1)};
    std::shared_ptr<int> ptr {std::make_shared<int>(test1)};

    ASSERT_EQ(*myptr, *ptr);
}

TEST(CounterTest1, MySharedPtrTests) {
    int test2 = 1;
    MySharedPtr<int> myptr {makeShared<int>(test2)};
    std::shared_ptr<int> ptr {std::make_shared<int>(test2)};

    ASSERT_EQ(myptr.getPtrCounter(), ptr.use_count());

    MySharedPtr<int> myptrcopy = myptr;
    std::shared_ptr<int> ptrcopy = ptr;

    ASSERT_EQ(myptrcopy.getPtrCounter(), ptrcopy.use_count());
}

TEST(DestructorTest1, MySharedPtrTests) {

    int test3 = 1;
    int a;
    int b;

    for (int i = 0; i != 1; i++){
        MySharedPtr<int> myptr (new int(test3));
        std::shared_ptr<int> ptr {new int(test3)};

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> myptr2 = myptr;
            std::shared_ptr<int> ptr2 = ptr;

            a = myptr.getPtrCounter();
            b = ptr.use_count();
            test3 = 2;
            EXPECT_EQ(a, test3);
            EXPECT_EQ(b, test3);
        }
        a = myptr.getPtrCounter();
        b = ptr.use_count();
        test3 = 1;
        EXPECT_EQ(a, test3);
        EXPECT_EQ(b, test3);
    }
}

TEST(DestructorTest2, MySharedPtrTests) {

    int test4 = 1;
    int *a;
    int *b;

    for (int i = 0; i != 1; i++){
        MySharedPtr<int> myptr {makeShared<int>(test4)};
        std::shared_ptr<int> ptr {std::make_shared<int>(test4)};

        a = myptr.getPtr();
        b = ptr.get();

        for (int i = 0; i != 1; i++){
            MySharedPtr<int> myptr2 = myptr;
            std::shared_ptr<int> ptr2 = ptr;
        }

    }

    ASSERT_EQ(*a, test4);
    ASSERT_EQ(*b, test4);
}





