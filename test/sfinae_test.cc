#include "./sfinae_test.h"

int main() {
  Test<double> t1(1.1); //// 偏特化
  Test<int> t2(1); //普通
  return 0;
}