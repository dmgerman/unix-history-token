begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Automated Testing Framework (atf)  *  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
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
file|<atf-c.h>
end_include

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|pass_and_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|pass_and_pass
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
name|pass_but_fail_requirement
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|pass_but_fail_requirement
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
name|pass_but_fail_check
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|pass_but_fail_check
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
name|fail_and_fail_requirement
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fail_and_fail_requirement
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
name|fail_and_fail_check
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fail_and_fail_check
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
name|fail_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fail_but_pass
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
name|exit_any_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|exit_any_and_exit
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
name|exit_code_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|exit_code_and_exit
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
name|exit_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|exit_but_pass
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
name|signal_any_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|signal_any_and_signal
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
name|signal_no_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|signal_no_and_signal
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
name|signal_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|signal_but_pass
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
name|death_and_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|death_and_exit
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
name|death_and_signal
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|death_and_signal
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
name|death_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|death_but_pass
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
name|timeout_and_hang
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|timeout_and_hang
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
argument|timeout_and_hang
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
name|timeout_but_pass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|timeout_but_pass
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
argument|timeout_but_pass
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
name|pass_and_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|pass_but_fail_requirement
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|pass_but_fail_check
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fail_and_fail_requirement
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fail_and_fail_check
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fail_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|exit_any_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|exit_code_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|exit_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|signal_any_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|signal_no_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|signal_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|death_and_exit
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|death_and_signal
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|death_but_pass
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|timeout_and_hang
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|timeout_but_pass
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

