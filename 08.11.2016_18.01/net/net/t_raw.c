begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_raw.c,v 1.1 2011/01/11 10:51:45 pooka Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
file|<rump/rump.h>
end_include

begin_include
include|#
directive|include
file|<rump/rump_syscalls.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|PRU_SENSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|PRU_SENSE
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
literal|"Biglock leak with PRU_SENSE on "
literal|"raw sockets (PR kern/44369)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|PRU_SENSE
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|stat
name|sb
decl_stmt|;
name|int
name|s
decl_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
name|RL
argument_list|(
name|s
operator|=
name|rump_sys_socket
argument_list|(
name|PF_ROUTE
argument_list|,
name|SOCK_RAW
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
comment|/* call PRU_SENSE.  unfixed bug causes panic in rump_unschedule() */
name|RL
argument_list|(
name|rump_sys_fstat
argument_list|(
name|s
argument_list|,
operator|&
name|sb
argument_list|)
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
name|PRU_SENSE
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

