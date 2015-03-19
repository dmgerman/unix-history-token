begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2011 Robert N. M. Watson  * Copyright (c) 2011 Jonathan Anderson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Test that various sysctls are (and aren't) available on capability mode.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/capsicum.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"cap_test.h"
end_include

begin_comment
comment|/*  * Certain sysctls are permitted in capability mode, but most are not.  Test  * for the ones that should be, and try one or two that shouldn't.  */
end_comment

begin_function
name|int
name|test_sysctl
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|oid
index|[
literal|2
index|]
decl_stmt|;
name|int
name|success
init|=
name|PASSED
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|oid
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|oid
index|[
literal|1
index|]
operator|=
name|KERN_OSRELDATE
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|CHECK
argument_list|(
name|sysctl
argument_list|(
name|oid
argument_list|,
literal|2
argument_list|,
operator|&
name|i
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|success
operator|)
return|;
block|}
end_function

end_unit

