begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ALLOC_BTREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ALLOC_BTREE_H__
end_define

begin_comment
comment|/*  * Freespace on-disk structures  */
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
comment|/*  * There are two on-disk btrees, one sorted by blockno and one sorted  * by blockcount and blockno.  All blocks look the same to make the code  * simpler; if we have time later, we'll make the optimizations.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ABTB_MAGIC
value|0x41425442
end_define

begin_comment
comment|/* 'ABTB' for bno tree */
end_comment

begin_define
define|#
directive|define
name|XFS_ABTC_MAGIC
value|0x41425443
end_define

begin_comment
comment|/* 'ABTC' for cnt tree */
end_comment

begin_comment
comment|/*  * Data record/key structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_alloc_rec
block|{
name|xfs_agblock_t
name|ar_startblock
decl_stmt|;
comment|/* starting block number */
name|xfs_extlen_t
name|ar_blockcount
decl_stmt|;
comment|/* count of free blocks */
block|}
name|xfs_alloc_rec_t
operator|,
name|xfs_alloc_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xfs_agblock_t
name|xfs_alloc_ptr_t
typedef|;
end_typedef

begin_comment
comment|/* btree pointer type */
end_comment

begin_comment
comment|/* btree block header type */
end_comment

begin_typedef
typedef|typedef
name|struct
name|xfs_btree_sblock
name|xfs_alloc_block_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BUF_TO_ALLOC_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_alloc_block_t
modifier|*
name|xfs_buf_to_alloc_block
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BUF_TO_ALLOC_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BUF_TO_ALLOC_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_to_alloc_block(bp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BUF_TO_ALLOC_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_alloc_block_t *)(XFS_BUF_PTR(bp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Real block structures have a size equal to the disk block size.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_SIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_alloc_block_size
parameter_list|(
name|int
name|lev
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_SIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_block_size(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_SIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|(1<< (cur)->bc_blocklog)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_MAXRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_alloc_block_maxrecs
parameter_list|(
name|int
name|lev
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_MAXRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_MAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_block_maxrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_MAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((cur)->bc_mp->m_alloc_mxr[lev != 0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_MINRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_alloc_block_minrecs
parameter_list|(
name|int
name|lev
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_BLOCK_MINRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_MINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_block_minrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_BLOCK_MINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((cur)->bc_mp->m_alloc_mnr[lev != 0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Minimum and maximum blocksize and sectorsize.  * The blocksize upper limit is pretty much arbitrary.  * The sectorsize upper limit is due to sizeof(sb_sectsize).  */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_BLOCKSIZE_LOG
value|9
end_define

begin_comment
comment|/* i.e. 512 bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_BLOCKSIZE_LOG
value|16
end_define

begin_comment
comment|/* i.e. 65536 bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_BLOCKSIZE
value|(1<< XFS_MIN_BLOCKSIZE_LOG)
end_define

begin_define
define|#
directive|define
name|XFS_MAX_BLOCKSIZE
value|(1<< XFS_MAX_BLOCKSIZE_LOG)
end_define

begin_define
define|#
directive|define
name|XFS_MIN_SECTORSIZE_LOG
value|9
end_define

begin_comment
comment|/* i.e. 512 bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_SECTORSIZE_LOG
value|15
end_define

begin_comment
comment|/* i.e. 32768 bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_SECTORSIZE
value|(1<< XFS_MIN_SECTORSIZE_LOG)
end_define

begin_define
define|#
directive|define
name|XFS_MAX_SECTORSIZE
value|(1<< XFS_MAX_SECTORSIZE_LOG)
end_define

begin_comment
comment|/*  * Block numbers in the AG:  * SB is sector 0, AGF is sector 1, AGI is sector 2, AGFL is sector 3.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BNO_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_bno_block
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_BNO_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BNO_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|xfs_bno_block(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BNO_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_AGFL_BLOCK(mp) + 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CNT_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_cnt_block
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_CNT_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_CNT_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|xfs_cnt_block(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_CNT_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_BNO_BLOCK(mp) + 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Record, key, and pointer address macros for btree blocks.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_REC_ADDR
operator|)
end_if

begin_function_decl
name|xfs_alloc_rec_t
modifier|*
name|xfs_alloc_rec_addr
parameter_list|(
name|xfs_alloc_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_REC_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_REC_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_rec_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_REC_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_REC_ADDR(XFS_ALLOC_BLOCK_SIZE(0,cur), xfs_alloc, bb, i, \ 		XFS_ALLOC_BLOCK_MAXRECS(0, cur))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_KEY_ADDR
operator|)
end_if

begin_function_decl
name|xfs_alloc_key_t
modifier|*
name|xfs_alloc_key_addr
parameter_list|(
name|xfs_alloc_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_KEY_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_KEY_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_key_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_KEY_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_KEY_ADDR(XFS_ALLOC_BLOCK_SIZE(1,cur), xfs_alloc, bb, i, \ 		XFS_ALLOC_BLOCK_MAXRECS(1, cur))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_PTR_ADDR
operator|)
end_if

begin_function_decl
name|xfs_alloc_ptr_t
modifier|*
name|xfs_alloc_ptr_addr
parameter_list|(
name|xfs_alloc_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_ALLOC_PTR_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_ALLOC_PTR_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_alloc_ptr_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ALLOC_PTR_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_PTR_ADDR(XFS_ALLOC_BLOCK_SIZE(1,cur), xfs_alloc, bb, i, \ 		XFS_ALLOC_BLOCK_MAXRECS(1, cur))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prototypes for externally visible routines.  */
end_comment

begin_comment
comment|/*  * Decrement cursor by one record at the level.  * For nonzero levels the leaf-ward information is untouched.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_decrement
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|level
parameter_list|,
comment|/* level in btree, 0 is leaf */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Delete the record pointed to by cur.  * The cursor refers to the place where the record was (could be inserted)  * when the operation returns.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_delete
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Get the data from the pointed-to record.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_get_rec
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
modifier|*
name|bno
parameter_list|,
comment|/* output: starting block of extent */
name|xfs_extlen_t
modifier|*
name|len
parameter_list|,
comment|/* output: length of extent */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output: success/failure */
end_comment

begin_comment
comment|/*  * Increment cursor by one record at the level.  * For nonzero levels the leaf-ward information is untouched.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_increment
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
name|level
parameter_list|,
comment|/* level in btree, 0 is leaf */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Insert the current record at the point referenced by cur.  * The cursor may be inconsistent on return if splits have been done.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_insert
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Lookup the record equal to [bno, len] in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_lookup_eq
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
name|bno
parameter_list|,
comment|/* starting block of extent */
name|xfs_extlen_t
name|len
parameter_list|,
comment|/* length of extent */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Lookup the first record greater than or equal to [bno, len]  * in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_lookup_ge
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
name|bno
parameter_list|,
comment|/* starting block of extent */
name|xfs_extlen_t
name|len
parameter_list|,
comment|/* length of extent */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Lookup the first record less than or equal to [bno, len]  * in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_lookup_le
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
name|bno
parameter_list|,
comment|/* starting block of extent */
name|xfs_extlen_t
name|len
parameter_list|,
comment|/* length of extent */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* success/failure */
end_comment

begin_comment
comment|/*  * Update the record referred to by cur, to the value given by [bno, len].  * This either works (return 0) or gets an EFSCORRUPTED error.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_update
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agblock_t
name|bno
parameter_list|,
comment|/* starting block of extent */
name|xfs_extlen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* length of extent */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ALLOC_BTREE_H__ */
end_comment

end_unit

