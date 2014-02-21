begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: pio.h,v 1.2 1998/09/15 10:50:12 pefo Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002-2004 Juli Mallett.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995-1999 Per Fogelstrom.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Per Fogelstrom.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	JNPR: cpufunc.h,v 1.5 2007/08/09 11:23:32 katta  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuregs.h>
end_include

begin_comment
comment|/*   * These functions are required by user-land atomi ops  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|mips_barrier
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|CPU_CNMIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_RMI
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_NLM
argument_list|)
name|__compiler_membar
argument_list|()
expr_stmt|;
else|#
directive|else
asm|__asm __volatile (".set noreorder\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|"nop\n\t"
literal|".set reorder\n\t"
operator|:
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
unit|}  static
name|__inline
name|void
name|mips_cp0_sync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile (__XSTRING(COP0_SYNC));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|mips_wbflush
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|CPU_CNMIPS
argument_list|)
asm|__asm __volatile (".set noreorder\n\t"
literal|"syncw\n\t"
literal|".set reorder\n"
operator|:
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_else
else|#
directive|else
end_else

begin_asm
asm|__asm __volatile ("sync" : : : "memory");
end_asm

begin_expr_stmt
name|mips_barrier
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX  * It would be nice to add variants that read/write register_t, to avoid some  * ABI checks.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_RW64_COP0
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
define|\
value|static __inline uint64_t					\ mips_rd_ ## n (void)						\ {								\ 	int v0;							\ 	__asm __volatile ("dmfc0 %[v0], $"__XSTRING(r)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n (uint64_t a0)					\ {								\ 	__asm __volatile ("dmtc0 %[a0], $"__XSTRING(r)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_define
define|#
directive|define
name|MIPS_RW64_COP0_SEL
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|static __inline uint64_t					\ mips_rd_ ## n(void)						\ {								\ 	int v0;							\ 	__asm __volatile ("dmfc0 %[v0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n(uint64_t a0)					\ {								\ 	__asm __volatile ("dmtc0 %[a0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_expr_stmt
unit|MIPS_RW64_COP0
operator|(
name|excpc
operator|,
name|MIPS_COP_0_EXC_PC
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0
argument_list|(
name|entryhi
argument_list|,
name|MIPS_COP_0_TLB_HI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0
argument_list|(
name|pagemask
argument_list|,
name|MIPS_COP_0_TLB_PG_MASK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_CNMIPS
end_ifdef

begin_expr_stmt
name|MIPS_RW64_COP0_SEL
argument_list|(
name|cvmcount
argument_list|,
name|MIPS_COP_0_COUNT
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0_SEL
argument_list|(
name|cvmctl
argument_list|,
name|MIPS_COP_0_COUNT
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0_SEL
argument_list|(
name|cvmmemctl
argument_list|,
name|MIPS_COP_0_COMPARE
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0_SEL
argument_list|(
name|icache_err
argument_list|,
name|MIPS_COP_0_CACHE_ERR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0_SEL
argument_list|(
name|dcache_err
argument_list|,
name|MIPS_COP_0_CACHE_ERR
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/* PHYSADDR_64_BIT */
end_comment

begin_expr_stmt
name|MIPS_RW64_COP0
argument_list|(
name|entrylo0
argument_list|,
name|MIPS_COP_0_TLB_LO0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW64_COP0
argument_list|(
name|entrylo1
argument_list|,
name|MIPS_COP_0_TLB_LO1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MIPS_RW64_COP0
argument_list|(
name|xcontext
argument_list|,
name|MIPS_COP_0_TLB_XCONTEXT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|MIPS_RW64_COP0
end_undef

begin_undef
undef|#
directive|undef
name|MIPS_RW64_COP0_SEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_RW32_COP0
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
define|\
value|static __inline uint32_t					\ mips_rd_ ## n (void)						\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $"__XSTRING(r)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n (uint32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $"__XSTRING(r)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_define
define|#
directive|define
name|MIPS_RW32_COP0_SEL
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|static __inline uint32_t					\ mips_rd_ ## n(void)						\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			  : [v0] "=&r"(v0));			\ 	mips_barrier();						\ 	return (v0);						\ }								\ static __inline void						\ mips_wr_ ## n(uint32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $"__XSTRING(r)", "__XSTRING(s)";"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\ 	mips_barrier();						\ } struct __hack
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_CNMIPS
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|mips_sync_icache
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile (
literal|".set push\n"
literal|".set mips64\n"
literal|".word 0x041f0000\n"
comment|/* xxx ICACHE */
literal|"nop\n"
literal|".set pop\n"
operator|:
operator|:
block|)
function|;
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|MIPS_RW32_COP0
operator|(
name|compare
operator|,
name|MIPS_COP_0_COMPARE
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|config
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config1
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config2
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config3
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_CNMIPS
end_ifdef

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config4
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BERI_LARGE_TLB
end_ifdef

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config5
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_NLM
argument_list|)
operator|||
name|defined
argument_list|(
name|BERI_LARGE_TLB
argument_list|)
end_if

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config6
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_NLM
end_ifdef

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|config7
argument_list|,
name|MIPS_COP_0_CONFIG
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|count
argument_list|,
name|MIPS_COP_0_COUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|index
argument_list|,
name|MIPS_COP_0_TLB_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|wired
argument_list|,
name|MIPS_COP_0_TLB_WIRED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|cause
argument_list|,
name|MIPS_COP_0_CAUSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|excpc
argument_list|,
name|MIPS_COP_0_EXC_PC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|status
argument_list|,
name|MIPS_COP_0_STATUS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX: Some of these registers are specific to MIPS32. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|entryhi
argument_list|,
name|MIPS_COP_0_TLB_HI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|pagemask
argument_list|,
name|MIPS_COP_0_TLB_PG_MASK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_NLM
end_ifdef

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|pagegrain
argument_list|,
name|MIPS_COP_0_TLB_PG_MASK
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_comment
comment|/* !PHYSADDR_64_BIT */
end_comment

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|entrylo0
argument_list|,
name|MIPS_COP_0_TLB_LO0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|entrylo1
argument_list|,
name|MIPS_COP_0_TLB_LO1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|prid
argument_list|,
name|MIPS_COP_0_PRID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX 64-bit?  */
end_comment

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|ebase
argument_list|,
name|MIPS_COP_0_PRID
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|watchlo
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchlo1
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchlo2
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchlo3
argument_list|,
name|MIPS_COP_0_WATCH_LO
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0
argument_list|(
name|watchhi
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchhi1
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchhi2
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|watchhi3
argument_list|,
name|MIPS_COP_0_WATCH_HI
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|perfcnt0
argument_list|,
name|MIPS_COP_0_PERFCNT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|perfcnt1
argument_list|,
name|MIPS_COP_0_PERFCNT
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|perfcnt2
argument_list|,
name|MIPS_COP_0_PERFCNT
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MIPS_RW32_COP0_SEL
argument_list|(
name|perfcnt3
argument_list|,
name|MIPS_COP_0_PERFCNT
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|MIPS_RW32_COP0
end_undef

begin_undef
undef|#
directive|undef
name|MIPS_RW32_COP0_SEL
end_undef

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
name|mips_rd_status
argument_list|()
expr_stmt|;
name|mips_wr_status
argument_list|(
name|s
operator|&
operator|~
name|MIPS_SR_INT_IE
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|&
name|MIPS_SR_INT_IE
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|intr_enable
parameter_list|(
name|void
parameter_list|)
block|{
name|register_t
name|s
decl_stmt|;
name|s
operator|=
name|mips_rd_status
argument_list|()
expr_stmt|;
name|mips_wr_status
argument_list|(
name|s
operator||
name|MIPS_SR_INT_IE
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|intr_restore
parameter_list|(
name|register_t
name|ie
parameter_list|)
block|{
if|if
condition|(
name|ie
operator|==
name|MIPS_SR_INT_IE
condition|)
block|{
name|intr_enable
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|set_intr_mask
parameter_list|(
name|uint32_t
name|mask
parameter_list|)
block|{
name|uint32_t
name|ostatus
decl_stmt|;
name|ostatus
operator|=
name|mips_rd_status
argument_list|()
expr_stmt|;
name|mask
operator|=
operator|(
name|ostatus
operator|&
operator|~
name|MIPS_SR_INT_MASK
operator|)
operator||
operator|(
name|mask
operator|&
name|MIPS_SR_INT_MASK
operator|)
expr_stmt|;
name|mips_wr_status
argument_list|(
name|mask
argument_list|)
expr_stmt|;
return|return
operator|(
name|ostatus
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|get_intr_mask
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|mips_rd_status
argument_list|()
operator|&
name|MIPS_SR_INT_MASK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile ("break");
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_o32
argument_list|)
end_if

begin_define
define|#
directive|define
name|mips3_ld
parameter_list|(
name|a
parameter_list|)
value|(*(const volatile uint64_t *)(a))
end_define

begin_define
define|#
directive|define
name|mips3_sd
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|(*(volatile uint64_t *)(a) = (v))
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|uint64_t
name|mips3_ld
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mips3_sd
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|readb
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint8_t *) (va))
end_define

begin_define
define|#
directive|define
name|readw
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint16_t *) (va))
end_define

begin_define
define|#
directive|define
name|readl
parameter_list|(
name|va
parameter_list|)
value|(*(volatile uint32_t *) (va))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_o32
argument_list|)
end_if

begin_define
define|#
directive|define
name|readq
parameter_list|(
name|a
parameter_list|)
value|(*(volatile uint64_t *)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|writeb
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint8_t *) (va) = (d))
end_define

begin_define
define|#
directive|define
name|writew
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint16_t *) (va) = (d))
end_define

begin_define
define|#
directive|define
name|writel
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint32_t *) (va) = (d))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__mips_o32
argument_list|)
end_if

begin_define
define|#
directive|define
name|writeq
parameter_list|(
name|va
parameter_list|,
name|d
parameter_list|)
value|(*(volatile uint64_t *) (va) = (d))
end_define

begin_endif
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

