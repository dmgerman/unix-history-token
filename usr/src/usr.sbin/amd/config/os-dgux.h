begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-dgux.h	5.4 (Berkeley) %G%  *  * $Id: os-dgux.h,v 5.2.2.1 1992/02/09 15:10:18 jsp beta $  *  * dg/ux definitions for Amd (automounter)  */
end_comment

begin_comment
comment|/*  * Does the compiler grok void *  */
end_comment

begin_define
define|#
directive|define
name|VOIDP
end_define

begin_comment
comment|/*  * Which version of the Sun RPC library we are using  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|RPC_4
end_define

begin_comment
comment|/*  * Which version of the NFS interface are we using.  * This is the implementation release number, not  * the protocol revision number.  */
end_comment

begin_define
define|#
directive|define
name|NFS_4
end_define

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|"nfs"
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|"dg/ux"
end_define

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|"dg/ux"
end_define

begin_comment
comment|/*  * Need the following in more places than just NFS_HDR  */
end_comment

begin_include
include|#
directive|include
file|<sys/dg_mount.h>
end_include

begin_comment
comment|/*  * This is braindead  * dg/ux has nfs 4.0 but doesn't have the following options  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0x0
end_define

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x0
end_define

begin_define
define|#
directive|define
name|M_NEWTYPE
value|0
end_define

begin_comment
comment|/*  * DG have their own filesystem.  */
end_comment

begin_define
define|#
directive|define
name|ufs_args
value|dgux_args
end_define

begin_comment
comment|/*  * Byte ordering  */
end_comment

begin_undef
undef|#
directive|undef
name|ARCH_ENDIAN
end_undef

begin_define
define|#
directive|define
name|ARCH_ENDIAN
value|"big"
end_define

begin_define
define|#
directive|define
name|_BSD_WAIT_FLAVOR
end_define

begin_define
define|#
directive|define
name|_BSD_TTY_FLAVOR
end_define

begin_define
define|#
directive|define
name|_BSD_SIGNAL_FLAVOR
end_define

begin_define
define|#
directive|define
name|_DGUX_SOURCE
end_define

begin_comment
comment|/*  * Use fcntl() rather than flock()  */
end_comment

begin_define
define|#
directive|define
name|LOCK_FCNTL
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|memset(ptr, 0, len)
end_define

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|memcpy(to, from, len)
end_define

begin_undef
undef|#
directive|undef
name|MOUNT_TRAP
end_undef

begin_define
define|#
directive|define
name|MOUNT_TRAP
parameter_list|(
name|type
parameter_list|,
name|mnt
parameter_list|,
name|flags
parameter_list|,
name|mnt_data
parameter_list|)
define|\
value|((struct nfs_args *)mnt_data)->version = !strcmp(type, MOUNT_TYPE_UFS)?\ 	     DG_MOUNT_DGUX_VERSION:DG_MOUNT_NFS_VERSION, \ 	dg_mount(type, mnt->mnt_dir, flags, mnt_data)
end_define

begin_undef
undef|#
directive|undef
name|UNMOUNT_TRAP
end_undef

begin_define
define|#
directive|define
name|UNMOUNT_TRAP
parameter_list|(
name|mnt
parameter_list|)
value|umount(mnt->mnt_dir)
end_define

end_unit

