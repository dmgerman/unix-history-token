begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running Mach as the target machine.  */
end_comment

begin_comment
comment|/* We do want to add an underscore to the front of each user symbol.    i386gas.h checks this.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386gstabs.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -DMACH"
end_define

begin_comment
comment|/* Specify extra dir to search for include files.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/usr/mach/include"
end_define

begin_comment
comment|/* Make stddef.h agree with types.h.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long int"
end_define

begin_escape
end_escape

begin_comment
comment|/* Defines to be able to build libgcc.a with GCC.  */
end_comment

begin_comment
comment|/* It might seem that these are not important, since gcc 2 will never    call libgcc for these functions.  But programs might be linked with    code compiled by gcc 1, and then these will be used.  */
end_comment

begin_define
define|#
directive|define
name|perform_udivsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = a;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b), "d" (dx));	\   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_divsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   ax = a;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b));	\   return ax;								\ }
end_define

begin_define
define|#
directive|define
name|perform_umodsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   dx = 0;								\   ax = a;								\   asm ("divl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b), "d" (dx));	\   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_modsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{									\   register int dx asm("dx");						\   register int ax asm("ax");						\ 									\   ax = a;								\   asm ("cltd\n\tidivl %3" : "=a" (ax), "=d" (dx) : "a" (ax), "g" (b));	\   return dx;								\ }
end_define

begin_define
define|#
directive|define
name|perform_fixdfsi
parameter_list|(
name|a
parameter_list|)
define|\
value|{									\   auto unsigned short ostatus;						\   auto unsigned short nstatus;						\   auto int ret;								\   auto double tmp;							\ 									\&ostatus;
comment|/* guarantee these land in memory */
value|\&nstatus;								\&ret;									\&tmp;									\ 									\   asm volatile ("fnstcw %0" : "=m" (ostatus));				\   nstatus = ostatus | 0x0c00;						\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (nstatus));		\   tmp = a;								\   asm volatile ("fldl %0" :
comment|/* no outputs */
value|: "m" (tmp));		\   asm volatile ("fistpl %0" : "=m" (ret));				\   asm volatile ("fldcw %0" :
comment|/* no outputs */
value|: "m" (ostatus));		\ 									\   return ret;								\ }
end_define

end_unit

