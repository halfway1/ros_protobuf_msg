#include "./test_template.h"

int main() {
  // 编译器在找模板的时候，是会先匹配模板全特化，和模板偏特化，最后才去匹配普通模板
  Test<double, double> t1(1.1, 1.1);
  Test<int, int> t2(1, 1);
  Test<int, char*> t3(1, "test");
  return 0;
}