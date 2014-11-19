begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_snapshot.c,v 1.3 2014/06/10 13:15:18 martin Exp $	*/
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
file|<fs/tmpfs/tmpfs_args.h>
end_include

begin_include
include|#
directive|include
file|<msdosfs/msdosfsmount.h>
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
value|"msdosfs.img"
end_define

begin_define
define|#
directive|define
name|NEWFS
value|"newfs_msdos -C 5M " IMGNAME
end_define

begin_define
define|#
directive|define
name|FSCK
value|"fsck_msdos -fn"
end_define

begin_define
define|#
directive|define
name|BAKNAME
value|"/stor/snap"
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
name|msdosfs_args
name|margs
decl_stmt|;
name|memset
argument_list|(
operator|&
name|margs
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|margs
argument_list|)
argument_list|)
expr_stmt|;
name|margs
operator|.
name|fspec
operator|=
name|__UNCONST
argument_list|(
name|fspec
argument_list|)
expr_stmt|;
name|margs
operator|.
name|version
operator|=
name|MSDOSFSMNT_VERSION
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_MSDOS
argument_list|,
name|path
argument_list|,
literal|0
argument_list|,
operator|&
name|margs
argument_list|,
sizeof|sizeof
argument_list|(
name|margs
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"mount msdosfs %s"
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
name|struct
name|tmpfs_args
name|targs
init|=
block|{
operator|.
name|ta_version
operator|=
name|TMPFS_ARGS_VERSION
block|, }
decl_stmt|;
if|if
condition|(
name|rump_sys_mkdir
argument_list|(
literal|"/stor"
argument_list|,
literal|0777
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mkdir /stor"
argument_list|)
expr_stmt|;
if|if
condition|(
name|rump_sys_mount
argument_list|(
name|MOUNT_TMPFS
argument_list|,
literal|"/stor"
argument_list|,
literal|0
argument_list|,
operator|&
name|targs
argument_list|,
sizeof|sizeof
argument_list|(
name|targs
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|atf_tc_fail_errno
argument_list|(
literal|"mount storage"
argument_list|)
expr_stmt|;
block|}
end_function

begin_include
include|#
directive|include
file|"../common/snapshot.c"
end_include

end_unit

