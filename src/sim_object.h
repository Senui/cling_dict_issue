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

#ifndef CORE_SIM_OBJECT_SIM_OBJECT_H_
#define CORE_SIM_OBJECT_SIM_OBJECT_H_

#include "root.h"

namespace bdm {

using SoUid = uint64_t;

/// Contains code required by all simulation objects
class SimObject {
 public:
  SimObject() { uid_ = 123; }

  explicit SimObject(TRootIOCtor* io_ctor) {}

  virtual ~SimObject() {}

  SoUid GetUid() const { return uid_;}

  virtual void EventHandler(SimObject* other1) {}

 protected:
  /// unique id
  SoUid uid_;

 private:
  BDM_CLASS_DEF(SimObject, 1)
};

}  // namespace bdm

#endif  // CORE_SIM_OBJECT_SIM_OBJECT_H_
