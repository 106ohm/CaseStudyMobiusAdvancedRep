#if !defined(__SAN_FUNCTIONS_H_INCLUDED__) && !defined(TEST)   // if x.h hasn't been included yet...
#define __SAN_FUNCTIONS_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
#include "Cpp/BaseClasses/BaseModelClass.h"

// function that compare NF->Deps(0) of the i-th replica
// with its maxim allowed value, i.e., degree of the i-th node
template <typename T, size_t MAXDEPS>
inline bool compare(Array1D<T*, MAXDEPS>* NFs){
  short deg = NFs->size() - 1;
  if (NFs->Index(0)->Mark() >= deg)
    return true;
  else
    return false;
}

// function that updates NF of the neighbours
template <typename T, size_t MAXDEPS>
inline void update(Array1D<T*, MAXDEPS>* NFs){
  short n = NFs->size();
  for (short i=0;i<n;i++){
    NFs->Index(i)->Mark() ++;
  }
}


#endif 
