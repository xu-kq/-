#include<iostream>
#include"String.hpp"

using std::ostream;

ostream& operator<< (ostream& os, String& str){
    os << str.get_c_str();
    return os;
}

int main(){
    String s1("hello");
    String s2(s1);
    String s3;
    s3 = s2;
    std::cout << s3 << std::endl;
    return 0;
}