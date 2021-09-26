#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

class CPPLib {
 public:
  //q3
  
  //q5
  void mergeArray(std::vector<int>& input1, std::vector<int>& input2);
  //q8
  bool CheckValidExpression(const std::string& a);
};


// q6
class MyString
{
public:
    char* data;
    int size;
    MyString();
    ~MyString();
    MyString(const MyString&);
    void push_back(char);
    void pop_back();
};

#endif
