begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) Peter Wemm<peter@netplex.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCPU_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_error
error|#
directive|error
error|gcc is required to use this file
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/tss.h>
end_include

begin_comment
comment|/*  * The SMP parts are setup in pmap.c and locore.s for the BSP, and  * mp_machdep.c sets up the data for the AP's to "see" when they awake.  * The reason for doing it via a struct is so that an array of pointers  * to each CPU's data can be set up for things like "check curproc on all  * other processors"  */
end_comment

begin_define
define|#
directive|define
name|PCPU_MD_FIELDS
define|\
value|struct	pcpu *pc_prvspace;
comment|/* Self-reference */
value|\ 	struct	i386tss pc_common_tss;					\ 	struct	segment_descriptor pc_common_tssd;			\ 	struct	segment_descriptor *pc_tss_gdt;				\ 	int	pc_currentldt;						\ 	u_int32_t pc_int_pending;
comment|/* master int pending flag */
value|\ 	u_int32_t pc_ipending;
comment|/* pending slow interrupts */
value|\ 	u_int32_t pc_fpending;
comment|/* pending fast interrupts */
value|\ 	u_int32_t pc_spending
end_define

begin_comment
comment|/* pending soft interrupts */
end_comment

begin_comment
comment|/*  * Evaluates to the byte offset of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__pcpu_offset
parameter_list|(
name|name
parameter_list|)
define|\
value|__offsetof(struct pcpu, name)
end_define

begin_comment
comment|/*  * Evaluates to the type of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__pcpu_type
parameter_list|(
name|name
parameter_list|)
define|\
value|__typeof(((struct pcpu *)0)->name)
end_define

begin_comment
comment|/*  * Evaluates to the address of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_PTR
parameter_list|(
name|name
parameter_list|)
value|({						\ 	__pcpu_type(name) *__p;						\ 									\ 	__asm __volatile("movl %%fs:%1,%0; addl %2,%0"			\ 	    : "=r" (__p)						\ 	    : "m" (*(struct pcpu *)(__pcpu_offset(pc_prvspace))),	\ 	      "i" (__pcpu_offset(name)));				\ 									\ 	__p;								\ })
end_define

begin_comment
comment|/*  * Evaluates to the value of the per-cpu variable name.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_GET
parameter_list|(
name|name
parameter_list|)
value|({						\ 	__pcpu_type(name) __result;					\ 									\ 	if (sizeof(__result) == 1) {					\ 		u_char __b;						\ 		__asm __volatile("movb %%fs:%1,%0"			\ 		    : "=r" (__b)					\ 		    : "m" (*(u_char *)(__pcpu_offset(name))));		\ 		__result = *(__pcpu_type(name) *)&__b;			\ 	} else if (sizeof(__result) == 2) {				\ 		u_short __w;						\ 		__asm __volatile("movw %%fs:%1,%0"			\ 		    : "=r" (__w)					\ 		    : "m" (*(u_short *)(__pcpu_offset(name))));		\ 		__result = *(__pcpu_type(name) *)&__w;			\ 	} else if (sizeof(__result) == 4) {				\ 		u_int __i;						\ 		__asm __volatile("movl %%fs:%1,%0"			\ 		    : "=r" (__i)					\ 		    : "m" (*(u_int *)(__pcpu_offset(name))));		\ 		__result = *(__pcpu_type(name) *)&__i;			\ 	} else {							\ 		__result = *__PCPU_PTR(name);				\ 	}								\ 									\ 	__result;							\ })
end_define

begin_comment
comment|/*  * Sets the value of the per-cpu variable name to value val.  */
end_comment

begin_define
define|#
directive|define
name|__PCPU_SET
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|)
value|({					\ 	__pcpu_type(name) __val = (val);				\ 									\ 	if (sizeof(__val) == 1) {					\ 		u_char __b;						\ 		__b = *(u_char *)&__val;				\ 		__asm __volatile("movb %1,%%fs:%0"			\ 		    : "=m" (*(u_char *)(__pcpu_offset(name)))		\ 		    : "r" (__b));					\ 	} else if (sizeof(__val) == 2) {				\ 		u_short __w;						\ 		__w = *(u_short *)&__val;				\ 		__asm __volatile("movw %1,%%fs:%0"			\ 		    : "=m" (*(u_short *)(__pcpu_offset(name)))		\ 		    : "r" (__w));					\ 	} else if (sizeof(__val) == 4) {				\ 		u_int __i;						\ 		__i = *(u_int *)&__val;					\ 		__asm __volatile("movl %1,%%fs:%0"			\ 		    : "=m" (*(u_int *)(__pcpu_offset(name)))		\ 		    : "r" (__i));					\ 	} else {							\ 		*__PCPU_PTR(name) = __val;				\ 	}								\ })
end_define

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|__PCPU_GET(pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|__PCPU_PTR(pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|val
parameter_list|)
value|__PCPU_SET(pc_ ## member, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_PCPU_H_ */
end_comment

end_unit

