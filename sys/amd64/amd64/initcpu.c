begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) KATO Takenori, 1997, 1998.  *   * All rights reserved.  Unpublished rights reserved under the copyright  * laws of Japan.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_cpu.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/cputypes.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_function_decl
name|void
name|initializecpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|hw_instruction_sse
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|instruction_sse
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|hw_instruction_sse
argument_list|,
literal|0
argument_list|,
literal|"SIMD/MMX2 instructions available in CPU"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we 386, 386sx, 486, etc? */
end_comment

begin_decl_stmt
name|u_int
name|cpu_feature
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Feature flags */
end_comment

begin_decl_stmt
name|u_int
name|cpu_high
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highest arg to CPUID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stepping ID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_procinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* HyperThreading Info / Brand Index / CLFUSH */
end_comment

begin_decl_stmt
name|char
name|cpu_vendor
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CPU Origin code */
end_comment

begin_decl_stmt
name|u_int
name|cpu_fxsr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SSE enabled */
end_comment

begin_comment
comment|/*  * Initialize CR4 (Control register 4) to enable SSE instructions.  */
end_comment

begin_function
name|void
name|enable_sse
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_XMM
operator|)
operator|&&
operator|(
name|cpu_feature
operator|&
name|CPUID_FXSR
operator|)
condition|)
block|{
name|load_cr4
argument_list|(
name|rcr4
argument_list|()
operator||
name|CR4_FXSR
operator||
name|CR4_XMM
argument_list|)
expr_stmt|;
name|cpu_fxsr
operator|=
name|hw_instruction_sse
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|initializecpu
parameter_list|(
name|void
parameter_list|)
block|{
switch|switch
condition|(
name|cpu
condition|)
block|{
default|default:
break|break;
block|}
name|enable_sse
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

