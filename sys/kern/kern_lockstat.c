begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008-2009 Stacey Son<sson@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Backend for the lock tracing (lockstat) kernel support. This is required   * to allow a module to load even though DTrace kernel support may not be   * present.   *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/lockstat.h>
end_include

begin_comment
comment|/*  * The following must match the type definition of dtrace_probe.  It is    * defined this way to avoid having to rely on CDDL code.  */
end_comment

begin_decl_stmt
name|uint32_t
name|lockstat_probemap
index|[
name|LS_NPROBES
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|lockstat_probe_func
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|uint64_t
name|lockstat_nsecs
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|bintime
name|bt
decl_stmt|;
name|uint64_t
name|ns
decl_stmt|;
name|binuptime
argument_list|(
operator|&
name|bt
argument_list|)
expr_stmt|;
name|ns
operator|=
name|bt
operator|.
name|sec
operator|*
operator|(
name|uint64_t
operator|)
literal|1000000000
expr_stmt|;
name|ns
operator|+=
operator|(
operator|(
name|uint64_t
operator|)
literal|1000000000
operator|*
call|(
name|uint32_t
call|)
argument_list|(
name|bt
operator|.
name|frac
operator|>>
literal|32
argument_list|)
operator|)
operator|>>
literal|32
expr_stmt|;
return|return
operator|(
name|ns
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KDTRACE_HOOKS */
end_comment

end_unit

