#include<iostream>
#include"Complex.hpp"

int main(){
    bool flag;
    Complex c1, c2(2.0, 3.0), c3(-2, -3);
    std::cout << c1+c2 << std::endl;
    
    c2 += c3;
    std::cout << c2 << std::endl;

    flag = c1 == c2;
    std::cout << flag << std::endl;
    return 0;
}