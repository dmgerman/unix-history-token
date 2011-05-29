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

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Membar operand macros for use in other macros when # is a special  * character.  Keep these in sync with what the hardware expects.  */
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
value|({					\ 	u_int __rd = (uint32_t)(rd);					\ 	__asm __volatile("casa [%2] %3, %4, %0"				\ 	    : "+r" (__rd), "=m" (*rs1)					\ 	    : "r" (rs1), "n" (asi), "r" (rs2), "m" (*rs1));		\ 	__rd;								\ })
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
value|({					\ 	u_long __rd = (uint64_t)(rd);					\ 	__asm __volatile("casxa [%2] %3, %4, %0"			\ 	    : "+r" (__rd), "=m" (*rs1)					\ 	    : "r" (rs1), "n" (asi), "r" (rs2), "m" (*rs1));		\ 	__rd;								\ })
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
name|flushw
parameter_list|()
value|do {							\ 	__asm __volatile("flushw" : :);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|mov
parameter_list|(
name|val
parameter_list|,
name|reg
parameter_list|)
value|do {						\ 	__asm __volatile("mov %0, %" __XSTRING(reg) : : "r" (val));	\ } while (0)
end_define

begin_comment
comment|/* Generate ld*a/st*a functions for non-constant ASIs. */
end_comment

begin_define
define|#
directive|define
name|LDNC_GEN
parameter_list|(
name|tp
parameter_list|,
name|o
parameter_list|)
define|\
value|static __inline tp						\ 	o ## _nc(caddr_t va, int asi)					\ 	{								\ 		tp r;							\ 		__asm __volatile("wr %2, 0, %%asi;" #o " [%1] %%asi, %0"\ 		    : "=r" (r) : "r" (va), "r" (asi));			\ 		return (r);						\ 	}
end_define

begin_expr_stmt
name|LDNC_GEN
argument_list|(
name|u_char
argument_list|,
name|lduba
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDNC_GEN
argument_list|(
name|u_short
argument_list|,
name|lduha
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDNC_GEN
argument_list|(
name|u_int
argument_list|,
name|lduwa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDNC_GEN
argument_list|(
name|u_long
argument_list|,
name|ldxa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|LD_GENERIC
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|op
parameter_list|,
name|type
parameter_list|)
value|({				\ 	type __r;							\ 	__asm __volatile(#op " [%1] %2, %0"				\ 	    : "=r" (__r) : "r" (va), "n" (asi));			\ 	__r;								\ })
end_define

begin_define
define|#
directive|define
name|lduba
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|)
value|LD_GENERIC(va, asi, lduba, u_char)
end_define

begin_define
define|#
directive|define
name|lduha
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|)
value|LD_GENERIC(va, asi, lduha, u_short)
end_define

begin_define
define|#
directive|define
name|lduwa
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|)
value|LD_GENERIC(va, asi, lduwa, u_int)
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
value|LD_GENERIC(va, asi, ldxa, u_long)
end_define

begin_define
define|#
directive|define
name|STNC_GEN
parameter_list|(
name|tp
parameter_list|,
name|o
parameter_list|)
define|\
value|static __inline void						\ 	o ## _nc(caddr_t va, int asi, tp val)				\ 	{								\ 		__asm __volatile("wr %2, 0, %%asi;" #o " %0, [%1] %%asi"\ 		    : : "r" (val), "r" (va), "r" (asi));		\ 	}
end_define

begin_expr_stmt
name|STNC_GEN
argument_list|(
name|u_char
argument_list|,
name|stba
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STNC_GEN
argument_list|(
name|u_short
argument_list|,
name|stha
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STNC_GEN
argument_list|(
name|u_int
argument_list|,
name|stwa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STNC_GEN
argument_list|(
name|u_long
argument_list|,
name|stxa
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ST_GENERIC
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|val
parameter_list|,
name|op
parameter_list|)
define|\
value|__asm __volatile(#op " %0, [%1] %2"				\ 	    : : "r" (val), "r" (va), "n" (asi));			\  #define	stba(va, asi, val)	ST_GENERIC(va, asi, val, stba)
end_define

begin_define
define|#
directive|define
name|stha
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|val
parameter_list|)
value|ST_GENERIC(va, asi, val, stha)
end_define

begin_define
define|#
directive|define
name|stwa
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|val
parameter_list|)
value|ST_GENERIC(va, asi, val, stwa)
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
value|ST_GENERIC(va, asi, val, stxa)
end_define

begin_comment
comment|/*  * Attempt to read from addr, val.  If a Data Access Error trap happens,  * they return -1 and the contents of val is undefined.  A return of 0  * means no trap happened, and the contents of val is valid.  */
end_comment

begin_function_decl
name|int
name|fasword8
parameter_list|(
name|u_long
name|asi
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fasword16
parameter_list|(
name|u_long
name|asi
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uint16_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fasword32
parameter_list|(
name|u_long
name|asi
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|membar
parameter_list|(
name|mask
parameter_list|)
value|do {						\ 	__asm __volatile("membar %0" : : "n" (mask) : "memory");	\ } while (0)
end_define

begin_define
define|#
directive|define
name|rd
parameter_list|(
name|name
parameter_list|)
value|({							\ 	uint64_t __sr;							\ 	__asm __volatile("rd %%" #name ", %0" : "=r" (__sr) :);		\ 	__sr;								\ })
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
name|xorval
parameter_list|)
value|do {					\ 	__asm __volatile("wr %0, %1, %%" #name				\ 	    : : "r" (val), "rI" (xorval));				\ } while (0)
end_define

begin_define
define|#
directive|define
name|rdpr
parameter_list|(
name|name
parameter_list|)
value|({							\ 	uint64_t __pr;							\ 	__asm __volatile("rdpr %%" #name", %0" : "=r" (__pr) :);	\ 	__pr;								\ })
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
name|xorval
parameter_list|)
value|do {					\ 	__asm __volatile("wrpr %0, %1, %%" #name			\ 	    : : "r" (val), "rI" (xorval));				\ } while (0)
end_define

begin_comment
comment|/*  * Trick GAS/GCC into compiling access to TICK/(S)TICK_COMPARE independently  * of the selected instruction set.  */
end_comment

begin_define
define|#
directive|define
name|rdtickcmpr
parameter_list|()
value|rd(asr23)
end_define

begin_define
define|#
directive|define
name|rdstick
parameter_list|()
value|rd(asr24)
end_define

begin_define
define|#
directive|define
name|rdstickcmpr
parameter_list|()
value|rd(asr25)
end_define

begin_define
define|#
directive|define
name|wrtickcmpr
parameter_list|(
name|val
parameter_list|,
name|xorval
parameter_list|)
value|wr(asr23, (val), (xorval))
end_define

begin_define
define|#
directive|define
name|wrstick
parameter_list|(
name|val
parameter_list|,
name|xorval
parameter_list|)
value|wr(asr24, (val), (xorval))
end_define

begin_define
define|#
directive|define
name|wrstickcmpr
parameter_list|(
name|val
parameter_list|,
name|xorval
parameter_list|)
value|wr(asr25, (val), (xorval))
end_define

begin_comment
comment|/*  * Macro intended to be used instead of wr(asr23, val, xorval) for writing to  * the TICK_COMPARE register in order to avoid a bug in BlackBird CPUs that  * can cause these writes to fail under certain conditions which in turn  * causes the hardclock to stop.  The workaround is to read the TICK_COMPARE  * register back immediately after writing to it with these two instructions  * aligned to a quadword boundary in order to ensure that I$ misses won't  * split them up.  */
end_comment

begin_define
define|#
directive|define
name|wrtickcmpr_bbwar
parameter_list|(
name|val
parameter_list|,
name|xorval
parameter_list|)
value|({				\ 	__asm __volatile(						\ 	"	ba,pt	%%xcc, 1f ;		"			\ 	"	 nop	 ;			"			\ 	"	.align	128 ;			"			\ 	"1:	wr	%0, %1, %%asr23 ;	"			\ 	"	rd	%%asr23, %%g0 ;		"			\ 	: : "r" (val), "rI" (xorval));					\ })
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
asm|__asm __volatile("ta %%xcc, 1" : :);
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|intr_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|s
decl_stmt|;
name|s
operator|=
name|rdpr
argument_list|(
name|pstate
argument_list|)
expr_stmt|;
name|wrpr
argument_list|(
name|pstate
argument_list|,
name|s
operator|&
operator|~
name|PSTATE_IE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|intr_restore
parameter_list|(
name|s
parameter_list|)
value|wrpr(pstate, (s), 0)
end_define

begin_comment
comment|/*  * In some places, it is required that the store is directly followed by a  * membar #Sync.  Don't trust the compiler to not insert instructions in  * between.  We also need to disable interrupts completely.  */
end_comment

begin_define
define|#
directive|define
name|stxa_sync
parameter_list|(
name|va
parameter_list|,
name|asi
parameter_list|,
name|val
parameter_list|)
value|do {					\ 	register_t s;							\ 	s = intr_disable();						\ 	__asm __volatile("stxa %0, [%1] %2; membar #Sync"		\ 	    : : "r" (val), "r" (va), "n" (asi));			\ 	intr_restore(s);						\ } while (0)
end_define

begin_function_decl
name|void
name|ascopy
parameter_list|(
name|u_long
name|asi
parameter_list|,
name|vm_offset_t
name|src
parameter_list|,
name|vm_offset_t
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ascopyfrom
parameter_list|(
name|u_long
name|sasi
parameter_list|,
name|vm_offset_t
name|src
parameter_list|,
name|caddr_t
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ascopyto
parameter_list|(
name|caddr_t
name|src
parameter_list|,
name|u_long
name|dasi
parameter_list|,
name|vm_offset_t
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aszero
parameter_list|(
name|u_long
name|asi
parameter_list|,
name|vm_offset_t
name|dst
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Ultrasparc II doesn't implement popc in hardware.  */
end_comment

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

begin_undef
undef|#
directive|undef
name|LDNC_GEN
end_undef

begin_undef
undef|#
directive|undef
name|STNC_GEN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPUFUNC_H_ */
end_comment

end_unit

