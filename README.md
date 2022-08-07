# Class Complex
who works like a value

- ***Guard declaration:***

    prevent the duplicate references
```cpp
#pragma once 
```
- ***Forward declartion:***

    Only ***declatate*** the `class Complex` could we use it in the declaration of `__doapl`. The others follows the same reason.
```cpp
#include<iostream>
class Complex;
Complex& __doapl(Complex*, const Complex&);
Complex& __doami(Complex*, const Complex&);
Complex& __doaml(Complex*, const Complex&);
```
- ***Composite assignment operator:***

    ***Parameter*** is a **const** for the reason that we don't want to change the content. And this key word provide a Complier check for convenience.
```cpp
Complex& operator += (const Complex&);
```
- ***Const member function:***

    Declarate a member function is **const** means that we promise the invariance of content of member data.
    Also a check provided by Complier would be helpful.
```cpp
double real() const {   return re;  }
```
- ***Inline member function***

    For short function, **inline** is a recommendation given to Complier. The Compiler accepts it or not will be another topic, howerver.
```cpp
inline
double real(const Complex& c)
{
    return c.real();
}
```