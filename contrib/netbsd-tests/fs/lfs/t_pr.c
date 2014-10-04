begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_pr.c,v 1.6 2011/02/22 18:41:05 pooka Exp $	*/
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
file|<limits.h>
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
file|<ufs/ufs/ufsmount.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|mknod
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|mknod
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
literal|"mknod(2) hangs on LFS (PR kern/43503)"
argument_list|)
expr_stmt|;
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"timeout"
argument_list|,
literal|"20"
argument_list|)
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|IMGNAME
value|"disk.img"
end_define

begin_define
define|#
directive|define
name|FAKEBLK
value|"/dev/blk"
end_define

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|mknod
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|ufs_args
name|args
decl_stmt|;
comment|/* hmm, maybe i should fix newfs_lfs instead? */
if|if
condition|(
name|system
argument_list|(
literal|"newfs_lfs -D -F -s 10000 ./"
name|IMGNAME
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"newfs failed"
argument_list|)
expr_stmt|;
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
name|fspec
operator|=
name|__UNCONST
argument_list|(
name|FAKEBLK
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
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
name|atf_tc_fail_errno
argument_list|(
literal|"cannot create mountpoint"
argument_list|)
expr_stmt|;
name|rump_pub_etfs_register
argument_list|(
name|FAKEBLK
argument_list|,
name|IMGNAME
argument_list|,
name|RUMP_ETFS_BLK
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_LFS
argument_list|,
literal|"/mp"
argument_list|,
literal|0
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
literal|"rump_sys_mount failed"
argument_list|)
expr_stmt|;
comment|//atf_tc_expect_timeout("PR kern/43503");
if|if
condition|(
name|rump_sys_mknod
argument_list|(
literal|"/mp/node"
argument_list|,
name|S_IFCHR
operator||
literal|0777
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mknod failed"
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
name|mknod
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

