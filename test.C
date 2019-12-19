#include "src/reproducer.h"
#include <iostream>

R__LOAD_LIBRARY(libreproducer)

void test() {
  D d;
  B1 *b = &d;
  std::cout << b->GetUid() << std::endl;

  d.Foo(b);

  auto *casted = dynamic_cast<D *>(b);
  std::cout << casted->GetUid() << std::endl;
}
