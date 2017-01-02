begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<os/log.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../../common/darwin_log_common.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|os_log_t
name|logger_sub1
init|=
name|os_log_create
argument_list|(
literal|"org.llvm.lldb.test.sub1"
argument_list|,
literal|"cat1"
argument_list|)
decl_stmt|;
name|os_log_t
name|logger_sub2
init|=
name|os_log_create
argument_list|(
literal|"org.llvm.lldb.test.sub2"
argument_list|,
literal|"cat2"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|logger_sub1
operator|||
operator|!
name|logger_sub2
condition|)
return|return
literal|1
return|;
comment|// Note we cannot use the os_log() line as the breakpoint because, as of
comment|// the initial writing of this test, we get multiple breakpoints for that
comment|// line, which confuses the pexpect test logic.
name|printf
argument_list|(
literal|"About to log\n"
argument_list|)
expr_stmt|;
comment|// break here
name|os_log_debug
argument_list|(
name|logger_sub1
argument_list|,
literal|"source-log-sub1-cat1"
argument_list|)
expr_stmt|;
name|os_log
argument_list|(
name|logger_sub2
argument_list|,
literal|"source-log-sub2-cat2"
argument_list|)
expr_stmt|;
comment|// Sleep, as the darwin log reporting doesn't always happen until a bit
comment|// later.  We need the message to come out before the process terminates.
name|sleep
argument_list|(
name|FINAL_WAIT_SECONDS
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

