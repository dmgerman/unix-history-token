begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_tls_static.c,v 1.2 2012/01/17 20:34:57 joerg Exp $	*/
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
literal|"$NetBSD: t_tls_static.c,v 1.2 2012/01/17 20:34:57 joerg Exp $"
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
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/tls.h>
end_include

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

begin_expr_stmt
name|ATF_TC
argument_list|(
name|t_tls_static
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|t_tls_static
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Test (un)initialized TLS variables in static binaries"
argument_list|)
expr_stmt|;
block|}
end_block

begin_function_decl
name|void
name|testf_helper
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__thread
name|int
name|var1
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|int
name|var2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
modifier|*
name|testf
parameter_list|(
name|void
modifier|*
name|dummy
parameter_list|)
block|{
name|ATF_CHECK_EQ
argument_list|(
name|var1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|var2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|testf_helper
argument_list|()
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|var1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ
argument_list|(
name|var2
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|t_tls_static
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|pthread_t
name|t
decl_stmt|;
ifdef|#
directive|ifdef
name|__HAVE_NO___THREAD
name|atf_tc_skip
argument_list|(
literal|"no TLS support on this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|testf
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
literal|0
argument_list|,
name|testf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
literal|0
argument_list|,
name|testf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|t_tls_static
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

