begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Automated Testing Framework (atf)  *  * Copyright (c) 2007 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
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

begin_include
include|#
directive|include
file|"atf-c/detail/env.h"
end_include

begin_include
include|#
directive|include
file|"atf-c/detail/fs.h"
end_include

begin_include
include|#
directive|include
file|"atf-c/detail/test_helpers.h"
end_include

begin_include
include|#
directive|include
file|"atf-c/detail/text.h"
end_include

begin_comment
comment|/* ---------------------------------------------------------------------  * Auxiliary functions.  * --------------------------------------------------------------------- */
end_comment

begin_function
specifier|static
name|void
name|safe_remove
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
if|if
condition|(
name|unlink
argument_list|(
name|path
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail
argument_list|(
literal|"unlink(2) of %s failed"
argument_list|,
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|touch
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|int
name|fd
decl_stmt|;
name|fd
operator|=
name|open
argument_list|(
name|path
argument_list|,
name|O_WRONLY
operator||
name|O_TRUNC
operator||
name|O_CREAT
argument_list|,
literal|0644
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail
argument_list|(
literal|"Could not create file %s"
argument_list|,
name|path
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_cleanup".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC_WITH_CLEANUP
argument_list|(
name|cleanup_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cleanup_pass
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
literal|"Helper test case for the t_cleanup test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cleanup_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|touch
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_CLEANUP
argument_list|(
argument|cleanup_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|atf_tc_get_config_var_as_bool
argument_list|(
name|tc
argument_list|,
literal|"cleanup"
argument_list|)
condition|)
name|safe_remove
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITH_CLEANUP
argument_list|(
name|cleanup_fail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cleanup_fail
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
literal|"Helper test case for the t_cleanup test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cleanup_fail
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|touch
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"On purpose"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_CLEANUP
argument_list|(
argument|cleanup_fail
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|atf_tc_get_config_var_as_bool
argument_list|(
name|tc
argument_list|,
literal|"cleanup"
argument_list|)
condition|)
name|safe_remove
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITH_CLEANUP
argument_list|(
name|cleanup_skip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cleanup_skip
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
literal|"Helper test case for the t_cleanup test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cleanup_skip
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|touch
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
name|atf_tc_skip
argument_list|(
literal|"On purpose"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_CLEANUP
argument_list|(
argument|cleanup_skip
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|atf_tc_get_config_var_as_bool
argument_list|(
name|tc
argument_list|,
literal|"cleanup"
argument_list|)
condition|)
name|safe_remove
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITH_CLEANUP
argument_list|(
name|cleanup_curdir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cleanup_curdir
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
literal|"Helper test case for the t_cleanup test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cleanup_curdir
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|fopen
argument_list|(
literal|"oldvalue"
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
name|atf_tc_fail
argument_list|(
literal|"Failed to create oldvalue file"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|f
argument_list|,
literal|"1234"
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_CLEANUP
argument_list|(
argument|cleanup_curdir
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|fopen
argument_list|(
literal|"oldvalue"
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|!=
name|NULL
condition|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|fscanf
argument_list|(
name|f
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|i
argument_list|)
operator|!=
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Failed to read old value\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"Old value: %d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITH_CLEANUP
argument_list|(
name|cleanup_sigterm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cleanup_sigterm
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
literal|"Helper test case for the t_cleanup test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cleanup_sigterm
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|nofile
decl_stmt|;
name|touch
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGTERM
argument_list|)
expr_stmt|;
name|RE
argument_list|(
name|atf_text_format
argument_list|(
operator|&
name|nofile
argument_list|,
literal|"%s.no"
argument_list|,
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|touch
argument_list|(
name|nofile
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|nofile
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_CLEANUP
argument_list|(
argument|cleanup_sigterm
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|safe_remove
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"tmpfile"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_config".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC
argument_list|(
name|config_unset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|config_unset
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
literal|"Helper test case for the t_config test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|config_unset
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_REQUIRE
argument_list|(
operator|!
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|config_empty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|config_empty
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
literal|"Helper test case for the t_config test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|config_empty
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_REQUIRE
argument_list|(
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|strlen
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|config_value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|config_value
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
literal|"Helper test case for the t_config test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|config_value
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_REQUIRE
argument_list|(
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|strcmp
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|,
literal|"foo"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|config_multi_value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|config_multi_value
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
literal|"Helper test case for the t_config test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|config_multi_value
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|ATF_REQUIRE
argument_list|(
name|atf_tc_has_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|strcmp
argument_list|(
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"test"
argument_list|)
argument_list|,
literal|"foo bar"
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_expect".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_pass_and_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_pass_and_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_pass_but_fail_requirement
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_pass_but_fail_requirement
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"Some reason"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_pass_but_fail_check
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_pass_but_fail_check
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|atf_tc_fail_nonfatal
argument_list|(
literal|"Some reason"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_fail_and_fail_requirement
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_fail_and_fail_requirement
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_fail
argument_list|(
literal|"Fail %s"
argument_list|,
literal|"reason"
argument_list|)
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"The failure"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_fail_and_fail_check
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_fail_and_fail_check
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_fail
argument_list|(
literal|"Fail first"
argument_list|)
expr_stmt|;
name|atf_tc_fail_nonfatal
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|atf_tc_expect_fail
argument_list|(
literal|"And fail again"
argument_list|)
expr_stmt|;
name|atf_tc_fail_nonfatal
argument_list|(
literal|"def"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_fail_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_fail_but_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_fail
argument_list|(
literal|"Fail first"
argument_list|)
expr_stmt|;
name|atf_tc_fail_nonfatal
argument_list|(
literal|"abc"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|atf_tc_expect_fail
argument_list|(
literal|"Will not fail"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|atf_tc_expect_fail
argument_list|(
literal|"And fail again"
argument_list|)
expr_stmt|;
name|atf_tc_fail_nonfatal
argument_list|(
literal|"def"
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_exit_any_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_exit_any_and_exit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_exit
argument_list|(
operator|-
literal|1
argument_list|,
literal|"Call will exit"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_exit_code_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_exit_code_and_exit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_exit
argument_list|(
literal|123
argument_list|,
literal|"Call will exit"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|123
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_exit_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_exit_but_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_exit
argument_list|(
operator|-
literal|1
argument_list|,
literal|"Call won't exit"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_signal_any_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_signal_any_and_signal
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_signal
argument_list|(
operator|-
literal|1
argument_list|,
literal|"Call will signal"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGKILL
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_signal_no_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_signal_no_and_signal
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_signal
argument_list|(
name|SIGHUP
argument_list|,
literal|"Call will signal"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_signal_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_signal_but_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_signal
argument_list|(
operator|-
literal|1
argument_list|,
literal|"Call won't signal"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_death_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_death_and_exit
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_death
argument_list|(
literal|"Exit case"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|123
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_death_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_death_and_signal
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_death
argument_list|(
literal|"Signal case"
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGKILL
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|expect_death_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_death_but_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_death
argument_list|(
literal|"Call won't die"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|expect_timeout_and_hang
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|expect_timeout_and_hang
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
literal|"timeout"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_timeout_and_hang
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_timeout
argument_list|(
literal|"Will overrun"
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|expect_timeout_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|expect_timeout_but_pass
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
literal|"timeout"
argument_list|,
literal|"1"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|expect_timeout_but_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_expect_timeout
argument_list|(
literal|"Will just exit"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_meta_data".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|metadata_no_descr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|metadata_no_descr
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|metadata_no_head
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|metadata_no_head
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_srcdir".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC
argument_list|(
name|srcdir_exists
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|srcdir_exists
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
literal|"Helper test case for the t_srcdir test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|srcdir_exists
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_fs_path_t
name|p
decl_stmt|;
name|bool
name|b
decl_stmt|;
name|RE
argument_list|(
name|atf_fs_path_init_fmt
argument_list|(
operator|&
name|p
argument_list|,
literal|"%s/datafile"
argument_list|,
name|atf_tc_get_config_var
argument_list|(
name|tc
argument_list|,
literal|"srcdir"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|RE
argument_list|(
name|atf_fs_exists
argument_list|(
operator|&
name|p
argument_list|,
operator|&
name|b
argument_list|)
argument_list|)
expr_stmt|;
name|atf_fs_path_fini
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|b
condition|)
name|atf_tc_fail
argument_list|(
literal|"Cannot find datafile"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ---------------------------------------------------------------------  * Helper tests for "t_result".  * --------------------------------------------------------------------- */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|result_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|result_pass
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"msg\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|result_fail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|result_fail
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"msg\n"
argument_list|)
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"Failure reason"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|result_skip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|result_skip
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"msg\n"
argument_list|)
expr_stmt|;
name|atf_tc_skip
argument_list|(
literal|"Skipped reason"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|result_newlines_fail
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|result_newlines_fail
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
literal|"Helper test case for the t_result test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|result_newlines_fail
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_fail
argument_list|(
literal|"First line\nSecond line"
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|result_newlines_skip
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|result_newlines_skip
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
literal|"Helper test case for the t_result test "
literal|"program"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|result_newlines_skip
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_skip
argument_list|(
literal|"First line\nSecond line"
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
comment|/* Add helper tests for t_cleanup. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cleanup_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cleanup_fail
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cleanup_skip
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cleanup_curdir
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cleanup_sigterm
argument_list|)
expr_stmt|;
comment|/* Add helper tests for t_config. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|config_unset
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|config_empty
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|config_value
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|config_multi_value
argument_list|)
expr_stmt|;
comment|/* Add helper tests for t_expect. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_pass_and_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_pass_but_fail_requirement
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_pass_but_fail_check
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_fail_and_fail_requirement
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_fail_and_fail_check
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_fail_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_exit_any_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_exit_code_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_exit_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_signal_any_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_signal_no_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_signal_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_death_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_death_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_death_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_timeout_and_hang
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|expect_timeout_but_pass
argument_list|)
expr_stmt|;
comment|/* Add helper tests for t_meta_data. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|metadata_no_descr
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|metadata_no_head
argument_list|)
expr_stmt|;
comment|/* Add helper tests for t_srcdir. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|srcdir_exists
argument_list|)
expr_stmt|;
comment|/* Add helper tests for t_result. */
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|result_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|result_fail
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|result_skip
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|result_newlines_fail
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|result_newlines_skip
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

