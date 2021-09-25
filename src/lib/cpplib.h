#ifndef TEMPLATE_CPPLIB_H
#define TEMPLATE_CPPLIB_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

/**
 *  Example class used for GTest demo
 */
class CPPLib {
 public:
  //q3
  void mergeArray(std::vector<int>& input1, std::vector<int>& input2);
  //q6
  bool CheckValidExpression(const std::string& a);
};

//q2
class Point{	
private:	
    int x;	
    int y;	
public:	
    Point();	
    Point(int);	
    Point(const Point&);	
    ~Point();	
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
