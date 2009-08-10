begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpu.h,v 1.70 2003/01/17 23:36:08 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *	@(#)cpu.h	8.4 (Berkeley) 1/4/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPUINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_CPUINFO_H_
end_define

begin_comment
comment|/*  * Exported definitions unique to NetBSD/mips cpu support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|mips_cpuinfo
block|{
name|u_int8_t
name|cpu_vendor
decl_stmt|;
name|u_int8_t
name|cpu_rev
decl_stmt|;
name|u_int8_t
name|cpu_impl
decl_stmt|;
name|u_int8_t
name|tlb_type
decl_stmt|;
name|u_int16_t
name|tlb_nentries
decl_stmt|;
name|u_int8_t
name|icache_virtual
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|ic_size
decl_stmt|;
name|u_int8_t
name|ic_linesize
decl_stmt|;
name|u_int8_t
name|ic_nways
decl_stmt|;
name|u_int16_t
name|ic_nsets
decl_stmt|;
name|u_int32_t
name|dc_size
decl_stmt|;
name|u_int8_t
name|dc_linesize
decl_stmt|;
name|u_int8_t
name|dc_nways
decl_stmt|;
name|u_int16_t
name|dc_nsets
decl_stmt|;
block|}
name|l1
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* TODO: Merge above structure with NetBSD's below. */
end_comment

begin_struct
struct|struct
name|cpu_info
block|{
ifdef|#
directive|ifdef
name|notyet
name|struct
name|schedstate_percpu
name|ci_schedstate
decl_stmt|;
comment|/* scheduler state */
endif|#
directive|endif
name|u_long
name|ci_cpu_freq
decl_stmt|;
comment|/* CPU frequency */
name|u_long
name|ci_cycles_per_hz
decl_stmt|;
comment|/* CPU freq / hz */
name|u_long
name|ci_divisor_delay
decl_stmt|;
comment|/* for delay/DELAY */
name|u_long
name|ci_divisor_recip
decl_stmt|;
comment|/* scaled reciprocal of previous; 					   see below */
if|#
directive|if
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
operator|||
name|defined
argument_list|(
name|LOCKDEBUG
argument_list|)
name|u_long
name|ci_spin_locks
decl_stmt|;
comment|/* # of spin locks held */
name|u_long
name|ci_simple_locks
decl_stmt|;
comment|/* # of simple locks held */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * To implement a more accurate microtime using the CP0 COUNT register  * we need to divide that register by the number of cycles per MHz.  * But...  *  * DIV and DIVU are expensive on MIPS (eg 75 clocks on the R4000).  MULT  * and MULTU are only 12 clocks on the same CPU.  *  * The strategy we use is to calculate the reciprical of cycles per MHz,  * scaled by 1<<32.  Then we can simply issue a MULTU and pluck of the  * HI register and have the results of the division.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SET_CI_RECIPRICAL
parameter_list|(
name|cpu
parameter_list|)
define|\
value|do {									\ 	KASSERT((cpu)->ci_divisor_delay != 0, ("divisor delay"));		\ 	(cpu)->ci_divisor_recip = 0x100000000ULL / (cpu)->ci_divisor_delay; \ } while (0)
end_define

begin_define
define|#
directive|define
name|MIPS_COUNT_TO_MHZ
parameter_list|(
name|cpu
parameter_list|,
name|count
parameter_list|,
name|res
parameter_list|)
define|\
value|__asm __volatile ("multu %1,%2 ; mfhi %0"			\ 	    : "=r"((res)) : "r"((count)), "r"((cpu)->ci_divisor_recip))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|cpu_info
name|cpu_info_store
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|curcpu
parameter_list|()
value|(&cpu_info_store)
end_define

begin_define
define|#
directive|define
name|cpu_number
parameter_list|()
value|(0)
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
comment|/* !LOCORE */
end_comment

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
comment|/* _CPUINFO_H_ */
end_comment

end_unit

