begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sparc/sparc.h"
end_include

begin_comment
comment|/* Override the name of the mcount profiling function.  */
end_comment

begin_undef
undef|#
directive|undef
name|MCOUNT_FUNCTION
end_undef

begin_define
define|#
directive|define
name|MCOUNT_FUNCTION
value|"*.mcount"
end_define

begin_comment
comment|/* LINK_SPEC is needed only for SunOS 4.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_comment
comment|/* Override MACHINE_STATE_{SAVE,RESTORE} because we have special    traps available which can get and set the condition codes    reliably.  */
end_comment

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_SAVE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_SAVE
parameter_list|(
name|ID
parameter_list|)
define|\
value|unsigned long int ms_flags, ms_saveret;		\   asm volatile("ta	0x20\n\t"			\ 	       "mov	%%g1, %0\n\t"			\ 	       "mov	%%g2, %1\n\t"			\ 	       : "=r" (ms_flags), "=r" (ms_saveret));
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_STATE_RESTORE
end_undef

begin_define
define|#
directive|define
name|MACHINE_STATE_RESTORE
parameter_list|(
name|ID
parameter_list|)
define|\
value|asm volatile("mov	%0, %%g1\n\t"			\ 	       "mov	%1, %%g2\n\t"			\ 	       "ta	0x21\n\t"			\ 	       :
comment|/* no outputs */
value|\ 	       : "r" (ms_flags), "r" (ms_saveret));
end_define

end_unit

