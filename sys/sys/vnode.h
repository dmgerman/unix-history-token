begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vnode.h	7.39 (Berkeley) 6/27/91  *	$Id: vnode.h,v 1.9 1994/01/14 16:25:49 davidg Exp $  */
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
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|VPROC
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
block|,
name|VT_PCFS
block|,
name|VT_ISOFS
block|,
name|VT_PROCFS
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
value|188
end_define

begin_struct
struct|struct
name|vnode
block|{
name|u_long
name|v_flag
decl_stmt|;
comment|/* vnode flags (see below) */
name|short
name|v_usecount
decl_stmt|;
comment|/* reference count of users */
name|short
name|v_writecount
decl_stmt|;
comment|/* reference count of writers */
name|long
name|v_holdcnt
decl_stmt|;
comment|/* page& buffer references */
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
name|caddr_t
name|vu_vmdata
decl_stmt|;
comment|/* private data for vm (VREG) */
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
name|v_vmdata
value|v_un.vu_vmdata
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
union|union
block|{
name|u_quad_t
name|v
decl_stmt|;
name|u_long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|va_qsize
union|;
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
union|union
block|{
name|u_quad_t
name|v
decl_stmt|;
name|u_long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|va_qbytes
union|;
comment|/* bytes of disk space held by file */
name|u_int
name|va_vaflags
decl_stmt|;
comment|/* operations flags, see below */
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

begin_comment
comment|/*  * Operations on vnodes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|flock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vnodeops
block|{
name|int
argument_list|(
argument|*vop_lookup
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
argument|*vop_create
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
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
argument|*vop_mknod
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
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
argument|*vop_open
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
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
argument|*vop_close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflag
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
argument|*vop_access
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
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
argument|*vop_getattr
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
name|vattr
operator|*
name|vap
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
argument|*vop_setattr
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
name|vattr
operator|*
name|vap
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
argument|*vop_read
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
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_write
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
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_ioctl
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|command
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
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
argument|*vop_select
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|which
operator|,
name|int
name|fflags
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
argument|*vop_mmap
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
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
argument|*vop_fsync
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
name|waitfor
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
argument|*vop_seek
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|off_t
name|oldoff
operator|,
name|off_t
name|newoff
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_remove
argument_list|)
name|__P
argument_list|(
operator|(
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
argument|*vop_link
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
argument|*vop_rename
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|fndp
operator|,
expr|struct
name|nameidata
operator|*
name|tdnp
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
argument|*vop_mkdir
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
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
argument|*vop_rmdir
argument_list|)
name|__P
argument_list|(
operator|(
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
argument|*vop_symlink
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
name|char
operator|*
name|target
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
argument|*vop_readdir
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
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|eofflagp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_readlink
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
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_abortop
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_inactive
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
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_reclaim
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_lock
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_unlock
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_bmap
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|daddr_t
name|bn
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_strategy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*vop_print
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_islocked
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*vop_advlock
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|id
operator|,
name|int
name|op
operator|,
expr|struct
name|flock
operator|*
name|fl
operator|,
name|int
name|flags
operator|)
argument_list|)
expr_stmt|;
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_lookup))(v,n,p)
end_define

begin_define
define|#
directive|define
name|VOP_CREATE
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_create))(n,a,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_mknod))(n,a,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_open))(v,f,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_close))(v,f,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_access))(v,f,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_getattr))(v,a,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_setattr))(v,a,c,p)
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
value|(*((v)->v_op->vop_read))(v,u,i,c)
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
value|(*((v)->v_op->vop_write))(v,u,i,c)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_ioctl))(v,o,d,f,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_select))(v,w,f,c,p)
end_define

begin_define
define|#
directive|define
name|VOP_MMAP
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_mmap))(v,c,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_fsync))(v,f,c,w,p)
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
value|(*((v)->v_op->vop_seek))(v,p,o,w)
end_define

begin_define
define|#
directive|define
name|VOP_REMOVE
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_remove))(n,p)
end_define

begin_define
define|#
directive|define
name|VOP_LINK
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_link))(v,n,p)
end_define

begin_define
define|#
directive|define
name|VOP_RENAME
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|)
value|(*((s)->ni_dvp->v_op->vop_rename))(s,t,p)
end_define

begin_define
define|#
directive|define
name|VOP_MKDIR
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_mkdir))(n,a,p)
end_define

begin_define
define|#
directive|define
name|VOP_RMDIR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_rmdir))(n,p)
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
parameter_list|,
name|p
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_symlink))(n,a,m,p)
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
value|(*((v)->v_op->vop_readdir))(v,u,c,e)
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
value|(*((v)->v_op->vop_readlink))(v,u,c)
end_define

begin_define
define|#
directive|define
name|VOP_ABORTOP
parameter_list|(
name|n
parameter_list|)
value|(*((n)->ni_dvp->v_op->vop_abortop))(n)
end_define

begin_define
define|#
directive|define
name|VOP_INACTIVE
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(*((v)->v_op->vop_inactive))(v,p)
end_define

begin_define
define|#
directive|define
name|VOP_RECLAIM
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vop_reclaim))(v)
end_define

begin_define
define|#
directive|define
name|VOP_LOCK
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vop_lock))(v)
end_define

begin_define
define|#
directive|define
name|VOP_UNLOCK
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vop_unlock))(v)
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
value|(*((v)->v_op->vop_bmap))(v,s,p,n)
end_define

begin_define
define|#
directive|define
name|VOP_STRATEGY
parameter_list|(
name|b
parameter_list|)
value|(*((b)->b_vp->v_op->vop_strategy))(b)
end_define

begin_define
define|#
directive|define
name|VOP_PRINT
parameter_list|(
name|v
parameter_list|)
value|(*((v)->v_op->vop_print))(v)
end_define

begin_define
define|#
directive|define
name|VOP_ISLOCKED
parameter_list|(
name|v
parameter_list|)
value|(((v)->v_flag& VXLOCK) || \ 				(*((v)->v_op->vop_islocked))(v))
end_define

begin_define
define|#
directive|define
name|VOP_ADVLOCK
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
value|(*((v)->v_op->vop_advlock))(v,p,o,l,f)
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

begin_define
define|#
directive|define
name|IO_PAGER
value|0x20
end_define

begin_comment
comment|/* I/O requested from pager */
end_comment

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
value|(~0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * public vnode manipulation functions  */
end_comment

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
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|fmode
operator|,
name|int
name|cmode
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
name|proc
operator|*
name|p
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
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_read
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
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
name|int
name|vn_write
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
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
name|int
name|vn_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|com
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_select
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|which
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vn_closefile
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|vn_stat
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|stat
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
name|vn_writechk
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
expr|struct
name|vnodeops
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
name|bdevvp
name|__P
argument_list|(
operator|(
name|int
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
comment|/* check for special device aliases */
end_comment

begin_comment
comment|/* XXX nvp_rdev should be type dev_t, not int */
end_comment

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|checkalias
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|nvp_rdev
operator|,
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

begin_comment
comment|/* total references to a device */
end_comment

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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get first reference to a vnode */
end_comment

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

begin_comment
comment|/* increase reference to a vnode */
end_comment

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

begin_comment
comment|/* unlock and release vnode */
end_comment

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

begin_comment
comment|/* release vnode */
end_comment

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

begin_comment
comment|/* completely recycle vnode */
end_comment

begin_decl_stmt
name|void
name|vgoneall
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

begin_comment
comment|/* recycle vnode and all its aliases */
end_comment

begin_function_decl
specifier|extern
name|void
name|vflushbuf
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vinvalbuf
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bdevvp
parameter_list|(
name|int
comment|/*dev_t*/
name|dev
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|vnode
modifier|*
name|checkalias
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
comment|/*dev_t*/
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|void
name|holdrele
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vclean
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vfinddev
parameter_list|(
name|int
comment|/*dev_t*/
parameter_list|,
name|enum
name|vtype
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vprint
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kinfo_vnode
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vnode_pager_uncache
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vnode_pager_setsize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cache_purge
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cache_purgevfs
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* increase reference */
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
comment|/* increase buf or page ref */
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
comment|/* decrease buf or page ref */
end_comment

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
name|rootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root (i.e. "/") vnode */
end_comment

begin_decl_stmt
specifier|extern
name|long
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_VNODE_H_ */
end_comment

end_unit

