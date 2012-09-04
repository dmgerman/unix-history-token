begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Automated Testing Framework (atf)  *  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"atf-c/error.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|pass
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
literal|"An empty test case that always passes"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|fail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|fail
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
literal|"An empty test case that always fails"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fail
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_fail
argument_list|(
literal|"On purpose"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|skip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|skip
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
literal|"An empty test case that is always "
literal|"skipped"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|skip
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_skip
argument_list|(
literal|"By design"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
expr|default
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|default
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
literal|"A test case that passes without "
literal|"explicitly stating it"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|default
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{ }
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
name|pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fail
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|skip
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
expr|default
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

