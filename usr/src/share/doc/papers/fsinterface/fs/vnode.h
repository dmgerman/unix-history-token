begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)vnode.h 2.10 85/03/27 SMI	*/
end_comment

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
block|}
enum|;
end_enum

begin_struct
struct|struct
name|vnode
block|{
name|u_short
name|v_flag
decl_stmt|;
comment|/* vnode flags (see below) */
name|u_short
name|v_count
decl_stmt|;
comment|/* reference count */
name|u_short
name|v_shlockc
decl_stmt|;
comment|/* count of shared locks */
name|u_short
name|v_exlockc
decl_stmt|;
comment|/* count of exclusive locks */
name|struct
name|vfs
modifier|*
name|v_vfsmountedhere
decl_stmt|;
comment|/* ptr to vfs mounted here */
name|struct
name|vfs
modifier|*
name|v_vfsp
decl_stmt|;
comment|/* ptr to vfs we are in */
name|struct
name|vnodeops
modifier|*
name|v_op
decl_stmt|;
comment|/* vnode operations */
operator|*
operator|*
expr|struct
name|text
operator|*
name|v_text
expr_stmt|;
comment|/* text/mapped region */
name|enum
name|vtype
name|v_type
decl_stmt|;
comment|/* vnode type */
name|caddr_t
name|v_data
decl_stmt|;
comment|/* private data for fs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * vnode flags.  */
end_comment

begin_define
define|#
directive|define
name|VROOT
value|0x01
end_define

begin_comment
comment|/* root of its file system */
end_comment

begin_define
define|#
directive|define
name|VTEXT
value|0x02
end_define

begin_comment
comment|/* vnode is a pure text prototype */
end_comment

begin_define
define|#
directive|define
name|VEXLOCK
value|0x10
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|VSHLOCK
value|0x20
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|VLWAIT
value|0x40
end_define

begin_comment
comment|/* proc is waiting on shared or excl. lock */
end_comment

begin_comment
comment|/*  * Operations on vnodes.  */
end_comment

begin_struct
struct|struct
name|vnodeops
block|{
operator|*
name|int
argument_list|(
operator|*
name|vn_lookup
argument_list|)
argument_list|(
comment|/* ndp */
argument_list|)
expr_stmt|;
operator|*
name|int
argument_list|(
operator|*
name|vn_create
argument_list|)
argument_list|(
comment|/* ndp, vap, fflags */
argument_list|)
expr_stmt|;
operator|*
name|int
argument_list|(
operator|*
name|vn_open
argument_list|)
argument_list|(
comment|/* vp, fflags, cred */
argument_list|)
expr_stmt|;
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
comment|/* vp, mode, cred */
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
operator|*
operator|*
name|int
argument_list|(
operator|*
name|vn_read
argument_list|)
argument_list|(
comment|/* vp, uiop, ioflag, cred */
argument_list|)
expr_stmt|;
operator|*
operator|*
name|int
argument_list|(
operator|*
name|vn_write
argument_list|)
argument_list|(
comment|/* vp, uiop, ioflag, cred */
argument_list|)
expr_stmt|;
operator|*
name|int
argument_list|(
operator|*
name|vn_ioctl
argument_list|)
argument_list|(
comment|/* vp, com, data, fflag, cred */
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|*
name|vn_select
function_decl|)
parameter_list|(
comment|/* vp, which, cred */
parameter_list|)
function_decl|;
operator|*
operator|*
name|int
argument_list|(
operator|*
name|vn_mmap
argument_list|)
argument_list|(
comment|/* vp, ..., cred */
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|*
name|vn_fsync
function_decl|)
parameter_list|(
comment|/* vp, cred */
parameter_list|)
function_decl|;
operator|*
operator|*
name|int
argument_list|(
argument|*vn_seek
argument_list|)
operator|(
comment|/* vp, off, whence */
operator|*
name|int
argument_list|(
operator|*
name|vn_remove
argument_list|)
argument_list|(
comment|/* ndp */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_link
argument_list|)
argument_list|(
comment|/* vp, ndp */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_rename
argument_list|)
argument_list|(
comment|/* ndp, ndp */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_mkdir
argument_list|)
argument_list|(
comment|/* ndp, vap */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_rmdir
argument_list|)
argument_list|(
comment|/* ndp */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_symlink
argument_list|)
argument_list|(
comment|/* ndp, vap, nm */
argument_list|)
expr|;
name|int
argument_list|(
operator|*
name|vn_readdir
argument_list|)
argument_list|(
comment|/* vp, uiop, ioflag, cred */
argument_list|)
expr|;
name|int
argument_list|(
operator|*
name|vn_readlink
argument_list|)
argument_list|(
comment|/* vp, uiop, ioflag, cred */
argument_list|)
expr|;
operator|*
operator|*
name|int
argument_list|(
operator|*
name|vn_abortop
argument_list|)
argument_list|(
comment|/* ndp */
argument_list|)
expr|;
operator|*
name|int
argument_list|(
operator|*
name|vn_inactive
argument_list|)
argument_list|(
comment|/* vp */
argument_list|)
expr|;
operator|*
operator|*
name|int
argument_list|(
argument|*vn_vptofh
argument_list|)
operator|(
comment|/* vp, fhp */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags for ioflag  */
end_comment

begin_define
define|#
directive|define
name|IO_ATOMIC
value|0x01
end_define

begin_comment
comment|/* do io as atomic unit for VOP_RDWR */
end_comment

begin_define
define|#
directive|define
name|IO_UNIT
value|IO_ATOMIC
end_define

begin_comment
comment|/* compat */
end_comment

begin_define
define|#
directive|define
name|IO_APPEND
value|0x02
end_define

begin_comment
comment|/* append write for VOP_RDWR */
end_comment

begin_define
define|#
directive|define
name|IO_SYNC
value|0x04
end_define

begin_comment
comment|/* sync io for VOP_RDWR */
end_comment

begin_comment
comment|/*  * Vnode attributes.  A field value of -1  * represents a field whose value is unavailable  * (getattr) or which is not to be changed (setattr).  */
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
operator|*
name|uid_t
name|va_uid
expr_stmt|;
comment|/* owner user id */
operator|*
name|gid_t
name|va_gid
expr_stmt|;
comment|/* owner group id */
name|long
name|va_fsid
decl_stmt|;
comment|/* file system id (dev for now) */
operator|*
name|long
name|va_fileid
expr_stmt|;
comment|/* file id */
name|short
name|va_nlink
decl_stmt|;
comment|/* number of references to file */
name|u_long
name|va_size
decl_stmt|;
comment|/* file size in bytes (quad?) */
operator|*
name|u_long
name|va_size1
expr_stmt|;
comment|/* reserved if not quad */
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
name|dev_t
name|va_rdev
decl_stmt|;
comment|/* device the file represents */
name|u_long
name|va_blocks
decl_stmt|;
comment|/* bytes of disk space held by file */
operator|*
name|u_long
name|va_blocks1
expr_stmt|;
comment|/* reserved if va_blocks not a quad */
block|}
struct|;
end_struct

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
name|vn_create
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* creat/mkdir vnode */
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
name|vn_rele
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* release vnode */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_link
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* make hard link */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_rename
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rename (move) */
end_comment

begin_function_decl
specifier|extern
name|int
name|vn_remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove/rmdir */
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
name|getvnodefp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get fp from vnode fd */
end_comment

begin_define
define|#
directive|define
name|VN_HOLD
parameter_list|(
name|VP
parameter_list|)
value|{ \ 	(VP)->v_count++; \ }
end_define

begin_define
define|#
directive|define
name|VN_RELE
parameter_list|(
name|VP
parameter_list|)
value|{ \ 	vn_rele(VP); \ }
end_define

begin_define
define|#
directive|define
name|VN_INIT
parameter_list|(
name|VP
parameter_list|,
name|VFSP
parameter_list|,
name|TYPE
parameter_list|,
name|DEV
parameter_list|)
value|{ \ 	(VP)->v_flag = 0; \ 	(VP)->v_count = 1; \ 	(VP)->v_shlockc = (VP)->v_exlockc = 0; \ 	(VP)->v_vfsp = (VFSP); \ 	(VP)->v_type = (TYPE); \ 	(VP)->v_rdev = (DEV); \ }
end_define

begin_comment
comment|/*  * flags for vn_remove  */
end_comment

begin_enum
enum|enum
name|rm
block|{
name|FILE
block|,
name|DIRECTORY
block|}
enum|;
end_enum

begin_comment
comment|/* rmdir or rm (remove) */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

