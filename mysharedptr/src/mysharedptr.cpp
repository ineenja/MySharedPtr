#include "mysharedptr.h"


// для специализированного шаблона под массивы
//template <typename T>
//MySharedPtr<T[]>::MySharedPtr(): ptr(nullptr), ptrCounter(nullptr) {}; // конструктор без параметров создающий никуда не адресующий указатель на массив

//template <typename T>
//MySharedPtr<T[]>::MySharedPtr(T* ptr): ptr(ptr), ptrCounter(new uint32_t(1)) {}; // конструктор создающий указатель на массив

//template <typename T>
//MySharedPtr<T[]>::MySharedPtr(MySharedPtr<T>& other): ptr(other.ptr), ptrCounter(other.ptrCounter) {
//    *ptrCounter += 1;
//}; // конструктор копирующий существующий указатель на массив

//template <typename T>
//MySharedPtr<T[]>::~MySharedPtr(){
//    clean();
//}

//template <typename T>
//void MySharedPtr<T[]>::clean(){
//    (*ptrCounter)--;
//    if (*ptrCounter == 0){
//        delete [] ptr;
//        delete ptrCounter;
//    }
//}

//template <typename T>
//MySharedPtr<T[]>& MySharedPtr<T[]>::operator=(const MySharedPtr* r){

//    ptr = r->ptr;
//    ptrCounter = r->ptrCounter;
//    if (ptr) {
//        ++(*ptrCounter);
//    }

//    return *this;
//}

//template <typename T>
//T* MySharedPtr<T[]>::get() const{
//    return get;
//}
