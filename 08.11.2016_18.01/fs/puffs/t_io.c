begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_io.c,v 1.1 2010/11/12 17:33:28 pooka Exp $	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<puffs.h>
end_include

begin_include
include|#
directive|include
file|<puffsdump.h>
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
file|<string.h>
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
file|"../../h_macros.h"
end_include

begin_include
include|#
directive|include
file|"../common/h_fsmacros.h"
end_include

begin_define
define|#
directive|define
name|MAKEOPTS
parameter_list|(
modifier|...
parameter_list|)
define|\
value|char *theopts[] = {NULL, "-s", __VA_ARGS__, "dtfs", "n/a", NULL}
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|nocache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|nocache
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
literal|"tests large i/o without page cache"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|nocache
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|MAKEOPTS
argument_list|(
literal|"-o"
argument_list|,
literal|"nopagecache"
argument_list|)
expr_stmt|;
name|char
name|data
index|[
literal|1024
operator|*
literal|1024
index|]
decl_stmt|;
name|void
modifier|*
name|args
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|FSTEST_CONSTRUCTOR_FSPRIV
argument_list|(
name|tc
argument_list|,
name|puffs
argument_list|,
name|args
argument_list|,
name|theopts
argument_list|)
expr_stmt|;
name|FSTEST_ENTER
argument_list|()
expr_stmt|;
name|RL
argument_list|(
name|fd
operator|=
name|rump_sys_open
argument_list|(
literal|"afile"
argument_list|,
name|O_CREAT
operator||
name|O_RDWR
argument_list|,
literal|0755
argument_list|)
argument_list|)
expr_stmt|;
name|RL
argument_list|(
name|rump_sys_write
argument_list|(
name|fd
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
name|data
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|rump_sys_close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|FSTEST_EXIT
argument_list|()
expr_stmt|;
name|FSTEST_DESTRUCTOR
argument_list|(
name|tc
argument_list|,
name|puffs
argument_list|,
name|args
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
name|nocache
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

