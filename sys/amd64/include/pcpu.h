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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
value|\ 	struct	pmap *pc_curpmap;					\ 	struct	amd64tss *pc_tssp;					\ 	register_t pc_rsp0;						\ 	register_t pc_scratch_rsp;
comment|/* User %rsp in syscall */
value|\ 	u_int	pc_apic_id;						\ 	u_int   pc_acpi_id
end_define

begin_comment
comment|/* ACPI CPU id */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|pcpup
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCPU_GET
parameter_list|(
name|member
parameter_list|)
value|(pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_PTR
parameter_list|(
name|member
parameter_list|)
value|(&pcpup->pc_ ## member)
end_define

begin_define
define|#
directive|define
name|PCPU_SET
parameter_list|(
name|member
parameter_list|,
name|value
parameter_list|)
value|(pcpup->pc_ ## member = (value))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUCLIKE___TYPEOF
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__GNUCLIKE___OFFSETOF
argument_list|)
end_elif

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
value|__extension__ ({				\ 	__pcpu_type(name) *__p;						\ 									\ 	__asm __volatile("movq %%gs:%1,%0; addq %2,%0"			\ 	    : "=r" (__p)						\ 	    : "m" (*(struct pcpu *)(__pcpu_offset(pc_prvspace))),	\ 	      "i" (__pcpu_offset(name)));				\ 									\ 	__p;								\ })
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
value|__extension__ ({				\ 	__pcpu_type(name) __result;					\ 									\ 	if (sizeof(__result) == 1 || sizeof(__result) == 2 ||		\ 	    sizeof(__result) == 4 || sizeof(__result) == 8) {		\ 		struct __s {						\ 			u_char	__b[MIN(sizeof(__pcpu_type(name)), 8)];	\ 		} __s;							\ 		__asm __volatile("mov %%gs:%1,%0"			\ 		    : "=r" (__s)					\ 		    : "m" (*(struct __s *)(__pcpu_offset(name))));	\ 		*(struct __s *)(void *)&__result = __s;			\ 	} else {							\ 		__result = *__PCPU_PTR(name);				\ 	}								\ 									\ 	__result;							\ })
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
value|{						\ 	__pcpu_type(name) __val = (val);				\ 									\ 	if (sizeof(__val) == 1 || sizeof(__val) == 2 ||			\ 	    sizeof(__val) == 4 || sizeof(__val) == 8) {			\ 		struct __s {						\ 			u_char	__b[MIN(sizeof(__pcpu_type(name)), 8)];	\ 		} __s;							\ 		__s = *(struct __s *)(void *)&__val;			\ 		__asm __volatile("mov %1,%%gs:%0"			\ 		    : "=m" (*(struct __s *)(__pcpu_offset(name)))	\ 		    : "r" (__s));					\ 	} else {							\ 		*__PCPU_PTR(name) = __val;				\ 	}								\ }
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

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|thread
operator|*
name|__curthread
argument_list|(
argument|void
argument_list|)
block|{ 	struct
name|thread
operator|*
name|td
block|;
asm|__asm __volatile("movq %%gs:0,%0" : "=r" (td));
return|return
operator|(
name|td
operator|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|curthread
value|(__curthread())
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|this file needs to be ported to your compiler
end_error

begin_endif
endif|#
directive|endif
end_endif

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

