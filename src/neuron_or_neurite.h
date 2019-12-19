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

#ifndef NEUROSCIENCE_NEURON_OR_NEURITE_H_
#define NEUROSCIENCE_NEURON_OR_NEURITE_H_

namespace bdm {

class NeuronOrNeurite {
 public:
  virtual ~NeuronOrNeurite() {}

  virtual SoUid GetUid() const = 0;
};

}  // namespace bdm

#endif  // NEUROSCIENCE_NEURON_OR_NEURITE_H_
