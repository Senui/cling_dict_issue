#include "src/neurite_element.h"

#include <iostream>

R__LOAD_LIBRARY(libmain)

using namespace bdm;

void test() {
  NeuriteElement my_neurite;
  SimObject *so = &my_neurite;

  std::cout << "[Before lib call] so = " << so << std::endl;
  std::cout << "[Before lib call] so->GetUid() = " << so->GetUid() << std::endl;

  my_neurite.EventHandler(so); // crashes later on dynamic cast

  std::cout << "[After lib call] so = " << so << std::endl;
  std::cout << "[After lib call] so->GetUid() = " << so->GetUid() << std::endl;

  auto *casted = dynamic_cast<NeuriteElement *>(so);
  std::cout << casted->GetUid() << std::endl;
}
