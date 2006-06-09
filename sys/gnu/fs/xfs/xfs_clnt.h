begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_CLNT_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_CLNT_H__
end_define

begin_comment
comment|/*  * XFS arguments structure, constructed from the arguments we  * are passed via the mount system call.  *  * NOTE: The mount system call is handled differently between  * Linux and IRIX.  In IRIX we worked work with a binary data  * structure coming in across the syscall interface from user  * space (the mount userspace knows about each filesystem type  * and the set of valid options for it, and converts the users  * argument string into a binary structure _before_ making the  * system call), and the ABI issues that this implies.  *  * In Linux, we are passed a comma separated set of options;  * ie. a NULL terminated string of characters.  Userspace mount  * code does not have any knowledge of mount options expected by  * each filesystem type and so each filesystem parses its mount  * options in kernel space.  *  * For the Linux port, we kept this structure pretty much intact  * and use it internally (because the existing code groks it).  */
end_comment

begin_struct
struct|struct
name|xfs_mount_args
block|{
name|int
name|flags
decl_stmt|;
comment|/* flags -> see XFSMNT_... macros below */
name|int
name|flags2
decl_stmt|;
comment|/* flags -> see XFSMNT2_... macros below */
name|int
name|logbufs
decl_stmt|;
comment|/* Number of log buffers, -1 to default */
name|int
name|logbufsize
decl_stmt|;
comment|/* Size of log buffers, -1 to default */
name|char
name|fsname
index|[
name|MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* data device name */
name|char
name|rtname
index|[
name|MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* realtime device filename */
name|char
name|logname
index|[
name|MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* journal device filename */
name|char
name|mtpt
index|[
name|MAXNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* filesystem mount point */
name|int
name|sunit
decl_stmt|;
comment|/* stripe unit (BBs) */
name|int
name|swidth
decl_stmt|;
comment|/* stripe width (BBs), multiple of sunit */
name|uchar_t
name|iosizelog
decl_stmt|;
comment|/* log2 of the preferred I/O size */
name|int
name|ihashsize
decl_stmt|;
comment|/* inode hash table size (buckets) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * XFS mount option flags -- args->flags1  */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_ATTR2
value|0x00000001
end_define

begin_comment
comment|/* allow ATTR2 EA format */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_WSYNC
value|0x00000002
end_define

begin_comment
comment|/* safe mode nfs mount 						 * compatible */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_INO64
value|0x00000004
end_define

begin_comment
comment|/* move inode numbers up 						 * past 2^32 */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_UQUOTA
value|0x00000008
end_define

begin_comment
comment|/* user quota accounting */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_PQUOTA
value|0x00000010
end_define

begin_comment
comment|/* IRIX prj quota accounting */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_UQUOTAENF
value|0x00000020
end_define

begin_comment
comment|/* user quota limit 						 * enforcement */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_PQUOTAENF
value|0x00000040
end_define

begin_comment
comment|/* IRIX project quota limit 						 * enforcement */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_QUIET
value|0x00000080
end_define

begin_comment
comment|/* don't report mount errors */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_NOALIGN
value|0x00000200
end_define

begin_comment
comment|/* don't allocate at 						 * stripe boundaries*/
end_comment

begin_define
define|#
directive|define
name|XFSMNT_RETERR
value|0x00000400
end_define

begin_comment
comment|/* return error to user */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_NORECOVERY
value|0x00000800
end_define

begin_comment
comment|/* no recovery, implies 						 * read-only mount */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_SHARED
value|0x00001000
end_define

begin_comment
comment|/* shared XFS mount */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_IOSIZE
value|0x00002000
end_define

begin_comment
comment|/* optimize for I/O size */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_OSYNCISOSYNC
value|0x00004000
end_define

begin_comment
comment|/* o_sync is REALLY o_sync */
end_comment

begin_comment
comment|/* (osyncisdsync is default) */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_32BITINODES
value|0x00200000
end_define

begin_comment
comment|/* restrict inodes to 32 						 * bits of address space */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_GQUOTA
value|0x00400000
end_define

begin_comment
comment|/* group quota accounting */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_GQUOTAENF
value|0x00800000
end_define

begin_comment
comment|/* group quota limit 						 * enforcement */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_NOUUID
value|0x01000000
end_define

begin_comment
comment|/* Ignore fs uuid */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_DMAPI
value|0x02000000
end_define

begin_comment
comment|/* enable dmapi/xdsm */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_BARRIER
value|0x04000000
end_define

begin_comment
comment|/* use write barriers */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_IDELETE
value|0x08000000
end_define

begin_comment
comment|/* inode cluster delete */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_SWALLOC
value|0x10000000
end_define

begin_comment
comment|/* turn on stripe width 						 * allocation */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_IHASHSIZE
value|0x20000000
end_define

begin_comment
comment|/* inode hash table size */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_DIRSYNC
value|0x40000000
end_define

begin_comment
comment|/* sync creat,link,unlink,rename 						 * symlink,mkdir,rmdir,mknod */
end_comment

begin_define
define|#
directive|define
name|XFSMNT_FLAGS2
value|0x80000000
end_define

begin_comment
comment|/* more flags set in flags2 */
end_comment

begin_comment
comment|/*  * XFS mount option flags -- args->flags2  */
end_comment

begin_define
define|#
directive|define
name|XFSMNT2_COMPAT_IOSIZE
value|0x00000001
end_define

begin_comment
comment|/* don't report large preferred 						 * I/O size in stat(2) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_CLNT_H__ */
end_comment

end_unit

