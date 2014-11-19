begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_ptyfs.c,v 1.1 2010/06/11 23:52:38 pooka Exp $	*/
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
file|<fs/ptyfs/ptyfs.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_function
specifier|static
name|void
name|mountptyfs
parameter_list|(
specifier|const
name|char
modifier|*
name|mp
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|struct
name|ptyfs_args
name|args
decl_stmt|;
if|if
condition|(
name|rump_sys_mkdir
argument_list|(
literal|"/mp"
argument_list|,
literal|0777
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EEXIST
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mp1"
argument_list|)
expr_stmt|;
block|}
name|memset
argument_list|(
operator|&
name|args
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|args
argument_list|)
argument_list|)
expr_stmt|;
name|args
operator|.
name|version
operator|=
name|PTYFS_ARGSVERSION
expr_stmt|;
name|args
operator|.
name|mode
operator|=
literal|0777
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_PTYFS
argument_list|,
name|mp
argument_list|,
name|flags
argument_list|,
operator|&
name|args
argument_list|,
sizeof|sizeof
argument_list|(
name|args
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"could not mount ptyfs"
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|basic
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
literal|"mount ptyfs"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|rump_init
argument_list|()
expr_stmt|;
name|mountptyfs
argument_list|(
literal|"/mp"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_unmount
argument_list|(
literal|"/mp"
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"unmount failed"
argument_list|)
expr_stmt|;
comment|/* done */
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
name|basic
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

