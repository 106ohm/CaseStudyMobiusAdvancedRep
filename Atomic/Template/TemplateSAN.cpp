

// This C++ file was created by SanEditor

#include "Atomic/Template/TemplateSAN.h"

#include "Cpp/BaseClasses/SAN/SANUtils.hpp"

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>


/******************************************************************
                     TemplateSAN Constructor
******************************************************************/


TemplateSAN::TemplateSAN()
{
  auto tmp_canFail = san::make_place("canFail", 1);
  canFail = tmp_canFail.first;
  if (tmp_canFail.second)
    mOwnedStateVariables.emplace_back(canFail);
  auto tmp_NF = san::make_place("NF", 0);
  NF = tmp_NF.first;
  if (tmp_NF.second)
    mOwnedStateVariables.emplace_back(NF);

  std::array<BaseStateVariableClass*, 2> places = {
    canFail,  // 0
    NF   // 1
  };

  std::array<BaseStateVariableClass*, 0> roPlaces = {
  };

  Init(to_array_view(places), to_array_view(roPlaces));
}

TemplateSAN::TemplateSAN(int index)
:
  SANModel(index)
{
  auto tmp_canFail = san::make_place("canFail", 1);
  canFail = tmp_canFail.first;
  if (tmp_canFail.second)
    mOwnedStateVariables.emplace_back(canFail);
  auto tmp_NF = san::make_place("NF", 0);
  NF = tmp_NF.first;
  if (tmp_NF.second)
    mOwnedStateVariables.emplace_back(NF);

  std::array<BaseStateVariableClass*, 2> places = {
    canFail,  // 0
    NF   // 1
  };

  std::array<BaseStateVariableClass*, 0> roPlaces = {
  };

  Init(to_array_view(places), to_array_view(roPlaces));
}

TemplateSAN::TemplateSAN(const sharedVariableMap_t& sharedSVMap, bool initSharedSV)
{
  auto tmp_canFail = san::make_place("canFail", 1, initSharedSV, &sharedSVMap);
  canFail = tmp_canFail.first;
  if (tmp_canFail.second)
    mOwnedStateVariables.emplace_back(canFail);

  auto tmp_NF = san::make_place("NF", 0, initSharedSV, &sharedSVMap);
  NF = tmp_NF.first;
  if (tmp_NF.second)
    mOwnedStateVariables.emplace_back(NF);


  std::array<BaseStateVariableClass*, 2> places = {
    canFail,  // 0
    NF   // 1
  };

  std::array<BaseStateVariableClass*, 0> roPlaces = {
  };

  Init(to_array_view(places), to_array_view(roPlaces));
}

TemplateSAN::TemplateSAN(int index, const sharedVariableMap_t& sharedSVMap, bool initSharedSV)
:
  SANModel(index)
{
  auto tmp_canFail = san::make_place("canFail", 1, initSharedSV, &sharedSVMap);
  canFail = tmp_canFail.first;
  if (tmp_canFail.second)
    mOwnedStateVariables.emplace_back(canFail);

  auto tmp_NF = san::make_place("NF", 0, initSharedSV, &sharedSVMap);
  NF = tmp_NF.first;
  if (tmp_NF.second)
    mOwnedStateVariables.emplace_back(NF);


  std::array<BaseStateVariableClass*, 2> places = {
    canFail,  // 0
    NF   // 1
  };

  std::array<BaseStateVariableClass*, 0> roPlaces = {
  };

  Init(to_array_view(places), to_array_view(roPlaces));
}

TemplateSAN::TemplateSAN(int index, const sharedVariableMap_t& sharedSVMap, bool initSharedSV, const shared_var_topology_t& deps)
:
  SANModel(index)
{
  setDeps(deps);
  LocalDepsIndxs = getIndexes();


  shared_var_topology_const_iterator_t it;

  // Cumulate SVs as soon as they are defined
  std::vector<BaseStateVariableClass*> places;

  it = deps.find("canFail");
  if (it == deps.end())
  {
    auto tmp_canFail = san::make_place("canFail", 1, initSharedSV, &sharedSVMap);
    canFail = tmp_canFail.first;
    if (tmp_canFail.second)
      mOwnedStateVariables.emplace_back(canFail);
    canFails.push_back(canFail);
    places.push_back(canFail);
  }
  else
  {
    // canFail is a Dependency-Aware SV
    for (auto index : it->second)
    {
      std::string name = "canFail";
      name += std::to_string(index);
      auto tmp_canFail = san::make_place(name.c_str(), 1, initSharedSV, &sharedSVMap);
      canFails.push_back(tmp_canFail.first);
      assert(tmp_canFail.second == false);
      places.push_back(tmp_canFail.first);
    }
  }

  it = deps.find("NF");
  if (it == deps.end())
  {
    auto tmp_NF = san::make_place("NF", 0, initSharedSV, &sharedSVMap);
    NF = tmp_NF.first;
    if (tmp_NF.second)
      mOwnedStateVariables.emplace_back(NF);
    NFs.push_back(NF);
    places.push_back(NF);
  }
  else
  {
    // NF is a Dependency-Aware SV
    for (auto index : it->second)
    {
      std::string name = "NF";
      name += std::to_string(index);
      auto tmp_NF = san::make_place(name.c_str(), 0, initSharedSV, &sharedSVMap);
      NFs.push_back(tmp_NF.first);
      assert(tmp_NF.second == false);
      places.push_back(tmp_NF.first);
    }
  }

  std::array<BaseStateVariableClass*, 0> roPlaces = {
  };

  InitDepAware(to_array_view(places), to_array_view(roPlaces));
}

TemplateSAN::~TemplateSAN(){
};

void TemplateSAN::Init(mobius::array_view<BaseStateVariableClass*> places,
              mobius::array_view<BaseStateVariableClass*> roPlaces)
{

  std::array<Activity*, 2> actionList = {
    &tFail, //0
    &TFail  // 1
  };

  std::array<BaseGroupClass*, 2> groupList = {
    (BaseGroupClass*) &(TFail), 
    (BaseGroupClass*) &(tFail)
  };


  initializeSANModelNow("Template", places, roPlaces, 
                        to_array_view(actionList), to_array_view(groupList));

  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[4][2]={ 
    {0,0}, {1,0}, {0,1}, {1,1}
  };
  for(int n=0; n<4; ++n) {
    AddAffectArc(places[AffectArcs[n][0]],
                 actionList[AffectArcs[n][1]]);
  }
  int EnableArcs[3][2]={ 
    {0,0}, {1,0}, {0,1}
  };
  for(int n=0; n<3; ++n) {
    AddEnableArc(places[EnableArcs[n][0]],
                 actionList[EnableArcs[n][1]]);
  }

  for (auto& action : actionList)
  {
    action->LinkVariables();
  }

  CustomInitialization();
}

void TemplateSAN::InitDepAware(mobius::array_view<BaseStateVariableClass*> places,
              mobius::array_view<BaseStateVariableClass*> roPlaces)
{

  std::array<Activity*, 2> actionList = {
    &tFail, //0
    &TFail  // 1
  };

  std::array<BaseGroupClass*, 2> groupList = {
    (BaseGroupClass*) &(TFail), 
    (BaseGroupClass*) &(tFail)
  };


  initializeSANModelNow("Template", places, roPlaces, 
                        to_array_view(actionList), to_array_view(groupList));

  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  std::multimap<Activity*, std::string> affectArcs;
  affectArcs.insert( std::make_pair(actionList[0], "canFail") );
  affectArcs.insert( std::make_pair(actionList[0], "NF") );
  affectArcs.insert( std::make_pair(actionList[1], "canFail") );
  affectArcs.insert( std::make_pair(actionList[1], "NF") );

  for(auto& arc : affectArcs)
  {
    Activity* a = arc.first;
    auto range = affectArcs.equal_range(a);
    for (auto it = range.first; it != range.second; ++it)
    {
      auto affectPlaces = mobius::match_prefix(places, it->second);
      for (auto& p : affectPlaces)
        AddAffectArc(p, a);
    }
  }

  std::multimap<Activity*, std::string> enableArcs;
  enableArcs.insert( std::make_pair(actionList[0], "canFail") );
  enableArcs.insert( std::make_pair(actionList[0], "NF") );
  enableArcs.insert( std::make_pair(actionList[1], "canFail") );

  for(auto& arc : enableArcs)
  {
    Activity* a = arc.first;
    auto range = enableArcs.equal_range(a);
    for (auto it = range.first; it != range.second; ++it)
    {
      auto enablePlaces = mobius::match_prefix(places, it->second);
      for (auto& p : enablePlaces)
        AddEnableArc(p, a);
    }
  }

  for (auto& action : actionList)
  {
    action->LinkVariables();
  }

  CustomInitialization();
}

void TemplateSAN::CustomInitialization() {
}


const std::vector<Place*>& TemplateSAN::canFaildeps() const {
  return canFails;
}

Place* const TemplateSAN::canFaildeps(int i) const {
  return canFails[i];
}

const std::vector<int>& TemplateSAN::canFaildepsID() const {
    return getIndexes("canFail");
}

int TemplateSAN::canFaildepsID(int i) const {
  return getIndex("canFail",i);
}

const std::vector<Place*>& TemplateSAN::NFdeps() const {
  return NFs;
}

Place* const TemplateSAN::NFdeps(int i) const {
  return NFs[i];
}

const std::vector<int>& TemplateSAN::NFdepsID() const {
    return getIndexes("NF");
}

int TemplateSAN::NFdepsID(int i) const {
  return getIndex("NF",i);
}

int TemplateSAN::replicaIndex() const
{
  return getIndex();
}

const std::vector<BaseStateVariableClass*>  TemplateSAN::getStateVars(const char* name) const
{
  std::vector<BaseStateVariableClass*> result;
  auto indexes = getIndexes(name);
  for(auto index : indexes)
  {
    std::string tmp = name + std::to_string(index);
    for(auto var : mLocalStateVariables)
    {
      if (var->getName() == tmp)
      {
        result.push_back(var);
        break;
      }
    }
  }
  return result;
}

void TemplateSAN::assignPlacesToActivitiesInst()
{
  if (canFail == nullptr)
    tFail.canFail = canFaildeps(0);
  else
    tFail.canFail = canFail;

  if (NF == nullptr)
    tFail.NF = NFdeps(0);
  else
    tFail.NF = NF;

}

void TemplateSAN::assignPlacesToActivitiesTimed()
{
  if (canFail == nullptr)
    TFail.canFail = canFaildeps(0);
  else
    TFail.canFail = canFail;

  if (NF == nullptr)
    TFail.NF = NFdeps(0);
  else
    TFail.NF = NF;

}

/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================tFailActivity========================*/

TemplateSAN::tFailActivity::tFailActivity(TemplateSAN* pParent)
  : mParent(*pParent)
{
  std::string name = "tFail";
  ActivityInitialize(name.c_str(),1,Instantaneous , RaceEnabled, 2,2, false);
}


  const std::vector<Place*>& TemplateSAN::tFailActivity::canFaildeps() const {
    return mParent.canFaildeps();
  }

  Place* const TemplateSAN::tFailActivity::canFaildeps(int i) const {
    return mParent.canFaildeps(i);
  }

  const std::vector<int>& TemplateSAN::tFailActivity::canFaildepsID() const {
    return mParent.canFaildepsID();
  }

  int TemplateSAN::tFailActivity::canFaildepsID(int i) const {
    return mParent.canFaildepsID(i);
  }

  const std::vector<Place*>& TemplateSAN::tFailActivity::NFdeps() const {
    return mParent.NFdeps();
  }

  Place* const TemplateSAN::tFailActivity::NFdeps(int i) const {
    return mParent.NFdeps(i);
  }

  const std::vector<int>& TemplateSAN::tFailActivity::NFdepsID() const {
    return mParent.NFdepsID();
  }

  int TemplateSAN::tFailActivity::NFdepsID(int i) const {
    return mParent.NFdepsID(i);
  }

  int TemplateSAN::tFailActivity::replicaIndex() const
  {
    return mParent.replicaIndex();
  }

void TemplateSAN::tFailActivity::LinkVariables()
{
  canFail->Register(&canFail_Mobius_Mark);
  NF->Register(&NF_Mobius_Mark);
}

bool TemplateSAN::tFailActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(
(canFail->Mark() > 0 && compare(NFdeps())));
  return NewEnabled;
}

double TemplateSAN::tFailActivity::Weight(){ 
  return 1;
}

bool TemplateSAN::tFailActivity::ReactivationPredicate(){ 
  return false;
}

bool TemplateSAN::tFailActivity::ReactivationFunction(){ 
  return false;
}

double TemplateSAN::tFailActivity::SampleDistribution(){

  return 0;

}

double* TemplateSAN::tFailActivity::ReturnDistributionParameters(){
    return nullptr;
}

int TemplateSAN::tFailActivity::Rank(){
  return 1;
}

BaseActionClass* TemplateSAN::tFailActivity::Fire(){

  { // Input Gate: IGtFail
    ;
  }
  { // Output Gate: OGFail
    update(NFdeps());
canFail->Mark() = 0;
debug << "tFail fired in Replica " << replicaIndex() << std::endl;
  }
  return this;
}

/*======================TFailActivity========================*/

TemplateSAN::TFailActivity::TFailActivity(TemplateSAN* pParent)
  : mParent(*pParent)
{
  TheDistributionParameters = new double[1];
  std::string name = "TFail";
  ActivityInitialize(name.c_str(),0,Exponential, RaceEnabled, 2,1, true);
}

TemplateSAN::TFailActivity::~TFailActivity() {
  delete[] TheDistributionParameters;
}


  const std::vector<Place*>& TemplateSAN::TFailActivity::canFaildeps() const {
    return mParent.canFaildeps();
  }

  Place* const TemplateSAN::TFailActivity::canFaildeps(int i) const {
    return mParent.canFaildeps(i);
  }

  const std::vector<int>& TemplateSAN::TFailActivity::canFaildepsID() const {
    return mParent.canFaildepsID();
  }

  int TemplateSAN::TFailActivity::canFaildepsID(int i) const {
    return mParent.canFaildepsID(i);
  }

  const std::vector<Place*>& TemplateSAN::TFailActivity::NFdeps() const {
    return mParent.NFdeps();
  }

  Place* const TemplateSAN::TFailActivity::NFdeps(int i) const {
    return mParent.NFdeps(i);
  }

  const std::vector<int>& TemplateSAN::TFailActivity::NFdepsID() const {
    return mParent.NFdepsID();
  }

  int TemplateSAN::TFailActivity::NFdepsID(int i) const {
    return mParent.NFdepsID(i);
  }

  int TemplateSAN::TFailActivity::replicaIndex() const
  {
    return mParent.replicaIndex();
  }

void TemplateSAN::TFailActivity::LinkVariables()
{
  canFail->Register(&canFail_Mobius_Mark);
  NF->Register(&NF_Mobius_Mark);
}

bool TemplateSAN::TFailActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(
((*(canFail_Mobius_Mark)) >=1));
  return NewEnabled;
}

double TemplateSAN::TFailActivity::Rate(){
  return singleFailureRate * (NFdeps(0)->Mark() + 1);
  return 1.0;  // default rate if none is specified
}

double TemplateSAN::TFailActivity::Weight(){ 
  return 1;
}

bool TemplateSAN::TFailActivity::ReactivationPredicate(){ 
  return 1==1;
}

bool TemplateSAN::TFailActivity::ReactivationFunction(){ 
  return 1==1;
}

double TemplateSAN::TFailActivity::SampleDistribution(){

  try
  {
      return TheDistribution->Exponential( singleFailureRate * (NFdeps(0)->Mark() + 1));
  }
  catch(std::invalid_argument& e)
  {
      std::string msg = "\nThe timed action \'";
      msg += ActionName;
      msg += "\' tried to pass an invalid argument to ";
      msg += "the Exponential distribution.\n";
      msg += e.what();
      throw std::invalid_argument(msg);
  }
}

double* TemplateSAN::TFailActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int TemplateSAN::TFailActivity::Rank(){
  return 1;
}

BaseActionClass* TemplateSAN::TFailActivity::Fire(){

  (*(canFail_Mobius_Mark))--;
  { // Output Gate: OGTFail
    update(NFdeps());
canFail->Mark() = 0;
debug << "TFail fired in Replica " << replicaIndex() << std::endl;
  }
  return this;
}

