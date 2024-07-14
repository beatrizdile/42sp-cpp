#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

static void printData(const Data *p) {
    std::cout << "Name: " << p->name << std::endl;
    std::cout << "Year: " << p->year << std::endl;
    std::cout << "Price: " << p->price << std::endl << std::endl;
}

int main() {
    Data *data = new Data();

    data->name = "Bea";
    data->year = 2004;
    data->price = 4.2f;

    uintptr_t ptr;

    std::cout << "Data before serialize" << std::endl;
    std::cout << "Data address: " << data << std::endl;
    printData(data);

    ptr = Serializer::serialize(data);
    std::cout << "Data after serialize" << std::endl;
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Serialized data address: " << ptr << std::endl;
    printData(data);

    Data *testData;

    testData = Serializer::deserialize(ptr);
    std::cout << "Data after deserialize" << std::endl;
    std::cout << "Data address: " << testData << std::endl;
    printData(testData);

    delete data;
}
