begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mount.h	8.13 (Berkeley) 3/27/94  *	$Id: mount.h,v 1.34.2.1 1997/08/17 13:33:43 joerg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MOUNT_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|fsid
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|fsid_t
typedef|;
end_typedef

begin_comment
comment|/* file system id type */
end_comment

begin_comment
comment|/*  * File identifier.  * These are unique per filesystem on a single machine.  */
end_comment

begin_define
define|#
directive|define
name|MAXFIDSZ
value|16
end_define

begin_struct
struct|struct
name|fid
block|{
name|u_short
name|fid_len
decl_stmt|;
comment|/* length of data in bytes */
name|u_short
name|fid_reserved
decl_stmt|;
comment|/* force longword alignment */
name|char
name|fid_data
index|[
name|MAXFIDSZ
index|]
decl_stmt|;
comment|/* data (variable length) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * file system statistics  */
end_comment

begin_define
define|#
directive|define
name|MNAMELEN
value|90
end_define

begin_comment
comment|/* length of buffer for returned name */
end_comment

begin_struct
struct|struct
name|statfs
block|{
name|long
name|f_spare2
decl_stmt|;
comment|/* placeholder */
name|long
name|f_bsize
decl_stmt|;
comment|/* fundamental file system block size */
name|long
name|f_iosize
decl_stmt|;
comment|/* optimal transfer block size */
name|long
name|f_blocks
decl_stmt|;
comment|/* total data blocks in file system */
name|long
name|f_bfree
decl_stmt|;
comment|/* free blocks in fs */
name|long
name|f_bavail
decl_stmt|;
comment|/* free blocks avail to non-superuser */
name|long
name|f_files
decl_stmt|;
comment|/* total file nodes in file system */
name|long
name|f_ffree
decl_stmt|;
comment|/* free file nodes in fs */
name|fsid_t
name|f_fsid
decl_stmt|;
comment|/* file system id */
name|uid_t
name|f_owner
decl_stmt|;
comment|/* user that mounted the filesystem */
name|int
name|f_type
decl_stmt|;
comment|/* type of filesystem (see below) */
name|int
name|f_flags
decl_stmt|;
comment|/* copy of mount flags */
name|long
name|f_spare
index|[
literal|6
index|]
decl_stmt|;
comment|/* spare for later */
name|char
name|f_mntonname
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* directory on which mounted */
name|char
name|f_mntfromname
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* mounted filesystem */
block|}
struct|;
end_struct

begin_comment
comment|/*  * File system types.  */
end_comment

begin_define
define|#
directive|define
name|MOUNT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|MOUNT_UFS
value|1
end_define

begin_comment
comment|/* Fast Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_NFS
value|2
end_define

begin_comment
comment|/* Sun-compatible Network Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_MFS
value|3
end_define

begin_comment
comment|/* Memory-based Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_MSDOS
value|4
end_define

begin_comment
comment|/* MS/DOS Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_LFS
value|5
end_define

begin_comment
comment|/* Log-based Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_LOFS
value|6
end_define

begin_comment
comment|/* Loopback Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_FDESC
value|7
end_define

begin_comment
comment|/* File Descriptor Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_PORTAL
value|8
end_define

begin_comment
comment|/* Portal Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_NULL
value|9
end_define

begin_comment
comment|/* Minimal Filesystem Layer */
end_comment

begin_define
define|#
directive|define
name|MOUNT_UMAP
value|10
end_define

begin_comment
comment|/* User/Group Identifier Remapping Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_KERNFS
value|11
end_define

begin_comment
comment|/* Kernel Information Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_PROCFS
value|12
end_define

begin_comment
comment|/* /proc Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_AFS
value|13
end_define

begin_comment
comment|/* Andrew Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_CD9660
value|14
end_define

begin_comment
comment|/* ISO9660 (aka CDROM) Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_UNION
value|15
end_define

begin_comment
comment|/* Union (translucent) Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_DEVFS
value|16
end_define

begin_comment
comment|/* existing device Filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_EXT2FS
value|17
end_define

begin_comment
comment|/* Linux EXT2FS */
end_comment

begin_define
define|#
directive|define
name|MOUNT_TFS
value|18
end_define

begin_comment
comment|/* Netcon Novell filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_CFS
value|19
end_define

begin_comment
comment|/* Coda filesystem */
end_comment

begin_define
define|#
directive|define
name|MOUNT_MAXTYPE
value|19
end_define

begin_define
define|#
directive|define
name|INITMOUNTNAMES
value|{ \ 	"none",
comment|/*  0 MOUNT_NONE */
value|\ 	"ufs",
comment|/*  1 MOUNT_UFS */
value|\ 	"nfs",
comment|/*  2 MOUNT_NFS */
value|\ 	"mfs",
comment|/*  3 MOUNT_MFS */
value|\ 	"msdos",
comment|/*  4 MOUNT_MSDOS */
value|\ 	"lfs",
comment|/*  5 MOUNT_LFS */
value|\ 	"lofs",
comment|/*  6 MOUNT_LOFS */
value|\ 	"fdesc",
comment|/*  7 MOUNT_FDESC */
value|\ 	"portal",
comment|/*  8 MOUNT_PORTAL */
value|\ 	"null",
comment|/*  9 MOUNT_NULL */
value|\ 	"umap",
comment|/* 10 MOUNT_UMAP */
value|\ 	"kernfs",
comment|/* 11 MOUNT_KERNFS */
value|\ 	"procfs",
comment|/* 12 MOUNT_PROCFS */
value|\ 	"afs",
comment|/* 13 MOUNT_AFS */
value|\ 	"cd9660",
comment|/* 14 MOUNT_CD9660 */
value|\ 	"union",
comment|/* 15 MOUNT_UNION */
value|\ 	"devfs",
comment|/* 16 MOUNT_DEVFS */
value|\ 	"ext2fs",
comment|/* 17 MOUNT_EXT2FS */
value|\ 	"tfs",
comment|/* 18 MOUNT_TFS */
value|\ 	"cfs",
comment|/* 19 MOUNT_TFS */
value|\ 	0,
comment|/* 19 MOUNT_SPARE */
value|\ }
end_define

begin_comment
comment|/*  * Structure per mounted file system.  Each mounted file system has an  * array of operations and an instance record.  The file systems are  * put on a doubly linked list.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|vnodelst
argument_list|,
name|vnode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mount
block|{
name|CIRCLEQ_ENTRY
argument_list|(
argument|mount
argument_list|)
name|mnt_list
expr_stmt|;
comment|/* mount list */
name|struct
name|vfsops
modifier|*
name|mnt_op
decl_stmt|;
comment|/* operations on fs */
name|struct
name|vfsconf
modifier|*
name|mnt_vfc
decl_stmt|;
comment|/* configuration info */
name|struct
name|vnode
modifier|*
name|mnt_vnodecovered
decl_stmt|;
comment|/* vnode we mounted on */
name|struct
name|vnodelst
name|mnt_vnodelist
decl_stmt|;
comment|/* list of vnodes this mount */
name|int
name|mnt_flag
decl_stmt|;
comment|/* flags */
name|int
name|mnt_maxsymlinklen
decl_stmt|;
comment|/* max size of short symlink */
name|struct
name|statfs
name|mnt_stat
decl_stmt|;
comment|/* cache of filesystem stats */
name|qaddr_t
name|mnt_data
decl_stmt|;
comment|/* private data */
comment|/*	struct vfsconf	*mnt_vfc; */
comment|/* configuration info */
name|time_t
name|mnt_time
decl_stmt|;
comment|/* last time written*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mount flags.  *  * Unmount uses MNT_FORCE flag.  */
end_comment

begin_define
define|#
directive|define
name|MNT_RDONLY
value|0x00000001
end_define

begin_comment
comment|/* read only filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_SYNCHRONOUS
value|0x00000002
end_define

begin_comment
comment|/* file system written synchronously */
end_comment

begin_define
define|#
directive|define
name|MNT_NOEXEC
value|0x00000004
end_define

begin_comment
comment|/* can't exec from filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_NOSUID
value|0x00000008
end_define

begin_comment
comment|/* don't honor setuid bits on fs */
end_comment

begin_define
define|#
directive|define
name|MNT_NODEV
value|0x00000010
end_define

begin_comment
comment|/* don't interpret special files */
end_comment

begin_define
define|#
directive|define
name|MNT_UNION
value|0x00000020
end_define

begin_comment
comment|/* union with underlying filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_ASYNC
value|0x00000040
end_define

begin_comment
comment|/* file system written asynchronously */
end_comment

begin_define
define|#
directive|define
name|MNT_NOATIME
value|0x10000000
end_define

begin_comment
comment|/* Disable update of file access times */
end_comment

begin_comment
comment|/*  * exported mount flags.  */
end_comment

begin_define
define|#
directive|define
name|MNT_EXRDONLY
value|0x00000080
end_define

begin_comment
comment|/* exported read only */
end_comment

begin_define
define|#
directive|define
name|MNT_EXPORTED
value|0x00000100
end_define

begin_comment
comment|/* file system is exported */
end_comment

begin_define
define|#
directive|define
name|MNT_DEFEXPORTED
value|0x00000200
end_define

begin_comment
comment|/* exported to the world */
end_comment

begin_define
define|#
directive|define
name|MNT_EXPORTANON
value|0x00000400
end_define

begin_comment
comment|/* use anon uid mapping for everyone */
end_comment

begin_define
define|#
directive|define
name|MNT_EXKERB
value|0x00000800
end_define

begin_comment
comment|/* exported with Kerberos uid mapping */
end_comment

begin_comment
comment|/*  * Flags set by internal operations.  */
end_comment

begin_define
define|#
directive|define
name|MNT_LOCAL
value|0x00001000
end_define

begin_comment
comment|/* filesystem is stored locally */
end_comment

begin_define
define|#
directive|define
name|MNT_QUOTA
value|0x00002000
end_define

begin_comment
comment|/* quotas are enabled on filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_ROOTFS
value|0x00004000
end_define

begin_comment
comment|/* identifies the root filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_USER
value|0x00008000
end_define

begin_comment
comment|/* mounted by a user */
end_comment

begin_comment
comment|/*  * Mask of flags that are visible to statfs()  */
end_comment

begin_define
define|#
directive|define
name|MNT_VISFLAGMASK
value|(MNT_RDONLY|MNT_SYNCHRONOUS|MNT_NOEXEC|MNT_NOSUID| \ 			 MNT_NODEV|MNT_UNION|MNT_ASYNC|MNT_EXRDONLY|MNT_EXPORTED| \ 			 MNT_DEFEXPORTED|MNT_EXPORTANON|MNT_EXKERB|MNT_LOCAL| \ 			 MNT_QUOTA|MNT_ROOTFS|MNT_USER|MNT_NOATIME)
end_define

begin_comment
comment|/*  * filesystem control flags.  *  * MNT_MLOCK lock the mount entry so that name lookup cannot proceed  * past the mount point.  This keeps the subtree stable during mounts  * and unmounts.  */
end_comment

begin_define
define|#
directive|define
name|MNT_UPDATE
value|0x00010000
end_define

begin_comment
comment|/* not a real mount, just an update */
end_comment

begin_define
define|#
directive|define
name|MNT_DELEXPORT
value|0x00020000
end_define

begin_comment
comment|/* delete export host lists */
end_comment

begin_define
define|#
directive|define
name|MNT_RELOAD
value|0x00040000
end_define

begin_comment
comment|/* reload filesystem data */
end_comment

begin_define
define|#
directive|define
name|MNT_FORCE
value|0x00080000
end_define

begin_comment
comment|/* force unmount or readonly change */
end_comment

begin_define
define|#
directive|define
name|MNT_MLOCK
value|0x00100000
end_define

begin_comment
comment|/* lock so that subtree is stable */
end_comment

begin_define
define|#
directive|define
name|MNT_MWAIT
value|0x00200000
end_define

begin_comment
comment|/* someone is waiting for lock */
end_comment

begin_define
define|#
directive|define
name|MNT_MPBUSY
value|0x00400000
end_define

begin_comment
comment|/* scan of mount point in progress */
end_comment

begin_define
define|#
directive|define
name|MNT_MPWANT
value|0x00800000
end_define

begin_comment
comment|/* waiting for mount point */
end_comment

begin_define
define|#
directive|define
name|MNT_UNMOUNT
value|0x01000000
end_define

begin_comment
comment|/* unmount in progress */
end_comment

begin_define
define|#
directive|define
name|MNT_WANTRDWR
value|0x02000000
end_define

begin_comment
comment|/* want upgrade to read/write */
end_comment

begin_comment
comment|/*  * used to get configured filesystems information  */
end_comment

begin_define
define|#
directive|define
name|VFS_MAXNAMELEN
value|32
end_define

begin_struct
struct|struct
name|vfsconf
block|{
name|void
modifier|*
name|vfc_vfsops
decl_stmt|;
name|char
name|vfc_name
index|[
name|VFS_MAXNAMELEN
index|]
decl_stmt|;
name|int
name|vfc_index
decl_stmt|;
name|int
name|vfc_refcount
decl_stmt|;
name|int
name|vfc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NB: these flags refer to IMPLEMENTATION properties, not properties of  * any actual mounts; i.e., it does not make sense to change the flags.  */
end_comment

begin_define
define|#
directive|define
name|VFCF_STATIC
value|0x00000001
end_define

begin_comment
comment|/* statically compiled into kernel */
end_comment

begin_define
define|#
directive|define
name|VFCF_NETWORK
value|0x00000002
end_define

begin_comment
comment|/* may get data over the network */
end_comment

begin_define
define|#
directive|define
name|VFCF_READONLY
value|0x00000004
end_define

begin_comment
comment|/* writes are not implemented */
end_comment

begin_define
define|#
directive|define
name|VFCF_SYNTHETIC
value|0x00000008
end_define

begin_comment
comment|/* data does not represent real files */
end_comment

begin_define
define|#
directive|define
name|VFCF_LOOPBACK
value|0x00000010
end_define

begin_comment
comment|/* aliases some other mounted FS */
end_comment

begin_define
define|#
directive|define
name|VFCF_UNICODE
value|0x00000020
end_define

begin_comment
comment|/* stores file names as Unicode*/
end_comment

begin_comment
comment|/*  * Operations supported on mounted file system.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|doforce
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag to permit forcible unmounting. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfsconf
name|void_vfsconf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsconf
modifier|*
name|vfsconf
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vfsops
block|{
name|int
argument_list|(
argument|*vfs_mount
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|char
operator|*
name|path
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|flags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_unmount
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|mntflags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_root
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_quotactl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|cmds
operator|,
name|uid_t
name|uid
operator|,
name|caddr_t
name|arg
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_statfs
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|statfs
operator|*
name|sbp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_sync
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|waitfor
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_vget
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|ino_t
name|ino
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_fhtovp
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|int
operator|*
name|exflagsp
operator|,
expr|struct
name|ucred
operator|*
operator|*
name|credanonp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_vptofh
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFS_MOUNT
parameter_list|(
name|MP
parameter_list|,
name|PATH
parameter_list|,
name|DATA
parameter_list|,
name|NDP
parameter_list|,
name|P
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_mount)(MP, PATH, DATA, NDP, P)
end_define

begin_define
define|#
directive|define
name|VFS_START
parameter_list|(
name|MP
parameter_list|,
name|FLAGS
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_start)(MP, FLAGS, P)
end_define

begin_define
define|#
directive|define
name|VFS_UNMOUNT
parameter_list|(
name|MP
parameter_list|,
name|FORCE
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_unmount)(MP, FORCE, P)
end_define

begin_define
define|#
directive|define
name|VFS_ROOT
parameter_list|(
name|MP
parameter_list|,
name|VPP
parameter_list|)
value|(*(MP)->mnt_op->vfs_root)(MP, VPP)
end_define

begin_define
define|#
directive|define
name|VFS_QUOTACTL
parameter_list|(
name|MP
parameter_list|,
name|C
parameter_list|,
name|U
parameter_list|,
name|A
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_quotactl)(MP, C, U, A, P)
end_define

begin_define
define|#
directive|define
name|VFS_STATFS
parameter_list|(
name|MP
parameter_list|,
name|SBP
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_statfs)(MP, SBP, P)
end_define

begin_define
define|#
directive|define
name|VFS_SYNC
parameter_list|(
name|MP
parameter_list|,
name|WAIT
parameter_list|,
name|C
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_sync)(MP, WAIT, C, P)
end_define

begin_define
define|#
directive|define
name|VFS_VGET
parameter_list|(
name|MP
parameter_list|,
name|INO
parameter_list|,
name|VPP
parameter_list|)
value|(*(MP)->mnt_op->vfs_vget)(MP, INO, VPP)
end_define

begin_define
define|#
directive|define
name|VFS_FHTOVP
parameter_list|(
name|MP
parameter_list|,
name|FIDP
parameter_list|,
name|NAM
parameter_list|,
name|VPP
parameter_list|,
name|EXFLG
parameter_list|,
name|CRED
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_fhtovp)(MP, FIDP, NAM, VPP, EXFLG, CRED)
end_define

begin_define
define|#
directive|define
name|VFS_VPTOFH
parameter_list|(
name|VP
parameter_list|,
name|FIDP
parameter_list|)
value|(*(VP)->v_mount->mnt_op->vfs_vptofh)(VP, FIDP)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VFS_LKM
end_ifdef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_define
define|#
directive|define
name|VFS_SET
parameter_list|(
name|vfsops
parameter_list|,
name|fsname
parameter_list|,
name|index
parameter_list|,
name|flags
parameter_list|)
define|\
value|static struct vfsconf _fs_vfsconf = { \&vfsops, \ 		#fsname, \ 		index, \ 		0, \ 		flags \ 	}; \ 	extern struct linker_set MODVNOPS; \ 	MOD_VFS(#fsname,index,&MODVNOPS,&_fs_vfsconf); \ 	int \ 	fsname ## _mod(struct lkm_table *lkmtp, int cmd, int ver) { \ 		DISPATCH(lkmtp, cmd, ver, lkm_nullcmd, lkm_nullcmd, lkm_nullcmd); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VFS_SET
parameter_list|(
name|vfsops
parameter_list|,
name|fsname
parameter_list|,
name|index
parameter_list|,
name|flags
parameter_list|)
define|\
value|static struct vfsconf _fs_vfsconf = { \&vfsops, \ 		#fsname, \ 		index, \ 		0, \ 		flags | VFCF_STATIC \ 	}; \ 	DATA_SET(vfs_set,_fs_vfsconf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VFS_LKM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * Flags for various system call interfaces.  *  * waitfor flags to vfs_sync() and getfsstat()  */
end_comment

begin_define
define|#
directive|define
name|MNT_WAIT
value|1
end_define

begin_define
define|#
directive|define
name|MNT_NOWAIT
value|2
end_define

begin_comment
comment|/*  * Generic file handle  */
end_comment

begin_struct
struct|struct
name|fhandle
block|{
name|fsid_t
name|fh_fsid
decl_stmt|;
comment|/* File system id of mount point */
name|struct
name|fid
name|fh_fid
decl_stmt|;
comment|/* File sys specific id */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fhandle
name|fhandle_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* XXX for AF_MAX */
end_comment

begin_comment
comment|/*  * Network address lookup element  */
end_comment

begin_struct
struct|struct
name|netcred
block|{
name|struct
name|radix_node
name|netc_rnodes
index|[
literal|2
index|]
decl_stmt|;
name|int
name|netc_exflags
decl_stmt|;
name|struct
name|ucred
name|netc_anon
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Network export information  */
end_comment

begin_struct
struct|struct
name|netexport
block|{
name|struct
name|netcred
name|ne_defexported
decl_stmt|;
comment|/* Default export */
name|struct
name|radix_node_head
modifier|*
name|ne_rtable
index|[
name|AF_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Individual exports */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * Export arguments for local filesystem mount calls.  */
end_comment

begin_struct
struct|struct
name|export_args
block|{
name|int
name|ex_flags
decl_stmt|;
comment|/* export related flags */
name|uid_t
name|ex_root
decl_stmt|;
comment|/* mapping for root uid */
name|struct
name|ucred
name|ex_anon
decl_stmt|;
comment|/* mapping for anonymous user */
name|struct
name|sockaddr
modifier|*
name|ex_addr
decl_stmt|;
comment|/* net address to which exported */
name|int
name|ex_addrlen
decl_stmt|;
comment|/* and the net address length */
name|struct
name|sockaddr
modifier|*
name|ex_mask
decl_stmt|;
comment|/* mask of valid bits in saddr */
name|int
name|ex_masklen
decl_stmt|;
comment|/* and the smask length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arguments to mount UFS-based filesystems  */
end_comment

begin_struct
struct|struct
name|ufs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MFS
end_ifdef

begin_comment
comment|/*  * Arguments to mount MFS  */
end_comment

begin_struct
struct|struct
name|mfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* name to export for statfs */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* if exported MFSes are supported */
name|caddr_t
name|base
decl_stmt|;
comment|/* base of file system in memory */
name|u_long
name|size
decl_stmt|;
comment|/* size of file system */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOSFS
end_ifdef

begin_comment
comment|/*  *  Arguments to mount MSDOS filesystems.  */
end_comment

begin_struct
struct|struct
name|msdosfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* blocks special holding the fs to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
name|uid_t
name|uid
decl_stmt|;
comment|/* uid that owns msdosfs files */
name|gid_t
name|gid
decl_stmt|;
comment|/* gid that owns msdosfs files */
name|mode_t
name|mask
decl_stmt|;
comment|/* mask to be applied for msdosfs perms */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CD9660
end_ifdef

begin_comment
comment|/*  * Arguments to mount ISO 9660 filesystems.  */
end_comment

begin_struct
struct|struct
name|iso_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export info */
name|int
name|flags
decl_stmt|;
comment|/* mounting flags, see below */
name|int
name|ssector
decl_stmt|;
comment|/* starting sector */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISOFSMNT_NORRIP
value|0x00000001
end_define

begin_comment
comment|/* disable Rock Ridge Ext.*/
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_GENS
value|0x00000002
end_define

begin_comment
comment|/* enable generation numbers */
end_comment

begin_define
define|#
directive|define
name|ISOFSMNT_EXTATT
value|0x00000004
end_define

begin_comment
comment|/* enable extended attributes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CD9660 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_comment
comment|/*  * Arguments to mount NFS  */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|int
name|addrlen
decl_stmt|;
comment|/* length of address */
name|int
name|sotype
decl_stmt|;
comment|/* Socket type */
name|int
name|proto
decl_stmt|;
comment|/* and Protocol */
name|u_char
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
name|int
name|fhsize
decl_stmt|;
comment|/* Size, in bytes, of fh */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|wsize
decl_stmt|;
comment|/* write size in bytes */
name|int
name|rsize
decl_stmt|;
comment|/* read size in bytes */
name|int
name|readdirsize
decl_stmt|;
comment|/* readdir size in bytes */
name|int
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|int
name|maxgrouplist
decl_stmt|;
comment|/* Max. size of group list */
name|int
name|readahead
decl_stmt|;
comment|/* # of blocks to readahead */
name|int
name|leaseterm
decl_stmt|;
comment|/* Term (sec) of lease */
name|int
name|deadthresh
decl_stmt|;
comment|/* Retrans threshold */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SOFT
value|0x00000001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x00000002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x00000004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x00000008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x00000010
end_define

begin_comment
comment|/* set number of request retrys */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MAXGRPS
value|0x00000020
end_define

begin_comment
comment|/* set maximum grouplist size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x00000040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCONN
value|0x00000080
end_define

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NQNFS
value|0x00000100
end_define

begin_comment
comment|/* Use Nqnfs protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NFSV3
value|0x00000200
end_define

begin_comment
comment|/* Use NFS Version 3 protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_KERB
value|0x00000400
end_define

begin_comment
comment|/* Use Kerberos authentication */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DUMBTIMR
value|0x00000800
end_define

begin_comment
comment|/* Don't estimate rtt dynamically */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_LEASETERM
value|0x00001000
end_define

begin_comment
comment|/* set lease term (nqnfs) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READAHEAD
value|0x00002000
end_define

begin_comment
comment|/* set read ahead */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DEADTHRESH
value|0x00004000
end_define

begin_comment
comment|/* set dead server retry thresh */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RESVPORT
value|0x00008000
end_define

begin_comment
comment|/* Allocate a reserved port */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RDIRPLUS
value|0x00010000
end_define

begin_comment
comment|/* Use Readdirplus for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READDIRSIZE
value|0x00020000
end_define

begin_comment
comment|/* Set readdir size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INTERNAL
value|0xfffc0000
end_define

begin_comment
comment|/* Bits set internally */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HASWRITEVERF
value|0x00040000
end_define

begin_comment
comment|/* Has write verifier for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_GOTPATHCONF
value|0x00080000
end_define

begin_comment
comment|/* Got the V3 pathconf info */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_GOTFSINFO
value|0x00100000
end_define

begin_comment
comment|/* Got the V3 fsinfo */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MNTD
value|0x00200000
end_define

begin_comment
comment|/* Mnt server for mnt point */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DISMINPROG
value|0x00400000
end_define

begin_comment
comment|/* Dismount in progress */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DISMNT
value|0x00800000
end_define

begin_comment
comment|/* Dismounted */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SNDLOCK
value|0x01000000
end_define

begin_comment
comment|/* Send socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTSND
value|0x02000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RCVLOCK
value|0x04000000
end_define

begin_comment
comment|/* Rcv socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTRCV
value|0x08000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WAITAUTH
value|0x10000000
end_define

begin_comment
comment|/* Wait for authentication */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HASAUTH
value|0x20000000
end_define

begin_comment
comment|/* Has authenticator */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTAUTH
value|0x40000000
end_define

begin_comment
comment|/* Wants an authenticator */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_AUTHERR
value|0x80000000
end_define

begin_comment
comment|/* Authentication error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_extern
extern|extern	int (*mountroot
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
modifier|*
name|mountrootvfsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * exported vnode operations  */
end_comment

begin_decl_stmt
name|int
name|dounmount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mount
modifier|*
name|getvfs
name|__P
argument_list|(
operator|(
name|fsid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return vfs given fsid */
end_comment

begin_decl_stmt
name|void
name|getnewfsid
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vflush
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_export
comment|/* process mount export info */
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|netexport
operator|*
operator|,
expr|struct
name|export_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|netcred
modifier|*
name|vfs_export_lookup
comment|/* lookup host in fs export list */
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|netexport
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock a vfs */
end_comment

begin_decl_stmt
name|int
name|vfs_mountedon
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is a vfs mounted on vp */
end_comment

begin_decl_stmt
name|int
name|vfs_mountroot
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX goes away? */
end_comment

begin_decl_stmt
name|void
name|vfs_msync
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unlock a vfs */
end_comment

begin_decl_stmt
name|void
name|vfs_unmountall
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_busy
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mark a vfs  busy */
end_comment

begin_decl_stmt
name|void
name|vfs_unbusy
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mark a vfs not busy */
end_comment

begin_extern
extern|extern	CIRCLEQ_HEAD(mntlist
operator|,
extern|mount
end_extern

begin_expr_stmt
unit|)
name|mountlist
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mounted filesystem list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
modifier|*
name|vfssw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filesystem type table */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|fstatfs
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|statfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getfh
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|fhandle_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getfsstat
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getmntinfo
name|__P
argument_list|(
operator|(
expr|struct
name|statfs
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mount
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|statfs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|statfs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unmount
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C library stuff */
end_comment

begin_decl_stmt
name|struct
name|vfsconf
modifier|*
name|getvfsbyname
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vfsconf
modifier|*
name|getvfsbytype
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vfsconf
modifier|*
name|getvfsent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setvfsent
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endvfsent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfsisloadable
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfsload
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MOUNT_H_ */
end_comment

end_unit

