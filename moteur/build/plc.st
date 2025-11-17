TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


TYPE
  datatype0 : BOOL;
END_TYPE

PROGRAM latch
  VAR
    start : BOOL := True;
    stop : BOOL;
    moteur : BOOL;
  END_VAR

  moteur := NOT(stop) AND (moteur OR start);
END_PROGRAM

PROGRAM setreset
  VAR
    SET : BOOL;
    RESET : BOOL;
    MOTOR : BOOL;
    RS0 : RS;
  END_VAR

  RS0(S := SET, R1 := RESET);
  MOTOR := RS0.Q1;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : setreset;
  END_RESOURCE
END_CONFIGURATION
