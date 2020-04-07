#ifndef TemplateSAN_H_
#define TemplateSAN_H_

#include "params/src/params.h"
#include "Cpp/BaseClasses/IdentityModelClass.h"
#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/array_view.hpp"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"

#include <unordered_map>
#include <map>
#include <vector>
#include <memory>

extern Double singleFailureRate;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               TemplateSAN Submodel Definition                   
*********************************************************************/

class TemplateSAN : public SANModel
{
public:


  TemplateSAN();
  TemplateSAN(int index);
  TemplateSAN(const sharedVariableMap_t&, bool);
  TemplateSAN(int index, const sharedVariableMap_t&, bool);
  TemplateSAN(int index, const sharedVariableMap_t&, bool, const shared_var_topology_t&);

  ~TemplateSAN();

  class tFailActivity : public Activity {
  public:

    Place* canFail = nullptr;
    short* canFail_Mobius_Mark = nullptr;
    Place* NF = nullptr;
    short* NF_Mobius_Mark = nullptr;

    double* TheDistributionParameters = nullptr;

    tFailActivity(TemplateSAN* pParent);
    double Rate() { return 0; }
    const std::vector<Place*>& canFaildeps() const;
    Place* const canFaildeps(int) const;
    const std::vector<int>& canFaildepsID() const;
    int canFaildepsID(int) const;

    const std::vector<Place*>& NFdeps() const;
    Place* const NFdeps(int) const;
    const std::vector<int>& NFdepsID() const;
    int NFdepsID(int) const;

    int replicaIndex() const;
    bool Enabled();
    void LinkVariables();
    double Weight();
    bool ReactivationPredicate();
    bool ReactivationFunction();
    double SampleDistribution();
    double* ReturnDistributionParameters();
    int Rank();
    BaseActionClass* Fire();

  private:
    // member parent will be instantiated just before the constructor
    TemplateSAN& mParent;
  }; // tFailActivityActivity

  class TFailActivity : public Activity {
  public:

    Place* canFail = nullptr;
    short* canFail_Mobius_Mark = nullptr;
    Place* NF = nullptr;
    short* NF_Mobius_Mark = nullptr;

    double* TheDistributionParameters = nullptr;

    TFailActivity(TemplateSAN* pParent);
    ~TFailActivity();
    const std::vector<Place*>& canFaildeps() const;
    Place* const canFaildeps(int) const;
    const std::vector<int>& canFaildepsID() const;
    int canFaildepsID(int) const;

    const std::vector<Place*>& NFdeps() const;
    Place* const NFdeps(int) const;
    const std::vector<int>& NFdepsID() const;
    int NFdepsID(int) const;

    int replicaIndex() const;
    bool Enabled();
    void LinkVariables();
    double Weight();
    bool ReactivationPredicate();
    bool ReactivationFunction();
    double SampleDistribution();
    double* ReturnDistributionParameters();
    int Rank();
    BaseActionClass* Fire();
    double Rate();
  private:
    // member parent will be instantiated just before the constructor
    TemplateSAN& mParent;
  }; // TFailActivityActivity

  //List of user-specified place names
  Place* canFail = nullptr;
  Place* NF = nullptr;

  //List of user-specified place names used in a dependency aware model
  std::vector<Place*> canFails;
  std::vector<Place*> NFs;

  // Create instances of all actvities
  tFailActivity tFail{this};
  TFailActivity TFail{this};
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup tFailGroup;


  int replicaIndex() const;
  const std::vector<BaseStateVariableClass*> getStateVars(const char* name) const;

  const std::vector<Place*>& canFaildeps() const;
  Place* const canFaildeps(int) const;
  const std::vector<int>& canFaildepsID() const;
  int canFaildepsID(int) const;

  const std::vector<Place*>& NFdeps() const;
  Place* const NFdeps(int) const;
  const std::vector<int>& NFdepsID() const;
  int NFdepsID(int) const;


  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();

private:
  void Init(mobius::array_view<BaseStateVariableClass*> places,
            mobius::array_view<BaseStateVariableClass*> roPlaces);

  void InitDepAware(mobius::array_view<BaseStateVariableClass*> places,
                    mobius::array_view<BaseStateVariableClass*> roPlaces);

  int InitialPlaceSize;
  std::map<std::string, std::vector<int>> LocalDepsIndxs;
  std::vector<int> LocalDepSizes;
  std::map<std::string, std::vector<BaseStateVariableClass*>> LocalDSVs;

  // Create a vector of the local/shared places that we own (must delete)
  typedef std::unique_ptr<BaseStateVariableClass> owned_sv_t;
  std::vector<owned_sv_t> mOwnedStateVariables;
}; // end TemplateSAN

#endif // TemplateSAN_H_
