begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vnode.h	7.29 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * The vnode is the focus of all file activity in UNIX.  * There is a unique vnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  */
end_comment

begin_comment
comment|/*  * vnode types. VNON means no type.  */
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
comment|/*  * Vnode tag types.  * These are for the benefit of external programs only (e.g., pstat)  * and should NEVER be inspected inside the kernel.  */
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
name|VT_MFS
block|}
enum|;
end_enum

begin_comment
comment|/*  * This defines the maximum size of the private data area  * permitted for any file system type. A defined constant   * is used rather than a union structure to cut down on the  * number of header files that must be included.  */
end_comment

begin_define
define|#
directive|define
name|VN_MAXPRIVATE
value|184
end_define

begin_struct
struct|struct
name|vnode
block|{
name|u_long
name|v_flag
decl_stmt|;
comment|/* vnode flags (see below) */
name|long
name|v_usecount
decl_stmt|;
comment|/* reference count of users */
name|long
name|v_holdcnt
decl_stmt|;
comment|/* page& buffer references */
name|u_short
name|v_shlockc
decl_stmt|;
comment|/* count of shared locks */
name|u_short
name|v_exlockc
decl_stmt|;
comment|/* count of exclusive locks */
name|off_t
name|v_lastr
decl_stmt|;
comment|/* last read (read-ahead) */
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
name|struct
name|vnodeops
modifier|*
name|v_op
decl_stmt|;
comment|/* vnode operations */
name|struct
name|vnode
modifier|*
name|v_freef
decl_stmt|;
comment|/* vnode freelist forward */
name|struct
name|vnode
modifier|*
modifier|*
name|v_freeb
decl_stmt|;
comment|/* vnode freelist back */
name|struct
name|vnode
modifier|*
name|v_mountf
decl_stmt|;
comment|/* vnode mountlist forward */
name|struct
name|vnode
modifier|*
modifier|*
name|v_mountb
decl_stmt|;
comment|/* vnode mountlist back */
name|struct
name|buf
modifier|*
name|v_cleanblkhd
decl_stmt|;
comment|/* clean blocklist head */
name|struct
name|buf
modifier|*
name|v_dirtyblkhd
decl_stmt|;
comment|/* dirty blocklist head */
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
name|struct
name|text
modifier|*
name|vu_text
decl_stmt|;
comment|/* text/mapped region (VREG) */
name|struct
name|specinfo
modifier|*
name|vu_specinfo
decl_stmt|;
comment|/* device (VCHR, VBLK) */
name|struct
name|fifoinfo
modifier|*
name|vu_fifoinfo
decl_stmt|;
comment|/* fifo (VFIFO) */
block|}
name|v_un
union|;
name|enum
name|vtagtype
name|v_tag
decl_stmt|;
comment|/* type of underlying data */
name|char
name|v_data
index|[
name|VN_MAXPRIVATE
index|]
decl_stmt|;
comment|/* private data for fs */
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
name|v_text
value|v_un.vu_text
end_define

begin_define
define|#
directive|define
name|v_specinfo
value|v_un.vu_specinfo
end_define

begin_define
define|#
directive|define
name|v_fifoinfo
value|v_un.vu_fifoinfo
end_define

begin_comment
comment|/*  * vnode flags.  */
end_comment

begin_define
define|#
directive|define
name|VROOT
value|0x0001
end_define

begin_comment
comment|/* root of its file system */
end_comment

begin_define
define|#
directive|define
name|VTEXT
value|0x0002
end_define

begin_comment
comment|/* vnode is a pure text prototype */
end_comment

begin_define
define|#
directive|define
name|VSYSTEM
value|0x0004
end_define

begin_comment
comment|/* vnode being used by kernel */
end_comment

begin_define
define|#
directive|define
name|VEXLOCK
value|0x0010
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|VSHLOCK
value|0x0020
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|VLWAIT
value|0x0040
end_define

begin_comment
comment|/* proc is waiting on shared or excl. lock */
end_comment

begin_define
define|#
directive|define
name|VXLOCK
value|0x0100
end_define

begin_comment
comment|/* vnode is locked to change underlying type */
end_comment

begin_define
define|#
directive|define
name|VXWANT
value|0x0200
end_define

begin_comment
comment|/* process is waiting for vnode */
end_comment

begin_define
define|#
directive|define
name|VBWAIT
value|0x0400
end_define

begin_comment
comment|/* waiting for output to complete */
end_comment

begin_define
define|#
directive|define
name|VALIASED
value|0x0800
end_define

begin_comment
comment|/* vnode has an alias */
end_comment

begin_comment
comment|/*  * Operations on vnodes.  */
end_comment

begin_struct
struct|struct
name|vnodeops
block|{
name|int
function_decl|(
modifier|*
name|vn_lookup
function_decl|)
parameter_list|(
comment|/* ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_create
function_decl|)
parameter_list|(
comment|/* ndp, fflags, vap, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_mknod
function_decl|)
parameter_list|(
comment|/* ndp, vap, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_open
function_decl|)
parameter_list|(
comment|/* vp, fflags, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_close
function_decl|)
parameter_list|(
comment|/* vp, fflags, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_access
function_decl|)
parameter_list|(
comment|/* vp, fflags, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_getattr
function_decl|)
parameter_list|(
comment|/* vp, vap, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_setattr
function_decl|)
parameter_list|(
comment|/* vp, vap, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_read
function_decl|)
parameter_list|(
comment|/* vp, uiop, offp, ioflag, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_write
function_decl|)
parameter_list|(
comment|/* vp, uiop, offp, ioflag, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_ioctl
function_decl|)
parameter_list|(
comment|/* vp, com, data, fflag, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_select
function_decl|)
parameter_list|(
comment|/* vp, which, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_mmap
function_decl|)
parameter_list|(
comment|/* vp, ..., cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_fsync
function_decl|)
parameter_list|(
comment|/* vp, fflags, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_seek
function_decl|)
parameter_list|(
comment|/* vp, (old)offp, off, whence */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_remove
function_decl|)
parameter_list|(
comment|/* ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_link
function_decl|)
parameter_list|(
comment|/* vp, ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_rename
function_decl|)
parameter_list|(
comment|/* ndp, ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_mkdir
function_decl|)
parameter_list|(
comment|/* ndp, vap */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_rmdir
function_decl|)
parameter_list|(
comment|/* ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_symlink
function_decl|)
parameter_list|(
comment|/* ndp, vap, nm */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_readdir
function_decl|)
parameter_list|(
comment|/* vp, uiop, cred, eofflagp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_readlink
function_decl|)
parameter_list|(
comment|/* vp, uiop, cred */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_abortop
function_decl|)
parameter_list|(
comment|/* ndp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_inactive
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_reclaim
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_lock
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_unlock
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_bmap
function_decl|)
parameter_list|(
comment|/* vp, bn, vpp, bnp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_strategy
function_decl|)
parameter_list|(
comment|/* bp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_print
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vn_islocked
function_decl|)
parameter_list|(
comment|/* vp */
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Macros to call the vnode ops */
end_comment

begin_define
define|#
directive|define
name|VOP_LOOKUP
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(*((v)->v_op->vn_lookup))((v),(n))
end_define

begin_define
define|#
directive|define
name|VOP_CREATE
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_create))((n),(a))
end_define

begin_define
define|#
directive|define
name|VOP_MKNOD
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_mknod))((n),(a),(c))
end_define

begin_define
define|#
directive|define
name|VOP_OPEN
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_open))((v),(f),(c))
end_define

begin_define
define|#
directive|define
name|VOP_CLOSE
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_close))((v),(f),(c))
end_define

begin_define
define|#
directive|define
name|VOP_ACCESS
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_access))((v),(f),(c))
end_define

begin_define
define|#
directive|define
name|VOP_GETATTR
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_getattr))((v),(a),(c))
end_define

begin_define
define|#
directive|define
name|VOP_SETATTR
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_setattr))((v),(a),(c))
end_define

begin_define
define|#
directive|define
name|VOP_READ
parameter_list|(
name|v
parameter_list|,
name|u
parameter_list|,
name|i
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_read))((v),(u),(i),(c))
end_define

begin_define
define|#
directive|define
name|VOP_WRITE
parameter_list|(
name|v
parameter_list|,
name|u
parameter_list|,
name|i
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_write))((v),(u),(i),(c))
end_define

begin_define
define|#
directive|define
name|VOP_IOCTL
parameter_list|(
name|v
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_ioctl))((v),(o),(d),(f),(c))
end_define

begin_define
define|#
directive|define
name|VOP_SELECT
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_select))((v),(w),(f),(c))
end_define

begin_define
define|#
directive|define
name|VOP_MMAP
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_mmap))((v),(c))
end_define

begin_define
define|#
directive|define
name|VOP_FSYNC
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|,
name|w
parameter_list|)
value|(*((v)->v_op->vn_fsync))((v),(f),(c),(w))
end_define

begin_define
define|#
directive|define
name|VOP_SEEK
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|(*((v)->v_op->vn_seek))((v),(p),(o),(w))
end_define

begin_define
define|#
directive|define
name|VOP_REMOVE
parameter_list|(
name|n
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_remove))(n)
end_define

begin_define
define|#
directive|define
name|VOP_LINK
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_link))((v),(n))
end_define

begin_define
define|#
directive|define
name|VOP_RENAME
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(*((s)->ni_dvp->v_op->vn_rename))((s),(t))
end_define

begin_define
define|#
directive|define
name|VOP_MKDIR
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_mkdir))((n),(a))
end_define

begin_define
define|#
directive|define
name|VOP_RMDIR
parameter_list|(
name|n
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_rmdir))(n)
end_define

begin_define
define|#
directive|define
name|VOP_SYMLINK
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|m
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_symlink))((n),(a),(m))
end_define

begin_define
define|#
directive|define
name|VOP_READDIR
parameter_list|(
name|v
parameter_list|,
name|u
parameter_list|,
name|c
parameter_list|,
name|e
parameter_list|)
value|(*((v)->v_op->vn_readdir))((v),(u),(c),(e))
end_define

begin_define
define|#
directive|define
name|VOP_READLINK
parameter_list|(
name|v
parameter_list|,
name|u
parameter_list|,
name|c
parameter_list|)
value|(*((v)->v_op->vn_readlink))((v),(u),(c))
end_define

begin_define
define|#
directive|define
name|VOP_ABORTOP
parameter_list|(
name|n
parameter_list|)
value|(*((n)->ni_dvp->v_op->vn_abortop))(n)
end_define

begin_define
define|#
directive|define
name|VOP_INACTIVE
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_inactive))(v)
end_define

begin_define
define|#
directive|define
name|VOP_RECLAIM
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_reclaim))(v)
end_define

begin_define
define|#
directive|define
name|VOP_LOCK
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_lock))(v)
end_define

begin_define
define|#
directive|define
name|VOP_UNLOCK
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_unlock))(v)
end_define

begin_define
define|#
directive|define
name|VOP_BMAP
parameter_list|(
name|v
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
value|(*((v)->v_op->vn_bmap))((v),(s),(p),(n))
end_define

begin_define
define|#
directive|define
name|VOP_STRATEGY
parameter_list|(
name|b
parameter_list|)
value|(*((b)->b_vp->v_op->vn_strategy))(b)
end_define

begin_define
define|#
directive|define
name|VOP_PRINT
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_print))(v)
end_define

begin_define
define|#
directive|define
name|VOP_ISLOCKED
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vn_islocked))(v)
end_define

begin_comment
comment|/*  * flags for ioflag  */
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

begin_comment
comment|/*  * Vnode attributes.  A field value of VNOVAL  * represents a field whose value is unavailable  * (getattr) or which is not to be changed (setattr).  */
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
name|long
name|va_fsid
decl_stmt|;
comment|/* file system id (dev for now) */
name|long
name|va_fileid
decl_stmt|;
comment|/* file id */
name|u_quad
name|va_qsize
decl_stmt|;
comment|/* file size in bytes */
name|long
name|va_blocksize
decl_stmt|;
comment|/* blocksize preferred for i/o */
name|struct
name|timeval
name|va_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timeval
name|va_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timeval
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
name|dev_t
name|va_rdev
decl_stmt|;
comment|/* device the special file represents */
name|u_quad
name|va_qbytes
decl_stmt|;
comment|/* bytes of disk space held by file */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|va_size
value|va_qsize.val[0]
end_define

begin_define
define|#
directive|define
name|va_size_rsv
value|va_qsize.val[1]
end_define

begin_define
define|#
directive|define
name|va_bytes
value|va_qbytes.val[0]
end_define

begin_define
define|#
directive|define
name|va_bytes_rsv
value|va_qbytes.val[1]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_size
value|va_qsize.val[1]
end_define

begin_define
define|#
directive|define
name|va_size_rsv
value|va_qsize.val[0]
end_define

begin_define
define|#
directive|define
name|va_bytes
value|va_qbytes.val[1]
end_define

begin_define
define|#
directive|define
name|va_bytes_rsv
value|va_qbytes.val[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Modes. Some values same as Ixxx entries from inode.h for now  */
end_comment

begin_define
define|#
directive|define
name|VSUID
value|04000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|VSGID
value|02000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|VSVTX
value|01000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|VREAD
value|0400
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|0200
end_define

begin_define
define|#
directive|define
name|VEXEC
value|0100
end_define

begin_comment
comment|/*  * Token indicating no attribute value yet assigned  */
end_comment

begin_define
define|#
directive|define
name|VNOVAL
value|((unsigned)0xffffffff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * public vnode manipulation functions  */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_open
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* open vnode */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_rdwr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read or write vnode */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* close vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vattr_null
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set attributes to null */
end_comment

begin_function_decl
specifier|extern
name|int
name|getnewvnode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* allocate a new vnode */
end_comment

begin_function_decl
specifier|extern
name|int
name|bdevvp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* allocate a new special dev vnode */
end_comment

begin_function_decl
specifier|extern
name|struct
name|vnode
modifier|*
name|checkalias
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* check for special device aliases */
end_comment

begin_function_decl
specifier|extern
name|int
name|vcount
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* total references to a device */
end_comment

begin_function_decl
specifier|extern
name|int
name|vget
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get first reference to a vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vref
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* increase reference to a vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vput
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* unlock and release vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vrele
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* release vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vgone
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* completely recycle vnode */
end_comment

begin_function_decl
specifier|extern
name|void
name|vgoneall
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* recycle vnode and all its aliases */
end_comment

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
comment|/* vflush: force file closeure */
end_comment

begin_define
define|#
directive|define
name|DOCLOSE
value|0x0004
end_define

begin_comment
comment|/* vclean: close active files */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIAGNOSTIC
end_ifndef

begin_define
define|#
directive|define
name|VREF
parameter_list|(
name|vp
parameter_list|)
value|(vp)->v_usecount++
end_define

begin_comment
comment|/* increase reference to a vnode */
end_comment

begin_define
define|#
directive|define
name|VHOLD
parameter_list|(
name|vp
parameter_list|)
value|(vp)->v_holdcnt++
end_define

begin_comment
comment|/* increase buf or page ref to vnode */
end_comment

begin_define
define|#
directive|define
name|HOLDRELE
parameter_list|(
name|vp
parameter_list|)
value|(vp)->v_holdcnt--
end_define

begin_comment
comment|/* decrease buf or page ref to vnode */
end_comment

begin_define
define|#
directive|define
name|VATTR_NULL
parameter_list|(
name|vap
parameter_list|)
value|*(vap) = va_null
end_define

begin_comment
comment|/* initialize a vattr stucture */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DIAGNOSTIC */
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

begin_define
define|#
directive|define
name|VHOLD
parameter_list|(
name|vp
parameter_list|)
value|vhold(vp)
end_define

begin_define
define|#
directive|define
name|HOLDRELE
parameter_list|(
name|vp
parameter_list|)
value|holdrele(vp)
end_define

begin_define
define|#
directive|define
name|VATTR_NULL
parameter_list|(
name|vap
parameter_list|)
value|vattr_null(vap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULLVP
value|((struct vnode *)0)
end_define

begin_comment
comment|/*  * Global vnode data.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|rootdir
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
name|struct
name|vattr
name|va_null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* predefined null vattr structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

