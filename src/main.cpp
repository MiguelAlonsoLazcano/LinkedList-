#include <SingleList.h>
#include <iostream>


void testFunctionAdd(){
    SingleList<int> list;
    for(int i = 0; i < 10; ++i)
        list.add(i);

    auto head = list.getHead();
    while (head != nullptr){
        std::cout << head->getValue() << ' ';
        head = head->getNext();
    }
    std::cout << std::endl;
}

void testParamContructor(){
    SingleList<int> list(10, 5);
    auto head = list.getHead();
    while (head != nullptr){
        std::cout << head->getValue() << ' ';
        head = head->getNext();
    }
    std::cout << std::endl;
}

void testInitializedListContructor(){
    SingleList<int> list{1,2,3,4,5};
    auto head = list.getHead();
    while (head != nullptr){
        std::cout << head->getValue() << ' ';
        head = head->getNext();
    }
    std::cout << std::endl;
}

int main() {

    testFunctionAdd();
    testParamContructor();
    testInitializedListContructor();


    return 0;
}