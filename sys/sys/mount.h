begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mount.h	8.21 (Berkeley) 5/20/95  * $FreeBSD$  */
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

begin_comment
comment|/*  * XXX - compatability until lockmgr() goes away or all the #includes are  * updated.  */
end_comment

begin_include
include|#
directive|include
file|<sys/lockmgr.h>
end_include

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

begin_struct_decl
struct_decl|struct
name|netcred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netexport
struct_decl|;
end_struct_decl

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNAMELEN
value|80
end_define

begin_comment
comment|/* length of buffer for returned name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|MNAMELEN
value|72
end_define

begin_comment
comment|/* length of buffer for returned name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|MNAMELEN
index|]
decl_stmt|;
comment|/* mounted filesystem */
name|short
name|f_spares2
decl_stmt|;
comment|/* unused spare */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure per mounted file system.  Each mounted file system has an  * array of operations and an instance record.  The file systems are  * put on a doubly linked list.  *  * NOTE: mnt_nvnodelist and mnt_reservedvnlist.  At the moment vnodes  * are linked into mnt_nvnodelist.  At some point in the near future the  * vnode list will be split into a 'dirty' and 'clean' list. mnt_nvnodelist  * will become the dirty list and mnt_reservedvnlist will become the 'clean'  * list.  Filesystem kld's syncing code should remain compatible since  * they only need to scan the dirty vnode list (nvnodelist -> dirtyvnodelist).  */
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

begin_struct
struct|struct
name|mount
block|{
name|TAILQ_ENTRY
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
name|vnode
modifier|*
name|mnt_syncer
decl_stmt|;
comment|/* syncer vnode */
name|struct
name|vnodelst
name|mnt_nvnodelist
decl_stmt|;
comment|/* list of vnodes this mount */
name|struct
name|vnodelst
name|mnt_reservedvnlist
decl_stmt|;
comment|/* (future) dirty vnode list */
name|struct
name|lock
name|mnt_lock
decl_stmt|;
comment|/* mount structure lock */
name|int
name|mnt_writeopcount
decl_stmt|;
comment|/* write syscalls in progress */
name|int
name|mnt_flag
decl_stmt|;
comment|/* flags shared with user */
name|int
name|mnt_kern_flag
decl_stmt|;
comment|/* kernel only flags */
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
name|time_t
name|mnt_time
decl_stmt|;
comment|/* last time written*/
name|u_int
name|mnt_iosize_max
decl_stmt|;
comment|/* max IO request size */
name|struct
name|netexport
modifier|*
name|mnt_export
decl_stmt|;
comment|/* export list */
block|}
struct|;
end_struct

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
name|MNT_JAILDEVFS
value|0x02000000
end_define

begin_comment
comment|/* Jail friendly DEVFS behaviour */
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
comment|/*  * Mask of flags that are visible to statfs()  * XXX I think that this could now become (~(MNT_CMDFLAGS))  * but the 'mount' program may need changing to handle this.  */
end_comment

begin_define
define|#
directive|define
name|MNT_VISFLAGMASK
value|(MNT_RDONLY	| MNT_SYNCHRONOUS | MNT_NOEXEC	| \ 			MNT_NOSUID	| MNT_NODEV	| MNT_UNION	| \ 			MNT_ASYNC	| MNT_EXRDONLY	| MNT_EXPORTED	| \ 			MNT_DEFEXPORTED	| MNT_EXPORTANON| MNT_EXKERB	| \ 			MNT_LOCAL	| MNT_USER	| MNT_QUOTA	| \ 			MNT_ROOTFS	| MNT_NOATIME	| MNT_NOCLUSTERR| \ 			MNT_NOCLUSTERW	| MNT_SUIDDIR	| MNT_SOFTDEP	| \ 			MNT_IGNORE	| MNT_EXPUBLIC	| MNT_NOSYMFOLLOW | \ 			MNT_JAILDEVFS	| MNT_MULTILABEL)
end_define

begin_comment
comment|/* Mask of flags that can be updated */
end_comment

begin_define
define|#
directive|define
name|MNT_UPDATEMASK
value|(MNT_NOSUID	| MNT_NOEXEC	| MNT_NODEV	| \ 			MNT_SYNCHRONOUS	| MNT_UNION	| MNT_ASYNC	| \ 			MNT_NOATIME | \ 			MNT_NOSYMFOLLOW	| MNT_IGNORE	| MNT_JAILDEVFS	| \ 			MNT_NOCLUSTERR	| MNT_NOCLUSTERW | MNT_SUIDDIR | \ 			MNT_MULTILABEL)
end_define

begin_comment
comment|/*  * External filesystem command modifier flags.  * Unmount can use the MNT_FORCE flag.  * XXX These are not STATES and really should be somewhere else.  */
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
name|MNT_CMDFLAGS
value|(MNT_UPDATE	| MNT_DELEXPORT	| MNT_RELOAD	| \ 			MNT_FORCE	| MNT_SNAPSHOT)
end_define

begin_comment
comment|/*  * Still available  */
end_comment

begin_define
define|#
directive|define
name|MNT_SPARE3
value|0x08000000
end_define

begin_comment
comment|/*  * Internal filesystem control flags stored in mnt_kern_flag.  *  * MNTK_UNMOUNT locks the mount entry so that name lookup cannot proceed  * past the mount point.  This keeps the subtree stable during mounts  * and unmounts.  */
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
name|MNTK_WANTRDWR
value|0x04000000
end_define

begin_comment
comment|/* upgrade to read/write requested */
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
name|MNTK_SUSPENDED
value|0x10000000
end_define

begin_comment
comment|/* write operations are suspended */
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
name|struct
name|vfsconf
modifier|*
name|vfc_next
decl_stmt|;
comment|/* next in list */
block|}
struct|;
end_struct

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
comment|/* stores file names as Unicode*/
end_comment

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

begin_struct_decl
struct_decl|struct
name|mount_args
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
function_decl|(
modifier|*
name|vfs_mount
function_decl|)
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_start
function_decl|)
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
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_unmount
function_decl|)
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
name|int
function_decl|(
modifier|*
name|vfs_root
function_decl|)
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_quotactl
function_decl|)
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
name|caddr_t
name|arg
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_statfs
function_decl|)
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
name|int
function_decl|(
modifier|*
name|vfs_sync
function_decl|)
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
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_vget
function_decl|)
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
name|int
function_decl|(
modifier|*
name|vfs_fhtovp
function_decl|)
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
name|int
function_decl|(
modifier|*
name|vfs_checkexp
function_decl|)
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
name|int
function_decl|(
modifier|*
name|vfs_vptofh
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|fid
modifier|*
name|fhp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_init
function_decl|)
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_uninit
function_decl|)
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_extattrctl
function_decl|)
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
name|VFS_VPTOFH
parameter_list|(
name|VP
parameter_list|,
name|FIDP
parameter_list|)
value|(*(VP)->v_mount->mnt_op->vfs_vptofh)(VP, FIDP)
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

begin_include
include|#
directive|include
file|<sys/module.h>
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
name|flags
parameter_list|)
define|\
value|static struct vfsconf fsname ## _vfsconf = {		\&vfsops,					\ 		#fsname,					\ 		-1,						\ 		0,						\ 		flags						\ 	};							\ 	static moduledata_t fsname ## _mod = {			\ 		#fsname,					\ 		vfs_modevent,					\& fsname ## _vfsconf				\ 	};							\ 	DECLARE_MODULE(fsname, fsname ## _mod, SI_SUB_VFS, SI_ORDER_MIDDLE)
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
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_mount
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|data
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
name|int
name|vfs_lock
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lock a vfs */
end_comment

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
name|void
name|vfs_unlock
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unlock a vfs */
end_comment

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
name|td
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
name|struct
name|netcred
modifier|*
name|vfs_export_lookup
comment|/* lookup host in fs export list */
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|sockaddr
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
name|dev_t
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
name|int
name|vfs_mountedon
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* is a vfs mounted on vp */
end_comment

begin_function_decl
name|void
name|vfs_mountroot
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mount our root filesystem */
end_comment

begin_function_decl
name|int
name|vfs_rootmountalloc
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
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
name|td
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

begin_function_decl
name|int
name|vfs_register
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_unregister
parameter_list|(
name|struct
name|vfsconf
modifier|*
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
comment|/*   * Declarations for these vfs default operations are located in   * kern/vfs_default.c, they should be used instead of making "dummy"   * functions or casting entries in the VFS op table to "enopnotsupp()".  */
end_comment

begin_function_decl
name|int
name|vfs_stdmount
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdstart
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
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdunmount
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
end_function_decl

begin_function_decl
name|int
name|vfs_stdroot
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdquotactl
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
name|caddr_t
name|arg
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdstatfs
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
end_function_decl

begin_function_decl
name|int
name|vfs_stdsync
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
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdvget
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
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdfhtovp
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
end_function_decl

begin_function_decl
name|int
name|vfs_stdcheckexp
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
end_function_decl

begin_function_decl
name|int
name|vfs_stdvptofh
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|fid
modifier|*
name|fhp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdinit
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stduninit
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_stdextattrctl
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
end_function_decl

begin_comment
comment|/* XXX - these should be indirect functions!!! */
end_comment

begin_function_decl
name|int
name|softdep_process_worklist
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|softdep_fsync
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|endvfsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ovfsconf
modifier|*
name|getvfsbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ovfsconf
modifier|*
name|getvfsbytype
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ovfsconf
modifier|*
name|getvfsent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|getvfsbyname
value|new_getvfsbyname
end_define

begin_function_decl
name|int
name|new_getvfsbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setvfsent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfsisloadable
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfsload
parameter_list|(
specifier|const
name|char
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

