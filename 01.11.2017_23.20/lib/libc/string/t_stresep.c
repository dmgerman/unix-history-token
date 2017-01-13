begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_stresep.c,v 1.3 2013/02/15 23:56:32 christos Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
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
file|<string.h>
end_include

begin_define
define|#
directive|define
name|expect
parameter_list|(
name|a
parameter_list|)
define|\
value|if ((p = stresep(&q, " ", '\\')) == NULL || strcmp(p, a)) {	\ 		fprintf(stderr, "failed on line %d: %s != %s\n",	\ 		    __LINE__, p, a);					\ 		atf_tc_fail("Check stderr for test id/line");		\ 	}
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|stresep_basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|stresep_basic
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
literal|"Test stresep results"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|stresep_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|brkstr
index|[]
init|=
literal|"foo\\ \\ bar baz bar\\ foo\\  bar\\ \\ foo \\ \\ \\ "
literal|"baz bar\\ \\ "
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
init|=
name|brkstr
decl_stmt|;
name|expect
argument_list|(
literal|"foo  bar"
argument_list|)
expr_stmt|;
name|expect
argument_list|(
literal|"baz"
argument_list|)
expr_stmt|;
name|expect
argument_list|(
literal|"bar foo "
argument_list|)
expr_stmt|;
name|expect
argument_list|(
literal|"bar  foo"
argument_list|)
expr_stmt|;
name|expect
argument_list|(
literal|"   baz"
argument_list|)
expr_stmt|;
name|expect
argument_list|(
literal|"bar  "
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
name|stresep_basic
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

