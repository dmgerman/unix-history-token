begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: atomic.h,v 1.1 1998/08/24 08:39:36 dfr Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts.  This code is now SMP safe as well.  *  * The assembly is volatilized to demark potential before-and-after side  * effects if an interrupt or SMP collision were to occurs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|ATOMIC_ASM
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|OP
parameter_list|,
name|V
parameter_list|)
define|\
value|static __inline void			\ NAME(void *p, TYPE v)			\ {					\ 	__asm __volatile("lock; "	\ 			 OP : "=m" (*(TYPE *)p) : "ir" (V), "0" (*(TYPE *)p)); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_ASM
parameter_list|(
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|OP
parameter_list|,
name|V
parameter_list|)
define|\
value|static __inline void			\ NAME(void *p, TYPE v)			\ {					\ 	__asm __volatile(OP : "=m" (*(TYPE *)p) : "ir" (V), "0" (*(TYPE *)p)); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_set_char
argument_list|,
argument|u_char
argument_list|,
literal|"orb %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_clear_char
argument_list|,
argument|u_char
argument_list|,
literal|"andb %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_add_char
argument_list|,
argument|u_char
argument_list|,
literal|"addb %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_subtract_char
argument_list|,
argument|u_char
argument_list|,
literal|"subb %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_set_short
argument_list|,
argument|u_short
argument_list|,
literal|"orw %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_clear_short
argument_list|,
argument|u_short
argument_list|,
literal|"andw %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_add_short
argument_list|,
argument|u_short
argument_list|,
literal|"addw %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_subtract_short
argument_list|,
argument|u_short
argument_list|,
literal|"subw %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_set_int
argument_list|,
argument|u_int
argument_list|,
literal|"orl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_clear_int
argument_list|,
argument|u_int
argument_list|,
literal|"andl %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_add_int
argument_list|,
argument|u_int
argument_list|,
literal|"addl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_subtract_int
argument_list|,
argument|u_int
argument_list|,
literal|"subl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_set_long
argument_list|,
argument|u_long
argument_list|,
literal|"orl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_clear_long
argument_list|,
argument|u_long
argument_list|,
literal|"andl %1,%0"
argument_list|,
argument|~v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_add_long
argument_list|,
argument|u_long
argument_list|,
literal|"addl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_macro
name|ATOMIC_ASM
argument_list|(
argument|atomic_subtract_long
argument_list|,
argument|u_long
argument_list|,
literal|"subl %1,%0"
argument_list|,
argument|v
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|ATOMIC_ASM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

