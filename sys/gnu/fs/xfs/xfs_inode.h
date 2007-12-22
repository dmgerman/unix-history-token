begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_INODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_INODE_H__
end_define

begin_comment
comment|/*  * Fork identifiers.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DATA_FORK
value|0
end_define

begin_define
define|#
directive|define
name|XFS_ATTR_FORK
value|1
end_define

begin_comment
comment|/*  * The following xfs_ext_irec_t struct introduces a second (top) level  * to the in-core extent allocation scheme. These structs are allocated  * in a contiguous block, creating an indirection array where each entry  * (irec) contains a pointer to a buffer of in-core extent records which  * it manages. Each extent buffer is 4k in size, since 4k is the system  * page size on Linux i386 and systems with larger page sizes don't seem  * to gain much, if anything, by using their native page size as the  * extent buffer size. Also, using 4k extent buffers everywhere provides  * a consistent interface for CXFS across different platforms.  *  * There is currently no limit on the number of irec's (extent lists)  * allowed, so heavily fragmented files may require an indirection array  * which spans multiple system pages of memory. The number of extents  * which would require this amount of contiguous memory is very large  * and should not cause problems in the foreseeable future. However,  * if the memory needed for the contiguous array ever becomes a problem,  * it is possible that a third level of indirection may be required.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_ext_irec
block|{
name|xfs_bmbt_rec_t
modifier|*
name|er_extbuf
decl_stmt|;
comment|/* block of extent records */
name|xfs_extnum_t
name|er_extoff
decl_stmt|;
comment|/* extent offset in file */
name|xfs_extnum_t
name|er_extcount
decl_stmt|;
comment|/* number of extents in page/block */
block|}
name|xfs_ext_irec_t
typedef|;
end_typedef

begin_comment
comment|/*  * File incore extent information, present for each of data& attr forks.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IEXT_BUFSZ
value|4096
end_define

begin_define
define|#
directive|define
name|XFS_LINEAR_EXTS
value|(XFS_IEXT_BUFSZ / (uint)sizeof(xfs_bmbt_rec_t))
end_define

begin_define
define|#
directive|define
name|XFS_INLINE_EXTS
value|2
end_define

begin_define
define|#
directive|define
name|XFS_INLINE_DATA
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_ifork
block|{
name|int
name|if_bytes
decl_stmt|;
comment|/* bytes in if_u1 */
name|int
name|if_real_bytes
decl_stmt|;
comment|/* bytes allocated in if_u1 */
name|xfs_bmbt_block_t
modifier|*
name|if_broot
decl_stmt|;
comment|/* file's incore btree root */
name|short
name|if_broot_bytes
decl_stmt|;
comment|/* bytes allocated for root */
name|unsigned
name|char
name|if_flags
decl_stmt|;
comment|/* per-fork flags */
name|unsigned
name|char
name|if_ext_max
decl_stmt|;
comment|/* max # of extent records */
name|xfs_extnum_t
name|if_lastex
decl_stmt|;
comment|/* last if_extents used */
union|union
block|{
name|xfs_bmbt_rec_t
modifier|*
name|if_extents
decl_stmt|;
comment|/* linear map file exts */
name|xfs_ext_irec_t
modifier|*
name|if_ext_irec
decl_stmt|;
comment|/* irec map file exts */
name|char
modifier|*
name|if_data
decl_stmt|;
comment|/* inline file data */
block|}
name|if_u1
union|;
union|union
block|{
name|xfs_bmbt_rec_t
name|if_inline_ext
index|[
name|XFS_INLINE_EXTS
index|]
decl_stmt|;
comment|/* very small file extents */
name|char
name|if_inline_data
index|[
name|XFS_INLINE_DATA
index|]
decl_stmt|;
comment|/* very small file data */
name|xfs_dev_t
name|if_rdev
decl_stmt|;
comment|/* dev number if special */
name|uuid_t
name|if_uuid
decl_stmt|;
comment|/* mount point value */
block|}
name|if_u2
union|;
block|}
name|xfs_ifork_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for xfs_ichgtime().  */
end_comment

begin_define
define|#
directive|define
name|XFS_ICHGTIME_MOD
value|0x1
end_define

begin_comment
comment|/* data fork modification timestamp */
end_comment

begin_define
define|#
directive|define
name|XFS_ICHGTIME_ACC
value|0x2
end_define

begin_comment
comment|/* data fork access timestamp */
end_comment

begin_define
define|#
directive|define
name|XFS_ICHGTIME_CHG
value|0x4
end_define

begin_comment
comment|/* inode field change timestamp */
end_comment

begin_comment
comment|/*  * Per-fork incore inode flags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IFINLINE
value|0x01
end_define

begin_comment
comment|/* Inline data is read in */
end_comment

begin_define
define|#
directive|define
name|XFS_IFEXTENTS
value|0x02
end_define

begin_comment
comment|/* All extent pointers are read in */
end_comment

begin_define
define|#
directive|define
name|XFS_IFBROOT
value|0x04
end_define

begin_comment
comment|/* i_broot points to the bmap b-tree root */
end_comment

begin_define
define|#
directive|define
name|XFS_IFEXTIREC
value|0x08
end_define

begin_comment
comment|/* Indirection array of extent blocks */
end_comment

begin_comment
comment|/*  * Flags for xfs_itobp(), xfs_imap() and xfs_dilocate().  */
end_comment

begin_define
define|#
directive|define
name|XFS_IMAP_LOOKUP
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_IMAP_BULKSTAT
value|0x2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_struct_decl
struct_decl|struct
name|bhv_desc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ktrace
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmap_free
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_irec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_bmbt_block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode_log_item
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dquot
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_ILOCK_TRACE
argument_list|)
end_if

begin_define
define|#
directive|define
name|XFS_ILOCK_KTRACE_SIZE
value|32
end_define

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_ilock_trace_buf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|xfs_ilock_trace
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|inst_t
modifier|*
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
name|xfs_ilock_trace
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|,
name|ra
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|dm_attrs_s
block|{
name|__uint32_t
name|da_dmevmask
decl_stmt|;
comment|/* DMIG event mask */
name|__uint16_t
name|da_dmstate
decl_stmt|;
comment|/* DMIG state info */
name|__uint16_t
name|da_pad
decl_stmt|;
comment|/* DMIG extra padding */
block|}
name|dm_attrs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_iocore
block|{
name|void
modifier|*
name|io_obj
decl_stmt|;
comment|/* pointer to container 						 * inode or dcxvn structure */
name|struct
name|xfs_mount
modifier|*
name|io_mount
decl_stmt|;
comment|/* fs mount struct ptr */
ifdef|#
directive|ifdef
name|DEBUG
name|mrlock_t
modifier|*
name|io_lock
decl_stmt|;
comment|/* inode IO lock */
name|mrlock_t
modifier|*
name|io_iolock
decl_stmt|;
comment|/* inode IO lock */
endif|#
directive|endif
comment|/* I/O state */
name|xfs_fsize_t
name|io_new_size
decl_stmt|;
comment|/* sz when write completes */
comment|/* Miscellaneous state. */
name|unsigned
name|int
name|io_flags
decl_stmt|;
comment|/* IO related flags */
comment|/* DMAPI state */
name|dm_attrs_t
name|io_dmattrs
decl_stmt|;
block|}
name|xfs_iocore_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|io_dmevmask
value|io_dmattrs.da_dmevmask
end_define

begin_define
define|#
directive|define
name|io_dmstate
value|io_dmattrs.da_dmstate
end_define

begin_define
define|#
directive|define
name|XFS_IO_INODE
parameter_list|(
name|io
parameter_list|)
value|((xfs_inode_t *) ((io)->io_obj))
end_define

begin_define
define|#
directive|define
name|XFS_IO_DCXVN
parameter_list|(
name|io
parameter_list|)
value|((dcxvn_t *) ((io)->io_obj))
end_define

begin_comment
comment|/*  * Flags in the flags field  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOCORE_RT
value|0x1
end_define

begin_comment
comment|/*  * xfs_iocore prototypes  */
end_comment

begin_function_decl
specifier|extern
name|void
name|xfs_iocore_inode_init
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_iocore_inode_reinit
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This is the type used in the xfs inode hash table.  * An array of these is allocated for each mounted  * file system to hash the inodes for that file system.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_ihash
block|{
name|struct
name|xfs_inode
modifier|*
name|ih_next
decl_stmt|;
name|rwlock_t
name|ih_lock
decl_stmt|;
name|uint
name|ih_version
decl_stmt|;
block|}
name|xfs_ihash_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_IHASH
parameter_list|(
name|mp
parameter_list|,
name|ino
parameter_list|)
value|((mp)->m_ihash + (((uint)(ino)) % (mp)->m_ihsize))
end_define

begin_comment
comment|/*  * This is the xfs inode cluster hash.  This hash is used by xfs_iflush to  * find inodes that share a cluster and can be flushed to disk at the same  * time.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_chashlist
block|{
name|struct
name|xfs_chashlist
modifier|*
name|chl_next
decl_stmt|;
name|struct
name|xfs_chashlist
modifier|*
name|chl_prev
decl_stmt|;
name|struct
name|xfs_inode
modifier|*
name|chl_ip
decl_stmt|;
name|xfs_daddr_t
name|chl_blkno
decl_stmt|;
comment|/* starting block number of 						 * the cluster */
name|struct
name|xfs_buf
modifier|*
name|chl_buf
decl_stmt|;
comment|/* the inode buffer */
block|}
name|xfs_chashlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_chash
block|{
name|xfs_chashlist_t
modifier|*
name|ch_list
decl_stmt|;
name|lock_t
name|ch_lock
decl_stmt|;
block|}
name|xfs_chash_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_CHASH
parameter_list|(
name|mp
parameter_list|,
name|blk
parameter_list|)
value|((mp)->m_chash + (((uint)blk) % (mp)->m_chsize))
end_define

begin_comment
comment|/*  * This is the xfs in-core inode structure.  * Most of the on-disk inode is embedded in the i_d field.  *  * The extent pointers/inline file space, however, are managed  * separately.  The memory for this information is pointed to by  * the if_u1 unions depending on the type of the data.  * This is used to linearize the array of extents for fast in-core  * access.  This is used until the file's number of extents  * surpasses XFS_MAX_INCORE_EXTENTS, at which point all extent pointers  * are accessed through the buffer cache.  *  * Other state kept in the in-core inode is used for identification,  * locking, transactional updating, etc of the inode.  *  * Generally, we do not want to hold the i_rlock while holding the  * i_ilock. Hierarchy is i_iolock followed by i_rlock.  *  * xfs_iptr_t contains all the inode fields upto and including the  * i_mnext and i_mprev fields, it is used as a marker in the inode  * chain off the mount structure by xfs_sync calls.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|xfs_ihash
modifier|*
name|ip_hash
decl_stmt|;
comment|/* pointer to hash header */
name|struct
name|xfs_inode
modifier|*
name|ip_next
decl_stmt|;
comment|/* inode hash link forw */
name|struct
name|xfs_inode
modifier|*
name|ip_mnext
decl_stmt|;
comment|/* next inode in mount list */
name|struct
name|xfs_inode
modifier|*
name|ip_mprev
decl_stmt|;
comment|/* ptr to prev inode */
name|struct
name|xfs_inode
modifier|*
modifier|*
name|ip_prevp
decl_stmt|;
comment|/* ptr to prev i_next */
name|struct
name|xfs_mount
modifier|*
name|ip_mount
decl_stmt|;
comment|/* fs mount struct ptr */
block|}
name|xfs_iptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_inode
block|{
comment|/* Inode linking and identification information. */
name|struct
name|xfs_ihash
modifier|*
name|i_hash
decl_stmt|;
comment|/* pointer to hash header */
name|struct
name|xfs_inode
modifier|*
name|i_next
decl_stmt|;
comment|/* inode hash link forw */
name|struct
name|xfs_inode
modifier|*
name|i_mnext
decl_stmt|;
comment|/* next inode in mount list */
name|struct
name|xfs_inode
modifier|*
name|i_mprev
decl_stmt|;
comment|/* ptr to prev inode */
name|struct
name|xfs_inode
modifier|*
modifier|*
name|i_prevp
decl_stmt|;
comment|/* ptr to prev i_next */
name|struct
name|xfs_mount
modifier|*
name|i_mount
decl_stmt|;
comment|/* fs mount struct ptr */
name|TAILQ_ENTRY
argument_list|(
argument|xfs_inode
argument_list|)
name|i_reclaim
expr_stmt|;
comment|/* reclaim list */
name|struct
name|bhv_desc
name|i_bhv_desc
decl_stmt|;
comment|/* inode behavior descriptor*/
name|struct
name|xfs_dquot
modifier|*
name|i_udquot
decl_stmt|;
comment|/* user dquot */
name|struct
name|xfs_dquot
modifier|*
name|i_gdquot
decl_stmt|;
comment|/* group dquot */
comment|/* Inode location stuff */
name|xfs_ino_t
name|i_ino
decl_stmt|;
comment|/* inode number (agno/agino)*/
name|xfs_daddr_t
name|i_blkno
decl_stmt|;
comment|/* blkno of inode buffer */
name|ushort
name|i_len
decl_stmt|;
comment|/* len of inode buffer */
name|ushort
name|i_boffset
decl_stmt|;
comment|/* off of inode in buffer */
comment|/* Extent information. */
name|xfs_ifork_t
modifier|*
name|i_afp
decl_stmt|;
comment|/* attribute fork pointer */
name|xfs_ifork_t
name|i_df
decl_stmt|;
comment|/* data fork */
comment|/* Transaction and locking information. */
name|struct
name|xfs_trans
modifier|*
name|i_transp
decl_stmt|;
comment|/* ptr to owning transaction*/
name|struct
name|xfs_inode_log_item
modifier|*
name|i_itemp
decl_stmt|;
comment|/* logging information */
name|mrlock_t
name|i_lock
decl_stmt|;
comment|/* inode lock */
name|mrlock_t
name|i_iolock
decl_stmt|;
comment|/* inode IO lock */
name|sema_t
name|i_flock
decl_stmt|;
comment|/* inode flush lock */
name|atomic_t
name|i_pincount
decl_stmt|;
comment|/* inode pin count */
name|wait_queue_head_t
name|i_ipin_wait
decl_stmt|;
comment|/* inode pinning wait queue */
ifdef|#
directive|ifdef
name|HAVE_REFCACHE
name|struct
name|xfs_inode
modifier|*
modifier|*
name|i_refcache
decl_stmt|;
comment|/* ptr to entry in ref cache */
name|struct
name|xfs_inode
modifier|*
name|i_release
decl_stmt|;
comment|/* inode to unref */
endif|#
directive|endif
comment|/* I/O state */
name|xfs_iocore_t
name|i_iocore
decl_stmt|;
comment|/* I/O core */
comment|/* Miscellaneous state. */
name|unsigned
name|short
name|i_flags
decl_stmt|;
comment|/* see defined flags below */
name|unsigned
name|char
name|i_update_core
decl_stmt|;
comment|/* timestamps/size is dirty */
name|unsigned
name|char
name|i_update_size
decl_stmt|;
comment|/* di_size field is dirty */
name|unsigned
name|int
name|i_gen
decl_stmt|;
comment|/* generation count */
name|unsigned
name|int
name|i_delayed_blks
decl_stmt|;
comment|/* count of delay alloc blks */
name|xfs_dinode_core_t
name|i_d
decl_stmt|;
comment|/* most of ondisk inode */
name|xfs_chashlist_t
modifier|*
name|i_chash
decl_stmt|;
comment|/* cluster hash list header */
name|struct
name|xfs_inode
modifier|*
name|i_cnext
decl_stmt|;
comment|/* cluster hash link forward */
name|struct
name|xfs_inode
modifier|*
name|i_cprev
decl_stmt|;
comment|/* cluster hash link backward */
comment|/* Trace buffers per inode. */
ifdef|#
directive|ifdef
name|XFS_BMAP_TRACE
name|struct
name|ktrace
modifier|*
name|i_xtrace
decl_stmt|;
comment|/* inode extent list trace */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_BMBT_TRACE
name|struct
name|ktrace
modifier|*
name|i_btrace
decl_stmt|;
comment|/* inode bmap btree trace */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_RW_TRACE
name|struct
name|ktrace
modifier|*
name|i_rwtrace
decl_stmt|;
comment|/* inode read/write trace */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_ILOCK_TRACE
name|struct
name|ktrace
modifier|*
name|i_lock_trace
decl_stmt|;
comment|/* inode lock/unlock trace */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|XFS_DIR2_TRACE
name|struct
name|ktrace
modifier|*
name|i_dir_trace
decl_stmt|;
comment|/* inode directory trace */
endif|#
directive|endif
block|}
name|xfs_inode_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/*  * Fork handling.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IFORK_PTR
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|)
define|\
value|((w) == XFS_DATA_FORK ?&(ip)->i_df : (ip)->i_afp)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_Q
parameter_list|(
name|ip
parameter_list|)
value|XFS_CFORK_Q(&(ip)->i_d)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_DSIZE
parameter_list|(
name|ip
parameter_list|)
value|XFS_CFORK_DSIZE(&ip->i_d, ip->i_mount)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_ASIZE
parameter_list|(
name|ip
parameter_list|)
value|XFS_CFORK_ASIZE(&ip->i_d, ip->i_mount)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_SIZE
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_SIZE(&ip->i_d, ip->i_mount, w)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_FORMAT
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_FORMAT(&ip->i_d, w)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_FMT_SET
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|XFS_CFORK_FMT_SET(&ip->i_d, w, n)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_NEXTENTS
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|)
value|XFS_CFORK_NEXTENTS(&ip->i_d, w)
end_define

begin_define
define|#
directive|define
name|XFS_IFORK_NEXT_SET
parameter_list|(
name|ip
parameter_list|,
name|w
parameter_list|,
name|n
parameter_list|)
value|XFS_CFORK_NEXT_SET(&ip->i_d, w, n)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * In-core inode flags.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IGRIO
value|0x0001
end_define

begin_comment
comment|/* inode used for guaranteed rate i/o */
end_comment

begin_define
define|#
directive|define
name|XFS_IUIOSZ
value|0x0002
end_define

begin_comment
comment|/* inode i/o sizes have been explicitly set */
end_comment

begin_define
define|#
directive|define
name|XFS_IQUIESCE
value|0x0004
end_define

begin_comment
comment|/* we have started quiescing for this inode */
end_comment

begin_define
define|#
directive|define
name|XFS_IRECLAIM
value|0x0008
end_define

begin_comment
comment|/* we have started reclaiming this inode    */
end_comment

begin_define
define|#
directive|define
name|XFS_ISTALE
value|0x0010
end_define

begin_comment
comment|/* inode has been staled */
end_comment

begin_define
define|#
directive|define
name|XFS_IRECLAIMABLE
value|0x0020
end_define

begin_comment
comment|/* inode can be reclaimed */
end_comment

begin_define
define|#
directive|define
name|XFS_INEW
value|0x0040
end_define

begin_comment
comment|/*  * Flags for inode locking.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IOLOCK_EXCL
value|0x001
end_define

begin_define
define|#
directive|define
name|XFS_IOLOCK_SHARED
value|0x002
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK_EXCL
value|0x004
end_define

begin_define
define|#
directive|define
name|XFS_ILOCK_SHARED
value|0x008
end_define

begin_define
define|#
directive|define
name|XFS_IUNLOCK_NONOTIFY
value|0x010
end_define

begin_comment
comment|/*	XFS_IOLOCK_NESTED	0x020 */
end_comment

begin_define
define|#
directive|define
name|XFS_EXTENT_TOKEN_RD
value|0x040
end_define

begin_define
define|#
directive|define
name|XFS_SIZE_TOKEN_RD
value|0x080
end_define

begin_define
define|#
directive|define
name|XFS_EXTSIZE_RD
value|(XFS_EXTENT_TOKEN_RD|XFS_SIZE_TOKEN_RD)
end_define

begin_define
define|#
directive|define
name|XFS_WILLLEND
value|0x100
end_define

begin_comment
comment|/* Always acquire tokens for lending */
end_comment

begin_define
define|#
directive|define
name|XFS_EXTENT_TOKEN_WR
value|(XFS_EXTENT_TOKEN_RD | XFS_WILLLEND)
end_define

begin_define
define|#
directive|define
name|XFS_SIZE_TOKEN_WR
value|(XFS_SIZE_TOKEN_RD | XFS_WILLLEND)
end_define

begin_define
define|#
directive|define
name|XFS_EXTSIZE_WR
value|(XFS_EXTSIZE_RD | XFS_WILLLEND)
end_define

begin_comment
comment|/*	XFS_SIZE_TOKEN_WANT	0x200 */
end_comment

begin_define
define|#
directive|define
name|XFS_LOCK_MASK
define|\
value|(XFS_IOLOCK_EXCL | XFS_IOLOCK_SHARED | XFS_ILOCK_EXCL | \ 	 XFS_ILOCK_SHARED | XFS_EXTENT_TOKEN_RD | XFS_SIZE_TOKEN_RD | \ 	 XFS_WILLLEND)
end_define

begin_comment
comment|/*  * Flags for xfs_iflush()  */
end_comment

begin_define
define|#
directive|define
name|XFS_IFLUSH_DELWRI_ELSE_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|XFS_IFLUSH_DELWRI_ELSE_ASYNC
value|2
end_define

begin_define
define|#
directive|define
name|XFS_IFLUSH_SYNC
value|3
end_define

begin_define
define|#
directive|define
name|XFS_IFLUSH_ASYNC
value|4
end_define

begin_define
define|#
directive|define
name|XFS_IFLUSH_DELWRI
value|5
end_define

begin_comment
comment|/*  * Flags for xfs_itruncate_start().  */
end_comment

begin_define
define|#
directive|define
name|XFS_ITRUNC_DEFINITE
value|0x1
end_define

begin_define
define|#
directive|define
name|XFS_ITRUNC_MAYBE
value|0x2
end_define

begin_define
define|#
directive|define
name|XFS_ITOV
parameter_list|(
name|ip
parameter_list|)
value|BHV_TO_VNODE(XFS_ITOBHV(ip))
end_define

begin_define
define|#
directive|define
name|XFS_ITOV_NULL
parameter_list|(
name|ip
parameter_list|)
value|BHV_TO_VNODE_NULL(XFS_ITOBHV(ip))
end_define

begin_define
define|#
directive|define
name|XFS_ITOBHV
parameter_list|(
name|ip
parameter_list|)
value|((struct bhv_desc *)(&((ip)->i_bhv_desc)))
end_define

begin_define
define|#
directive|define
name|XFS_BHVTOI
parameter_list|(
name|bhvp
parameter_list|)
value|((xfs_inode_t *)((char *)(bhvp) - \ 				(char *)&(((xfs_inode_t *)0)->i_bhv_desc)))
end_define

begin_define
define|#
directive|define
name|BHV_IS_XFS
parameter_list|(
name|bdp
parameter_list|)
value|(BHV_OPS(bdp) ==&xfs_vnodeops)
end_define

begin_comment
comment|/*  * For multiple groups support: if S_ISGID bit is set in the parent  * directory, group of new file is set to that of the parent, and  * new subdirectory gets S_ISGID bit from parent.  */
end_comment

begin_define
define|#
directive|define
name|XFS_INHERIT_GID
parameter_list|(
name|pip
parameter_list|,
name|vfsp
parameter_list|)
define|\
value|(((vfsp)->vfs_flag& VFS_GRPID) || ((pip)->i_d.di_mode& S_ISGID))
end_define

begin_comment
comment|/*  * xfs_iget.c prototypes.  */
end_comment

begin_define
define|#
directive|define
name|IGET_CREATE
value|1
end_define

begin_function_decl
name|void
name|xfs_ihash_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ihash_free
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_chash_init
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_chash_free
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_inode_t
modifier|*
name|xfs_inode_incore
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_inode_lock_init
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iget
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|uint
parameter_list|,
name|uint
parameter_list|,
name|xfs_inode_t
modifier|*
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iput
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iput_new
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ilock
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_ilock_nowait
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iunlock
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ilock_demote
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iflock
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iflock_nowait
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_ilock_map_shared
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iunlock_map_shared
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ifunlock
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ireclaim
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_finish_reclaim
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_finish_reclaim_all
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * xfs_inode.c prototypes.  */
end_comment

begin_function_decl
name|int
name|xfs_itobp
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_dinode_t
modifier|*
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iread
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|xfs_inode_t
modifier|*
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iread_extents
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_ialloc
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|xfs_nlink_t
parameter_list|,
name|xfs_dev_t
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|,
name|xfs_prid_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|xfs_buf
modifier|*
modifier|*
parameter_list|,
name|boolean_t
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_xlate_dinode_core
parameter_list|(
name|xfs_caddr_t
parameter_list|,
name|struct
name|xfs_dinode_core
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_ip2xflags
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_dic2xflags
parameter_list|(
name|struct
name|xfs_dinode_core
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_ifree
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|struct
name|xfs_bmap_free
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_itruncate_start
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|,
name|xfs_fsize_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_itruncate_finish
parameter_list|(
name|struct
name|xfs_trans
modifier|*
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_fsize_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iunlink
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_igrow_start
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_fsize_t
parameter_list|,
name|struct
name|cred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_igrow_finish
parameter_list|(
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_fsize_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_idestroy_fork
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_idestroy
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_idata_realloc
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iextract
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_realloc
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iroot_realloc
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ipin
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iunpin
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iextents_copy
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_bmbt_rec_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iflush
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iflush_all
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_iaccess
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|cred_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint
name|xfs_iroundup
parameter_list|(
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_ichgtime
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_fsize_t
name|xfs_file_last_byte
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_lock_inodes
parameter_list|(
name|xfs_inode_t
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_inode_t
modifier|*
name|xfs_vtoi
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_synchronize_atime
parameter_list|(
name|xfs_inode_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_iext_get_ext
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_insert
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_add
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_add_indirect_multi
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_remove
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_remove_inline
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_remove_direct
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_remove_indirect
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_realloc_direct
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_realloc_indirect
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_indirect_to_direct
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_direct_to_inline
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_inline_to_direct
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_destroy
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_iext_bno_to_ext
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_ext_irec_t
modifier|*
name|xfs_iext_bno_to_irec
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_ext_irec_t
modifier|*
name|xfs_iext_idx_to_irec
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|xfs_extnum_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_init
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_ext_irec_t
modifier|*
name|xfs_iext_irec_new
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_remove
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_compact
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_compact_pages
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_compact_full
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_iext_irec_update_extoffs
parameter_list|(
name|xfs_ifork_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_ipincount
parameter_list|(
name|ip
parameter_list|)
value|((unsigned int) atomic_read(&ip->i_pincount))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
name|void
name|xfs_isize_check
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|xfs_inode_t
modifier|*
parameter_list|,
name|xfs_fsize_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|xfs_isize_check
parameter_list|(
name|mp
parameter_list|,
name|ip
parameter_list|,
name|isize
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_if

begin_function_decl
name|void
name|xfs_inobp_check
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
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
name|xfs_inobp_check
parameter_list|(
name|mp
parameter_list|,
name|bp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_chashlist_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_ifork_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_inode_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_ili_zone
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_INODE_H__ */
end_comment

end_unit

