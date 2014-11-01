begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"atf-c/tp.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|getopt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|getopt
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
literal|"Checks if getopt(3) global state is "
literal|"reset by the test program driver so that test cases can use "
literal|"getopt(3) again"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|getopt
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
comment|/* Provide an option that is unknown to the test program driver and      * one that is, together with an argument that would be swallowed by      * the test program option if it were recognized. */
name|int
name|argc
init|=
literal|4
decl_stmt|;
name|char
name|arg1
index|[]
init|=
literal|"progname"
decl_stmt|;
name|char
name|arg2
index|[]
init|=
literal|"-Z"
decl_stmt|;
name|char
name|arg3
index|[]
init|=
literal|"-s"
decl_stmt|;
name|char
name|arg4
index|[]
init|=
literal|"foo"
decl_stmt|;
name|char
modifier|*
specifier|const
name|argv
index|[]
init|=
block|{
name|arg1
block|,
name|arg2
block|,
name|arg3
block|,
name|arg4
block|,
name|NULL
block|}
decl_stmt|;
name|int
name|ch
decl_stmt|;
name|bool
name|zflag
decl_stmt|;
comment|/* Given that this obviously is a test program, and that we used the      * same driver to start, we can test getopt(3) right here without doing      * any fancy stuff. */
name|zflag
operator|=
name|false
expr_stmt|;
while|while
condition|(
operator|(
name|ch
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|":Z"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|'Z'
case|:
name|zflag
operator|=
name|true
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
if|if
condition|(
name|optopt
operator|!=
literal|'s'
condition|)
name|atf_tc_fail
argument_list|(
literal|"Unexpected unknown option -%c found"
argument_list|,
name|optopt
argument_list|)
expr_stmt|;
block|}
block|}
name|ATF_REQUIRE
argument_list|(
name|zflag
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_EQ_MSG
argument_list|(
literal|1
argument_list|,
name|argc
operator|-
name|optind
argument_list|,
literal|"Invalid number of arguments left "
literal|"after the call to getopt(3)"
argument_list|)
expr_stmt|;
name|ATF_CHECK_STREQ_MSG
argument_list|(
literal|"foo"
argument_list|,
name|argv
index|[
name|optind
index|]
argument_list|,
literal|"The non-option argument is "
literal|"invalid"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Main.  * --------------------------------------------------------------------- */
end_comment

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
name|getopt
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

