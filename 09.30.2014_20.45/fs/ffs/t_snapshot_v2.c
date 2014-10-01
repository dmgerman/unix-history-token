begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_snapshot_v2.c,v 1.2 2013/02/06 09:05:01 hannken Exp $	*/
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
file|<atf-c.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"../../h_macros.h"
end_include

begin_define
define|#
directive|define
name|IMGNAME
value|"ffs.img"
end_define

begin_define
define|#
directive|define
name|NEWFS
value|"newfs -F -s 10000 -O 2 " IMGNAME
end_define

begin_define
define|#
directive|define
name|FSCK
value|"fsck_ffs -fn -F"
end_define

begin_define
define|#
directive|define
name|BAKNAME
value|"/mnt/le_snapp"
end_define

begin_function
specifier|static
name|void
name|mount_diskfs
parameter_list|(
specifier|const
name|char
modifier|*
name|fspec
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|struct
name|ufs_args
name|uargs
decl_stmt|;
name|uargs
operator|.
name|fspec
operator|=
name|__UNCONST
argument_list|(
name|fspec
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_FFS
argument_list|,
name|path
argument_list|,
literal|0
argument_list|,
operator|&
name|uargs
argument_list|,
sizeof|sizeof
argument_list|(
name|uargs
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mount ffs %s"
argument_list|,
name|path
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|begin
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* empty */
block|}
end_function

begin_include
include|#
directive|include
file|"../common/snapshot.c"
end_include

end_unit

