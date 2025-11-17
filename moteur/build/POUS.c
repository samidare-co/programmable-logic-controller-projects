void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void LATCH_init__(LATCH *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTEUR,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LATCH_body__(LATCH *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,MOTEUR,,(!(__GET_VAR(data__->STOP,)) && (__GET_VAR(data__->MOTEUR,) || __GET_VAR(data__->START,))));

  goto __end;

__end:
  return;
} // LATCH_body__() 





void SETRESET_init__(SETRESET *data__, BOOL retain) {
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOTOR,__BOOL_LITERAL(FALSE),retain)
  RS_init__(&data__->RS0,retain);
}

// Code part
void SETRESET_body__(SETRESET *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->RS0.,S,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->RS0.,R1,,__GET_VAR(data__->RESET,));
  RS_body__(&data__->RS0);
  __SET_VAR(data__->,MOTOR,,__GET_VAR(data__->RS0.Q1,));

  goto __end;

__end:
  return;
} // SETRESET_body__() 





