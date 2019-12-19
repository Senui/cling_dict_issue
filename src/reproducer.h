#include "custom_macros.h"
#include <iostream>

class B1 {
public:
  B1() : uid_(123) {}
  virtual ~B1() {}
  int GetUid() const { return uid_; }
  BDM_CLASS_DEF(B1, 1)

protected:
  int uid_;
};

class B2 {
public:
  virtual int GetUid() const = 0;
};

class D : public B1, public B2 {
public:
  D() {}
  void Foo(B1 *b) {
    D *d = dynamic_cast<D *>(b);
    std::cout << d->GetUid() << std::endl;
  }
  int GetUid() const override { return B1::GetUid(); }
  BDM_CLASS_DEF_OVERRIDE(D, 1)
};
