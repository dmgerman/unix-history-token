begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_mount.c,v 1.13 2012/11/27 16:01:49 jakllsch Exp $	*/
end_comment

begin_comment
comment|/*  * Basic tests for mounting  */
end_comment

begin_comment
comment|/*  * 48Kimage:  * Adapted for rump and atf from a testcase supplied  * by Hubert Feyrer on netbsd-users@  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_define
define|#
directive|define
name|FSTEST_IMGSIZE
value|(96 * 512)
end_define

begin_include
include|#
directive|include
file|"../common/h_fsmacros.h"
end_include

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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
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

begin_expr_stmt
name|ATF_TC
argument_list|(
literal|48Kimage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
literal|48Kimage
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
literal|"mount small 48K ffs image"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
literal|48Kimage
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|void
modifier|*
name|tmp
decl_stmt|;
name|atf_tc_expect_fail
argument_list|(
literal|"PR kern/43573"
argument_list|)
expr_stmt|;
name|FSTEST_CONSTRUCTOR
argument_list|(
name|tc
argument_list|,
name|ffs
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|atf_tc_expect_pass
argument_list|()
expr_stmt|;
name|FSTEST_DESTRUCTOR
argument_list|(
name|tc
argument_list|,
name|ffs
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|fsbsizeovermaxphys
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|fsbsizeovermaxphys
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
literal|"mounts file system with "
literal|"blocksize> MAXPHYS"
argument_list|)
expr_stmt|;
comment|/* PR kern/43727 */
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fsbsizeovermaxphys
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|cmd
index|[
literal|1024
index|]
decl_stmt|;
name|struct
name|ufs_args
name|args
decl_stmt|;
name|struct
name|statvfs
name|svb
decl_stmt|;
comment|/* 	 * We cannot pass newfs parameters via the fstest interface, 	 * so do things the oldfashioned manual way. 	 */
name|snprintf
argument_list|(
name|cmd
argument_list|,
sizeof|sizeof
argument_list|(
name|cmd
argument_list|)
argument_list|,
literal|"newfs -G -b %d -F -s 10000 "
literal|"ffs.img> /dev/null"
argument_list|,
name|MAXPHYS
operator|*
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|system
argument_list|(
name|cmd
argument_list|)
condition|)
name|atf_tc_fail
argument_list|(
literal|"cannot create file system"
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|rump_pub_etfs_register
argument_list|(
literal|"/devdisk"
argument_list|,
literal|"ffs.img"
argument_list|,
name|RUMP_ETFS_BLK
argument_list|)
condition|)
name|atf_tc_fail
argument_list|(
literal|"cannot register rump fake device"
argument_list|)
expr_stmt|;
name|args
operator|.
name|fspec
operator|=
name|__UNCONST
argument_list|(
literal|"/devdisk"
argument_list|)
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
literal|"create mountpoint"
argument_list|)
expr_stmt|;
comment|/* mount succeeded?  bad omen.  confirm we're in trouble.  */
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_FFS
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
operator|!=
operator|-
literal|1
condition|)
block|{
name|rump_sys_statvfs1
argument_list|(
literal|"/mp"
argument_list|,
operator|&
name|svb
argument_list|,
name|ST_WAIT
argument_list|)
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"not expecting to be alive"
argument_list|)
expr_stmt|;
block|}
comment|/* otherwise we're do-ne */
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|fsbsizeovermaxbsize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|fsbsizeovermaxbsize
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
literal|"mounts file system with "
literal|"blocksize> MAXBSIZE"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|fsbsizeovermaxbsize
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|char
name|cmd
index|[
literal|1024
index|]
decl_stmt|;
name|struct
name|ufs_args
name|args
decl_stmt|;
name|struct
name|statvfs
name|svb
decl_stmt|;
comment|/* 	 * We cannot pass newfs parameters via the fstest interface, 	 * so do things the oldfashioned manual way. 	 */
name|snprintf
argument_list|(
name|cmd
argument_list|,
sizeof|sizeof
argument_list|(
name|cmd
argument_list|)
argument_list|,
literal|"newfs -G -b %d -F -s 10000 "
literal|"ffs.img> /dev/null"
argument_list|,
name|MAXBSIZE
operator|*
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|system
argument_list|(
name|cmd
argument_list|)
condition|)
name|atf_tc_fail
argument_list|(
literal|"cannot create file system"
argument_list|)
expr_stmt|;
name|rump_init
argument_list|()
expr_stmt|;
if|if
condition|(
name|rump_pub_etfs_register
argument_list|(
literal|"/devdisk"
argument_list|,
literal|"ffs.img"
argument_list|,
name|RUMP_ETFS_BLK
argument_list|)
condition|)
name|atf_tc_fail
argument_list|(
literal|"cannot register rump fake device"
argument_list|)
expr_stmt|;
name|args
operator|.
name|fspec
operator|=
name|__UNCONST
argument_list|(
literal|"/devdisk"
argument_list|)
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
literal|"create mountpoint"
argument_list|)
expr_stmt|;
comment|/* mount succeeded?  bad omen.  confirm we're in trouble.  */
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_FFS
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
operator|!=
operator|-
literal|1
condition|)
block|{
name|rump_sys_statvfs1
argument_list|(
literal|"/mp"
argument_list|,
operator|&
name|svb
argument_list|,
name|ST_WAIT
argument_list|)
expr_stmt|;
name|atf_tc_fail
argument_list|(
literal|"not expecting to be alive"
argument_list|)
expr_stmt|;
block|}
comment|/* otherwise we're do-ne */
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
literal|48Kimage
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fsbsizeovermaxphys
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|fsbsizeovermaxbsize
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

