begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Sequent Intel 386 using GAS.    Copyright (C) 1992 Free Software Foundation, Inc.  /* Mostly it's like a Sequent 386 without GAS.  */
end_comment

begin_include
include|#
directive|include
file|"i386/sequent.h"
end_include

begin_comment
comment|/* A C statement or statements which output an assembler instruction    opcode to the stdio stream STREAM.  The macro-operand PTR is a    variable of type `char *' which points to the opcode name in its    "internal" form--the form that is written in the machine description.     GAS version 1.38.1 doesn't understand the `repz' opcode mnemonic.    So use `repe' instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_OPCODE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{									\   if ((PTR)[0] == 'r'							\&& (PTR)[1] == 'e'						\&& (PTR)[2] == 'p')						\     {									\       if ((PTR)[3] == 'z')						\ 	{								\ 	  fprintf (STREAM, "repe");					\ 	  (PTR) += 4;							\ 	}								\       else if ((PTR)[3] == 'n'&& (PTR)[4] == 'z')			\ 	{								\ 	  fprintf (STREAM, "repne");					\ 	  (PTR) += 5;							\ 	}								\     }									\ }
end_define

begin_comment
comment|/* Define macro used to output shift-double opcodes when the shift    count is in %cl.  Some assemblers require %cl as an argument;    some don't.     GAS requires the %cl argument, so override i386/unix.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SHIFT_DOUBLE_OMITS_COUNT
end_undef

begin_define
define|#
directive|define
name|SHIFT_DOUBLE_OMITS_COUNT
value|0
end_define

begin_comment
comment|/* Print opcodes the way that GAS expects them.  */
end_comment

begin_define
define|#
directive|define
name|GAS_MNEMONICS
value|1
end_define

end_unit

