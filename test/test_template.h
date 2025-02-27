#include <iostream>

template <class T1, class T2>
class Test {
 public:
  Test(T1 a, T2 b) : a_(a), b_(b) { std::cout << "模板化" << std::endl; }

 private:
  T1 a_;
  T2 b_;
};

//模板全特化
// 不能隐式转换， 必须显式
template <> // 没有参数
class Test<int, int> {
 public:
  Test(int a, int b) : a_(a), b_(b) { std::cout << "模板全特化" << std::endl; }

 private:
  int a_;
  int b_;
};

//模板偏特化，半特化
template <class T> // 一个参数
class Test<int, T> {
 public:
  Test(int a, T b) : a_(a), b_(b) { std::cout << "模板偏特化" << std::endl; }

 private:
  int a_;
  T b_;
};
