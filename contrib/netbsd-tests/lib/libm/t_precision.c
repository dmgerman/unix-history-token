begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_precision.c,v 1.3 2016/08/27 10:07:05 christos Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Joerg Sonnenberger.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_precision.c,v 1.3 2016/08/27 10:07:05 christos Exp $"
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
file|<float.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|t_precision
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|t_precision
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
literal|"Basic precision test for double and long double"
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|volatile
name|double
name|x
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__HAVE_LONG_DOUBLE
end_if

begin_decl_stmt
specifier|volatile
name|long
name|double
name|y
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|t_precision
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|x
operator|+=
name|DBL_EPSILON
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|x
operator|!=
literal|1.0
argument_list|)
expr_stmt|;
name|x
operator|-=
literal|1
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|x
operator|==
name|DBL_EPSILON
argument_list|)
expr_stmt|;
name|x
operator|=
literal|2
expr_stmt|;
name|x
operator|+=
name|DBL_EPSILON
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|x
operator|==
literal|2.0
argument_list|)
expr_stmt|;
if|#
directive|if
name|__HAVE_LONG_DOUBLE
name|y
operator|+=
name|LDBL_EPSILON
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|y
operator|!=
literal|1.0L
argument_list|)
expr_stmt|;
name|y
operator|-=
literal|1
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|y
operator|==
name|LDBL_EPSILON
argument_list|)
expr_stmt|;
name|y
operator|=
literal|2
expr_stmt|;
name|y
operator|+=
name|LDBL_EPSILON
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|y
operator|==
literal|2.0L
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|__FreeBSD__
ifdef|#
directive|ifdef
name|__i386__
name|atf_tc_expect_fail
argument_list|(
literal|"the __HAVE_LONG_DOUBLE checks fail on i386"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|t_precision
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

