//
// Created by mikhail on 16/07/2020.
//

#include <iostream>

extern "C" void test_extern(char* string);

extern "C" int some_cpp_func(int magic_num ) {
    std::cout << "C++ here!" << std::endl;
    test_extern("Another hello from CPP!");
    return magic_num + 42;
}