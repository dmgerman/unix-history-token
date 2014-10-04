begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: h_simplecli.c,v 1.2 2011/01/14 13:23:15 pooka Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump_syscalls.h>
end_include

begin_include
include|#
directive|include
file|<rump/rumpclient.h>
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
name|argv
index|[]
parameter_list|)
block|{
if|if
condition|(
name|rumpclient_init
argument_list|()
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"rumpclient init"
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
name|rump_sys_getpid
argument_list|()
expr_stmt|;
name|usleep
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|rump_sys_getpid
argument_list|()
operator|>
literal|0
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|err
argument_list|(
literal|1
argument_list|,
literal|"getpid"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

