begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vnode.h	8.7 (Berkeley) 2/4/94  * $FreeBSD$  */
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_label.h>
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
file|<vm/uma.h>
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
block|}
enum|;
end_enum

begin_comment
comment|/*  * Vnode tag types.  * These are for the benefit of external programs only (e.g., pstat)  * and should NEVER be inspected by the kernel.  */
end_comment

begin_enum
enum|enum
name|vtagtype
block|{
name|VT_NON
block|,
name|VT_UFS
block|,
name|VT_NFS
block|,
name|VT_UNUSED
block|,
name|VT_PC
block|,
name|VT_LFS
block|,
name|VT_LOFS
block|,
name|VT_FDESC
block|,
name|VT_PORTAL
block|,
name|VT_NULL
block|,
name|VT_UMAP
block|,
name|VT_KERNFS
block|,
name|VT_PROCFS
block|,
name|VT_AFS
block|,
name|VT_ISOFS
block|,
name|VT_UNION
block|,
name|VT_MSDOSFS
block|,
name|VT_DEVFS
block|,
name|VT_TFS
block|,
name|VT_VFS
block|,
name|VT_CODA
block|,
name|VT_NTFS
block|,
name|VT_HPFS
block|,
name|VT_NWFS
block|,
name|VT_PSEUDOFS
block|,
name|VT_SMBFS
block|,
name|VT_UDF
block|}
enum|;
end_enum

begin_comment
comment|/*  * Each underlying filesystem allocates its own private area and hangs  * it from v_data.  If non-null, this area is freed in getnewvnode().  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|buflists
argument_list|,
name|buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
name|vop_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

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
comment|/*  * Reading or writing any of these items requires holding the appropriate lock.  *  * Lock reference:  *	f - freelist mutex  *	i - interlock  *	m - mntvnodes mutex  *	p - pollinfo lock  *	v - vnode lock  *  * XXX Not all fields are locked yet and some fields that are marked are not  * locked consistently.  This is a work in progress.  */
end_comment

begin_struct
struct|struct
name|vnode
block|{
name|struct
name|mtx
name|v_interlock
decl_stmt|;
comment|/* lock for "i" things */
name|u_long
name|v_iflag
decl_stmt|;
comment|/* i vnode flags (see below) */
name|int
name|v_usecount
decl_stmt|;
comment|/* i ref count of users */
name|int
name|v_writecount
decl_stmt|;
comment|/* i ref count of writers */
name|long
name|v_numoutput
decl_stmt|;
comment|/* i writes in progress */
name|struct
name|thread
modifier|*
name|v_vxproc
decl_stmt|;
comment|/* i thread owning VXLOCK */
name|int
name|v_holdcnt
decl_stmt|;
comment|/* i page& buffer references */
name|u_long
name|v_vflag
decl_stmt|;
comment|/* v vnode flags */
name|u_long
name|v_id
decl_stmt|;
comment|/* capability identifier */
name|struct
name|mount
modifier|*
name|v_mount
decl_stmt|;
comment|/* ptr to vfs we are in */
name|vop_t
modifier|*
modifier|*
name|v_op
decl_stmt|;
comment|/* vnode operations vector */
name|TAILQ_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_freelist
expr_stmt|;
comment|/* f vnode freelist */
name|TAILQ_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_nmntvnodes
expr_stmt|;
comment|/* m vnodes for mount point */
name|struct
name|buflists
name|v_cleanblkhd
decl_stmt|;
comment|/* SORTED clean blocklist */
name|struct
name|buf
modifier|*
name|v_cleanblkroot
decl_stmt|;
comment|/* clean buf splay tree root */
name|struct
name|buflists
name|v_dirtyblkhd
decl_stmt|;
comment|/* SORTED dirty blocklist */
name|struct
name|buf
modifier|*
name|v_dirtyblkroot
decl_stmt|;
comment|/* dirty buf splay tree root */
name|LIST_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_synclist
expr_stmt|;
comment|/* vnodes with dirty buffers */
name|enum
name|vtype
name|v_type
decl_stmt|;
comment|/* vnode type */
union|union
block|{
name|struct
name|mount
modifier|*
name|vu_mountedhere
decl_stmt|;
comment|/* ptr to mounted vfs (VDIR) */
name|struct
name|socket
modifier|*
name|vu_socket
decl_stmt|;
comment|/* unix ipc (VSOCK) */
struct|struct
block|{
name|struct
name|specinfo
modifier|*
name|vu_specinfo
decl_stmt|;
comment|/* device (VCHR, VBLK) */
name|SLIST_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|vu_specnext
expr_stmt|;
block|}
name|vu_spec
struct|;
name|struct
name|fifoinfo
modifier|*
name|vu_fifoinfo
decl_stmt|;
comment|/* fifo (VFIFO) */
block|}
name|v_un
union|;
name|daddr_t
name|v_lastw
decl_stmt|;
comment|/* last write (write cluster) */
name|daddr_t
name|v_cstart
decl_stmt|;
comment|/* start block of cluster */
name|daddr_t
name|v_lasta
decl_stmt|;
comment|/* last allocation (cluster) */
name|int
name|v_clen
decl_stmt|;
comment|/* length of current cluster */
name|struct
name|vm_object
modifier|*
name|v_object
decl_stmt|;
comment|/* Place to store VM object */
name|struct
name|lock
name|v_lock
decl_stmt|;
comment|/* used if fs don't have one */
name|struct
name|lock
modifier|*
name|v_vnlock
decl_stmt|;
comment|/* pointer to vnode lock */
name|enum
name|vtagtype
name|v_tag
decl_stmt|;
comment|/* type of underlying data */
name|void
modifier|*
name|v_data
decl_stmt|;
comment|/* private data for fs */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|namecache
argument_list|)
name|v_cache_src
expr_stmt|;
comment|/* Cache entries from us */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|namecache
argument_list|)
name|v_cache_dst
expr_stmt|;
comment|/* Cache entries to us */
name|struct
name|vnode
modifier|*
name|v_dd
decl_stmt|;
comment|/* .. vnode */
name|u_long
name|v_ddid
decl_stmt|;
comment|/* .. capability identifier */
name|struct
name|vpollinfo
modifier|*
name|v_pollinfo
decl_stmt|;
comment|/* p Poll events */
name|struct
name|label
name|v_label
decl_stmt|;
comment|/* MAC label for vnode */
ifdef|#
directive|ifdef
name|DEBUG_LOCKS
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* Source file doing locking */
name|int
name|line
decl_stmt|;
comment|/* Line number doing locking */
endif|#
directive|endif
name|udev_t
name|v_cachedfs
decl_stmt|;
comment|/* cached fs id */
name|ino_t
name|v_cachedid
decl_stmt|;
comment|/* cached file id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|v_mountedhere
value|v_un.vu_mountedhere
end_define

begin_define
define|#
directive|define
name|v_socket
value|v_un.vu_socket
end_define

begin_define
define|#
directive|define
name|v_rdev
value|v_un.vu_spec.vu_specinfo
end_define

begin_define
define|#
directive|define
name|v_specnext
value|v_un.vu_spec.vu_specnext
end_define

begin_define
define|#
directive|define
name|v_fifoinfo
value|v_un.vu_fifoinfo
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
comment|/* socket, if VSOCK */
name|void
modifier|*
name|xvu_fifo
decl_stmt|;
comment|/* fifo, if VFIFO */
name|udev_t
name|xvu_rdev
decl_stmt|;
comment|/* maj/min, if VBLK/VCHR */
struct|struct
block|{
name|udev_t
name|xvu_dev
decl_stmt|;
comment|/* device, if VDIR/VREG/VLNK */
name|ino_t
name|xvu_ino
decl_stmt|;
comment|/* id, if VDIR/VREG/VLNK */
block|}
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
value|xv_un.xvu_dev
end_define

begin_define
define|#
directive|define
name|xv_ino
value|xv_un.xvu_ino
end_define

begin_define
define|#
directive|define
name|VN_POLLEVENT
parameter_list|(
name|vp
parameter_list|,
name|events
parameter_list|)
define|\
value|do {							\ 		if ((vp)->v_pollinfo != NULL&& 		\ 		    (vp)->v_pollinfo->vpi_events& (events))	\ 			vn_pollevent((vp), (events));		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|VN_KNOTE
parameter_list|(
name|vp
parameter_list|,
name|b
parameter_list|)
define|\
value|do {							\ 		if ((vp)->v_pollinfo != NULL)			\ 			KNOTE(&vp->v_pollinfo->vpi_selinfo.si_note, (b)); \ 	} while (0)
end_define

begin_comment
comment|/*  * Vnode flags.  *	VI flags are protected by interlock and live in v_iflag  *	VV flags are protected by the vnode lock and live in v_vflag  */
end_comment

begin_define
define|#
directive|define
name|VI_XLOCK
value|0x0001
end_define

begin_comment
comment|/* vnode is locked to change vtype */
end_comment

begin_define
define|#
directive|define
name|VI_XWANT
value|0x0002
end_define

begin_comment
comment|/* thread is waiting for vnode */
end_comment

begin_define
define|#
directive|define
name|VI_BWAIT
value|0x0004
end_define

begin_comment
comment|/* waiting for output to complete */
end_comment

begin_define
define|#
directive|define
name|VI_OLOCK
value|0x0008
end_define

begin_comment
comment|/* vnode is locked waiting for an object */
end_comment

begin_define
define|#
directive|define
name|VI_OWANT
value|0x0010
end_define

begin_comment
comment|/* a thread is waiting for VOLOCK */
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
name|VI_AGE
value|0x0040
end_define

begin_comment
comment|/* Insert vnode at head of free list */
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
name|VI_OBJDIRTY
value|0x0400
end_define

begin_comment
comment|/* object might be dirty */
end_comment

begin_comment
comment|/*  * XXX VI_ONWORKLST could be replaced with a check for NULL list elements  * in v_synclist.  */
end_comment

begin_define
define|#
directive|define
name|VI_ONWORKLST
value|0x0200
end_define

begin_comment
comment|/* On syncer work-list */
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
name|VV_OBJBUF
value|0x0008
end_define

begin_comment
comment|/* Allocate buffers in VM object */
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
name|short
name|va_nlink
decl_stmt|;
comment|/* number of references to file */
name|uid_t
name|va_uid
decl_stmt|;
comment|/* owner user id */
name|gid_t
name|va_gid
decl_stmt|;
comment|/* owner group id */
name|udev_t
name|va_fsid
decl_stmt|;
comment|/* filesystem id */
name|long
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
name|udev_t
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

begin_comment
comment|/*  * Flags for ioflag. (high 16 bits used to ask for read-ahead and  * help with write clustering)  */
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
name|IO_SYNC
value|0x0004
end_define

begin_comment
comment|/* do I/O synchronously */
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
name|IO_NDELAY
value|0x0010
end_define

begin_comment
comment|/* FNDELAY flag set in file table */
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
name|IO_ASYNC
value|0x0080
end_define

begin_comment
comment|/* bawrite rather then bdwrite */
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
name|IO_NOWDRAIN
value|0x0200
end_define

begin_comment
comment|/* do not block on wdrain */
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

begin_comment
comment|/*  *  Modes.  Some values same as Ixxx entries from inode.h for now.  */
end_comment

begin_define
define|#
directive|define
name|VEXEC
value|000100
end_define

begin_comment
comment|/* execute/search permission */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|000200
end_define

begin_comment
comment|/* write permission */
end_comment

begin_define
define|#
directive|define
name|VREAD
value|000400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|VSVTX
value|001000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|VSGID
value|002000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|VSUID
value|004000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|VADMIN
value|010000
end_define

begin_comment
comment|/* permission to administer */
end_comment

begin_define
define|#
directive|define
name|VSTAT
value|020000
end_define

begin_comment
comment|/* permission to retrieve attrs */
end_comment

begin_define
define|#
directive|define
name|VAPPEND
value|040000
end_define

begin_comment
comment|/* permission to write/append */
end_comment

begin_define
define|#
directive|define
name|VALLPERM
value|(VEXEC | VWRITE | VREAD | VADMIN | VSTAT | VAPPEND)
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
name|DOCLOSE
value|0x0008
end_define

begin_comment
comment|/* vclean: close active files */
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

begin_define
define|#
directive|define
name|VNODEOP_SET
parameter_list|(
name|f
parameter_list|)
define|\
value|C_SYSINIT(f##init, SI_SUB_VFS, SI_ORDER_SECOND, vfs_add_vnodeops,&f); \ 	C_SYSUNINIT(f##uninit, SI_SUB_VFS, SI_ORDER_SECOND, vfs_rm_vnodeops,&f);
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
name|int
name|desiredvnodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of vnodes desired */
end_comment

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|namei_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|prtactive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nonzero to call vprint() */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|vfs_ioopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Macro/function to check for client cache inconsistency w.r.t. leasing.  */
end_comment

begin_define
define|#
directive|define
name|LEASE_READ
value|0x1
end_define

begin_comment
comment|/* Check lease for readers */
end_comment

begin_define
define|#
directive|define
name|LEASE_WRITE
value|0x2
end_define

begin_comment
comment|/* Check lease for modifiers */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|lease_updatetime
function_decl|)
parameter_list|(
name|int
name|deltat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Requires interlock */
end_comment

begin_define
define|#
directive|define
name|VSHOULDFREE
parameter_list|(
name|vp
parameter_list|)
define|\
value|(!((vp)->v_iflag& (VI_FREE|VI_DOOMED))&& \ 	 !(vp)->v_holdcnt&& !(vp)->v_usecount&& \ 	 (!(vp)->v_object || \ 	  !((vp)->v_object->ref_count || (vp)->v_object->resident_page_count)))
end_define

begin_comment
comment|/* Requires interlock */
end_comment

begin_define
define|#
directive|define
name|VMIGHTFREE
parameter_list|(
name|vp
parameter_list|)
define|\
value|(!((vp)->v_iflag& (VI_FREE|VI_DOOMED|VI_XLOCK))&&	\ 	 LIST_EMPTY(&(vp)->v_cache_src)&& !(vp)->v_usecount)
end_define

begin_comment
comment|/* Requires interlock */
end_comment

begin_define
define|#
directive|define
name|VSHOULDBUSY
parameter_list|(
name|vp
parameter_list|)
define|\
value|(((vp)->v_iflag& VI_FREE)&& \ 	 ((vp)->v_holdcnt || (vp)->v_usecount))
end_define

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
name|int
name|vdesc_offset
decl_stmt|;
comment|/* offset in vector,first for speed */
name|char
modifier|*
name|vdesc_name
decl_stmt|;
comment|/* a readable name for debugging */
name|int
name|vdesc_flags
decl_stmt|;
comment|/* VDESC_* flags */
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
comment|/* 	 * Finally, we've got a list of private data (about each operation) 	 * for each transport layer.  (Support to manage this list is not 	 * yet part of BSD.) 	 */
name|caddr_t
modifier|*
name|vdesc_transports
decl_stmt|;
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

begin_comment
comment|/*  * Interlock for scanning list of vnodes attached to a mountpoint  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|mntvnode_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This macro is very helpful in defining those offsets in the vdesc struct.  *  * This is stolen from X11R4.  I ignored all the fancy stuff for  * Crays, so if you decide to port this to such a serious machine,  * you might want to consult Intrinsic.h's XtOffset{,Of,To}.  */
end_comment

begin_define
define|#
directive|define
name|VOPARG_OFFSET
parameter_list|(
name|p_type
parameter_list|,
name|field
parameter_list|)
define|\
value|((int) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))
end_define

begin_define
define|#
directive|define
name|VOPARG_OFFSETOF
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
define|\
value|VOPARG_OFFSET(s_type*,field)
end_define

begin_define
define|#
directive|define
name|VOPARG_OFFSETTO
parameter_list|(
name|S_TYPE
parameter_list|,
name|S_OFFSET
parameter_list|,
name|STRUCT_P
parameter_list|)
define|\
value|((S_TYPE)(((char*)(STRUCT_P))+(S_OFFSET)))
end_define

begin_comment
comment|/*  * This structure is used to configure the new vnodeops vector.  */
end_comment

begin_struct
struct|struct
name|vnodeopv_entry_desc
block|{
name|struct
name|vnodeop_desc
modifier|*
name|opve_op
decl_stmt|;
comment|/* which operation this is */
name|vop_t
modifier|*
name|opve_impl
decl_stmt|;
comment|/* code implementing this operation */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vnodeopv_desc
block|{
comment|/* ptr to the ptr to the vector where op should go */
name|vop_t
modifier|*
modifier|*
modifier|*
name|opv_desc_vector_p
decl_stmt|;
name|struct
name|vnodeopv_entry_desc
modifier|*
name|opv_desc_ops
decl_stmt|;
comment|/* null terminated list */
block|}
struct|;
end_struct

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

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_VFS_LOCKS
end_ifdef

begin_comment
comment|/*  * Macros to aid in tracing VFS locking problems.  Not totally  * reliable since if the thread sleeps between changing the lock  * state and checking it with the assert, some other thread could  * change the state.  They are good enough for debugging a single  * filesystem using a single-threaded test.  I find that 'cvs co src'  * is a pretty good test.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vfs_badlock_panic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vfs_badlock_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vfs_badlock_mutex
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASSERT_VI_UNLOCKED
parameter_list|(
name|vp
parameter_list|)
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (vfs_badlock_mutex)						\ 		mtx_assert(VI_MTX(_vp), MA_NOTOWNED);			\ } while (0)								\  #define	ASSERT_VI_LOCKED(vp)						\ do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (vfs_badlock_mutex)						\ 		mtx_assert(VI_MTX(_vp), MA_OWNED);			\ } while (0)
end_define

begin_comment
unit|\
comment|/*  * This only exists to supress warnings from unlocked specfs accesses.  It is  * no longer ok to have an unlocked VFS.  */
end_comment

begin_define
define|#
directive|define
name|IGNORE_LOCK
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_type == VCHR || (vp)->v_type == VBAD)
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
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& !IGNORE_LOCK(_vp)&& !VOP_ISLOCKED(_vp, NULL)) {	\ 		if (vfs_badlock_print)					\ 			printf("%s: %p is not locked but should be\n",	\ 			    str, _vp);					\ 		if (vfs_badlock_panic)					\ 			Debugger("Lock violation.\n");			\ 	}								\ } while (0)
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
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 	int lockstate;							\ 									\ 	if (_vp&& !IGNORE_LOCK(_vp)) {					\ 		lockstate = VOP_ISLOCKED(_vp, curthread);		\ 		if (lockstate == LK_EXCLUSIVE) {			\ 			if (vfs_badlock_print)				\ 				printf("%s: %p is locked but should not be\n",	\ 				    str, _vp);				\ 			if (vfs_badlock_panic)				\ 				Debugger("Lock Violation.\n");		\ 		}							\ 	}								\ } while (0)
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
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& !IGNORE_LOCK(_vp)&&					\ 	    VOP_ISLOCKED(_vp, curthread) != LK_EXCLUSIVE) {		\ 		if (vfs_badlock_print)					\ 			printf("%s: %p is not exclusive locked but should be\n",\ 			    str, _vp);					\ 		if (vfs_badlock_panic)					\ 			Debugger("Lock violation.\n");			\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_ELOCKED_OTHER
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& !IGNORE_LOCK(_vp)&&					\ 	    VOP_ISLOCKED(_vp, curthread) != LK_EXCLOTHER) {		\ 		if (vfs_badlock_print)					\ 			printf("%s: %p is not exclusive locked by another thread\n",\ 			    str, _vp);					\ 		if (vfs_badlock_panic)					\ 			Debugger("Lock violation.\n");			\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASSERT_VOP_SLOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
define|\
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& !IGNORE_LOCK(_vp)&&					\ 	    VOP_ISLOCKED(_vp, NULL) != LK_SHARED) {			\ 		if (vfs_badlock_print)					\ 			printf("%s: %p is not locked shared but should be",\ 		    str, _vp);						\ 		if (vfs_badlock_panic)					\ 			Debugger("Lock violation.\n");			\ 	}								\ } while (0)
end_define

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
name|vop_unlock_pre
parameter_list|(
name|void
modifier|*
name|a
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_VOP_LOCKED
parameter_list|(
name|vp
parameter_list|,
name|str
parameter_list|)
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
end_define

begin_define
define|#
directive|define
name|ASSERT_VI_UNLOCKED
parameter_list|(
name|vp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASSERT_VI_LOCKED
parameter_list|(
name|vp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * VOCALL calls an op given an ops vector.  We break it out because BSD's  * vclean changes the ops vector and then wants to call ops with the old  * vector.  */
end_comment

begin_define
define|#
directive|define
name|VOCALL
parameter_list|(
name|OPSV
parameter_list|,
name|OFF
parameter_list|,
name|AP
parameter_list|)
value|(( *((OPSV)[(OFF)])) (AP))
end_define

begin_comment
comment|/*  * This call works for vnodes in the kernel.  */
end_comment

begin_define
define|#
directive|define
name|VCALL
parameter_list|(
name|VP
parameter_list|,
name|OFF
parameter_list|,
name|AP
parameter_list|)
value|VOCALL((VP)->v_op,(OFF),(AP))
end_define

begin_define
define|#
directive|define
name|VDESC
parameter_list|(
name|OP
parameter_list|)
value|(& __CONCAT(OP,_desc))
end_define

begin_define
define|#
directive|define
name|VOFFSET
parameter_list|(
name|OP
parameter_list|)
value|(VDESC(OP)->vdesc_offset)
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

begin_include
include|#
directive|include
file|"vnode_if.h"
end_include

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
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|lease_check_hook
function_decl|)
parameter_list|(
name|struct
name|vop_lease_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|softdep_fsync_hook
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|softdep_process_worklist_hook
function_decl|)
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|addaliasu
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|udev_t
name|nvp_rdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bdevvp
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cache_* may belong in namei.h. */
end_comment

begin_function_decl
name|void
name|cache_enter
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
name|cache_purgevfs
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
name|cache_leaf_test
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
name|cvtnstat
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
name|getnewvnode
parameter_list|(
name|enum
name|vtagtype
name|tag
parameter_list|,
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|vop_t
modifier|*
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
name|int
name|lease_check
parameter_list|(
name|struct
name|vop_lease_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|spec_vnoperate
parameter_list|(
name|struct
name|vop_generic_args
modifier|*
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

begin_define
define|#
directive|define
name|textvp_fullpath
parameter_list|(
name|p
parameter_list|,
name|rb
parameter_list|,
name|rfb
parameter_list|)
define|\
value|vn_fullpath(FIRST_THREAD_IN_PROC(p), (p)->p_textvp, rb, rfb)
end_define

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
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|mode_t
name|acc_mode
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
name|mode_t
name|acc_mode
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

begin_function_decl
name|void
name|vdrop
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfinddev
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|enum
name|vtype
name|type
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
name|vfs_add_vnodeops
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_rm_vnodeops
parameter_list|(
specifier|const
name|void
modifier|*
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

begin_function_decl
name|void
name|vgonel
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
name|vhold
parameter_list|(
name|struct
name|vnode
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
name|struct
name|thread
modifier|*
name|td
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
name|vprint
parameter_list|(
name|char
modifier|*
name|label
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vrecycle
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|mtx
modifier|*
name|inter_lkp
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
name|vn_lock
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
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_LOCKS
end_ifdef

begin_function_decl
name|int
name|debug_vn_lock
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
name|thread
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
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
parameter_list|,
name|p
parameter_list|)
value|debug_vn_lock(vp,flags,p,__FILE__,__LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_pollevent
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vn_pollgone
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
name|caddr_t
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
name|int
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
name|caddr_t
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
name|int
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
name|dev_t
name|vn_todev
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
name|vn_write_suspend_wait
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
name|int
name|vfs_object_create
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
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfs_write_suspend
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
name|vop_stdlock
parameter_list|(
name|struct
name|vop_lock_args
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
name|vop_noislocked
parameter_list|(
name|struct
name|vop_islocked_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_nolock
parameter_list|(
name|struct
name|vop_lock_args
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
name|vop_nounlock
parameter_list|(
name|struct
name|vop_unlock_args
modifier|*
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
name|vop_revoke
parameter_list|(
name|struct
name|vop_revoke_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_sharedlock
parameter_list|(
name|struct
name|vop_lock_args
modifier|*
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
name|vop_defaultop
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
name|vop_stdcreatevobject
parameter_list|(
name|struct
name|vop_createvobject_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stddestroyvobject
parameter_list|(
name|struct
name|vop_destroyvobject_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vop_stdgetvobject
parameter_list|(
name|struct
name|vop_getvobject_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vfree
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|vbusy
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

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|default_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|spec_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|dead_vnodeop_p
decl_stmt|;
end_decl_stmt

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

