begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUFUNC_H_
end_define

begin_include
include|#
directive|include
file|<machine/asi.h>
end_include

begin_include
include|#
directive|include
file|<machine/pstate.h>
end_include

begin_comment
comment|/*  * membar operand macros for use in other macros when # is a special  * character.  Keep these in sync with what the hardware expects.  */
end_comment

begin_define
define|#
directive|define
name|C_Lookaside
value|(0)
end_define

begin_define
define|#
directive|define
name|C_MemIssue
value|(1)
end_define

begin_define
define|#
directive|define
name|C_Sync
value|(2)
end_define

begin_define
define|#
directive|define
name|M_LoadLoad
value|(0)
end_define

begin_define
define|#
directive|define
name|M_StoreLoad
value|(1)
end_define

begin_define
define|#
directive|define
name|M_LoadStore
value|(2)
end_define

begin_define
define|#
directive|define
name|M_StoreStore
value|(3)
end_define

begin_define
define|#
directive|define
name|CMASK_SHIFT
value|(4)
end_define

begin_define
define|#
directive|define
name|MMASK_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|CMASK_GEN
parameter_list|(
name|bit
parameter_list|)
value|((1<< (bit))<< CMASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|MMASK_GEN
parameter_list|(
name|bit
parameter_list|)
value|((1<< (bit))<< MMASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|Lookaside
value|CMASK_GEN(C_Lookaside)
end_define

begin_define
define|#
directive|define
name|MemIssue
value|CMASK_GEN(C_MemIssue)
end_define

begin_define
define|#
directive|define
name|Sync
value|CMASK_GEN(C_Sync)
end_define

begin_define
define|#
directive|define
name|LoadLoad
value|MMASK_GEN(M_LoadLoad)
end_define

begin_define
define|#
directive|define
name|StoreLoad
value|MMASK_GEN(M_StoreLoad)
end_define

begin_define
define|#
directive|define
name|LoadStore
value|MMASK_GEN(M_LoadStore)
end_define

begin_define
define|#
directive|define
name|StoreStore
value|MMASK_GEN(M_StoreStore)
end_define

begin_define
define|#
directive|define
name|casa
parameter_list|(
name|rs1
parameter_list|,
name|rs2
parameter_list|,
name|rd
parameter_list|,
name|asi
parameter_list|)
value|({					\ 	u_int __rd = (u_int32_t)(rd);					\ 	__asm __volatile("casa [%1] %2, %3, %0"				\ 	    : "+r" (__rd) : "r" (rs1), "n" (asi), "r" (rs2));		\ 	__rd;								\ })
end_define

begin_define
define|#
directive|define
name|casxa
parameter_list|(
name|rs1
parameter_list|,
name|rs2
parameter_list|,
name|rd
parameter_list|,
name|asi
parameter_list|)
value|({					\ 	u_long __rd = (u_int64_t)(rd);					\ 	__asm __volatile("casxa [%1] %2, %3, %0"			\ 	    : "+r" (__rd) : "r" (rs1), "n" (asi), "r" (rs2));		\ 	__rd;								\ })
end_define

begin_define
define|#
directive|define
name|flush
parameter_list|(
name|va
parameter_list|)
value|do {							\ 	__asm __volatile("flush %0" : : "r" (va));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|ldxa
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|)
value|({						\ 	u_long __r;							\ 	__asm __volatile("ldxa [%1] %2, %0"				\ 	    : "=r" (__r) : "r" (va), "n" (asi));			\ 	__r;								\ })
end_define

begin_define
define|#
directive|define
name|stxa
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|val
parameter_list|)
value|do {						\ 	__asm __volatile("stxa %0, [%1] %2"				\ 	    : : "r" (val), "r" (va), "n" (asi));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|membar
parameter_list|(
name|mask
parameter_list|)
value|do {						\ 	__asm __volatile("membar %0" : : "n" (mask));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|rd
parameter_list|(
name|name
parameter_list|)
value|({							\ 	u_int64_t __sr;							\ 	__asm __volatile("rd %%" #name ", %0" : "=r" (__sr) :);		\ 	__sr;								\ })
end_define

begin_define
define|#
directive|define
name|wr
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|,
name|xor
parameter_list|)
value|do {						\ 	__asm __volatile("wr %0, %1, %%" #name				\ 	    : : "r" (val), "rI" (xor));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|rdpr
parameter_list|(
name|name
parameter_list|)
value|({							\ 	u_int64_t __pr;							\ 	__asm __volatile("rdpr %%" #name", %0" : "=r" (__pr) :);	\ 	__pr;								\ })
end_define

begin_define
define|#
directive|define
name|wrpr
parameter_list|(
name|name
parameter_list|,
name|val
parameter_list|,
name|xor
parameter_list|)
value|do {					\ 	__asm __volatile("wrpr %0, %1, %%" #name			\ 	    : : "r" (val), "rI" (xor));					\ } while (0)
end_define

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("ta 1");
block|}
end_function

begin_comment
comment|/*  * XXX use %pil for these.  */
end_comment

begin_function
specifier|static
name|__inline
name|critical_t
name|critical_enter
parameter_list|(
name|void
parameter_list|)
block|{
name|critical_t
name|ie
decl_stmt|;
name|ie
operator|=
name|rdpr
argument_list|(
name|pstate
argument_list|)
expr_stmt|;
if|if
condition|(
name|ie
operator|&
name|PSTATE_IE
condition|)
name|wrpr
argument_list|(
name|pstate
argument_list|,
name|ie
argument_list|,
name|PSTATE_IE
argument_list|)
expr_stmt|;
return|return
operator|(
name|ie
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|critical_exit
parameter_list|(
name|critical_t
name|ie
parameter_list|)
block|{
if|if
condition|(
name|ie
operator|&
name|PSTATE_IE
condition|)
name|wrpr
argument_list|(
name|pstate
argument_list|,
name|ie
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|HAVE_INLINE_FFS
end_define

begin_comment
comment|/*  * See page 202 of the SPARC v9 Architecture Manual.  */
end_comment

begin_endif
unit|static __inline int ffs(int mask) { 	int result; 	int neg; 	int tmp;  	__asm __volatile( 	"	neg	%3, %1 ;	" 	"	xnor	%3, %1, %2 ;	" 	"	popc	%2, %0 ;	" 	"	movrz	%3, %%g0, %0 ;	" 	: "=r" (result), "=r" (neg), "=r" (tmp) : "r" (mask)); 	return (result); }
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

