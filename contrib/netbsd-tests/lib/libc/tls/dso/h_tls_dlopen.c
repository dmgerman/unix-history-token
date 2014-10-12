begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: h_tls_dlopen.c,v 1.5 2013/10/21 19:14:16 joerg Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Joerg Sonnenberger.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: h_tls_dlopen.c,v 1.5 2013/10/21 19:14:16 joerg Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/tls.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__HAVE_NO___THREAD
end_ifdef

begin_define
define|#
directive|define
name|__thread
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|var1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
name|var2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__thread
name|int
modifier|*
name|var3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|var5
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|__thread
name|pid_t
function_decl|(
modifier|*
name|local_var
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|getpid
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testf_dso_helper
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testf_dso_helper
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|var1
operator|=
name|x
expr_stmt|;
name|var2
operator|=
name|y
expr_stmt|;
name|var3
operator|=
operator|&
name|optind
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|local_var
argument_list|,
name|getpid
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

