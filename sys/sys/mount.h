begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mount.h	8.21 (Berkeley) 5/20/95  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
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
name|MFSNAMELEN
value|16
end_define

begin_comment
comment|/* length of fs type name, including null */
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
name|short
name|f_type
decl_stmt|;
comment|/* filesystem type number */
name|short
name|f_flags
decl_stmt|;
comment|/* copy of mount flags */
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
name|long
name|f_spare
index|[
literal|4
index|]
decl_stmt|;
comment|/* spare for later */
name|char
name|f_fstypename
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
comment|/* fs type name */
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
name|struct
name|lock
name|mnt_lock
decl_stmt|;
comment|/* mount structure lock */
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

begin_comment
comment|/*  * Mask of flags that are visible to statfs()  */
end_comment

begin_define
define|#
directive|define
name|MNT_VISFLAGMASK
value|0x0000ffff
end_define

begin_comment
comment|/*  * External filesystem control flags.  */
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

begin_comment
comment|/*  * Internal filesystem control flags.  *  * MNT_UNMOUNT locks the mount entry so that name lookup cannot proceed  * past the mount point.  This keeps the subtree stable during mounts  * and unmounts.  */
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
name|MNT_MWAIT
value|0x02000000
end_define

begin_comment
comment|/* waiting for unmount to finish */
end_comment

begin_define
define|#
directive|define
name|MNT_WANTRDWR
value|0x04000000
end_define

begin_comment
comment|/* upgrade to read/write requested */
end_comment

begin_comment
comment|/*  * Sysctl CTL_VFS definitions.  *  * Second level identifier specifies which filesystem. Second level  * identifier VFS_GENERIC returns information about all filesystems.  */
end_comment

begin_define
define|#
directive|define
name|VFS_GENERIC
value|0
end_define

begin_comment
comment|/* generic filesystem information */
end_comment

begin_comment
comment|/*  * Third level identifiers for VFS_GENERIC are given below; third  * level identifiers for specific filesystems are given in their  * mount specific header files.  */
end_comment

begin_define
define|#
directive|define
name|VFS_MAXTYPENUM
value|1
end_define

begin_comment
comment|/* int: highest defined filesystem type */
end_comment

begin_define
define|#
directive|define
name|VFS_CONF
value|2
end_define

begin_comment
comment|/* struct: vfsconf for filesystem given 				   as next argument */
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
comment|/*  * Filesystem configuration information. One of these exists for each  * type of filesystem supported by the kernel. These are searched at  * mount time to identify the requested filesystem.  */
end_comment

begin_struct
struct|struct
name|vfsconf
block|{
name|struct
name|vfsops
modifier|*
name|vfc_vfsops
decl_stmt|;
comment|/* filesystem operations vector */
name|char
name|vfc_name
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
comment|/* filesystem type name */
name|int
name|vfc_typenum
decl_stmt|;
comment|/* historic filesystem type number */
name|int
name|vfc_refcount
decl_stmt|;
comment|/* number mounted of this type */
name|int
name|vfc_flags
decl_stmt|;
comment|/* permanent flags */
name|int
function_decl|(
modifier|*
name|vfc_mountroot
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* if != NULL, routine to mount root */
name|struct
name|vfsconf
modifier|*
name|vfc_next
decl_stmt|;
comment|/* next in list */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|maxvfsconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* highest defined filesystem type */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfsconf
modifier|*
name|vfsconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of filesystem types */
end_comment

begin_comment
comment|/*  * Operations supported on mounted file system.  */
end_comment

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
expr|struct
name|vfsconf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vfs_sysctl
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|u_int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|*
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
expr|struct
name|proc
operator|*
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

begin_comment
comment|/*  * exported vnode operations  */
end_comment

begin_decl_stmt
name|int
name|vfs_busy
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
name|simplelock
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_export
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
name|void
name|vfs_getnewfsid
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

begin_decl_stmt
name|struct
name|mount
modifier|*
name|vfs_getvfs
name|__P
argument_list|(
operator|(
name|fsid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|vfs_mountroot
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
name|vfs_rootmountalloc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|mount
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_unbusy
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|struct
name|simplelock
name|mountlist_slock
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
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
specifier|const
name|char
operator|*
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

end_unit

