begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Semihalf  * Copyright (c) 2008, 2009 Reinoud Zandijk  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * From: NetBSD: nilfs.h,v 1.1 2009/07/18 16:31:42 reinoud  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_NANDFS_NANDFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_NANDFS_NANDFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|"nandfs_fs.h"
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NANDFSTEMP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Debug categories */
end_comment

begin_define
define|#
directive|define
name|NANDFS_DEBUG_VOLUMES
value|0x000001
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_BLOCK
value|0x000004
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_LOCKING
value|0x000008
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_NODE
value|0x000010
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_LOOKUP
value|0x000020
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_READDIR
value|0x000040
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_TRANSLATE
value|0x000080
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_STRATEGY
value|0x000100
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_READ
value|0x000200
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_WRITE
value|0x000400
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_IFILE
value|0x000800
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_ATTR
value|0x001000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_EXTATTR
value|0x002000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_ALLOC
value|0x004000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_CPFILE
value|0x008000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_DIRHASH
value|0x010000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_NOTIMPL
value|0x020000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_SHEDULE
value|0x040000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_SEG
value|0x080000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_SYNC
value|0x100000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_PARANOIA
value|0x200000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_VNCALL
value|0x400000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_BUF
value|0x1000000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_BMAP
value|0x2000000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_DAT
value|0x4000000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_GENERIC
value|0x8000000
end_define

begin_define
define|#
directive|define
name|NANDFS_DEBUG_CLEAN
value|0x10000000
end_define

begin_decl_stmt
specifier|extern
name|int
name|nandfs_verbose
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|name
parameter_list|,
name|arg
parameter_list|)
value|{ \ 		if (nandfs_verbose& NANDFS_DEBUG_##name) {\ 			printf arg;\ 		};\ 	}
end_define

begin_define
define|#
directive|define
name|DPRINTFIF
parameter_list|(
name|name
parameter_list|,
name|cond
parameter_list|,
name|arg
parameter_list|)
value|{ \ 		if (nandfs_verbose& NANDFS_DEBUG_##name) { \ 			if (cond) printf arg;\ 		};\ 	}
end_define

begin_define
define|#
directive|define
name|VFSTONANDFS
parameter_list|(
name|mp
parameter_list|)
value|((struct nandfsmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTON
parameter_list|(
name|vp
parameter_list|)
value|((struct nandfs_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NTOV
parameter_list|(
name|xp
parameter_list|)
value|((xp)->nn_vnode)
end_define

begin_function_decl
name|int
name|nandfs_init
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nandfs_uninit
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|nandfs_vnodeops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vop_vector
name|nandfs_system_vnodeops
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|nandfs_node
struct_decl|;
end_struct_decl

begin_comment
comment|/* Structure and derivatives */
end_comment

begin_struct
struct|struct
name|nandfs_mdt
block|{
name|uint32_t
name|entries_per_block
decl_stmt|;
name|uint32_t
name|entries_per_group
decl_stmt|;
name|uint32_t
name|blocks_per_group
decl_stmt|;
name|uint32_t
name|groups_per_desc_block
decl_stmt|;
comment|/* desc is super group */
name|uint32_t
name|blocks_per_desc_block
decl_stmt|;
comment|/* desc is super group */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_segment
block|{
name|LIST_ENTRY
argument_list|(
argument|nandfs_segment
argument_list|)
name|seg_link
expr_stmt|;
name|struct
name|nandfs_device
modifier|*
name|fsdev
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|buf
argument_list|)
name|segsum
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|buf
argument_list|)
name|data
expr_stmt|;
name|uint64_t
name|seg_num
decl_stmt|;
name|uint64_t
name|seg_next
decl_stmt|;
name|uint64_t
name|start_block
decl_stmt|;
name|uint32_t
name|num_blocks
decl_stmt|;
name|uint32_t
name|nblocks
decl_stmt|;
name|uint32_t
name|nbinfos
decl_stmt|;
name|uint32_t
name|segsum_blocks
decl_stmt|;
name|uint32_t
name|segsum_bytes
decl_stmt|;
name|uint32_t
name|bytes_left
decl_stmt|;
name|char
modifier|*
name|current_off
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_seginfo
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nandfs_segment
argument_list|)
name|seg_list
expr_stmt|;
name|struct
name|nandfs_segment
modifier|*
name|curseg
decl_stmt|;
name|struct
name|nandfs_device
modifier|*
name|fsdev
decl_stmt|;
name|uint32_t
name|blocks
decl_stmt|;
name|uint8_t
name|reiterate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NANDFS_FSSTOR_FAILED
value|1
end_define

begin_struct
struct|struct
name|nandfs_fsarea
block|{
name|int
name|offset
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|last_used
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nandfs_cleaner_enable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nandfs_cleaner_interval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nandfs_cleaner_segments
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|nandfs_device
block|{
name|struct
name|vnode
modifier|*
name|nd_devvp
decl_stmt|;
name|struct
name|g_consumer
modifier|*
name|nd_gconsumer
decl_stmt|;
name|struct
name|thread
modifier|*
name|nd_syncer
decl_stmt|;
name|struct
name|thread
modifier|*
name|nd_cleaner
decl_stmt|;
name|int
name|nd_syncer_exit
decl_stmt|;
name|int
name|nd_cleaner_exit
decl_stmt|;
name|struct
name|nandfs_fsarea
name|nd_fsarea
index|[
name|NANDFS_NFSAREAS
index|]
decl_stmt|;
name|int
name|nd_last_fsarea
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument|nandfs_mnts
argument_list|,
argument|nandfsmount
argument_list|)
name|nd_mounts
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|nandfs_device
argument_list|)
name|nd_next_device
expr_stmt|;
comment|/* FS structures */
name|struct
name|nandfs_fsdata
name|nd_fsdata
decl_stmt|;
name|struct
name|nandfs_super_block
name|nd_super
decl_stmt|;
name|struct
name|nandfs_segment_summary
name|nd_last_segsum
decl_stmt|;
name|struct
name|nandfs_super_root
name|nd_super_root
decl_stmt|;
name|struct
name|nandfs_node
modifier|*
name|nd_dat_node
decl_stmt|;
name|struct
name|nandfs_node
modifier|*
name|nd_cp_node
decl_stmt|;
name|struct
name|nandfs_node
modifier|*
name|nd_su_node
decl_stmt|;
name|struct
name|nandfs_node
modifier|*
name|nd_gc_node
decl_stmt|;
name|struct
name|nandfs_mdt
name|nd_dat_mdt
decl_stmt|;
name|struct
name|nandfs_mdt
name|nd_ifile_mdt
decl_stmt|;
name|struct
name|timespec
name|nd_ts
decl_stmt|;
comment|/* Synchronization */
name|struct
name|mtx
name|nd_mutex
decl_stmt|;
name|struct
name|mtx
name|nd_sync_mtx
decl_stmt|;
name|struct
name|cv
name|nd_sync_cv
decl_stmt|;
name|struct
name|mtx
name|nd_clean_mtx
decl_stmt|;
name|struct
name|cv
name|nd_clean_cv
decl_stmt|;
name|struct
name|lock
name|nd_seg_const
decl_stmt|;
name|struct
name|nandfs_seginfo
modifier|*
name|nd_seginfo
decl_stmt|;
comment|/* FS geometry */
name|uint64_t
name|nd_devsize
decl_stmt|;
name|uint64_t
name|nd_maxfilesize
decl_stmt|;
name|uint32_t
name|nd_blocksize
decl_stmt|;
name|uint32_t
name|nd_erasesize
decl_stmt|;
name|uint32_t
name|nd_devblocksize
decl_stmt|;
name|uint32_t
name|nd_segs_reserved
decl_stmt|;
comment|/* Segment usage */
name|uint64_t
name|nd_clean_segs
decl_stmt|;
name|uint64_t
modifier|*
name|nd_free_base
decl_stmt|;
name|uint64_t
name|nd_free_count
decl_stmt|;
name|uint64_t
name|nd_dirty_bufs
decl_stmt|;
comment|/* Running values */
name|uint64_t
name|nd_seg_sequence
decl_stmt|;
name|uint64_t
name|nd_seg_num
decl_stmt|;
name|uint64_t
name|nd_next_seg_num
decl_stmt|;
name|uint64_t
name|nd_last_pseg
decl_stmt|;
name|uint64_t
name|nd_last_cno
decl_stmt|;
name|uint64_t
name|nd_last_ino
decl_stmt|;
name|uint64_t
name|nd_fakevblk
decl_stmt|;
name|int
name|nd_mount_state
decl_stmt|;
name|int
name|nd_refcnt
decl_stmt|;
name|int
name|nd_syncing
decl_stmt|;
name|int
name|nd_cleaning
decl_stmt|;
block|}
struct|;
end_struct

begin_extern
extern|extern SLIST_HEAD(_nandfs_devices
operator|,
extern|nandfs_device
end_extern

begin_expr_stmt
unit|)
name|nandfs_devices
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NANDFS_FORCE_SYNCER
value|0x1
end_define

begin_define
define|#
directive|define
name|NANDFS_UMOUNT
value|0x2
end_define

begin_define
define|#
directive|define
name|SYNCER_UMOUNT
value|0x0
end_define

begin_define
define|#
directive|define
name|SYNCER_VFS_SYNC
value|0x1
end_define

begin_define
define|#
directive|define
name|SYNCER_BDFLUSH
value|0x2
end_define

begin_define
define|#
directive|define
name|SYNCER_FFORCE
value|0x3
end_define

begin_define
define|#
directive|define
name|SYNCER_FSYNC
value|0x4
end_define

begin_define
define|#
directive|define
name|SYNCER_ROUPD
value|0x5
end_define

begin_function
specifier|static
name|__inline
name|int
name|nandfs_writelockflags
parameter_list|(
name|struct
name|nandfs_device
modifier|*
name|fsdev
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|error
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|lockstatus
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_seg_const
argument_list|)
operator|!=
name|LK_EXCLUSIVE
condition|)
name|error
operator|=
name|lockmgr
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_seg_const
argument_list|,
name|flags
operator||
name|LK_SHARED
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nandfs_writeunlock
parameter_list|(
name|struct
name|nandfs_device
modifier|*
name|fsdev
parameter_list|)
block|{
if|if
condition|(
name|lockstatus
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_seg_const
argument_list|)
operator|!=
name|LK_EXCLUSIVE
condition|)
name|lockmgr
argument_list|(
operator|&
operator|(
name|fsdev
operator|)
operator|->
name|nd_seg_const
argument_list|,
name|LK_RELEASE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|NANDFS_WRITELOCKFLAGS
parameter_list|(
name|fsdev
parameter_list|,
name|flags
parameter_list|)
value|nandfs_writelockflags(fsdev, flags)
end_define

begin_define
define|#
directive|define
name|NANDFS_WRITELOCK
parameter_list|(
name|fsdev
parameter_list|)
value|NANDFS_WRITELOCKFLAGS(fsdev, 0)
end_define

begin_define
define|#
directive|define
name|NANDFS_WRITEUNLOCK
parameter_list|(
name|fsdev
parameter_list|)
value|nandfs_writeunlock(fsdev)
end_define

begin_define
define|#
directive|define
name|NANDFS_WRITEASSERT
parameter_list|(
name|fsdev
parameter_list|)
value|lockmgr_assert(&(fsdev)->nd_seg_const, KA_LOCKED)
end_define

begin_comment
comment|/* Specific mountpoint; head or a checkpoint/snapshot */
end_comment

begin_struct
struct|struct
name|nandfsmount
block|{
name|STAILQ_ENTRY
argument_list|(
argument|nandfsmount
argument_list|)
name|nm_next_mount
expr_stmt|;
name|struct
name|mount
modifier|*
name|nm_vfs_mountp
decl_stmt|;
name|struct
name|nandfs_device
modifier|*
name|nm_nandfsdev
decl_stmt|;
name|struct
name|nandfs_args
name|nm_mount_args
decl_stmt|;
name|struct
name|nandfs_node
modifier|*
name|nm_ifile_node
decl_stmt|;
name|uint8_t
name|nm_flags
decl_stmt|;
name|int8_t
name|nm_ronly
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nandfs_node
block|{
name|struct
name|vnode
modifier|*
name|nn_vnode
decl_stmt|;
name|struct
name|nandfsmount
modifier|*
name|nn_nmp
decl_stmt|;
name|struct
name|nandfs_device
modifier|*
name|nn_nandfsdev
decl_stmt|;
name|struct
name|lockf
modifier|*
name|nn_lockf
decl_stmt|;
name|uint64_t
name|nn_ino
decl_stmt|;
name|struct
name|nandfs_inode
name|nn_inode
decl_stmt|;
name|uint64_t
name|nn_diroff
decl_stmt|;
name|uint32_t
name|nn_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IN_ACCESS
value|0x0001
end_define

begin_comment
comment|/* Inode access time update request  */
end_comment

begin_define
define|#
directive|define
name|IN_CHANGE
value|0x0002
end_define

begin_comment
comment|/* Inode change time update request  */
end_comment

begin_define
define|#
directive|define
name|IN_UPDATE
value|0x0004
end_define

begin_comment
comment|/* Inode was written to; update mtime*/
end_comment

begin_define
define|#
directive|define
name|IN_MODIFIED
value|0x0008
end_define

begin_comment
comment|/* node has been modified */
end_comment

begin_define
define|#
directive|define
name|IN_RENAME
value|0x0010
end_define

begin_comment
comment|/* node is being renamed. */
end_comment

begin_comment
comment|/* File permissions. */
end_comment

begin_define
define|#
directive|define
name|IEXEC
value|0000100
end_define

begin_comment
comment|/* Executable. */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0000200
end_define

begin_comment
comment|/* Writeable. */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0000400
end_define

begin_comment
comment|/* Readable. */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|0001000
end_define

begin_comment
comment|/* Sticky bit. */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|0002000
end_define

begin_comment
comment|/* Set-gid. */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|0004000
end_define

begin_comment
comment|/* Set-uid. */
end_comment

begin_define
define|#
directive|define
name|PRINT_NODE_FLAGS
define|\
value|"\10\1IN_ACCESS\2IN_CHANGE\3IN_UPDATE\4IN_MODIFIED\5IN_RENAME"
end_define

begin_define
define|#
directive|define
name|NANDFS_GATHER
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |= B_FS_FLAG1)
end_define

begin_define
define|#
directive|define
name|NANDFS_UNGATHER
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~B_FS_FLAG1)
end_define

begin_define
define|#
directive|define
name|NANDFS_ISGATHERED
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags& B_FS_FLAG1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_NANDFS_NANDFS_H_ */
end_comment

end_unit

