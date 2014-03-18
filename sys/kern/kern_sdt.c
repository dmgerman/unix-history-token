begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2006-2008 John Birrell<jb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_kdtrace.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/sdt.h>
end_include

begin_expr_stmt
name|SDT_PROVIDER_DEFINE
argument_list|(
name|sdt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Hook for the DTrace probe function. The SDT provider will set this to  * dtrace_probe() when it loads.  */
end_comment

begin_decl_stmt
name|sdt_probe_func_t
name|sdt_probe_func
init|=
name|sdt_probe_stub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is a stub for probe calls in case kernel DTrace support isn't  * enabled. It should never get called because there is no DTrace support  * to enable it.  */
end_comment

begin_function
name|void
name|sdt_probe_stub
parameter_list|(
name|uint32_t
name|id
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
block|{
name|printf
argument_list|(
literal|"sdt_probe_stub: unexpectedly called\n"
argument_list|)
expr_stmt|;
name|kdb_backtrace
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

