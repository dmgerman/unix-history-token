begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mount.h	8.21 (Berkeley) 5/20/95  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/lockmgr.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|fsid
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
comment|/* filesystem id type */
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
comment|/*  * filesystem statistics  */
end_comment

begin_define
define|#
directive|define
name|MFSNAMELEN
value|16
end_define

begin_comment
comment|/* length of type name including null */
end_comment

begin_define
define|#
directive|define
name|MNAMELEN
value|88
end_define

begin_comment
comment|/* size of on/from name bufs */
end_comment

begin_define
define|#
directive|define
name|STATFS_VERSION
value|0x20030518
end_define

begin_comment
comment|/* current version number */
end_comment

begin_struct
struct|struct
name|statfs
block|{
name|uint32_t
name|f_version
decl_stmt|;
comment|/* structure version number */
name|uint32_t
name|f_type
decl_stmt|;
comment|/* type of filesystem */
name|uint64_t
name|f_flags
decl_stmt|;
comment|/* copy of mount exported flags */
name|uint64_t
name|f_bsize
decl_stmt|;
comment|/* filesystem fragment size */
name|uint64_t
name|f_iosize
decl_stmt|;
comment|/* optimal transfer block size */
name|uint64_t
name|f_blocks
decl_stmt|;
comment|/* total data blocks in filesystem */
name|uint64_t
name|f_bfree
decl_stmt|;
comment|/* free blocks in filesystem */
name|int64_t
name|f_bavail
decl_stmt|;
comment|/* free blocks avail to non-superuser */
name|uint64_t
name|f_files
decl_stmt|;
comment|/* total file nodes in filesystem */
name|int64_t
name|f_ffree
decl_stmt|;
comment|/* free nodes avail to non-superuser */
name|uint64_t
name|f_syncwrites
decl_stmt|;
comment|/* count of sync writes since mount */
name|uint64_t
name|f_asyncwrites
decl_stmt|;
comment|/* count of async writes since mount */
name|uint64_t
name|f_syncreads
decl_stmt|;
comment|/* count of sync reads since mount */
name|uint64_t
name|f_asyncreads
decl_stmt|;
comment|/* count of async reads since mount */
name|uint64_t
name|f_spare
index|[
literal|10
index|]
decl_stmt|;
comment|/* unused spare */
name|uint32_t
name|f_namemax
decl_stmt|;
comment|/* maximum filename length */
name|uid_t
name|f_owner
decl_stmt|;
comment|/* user that mounted the filesystem */
name|fsid_t
name|f_fsid
decl_stmt|;
comment|/* filesystem id */
name|char
name|f_charspare
index|[
literal|80
index|]
decl_stmt|;
comment|/* spare string space */
name|char
name|f_fstypename
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
comment|/* filesystem type name */
name|char
name|f_mntfromname
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* mounted filesystem */
name|char
name|f_mntonname
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* directory on which mounted */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|OMFSNAMELEN
value|16
end_define

begin_comment
comment|/* length of fs type name, including null */
end_comment

begin_define
define|#
directive|define
name|OMNAMELEN
value|(88 - 2 * sizeof(long))
end_define

begin_comment
comment|/* size of on/from name bufs */
end_comment

begin_comment
comment|/* XXX getfsstat.2 is out of date with write and read counter changes here. */
end_comment

begin_comment
comment|/* XXX statfs.2 is out of date with read counter changes here. */
end_comment

begin_struct
struct|struct
name|ostatfs
block|{
name|long
name|f_spare2
decl_stmt|;
comment|/* placeholder */
name|long
name|f_bsize
decl_stmt|;
comment|/* fundamental filesystem block size */
name|long
name|f_iosize
decl_stmt|;
comment|/* optimal transfer block size */
name|long
name|f_blocks
decl_stmt|;
comment|/* total data blocks in filesystem */
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
comment|/* total file nodes in filesystem */
name|long
name|f_ffree
decl_stmt|;
comment|/* free file nodes in fs */
name|fsid_t
name|f_fsid
decl_stmt|;
comment|/* filesystem id */
name|uid_t
name|f_owner
decl_stmt|;
comment|/* user that mounted the filesystem */
name|int
name|f_type
decl_stmt|;
comment|/* type of filesystem */
name|int
name|f_flags
decl_stmt|;
comment|/* copy of mount exported flags */
name|long
name|f_syncwrites
decl_stmt|;
comment|/* count of sync writes since mount */
name|long
name|f_asyncwrites
decl_stmt|;
comment|/* count of async writes since mount */
name|char
name|f_fstypename
index|[
name|OMFSNAMELEN
index|]
decl_stmt|;
comment|/* fs type name */
name|char
name|f_mntonname
index|[
name|OMNAMELEN
index|]
decl_stmt|;
comment|/* directory on which mounted */
name|long
name|f_syncreads
decl_stmt|;
comment|/* count of sync reads since mount */
name|long
name|f_asyncreads
decl_stmt|;
comment|/* count of async reads since mount */
name|short
name|f_spares1
decl_stmt|;
comment|/* unused spare */
name|char
name|f_mntfromname
index|[
name|OMNAMELEN
index|]
decl_stmt|;
comment|/* mounted filesystem */
name|short
name|f_spares2
decl_stmt|;
comment|/* unused spare */
comment|/* 	 * XXX on machines where longs are aligned to 8-byte boundaries, there 	 * is an unnamed int32_t here.  This spare was after the apparent end 	 * of the struct until we bit off the read counters from f_mntonname. 	 */
name|long
name|f_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* unused spare */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MMAXOPTIONLEN
value|65536
end_define

begin_comment
comment|/* maximum length of a mount option */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|vnodelst
argument_list|,
name|vnode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|vfsoptlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfsopt
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Structure per mounted filesystem.  Each mounted filesystem has an  * array of operations and an instance record.  The filesystems are  * put on a doubly linked list.  *  * Lock reference:  *	m - mountlist_mtx  *	i - interlock  *	l - mnt_lock  *  * Unmarked fields are considered stable as long as a ref is held.  *  */
end_comment

begin_struct
struct|struct
name|mount
block|{
name|struct
name|lock
name|mnt_lock
decl_stmt|;
comment|/* mount structure lock */
name|struct
name|mtx
name|mnt_mtx
decl_stmt|;
comment|/* mount structure interlock */
name|int
name|mnt_gen
decl_stmt|;
comment|/* struct mount generation */
define|#
directive|define
name|mnt_startzero
value|mnt_list
name|TAILQ_ENTRY
argument_list|(
argument|mount
argument_list|)
name|mnt_list
expr_stmt|;
comment|/* (m) mount list */
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
name|vnode
modifier|*
name|mnt_syncer
decl_stmt|;
comment|/* syncer vnode */
name|int
name|mnt_ref
decl_stmt|;
comment|/* (i) Reference count */
name|struct
name|vnodelst
name|mnt_nvnodelist
decl_stmt|;
comment|/* (i) list of vnodes */
name|int
name|mnt_nvnodelistsize
decl_stmt|;
comment|/* (i) # of vnodes */
name|int
name|mnt_writeopcount
decl_stmt|;
comment|/* (i) write syscalls pending */
name|int
name|mnt_kern_flag
decl_stmt|;
comment|/* (i) kernel only flags */
name|u_int
name|mnt_flag
decl_stmt|;
comment|/* (i) flags shared with user */
name|u_int
name|mnt_noasync
decl_stmt|;
comment|/* (i) # noasync overrides */
name|struct
name|vfsoptlist
modifier|*
name|mnt_opt
decl_stmt|;
comment|/* current mount options */
name|struct
name|vfsoptlist
modifier|*
name|mnt_optnew
decl_stmt|;
comment|/* new options passed to fs */
name|int
name|mnt_maxsymlinklen
decl_stmt|;
comment|/* max size of short symlink */
name|struct
name|statfs
name|mnt_stat
decl_stmt|;
comment|/* cache of filesystem stats */
name|struct
name|ucred
modifier|*
name|mnt_cred
decl_stmt|;
comment|/* credentials of mounter */
name|void
modifier|*
name|mnt_data
decl_stmt|;
comment|/* private data */
name|time_t
name|mnt_time
decl_stmt|;
comment|/* last time written*/
name|int
name|mnt_iosize_max
decl_stmt|;
comment|/* max size for clusters, etc */
name|struct
name|netexport
modifier|*
name|mnt_export
decl_stmt|;
comment|/* export list */
name|struct
name|label
modifier|*
name|mnt_mntlabel
decl_stmt|;
comment|/* MAC label for the mount */
name|struct
name|label
modifier|*
name|mnt_fslabel
decl_stmt|;
comment|/* MAC label for the fs */
name|u_int
name|mnt_hashseed
decl_stmt|;
comment|/* Random seed for vfs_hash */
name|int
name|mnt_markercnt
decl_stmt|;
comment|/* marker vnodes in use */
name|int
name|mnt_holdcnt
decl_stmt|;
comment|/* hold count */
name|int
name|mnt_holdcntwaiters
decl_stmt|;
comment|/* waits on hold count */
name|int
name|mnt_secondary_writes
decl_stmt|;
comment|/* (i) # of secondary writes */
name|int
name|mnt_secondary_accwrites
decl_stmt|;
comment|/* (i) secondary wr. starts */
define|#
directive|define
name|mnt_endzero
value|mnt_gjprovider
name|char
modifier|*
name|mnt_gjprovider
decl_stmt|;
comment|/* gjournal provider name */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|vnode
modifier|*
name|__mnt_vnode_next
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|mvp
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|__mnt_vnode_first
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|mvp
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__mnt_vnode_markerfree
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|mvp
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MNT_VNODE_FOREACH
parameter_list|(
name|vp
parameter_list|,
name|mp
parameter_list|,
name|mvp
parameter_list|)
define|\
value|for (vp = __mnt_vnode_first(&(mvp), (mp)); \ 		(vp) != NULL; vp = __mnt_vnode_next(&(mvp), (mp)))
end_define

begin_define
define|#
directive|define
name|MNT_VNODE_FOREACH_ABORT_ILOCKED
parameter_list|(
name|mp
parameter_list|,
name|mvp
parameter_list|)
define|\
value|__mnt_vnode_markerfree(&(mvp), (mp))
end_define

begin_define
define|#
directive|define
name|MNT_VNODE_FOREACH_ABORT
parameter_list|(
name|mp
parameter_list|,
name|mvp
parameter_list|)
define|\
value|do {								\ 	  MNT_ILOCK(mp);						\           MNT_VNODE_FOREACH_ABORT_ILOCKED(mp, mvp);			\ 	  MNT_IUNLOCK(mp);						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|MNT_ILOCK
parameter_list|(
name|mp
parameter_list|)
value|mtx_lock(&(mp)->mnt_mtx)
end_define

begin_define
define|#
directive|define
name|MNT_ITRYLOCK
parameter_list|(
name|mp
parameter_list|)
value|mtx_trylock(&(mp)->mnt_mtx)
end_define

begin_define
define|#
directive|define
name|MNT_IUNLOCK
parameter_list|(
name|mp
parameter_list|)
value|mtx_unlock(&(mp)->mnt_mtx)
end_define

begin_define
define|#
directive|define
name|MNT_MTX
parameter_list|(
name|mp
parameter_list|)
value|(&(mp)->mnt_mtx)
end_define

begin_define
define|#
directive|define
name|MNT_REF
parameter_list|(
name|mp
parameter_list|)
value|(mp)->mnt_ref++
end_define

begin_define
define|#
directive|define
name|MNT_REL
parameter_list|(
name|mp
parameter_list|)
value|do {						\ 	(mp)->mnt_ref--;						\ 	if ((mp)->mnt_ref == 0)						\ 		wakeup((mp));						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * User specifiable flags.  */
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
comment|/* filesystem written synchronously */
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
comment|/* filesystem written asynchronously */
end_comment

begin_define
define|#
directive|define
name|MNT_SUIDDIR
value|0x00100000
end_define

begin_comment
comment|/* special handling of SUID on dirs */
end_comment

begin_define
define|#
directive|define
name|MNT_SOFTDEP
value|0x00200000
end_define

begin_comment
comment|/* soft updates being done */
end_comment

begin_define
define|#
directive|define
name|MNT_NOSYMFOLLOW
value|0x00400000
end_define

begin_comment
comment|/* do not follow symlinks */
end_comment

begin_define
define|#
directive|define
name|MNT_GJOURNAL
value|0x02000000
end_define

begin_comment
comment|/* GEOM journal support enabled */
end_comment

begin_define
define|#
directive|define
name|MNT_MULTILABEL
value|0x04000000
end_define

begin_comment
comment|/* MAC support for individual objects */
end_comment

begin_define
define|#
directive|define
name|MNT_ACLS
value|0x08000000
end_define

begin_comment
comment|/* ACL support enabled */
end_comment

begin_define
define|#
directive|define
name|MNT_NOATIME
value|0x10000000
end_define

begin_comment
comment|/* disable update of file access time */
end_comment

begin_define
define|#
directive|define
name|MNT_NOCLUSTERR
value|0x40000000
end_define

begin_comment
comment|/* disable cluster read */
end_comment

begin_define
define|#
directive|define
name|MNT_NOCLUSTERW
value|0x80000000
end_define

begin_comment
comment|/* disable cluster write */
end_comment

begin_comment
comment|/*  * NFS export related mount flags.  */
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
comment|/* filesystem is exported */
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

begin_define
define|#
directive|define
name|MNT_EXPUBLIC
value|0x20000000
end_define

begin_comment
comment|/* public export (WebNFS) */
end_comment

begin_comment
comment|/*  * Flags set by internal operations,  * but visible to the user.  * XXX some of these are not quite right.. (I've never seen the root flag set)  */
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

begin_define
define|#
directive|define
name|MNT_IGNORE
value|0x00800000
end_define

begin_comment
comment|/* do not show entry in df */
end_comment

begin_comment
comment|/*  * Mask of flags that are visible to statfs().  * XXX I think that this could now become (~(MNT_CMDFLAGS))  * but the 'mount' program may need changing to handle this.  */
end_comment

begin_define
define|#
directive|define
name|MNT_VISFLAGMASK
value|(MNT_RDONLY	| MNT_SYNCHRONOUS | MNT_NOEXEC	| \ 			MNT_NOSUID	| MNT_UNION	| \ 			MNT_ASYNC	| MNT_EXRDONLY	| MNT_EXPORTED	| \ 			MNT_DEFEXPORTED	| MNT_EXPORTANON| MNT_EXKERB	| \ 			MNT_LOCAL	| MNT_USER	| MNT_QUOTA	| \ 			MNT_ROOTFS	| MNT_NOATIME	| MNT_NOCLUSTERR| \ 			MNT_NOCLUSTERW	| MNT_SUIDDIR	| MNT_SOFTDEP	| \ 			MNT_IGNORE	| MNT_EXPUBLIC	| MNT_NOSYMFOLLOW | \ 			MNT_GJOURNAL	| MNT_MULTILABEL | MNT_ACLS)
end_define

begin_comment
comment|/* Mask of flags that can be updated. */
end_comment

begin_define
define|#
directive|define
name|MNT_UPDATEMASK
value|(MNT_NOSUID	| MNT_NOEXEC	| \ 			MNT_SYNCHRONOUS	| MNT_UNION	| MNT_ASYNC	| \ 			MNT_NOATIME | \ 			MNT_NOSYMFOLLOW	| MNT_IGNORE	| \ 			MNT_NOCLUSTERR	| MNT_NOCLUSTERW | MNT_SUIDDIR	| \ 			MNT_ACLS	| MNT_USER)
end_define

begin_comment
comment|/*  * External filesystem command modifier flags.  * Unmount can use the MNT_FORCE flag.  * XXX: These are not STATES and really should be somewhere else.  * XXX: MNT_BYFSID collides with MNT_ACLS, but because MNT_ACLS is only used for  *      mount(2) and MNT_BYFSID is only used for unmount(2) it's harmless.  */
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
name|MNT_SNAPSHOT
value|0x01000000
end_define

begin_comment
comment|/* snapshot the filesystem */
end_comment

begin_define
define|#
directive|define
name|MNT_BYFSID
value|0x08000000
end_define

begin_comment
comment|/* specify filesystem by ID. */
end_comment

begin_define
define|#
directive|define
name|MNT_CMDFLAGS
value|(MNT_UPDATE	| MNT_DELEXPORT	| MNT_RELOAD	| \ 			MNT_FORCE	| MNT_SNAPSHOT	| MNT_BYFSID)
end_define

begin_comment
comment|/*  * Still available.  */
end_comment

begin_define
define|#
directive|define
name|MNT_SPARE_0x00000010
value|0x00000010
end_define

begin_comment
comment|/*  * Internal filesystem control flags stored in mnt_kern_flag.  *  * MNTK_UNMOUNT locks the mount entry so that name lookup cannot proceed  * past the mount point.  This keeps the subtree stable during mounts  * and unmounts.  *  * MNTK_UNMOUNTF permits filesystems to detect a forced unmount while  * dounmount() is still waiting to lock the mountpoint. This allows  * the filesystem to cancel operations that might otherwise deadlock  * with the unmount attempt (used by NFS).  */
end_comment

begin_define
define|#
directive|define
name|MNTK_UNMOUNTF
value|0x00000001
end_define

begin_comment
comment|/* forced unmount in progress */
end_comment

begin_define
define|#
directive|define
name|MNTK_ASYNC
value|0x00000002
end_define

begin_comment
comment|/* filtered async flag */
end_comment

begin_define
define|#
directive|define
name|MNTK_SOFTDEP
value|0x00000004
end_define

begin_comment
comment|/* async disabled by softdep */
end_comment

begin_define
define|#
directive|define
name|MNTK_UNMOUNT
value|0x01000000
end_define

begin_comment
comment|/* unmount in progress */
end_comment

begin_define
define|#
directive|define
name|MNTK_MWAIT
value|0x02000000
end_define

begin_comment
comment|/* waiting for unmount to finish */
end_comment

begin_define
define|#
directive|define
name|MNTK_SUSPEND
value|0x08000000
end_define

begin_comment
comment|/* request write suspension */
end_comment

begin_define
define|#
directive|define
name|MNTK_SUSPEND2
value|0x04000000
end_define

begin_comment
comment|/* block secondary writes */
end_comment

begin_define
define|#
directive|define
name|MNTK_SUSPENDED
value|0x10000000
end_define

begin_comment
comment|/* write operations are suspended */
end_comment

begin_define
define|#
directive|define
name|MNTK_MPSAFE
value|0x20000000
end_define

begin_comment
comment|/* Filesystem is MPSAFE. */
end_comment

begin_define
define|#
directive|define
name|MNTK_NOKNOTE
value|0x80000000
end_define

begin_comment
comment|/* Don't send KNOTEs from VOP hooks */
end_comment

begin_define
define|#
directive|define
name|MNTK_LOOKUP_SHARED
value|0x40000000
end_define

begin_comment
comment|/* FS supports shared lock lookups */
end_comment

begin_comment
comment|/*  * Sysctl CTL_VFS definitions.  *  * Second level identifier specifies which filesystem. Second level  * identifier VFS_VFSCONF returns information about all filesystems.  * Second level identifier VFS_GENERIC is non-terminal.  */
end_comment

begin_define
define|#
directive|define
name|VFS_VFSCONF
value|0
end_define

begin_comment
comment|/* get configured filesystems */
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

begin_comment
comment|/* synchronously wait for I/O to complete */
end_comment

begin_define
define|#
directive|define
name|MNT_NOWAIT
value|2
end_define

begin_comment
comment|/* start all I/O, but do not wait for it */
end_comment

begin_define
define|#
directive|define
name|MNT_LAZY
value|3
end_define

begin_comment
comment|/* push data not written by filesystem syncer */
end_comment

begin_define
define|#
directive|define
name|MNT_SUSPEND
value|4
end_define

begin_comment
comment|/* Suspend file system after sync */
end_comment

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
comment|/* Filesystem id of mount point */
name|struct
name|fid
name|fh_fid
decl_stmt|;
comment|/* Filesys specific id */
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
name|xucred
name|ex_anon
decl_stmt|;
comment|/* mapping for anonymous user */
name|struct
name|sockaddr
modifier|*
name|ex_addr
decl_stmt|;
comment|/* net address to which exported */
name|u_char
name|ex_addrlen
decl_stmt|;
comment|/* and the net address length */
name|struct
name|sockaddr
modifier|*
name|ex_mask
decl_stmt|;
comment|/* mask of valid bits in saddr */
name|u_char
name|ex_masklen
decl_stmt|;
comment|/* and the smask length */
name|char
modifier|*
name|ex_indexfile
decl_stmt|;
comment|/* index file for WebNFS URLs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure holding information for a publicly exported filesystem  * (WebNFS). Currently the specs allow just for one such filesystem.  */
end_comment

begin_struct
struct|struct
name|nfs_public
block|{
name|int
name|np_valid
decl_stmt|;
comment|/* Do we hold valid information */
name|fhandle_t
name|np_handle
decl_stmt|;
comment|/* Filehandle for pub fs (internal) */
name|struct
name|mount
modifier|*
name|np_mount
decl_stmt|;
comment|/* Mountpoint of exported fs */
name|char
modifier|*
name|np_index
decl_stmt|;
comment|/* Index file */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Filesystem configuration information. One of these exists for each  * type of filesystem supported by the kernel. These are searched at  * mount time to identify the requested filesystem.  *  * XXX: Never change the first two arguments!  */
end_comment

begin_struct
struct|struct
name|vfsconf
block|{
name|u_int
name|vfc_version
decl_stmt|;
comment|/* ABI version number */
name|char
name|vfc_name
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
comment|/* filesystem type name */
name|struct
name|vfsops
modifier|*
name|vfc_vfsops
decl_stmt|;
comment|/* filesystem operations vector */
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
name|struct
name|vfsoptdecl
modifier|*
name|vfc_opts
decl_stmt|;
comment|/* mount options */
name|TAILQ_ENTRY
argument_list|(
argument|vfsconf
argument_list|)
name|vfc_list
expr_stmt|;
comment|/* list of vfscons */
block|}
struct|;
end_struct

begin_comment
comment|/* Userland version of the struct vfsconf. */
end_comment

begin_struct
struct|struct
name|xvfsconf
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
name|struct
name|vfsconf
modifier|*
name|vfc_next
decl_stmt|;
comment|/* next in list */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|BURN_BRIDGES
end_ifndef

begin_struct
struct|struct
name|ovfsconf
block|{
name|void
modifier|*
name|vfc_vfsops
decl_stmt|;
name|char
name|vfc_name
index|[
literal|32
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NB: these flags refer to IMPLEMENTATION properties, not properties of  * any actual mounts; i.e., it does not make sense to change the flags.  */
end_comment

begin_define
define|#
directive|define
name|VFCF_STATIC
value|0x00010000
end_define

begin_comment
comment|/* statically compiled into kernel */
end_comment

begin_define
define|#
directive|define
name|VFCF_NETWORK
value|0x00020000
end_define

begin_comment
comment|/* may get data over the network */
end_comment

begin_define
define|#
directive|define
name|VFCF_READONLY
value|0x00040000
end_define

begin_comment
comment|/* writes are not implemented */
end_comment

begin_define
define|#
directive|define
name|VFCF_SYNTHETIC
value|0x00080000
end_define

begin_comment
comment|/* data does not represent real files */
end_comment

begin_define
define|#
directive|define
name|VFCF_LOOPBACK
value|0x00100000
end_define

begin_comment
comment|/* aliases some other mounted FS */
end_comment

begin_define
define|#
directive|define
name|VFCF_UNICODE
value|0x00200000
end_define

begin_comment
comment|/* stores file names as Unicode */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|fsctlop_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vfsidctl
block|{
name|int
name|vc_vers
decl_stmt|;
comment|/* should be VFSIDCTL_VERS1 (below) */
name|fsid_t
name|vc_fsid
decl_stmt|;
comment|/* fsid to operate on */
name|char
name|vc_fstypename
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
comment|/* type of fs 'nfs' or '*' */
name|fsctlop_t
name|vc_op
decl_stmt|;
comment|/* operation VFS_CTL_* (below) */
name|void
modifier|*
name|vc_ptr
decl_stmt|;
comment|/* pointer to data structure */
name|size_t
name|vc_len
decl_stmt|;
comment|/* sizeof said structure */
name|u_int32_t
name|vc_spare
index|[
literal|12
index|]
decl_stmt|;
comment|/* spare (must be zero) */
block|}
struct|;
end_struct

begin_comment
comment|/* vfsidctl API version. */
end_comment

begin_define
define|#
directive|define
name|VFS_CTL_VERS1
value|0x01
end_define

begin_comment
comment|/*  * New style VFS sysctls, do not reuse/conflict with the namespace for  * private sysctls.  * All "global" sysctl ops have the 33rd bit set:  * 0x...1....  * Private sysctl ops should have the 33rd bit unset.  */
end_comment

begin_define
define|#
directive|define
name|VFS_CTL_QUERY
value|0x00010001
end_define

begin_comment
comment|/* anything wrong? (vfsquery) */
end_comment

begin_define
define|#
directive|define
name|VFS_CTL_TIMEO
value|0x00010002
end_define

begin_comment
comment|/* set timeout for vfs notification */
end_comment

begin_define
define|#
directive|define
name|VFS_CTL_NOLOCKS
value|0x00010003
end_define

begin_comment
comment|/* disable file locking */
end_comment

begin_struct
struct|struct
name|vfsquery
block|{
name|u_int32_t
name|vq_flags
decl_stmt|;
name|u_int32_t
name|vq_spare
index|[
literal|31
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* vfsquery flags */
end_comment

begin_define
define|#
directive|define
name|VQ_NOTRESP
value|0x0001
end_define

begin_comment
comment|/* server down */
end_comment

begin_define
define|#
directive|define
name|VQ_NEEDAUTH
value|0x0002
end_define

begin_comment
comment|/* server bad auth */
end_comment

begin_define
define|#
directive|define
name|VQ_LOWDISK
value|0x0004
end_define

begin_comment
comment|/* we're low on space */
end_comment

begin_define
define|#
directive|define
name|VQ_MOUNT
value|0x0008
end_define

begin_comment
comment|/* new filesystem arrived */
end_comment

begin_define
define|#
directive|define
name|VQ_UNMOUNT
value|0x0010
end_define

begin_comment
comment|/* filesystem has left */
end_comment

begin_define
define|#
directive|define
name|VQ_DEAD
value|0x0020
end_define

begin_comment
comment|/* filesystem is dead, needs force unmount */
end_comment

begin_define
define|#
directive|define
name|VQ_ASSIST
value|0x0040
end_define

begin_comment
comment|/* filesystem needs assistance from external 				   program */
end_comment

begin_define
define|#
directive|define
name|VQ_NOTRESPLOCK
value|0x0080
end_define

begin_comment
comment|/* server lockd down */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG0100
value|0x0100
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG0200
value|0x0200
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG0400
value|0x0400
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG0800
value|0x0800
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG1000
value|0x1000
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG2000
value|0x2000
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG4000
value|0x4000
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_define
define|#
directive|define
name|VQ_FLAG8000
value|0x8000
end_define

begin_comment
comment|/* placeholder */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Point a sysctl request at a vfsidctl's data. */
end_comment

begin_define
define|#
directive|define
name|VCTLTOREQ
parameter_list|(
name|vc
parameter_list|,
name|req
parameter_list|)
define|\
value|do {								\ 		(req)->newptr = (vc)->vc_ptr;				\ 		(req)->newlen = (vc)->vc_len;				\ 		(req)->newidx = 0;					\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MOUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|nfs_mount_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vfc_typenum for nfs, or -1 */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|vfsconfhead
argument_list|,
name|vfsconf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vfsconfhead
name|vfsconf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Operations supported on mounted filesystem.  */
end_comment

begin_struct_decl
struct_decl|struct
name|mount_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_req
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mntarg
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|vfs_cmount_t
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_unmount_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|mntflags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_root_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_quotactl_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|cmds
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_statfs_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|statfs
modifier|*
name|sbp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_sync_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|waitfor
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_vget_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|ino_t
name|ino
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_fhtovp_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|fid
modifier|*
name|fhp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_checkexp_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|int
modifier|*
name|extflagsp
parameter_list|,
name|struct
name|ucred
modifier|*
modifier|*
name|credanonp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_init_t
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_uninit_t
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_extattrctl_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|cmd
parameter_list|,
name|struct
name|vnode
modifier|*
name|filename_vp
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|attrname
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_mount_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vfs_sysctl_t
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|fsctlop_t
name|op
parameter_list|,
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|vfsops
block|{
name|vfs_mount_t
modifier|*
name|vfs_mount
decl_stmt|;
name|vfs_cmount_t
modifier|*
name|vfs_cmount
decl_stmt|;
name|vfs_unmount_t
modifier|*
name|vfs_unmount
decl_stmt|;
name|vfs_root_t
modifier|*
name|vfs_root
decl_stmt|;
name|vfs_quotactl_t
modifier|*
name|vfs_quotactl
decl_stmt|;
name|vfs_statfs_t
modifier|*
name|vfs_statfs
decl_stmt|;
name|vfs_sync_t
modifier|*
name|vfs_sync
decl_stmt|;
name|vfs_vget_t
modifier|*
name|vfs_vget
decl_stmt|;
name|vfs_fhtovp_t
modifier|*
name|vfs_fhtovp
decl_stmt|;
name|vfs_checkexp_t
modifier|*
name|vfs_checkexp
decl_stmt|;
name|vfs_init_t
modifier|*
name|vfs_init
decl_stmt|;
name|vfs_uninit_t
modifier|*
name|vfs_uninit
decl_stmt|;
name|vfs_extattrctl_t
modifier|*
name|vfs_extattrctl
decl_stmt|;
name|vfs_sysctl_t
modifier|*
name|vfs_sysctl
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|vfs_statfs_t
name|__vfs_statfs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VFS_MOUNT
parameter_list|(
name|MP
parameter_list|,
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_mount)(MP, P)
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
name|FLAGS
parameter_list|,
name|VPP
parameter_list|,
name|P
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_root)(MP, FLAGS, VPP, P)
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
value|__vfs_statfs((MP), (SBP), (P))
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
name|P
parameter_list|)
value|(*(MP)->mnt_op->vfs_sync)(MP, WAIT, P)
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
name|FLAGS
parameter_list|,
name|VPP
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_vget)(MP, INO, FLAGS, VPP)
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
define|\
value|(*(MP)->mnt_op->vfs_fhtovp)(MP, FIDP, VPP)
end_define

begin_define
define|#
directive|define
name|VFS_CHECKEXP
parameter_list|(
name|MP
parameter_list|,
name|NAM
parameter_list|,
name|EXFLG
parameter_list|,
name|CRED
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_checkexp)(MP, NAM, EXFLG, CRED)
end_define

begin_define
define|#
directive|define
name|VFS_EXTATTRCTL
parameter_list|(
name|MP
parameter_list|,
name|C
parameter_list|,
name|FN
parameter_list|,
name|NS
parameter_list|,
name|N
parameter_list|,
name|P
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_extattrctl)(MP, C, FN, NS, N, P)
end_define

begin_define
define|#
directive|define
name|VFS_SYSCTL
parameter_list|(
name|MP
parameter_list|,
name|OP
parameter_list|,
name|REQ
parameter_list|)
define|\
value|(*(MP)->mnt_op->vfs_sysctl)(MP, OP, REQ)
end_define

begin_decl_stmt
specifier|extern
name|int
name|mpsafe_vfs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VFS_NEEDSGIANT_
parameter_list|(
name|MP
parameter_list|)
define|\
value|(!mpsafe_vfs || ((MP) != NULL&& ((MP)->mnt_kern_flag& MNTK_MPSAFE) == 0))
end_define

begin_define
define|#
directive|define
name|VFS_NEEDSGIANT
parameter_list|(
name|MP
parameter_list|)
value|__extension__				\ ({									\ 	struct mount *_mp;						\ 	_mp = (MP);							\ 	VFS_NEEDSGIANT_(_mp);						\ })
end_define

begin_define
define|#
directive|define
name|VFS_LOCK_GIANT
parameter_list|(
name|MP
parameter_list|)
value|__extension__				\ ({									\ 	int _locked;							\ 	struct mount *_mp;						\ 	_mp = (MP);							\ 	if (VFS_NEEDSGIANT_(_mp)) {					\ 		mtx_lock(&Giant);					\ 		_locked = 1;						\ 	} else								\ 		_locked = 0;						\ 	_locked;							\ })
end_define

begin_define
define|#
directive|define
name|VFS_UNLOCK_GIANT
parameter_list|(
name|locked
parameter_list|)
value|if ((locked)) mtx_unlock(&Giant);
end_define

begin_define
define|#
directive|define
name|VFS_ASSERT_GIANT
parameter_list|(
name|MP
parameter_list|)
value|do						\ {									\ 	struct mount *_mp;						\ 	_mp = (MP);							\ 	if (VFS_NEEDSGIANT_(_mp))					\ 		mtx_assert(&Giant, MA_OWNED);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|VFS_KNOTE_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|hint
parameter_list|)
value|do					\ {									\ 	if (((vp)->v_vflag& VV_NOKNOTE) == 0)				\ 		VN_KNOTE((vp), (hint), 1);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|VFS_KNOTE_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|hint
parameter_list|)
value|do					\ {									\ 	if (((vp)->v_vflag& VV_NOKNOTE) == 0)				\ 		VN_KNOTE((vp), (hint), 0);				\ } while (0)
end_define

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_comment
comment|/*  * Version numbers.  */
end_comment

begin_define
define|#
directive|define
name|VFS_VERSION_00
value|0x19660120
end_define

begin_define
define|#
directive|define
name|VFS_VERSION
value|VFS_VERSION_00
end_define

begin_define
define|#
directive|define
name|VFS_SET
parameter_list|(
name|vfsops
parameter_list|,
name|fsname
parameter_list|,
name|flags
parameter_list|)
define|\
value|static struct vfsconf fsname ## _vfsconf = {		\ 		.vfc_version = VFS_VERSION,			\ 		.vfc_name = #fsname,				\ 		.vfc_vfsops =&vfsops,				\ 		.vfc_typenum = -1,				\ 		.vfc_flags = flags,				\ 	};							\ 	static moduledata_t fsname ## _mod = {			\ 		#fsname,					\ 		vfs_modevent,					\& fsname ## _vfsconf				\ 	};							\ 	DECLARE_MODULE(fsname, fsname ## _mod, SI_SUB_VFS, SI_ORDER_MIDDLE)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mountrootfsname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * exported vnode operations  */
end_comment

begin_function_decl
name|int
name|dounmount
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kernel_mount
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kernel_vmount
parameter_list|(
name|int
name|flags
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mntarg
modifier|*
name|mount_arg
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mntarg
modifier|*
name|mount_argb
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
name|int
name|flag
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mntarg
modifier|*
name|mount_argf
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mntarg
modifier|*
name|mount_argsu
parameter_list|(
name|struct
name|mntarg
modifier|*
name|ma
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|val
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vfsconf
modifier|*
name|vfs_byname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vfsconf
modifier|*
name|vfs_byname_kld
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_mount_destroy
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_event_signal
parameter_list|(
name|fsid_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_freeopts
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_deleteopt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
name|opts
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_flagopt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
name|opts
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_int
modifier|*
name|w
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_getopt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|vfs_getopts
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_copyopt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_filteropt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|legal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_scanopt
parameter_list|(
name|struct
name|vfsoptlist
modifier|*
name|opts
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_setpublicfs
comment|/* set publicly exported fs */
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|netexport
modifier|*
parameter_list|,
name|struct
name|export_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_msync
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_busy
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_export
comment|/* process mount export info */
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|export_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_allocate_syncvnode
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_getnewfsid
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cdev
modifier|*
name|vfs_getrootfsid
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mount
modifier|*
name|vfs_getvfs
parameter_list|(
name|fsid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return vfs given fsid */
end_comment

begin_function_decl
name|int
name|vfs_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_mount_error
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_mountroot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mount our root filesystem */
end_comment

begin_function_decl
name|void
name|vfs_mountedfrom
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_ref
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_rel
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_suser
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_unbusy
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_unmountall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern	TAILQ_HEAD(mntlist
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
name|mtx
name|mountlist_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nfs_public
name|nfs_pub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Declarations for these vfs default operations are located in  * kern/vfs_default.c, they should be used instead of making "dummy"  * functions or casting entries in the VFS op table to "enopnotsupp()".  */
end_comment

begin_decl_stmt
name|vfs_root_t
name|vfs_stdroot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_quotactl_t
name|vfs_stdquotactl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_statfs_t
name|vfs_stdstatfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_sync_t
name|vfs_stdsync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_sync_t
name|vfs_stdnosync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_vget_t
name|vfs_stdvget
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_fhtovp_t
name|vfs_stdfhtovp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_checkexp_t
name|vfs_stdcheckexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_init_t
name|vfs_stdinit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_uninit_t
name|vfs_stduninit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_extattrctl_t
name|vfs_stdextattrctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_sysctl_t
name|vfs_stdsysctl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|fhopen
parameter_list|(
specifier|const
name|struct
name|fhandle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fhstat
parameter_list|(
specifier|const
name|struct
name|fhandle
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fhstatfs
parameter_list|(
specifier|const
name|struct
name|fhandle
modifier|*
parameter_list|,
name|struct
name|statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fstatfs
parameter_list|(
name|int
parameter_list|,
name|struct
name|statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getfh
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|fhandle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getfsstat
parameter_list|(
name|struct
name|statfs
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getmntinfo
parameter_list|(
name|struct
name|statfs
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lgetfh
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|fhandle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mount
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nmount
parameter_list|(
name|struct
name|iovec
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|statfs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unmount
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* C library stuff */
end_comment

begin_function_decl
name|int
name|getvfsbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|xvfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MOUNT_H_ */
end_comment

end_unit

