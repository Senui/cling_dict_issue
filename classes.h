#include <Rtypes.h>
#include <iostream>

namespace bdm {

class SoUidGenerator {
public:
  SoUidGenerator(const SoUidGenerator &) = delete;

  static SoUidGenerator *Get() {
    static SoUidGenerator kInstance;
    return &kInstance;
  }

  unsigned long NewSoUid() { return counter_++; }

private:
  SoUidGenerator() : counter_(0) {}
  std::atomic<unsigned long> counter_;
};

class SimObject {
public:
  SimObject() { uid_ = SoUidGenerator::Get()->NewSoUid(); }
  SimObject(unsigned long uid) : uid_(uid) {}
  virtual ~SimObject() {}

  unsigned long GetUid() const { return uid_; }

  virtual void EventHandler(SimObject *so) {}

private:
  unsigned long uid_;
  ClassDef(SimObject, 1);
};

class Cell : public SimObject {
public:
  Cell() {}
  virtual ~Cell() {}

private:
  ClassDef(Cell, 1);
};

namespace experimental {
namespace neuroscience {

class NeuronOrNeurite {
public:
  NeuronOrNeurite() {}
  virtual ~NeuronOrNeurite() {}
  virtual unsigned long GetUid() const = 0;
};

class NeuronSoma;

class NeuriteElement : public SimObject, public NeuronOrNeurite {
public:
  NeuriteElement() {}
  NeuriteElement(unsigned long uid) : SimObject(uid) {}

  unsigned long GetUid() const override { return SimObject::GetUid(); }
  SimObject *GetInstance(NeuronSoma *soma) { return new NeuriteElement(); }

  void EventHandler(SimObject *so) override {}

private:
  ClassDefOverride(NeuriteElement, 1);
};

class NeuronSoma : public Cell, public NeuronOrNeurite {
public:
  NeuronSoma() {}
  virtual ~NeuronSoma() {}

  unsigned long GetUid() const override { return Cell::GetUid(); }

  void EventHandler(SimObject *so) override {
    auto *neurite = dynamic_cast<NeuriteElement *>(so);
    std::cout << "EventHandler: " << neurite->GetUid() << std::endl;
  }

private:
  ClassDefOverride(NeuronSoma, 1);
};

} // namespace experimental
} // namespace neuroscience
} // namespace bdm
