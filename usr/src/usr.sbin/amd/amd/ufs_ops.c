begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)ufs_ops.c	5.3 (Berkeley) %G%  *  * $Id: ufs_ops.c,v 5.2.1.2 91/05/07 22:18:38 jsp Alpha $  *  */
end_comment

begin_include
include|#
directive|include
file|"am.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_UFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NFS_3
end_ifdef

begin_typedef
typedef|typedef
name|nfs_fh
name|fhandle_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS_3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UFS_HDR
end_ifdef

begin_include
include|#
directive|include
include|UFS_HDR
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UFS_HDR */
end_comment

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_comment
comment|/*  * UN*X file system  */
end_comment

begin_comment
comment|/*  * UFS needs local filesystem and device.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|ufs_match
name|P
argument_list|(
operator|(
name|am_opts
operator|*
name|fo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
modifier|*
name|ufs_match
parameter_list|(
name|fo
parameter_list|)
name|am_opts
modifier|*
name|fo
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|fo
operator|->
name|opt_dev
condition|)
block|{
name|plog
argument_list|(
name|XLOG_USER
argument_list|,
literal|"ufs: no device specified"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|dlog
argument_list|(
literal|"UFS: mounting device \"%s\" on \"%s\""
argument_list|,
name|fo
operator|->
name|opt_dev
argument_list|,
name|fo
operator|->
name|opt_fs
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* DEBUG */
comment|/* 	 * Determine magic cookie to put in mtab 	 */
return|return
name|strdup
argument_list|(
name|fo
operator|->
name|opt_dev
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|mount_ufs
argument_list|(
argument|dir
argument_list|,
argument|fs_name
argument_list|,
argument|opts
argument_list|)
name|char
operator|*
name|dir
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|fs_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|opts
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|ufs_args
name|ufs_args
decl_stmt|;
name|struct
name|mntent
name|mnt
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* 	 * Figure out the name of the file system type. 	 */
ifdef|#
directive|ifdef
name|M_NEWTYPE
name|char
modifier|*
name|type
init|=
name|MOUNT_TYPE_UFS
decl_stmt|;
else|#
directive|else
name|int
name|type
init|=
name|MOUNT_TYPE_UFS
decl_stmt|;
endif|#
directive|endif
comment|/* M_NEWTYPE */
name|bzero
argument_list|(
operator|(
name|voidp
operator|)
operator|&
name|ufs_args
argument_list|,
sizeof|sizeof
argument_list|(
name|ufs_args
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Paranoid */
comment|/* 	 * Fill in the mount structure 	 */
name|mnt
operator|.
name|mnt_dir
operator|=
name|dir
expr_stmt|;
name|mnt
operator|.
name|mnt_fsname
operator|=
name|fs_name
expr_stmt|;
name|mnt
operator|.
name|mnt_type
operator|=
name|MTAB_TYPE_UFS
expr_stmt|;
name|mnt
operator|.
name|mnt_opts
operator|=
name|opts
expr_stmt|;
name|mnt
operator|.
name|mnt_freq
operator|=
literal|1
expr_stmt|;
name|mnt
operator|.
name|mnt_passno
operator|=
literal|2
expr_stmt|;
name|flags
operator|=
name|compute_mount_flags
argument_list|(
operator|&
name|mnt
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ULTRIX_HACK
name|ufs_args
operator|.
name|ufs_flags
operator|=
name|flags
expr_stmt|;
name|ufs_args
operator|.
name|ufs_pgthresh
operator|=
literal|64
expr_stmt|;
comment|/* 64K - XXX */
name|flags
operator|&=
name|M_RDONLY
expr_stmt|;
else|#
directive|else
name|ufs_args
operator|.
name|fspec
operator|=
name|fs_name
expr_stmt|;
endif|#
directive|endif
comment|/* ULTRIX_HACK */
comment|/* 	 * Call generic mount routine 	 */
return|return
name|mount_fs
argument_list|(
operator|&
name|mnt
argument_list|,
name|flags
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|ufs_args
argument_list|,
literal|0
argument_list|,
name|type
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|ufs_fmount
parameter_list|(
name|mf
parameter_list|)
name|mntfs
modifier|*
name|mf
decl_stmt|;
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|mount_ufs
argument_list|(
name|mf
operator|->
name|mf_mount
argument_list|,
name|mf
operator|->
name|mf_info
argument_list|,
name|mf
operator|->
name|mf_mopts
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|errno
operator|=
name|error
expr_stmt|;
name|plog
argument_list|(
name|XLOG_ERROR
argument_list|,
literal|"mount_ufs: %m"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ufs_fumount
parameter_list|(
name|mf
parameter_list|)
name|mntfs
modifier|*
name|mf
decl_stmt|;
block|{
return|return
name|UMOUNT_FS
argument_list|(
name|mf
operator|->
name|mf_mount
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Ops structure  */
end_comment

begin_decl_stmt
name|am_ops
name|ufs_ops
init|=
block|{
literal|"ufs"
block|,
name|ufs_match
block|,
literal|0
block|,
comment|/* ufs_init */
name|auto_fmount
block|,
name|ufs_fmount
block|,
name|auto_fumount
block|,
name|ufs_fumount
block|,
name|efs_lookuppn
block|,
name|efs_readdir
block|,
literal|0
block|,
comment|/* ufs_readlink */
literal|0
block|,
comment|/* ufs_mounted */
literal|0
block|,
comment|/* ufs_umounted */
name|find_afs_srvr
block|,
ifdef|#
directive|ifdef
name|FLUSH_KERNEL_NAME_CACHE
name|FS_MKMNT
operator||
name|FS_NOTIMEOUT
operator||
name|FS_UBACKGROUND
operator||
name|FS_AMQINFO
else|#
directive|else
comment|/* FLUSH_KERNEL_NAME_CACHE */
name|FS_MKMNT
operator||
name|FS_NOTIMEOUT
operator||
name|FS_UBACKGROUND
operator||
name|FS_AMQINFO
endif|#
directive|endif
comment|/* FLUSH_KERNEL_NAME_CACHE */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_UFS */
end_comment

end_unit

