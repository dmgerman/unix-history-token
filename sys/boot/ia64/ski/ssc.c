begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"libski.h"
end_include

begin_comment
comment|/*  * Ugh... Work around a bug in the Linux version of ski for SSC_GET_RTC. The  * PSR.dt register is not preserved properly and causes further memory  * references to be done without translation. All we need to do is preserve  * PSR.dt across the SSC call. We do this by saving and restoring psr.l  * completely.  */
end_comment

begin_function
name|u_int64_t
name|ssc
parameter_list|(
name|u_int64_t
name|in0
parameter_list|,
name|u_int64_t
name|in1
parameter_list|,
name|u_int64_t
name|in2
parameter_list|,
name|u_int64_t
name|in3
parameter_list|,
name|int
name|which
parameter_list|)
block|{
specifier|register
name|u_int64_t
name|psr
decl_stmt|;
specifier|register
name|u_int64_t
name|ret0
asm|__asm("r8");
asm|__asm __volatile("mov %0=psr;;" : "=r"(psr));
asm|__asm __volatile("mov r15=%1\n\t"
literal|"break 0x80000;;"
operator|:
literal|"=r"
operator|(
name|ret0
operator|)
operator|:
literal|"r"
operator|(
name|which
operator|)
operator|,
literal|"r"
operator|(
name|in0
operator|)
operator|,
literal|"r"
operator|(
name|in1
operator|)
operator|,
literal|"r"
operator|(
name|in2
operator|)
operator|,
literal|"r"
operator|(
name|in3
operator|)
block|)
function|;
end_function

begin_asm
asm|__asm __volatile("mov psr.l=%0;; srlz.d" :: "r"(psr));
end_asm

begin_return
return|return
name|ret0
return|;
end_return

unit|}
end_unit

