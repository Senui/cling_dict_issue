#include <iostream>
#include "classes.h"

using namespace bdm;
using namespace bdm::experimental::neuroscience;

int main() {
  NeuronSoma* soma = new NeuronSoma();
  NeuriteElement neurite;

  SimObject* so = neurite.GetInstance(soma);
  soma->EventHandler(so);
  std::cout << "Compiled (g++): so->GetUid() = " << so->GetUid() << std::endl;

  auto *neurite2 = dynamic_cast<NeuriteElement *>(so);
  std::cout << neurite2->GetUid() << std::endl;
  std::cout << "Compiled (g++): neurite2->GetUid() = " << neurite2->GetUid() << std::endl;
  return 0;
}
