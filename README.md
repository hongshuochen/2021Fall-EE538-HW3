
# HW3 EE538 - Computing Principles for Electrical Engineers

- Plesae clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the hw.
- For non-coding quesitions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and tests in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Friday, March 5th by 23:59 pm
- Total: 120 points. 100 points is considered full credit.

## Question 1 (20 Points. Easy)

Please compare pros and cons of the following options, and also describe when each option is preferred.

- Passing parameters by value
- Passing parameters using pointers
- Passing parameters using references
- Passing parameters using const references

Answer:

## Question 2 (20 Points. Easy)
Part 1:\
Please write a class called `Point` which has private int attributes ```x```, ```y``` as its coordinates:
- Write a default constructor that initializes ```x```, ```y``` to ```0```, ```0```.
- Write a constructor that takes only one parameter ```x```. Use that parameter to initialize ```x``` and set ```y``` to ```0```.
- Write a constructor that takes two parameters.
- Write a copy constructor.
- Write a destructor that prints “Destructor is called!”.
- For class `Point`, make attributes private, and write ```GetX()``` and ```GetY()``` functions to return the values.
- Write several tests using GTest for your function in [tests/q2_student_test.cc](tests/q2_student_test.cc).

Part 2:\
Assume all constructors and function `PrintPoint()` are given. (You do not have to implement `PrintPoint()`) \
Assume the destructor will not be called.

For each of the following snippets, please write down which function(s) will be called:

Snippet 1:
Assuming the declaration of `PrintPoint()` is `void PrintPoint(Point p);`
```c++
Point p1;
PrintPoint (p1);
```
Answer:

Snippet 2:
Assuming the declaration of `PrintPoint()` is `void PrintPoint(Point &p);`
```c++
Point p1;
PrintPoint(p1);
```
Answer:

Snippet 3:
Assuming the declaration of `PrintPoint()` is `void PrintPoint(const Point &p);`
```c++
Point p1;
PrintPoint(p1);
```
Answer:

Snippet 4:
Assuming the declaration of `PrintPoint()` is `void PrintPoint(Point *p);`
```c++
Point *ptr;
PrintPoint(ptr);
```
Answer:

Snippet 5:
Assuming the declaration of `PrintPoint()` is `void PrintPoint(Point *p);`
```c++
Point *ptr;
ptr = new Point;
PrintPoint(ptr);
```
Answer:

## Question 3 (20 Points. Easy)

Given a vector of integer ```input```, and an integer ```sum```, return a set of sets ```{a,b}```, where ```a```, ```b``` are in the input vector and ```a + b = sum```, which are the numbers in ```input``` such that they can add up to sum. Function is defined as ```std::set<std::set<int>> twoSum(std::vector<int>& input, int sum)```

- You can assume the vector input doesn't contain duplicated numbers.
- You can only use numbers in vector once.
- If there is no answer, the output should return an empty set.
- You should return **all** results in the input vector if there are multiple answers.
- **Hint**: you may try unordered_map.
- Examples:
  - input = {2,3,4,5}, sum = 7, output = {{2,5},{3,4}}
  - input = {2,3,-2,5,0}, sum = 0, output = {{2,-2}}
  - input = {1,5,4,10}, sum = 200, output = {}

Write several tests using GTest for your function in [tests/q3_student_test.cc](tests/q3_student_test.cc).
Please create your test cases and run the following command to verify the functionality of your program.And what's your function's **time complexity**?
```
bazel test tests:q3_student_test
```
Please compute the time complexity of your implementation.

Answer:

## Question 4 (20 Points. Easy)

Write 2 classes to practice how to use the constructor, copy constructor, copy assign operator and destructor and compare the deep copy with shallow copy.

Both of the Car_shallow and Car_deep has one member vector pointer tires.

- Student_shallow
  - Write a **default constructor** to initialize tires to a vector with four 10. 
  - Write a **parameterized constructor** to initialize vector to desired tire pressures.

- Student_deep
  - Write a **default constructor** to initialize tires to a vector with four 10. 
  - Write a **parameterized constructor** to initialize vector to desired tire pressures.
  - Write a **destructor** to print "Delete Car_deep" and delete the integer pointer
  - Write a **copy constructor** with **deep copy**
  - Write a **copy assignment operator** with **deep copy**

Hint: How to create a vector
tires = new std::vector<int>();

```c++
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
```

Example:
```
std::cout << "Shallow" << std::endl;
Car_shallow a(11,12,13,14);
Car_shallow b = a;
Car_shallow c;
c = a;
std::cout << "Before" << std::endl;
a.print();
b.print();
c.print();
for (auto& p: (*a.tires))
  p *= 2;
std::cout << "After" << std::endl;
a.print();
b.print();
c.print();

std::cout << "Deep" << std::endl;
Car_deep a_deep(11,12,13,14);;
Car_deep b_deep = a_deep;
Car_deep c_deep;
c_deep = a_deep;
std::cout << "Before" << std::endl;
a_deep.print();
b_deep.print();
c_deep.print();
for (auto& p: (*a_deep.tires))
  p *= 2;
for (auto& p: (*b_deep.tires))
  p *= 3;
std::cout << "After" << std::endl;
a_deep.print();
b_deep.print();
c_deep.print();
```
Expected output:
```
Shallow
Before
11 12 13 14 
11 12 13 14 
11 12 13 14 
After
22 24 26 28 
22 24 26 28 
22 24 26 28 
Deep
Before
11 12 13 14 
11 12 13 14 
11 12 13 14 
After
22 24 26 28 
33 36 39 42 
11 12 13 14 
Delete Car_deep
Delete Car_deep
Delete Car_deep
```

Write several tests using GTest for your function in [tests/q4student_test.cc](tests/q4_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program. You don't need to test the destructor.
```
bazel test tests:q4_student_test
```

## Question 5 (20 Points. Medium)
Given an expression string, find if the input has valid brackets (i.e. { } or [ ] or ( ) ). Function is defined as ```bool​ ​CheckValidExpression​(​const​ ​string​&​ ​a​)```

An input expression is valid if:

Open brackets are closed by the same type of brackets.
Open brackets must be closed in the correct order.
An empty string is also considered valid.

You should only check for the validity of brackets based on the above rules, i.e. ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’, not the rest of the expression.

Example 1:
Input: "(a+b)"
Output: true

Example 2:
Input: "(a+b)[c*d]{5g+h}"
Output: true

Example 3:
Input: "(a+b]"
Output: false

Example 4:
Input: "(7h+[5c)+7]"
Output: false

Example 5:
Input: "{2k+[5j]}"
Output: true

Example 6:
Input: "{2k++[5--*j]}"
Output: true

Write a test using GTest for your finction in [tests/q5_student_test.cc](tests/q5_student_test.cc).
```
bazel test tests:q5_student_test
```
Please compute the time complexity of your implementation.

Answer:

