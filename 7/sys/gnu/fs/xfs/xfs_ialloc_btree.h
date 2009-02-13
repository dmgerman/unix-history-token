begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_IALLOC_BTREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_IALLOC_BTREE_H__
end_define

begin_comment
comment|/*  * Inode map on-disk structures  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_btree_cur
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_btree_sblock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * There is a btree for the inode map per allocation group.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IBT_MAGIC
value|0x49414254
end_define

begin_comment
comment|/* 'IABT' */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_inofree_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_INODES_PER_CHUNK
value|(NBBY * sizeof(xfs_inofree_t))
end_define

begin_define
define|#
directive|define
name|XFS_INODES_PER_CHUNK_LOG
value|(XFS_NBBYLOG + 3)
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_ALL_FREE
value|((xfs_inofree_t)-1)
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_MASKN
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|xfs_inobt_maskn(i,n)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_inofree_t
name|xfs_inobt_maskn
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|n
operator|)
operator|>=
name|XFS_INODES_PER_CHUNK
condition|?
then|\
operator|(
name|xfs_inofree_t
operator|)
literal|0
else|:
operator|(
operator|(
name|xfs_inofree_t
operator|)
literal|1
operator|<<
operator|(
name|n
operator|)
operator|)
operator|)
operator|-
literal|1
operator|)
operator|<<
operator|(
name|i
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Data record structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_inobt_rec
block|{
name|xfs_agino_t
name|ir_startino
decl_stmt|;
comment|/* starting inode number */
name|__int32_t
name|ir_freecount
decl_stmt|;
comment|/* count of free inodes (set bits) */
name|xfs_inofree_t
name|ir_free
decl_stmt|;
comment|/* free inode mask */
block|}
name|xfs_inobt_rec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Key structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_inobt_key
block|{
name|xfs_agino_t
name|ir_startino
decl_stmt|;
comment|/* starting inode number */
block|}
name|xfs_inobt_key_t
typedef|;
end_typedef

begin_comment
comment|/* btree pointer type */
end_comment

begin_typedef
typedef|typedef
name|__be32
name|xfs_inobt_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* btree block header type */
end_comment

begin_typedef
typedef|typedef
name|struct
name|xfs_btree_sblock
name|xfs_inobt_block_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_BUF_TO_INOBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_inobt_block_t *)XFS_BUF_PTR(bp))
end_define

begin_comment
comment|/*  * Bit manipulations for ir_free.  */
end_comment

begin_define
define|#
directive|define
name|XFS_INOBT_MASK
parameter_list|(
name|i
parameter_list|)
value|((xfs_inofree_t)1<< (i))
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_IS_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|)
define|\
value|(((rp)->ir_free& XFS_INOBT_MASK(i)) != 0)
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_IS_FREE_DISK
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|)
define|\
value|((INT_GET((rp)->ir_free,ARCH_CONVERT)& XFS_INOBT_MASK(i)) != 0)
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_SET_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|)
value|((rp)->ir_free |= XFS_INOBT_MASK(i))
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_CLR_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|)
value|((rp)->ir_free&= ~XFS_INOBT_MASK(i))
end_define

begin_comment
comment|/*  * Real block structures have a size equal to the disk block size.  */
end_comment

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_SIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|(1<< (cur)->bc_blocklog)
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|((cur)->bc_mp->m_inobt_mxr[lev != 0])
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|((cur)->bc_mp->m_inobt_mnr[lev != 0])
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_IS_LAST_REC
parameter_list|(
name|cur
parameter_list|)
define|\
value|((cur)->bc_ptrs[0] == be16_to_cpu(XFS_BUF_TO_INOBT_BLOCK((cur)->bc_bufs[0])->bb_numrecs))
end_define

begin_comment
comment|/*  * Maximum number of inode btree levels.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IN_MAXLEVELS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_in_maxlevels)
end_define

begin_comment
comment|/*  * block numbers in the AG.  */
end_comment

begin_define
define|#
directive|define
name|XFS_IBT_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_CNT_BLOCK(mp) + 1))
end_define

begin_define
define|#
directive|define
name|XFS_PREALLOC_BLOCKS
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_IBT_BLOCK(mp) + 1))
end_define

begin_comment
comment|/*  * Record, key, and pointer address macros for btree blocks.  */
end_comment

begin_define
define|#
directive|define
name|XFS_INOBT_REC_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|(XFS_BTREE_REC_ADDR(XFS_INOBT_BLOCK_SIZE(0,cur), xfs_inobt, bb, \ 				i, XFS_INOBT_BLOCK_MAXRECS(0, cur)))
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_KEY_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|(XFS_BTREE_KEY_ADDR(XFS_INOBT_BLOCK_SIZE(1,cur), xfs_inobt, bb, \ 				i, XFS_INOBT_BLOCK_MAXRECS(1, cur)))
end_define

begin_define
define|#
directive|define
name|XFS_INOBT_PTR_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|(XFS_BTREE_PTR_ADDR(XFS_INOBT_BLOCK_SIZE(1,cur), xfs_inobt, bb, \ 				i, XFS_INOBT_BLOCK_MAXRECS(1, cur)))
end_define

begin_comment
comment|/*  * Decrement cursor by one record at the level.  * For nonzero levels the leaf-ward information is untouched.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_decrement
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
name|level
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Delete the record pointed to by cur.  * The cursor refers to the place where the record was (could be inserted)  * when the operation returns.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_delete
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the data from the pointed-to record.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_get_rec
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|xfs_agino_t
modifier|*
name|ino
parameter_list|,
name|__int32_t
modifier|*
name|fcnt
parameter_list|,
name|xfs_inofree_t
modifier|*
name|free
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increment cursor by one record at the level.  * For nonzero levels the leaf-ward information is untouched.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_increment
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
name|level
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Insert the current record at the point referenced by cur.  * The cursor may be inconsistent on return if splits have been done.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_insert
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup the record equal to ino in the btree given by cur.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_lookup_eq
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|xfs_agino_t
name|ino
parameter_list|,
name|__int32_t
name|fcnt
parameter_list|,
name|xfs_inofree_t
name|free
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup the first record greater than or equal to ino  * in the btree given by cur.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_lookup_ge
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|xfs_agino_t
name|ino
parameter_list|,
name|__int32_t
name|fcnt
parameter_list|,
name|xfs_inofree_t
name|free
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lookup the first record less than or equal to ino  * in the btree given by cur.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_lookup_le
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|xfs_agino_t
name|ino
parameter_list|,
name|__int32_t
name|fcnt
parameter_list|,
name|xfs_inofree_t
name|free
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Update the record referred to by cur, to the value given  * by [ino, fcnt, free].  * This either works (return 0) or gets an EFSCORRUPTED error.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_inobt_update
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|xfs_agino_t
name|ino
parameter_list|,
name|__int32_t
name|fcnt
parameter_list|,
name|xfs_inofree_t
name|free
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_IALLOC_BTREE_H__ */
end_comment

end_unit

