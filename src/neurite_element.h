// -----------------------------------------------------------------------------
//
// Copyright (C) The BioDynaMo Project.
// All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// See the LICENSE file distributed with this work for details.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership.
//
// -----------------------------------------------------------------------------

#ifndef NEUROSCIENCE_NEURITE_ELEMENT_H_
#define NEUROSCIENCE_NEURITE_ELEMENT_H_

#include "sim_object.h"
#include "neuron_or_neurite.h"
#include <iostream>

namespace bdm {

class NeuriteElement : public SimObject, public NeuronOrNeurite {
 public:
  NeuriteElement() {}
  NeuriteElement(TRootIOCtor*) {}

  void EventHandler(SimObject* other1) override {
    SimObject::EventHandler(other1);

    std::cout << "[In lib call, before cast] other1 = " << other1 << std::endl;
    std::cout << "[In lib call, before cast] other1->GetUid() = " << other1->GetUid() << std::endl;
    NeuriteElement* neurite = dynamic_cast<NeuriteElement*>(other1);
    std::cout << "[In lib call, after cast] other1 = " << other1 << std::endl;
    std::cout << "[In lib call, after cast] other1->GetUid() = " << other1->GetUid() << std::endl;
    std::cout << neurite->GetUid() << std::endl;
}

  SoUid GetUid() const override { return SimObject::GetUid(); }

  BDM_CLASS_DEF_OVERRIDE(NeuriteElement, 1);
};

}  // namespace bdm

#endif  // NEUROSCIENCE_NEURITE_ELEMENT_H_
