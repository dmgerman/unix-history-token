begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mount.h	7.18 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|quad
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
name|short
name|f_type
decl_stmt|;
comment|/* type of filesystem (see below) */
name|short
name|f_flags
decl_stmt|;
comment|/* copy of mount flags */
name|long
name|f_fsize
decl_stmt|;
comment|/* fundamental file system block size */
name|long
name|f_bsize
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
name|long
name|f_spare
index|[
literal|9
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

begin_define
define|#
directive|define
name|MOUNT_NFS
value|2
end_define

begin_define
define|#
directive|define
name|MOUNT_MFS
value|3
end_define

begin_define
define|#
directive|define
name|MOUNT_PC
value|4
end_define

begin_define
define|#
directive|define
name|MOUNT_MAXTYPE
value|4
end_define

begin_comment
comment|/*  * Structure per mounted file system.  * Each mounted file system has an array of  * operations and an instance record.  * The file systems are put on a doubly linked list.  */
end_comment

begin_struct
struct|struct
name|mount
block|{
name|struct
name|mount
modifier|*
name|mnt_next
decl_stmt|;
comment|/* next in mount list */
name|struct
name|mount
modifier|*
name|mnt_prev
decl_stmt|;
comment|/* prev in mount list */
name|struct
name|vfsops
modifier|*
name|mnt_op
decl_stmt|;
comment|/* operations on fs */
name|struct
name|vnode
modifier|*
name|mnt_vnodecovered
decl_stmt|;
comment|/* vnode we mounted on */
name|struct
name|vnode
modifier|*
name|mnt_mounth
decl_stmt|;
comment|/* list of vnodes this mount */
name|int
name|mnt_flag
decl_stmt|;
comment|/* flags */
name|uid_t
name|mnt_exroot
decl_stmt|;
comment|/* exported mapping for uid 0 */
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
comment|/*  * Mount flags.  */
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

begin_comment
comment|/*  * exported mount flags.  */
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
name|MNT_EXRDONLY
value|0x00000200
end_define

begin_comment
comment|/* exported read only */
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

begin_comment
comment|/*  * Operations supported on mounted file system.  */
end_comment

begin_struct
struct|struct
name|vfsops
block|{
name|int
function_decl|(
modifier|*
name|vfs_mount
function_decl|)
parameter_list|(
comment|/* mp, path, data, ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_start
function_decl|)
parameter_list|(
comment|/* mp, flags */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_unmount
function_decl|)
parameter_list|(
comment|/* mp, forcibly */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_root
function_decl|)
parameter_list|(
comment|/* mp, vpp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_quotactl
function_decl|)
parameter_list|(
comment|/* mp, cmd, uid, arg */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_statfs
function_decl|)
parameter_list|(
comment|/* mp, sbp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_sync
function_decl|)
parameter_list|(
comment|/* mp, waitfor */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_fhtovp
function_decl|)
parameter_list|(
comment|/* mp, fidp, vpp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_vptofh
function_decl|)
parameter_list|(
comment|/* vp, fidp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_init
function_decl|)
parameter_list|(
comment|/* */
parameter_list|)
function_decl|;
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
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_mount)(MP, PATH, DATA, NDP)
end_define

begin_define
define|#
directive|define
name|VFS_START
parameter_list|(
name|MP
parameter_list|,
name|FLAGS
parameter_list|)
value|(*(MP)->mnt_op->vfs_start)(MP, FLAGS)
end_define

begin_define
define|#
directive|define
name|VFS_UNMOUNT
parameter_list|(
name|MP
parameter_list|,
name|FORCIBLY
parameter_list|)
value|(*(MP)->mnt_op->vfs_unmount)(MP, FORCIBLY)
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
parameter_list|)
value|(*(MP)->mnt_op->vfs_quotactl)(MP, C, U, A)
end_define

begin_define
define|#
directive|define
name|VFS_STATFS
parameter_list|(
name|MP
parameter_list|,
name|SBP
parameter_list|)
value|(*(MP)->mnt_op->vfs_statfs)(MP, SBP)
end_define

begin_define
define|#
directive|define
name|VFS_SYNC
parameter_list|(
name|MP
parameter_list|,
name|WAITFOR
parameter_list|)
value|(*(MP)->mnt_op->vfs_sync)(MP, WAITFOR)
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
name|VPP
parameter_list|)
value|(*(MP)->mnt_op->vfs_fhtovp)(MP, FIDP, VPP)
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
comment|/*  * Flags for various system call interfaces.  *  * forcibly flags for vfs_umount().  * waitfor flags to vfs_sync() and getfsstat()  */
end_comment

begin_define
define|#
directive|define
name|MNT_FORCE
value|1
end_define

begin_define
define|#
directive|define
name|MNT_NOFORCE
value|2
end_define

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
comment|/* Id of file */
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
comment|/*  * Arguments to mount UFS  */
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
name|int
name|exflags
decl_stmt|;
comment|/* export related flags */
name|uid_t
name|exroot
decl_stmt|;
comment|/* mapping for root uid */
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
name|name
decl_stmt|;
comment|/* name to export for statfs */
name|caddr_t
name|base
decl_stmt|;
comment|/* base address of file system in memory */
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
endif|MFS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_comment
comment|/*  * File Handle (32 bytes for version 2), variable up to 1024 for version 3  */
end_comment

begin_union
union|union
name|nfsv2fh
block|{
name|fhandle_t
name|fh_generic
decl_stmt|;
name|u_char
name|fh_bytes
index|[
literal|32
index|]
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|nfsv2fh
name|nfsv2fh_t
typedef|;
end_typedef

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
name|sotype
decl_stmt|;
comment|/* Socket type */
name|int
name|proto
decl_stmt|;
comment|/* and Protocol */
name|nfsv2fh_t
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
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
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
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
value|0x0001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x0002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x0004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x0008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x0010
end_define

begin_comment
comment|/* set number of request retrys */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HOSTNAME
value|0x0020
end_define

begin_comment
comment|/* set hostname for error printf */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x0040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCONN
value|0x0080
end_define

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SCKLOCK
value|0x0100
end_define

begin_comment
comment|/* Lock socket against others */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTSCK
value|0x0200
end_define

begin_comment
comment|/* Want a socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SPONGY
value|0x0400
end_define

begin_comment
comment|/* spongy mount (soft for stat and lookup) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_COMPRESS
value|0x0800
end_define

begin_comment
comment|/* Compress nfs rpc xdr */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_LOCKBITS
value|(NFSMNT_SCKLOCK | NFSMNT_WANTSCK)
end_define

begin_endif
endif|#
directive|endif
endif|NFS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * exported vnode operations  */
end_comment

begin_function_decl
specifier|extern
name|void
name|vfs_remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove a vfs from mounted vfs list */
end_comment

begin_function_decl
specifier|extern
name|int
name|vfs_lock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* lock a vfs */
end_comment

begin_function_decl
specifier|extern
name|void
name|vfs_unlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* unlock a vfs */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mount
modifier|*
name|getvfs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return vfs given fsid */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mount
modifier|*
name|rootfs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to root mount structure */
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
comment|/* mount filesystem type switch table */
end_comment

begin_else
else|#
directive|else
end_else

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
expr|struct
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
name|caddr_t
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

end_unit

