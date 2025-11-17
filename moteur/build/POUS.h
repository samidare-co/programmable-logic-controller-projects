#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
__DECLARE_DERIVED_TYPE(DATATYPE0,BOOL)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM LATCH
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,STOP)
  __DECLARE_VAR(BOOL,MOTEUR)

} LATCH;

void LATCH_init__(LATCH *data__, BOOL retain);
// Code part
void LATCH_body__(LATCH *data__);
// PROGRAM SETRESET
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,MOTOR)
  RS RS0;

} SETRESET;

void SETRESET_init__(SETRESET *data__, BOOL retain);
// Code part
void SETRESET_body__(SETRESET *data__);
#endif //__POUS_H
