begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-stellix.h	8.1 (Berkeley) %G%  *  * Amd (automounter) definitions for Stellix.  * From Stephen C. Pope<scp@acl.lanl.gov>  *  * $Id: os-stellix.h,v 5.2.2.1 1992/02/09 15:10:43 jsp beta $  */
end_comment

begin_define
define|#
directive|define
name|RPC_3
end_define

begin_define
define|#
directive|define
name|NFS_3
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
name|HAS_SYSLOG
end_define

begin_define
define|#
directive|define
name|OS_HAS_NDBM
end_define

begin_define
define|#
directive|define
name|UPDATE_MTAB
end_define

begin_define
define|#
directive|define
name|USE_FCNTL
end_define

begin_define
define|#
directive|define
name|LOCK_FCNTL
end_define

begin_comment
comment|/*  * Name of filesystem types  */
end_comment

begin_undef
undef|#
directive|undef
name|MTAB_TYPE_UFS
end_undef

begin_define
define|#
directive|define
name|MTAB_TYPE_UFS
value|"sfs"
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_UFS
value|sysfs(GETFSIND, "SFS1")
end_define

begin_define
define|#
directive|define
name|MOUNT_TYPE_NFS
value|sysfs(GETFSIND, "NFS")
end_define

begin_define
define|#
directive|define
name|SYS5_SIGNALS
end_define

begin_define
define|#
directive|define
name|HAS_SVR3_SIGNALS
end_define

begin_define
define|#
directive|define
name|MOUNT_HELPER_SOURCE
value|"mount_stellix.c"
end_define

begin_comment
comment|/*  * Name of mount& unmount system calls  *  * NOTE:  *  UNMOUNT_TRAP takes a struct mntent *  */
end_comment

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
value|stellix_mount(mnt->mnt_fsname, mnt->mnt_dir, flags, type, mnt_data)
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

begin_comment
comment|/*  * How to unmount filesystems.  * NEED_UMOUNT_FS includes code to scan the mount table  * to find the correct information for the unmount system  * call.  Some systems, such as 4.4bsd, do not require  * this - they can just do an unmount system call directly.  */
end_comment

begin_comment
comment|/* #define	NEED_UMOUNT_FS */
end_comment

begin_comment
comment|/* #define	UMOUNT_FS(dir)	umount_fs(dir) */
end_comment

begin_define
define|#
directive|define
name|NFS_HDR
value|"misc-stellix.h"
end_define

begin_define
define|#
directive|define
name|UFS_HDR
value|"misc-stellix.h"
end_define

begin_define
define|#
directive|define
name|M_RDONLY
value|0x01
end_define

begin_comment
comment|/* mount fs read only */
end_comment

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

end_unit

