
# HW3 EE538 - Computing Principles for Electrical Engineers

- Please clone the repository, edit [README.md](README.md) to answer the questions, and fill up functions to finish the hw.
- For non-coding questions, you will find **Answer** below each question. Please write your answer there.
- For coding questions, please make sure that your code can run ```bazel run/test```. In this homework, you will need to fill up [cpplib.cc](src/lib/cpplib.cc) and test in [tests](tests).
- For submission, please push your answers to Github before the deadline.
- Deadline: Tuesday, October 5th, at 11:59 PM (PDT)
- Total: 120 points. 100 points is considered full credit.

## Question 1 (10 Points. Easy)

Please describe circumstances when each option is preferred:

- Passing parameters by value
- Passing parameters by pointer
- Passing parameters by reference
- Passing parameters by const reference

Answer:

## Question 2 (10 Points. Easy)

- In what cases is it preferred to use a list rather than a vector? (Let’s assume cache miss is not an issue).

Answer:

- What is the difference between std::string and std::vector?

Answer:

- What is the difference between std::queue, std::stack, and std::vector?

Answer:

- Suppose we want to sort a std::vector<int>, but we cannot use std::sort. Instead, can we use std::set<int> to sort the items in the vector by putting them in the set first? Please explain under what conditions we can or we cannot?

Answer:
 
## Question 3 (15 Points. Easy)

Define a new enum type `Command` that can have the following values: `kSort`, `kFind`, `kErase`. Then define a new enum type `ResultCode` that can have the following values: `kSuccess`, `kIndexError`, `kFindError`

Implement in the following function

`ResultCode CPPLib::vector_commander(std::vector<int>& v, int left, int right, int find_value, Command command)`

- If command is `kSort`, it sorts items [left, right) in the vector and returns `kSuccess` if the given left and right indices were valid; otherwise, returns `kIndexError`
- If command is `kFind`, returns `kSuccess` if value `find_value` exists in the range [left, right); otherwise, it returns `kFindError`
- If command is `kErase`, it removes the item whose index is `left` from the vector if the index `left` was valid and returns `kSuccess`; otherwise, returns `kIndexError`
- Hints: you can use `std::sort()` and `std::find()`. Use a switch/case statement.
 
Write several tests using GTest for your function in [tests/q3_student_test.cc](tests/q3_student_test.cc).
Please create your test cases and run the following command to verify the functionality of your program. 
```
bazel test tests:q3_student_test
```

## Question 4 (10 Points. Medium)

Suppose we have a class `Point`, and function `PrintPointByVal()`, `PrintPointByPtr()`, and `PrintPointByRef()`:
```c++
class Point {
 public:
  int x_;
  int y_;
  Point() : x_(0), y_(0) {}
  Point(int x, int y) : x_(x), y_(y) {}
};
void PrintPointByVal(Point p) { std::cout << "x=" << p.x_ << ", y=" << p.y_ << std::endl; }
void PrintPointByPtr(Point *p) { std::cout << "x=" << p->x_ << ", y=" << p->y_ << std::endl; }
void PrintPointByRef(Point &p) { std::cout << "x=" << p.x_ << ", y=" << p.y_ << std::endl; }
```
For each of the following snippets, please write down which function(s) will be called (including constructors):

If there is an error anywhere in the snippet, please indicate and give some explanations.

E.g. Snippet: 
```c++
Point p1(1, 2);
PrintPointByRef(p1);
```
Answer: 
1. Parameterized constructor of Class `Point`
2. `PrintPointByRef()`

It's your turn:

Snippet 1:
```c++
Point p1;
Point p2 = p1;
```
Answer:

Snippet 2:
```c++
Point p1;
PrintPointByVal(p1);
```
Answer:

Snippet 3:
```c++
Point *ptr;
PrintPointByPtr(ptr);
```
Answer:

Snippet 4:
```c++
#include <iostream>
Point* ptr = new Point;
std::cout << *ptr.x_;
```
Answer:

Snippet 5:
```c++
Point *ptr = new Point(1, 2);
PrintPointByPtr(ptr);
ptr->~Point();
```
Answer:

## Question 5 (?? Points. Easy)

Given two integer arrays `input1` and `input2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `input1` and `input2` respectively. **Merge** `input1` and `input2` into a single array sorted in **non-decreasing order**. Function is defined as ```void mergeArray(std::vector<int>& input1, std::vector<int>& input2)```

- The final sorted array should not be returned by the function, but instead be *stored inside the array* `input1`. To accommodate this, `input1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `input2` has a length of `n`.

- There is no case that two inputs are empty.

- You **cannot** use std::merge or std::sort.

- You should come up with an algorithm that runs in **O(m + n)** time.

- **Hint**: you may use two pointers.

  Example 1:
  
  input1 = {1, 2, 3, 0, 0, 0}, m = 3, input2 = {2, 5, 6}, n = 3
  Output: input1 becomes {1, 2, 2, 3, 5, 6}

  Example 2: 

  input1 = {1}, m = 1, input2 = {}, n = 0
  Output: input1 becomes {1}

  Example 3: 

  input1 = {0}, m = 0, input2 = {1}, n = 1
  Output: input1 becomes {1}

Write several tests using GTest for your function in [tests/q5_student_test.cc](tests/q5_student_test.cc).
Please create your test cases and run the following command to verify the functionality of your program. 
```
bazel test tests:q5_student_test
```
## Question 6 (20 Points. Easy)
Implement a class called `MyString` similar to std::String. The class have a dynamic array for data and an int variable for size. Please write functions below
 - constructor
 - destructor
 - copy constructor
 - push_back
 - pop_back

```c++
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
```

Example:
```c++
MyString s1;
s1.push_back('E');
s1.push_back('E');
s1.push_back('5');
s1.push_back('3');
s1.push_back('8');
s1.push_back('!');
std::cout << "s1: " << s1.data << std::endl;

MyString s2 = s1;
s2.pop_back();
s2.push_back('?');
std::cout << "s1: " << s1.data << std::endl;
std::cout << "s2: " << s2.data << std::endl;
```
Expected output:
```
s1: EE538!
s1: EE538!
s2: EE538?
Delete!
Delete!
```

Write several tests using GTest for your function in [tests/q6_student_test.cc](tests/q6_student_test.cc).

Please create your test cases and run the following command to verify the functionality of your program. You don't need to test the destructor.

```
bazel test tests:q6_student_test
```

## Question 7 (15 Points. Medium)
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

Write a test using GTest for your finction in [tests/q7_student_test.cc](tests/q7_student_test.cc).
```
bazel test tests:q7_student_test
```
Please compute the time complexity of your implementation.

Answer:

## Question 8 (20 Points. Medium)

Assume `ListNode`, `SinglyLinkedList` are given and all member functions are already implemented:

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class SinglyLinkedList {
public:
    ListNode *head_;
    SinglyLinkedList() { head_ = nullptr; }
    bool empty();
    int size();
    void push_back(int i);
    void pop_back();
    int back();
    ListNode *GetBackPointer();
    ListNode *GetIthPointer(int i);
    void print();
};
```

1. Write a copy constructor for the list.

2. Write a new parameterized constructor `SinglyLinkedList(const std::vector<int> &v);` that takes a vector as an input and creates a linked list based on that. Note that your constructor should assign a valid value for `head_`.

   Example: 

   Input: v = {1, 4, 5, 6, 10}, 

   The created list: 1->4->5->6->10, and `head_` will point to the first node with value 1

3. Write a function `std::vector convert_to_vector();` that converts the list into a vector. 

   Example:

   The list: 1->4->5->6->10.

   Output: a vector with value: {1, 4, 5, 6, 10}

4. Write a function`ListNode *erase(int i);`Erase element i from the list if it exists and returns a pointer to item i-1. If item i doesn't exist, returns nullptr. The first item in the list has index 0. 

   Example: 

   Input: 1 -> 5 -> 10 ->20, i= 2.

   Output: 1 -> 5 -> 20, return value: a pointer to element 5.

5. Write a function `std::map<int, int> histogram();` Returns a histogram of the items in the list.

   Example:

   Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32

   Output: {{1,2}, {4,1}, {5,2}, {32,1}}

6. Write a function `void remove_duplicates();` Removes duplicate elements and only keeps the first one.

   Example:

   Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32

   Output: 1 -> 5 -> 20 -> 4 -> 32

7. Assuming the following struct is defined. Write a function `Statistics calculate_statistics()` which iterates through the list and returns a variable of type Statistics which has the correct values for the items in the list.

   ```c++
   struct Statistics {
     int minimum;
     int maximum;
     int median;
     float average;
     float standard_deviation;
    };
   ```

# Optional
 
## Question 9 (Medium)

Write your own class to recreate std::queue. Use a private member of type std::vector and add member functions such as push, pop, top, size, and empty. Also, implement the copy constructor.

## Question 10 (Medium)
 
Repeat Question 8 for a stack.