begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_dlerror-false.c,v 1.2 2017/01/13 21:30:42 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2009 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<link_elf.h>
end_include

begin_include
include|#
directive|include
file|"h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|rtld_dlerror_false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|rtld_dlerror_false
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
literal|"error set by dlopen persists past a successful dlopen call"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|rtld_dlerror_false
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|void
modifier|*
name|handle
decl_stmt|,
modifier|*
name|sym
decl_stmt|;
name|char
modifier|*
name|error
decl_stmt|;
comment|/* 	 *  	 * Test for dlerror() being set by a successful library open. 	 * Requires that the rpath be set to something that does not 	 * include libm.so. 	 */
name|handle
operator|=
name|dlopen
argument_list|(
literal|"libm.so"
argument_list|,
name|RTLD_LAZY
argument_list|)
expr_stmt|;
name|error
operator|=
name|dlerror
argument_list|()
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|error
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|handle
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|sym
operator|=
name|dlsym
argument_list|(
name|handle
argument_list|,
literal|"sin"
argument_list|)
expr_stmt|;
name|error
operator|=
name|dlerror
argument_list|()
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|sym
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|error
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|dlclose
argument_list|(
name|handle
argument_list|)
expr_stmt|;
name|error
operator|=
name|dlerror
argument_list|()
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|error
operator|==
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
name|rtld_dlerror_false
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

