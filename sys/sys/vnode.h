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
file|<vm/vm_zone.h>
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
name|__P
typedef|((
name|void
modifier|*
typedef|));
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
comment|/*  * Reading or writing any of these items requires holding the appropriate lock.  * v_freelist is locked by the global vnode_free_list mutex.  * v_mntvnodes is locked by the global mntvnodes mutex.  * v_flag, v_usecount, v_holdcount and v_writecount are  *    locked by the v_interlock mutex.  * v_pollinfo is locked by the lock contained inside it.  */
end_comment

begin_struct
struct|struct
name|vnode
block|{
name|u_long
name|v_flag
decl_stmt|;
comment|/* vnode flags (see below) */
name|int
name|v_usecount
decl_stmt|;
comment|/* reference count of users */
name|int
name|v_writecount
decl_stmt|;
comment|/* reference count of writers */
name|int
name|v_holdcnt
decl_stmt|;
comment|/* page& buffer references */
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
comment|/* vnode freelist */
name|TAILQ_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_nmntvnodes
expr_stmt|;
comment|/* vnodes for mount point */
name|struct
name|buflists
name|v_cleanblkhd
decl_stmt|;
comment|/* clean blocklist head */
name|struct
name|buflists
name|v_dirtyblkhd
decl_stmt|;
comment|/* dirty blocklist head */
name|LIST_ENTRY
argument_list|(
argument|vnode
argument_list|)
name|v_synclist
expr_stmt|;
comment|/* vnodes with dirty buffers */
name|long
name|v_numoutput
decl_stmt|;
comment|/* num of writes in progress */
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
name|mtx
name|v_interlock
decl_stmt|;
comment|/* lock on usecount and flag */
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
name|struct
name|thread
modifier|*
name|v_vxproc
decl_stmt|;
comment|/* thread owning VXLOCK */
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
comment|/*  * Vnode flags.  */
end_comment

begin_define
define|#
directive|define
name|VROOT
value|0x00001
end_define

begin_comment
comment|/* root of its file system */
end_comment

begin_define
define|#
directive|define
name|VTEXT
value|0x00002
end_define

begin_comment
comment|/* vnode is a pure text prototype */
end_comment

begin_define
define|#
directive|define
name|VSYSTEM
value|0x00004
end_define

begin_comment
comment|/* vnode being used by kernel */
end_comment

begin_define
define|#
directive|define
name|VISTTY
value|0x00008
end_define

begin_comment
comment|/* vnode represents a tty */
end_comment

begin_define
define|#
directive|define
name|VXLOCK
value|0x00100
end_define

begin_comment
comment|/* vnode is locked to change underlying type */
end_comment

begin_define
define|#
directive|define
name|VXWANT
value|0x00200
end_define

begin_comment
comment|/* thread is waiting for vnode */
end_comment

begin_define
define|#
directive|define
name|VBWAIT
value|0x00400
end_define

begin_comment
comment|/* waiting for output to complete */
end_comment

begin_define
define|#
directive|define
name|VNOSYNC
value|0x01000
end_define

begin_comment
comment|/* unlinked, stop syncing */
end_comment

begin_comment
comment|/* open for business    0x01000 */
end_comment

begin_define
define|#
directive|define
name|VOBJBUF
value|0x02000
end_define

begin_comment
comment|/* Allocate buffers in VM object */
end_comment

begin_define
define|#
directive|define
name|VCOPYONWRITE
value|0x04000
end_define

begin_comment
comment|/* vnode is doing copy-on-write */
end_comment

begin_define
define|#
directive|define
name|VAGE
value|0x08000
end_define

begin_comment
comment|/* Insert vnode at head of free list */
end_comment

begin_define
define|#
directive|define
name|VOLOCK
value|0x10000
end_define

begin_comment
comment|/* vnode is locked waiting for an object */
end_comment

begin_define
define|#
directive|define
name|VOWANT
value|0x20000
end_define

begin_comment
comment|/* a thread is waiting for VOLOCK */
end_comment

begin_define
define|#
directive|define
name|VDOOMED
value|0x40000
end_define

begin_comment
comment|/* This vnode is being recycled */
end_comment

begin_define
define|#
directive|define
name|VFREE
value|0x80000
end_define

begin_comment
comment|/* This vnode is on the freelist */
end_comment

begin_comment
comment|/* open for business	0x100000 */
end_comment

begin_define
define|#
directive|define
name|VONWORKLST
value|0x200000
end_define

begin_comment
comment|/* On syncer work-list */
end_comment

begin_define
define|#
directive|define
name|VMOUNT
value|0x400000
end_define

begin_comment
comment|/* Mount in progress */
end_comment

begin_define
define|#
directive|define
name|VOBJDIRTY
value|0x800000
end_define

begin_comment
comment|/* object might be dirty */
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
comment|/* file system id */
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
value|0x01
end_define

begin_comment
comment|/* do I/O as atomic unit */
end_comment

begin_define
define|#
directive|define
name|IO_APPEND
value|0x02
end_define

begin_comment
comment|/* append write to end */
end_comment

begin_define
define|#
directive|define
name|IO_SYNC
value|0x04
end_define

begin_comment
comment|/* do I/O synchronously */
end_comment

begin_define
define|#
directive|define
name|IO_NODELOCKED
value|0x08
end_define

begin_comment
comment|/* underlying node already locked */
end_comment

begin_define
define|#
directive|define
name|IO_NDELAY
value|0x10
end_define

begin_comment
comment|/* FNDELAY flag set in file table */
end_comment

begin_define
define|#
directive|define
name|IO_VMIO
value|0x20
end_define

begin_comment
comment|/* data already in VMIO space */
end_comment

begin_define
define|#
directive|define
name|IO_INVAL
value|0x40
end_define

begin_comment
comment|/* invalidate after I/O */
end_comment

begin_define
define|#
directive|define
name|IO_ASYNC
value|0x80
end_define

begin_comment
comment|/* bawrite rather then bdwrite */
end_comment

begin_define
define|#
directive|define
name|IO_DIRECT
value|0x100
end_define

begin_comment
comment|/* attempt to bypass buffer cache */
end_comment

begin_define
define|#
directive|define
name|IO_NOWDRAIN
value|0x200
end_define

begin_comment
comment|/* do not block on wdrain */
end_comment

begin_comment
comment|/*  *  Modes.  Some values same as Ixxx entries from inode.h for now.  */
end_comment

begin_define
define|#
directive|define
name|VADMIN
value|010000
end_define

begin_comment
comment|/* permission to administer vnode */
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
name|VSGID
value|002000
end_define

begin_comment
comment|/* set group id on execution */
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
name|VREAD
value|000400
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|000200
end_define

begin_define
define|#
directive|define
name|VEXEC
value|000100
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
name|vm_zone_t
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

begin_extern
extern|extern void	(*lease_updatetime
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|int
name|deltat
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VSHOULDFREE
parameter_list|(
name|vp
parameter_list|)
define|\
value|(!((vp)->v_flag& (VFREE|VDOOMED))&& \ 	 !(vp)->v_holdcnt&& !(vp)->v_usecount&& \ 	 (!(vp)->v_object || \ 	  !((vp)->v_object->ref_count || (vp)->v_object->resident_page_count)))
end_define

begin_define
define|#
directive|define
name|VMIGHTFREE
parameter_list|(
name|vp
parameter_list|)
define|\
value|(!((vp)->v_flag& (VFREE|VDOOMED|VXLOCK))&&	\ 	 LIST_EMPTY(&(vp)->v_cache_src)&& !(vp)->v_usecount)
end_define

begin_define
define|#
directive|define
name|VSHOULDBUSY
parameter_list|(
name|vp
parameter_list|)
define|\
value|(((vp)->v_flag& VFREE)&& \ 	 ((vp)->v_holdcnt || (vp)->v_usecount))
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

begin_comment
comment|/*  * [dfr] Kludge until I get around to fixing all the vfs locking.  */
end_comment

begin_define
define|#
directive|define
name|IS_LOCKING_VFS
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_tag == VT_UFS			\ 				 || (vp)->v_tag == VT_NFS		\ 				 || (vp)->v_tag == VT_LFS		\ 				 || (vp)->v_tag == VT_ISOFS		\ 				 || (vp)->v_tag == VT_MSDOSFS		\ 				 || (vp)->v_tag == VT_DEVFS)
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
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& IS_LOCKING_VFS(_vp)&& !VOP_ISLOCKED(_vp, NULL))	\ 		panic("%s: %p is not locked but should be", str, _vp);	\ } while (0)
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
value|do {									\ 	struct vnode *_vp = (vp);					\ 	int lockstate;							\ 									\ 	if (_vp&& IS_LOCKING_VFS(_vp)) {				\ 		lockstate = VOP_ISLOCKED(_vp, curthread);		\ 		if (lockstate == LK_EXCLUSIVE)				\ 			panic("%s: %p is locked but should not be",	\ 			    str, _vp);					\ 	}								\ } while (0)
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
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& IS_LOCKING_VFS(_vp)&&				\ 	    VOP_ISLOCKED(_vp, curthread) != LK_EXCLUSIVE)			\ 		panic("%s: %p is not exclusive locked but should be",	\ 		    str, _vp);						\ } while (0)
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
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& IS_LOCKING_VFS(_vp)&&				\ 	    VOP_ISLOCKED(_vp, curthread) != LK_EXCLOTHER)			\ 		panic("%s: %p is not exclusive locked by another thread",	\ 		    str, _vp);						\ } while (0)
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
value|do {									\ 	struct vnode *_vp = (vp);					\ 									\ 	if (_vp&& IS_LOCKING_VFS(_vp)&&				\ 	    VOP_ISLOCKED(_vp, NULL) != LK_SHARED)			\ 		panic("%s: %p is not locked shared but should be",	\ 		    str, _vp);						\ } while (0)
end_define

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

begin_extern
extern|extern int	(*lease_check_hook
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lease_args
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|addaliasu
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|udev_t
name|nvp_rdev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bdevvp
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache_* may belong in namei.h. */
end_comment

begin_decl_stmt
name|void
name|cache_enter
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|dvp
operator|,
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|componentname
operator|*
name|cnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cache_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|dvp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
expr|struct
name|componentname
operator|*
name|cnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cache_purge
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cache_purgevfs
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cache_leaf_test
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvtstat
name|__P
argument_list|(
operator|(
expr|struct
name|stat
operator|*
name|st
operator|,
expr|struct
name|ostat
operator|*
name|ost
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvtnstat
name|__P
argument_list|(
operator|(
expr|struct
name|stat
operator|*
name|sb
operator|,
expr|struct
name|nstat
operator|*
name|nsb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getnewvnode
name|__P
argument_list|(
operator|(
expr|enum
name|vtagtype
name|tag
operator|,
expr|struct
name|mount
operator|*
name|mp
operator|,
name|vop_t
operator|*
operator|*
name|vops
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lease_check
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lease_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_vnoperate
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|speedup_syncer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|vn_fullpath
name|__P
argument_list|(
operator|(
expr|struct
name|thread
operator|*
name|td
operator|,
expr|struct
name|vnode
operator|*
name|vn
operator|,
name|char
operator|*
operator|*
name|retbuf
operator|,
name|char
operator|*
operator|*
name|freebuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vaccess
name|__P
argument_list|(
operator|(
expr|enum
name|vtype
name|type
operator|,
name|mode_t
name|file_mode
operator|,
name|uid_t
name|uid
operator|,
name|gid_t
name|gid
operator|,
name|mode_t
name|acc_mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|privused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vaccess_acl_posix1e
name|__P
argument_list|(
operator|(
expr|enum
name|vtype
name|type
operator|,
name|uid_t
name|file_uid
operator|,
name|gid_t
name|file_gid
operator|,
expr|struct
name|acl
operator|*
name|acl
operator|,
name|mode_t
name|acc_mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|privused
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vattr_null
name|__P
argument_list|(
operator|(
expr|struct
name|vattr
operator|*
name|vap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vcount
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vdrop
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
name|vfinddev
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|enum
name|vtype
name|type
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_add_vnodeops
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_rm_vnodeops
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
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
name|mp
operator|,
name|int
name|rootrefs
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vget
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|lockflag
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vgone
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vgonel
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vhold
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
name|vinvalbuf
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|save
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|thread
operator|*
name|td
operator|,
name|int
name|slpflag
operator|,
name|int
name|slptimeo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vtruncbuf
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|thread
operator|*
name|td
operator|,
name|off_t
name|length
operator|,
name|int
name|blksize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vprint
name|__P
argument_list|(
operator|(
name|char
operator|*
name|label
operator|,
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vrecycle
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|mtx
operator|*
name|inter_lkp
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_close
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|flags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vn_finished_write
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_isdisk
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
operator|*
name|errp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|flags
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_LOCKS
end_ifdef

begin_decl_stmt
name|int
name|debug_vn_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|flags
operator|,
expr|struct
name|thread
operator|*
name|p
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|int
name|line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|vn_mkdir
name|__P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
name|int
name|mode
operator|,
expr|enum
name|uio_seg
name|segflg
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_open
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
name|int
operator|*
name|flagp
operator|,
name|int
name|cmode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_open_cred
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
name|int
operator|*
name|flagp
operator|,
name|int
name|cmode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vn_pollevent
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|events
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vn_pollgone
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_pollrecord
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|thread
operator|*
name|p
operator|,
name|int
name|events
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_rdwr
name|__P
argument_list|(
operator|(
expr|enum
name|uio_rw
name|rw
operator|,
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|base
operator|,
name|int
name|len
operator|,
name|off_t
name|offset
operator|,
expr|enum
name|uio_seg
name|segflg
operator|,
name|int
name|ioflg
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|aresid
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_rdwr_inchunks
name|__P
argument_list|(
operator|(
expr|enum
name|uio_rw
name|rw
operator|,
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|base
operator|,
name|int
name|len
operator|,
name|off_t
name|offset
operator|,
expr|enum
name|uio_seg
name|segflg
operator|,
name|int
name|ioflg
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|aresid
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_stat
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|stat
operator|*
name|sb
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_start_write
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|mount
operator|*
operator|*
name|mpp
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|vn_todev
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_write_suspend_wait
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_writechk
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_extattr_get
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|ioflg
operator|,
name|int
name|attrnamespace
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|,
name|int
operator|*
name|buflen
operator|,
name|char
operator|*
name|buf
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_extattr_set
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|ioflg
operator|,
name|int
name|attrnamespace
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|,
name|int
name|buflen
operator|,
name|char
operator|*
name|buf
operator|,
expr|struct
name|thread
operator|*
name|td
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|vfs_cache_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfs_object_create
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|thread
operator|*
name|td
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_timestamp
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_write_resume
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfs_write_suspend
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdbmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdgetwritemount
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getwritemount_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdgetpages
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getpages_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdinactive
name|__P
argument_list|(
operator|(
expr|struct
name|vop_inactive_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdislocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdputpages
name|__P
argument_list|(
operator|(
expr|struct
name|vop_putpages_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdunlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_noislocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_nolock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_nopoll
name|__P
argument_list|(
operator|(
expr|struct
name|vop_poll_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_nounlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdpathconf
name|__P
argument_list|(
operator|(
expr|struct
name|vop_pathconf_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdpoll
name|__P
argument_list|(
operator|(
expr|struct
name|vop_poll_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_revoke
name|__P
argument_list|(
operator|(
expr|struct
name|vop_revoke_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_sharedlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_eopnotsupp
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_ebadf
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_einval
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_enotty
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_defaultop
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_null
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_panic
name|__P
argument_list|(
operator|(
expr|struct
name|vop_generic_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdcreatevobject
name|__P
argument_list|(
operator|(
expr|struct
name|vop_createvobject_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stddestroyvobject
name|__P
argument_list|(
operator|(
expr|struct
name|vop_destroyvobject_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vop_stdgetvobject
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getvobject_args
operator|*
name|ap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vfree
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
name|void
name|vput
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vrele
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vref
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vbusy
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

