begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vnode.h	7.54 (Berkeley) %G%  */
end_comment

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
name|VT_MFS
block|,
name|VT_LFS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Each underlying filesystem allocates its own private area and hangs  * it from v_data.  If non-null, this area is free in getnewvnode().  */
end_comment

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
name|daddr_t
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
name|int
function_decl|(
modifier|*
modifier|*
name|v_op
function_decl|)
parameter_list|()
function_decl|;
comment|/* vnode operations vector */
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
name|struct
name|nqlease
modifier|*
name|v_lease
decl_stmt|;
comment|/* Soft reference to lease */
name|long
name|v_spare
index|[
literal|13
index|]
decl_stmt|;
comment|/* round to 128 bytes */
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
comment|/*  * Vnode flags.  */
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
name|long
name|va_fsid
decl_stmt|;
comment|/* file system id (dev for now) */
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for ioflag.  */
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
comment|/*  *  Modes.  Some values same as Ixxx entries from inode.h for now.  */
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
value|00400
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|VWRITE
value|00200
end_define

begin_define
define|#
directive|define
name|VEXEC
value|00100
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
value|(iftovt_tab[((mode)& IFMT)>> 12])
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

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

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
name|VREF
parameter_list|(
name|vp
parameter_list|)
value|vref(vp)
end_define

begin_decl_stmt
name|void
name|holdrele
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
name|vattr_null
name|__P
argument_list|(
operator|(
expr|struct
name|vattr
operator|*
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
name|void
name|vref
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

begin_else
else|#
directive|else
end_else

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
name|VREF
parameter_list|(
name|vp
parameter_list|)
value|(vp)->v_usecount++
end_define

begin_comment
comment|/* increase reference */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_decl_stmt
name|void
name|lease_check
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
operator|,
expr|struct
name|ucred
operator|*
name|ucred
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lease_updatetime
name|__P
argument_list|(
operator|(
name|int
name|deltat
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LEASE_CHECK
parameter_list|(
name|vp
parameter_list|,
name|p
parameter_list|,
name|cred
parameter_list|,
name|flag
parameter_list|)
value|lease_check((vp), (p), (cred), (flag))
end_define

begin_define
define|#
directive|define
name|LEASE_UPDATETIME
parameter_list|(
name|dt
parameter_list|)
value|lease_updatetime(dt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LEASE_CHECK
parameter_list|(
name|vp
parameter_list|,
name|p
parameter_list|,
name|cred
parameter_list|,
name|flag
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LEASE_UPDATETIME
parameter_list|(
name|dt
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mods for exensibility.  */
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
comment|/* Low order 16 flag bits are reserved for map flags for vp arguments. */
end_comment

begin_define
define|#
directive|define
name|VDESC_NOMAP_VPP
value|0x0100
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
comment|/* offset in vector--first for speed */
name|char
modifier|*
name|vdesc_name
decl_stmt|;
comment|/* a readable name for debugging */
name|int
name|vdesc_flags
decl_stmt|;
comment|/* VDESC_* flags */
comment|/* 	 * These ops are used by bypass routines to map and locate arguments. 	 * Creds and procs are not needed in bypass routines, but sometimes 	 * they are useful to (for example) transport layers. 	 */
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
name|vdesc_proc_offset
decl_stmt|;
comment|/* proc location, if any */
comment|/* 	 * Finally, we've got a list of private data (about each operation) 	 * for each transport layer.  (Support to manage this list is not 	 * yet part of BSD.) 	 */
name|caddr_t
modifier|*
name|vdesc_transports
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/*  * This macro is very helpful in defining those offsets in the vdesc struct.  *  * This is stolen from X11R4.  I ingored all the fancy stuff for  * Crays, so if you decide to port this to such a serious machine,  * you might want to consult Intrisics.h's XtOffset{,Of,To}.  */
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
name|int
function_decl|(
modifier|*
name|opve_impl
function_decl|)
parameter_list|()
function_decl|;
comment|/* code implementing this operation */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vnodeopv_desc
block|{
comment|/* ptr to the ptr to the vector where op should go */
name|int
function_decl|(
modifier|*
modifier|*
modifier|*
name|opv_desc_vector_p
function_decl|)
parameter_list|()
function_decl|;
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
comment|/*  * A default routine which just returns an error.  */
end_comment

begin_decl_stmt
name|int
name|vn_default_error
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/*  * Finally, include the default set of vnode operations.  */
end_comment

begin_include
include|#
directive|include
file|<sys/vnode_if.h>
end_include

begin_comment
comment|/*  * Public vnode manipulation functions.  */
end_comment

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
name|proc
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

begin_struct_decl
struct_decl|struct
name|vop_bwrite_args
struct_decl|;
end_struct_decl

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
name|int
argument_list|(
operator|*
operator|*
name|vops
argument_list|)
argument_list|()
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

begin_decl_stmt
name|int
name|vn_bwrite
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bwrite_args
operator|*
name|ap
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
name|dev_t
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

end_unit

