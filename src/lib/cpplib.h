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
  ResultCode VectorCommander(std::vector<int>& v, int left, int right, int find_value, Command command);
  //q3
  void mergeArray(std::vector<int>& input1, std::vector<int>& input2);
  //q6
  bool CheckValidExpression(const std::string& a);
};


// q4
class Car_shallow
{
public:
    std::vector<int>* tires;
    Car_shallow();
    Car_shallow(int,int,int,int);
    void print();
};
class Car_deep
{
public:
    std::vector<int>* tires;
    Car_deep();
    Car_deep(int,int,int,int);
    ~Car_deep();
    Car_deep(const Car_deep&);
    Car_deep& operator=(const Car_deep&);
    void print();
};

#endif
