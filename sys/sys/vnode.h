begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vnode.h	8.7 (Berkeley) 2/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VNODE_H_
end_define

begin_include
include|#
directive|include
file|<sys/bufobj.h>
end_include

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
file|<sys/lockmgr.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rangelock.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_comment
comment|/*  * The vnode is the focus of all file activity in UNIX.  There is a  * unique vnode allocated for each active file, each current directory,  * each mounted-on file, text file, and the root.  */
end_comment

begin_comment
comment|/*  * Vnode types.  VNON means no type.  */
end_comment

begin_enum
enum|enum
name|vtype
block|{
name|VNON
block|,
name|VREG
block|,
name|VDIR
block|,
name|VBLK
block|,
name|VCHR
block|,
name|VLNK
block|,
name|VSOCK
block|,
name|VFIFO
block|,
name|VBAD
block|,
name|VMARKER
block|}
enum|;
end_enum

begin_comment
comment|/*  * Each underlying filesystem allocates its own private area and hangs  * it from v_data.  If non-null, this area is freed in getnewvnode().  */
end_comment

begin_struct_decl
struct_decl|struct
name|namecache
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|vpollinfo
block|{
name|struct
name|mtx
name|vpi_lock
decl_stmt|;
comment|/* lock to protect below */
name|struct
name|selinfo
name|vpi_selinfo
decl_stmt|;
comment|/* identity of poller(s) */
name|short
name|vpi_events
decl_stmt|;
comment|/* what they are looking for */
name|short
name|vpi_revents
decl_stmt|;
comment|/* what has happened */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reading or writing any of these items requires holding the appropriate lock.  *  * Lock reference:  *	c - namecache mutex  *	i - interlock  *	l - mp mnt_listmtx or freelist mutex  *	I - updated with atomics, 0->1 and 1->0 transitions with interlock held  *	m - mount point interlock  *	p - pollinfo lock  *	u - Only a reference to the vnode is needed to read.  *	v - vnode lock  *  * Vnodes may be found on many lists.  The general way to deal with operating  * on a vnode that is on a list is:  *	1) Lock the list and find the vnode.  *	2) Lock interlock so that the vnode does not go away.  *	3) Unlock the list to avoid lock order reversals.  *	4) vget with LK_INTERLOCK and check for ENOENT, or  *	5) Check for DOOMED if the vnode lock is not required.  *	6) Perform your operation, then vput().  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KVM_VNODE
argument_list|)
end_if

begin_struct
struct|struct
name|vnode
block|{
comment|/* 	 * Fields which define the identity of the vnode.  These fields are 	 * owned by the filesystem (XXX: and vgone() ?) 	 */
specifier|const
name|char
modifier|*
name|v_tag
decl_stmt|;
comment|/* u type of underlying data */
name|struct
name|vop_vector
modifier|*
name|v_op
decl_stmt|;
comment|/* u vnode operations vector */
name|void
modifier|*
name|v_data
decl_stmt|;
comment|/* u private data for fs */
comment|/* 	 * Filesystem instance stuff 	 */
name|struct
name|mount
modifier|*
name|v_mount
decl_stmt|;
comment|/* u ptr to vfs we are in */
name|TAILQ_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_nmntvnodes
expr_stmt|;
comment|/* m vnodes for mount point */
comment|/* 	 * Type specific fields, only one applies to any given vnode. 	 */
union|union
block|{
name|struct
name|mount
modifier|*
name|v_mountedhere
decl_stmt|;
comment|/* v ptr to mountpoint (VDIR) */
name|struct
name|unpcb
modifier|*
name|v_unpcb
decl_stmt|;
comment|/* v unix domain net (VSOCK) */
name|struct
name|cdev
modifier|*
name|v_rdev
decl_stmt|;
comment|/* v device (VCHR, VBLK) */
name|struct
name|fifoinfo
modifier|*
name|v_fifoinfo
decl_stmt|;
comment|/* v fifo (VFIFO) */
block|}
union|;
comment|/* 	 * vfs_hash: (mount + inode) -> vnode hash.  The hash value 	 * itself is grouped with other int fields, to avoid padding. 	 */
name|LIST_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_hashlist
expr_stmt|;
comment|/* 	 * VFS_namecache stuff 	 */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|namecache
argument_list|)
name|v_cache_src
expr_stmt|;
comment|/* c Cache entries from us */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|namecache
argument_list|)
name|v_cache_dst
expr_stmt|;
comment|/* c Cache entries to us */
name|struct
name|namecache
modifier|*
name|v_cache_dd
decl_stmt|;
comment|/* c Cache entry for .. vnode */
comment|/* 	 * Locking 	 */
name|struct
name|lock
name|v_lock
decl_stmt|;
comment|/* u (if fs don't have one) */
name|struct
name|mtx
name|v_interlock
decl_stmt|;
comment|/* lock for "i" things */
name|struct
name|lock
modifier|*
name|v_vnlock
decl_stmt|;
comment|/* u pointer to vnode lock */
comment|/* 	 * The machinery of being a vnode 	 */
name|TAILQ_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_actfreelist
expr_stmt|;
comment|/* l vnode active/free lists */
name|struct
name|bufobj
name|v_bufobj
decl_stmt|;
comment|/* * Buffer cache object */
comment|/* 	 * Hooks for various subsystems and features. 	 */
name|struct
name|vpollinfo
modifier|*
name|v_pollinfo
decl_stmt|;
comment|/* i Poll events, p for *v_pi */
name|struct
name|label
modifier|*
name|v_label
decl_stmt|;
comment|/* MAC label for vnode */
name|struct
name|lockf
modifier|*
name|v_lockf
decl_stmt|;
comment|/* Byte-level advisory lock list */
name|struct
name|rangelock
name|v_rl
decl_stmt|;
comment|/* Byte-range lock */
comment|/* 	 * clustering stuff 	 */
name|daddr_t
name|v_cstart
decl_stmt|;
comment|/* v start block of cluster */
name|daddr_t
name|v_lasta
decl_stmt|;
comment|/* v last allocation  */
name|daddr_t
name|v_lastw
decl_stmt|;
comment|/* v last write  */
name|int
name|v_clen
decl_stmt|;
comment|/* v length of cur. cluster */
name|u_int
name|v_holdcnt
decl_stmt|;
comment|/* I prevents recycling. */
name|u_int
name|v_usecount
decl_stmt|;
comment|/* I ref count of users */
name|u_int
name|v_iflag
decl_stmt|;
comment|/* i vnode flags (see below) */
name|u_int
name|v_vflag
decl_stmt|;
comment|/* v vnode flags */
name|u_int
name|v_mflag
decl_stmt|;
comment|/* l mnt-specific vnode flags */
name|int
name|v_writecount
decl_stmt|;
comment|/* v ref count of writers */
name|u_int
name|v_hash
decl_stmt|;
name|enum
name|vtype
name|v_type
decl_stmt|;
comment|/* u vnode type */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) || defined(_KVM_VNODE) */
end_comment

begin_define
define|#
directive|define
name|bo2vnode
parameter_list|(
name|bo
parameter_list|)
value|__containerof((bo), struct vnode, v_bufobj)
end_define

begin_comment
comment|/* XXX: These are temporary to avoid a source sweep at this time */
end_comment

begin_define
define|#
directive|define
name|v_object
value|v_bufobj.bo_object
end_define

begin_comment
comment|/*  * Userland version of struct vnode, for sysctl.  */
end_comment

begin_struct
struct|struct
name|xvnode
block|{
name|size_t
name|xv_size
decl_stmt|;
comment|/* sizeof(struct xvnode) */
name|void
modifier|*
name|xv_vnode
decl_stmt|;
comment|/* address of real vnode */
name|u_long
name|xv_flag
decl_stmt|;
comment|/* vnode vflags */
name|int
name|xv_usecount
decl_stmt|;
comment|/* reference count of users */
name|int
name|xv_writecount
decl_stmt|;
comment|/* reference count of writers */
name|int
name|xv_holdcnt
decl_stmt|;
comment|/* page& buffer references */
name|u_long
name|xv_id
decl_stmt|;
comment|/* capability identifier */
name|void
modifier|*
name|xv_mount
decl_stmt|;
comment|/* address of parent mount */
name|long
name|xv_numoutput
decl_stmt|;
comment|/* num of writes in progress */
name|enum
name|vtype
name|xv_type
decl_stmt|;
comment|/* vnode type */
union|union
block|{
name|void
modifier|*
name|xvu_socket
decl_stmt|;
comment|/* unpcb, if VSOCK */
name|void
modifier|*
name|xvu_fifo
decl_stmt|;
comment|/* fifo, if VFIFO */
name|dev_t
name|xvu_rdev
decl_stmt|;
comment|/* maj/min, if VBLK/VCHR */
struct|struct
block|{
name|dev_t
name|xvu_dev
decl_stmt|;
comment|/* device, if VDIR/VREG/VLNK */
name|ino_t
name|xvu_ino
decl_stmt|;
comment|/* id, if VDIR/VREG/VLNK */
block|}
name|xv_uns
struct|;
block|}
name|xv_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|xv_socket
value|xv_un.xvu_socket
end_define

begin_define
define|#
directive|define
name|xv_fifo
value|xv_un.xvu_fifo
end_define

begin_define
define|#
directive|define
name|xv_rdev
value|xv_un.xvu_rdev
end_define

begin_define
define|#
directive|define
name|xv_dev
value|xv_un.xv_uns.xvu_dev
end_define

begin_define
define|#
directive|define
name|xv_ino
value|xv_un.xv_uns.xvu_ino
end_define

begin_comment
comment|/* We don't need to lock the knlist */
end_comment

begin_define
define|#
directive|define
name|VN_KNLIST_EMPTY
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_pollinfo == NULL ||	\ 	    KNLIST_EMPTY(&(vp)->v_pollinfo->vpi_selinfo.si_note))
end_define

begin_define
define|#
directive|define
name|VN_KNOTE
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|,
name|a
parameter_list|)
define|\
value|do {							\ 		if (!VN_KNLIST_EMPTY(vp))			\ 			KNOTE(&vp->v_pollinfo->vpi_selinfo.si_note, (b), \ 			    (a) | KNF_NOKQLOCK);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|VN_KNOTE_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|)
value|VN_KNOTE(vp, b, KNF_LISTLOCKED)
end_define

begin_define
define|#
directive|define
name|VN_KNOTE_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|)
value|VN_KNOTE(vp, b, 0)
end_define

begin_comment
comment|/*  * Vnode flags.  *	VI flags are protected by interlock and live in v_iflag  *	VV flags are protected by the vnode lock and live in v_vflag  *  *	VI_DOOMED is doubly protected by the interlock and vnode lock.  Both  *	are required for writing but the status may be checked with either.  */
end_comment

begin_define
define|#
directive|define
name|VI_MOUNT
value|0x0020
end_define

begin_comment
comment|/* Mount in progress */
end_comment

begin_define
define|#
directive|define
name|VI_DOOMED
value|0x0080
end_define

begin_comment
comment|/* This vnode is being recycled */
end_comment

begin_define
define|#
directive|define
name|VI_FREE
value|0x0100
end_define

begin_comment
comment|/* This vnode is on the freelist */
end_comment

begin_define
define|#
directive|define
name|VI_ACTIVE
value|0x0200
end_define

begin_comment
comment|/* This vnode is on the active list */
end_comment

begin_define
define|#
directive|define
name|VI_DOINGINACT
value|0x0800
end_define

begin_comment
comment|/* VOP_INACTIVE is in progress */
end_comment

begin_define
define|#
directive|define
name|VI_OWEINACT
value|0x1000
end_define

begin_comment
comment|/* Need to call inactive */
end_comment

begin_define
define|#
directive|define
name|VV_ROOT
value|0x0001
end_define

begin_comment
comment|/* root of its filesystem */
end_comment

begin_define
define|#
directive|define
name|VV_ISTTY
value|0x0002
end_define

begin_comment
comment|/* vnode represents a tty */
end_comment

begin_define
define|#
directive|define
name|VV_NOSYNC
value|0x0004
end_define

begin_comment
comment|/* unlinked, stop syncing */
end_comment

begin_define
define|#
directive|define
name|VV_ETERNALDEV
value|0x0008
end_define

begin_comment
comment|/* device that is never destroyed */
end_comment

begin_define
define|#
directive|define
name|VV_CACHEDLABEL
value|0x0010
end_define

begin_comment
comment|/* Vnode has valid cached MAC label */
end_comment

begin_define
define|#
directive|define
name|VV_TEXT
value|0x0020
end_define

begin_comment
comment|/* vnode is a pure text prototype */
end_comment

begin_define
define|#
directive|define
name|VV_COPYONWRITE
value|0x0040
end_define

begin_comment
comment|/* vnode is doing copy-on-write */
end_comment

begin_define
define|#
directive|define
name|VV_SYSTEM
value|0x0080
end_define

begin_comment
comment|/* vnode being used by kernel */
end_comment

begin_define
define|#
directive|define
name|VV_PROCDEP
value|0x0100
end_define

begin_comment
comment|/* vnode is process dependent */
end_comment

begin_define
define|#
directive|define
name|VV_NOKNOTE
value|0x0200
end_define

begin_comment
comment|/* don't activate knotes on this vnode */
end_comment

begin_define
define|#
directive|define
name|VV_DELETED
value|0x0400
end_define

begin_comment
comment|/* should be removed */
end_comment

begin_define
define|#
directive|define
name|VV_MD
value|0x0800
end_define

begin_comment
comment|/* vnode backs the md device */
end_comment

begin_define
define|#
directive|define
name|VV_FORCEINSMQ
value|0x1000
end_define

begin_comment
comment|/* force the insmntque to succeed */
end_comment

begin_define
define|#
directive|define
name|VMP_TMPMNTFREELIST
value|0x0001
end_define

begin_comment
comment|/* Vnode is on mnt's tmp free list */
end_comment

begin_comment
comment|/*  * Vnode attributes.  A field value of VNOVAL represents a field whose value  * is unavailable (getattr) or which is not to be changed (setattr).  */
end_comment

begin_struct
struct|struct
name|vattr
block|{
name|enum
name|vtype
name|va_type
decl_stmt|;
comment|/* vnode type (for create) */
name|u_short
name|va_mode
decl_stmt|;
comment|/* files access mode and type */
name|u_short
name|va_padding0
decl_stmt|;
name|uid_t
name|va_uid
decl_stmt|;
comment|/* owner user id */
name|gid_t
name|va_gid
decl_stmt|;
comment|/* owner group id */
name|nlink_t
name|va_nlink
decl_stmt|;
comment|/* number of references to file */
name|dev_t
name|va_fsid
decl_stmt|;
comment|/* filesystem id */
name|ino_t
name|va_fileid
decl_stmt|;
comment|/* file id */
name|u_quad_t
name|va_size
decl_stmt|;
comment|/* file size in bytes */
name|long
name|va_blocksize
decl_stmt|;
comment|/* blocksize preferred for i/o */
name|struct
name|timespec
name|va_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|va_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|va_ctime
decl_stmt|;
comment|/* time file changed */
name|struct
name|timespec
name|va_birthtime
decl_stmt|;
comment|/* time file created */
name|u_long
name|va_gen
decl_stmt|;
comment|/* generation number of file */
name|u_long
name|va_flags
decl_stmt|;
comment|/* flags defined for file */
name|dev_t
name|va_rdev
decl_stmt|;
comment|/* device the special file represents */
name|u_quad_t
name|va_bytes
decl_stmt|;
comment|/* bytes of disk space held by file */
name|u_quad_t
name|va_filerev
decl_stmt|;
comment|/* file modification number */
name|u_int
name|va_vaflags
decl_stmt|;
comment|/* operations flags, see below */
name|long
name|va_spare
decl_stmt|;
comment|/* remain quad aligned */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for va_vaflags.  */
end_comment

begin_define
define|#
directive|define
name|VA_UTIMES_NULL
value|0x01
end_define

begin_comment
comment|/* utimes argument was NULL */
end_comment

begin_define
define|#
directive|define
name|VA_EXCLUSIVE
value|0x02
end_define

begin_comment
comment|/* exclusive create request */
end_comment

begin_define
define|#
directive|define
name|VA_SYNC
value|0x04
end_define

begin_comment
comment|/* O_SYNC truncation */
end_comment

begin_comment
comment|/*  * Flags for ioflag. (high 16 bits used to ask for read-ahead and  * help with write clustering)  * NB: IO_NDELAY and IO_DIRECT are linked to fcntl.h  */
end_comment

begin_define
define|#
directive|define
name|IO_UNIT
value|0x0001
end_define

begin_comment
comment|/* do I/O as atomic unit */
end_comment

begin_define
define|#
directive|define
name|IO_APPEND
value|0x0002
end_define

begin_comment
comment|/* append write to end */
end_comment

begin_define
define|#
directive|define
name|IO_NDELAY
value|0x0004
end_define

begin_comment
comment|/* FNDELAY flag set in file table */
end_comment

begin_define
define|#
directive|define
name|IO_NODELOCKED
value|0x0008
end_define

begin_comment
comment|/* underlying node already locked */
end_comment

begin_define
define|#
directive|define
name|IO_ASYNC
value|0x0010
end_define

begin_comment
comment|/* bawrite rather then bdwrite */
end_comment

begin_define
define|#
directive|define
name|IO_VMIO
value|0x0020
end_define

begin_comment
comment|/* data already in VMIO space */
end_comment

begin_define
define|#
directive|define
name|IO_INVAL
value|0x0040
end_define

begin_comment
comment|/* invalidate after I/O */
end_comment

begin_define
define|#
directive|define
name|IO_SYNC
value|0x0080
end_define

begin_comment
comment|/* do I/O synchronously */
end_comment

begin_define
define|#
directive|define
name|IO_DIRECT
value|0x0100
end_define

begin_comment
comment|/* attempt to bypass buffer cache */
end_comment

begin_define
define|#
directive|define
name|IO_NOREUSE
value|0x0200
end_define

begin_comment
comment|/* VMIO data won't be reused */
end_comment

begin_define
define|#
directive|define
name|IO_EXT
value|0x0400
end_define

begin_comment
comment|/* operate on external attributes */
end_comment

begin_define
define|#
directive|define
name|IO_NORMAL
value|0x0800
end_define

begin_comment
comment|/* operate on regular data */
end_comment

begin_define
define|#
directive|define
name|IO_NOMACCHECK
value|0x1000
end_define

begin_comment
comment|/* MAC checks unnecessary */
end_comment

begin_define
define|#
directive|define
name|IO_BUFLOCKED
value|0x2000
end_define

begin_comment
comment|/* ffs flag; indir buf is locked */
end_comment

begin_define
define|#
directive|define
name|IO_RANGELOCKED
value|0x4000
end_define

begin_comment
comment|/* range locked */
end_comment

begin_define
define|#
directive|define
name|IO_SEQMAX
value|0x7F
end_define

begin_comment
comment|/* seq heuristic max value */
end_comment

begin_define
define|#
directive|define
name|IO_SEQSHIFT
value|16
end_define

begin_comment
comment|/* seq heuristic in upper 16 bits */
end_comment

begin_comment
comment|/*  * Flags for accmode_t.  */
end_comment

begin_define
define|#
directive|define
name|VEXEC
value|000000000100
end_define

begin_comment
comment|/* execute/search permission */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|000000000200
end_define

begin_comment
comment|/* write permission */
end_comment

begin_define
define|#
directive|define
name|VREAD
value|000000000400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|VADMIN
value|000000010000
end_define

begin_comment
comment|/* being the file owner */
end_comment

begin_define
define|#
directive|define
name|VAPPEND
value|000000040000
end_define

begin_comment
comment|/* permission to write/append */
end_comment

begin_comment
comment|/*  * VEXPLICIT_DENY makes VOP_ACCESSX(9) return EPERM or EACCES only  * if permission was denied explicitly, by a "deny" rule in NFSv4 ACL,  * and 0 otherwise.  This never happens with ordinary unix access rights  * or POSIX.1e ACLs.  Obviously, VEXPLICIT_DENY must be OR-ed with  * some other V* constant.  */
end_comment

begin_define
define|#
directive|define
name|VEXPLICIT_DENY
value|000000100000
end_define

begin_define
define|#
directive|define
name|VREAD_NAMED_ATTRS
value|000000200000
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|VWRITE_NAMED_ATTRS
value|000000400000
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|VDELETE_CHILD
value|000001000000
end_define

begin_define
define|#
directive|define
name|VREAD_ATTRIBUTES
value|000002000000
end_define

begin_comment
comment|/* permission to stat(2) */
end_comment

begin_define
define|#
directive|define
name|VWRITE_ATTRIBUTES
value|000004000000
end_define

begin_comment
comment|/* change {m,c,a}time */
end_comment

begin_define
define|#
directive|define
name|VDELETE
value|000010000000
end_define

begin_define
define|#
directive|define
name|VREAD_ACL
value|000020000000
end_define

begin_comment
comment|/* read ACL and file mode */
end_comment

begin_define
define|#
directive|define
name|VWRITE_ACL
value|000040000000
end_define

begin_comment
comment|/* change ACL and/or file mode */
end_comment

begin_define
define|#
directive|define
name|VWRITE_OWNER
value|000100000000
end_define

begin_comment
comment|/* change file owner */
end_comment

begin_define
define|#
directive|define
name|VSYNCHRONIZE
value|000200000000
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|VCREAT
value|000400000000
end_define

begin_comment
comment|/* creating new file */
end_comment

begin_define
define|#
directive|define
name|VVERIFY
value|001000000000
end_define

begin_comment
comment|/* verification required */
end_comment

begin_comment
comment|/*  * Permissions that were traditionally granted only to the file owner.  */
end_comment

begin_define
define|#
directive|define
name|VADMIN_PERMS
value|(VADMIN | VWRITE_ATTRIBUTES | VWRITE_ACL | \     VWRITE_OWNER)
end_define

begin_comment
comment|/*  * Permissions that were traditionally granted to everyone.  */
end_comment

begin_define
define|#
directive|define
name|VSTAT_PERMS
value|(VREAD_ATTRIBUTES | VREAD_ACL)
end_define

begin_comment
comment|/*  * Permissions that allow to change the state of the file in any way.  */
end_comment

begin_define
define|#
directive|define
name|VMODIFY_PERMS
value|(VWRITE | VAPPEND | VADMIN_PERMS | VDELETE_CHILD | \     VDELETE)
end_define

begin_comment
comment|/*  * Token indicating no attribute value yet assigned.  */
end_comment

begin_define
define|#
directive|define
name|VNOVAL
value|(-1)
end_define

begin_comment
comment|/*  * LK_TIMELOCK timeout for vnode locks (used mainly by the pageout daemon)  */
end_comment

begin_define
define|#
directive|define
name|VLKTIMEOUT
value|(hz / 20 + 1)
end_define

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
name|M_VNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|u_int
name|ncsizefactor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Convert between vnode types and inode formats (since POSIX.1  * defines mode word of stat structure in terms of inode formats).  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|vtype
name|iftovt_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vttoif_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFTOVT
parameter_list|(
name|mode
parameter_list|)
value|(iftovt_tab[((mode)& S_IFMT)>> 12])
end_define

begin_define
define|#
directive|define
name|VTTOIF
parameter_list|(
name|indx
parameter_list|)
value|(vttoif_tab[(int)(indx)])
end_define

begin_define
define|#
directive|define
name|MAKEIMODE
parameter_list|(
name|indx
parameter_list|,
name|mode
parameter_list|)
value|(int)(VTTOIF(indx) | (mode))
end_define

begin_comment
comment|/*  * Flags to various vnode functions.  */
end_comment

begin_define
define|#
directive|define
name|SKIPSYSTEM
value|0x0001
end_define

begin_comment
comment|/* vflush: skip vnodes marked VSYSTEM */
end_comment

begin_define
define|#
directive|define
name|FORCECLOSE
value|0x0002
end_define

begin_comment
comment|/* vflush: force file closure */
end_comment

begin_define
define|#
directive|define
name|WRITECLOSE
value|0x0004
end_define

begin_comment
comment|/* vflush: only close writable files */
end_comment

begin_define
define|#
directive|define
name|EARLYFLUSH
value|0x0008
end_define

begin_comment
comment|/* vflush: early call for ffs_flushfiles */
end_comment

begin_define
define|#
directive|define
name|V_SAVE
value|0x0001
end_define

begin_comment
comment|/* vinvalbuf: sync file first */
end_comment

begin_define
define|#
directive|define
name|V_ALT
value|0x0002
end_define

begin_comment
comment|/* vinvalbuf: invalidate only alternate bufs */
end_comment

begin_define
define|#
directive|define
name|V_NORMAL
value|0x0004
end_define

begin_comment
comment|/* vinvalbuf: invalidate only regular bufs */
end_comment

begin_define
define|#
directive|define
name|V_CLEANONLY
value|0x0008
end_define

begin_comment
comment|/* vinvalbuf: invalidate only clean bufs */
end_comment

begin_define
define|#
directive|define
name|V_VMIO
value|0x0010
end_define

begin_comment
comment|/* vinvalbuf: called during pageout */
end_comment

begin_define
define|#
directive|define
name|REVOKEALL
value|0x0001
end_define

begin_comment
comment|/* vop_revoke: revoke all aliases */
end_comment

begin_define
define|#
directive|define
name|V_WAIT
value|0x0001
end_define

begin_comment
comment|/* vn_start_write: sleep for suspend */
end_comment

begin_define
define|#
directive|define
name|V_NOWAIT
value|0x0002
end_define

begin_comment
comment|/* vn_start_write: don't sleep for suspend */
end_comment

begin_define
define|#
directive|define
name|V_XSLEEP
value|0x0004
end_define

begin_comment
comment|/* vn_start_write: just return after sleep */
end_comment

begin_define
define|#
directive|define
name|V_MNTREF
value|0x0010
end_define

begin_comment
comment|/* vn_start_write: mp is already ref-ed */
end_comment

begin_define
define|#
directive|define
name|VR_START_WRITE
value|0x0001
end_define

begin_comment
comment|/* vfs_write_resume: start write atomically */
end_comment

begin_define
define|#
directive|define
name|VR_NO_SUSPCLR
value|0x0002
end_define

begin_comment
comment|/* vfs_write_resume: do not clear suspension */
end_comment

begin_define
define|#
directive|define
name|VS_SKIP_UNMOUNT
value|0x0001
end_define

begin_comment
comment|/* vfs_write_suspend: fail if the 				   filesystem is being unmounted */
end_comment

begin_define
define|#
directive|define
name|VREF
parameter_list|(
name|vp
parameter_list|)
value|vref(vp)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_define
define|#
directive|define
name|VATTR_NULL
parameter_list|(
name|vap
parameter_list|)
value|vattr_null(vap)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VATTR_NULL
parameter_list|(
name|vap
parameter_list|)
value|(*(vap) = va_null)
end_define

begin_comment
comment|/* initialize a vattr */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAGNOSTIC */
end_comment

begin_define
define|#
directive|define
name|NULLVP
value|((struct vnode *)NULL)
end_define

begin_comment
comment|/*  * Global vnode data.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|rootvnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root (i.e. "/") vnode */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mount
modifier|*
name|rootdevmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "/dev" mount */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|desiredvnodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of vnodes desired */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|uma_zone
modifier|*
name|namei_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vattr
name|va_null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* predefined null vattr structure */
end_comment

begin_define
define|#
directive|define
name|VI_LOCK
parameter_list|(
name|vp
parameter_list|)
value|mtx_lock(&(vp)->v_interlock)
end_define

begin_define
define|#
directive|define
name|VI_LOCK_FLAGS
parameter_list|(
name|vp
parameter_list|,
name|flags
parameter_list|)
value|mtx_lock_flags(&(vp)->v_interlock, (flags))
end_define

begin_define
define|#
directive|define
name|VI_TRYLOCK
parameter_list|(
name|vp
parameter_list|)
value|mtx_trylock(&(vp)->v_interlock)
end_define

begin_define
define|#
directive|define
name|VI_UNLOCK
parameter_list|(
name|vp
parameter_list|)
value|mtx_unlock(&(vp)->v_interlock)
end_define

begin_define
define|#
directive|define
name|VI_MTX
parameter_list|(
name|vp
parameter_list|)
value|(&(vp)->v_interlock)
end_define

begin_define
define|#
directive|define
name|VN_LOCK_AREC
parameter_list|(
name|vp
parameter_list|)
value|lockallowrecurse((vp)->v_vnlock)
end_define

begin_define
define|#
directive|define
name|VN_LOCK_ASHARE
parameter_list|(
name|vp
parameter_list|)
value|lockallowshare((vp)->v_vnlock)
end_define

begin_define
define|#
directive|define
name|VN_LOCK_DSHARE
parameter_list|(
name|vp
parameter_list|)
value|lockdisableshare((vp)->v_vnlock)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Mods for extensibility.  */
end_comment

begin_comment
comment|/*  * Flags for vdesc_flags:  */
end_comment

begin_define
define|#
directive|define
name|VDESC_MAX_VPS
value|16
end_define

begin_comment
comment|/* Low order 16 flag bits are reserved for willrele flags for vp arguments. */
end_comment

begin_define
define|#
directive|define
name|VDESC_VP0_WILLRELE
value|0x0001
end_define

begin_define
define|#
directive|define
name|VDESC_VP1_WILLRELE
value|0x0002
end_define

begin_define
define|#
directive|define
name|VDESC_VP2_WILLRELE
value|0x0004
end_define

begin_define
define|#
directive|define
name|VDESC_VP3_WILLRELE
value|0x0008
end_define

begin_define
define|#
directive|define
name|VDESC_NOMAP_VPP
value|0x0100
end_define

begin_define
define|#
directive|define
name|VDESC_VPP_WILLRELE
value|0x0200
end_define

begin_comment
comment|/*  * A generic structure.  * This can be used by bypass routines to identify generic arguments.  */
end_comment

begin_struct
struct|struct
name|vop_generic_args
block|{
name|struct
name|vnodeop_desc
modifier|*
name|a_desc
decl_stmt|;
comment|/* other random data follows, presumably */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|vop_bypass_t
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * VDESC_NO_OFFSET is used to identify the end of the offset list  * and in places where no such field exists.  */
end_comment

begin_define
define|#
directive|define
name|VDESC_NO_OFFSET
value|-1
end_define

begin_comment
comment|/*  * This structure describes the vnode operation taking place.  */
end_comment

begin_struct
struct|struct
name|vnodeop_desc
block|{
name|char
modifier|*
name|vdesc_name
decl_stmt|;
comment|/* a readable name for debugging */
name|int
name|vdesc_flags
decl_stmt|;
comment|/* VDESC_* flags */
name|vop_bypass_t
modifier|*
name|vdesc_call
decl_stmt|;
comment|/* Function to call */
comment|/* 	 * These ops are used by bypass routines to map and locate arguments. 	 * Creds and procs are not needed in bypass routines, but sometimes 	 * they are useful to (for example) transport layers. 	 * Nameidata is useful because it has a cred in it. 	 */
name|int
modifier|*
name|vdesc_vp_offsets
decl_stmt|;
comment|/* list ended by VDESC_NO_OFFSET */
name|int
name|vdesc_vpp_offset
decl_stmt|;
comment|/* return vpp location */
name|int
name|vdesc_cred_offset
decl_stmt|;
comment|/* cred location, if any */
name|int
name|vdesc_thread_offset
decl_stmt|;
comment|/* thread location, if any */
name|int
name|vdesc_componentname_offset
decl_stmt|;
comment|/* if any */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * A list of all the operation descs.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
modifier|*
name|vnodeop_descs
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VOPARG_OFFSETOF
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|__offsetof(s_type, field)
end_define

begin_define
define|#
directive|define
name|VOPARG_OFFSETTO
parameter_list|(
name|s_type
parameter_list|,
name|s_offset
parameter_list|,
name|struct_p
parameter_list|)
define|\
value|((s_type)(((char*)(struct_p)) + (s_offset)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_VFS_LOCKS
end_ifdef

begin_comment
comment|/*  * Support code to aid in debugging VFS locking problems.  Not totally  * reliable since if the thread sleeps between changing the lock  * state and checking it with the assert, some other thread could  * change the state.  They are good enough for debugging a single  * filesystem using a single-threaded test.  Note that the unreliability is  * limited to false negatives; efforts were made to ensure that false  * positives cannot occur.  */
end_comment

begin_function_decl
name|void
name|assert_vi_locked
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_vi_unlocked
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_vop_elocked
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_vop_locked
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_vop_unlocked
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ASSERT_VI_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|assert_vi_locked((vp), (str))
end_define

begin_define
define|#
directive|define
name|ASSERT_VI_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|assert_vi_unlocked((vp), (str))
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_ELOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|assert_vop_elocked((vp), (str))
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|assert_vop_locked((vp), (str))
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|assert_vop_unlocked((vp), (str))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG_VFS_LOCKS */
end_comment

begin_define
define|#
directive|define
name|ASSERT_VI_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VI_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_ELOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_UNLOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_VFS_LOCKS */
end_comment

begin_comment
comment|/*  * This call works for vnodes in the kernel.  */
end_comment

begin_define
define|#
directive|define
name|VCALL
parameter_list|(
name|c
parameter_list|)
value|((c)->a_desc->vdesc_call(c))
end_define

begin_define
define|#
directive|define
name|DOINGASYNC
parameter_list|(
name|vp
parameter_list|)
define|\
value|(((vp)->v_mount->mnt_kern_flag& MNTK_ASYNC) != 0&&	\ 	 ((curthread->td_pflags& TDP_SYNCIO) == 0))
end_define

begin_comment
comment|/*  * VMIO support inline  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vmiodirenable
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|int
name|vn_canvmio
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
block|{
if|if
condition|(
name|vp
operator|&&
operator|(
name|vp
operator|->
name|v_type
operator|==
name|VREG
operator|||
operator|(
name|vmiodirenable
operator|&&
name|vp
operator|->
name|v_type
operator|==
name|VDIR
operator|)
operator|)
condition|)
return|return
operator|(
name|TRUE
operator|)
return|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Finally, include the default set of vnode operations.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|vop_getpages_iodone_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|vm_page_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_include
include|#
directive|include
file|"vnode_if.h"
end_include

begin_comment
comment|/* vn_open_flags */
end_comment

begin_define
define|#
directive|define
name|VN_OPEN_NOAUDIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VN_OPEN_NOCAPCHECK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VN_OPEN_NAMECACHE
value|0x00000004
end_define

begin_comment
comment|/*  * Public vnode manipulation functions.  */
end_comment

begin_struct_decl
struct_decl|struct
name|componentname
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ostat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|freebsd11_stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nstat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vfsops
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|vn_get_ino_t
function_decl|)
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|bnoreuselist
parameter_list|(
name|struct
name|bufv
modifier|*
name|bufv
parameter_list|,
name|struct
name|bufobj
modifier|*
name|bo
parameter_list|,
name|daddr_t
name|startn
parameter_list|,
name|daddr_t
name|endn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cache_* may belong in namei.h. */
end_comment

begin_function_decl
name|void
name|cache_changesize
parameter_list|(
name|int
name|newhashsize
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cache_enter
parameter_list|(
name|dvp
parameter_list|,
name|vp
parameter_list|,
name|cnp
parameter_list|)
define|\
value|cache_enter_time(dvp, vp, cnp, NULL, NULL)
end_define

begin_function_decl
name|void
name|cache_enter_time
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|struct
name|timespec
modifier|*
name|dtsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cache_lookup
parameter_list|(
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|timespec
modifier|*
name|tsp
parameter_list|,
name|int
modifier|*
name|ticksp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cache_purge
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cache_purge_negative
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cache_purgevfs
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|change_dir
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
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
name|cvtstat
parameter_list|(
name|struct
name|stat
modifier|*
name|st
parameter_list|,
name|struct
name|ostat
modifier|*
name|ost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freebsd11_cvtnstat
parameter_list|(
name|struct
name|stat
modifier|*
name|sb
parameter_list|,
name|struct
name|nstat
modifier|*
name|nsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_cvtstat
parameter_list|(
name|struct
name|stat
modifier|*
name|st
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
name|ost
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getnewvnode
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vop_vector
modifier|*
name|vops
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
name|void
name|getnewvnode_reserve
parameter_list|(
name|u_int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getnewvnode_drop_reserve
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|insmntque1
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|void
function_decl|(
modifier|*
name|dtr
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|dtr_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|insmntque
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_quad_t
name|init_va_filerev
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|speedup_syncer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_vptocnp
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_fullpath
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
name|vn
parameter_list|,
name|char
modifier|*
modifier|*
name|retbuf
parameter_list|,
name|char
modifier|*
modifier|*
name|freebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_fullpath_global
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
name|vn
parameter_list|,
name|char
modifier|*
modifier|*
name|retbuf
parameter_list|,
name|char
modifier|*
modifier|*
name|freebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|vn_dir_dd_ino
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_commname
parameter_list|(
name|struct
name|vnode
modifier|*
name|vn
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_path_to_global_path
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|u_int
name|pathlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vaccess
parameter_list|(
name|enum
name|vtype
name|type
parameter_list|,
name|mode_t
name|file_mode
parameter_list|,
name|uid_t
name|file_uid
parameter_list|,
name|gid_t
name|file_gid
parameter_list|,
name|accmode_t
name|accmode
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
modifier|*
name|privused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vaccess_acl_nfs4
parameter_list|(
name|enum
name|vtype
name|type
parameter_list|,
name|uid_t
name|file_uid
parameter_list|,
name|gid_t
name|file_gid
parameter_list|,
name|struct
name|acl
modifier|*
name|aclp
parameter_list|,
name|accmode_t
name|accmode
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
modifier|*
name|privused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vaccess_acl_posix1e
parameter_list|(
name|enum
name|vtype
name|type
parameter_list|,
name|uid_t
name|file_uid
parameter_list|,
name|gid_t
name|file_gid
parameter_list|,
name|struct
name|acl
modifier|*
name|acl
parameter_list|,
name|accmode_t
name|accmode
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
modifier|*
name|privused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vattr_null
parameter_list|(
name|struct
name|vattr
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vcount
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vdrop
parameter_list|(
name|vp
parameter_list|)
value|_vdrop((vp), 0)
end_define

begin_define
define|#
directive|define
name|vdropl
parameter_list|(
name|vp
parameter_list|)
value|_vdrop((vp), 1)
end_define

begin_function_decl
name|void
name|_vdrop
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vflush
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|rootrefs
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
name|vget
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|lockflag
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
name|vgone
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vhold
parameter_list|(
name|vp
parameter_list|)
value|_vhold((vp), 0)
end_define

begin_define
define|#
directive|define
name|vholdl
parameter_list|(
name|vp
parameter_list|)
value|_vhold((vp), 1)
end_define

begin_function_decl
name|void
name|_vhold
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinactive
parameter_list|(
name|struct
name|vnode
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
name|vinvalbuf
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|save
parameter_list|,
name|int
name|slpflag
parameter_list|,
name|int
name|slptimeo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vtruncbuf
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|off_t
name|length
parameter_list|,
name|int
name|blksize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vunref
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_printf
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vrecycle
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vrecyclel
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_bmap_seekhole
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|off_t
modifier|*
name|off
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_close
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|ucred
modifier|*
name|file_cred
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
name|vn_finished_write
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_finished_secondary_write
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_isdisk
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
modifier|*
name|errp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_vn_lock
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|flags
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vn_lock
parameter_list|(
name|vp
parameter_list|,
name|flags
parameter_list|)
value|_vn_lock(vp, flags, __FILE__, __LINE__)
end_define

begin_function_decl
name|int
name|vn_open
parameter_list|(
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|,
name|int
modifier|*
name|flagp
parameter_list|,
name|int
name|cmode
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_open_cred
parameter_list|(
name|struct
name|nameidata
modifier|*
name|ndp
parameter_list|,
name|int
modifier|*
name|flagp
parameter_list|,
name|int
name|cmode
parameter_list|,
name|u_int
name|vn_open_flags
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_open_vnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|fmode
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
parameter_list|,
name|struct
name|file
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_pages_remove
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|vm_pindex_t
name|start
parameter_list|,
name|vm_pindex_t
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_pollrecord
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|,
name|int
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_rdwr
parameter_list|(
name|enum
name|uio_rw
name|rw
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|void
modifier|*
name|base
parameter_list|,
name|int
name|len
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|enum
name|uio_seg
name|segflg
parameter_list|,
name|int
name|ioflg
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
parameter_list|,
name|struct
name|ucred
modifier|*
name|file_cred
parameter_list|,
name|ssize_t
modifier|*
name|aresid
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
name|vn_rdwr_inchunks
parameter_list|(
name|enum
name|uio_rw
name|rw
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|len
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|enum
name|uio_seg
name|segflg
parameter_list|,
name|int
name|ioflg
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
parameter_list|,
name|struct
name|ucred
modifier|*
name|file_cred
parameter_list|,
name|size_t
modifier|*
name|aresid
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
name|vn_rlimit_fsize
parameter_list|(
specifier|const
name|struct
name|vnode
modifier|*
name|vn
parameter_list|,
specifier|const
name|struct
name|uio
modifier|*
name|uio
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
name|vn_stat
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
parameter_list|,
name|struct
name|ucred
modifier|*
name|file_cred
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
name|vn_start_write
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|mount
modifier|*
modifier|*
name|mpp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_start_secondary_write
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|mount
modifier|*
modifier|*
name|mpp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_writechk
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_extattr_get
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|ioflg
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|attrname
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|,
name|char
modifier|*
name|buf
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
name|vn_extattr_set
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|ioflg
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|attrname
parameter_list|,
name|int
name|buflen
parameter_list|,
name|char
modifier|*
name|buf
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
name|vn_extattr_rm
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|ioflg
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

begin_function_decl
name|int
name|vn_vget_ino
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|ino_t
name|ino
parameter_list|,
name|int
name|lkflags
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|rvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_vget_ino_gen
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|vn_get_ino_t
name|alloc
parameter_list|,
name|void
modifier|*
name|alloc_arg
parameter_list|,
name|int
name|lkflags
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|rvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_utimes_perm
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vattr
modifier|*
name|vap
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
name|vn_io_fault_uiomove
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|int
name|xfersize
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_io_fault_pgmove
parameter_list|(
name|vm_page_t
name|ma
index|[]
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|int
name|xfersize
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vn_rangelock_unlock
parameter_list|(
name|vp
parameter_list|,
name|cookie
parameter_list|)
define|\
value|rangelock_unlock(&(vp)->v_rl, (cookie), VI_MTX(vp))
end_define

begin_define
define|#
directive|define
name|vn_rangelock_unlock_range
parameter_list|(
name|vp
parameter_list|,
name|cookie
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|rangelock_unlock_range(&(vp)->v_rl, (cookie), (start), (end), 	\ 	    VI_MTX(vp))
end_define

begin_define
define|#
directive|define
name|vn_rangelock_rlock
parameter_list|(
name|vp
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|rangelock_rlock(&(vp)->v_rl, (start), (end), VI_MTX(vp))
end_define

begin_define
define|#
directive|define
name|vn_rangelock_wlock
parameter_list|(
name|vp
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|rangelock_wlock(&(vp)->v_rl, (start), (end), VI_MTX(vp))
end_define

begin_function_decl
name|int
name|vfs_cache_lookup
parameter_list|(
name|struct
name|vop_lookup_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_timestamp
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_write_resume
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_write_suspend
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_write_suspend_umnt
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnlru_free
parameter_list|(
name|int
parameter_list|,
name|struct
name|vfsops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdbmap
parameter_list|(
name|struct
name|vop_bmap_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdfdatasync_buf
parameter_list|(
name|struct
name|vop_fdatasync_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdfsync
parameter_list|(
name|struct
name|vop_fsync_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdgetwritemount
parameter_list|(
name|struct
name|vop_getwritemount_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdgetpages
parameter_list|(
name|struct
name|vop_getpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdinactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdislocked
parameter_list|(
name|struct
name|vop_islocked_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdkqfilter
parameter_list|(
name|struct
name|vop_kqfilter_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdlock
parameter_list|(
name|struct
name|vop_lock1_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdputpages
parameter_list|(
name|struct
name|vop_putpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdunlock
parameter_list|(
name|struct
name|vop_unlock_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_nopoll
parameter_list|(
name|struct
name|vop_poll_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdaccess
parameter_list|(
name|struct
name|vop_access_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdaccessx
parameter_list|(
name|struct
name|vop_accessx_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdadvise
parameter_list|(
name|struct
name|vop_advise_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdadvlock
parameter_list|(
name|struct
name|vop_advlock_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdadvlockasync
parameter_list|(
name|struct
name|vop_advlockasync_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdadvlockpurge
parameter_list|(
name|struct
name|vop_advlockpurge_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdallocate
parameter_list|(
name|struct
name|vop_allocate_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdpathconf
parameter_list|(
name|struct
name|vop_pathconf_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdpoll
parameter_list|(
name|struct
name|vop_poll_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdvptocnp
parameter_list|(
name|struct
name|vop_vptocnp_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdvptofh
parameter_list|(
name|struct
name|vop_vptofh_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdunp_bind
parameter_list|(
name|struct
name|vop_unp_bind_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdunp_connect
parameter_list|(
name|struct
name|vop_unp_connect_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdunp_detach
parameter_list|(
name|struct
name|vop_unp_detach_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_eopnotsupp
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_ebadf
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_einval
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_enoent
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_enotty
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_null
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_panic
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dead_poll
parameter_list|(
name|struct
name|vop_poll_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dead_read
parameter_list|(
name|struct
name|vop_read_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dead_write
parameter_list|(
name|struct
name|vop_write_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These are called from within the actual VOPS. */
end_comment

begin_function_decl
name|void
name|vop_close_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_create_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_deleteextattr_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_link_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_lookup_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_lookup_pre
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_mkdir_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_mknod_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_open_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_read_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_readdir_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_reclaim_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_remove_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_rename_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_rename_pre
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_rmdir_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_setattr_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_setextattr_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_symlink_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_VFS_LOCKS
end_ifdef

begin_function_decl
name|void
name|vop_strategy_pre
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_lock_pre
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_lock_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_unlock_post
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|int
name|rc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vop_unlock_pre
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vop_strategy_pre
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vop_lock_pre
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vop_lock_post
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vop_unlock_post
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vop_unlock_pre
parameter_list|(
name|x
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|vop_rename_fail
parameter_list|(
name|struct
name|vop_rename_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VOP_WRITE_PRE
parameter_list|(
name|ap
parameter_list|)
define|\
value|struct vattr va;						\ 	int error;							\ 	off_t osize, ooffset, noffset;					\ 									\ 	osize = ooffset = noffset = 0;					\ 	if (!VN_KNLIST_EMPTY((ap)->a_vp)) {				\ 		error = VOP_GETATTR((ap)->a_vp,&va, (ap)->a_cred);	\ 		if (error)						\ 			return (error);					\ 		ooffset = (ap)->a_uio->uio_offset;			\ 		osize = (off_t)va.va_size;				\ 	}
end_define

begin_define
define|#
directive|define
name|VOP_WRITE_POST
parameter_list|(
name|ap
parameter_list|,
name|ret
parameter_list|)
define|\
value|noffset = (ap)->a_uio->uio_offset;				\ 	if (noffset> ooffset&& !VN_KNLIST_EMPTY((ap)->a_vp)) {	\ 		VFS_KNOTE_LOCKED((ap)->a_vp, NOTE_WRITE			\ 		    | (noffset> osize ? NOTE_EXTEND : 0));		\ 	}
end_define

begin_define
define|#
directive|define
name|VOP_LOCK
parameter_list|(
name|vp
parameter_list|,
name|flags
parameter_list|)
value|VOP_LOCK1(vp, flags, __FILE__, __LINE__)
end_define

begin_function_decl
name|void
name|vput
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vrele
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vref
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vrefl
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vrefact
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vrefcnt
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|v_addpollinfo
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vnode_create_vobject
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|off_t
name|size
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
name|vnode_destroy_vobject
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|fifo_specops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|dead_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|default_vnodeops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VOP_PANIC
value|((void*)(uintptr_t)vop_panic)
end_define

begin_define
define|#
directive|define
name|VOP_NULL
value|((void*)(uintptr_t)vop_null)
end_define

begin_define
define|#
directive|define
name|VOP_EBADF
value|((void*)(uintptr_t)vop_ebadf)
end_define

begin_define
define|#
directive|define
name|VOP_ENOTTY
value|((void*)(uintptr_t)vop_enotty)
end_define

begin_define
define|#
directive|define
name|VOP_EINVAL
value|((void*)(uintptr_t)vop_einval)
end_define

begin_define
define|#
directive|define
name|VOP_ENOENT
value|((void*)(uintptr_t)vop_enoent)
end_define

begin_define
define|#
directive|define
name|VOP_EOPNOTSUPP
value|((void*)(uintptr_t)vop_eopnotsupp)
end_define

begin_comment
comment|/* fifo_vnops.c */
end_comment

begin_function_decl
name|int
name|fifo_printinfo
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vfs_hash.c */
end_comment

begin_typedef
typedef|typedef
name|int
name|vfs_hash_cmp_t
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|vfs_hash_changesize
parameter_list|(
name|int
name|newhashsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_hash_get
parameter_list|(
specifier|const
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|u_int
name|hash
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|vfs_hash_cmp_t
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|vfs_hash_index
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_hash_insert
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_int
name|hash
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|vfs_hash_cmp_t
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_hash_ref
parameter_list|(
specifier|const
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|u_int
name|hash
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|,
name|vfs_hash_cmp_t
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_hash_rehash
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_int
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_hash_remove
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_kqfilter
parameter_list|(
name|struct
name|vop_kqfilter_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_mark_atime
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|vfs_read_dirent
parameter_list|(
name|struct
name|vop_readdir_args
modifier|*
name|ap
parameter_list|,
name|struct
name|dirent
modifier|*
name|dp
parameter_list|,
name|off_t
name|off
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfs_unixify_accmode
parameter_list|(
name|accmode_t
modifier|*
name|accmode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_unp_reclaim
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setfmode
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setfown
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_chmod
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
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
name|vn_chown
parameter_list|(
name|struct
name|file
modifier|*
name|fp
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|struct
name|ucred
modifier|*
name|active_cred
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
name|vn_fsid
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vattr
modifier|*
name|va
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_VNODE_H_ */
end_comment

end_unit

