begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)vfs.h 2.7 85/10/31 SMI	*/
end_comment

begin_typedef
typedef|typedef
name|long
name|fsid_t
index|[
literal|2
index|]
typedef|;
end_typedef

begin_comment
comment|/* file system id type */
end_comment

begin_comment
comment|/*  * Structure per mounted file system.  * Each mounted file system has an array of  * operations and an instance record.  * The file systems are put on a doubly linked list.  */
end_comment

begin_struct
struct|struct
name|vfs
comment|/* why not mount? */
block|{
name|struct
name|vfs
modifier|*
name|vfs_next
decl_stmt|;
comment|/* next vfs in vfs list */
operator|*
operator|*
expr|struct
name|vfs
operator|*
name|vfs_prev
expr_stmt|;
comment|/* prev vfs in vfs list */
name|struct
name|vfsops
modifier|*
name|vfs_op
decl_stmt|;
comment|/* operations on vfs */
name|struct
name|vnode
modifier|*
name|vfs_vnodecovered
decl_stmt|;
comment|/* vnode we mounted on */
name|int
name|vfs_flag
decl_stmt|;
comment|/* flags */
operator|*
name|int
name|vfs_bsize
expr_stmt|;
comment|/* basic block size */
operator|*
operator|*
name|int
name|vfs_tsize
expr_stmt|;
comment|/* optimal transfer size */
operator|*
name|uid_t
name|vfs_exroot
expr_stmt|;
comment|/* exported fs uid 0 mapping */
name|short
name|vfs_exflags
decl_stmt|;
comment|/* exported fs flags */
operator|*
operator|*
name|fsid_t
name|vfs_fsid
expr_stmt|;
comment|/* identifier */
name|caddr_t
name|vfs_data
decl_stmt|;
comment|/* private data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * vfs flags.  * VFS_MLOCK lock the vfs so that name lookup cannot proceed past the vfs.  * This keeps the subtree stable during mounts and unmounts.  */
end_comment

begin_define
define|#
directive|define
name|VFS_RDONLY
value|0x01
end_define

begin_comment
comment|/* read only vfs */
end_comment

begin_define
define|#
directive|define
name|VFS_NOEXEC
value|*	0x02
end_define

begin_comment
comment|/* can't exec from filesystem */
end_comment

begin_define
define|#
directive|define
name|VFS_MLOCK
value|0x04
end_define

begin_comment
comment|/* lock vfs so that subtree is stable */
end_comment

begin_define
define|#
directive|define
name|VFS_MWAIT
value|0x08
end_define

begin_comment
comment|/* someone is waiting for lock */
end_comment

begin_define
define|#
directive|define
name|VFS_NOSUID
value|0x10
end_define

begin_comment
comment|/* don't honor setuid bits on vfs */
end_comment

begin_define
define|#
directive|define
name|VFS_EXPORTED
value|0x20
end_define

begin_comment
comment|/* file system is exported (NFS) */
end_comment

begin_comment
comment|/*  * exported vfs flags.  */
end_comment

begin_define
define|#
directive|define
name|EX_RDONLY
value|0x01
end_define

begin_comment
comment|/* exported read only */
end_comment

begin_comment
comment|/*  * Operations supported on virtual file system.  */
end_comment

begin_struct
struct|struct
name|vfsops
block|{
operator|*
name|int
argument_list|(
operator|*
name|vfs_mount
argument_list|)
argument_list|(
comment|/* vfs, path, data, datalen */
argument_list|)
expr_stmt|;
operator|*
name|int
argument_list|(
operator|*
name|vfs_unmount
argument_list|)
argument_list|(
comment|/* vfs, forcibly */
argument_list|)
expr_stmt|;
operator|*
operator|*
name|int
argument_list|(
operator|*
name|vfs_mountroot
argument_list|)
argument_list|()
expr_stmt|;
name|int
function_decl|(
modifier|*
name|vfs_root
function_decl|)
parameter_list|(
comment|/* vfs, vpp */
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|vfs_statfs
function_decl|)
parameter_list|(
comment|/* vfs, sbp */
parameter_list|)
function_decl|;
operator|*
name|int
argument_list|(
operator|*
name|vfs_sync
argument_list|)
argument_list|(
comment|/* vfs, waitfor */
argument_list|)
expr_stmt|;
operator|*
operator|*
expr|struct
name|vnode
operator|*
operator|(
operator|*
name|vfs_fhtovp
operator|)
operator|(
comment|/* vfs, fh */
block|}
struct|;
end_struct

begin_comment
comment|/*  * file system statistics  */
end_comment

begin_struct
struct|struct
name|statfs
block|{
operator|*
name|short
name|f_type
expr_stmt|;
comment|/* type of filesystem */
operator|*
name|short
name|f_flags
expr_stmt|;
comment|/* copy of vfs (mount) flags */
name|long
name|f_bsize
decl_stmt|;
comment|/* fundamental file system block size */
operator|*
name|long
name|f_tsize
expr_stmt|;
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
literal|7
index|]
decl_stmt|;
comment|/* spare for later */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * public operations  */
end_comment

begin_function_decl
specifier|extern
name|void
name|vfs_mountroot
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* mount the root */
end_comment

begin_function_decl
specifier|extern
name|int
name|vfs_add
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add a new vfs to mounted vfs list */
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

begin_define
define|#
directive|define
name|VFS_INIT
parameter_list|(
name|VFSP
parameter_list|,
name|OP
parameter_list|,
name|DATA
parameter_list|)
value|{ \ 	(VFSP)->vfs_next = (struct vfs *)0; \ 	(VFSP)->vfs_op = (OP); \ 	(VFSP)->vfs_flag = 0; \ 	(VFSP)->vfs_exflags = 0; \ 	(VFSP)->vfs_data = (DATA); \ }
end_define

begin_comment
comment|/*  * globals  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfs
modifier|*
name|rootvfs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to root vfs structure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

