begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BTREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BTREE_H__
end_define

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
name|xfs_inode
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

begin_comment
comment|/*  * This nonsense is to make -wlint happy.  */
end_comment

begin_define
define|#
directive|define
name|XFS_LOOKUP_EQ
value|((xfs_lookup_t)XFS_LOOKUP_EQi)
end_define

begin_define
define|#
directive|define
name|XFS_LOOKUP_LE
value|((xfs_lookup_t)XFS_LOOKUP_LEi)
end_define

begin_define
define|#
directive|define
name|XFS_LOOKUP_GE
value|((xfs_lookup_t)XFS_LOOKUP_GEi)
end_define

begin_define
define|#
directive|define
name|XFS_BTNUM_BNO
value|((xfs_btnum_t)XFS_BTNUM_BNOi)
end_define

begin_define
define|#
directive|define
name|XFS_BTNUM_CNT
value|((xfs_btnum_t)XFS_BTNUM_CNTi)
end_define

begin_define
define|#
directive|define
name|XFS_BTNUM_BMAP
value|((xfs_btnum_t)XFS_BTNUM_BMAPi)
end_define

begin_define
define|#
directive|define
name|XFS_BTNUM_INO
value|((xfs_btnum_t)XFS_BTNUM_INOi)
end_define

begin_comment
comment|/*  * Short form header: space allocation btrees.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_btree_sblock
block|{
name|__be32
name|bb_magic
decl_stmt|;
comment|/* magic number for block type */
name|__be16
name|bb_level
decl_stmt|;
comment|/* 0 is a leaf */
name|__be16
name|bb_numrecs
decl_stmt|;
comment|/* current # of data records */
name|__be32
name|bb_leftsib
decl_stmt|;
comment|/* left sibling block or NULLAGBLOCK */
name|__be32
name|bb_rightsib
decl_stmt|;
comment|/* right sibling block or NULLAGBLOCK */
block|}
name|xfs_btree_sblock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Long form header: bmap btrees.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_btree_lblock
block|{
name|__be32
name|bb_magic
decl_stmt|;
comment|/* magic number for block type */
name|__be16
name|bb_level
decl_stmt|;
comment|/* 0 is a leaf */
name|__be16
name|bb_numrecs
decl_stmt|;
comment|/* current # of data records */
name|__be64
name|bb_leftsib
decl_stmt|;
comment|/* left sibling block or NULLDFSBNO */
name|__be64
name|bb_rightsib
decl_stmt|;
comment|/* right sibling block or NULLDFSBNO */
block|}
name|xfs_btree_lblock_t
typedef|;
end_typedef

begin_comment
comment|/*  * Combined header and structure, used by common code.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_btree_hdr
block|{
name|__be32
name|bb_magic
decl_stmt|;
comment|/* magic number for block type */
name|__be16
name|bb_level
decl_stmt|;
comment|/* 0 is a leaf */
name|__be16
name|bb_numrecs
decl_stmt|;
comment|/* current # of data records */
block|}
name|xfs_btree_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_btree_block
block|{
name|xfs_btree_hdr_t
name|bb_h
decl_stmt|;
comment|/* header */
union|union
block|{
struct|struct
block|{
name|__be32
name|bb_leftsib
decl_stmt|;
name|__be32
name|bb_rightsib
decl_stmt|;
block|}
name|s
struct|;
comment|/* short form pointers */
struct|struct
block|{
name|__be64
name|bb_leftsib
decl_stmt|;
name|__be64
name|bb_rightsib
decl_stmt|;
block|}
name|l
struct|;
comment|/* long form pointers */
block|}
name|bb_u
union|;
comment|/* rest */
block|}
name|xfs_btree_block_t
typedef|;
end_typedef

begin_comment
comment|/*  * For logging record fields.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BB_MAGIC
value|0x01
end_define

begin_define
define|#
directive|define
name|XFS_BB_LEVEL
value|0x02
end_define

begin_define
define|#
directive|define
name|XFS_BB_NUMRECS
value|0x04
end_define

begin_define
define|#
directive|define
name|XFS_BB_LEFTSIB
value|0x08
end_define

begin_define
define|#
directive|define
name|XFS_BB_RIGHTSIB
value|0x10
end_define

begin_define
define|#
directive|define
name|XFS_BB_NUM_BITS
value|5
end_define

begin_define
define|#
directive|define
name|XFS_BB_ALL_BITS
value|((1<< XFS_BB_NUM_BITS) - 1)
end_define

begin_comment
comment|/*  * Boolean to select which form of xfs_btree_block_t.bb_u to use.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BTREE_LONG_PTRS
parameter_list|(
name|btnum
parameter_list|)
value|((btnum) == XFS_BTNUM_BMAP)
end_define

begin_comment
comment|/*  * Magic numbers for btree blocks.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|__uint32_t
name|xfs_magics
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Maximum and minimum records in a btree block.  * Given block size, type prefix, and leaf flag (0 or 1).  * The divisor below is equivalent to lf ? (e1) : (e2) but that produces  * compiler warnings.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BTREE_BLOCK_MAXRECS
parameter_list|(
name|bsz
parameter_list|,
name|t
parameter_list|,
name|lf
parameter_list|)
define|\
value|((int)(((bsz) - (uint)sizeof(t ## _block_t)) / \ 	 (((lf) * (uint)sizeof(t ## _rec_t)) + \ 	  ((1 - (lf)) * \ 	   ((uint)sizeof(t ## _key_t) + (uint)sizeof(t ## _ptr_t))))))
end_define

begin_define
define|#
directive|define
name|XFS_BTREE_BLOCK_MINRECS
parameter_list|(
name|bsz
parameter_list|,
name|t
parameter_list|,
name|lf
parameter_list|)
define|\
value|(XFS_BTREE_BLOCK_MAXRECS(bsz,t,lf) / 2)
end_define

begin_comment
comment|/*  * Record, key, and pointer address calculation macros.  * Given block size, type prefix, block pointer, and index of requested entry  * (first entry numbered 1).  */
end_comment

begin_define
define|#
directive|define
name|XFS_BTREE_REC_ADDR
parameter_list|(
name|bsz
parameter_list|,
name|t
parameter_list|,
name|bb
parameter_list|,
name|i
parameter_list|,
name|mxr
parameter_list|)
define|\
value|((t ## _rec_t *)((char *)(bb) + sizeof(t ## _block_t) + \ 	 ((i) - 1) * sizeof(t ## _rec_t)))
end_define

begin_define
define|#
directive|define
name|XFS_BTREE_KEY_ADDR
parameter_list|(
name|bsz
parameter_list|,
name|t
parameter_list|,
name|bb
parameter_list|,
name|i
parameter_list|,
name|mxr
parameter_list|)
define|\
value|((t ## _key_t *)((char *)(bb) + sizeof(t ## _block_t) + \ 	 ((i) - 1) * sizeof(t ## _key_t)))
end_define

begin_define
define|#
directive|define
name|XFS_BTREE_PTR_ADDR
parameter_list|(
name|bsz
parameter_list|,
name|t
parameter_list|,
name|bb
parameter_list|,
name|i
parameter_list|,
name|mxr
parameter_list|)
define|\
value|((t ## _ptr_t *)((char *)(bb) + sizeof(t ## _block_t) + \ 	 (mxr) * sizeof(t ## _key_t) + ((i) - 1) * sizeof(t ## _ptr_t)))
end_define

begin_define
define|#
directive|define
name|XFS_BTREE_MAXLEVELS
value|8
end_define

begin_comment
comment|/* max of all btrees */
end_comment

begin_comment
comment|/*  * Btree cursor structure.  * This collects all information needed by the btree code in one place.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_btree_cur
block|{
name|struct
name|xfs_trans
modifier|*
name|bc_tp
decl_stmt|;
comment|/* transaction we're in, if any */
name|struct
name|xfs_mount
modifier|*
name|bc_mp
decl_stmt|;
comment|/* file system mount struct */
union|union
block|{
name|xfs_alloc_rec_incore_t
name|a
decl_stmt|;
name|xfs_bmbt_irec_t
name|b
decl_stmt|;
name|xfs_inobt_rec_t
name|i
decl_stmt|;
block|}
name|bc_rec
union|;
comment|/* current insert/search record value */
name|struct
name|xfs_buf
modifier|*
name|bc_bufs
index|[
name|XFS_BTREE_MAXLEVELS
index|]
decl_stmt|;
comment|/* buf ptr per level */
name|int
name|bc_ptrs
index|[
name|XFS_BTREE_MAXLEVELS
index|]
decl_stmt|;
comment|/* key/record # */
name|__uint8_t
name|bc_ra
index|[
name|XFS_BTREE_MAXLEVELS
index|]
decl_stmt|;
comment|/* readahead bits */
define|#
directive|define
name|XFS_BTCUR_LEFTRA
value|1
comment|/* left sibling has been read-ahead */
define|#
directive|define
name|XFS_BTCUR_RIGHTRA
value|2
comment|/* right sibling has been read-ahead */
name|__uint8_t
name|bc_nlevels
decl_stmt|;
comment|/* number of levels in the tree */
name|__uint8_t
name|bc_blocklog
decl_stmt|;
comment|/* log2(blocksize) of btree blocks */
name|xfs_btnum_t
name|bc_btnum
decl_stmt|;
comment|/* identifies which btree type */
union|union
block|{
struct|struct
block|{
comment|/* needed for BNO, CNT */
name|struct
name|xfs_buf
modifier|*
name|agbp
decl_stmt|;
comment|/* agf buffer pointer */
name|xfs_agnumber_t
name|agno
decl_stmt|;
comment|/* ag number */
block|}
name|a
struct|;
struct|struct
block|{
comment|/* needed for BMAP */
name|struct
name|xfs_inode
modifier|*
name|ip
decl_stmt|;
comment|/* pointer to our inode */
name|struct
name|xfs_bmap_free
modifier|*
name|flist
decl_stmt|;
comment|/* list to free after */
name|xfs_fsblock_t
name|firstblock
decl_stmt|;
comment|/* 1st blk allocated */
name|int
name|allocated
decl_stmt|;
comment|/* count of alloced */
name|short
name|forksize
decl_stmt|;
comment|/* fork's inode space */
name|char
name|whichfork
decl_stmt|;
comment|/* data or attr fork */
name|char
name|flags
decl_stmt|;
comment|/* flags */
define|#
directive|define
name|XFS_BTCUR_BPRV_WASDEL
value|1
comment|/* was delayed */
block|}
name|b
struct|;
struct|struct
block|{
comment|/* needed for INO */
name|struct
name|xfs_buf
modifier|*
name|agbp
decl_stmt|;
comment|/* agi buffer pointer */
name|xfs_agnumber_t
name|agno
decl_stmt|;
comment|/* ag number */
block|}
name|i
struct|;
block|}
name|bc_private
union|;
comment|/* per-btree type data */
block|}
name|xfs_btree_cur_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_BTREE_NOERROR
value|0
end_define

begin_define
define|#
directive|define
name|XFS_BTREE_ERROR
value|1
end_define

begin_comment
comment|/*  * Convert from buffer to btree block header.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BUF_TO_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_btree_block_t *)XFS_BUF_PTR(bp))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_LBLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_btree_lblock_t *)XFS_BUF_PTR(bp))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_SBLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_btree_sblock_t *)XFS_BUF_PTR(bp))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*  * Debug routine: check that block header is ok.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_check_block
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_btree_block_t
modifier|*
name|block
parameter_list|,
comment|/* generic btree block pointer */
name|int
name|level
parameter_list|,
comment|/* level of the btree block */
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* buffer containing block, if any */
end_comment

begin_comment
comment|/*  * Debug routine: check that keys are in the right order.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_check_key
parameter_list|(
name|xfs_btnum_t
name|btnum
parameter_list|,
comment|/* btree identifier */
name|void
modifier|*
name|ak1
parameter_list|,
comment|/* pointer to left (lower) key */
name|void
modifier|*
name|ak2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pointer to right (higher) key */
end_comment

begin_comment
comment|/*  * Debug routine: check that records are in the right order.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_check_rec
parameter_list|(
name|xfs_btnum_t
name|btnum
parameter_list|,
comment|/* btree identifier */
name|void
modifier|*
name|ar1
parameter_list|,
comment|/* pointer to left (lower) record */
name|void
modifier|*
name|ar2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pointer to right (higher) record */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_btree_check_block
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_btree_check_key
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_btree_check_rec
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*  * Checking routine: check that long form block header is ok.  */
end_comment

begin_function_decl
name|int
comment|/* error (0 or EFSCORRUPTED) */
name|xfs_btree_check_lblock
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_btree_lblock_t
modifier|*
name|block
parameter_list|,
comment|/* btree long form block pointer */
name|int
name|level
parameter_list|,
comment|/* level of the btree block */
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* buffer containing block, if any */
end_comment

begin_comment
comment|/*  * Checking routine: check that (long) pointer is ok.  */
end_comment

begin_function_decl
name|int
comment|/* error (0 or EFSCORRUPTED) */
name|xfs_btree_check_lptr
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_dfsbno_t
name|ptr
parameter_list|,
comment|/* btree block disk address */
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* btree block level */
end_comment

begin_comment
comment|/*  * Checking routine: check that short form block header is ok.  */
end_comment

begin_function_decl
name|int
comment|/* error (0 or EFSCORRUPTED) */
name|xfs_btree_check_sblock
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_btree_sblock_t
modifier|*
name|block
parameter_list|,
comment|/* btree short form block pointer */
name|int
name|level
parameter_list|,
comment|/* level of the btree block */
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* buffer containing block */
end_comment

begin_comment
comment|/*  * Checking routine: check that (short) pointer is ok.  */
end_comment

begin_function_decl
name|int
comment|/* error (0 or EFSCORRUPTED) */
name|xfs_btree_check_sptr
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
name|ptr
parameter_list|,
comment|/* btree block disk address */
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* btree block level */
end_comment

begin_comment
comment|/*  * Delete the btree cursor.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_del_cursor
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* del because of error */
end_comment

begin_comment
comment|/*  * Duplicate the btree cursor.  * Allocate a new one, copy the record, re-get the buffers.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_btree_dup_cursor
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* input cursor */
name|xfs_btree_cur_t
modifier|*
modifier|*
name|ncur
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output cursor */
end_comment

begin_comment
comment|/*  * Change the cursor to point to the first record in the current block  * at the given level.  Other levels are unaffected.  */
end_comment

begin_function_decl
name|int
comment|/* success=1, failure=0 */
name|xfs_btree_firstrec
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* level to change */
end_comment

begin_comment
comment|/*  * Get a buffer for the block, return it with no data read.  * Long-form addressing.  */
end_comment

begin_function_decl
name|struct
name|xfs_buf
modifier|*
comment|/* buffer for fsbno */
name|xfs_btree_get_bufl
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_fsblock_t
name|fsbno
parameter_list|,
comment|/* file system block number */
name|uint
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lock flags for get_buf */
end_comment

begin_comment
comment|/*  * Get a buffer for the block, return it with no data read.  * Short-form addressing.  */
end_comment

begin_function_decl
name|struct
name|xfs_buf
modifier|*
comment|/* buffer for agno/agbno */
name|xfs_btree_get_bufs
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_agnumber_t
name|agno
parameter_list|,
comment|/* allocation group number */
name|xfs_agblock_t
name|agbno
parameter_list|,
comment|/* allocation group block number */
name|uint
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lock flags for get_buf */
end_comment

begin_comment
comment|/*  * Allocate a new btree cursor.  * The cursor is either for allocation (A) or bmap (B).  */
end_comment

begin_function_decl
name|xfs_btree_cur_t
modifier|*
comment|/* new btree cursor */
name|xfs_btree_init_cursor
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_buf
modifier|*
name|agbp
parameter_list|,
comment|/* (A only) buffer for agf structure */
name|xfs_agnumber_t
name|agno
parameter_list|,
comment|/* (A only) allocation group number */
name|xfs_btnum_t
name|btnum
parameter_list|,
comment|/* btree identifier */
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
comment|/* (B only) inode owning the btree */
name|int
name|whichfork
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* (B only) data/attr fork */
end_comment

begin_comment
comment|/*  * Check for the cursor referring to the last block at the given level.  */
end_comment

begin_function_decl
name|int
comment|/* 1=is last block, 0=not last block */
name|xfs_btree_islastblock
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* level to check */
end_comment

begin_comment
comment|/*  * Change the cursor to point to the last record in the current block  * at the given level.  Other levels are unaffected.  */
end_comment

begin_function_decl
name|int
comment|/* success=1, failure=0 */
name|xfs_btree_lastrec
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* level to change */
end_comment

begin_comment
comment|/*  * Compute first and last byte offsets for the fields given.  * Interprets the offsets table, which contains struct field offsets.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_offsets
parameter_list|(
name|__int64_t
name|fields
parameter_list|,
comment|/* bitmask of fields */
specifier|const
name|short
modifier|*
name|offsets
parameter_list|,
comment|/* table of field offsets */
name|int
name|nbits
parameter_list|,
comment|/* number of bits to inspect */
name|int
modifier|*
name|first
parameter_list|,
comment|/* output: first byte offset */
name|int
modifier|*
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output: last byte offset */
end_comment

begin_comment
comment|/*  * Get a buffer for the block, return it read in.  * Long-form addressing.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_btree_read_bufl
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_fsblock_t
name|fsbno
parameter_list|,
comment|/* file system block number */
name|uint
name|lock
parameter_list|,
comment|/* lock flags for read_buf */
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|,
comment|/* buffer for fsbno */
name|int
name|refval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ref count value for buffer */
end_comment

begin_comment
comment|/*  * Get a buffer for the block, return it read in.  * Short-form addressing.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_btree_read_bufs
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_agnumber_t
name|agno
parameter_list|,
comment|/* allocation group number */
name|xfs_agblock_t
name|agbno
parameter_list|,
comment|/* allocation group block number */
name|uint
name|lock
parameter_list|,
comment|/* lock flags for read_buf */
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|,
comment|/* buffer for agno/agbno */
name|int
name|refval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ref count value for buffer */
end_comment

begin_comment
comment|/*  * Read-ahead the block, don't wait for it, don't return a buffer.  * Long-form addressing.  */
end_comment

begin_function_decl
name|void
comment|/* error */
name|xfs_btree_reada_bufl
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|xfs_fsblock_t
name|fsbno
parameter_list|,
comment|/* file system block number */
name|xfs_extlen_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* count of filesystem blocks */
end_comment

begin_comment
comment|/*  * Read-ahead the block, don't wait for it, don't return a buffer.  * Short-form addressing.  */
end_comment

begin_function_decl
name|void
comment|/* error */
name|xfs_btree_reada_bufs
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount point */
name|xfs_agnumber_t
name|agno
parameter_list|,
comment|/* allocation group number */
name|xfs_agblock_t
name|agbno
parameter_list|,
comment|/* allocation group block number */
name|xfs_extlen_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* count of filesystem blocks */
end_comment

begin_comment
comment|/*  * Read-ahead btree blocks, at the given level.  * Bits in lr are set from XFS_BTCUR_{LEFT,RIGHT}RA.  */
end_comment

begin_function_decl
name|int
comment|/* readahead block count */
name|xfs_btree_readahead_core
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|lev
parameter_list|,
comment|/* level in btree */
name|int
name|lr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* left/right bits */
end_comment

begin_function
specifier|static
specifier|inline
name|int
comment|/* readahead block count */
name|xfs_btree_readahead
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|lev
parameter_list|,
comment|/* level in btree */
name|int
name|lr
parameter_list|)
comment|/* left/right bits */
block|{
if|if
condition|(
operator|(
name|cur
operator|->
name|bc_ra
index|[
name|lev
index|]
operator||
name|lr
operator|)
operator|==
name|cur
operator|->
name|bc_ra
index|[
name|lev
index|]
condition|)
return|return
literal|0
return|;
return|return
name|xfs_btree_readahead_core
argument_list|(
name|cur
argument_list|,
name|lev
argument_list|,
name|lr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Set the buffer for level "lev" in the cursor to bp, releasing  * any previous buffer.  */
end_comment

begin_function_decl
name|void
name|xfs_btree_setbuf
parameter_list|(
name|xfs_btree_cur_t
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|lev
parameter_list|,
comment|/* level in btree */
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* new buffer to set */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/*  * Min and max functions for extlen, agblock, fileoff, and filblks types.  */
end_comment

begin_define
define|#
directive|define
name|XFS_EXTLEN_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_extlen_t)(a)< (xfs_extlen_t)(b) ? \ 		(xfs_extlen_t)(a) : (xfs_extlen_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_EXTLEN_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_extlen_t)(a)> (xfs_extlen_t)(b) ? \ 		(xfs_extlen_t)(a) : (xfs_extlen_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_AGBLOCK_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_agblock_t)(a)< (xfs_agblock_t)(b) ? \ 		(xfs_agblock_t)(a) : (xfs_agblock_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_AGBLOCK_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_agblock_t)(a)> (xfs_agblock_t)(b) ? \ 		(xfs_agblock_t)(a) : (xfs_agblock_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_FILEOFF_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_fileoff_t)(a)< (xfs_fileoff_t)(b) ? \ 		(xfs_fileoff_t)(a) : (xfs_fileoff_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_FILEOFF_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_fileoff_t)(a)> (xfs_fileoff_t)(b) ? \ 		(xfs_fileoff_t)(a) : (xfs_fileoff_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_FILBLKS_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_filblks_t)(a)< (xfs_filblks_t)(b) ? \ 		(xfs_filblks_t)(a) : (xfs_filblks_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_FILBLKS_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xfs_filblks_t)(a)> (xfs_filblks_t)(b) ? \ 		(xfs_filblks_t)(a) : (xfs_filblks_t)(b))
end_define

begin_define
define|#
directive|define
name|XFS_FSB_SANITY_CHECK
parameter_list|(
name|mp
parameter_list|,
name|fsb
parameter_list|)
define|\
value|(XFS_FSB_TO_AGNO(mp, fsb)< mp->m_sb.sb_agcount&& \ 		XFS_FSB_TO_AGBNO(mp, fsb)< mp->m_sb.sb_agblocks)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_BTREE_H__ */
end_comment

end_unit

