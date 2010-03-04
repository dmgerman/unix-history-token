begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995-1997 Wolfgang Solfrank.  * Copyright (C) 1995-1997 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: cpu.h,v 1.11 2000/05/26 21:19:53 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_comment
comment|/*  * CPU Feature Attributes  *  * These are defined in the PowerPC ELF ABI for the AT_HWCAP vector,  * and are exported to userland via the machdep.cpu_features  * sysctl.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cpu_features
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PPC_FEATURE_32
value|0x80000000
end_define

begin_comment
comment|/* Always true */
end_comment

begin_define
define|#
directive|define
name|PPC_FEATURE_64
value|0x40000000
end_define

begin_comment
comment|/* Defined on a 64-bit CPU */
end_comment

begin_define
define|#
directive|define
name|PPC_FEATURE_HAS_ALTIVEC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PPC_FEATURE_HAS_FPU
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PPC_FEATURE_HAS_MMU
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PPC_FEATURE_UNIFIED_CACHE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PPC_FEATURE_BITMASK
define|\
value|"\20"								\ 	"\040PPC32\037PPC64\035ALTIVEC\034FPU\033MMU\031UNIFIEDCACHE"
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|frame
parameter_list|)
value|(((frame)->srr1& PSL_PR) != 0)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|frame
parameter_list|)
value|((frame)->srr0)
end_define

begin_define
define|#
directive|define
name|cpu_swapout
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cpu_number
parameter_list|()
value|0
end_define

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CACHELINE
value|1
end_define

begin_function
specifier|static
name|__inline
name|u_int64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|_upper
decl_stmt|,
name|_lower
decl_stmt|;
name|u_int64_t
name|_time
decl_stmt|;
asm|__asm __volatile(
literal|"mftb %0\n"
literal|"mftbu %1"
operator|:
literal|"=r"
operator|(
name|_lower
operator|)
operator|,
literal|"=r"
operator|(
name|_upper
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|_time
operator|=
operator|(
name|u_int64_t
operator|)
name|_upper
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_time
operator|=
operator|(
name|_time
operator|<<
literal|32
operator|)
operator|+
name|_lower
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|_time
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->fixreg[1])
end_define

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_decl_stmt
unit|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX the following should not be here. */
end_comment

begin_function_decl
name|void
name|savectx
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kcopy
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPU_H_ */
end_comment

end_unit

