begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995-1997 Wolfgang Solfrank.  * Copyright (C) 1995-1997 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: cpu.h,v 1.11 2000/05/26 21:19:53 thorpej Exp $  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|frame
parameter_list|)
value|(((frame)->srr1& PSL_PR) != 0)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|frame
parameter_list|)
value|((frame)->pri == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|frame
parameter_list|)
value|((frame)->srr0)
end_define

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|frame
parameter_list|)
value|((frame)->depth> 0)
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

begin_function_decl
name|void
name|delay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|delay(n)
end_define

begin_decl_stmt
specifier|extern
name|char
name|bootpath
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CACHELINESIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|__syncicache
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CACHELINE
value|1
end_define

begin_define
define|#
directive|define
name|CPU_MAXID
value|2
end_define

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "cachelinesize", CTLTYPE_INT }, \ }
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
name|upper
decl_stmt|,
name|lower
decl_stmt|;
name|u_int64_t
name|time
decl_stmt|;
asm|__asm __volatile(
literal|"mftb %0\n"
literal|"mftbu %1"
operator|:
literal|"=r"
operator|(
name|lower
operator|)
operator|,
literal|"=r"
operator|(
name|upper
operator|)
block|)
function|;
end_function

begin_expr_stmt
name|time
operator|=
operator|(
name|u_int64_t
operator|)
name|upper
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|time
operator|=
operator|(
name|time
operator|<<
literal|32
operator|)
operator|+
name|lower
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|time
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

begin_decl_stmt
unit|void
name|savectx
name|__P
argument_list|(
operator|(
expr|struct
name|pcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
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

