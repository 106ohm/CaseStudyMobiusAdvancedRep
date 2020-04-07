#ifndef __PARAMS_H_INCLUDED__   // if x.h hasn't been included yet...
#define __PARAMS_H_INCLUDED__   //   #define this so the compiler knows it has been included

/* redirect stderr to file, for OPT compile mode only (no for DEBUG or TEST mode). 
Use /dev/null to disable stderr to improve the performance when the program is executed by GUI. 
Note: The list of options of the simulator, when they are not correctly used by command line, is also redirected. 
     In this case, to show the list of options use the solver compiled using debug or test mode. 
 */
//const char* const stderrfile="/tmp/mobius.smartgrid.stderr.txt";
const char* const stderrfile="/dev/null";

const double fivemin=300; // 5 minutes=300 seconds
const double tenmin=600; // 10 minutes=600 seconds

/* C++ data structures for paramters automatically generated */
#include "paramst.h"
#include "params_default.h"

#include "SAN/SAN_functions.h"

#endif 
