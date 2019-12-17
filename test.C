#include "classes.h"

R__LOAD_LIBRARY(libmain)

using namespace bdm;
using namespace bdm::experimental::neuroscience;

void test() {
  auto* soma = new NeuronSoma();
  NeuriteElement neurite(42);

  SimObject* so = neurite.GetInstance(soma);
  soma->EventHandler(so);
  std::cout << "Macro: so->GetUid() = " << so->GetUid() << std::endl;

  auto *neurite2 = dynamic_cast<NeuriteElement *>(so);
  std::cout << "Macro: neurite2->GetUid() = " << neurite2->GetUid() << std::endl;
}