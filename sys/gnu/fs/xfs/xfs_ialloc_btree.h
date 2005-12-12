begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
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
name|XFSSO_XFS_INOBT_MASKN
operator|)
end_if

begin_function_decl
name|xfs_inofree_t
name|xfs_inobt_maskn
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|n
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
name|XFSSO_XFS_INOBT_MASKN
operator|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_MASKN
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|((((n)>= XFS_INODES_PER_CHUNK ? \ 		(xfs_inofree_t)0 : ((xfs_inofree_t)1<< (n))) - 1)<< (i))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_typedef
typedef|typedef
name|xfs_agblock_t
name|xfs_inobt_ptr_t
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
name|xfs_inobt_block_t
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
name|XFSSO_XFS_BUF_TO_INOBT_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_inobt_block_t
modifier|*
name|xfs_buf_to_inobt_block
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
name|XFSSO_XFS_BUF_TO_INOBT_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BUF_TO_INOBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_to_inobt_block(bp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BUF_TO_INOBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_inobt_block_t *)(XFS_BUF_PTR(bp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bit manipulations for ir_free.  */
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
name|XFSSO_XFS_INOBT_MASK
operator|)
end_if

begin_function_decl
name|xfs_inofree_t
name|xfs_inobt_mask
parameter_list|(
name|int
name|i
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
name|XFSSO_XFS_INOBT_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_MASK
parameter_list|(
name|i
parameter_list|)
value|xfs_inobt_mask(i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_MASK
parameter_list|(
name|i
parameter_list|)
value|((xfs_inofree_t)1<< (i))
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
name|XFSSO_XFS_INOBT_IS_FREE
operator|)
end_if

begin_function_decl
name|int
name|xfs_inobt_is_free
parameter_list|(
name|xfs_inobt_rec_t
modifier|*
name|rp
parameter_list|,
name|int
name|i
parameter_list|,
name|xfs_arch_t
name|arch
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
name|XFSSO_XFS_INOBT_IS_FREE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_IS_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|xfs_inobt_is_free(rp,i,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_IS_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|((INT_GET((rp)->ir_free, arch) \& XFS_INOBT_MASK(i)) != 0)
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
name|XFSSO_XFS_INOBT_SET_FREE
operator|)
end_if

begin_function_decl
name|void
name|xfs_inobt_set_free
parameter_list|(
name|xfs_inobt_rec_t
modifier|*
name|rp
parameter_list|,
name|int
name|i
parameter_list|,
name|xfs_arch_t
name|arch
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
name|XFSSO_XFS_INOBT_SET_FREE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_SET_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|xfs_inobt_set_free(rp,i,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_SET_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|(INT_MOD_EXPR((rp)->ir_free, arch, |= XFS_INOBT_MASK(i)))
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
name|XFSSO_XFS_INOBT_CLR_FREE
operator|)
end_if

begin_function_decl
name|void
name|xfs_inobt_clr_free
parameter_list|(
name|xfs_inobt_rec_t
modifier|*
name|rp
parameter_list|,
name|int
name|i
parameter_list|,
name|xfs_arch_t
name|arch
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
name|XFSSO_XFS_INOBT_CLR_FREE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_CLR_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|xfs_inobt_clr_free(rp,i,arch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_CLR_FREE
parameter_list|(
name|rp
parameter_list|,
name|i
parameter_list|,
name|arch
parameter_list|)
value|(INT_MOD_EXPR((rp)->ir_free, arch,&= ~XFS_INOBT_MASK(i)))
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
name|XFSSO_XFS_INOBT_BLOCK_SIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_inobt_block_size
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
name|XFSSO_XFS_INOBT_BLOCK_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_SIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_inobt_block_size(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

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
name|XFSSO_XFS_INOBT_BLOCK_MAXRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_inobt_block_maxrecs
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
name|XFSSO_XFS_INOBT_BLOCK_MAXRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_inobt_block_maxrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((cur)->bc_mp->m_inobt_mxr[lev != 0])
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
name|XFSSO_XFS_INOBT_BLOCK_MINRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_inobt_block_minrecs
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
name|XFSSO_XFS_INOBT_BLOCK_MINRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_inobt_block_minrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_BLOCK_MINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((cur)->bc_mp->m_inobt_mnr[lev != 0])
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
name|XFSSO_XFS_INOBT_IS_LAST_REC
operator|)
end_if

begin_function_decl
name|int
name|xfs_inobt_is_last_rec
parameter_list|(
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
name|XFSSO_XFS_INOBT_IS_LAST_REC
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INOBT_IS_LAST_REC
parameter_list|(
name|cur
parameter_list|)
value|xfs_inobt_is_last_rec(cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INOBT_IS_LAST_REC
parameter_list|(
name|cur
parameter_list|)
define|\
value|((cur)->bc_ptrs[0] == \ 		INT_GET(XFS_BUF_TO_INOBT_BLOCK((cur)->bc_bufs[0])->bb_numrecs, ARCH_CONVERT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Maximum number of inode btree levels.  */
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
name|XFSSO_XFS_IN_MAXLEVELS
operator|)
end_if

begin_function_decl
name|int
name|xfs_in_maxlevels
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
name|XFSSO_XFS_IN_MAXLEVELS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_IN_MAXLEVELS
parameter_list|(
name|mp
parameter_list|)
value|xfs_in_maxlevels(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_IN_MAXLEVELS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_in_maxlevels)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * block numbers in the AG.  */
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
name|XFSSO_XFS_IBT_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_ibt_block
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
name|XFSSO_XFS_IBT_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_IBT_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|xfs_ibt_block(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_IBT_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_CNT_BLOCK(mp) + 1))
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
name|XFSSO_XFS_PREALLOC_BLOCKS
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_prealloc_blocks
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
name|XFSSO_XFS_PREALLOC_BLOCKS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_PREALLOC_BLOCKS
parameter_list|(
name|mp
parameter_list|)
value|xfs_prealloc_blocks(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_PREALLOC_BLOCKS
parameter_list|(
name|mp
parameter_list|)
value|((xfs_agblock_t)(XFS_IBT_BLOCK(mp) + 1))
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
name|XFSSO_XFS_INOBT_REC_ADDR
operator|)
end_if

begin_function_decl
name|xfs_inobt_rec_t
modifier|*
name|xfs_inobt_rec_addr
parameter_list|(
name|xfs_inobt_block_t
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
name|XFSSO_XFS_INOBT_REC_ADDR
operator|)
end_if

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
value|xfs_inobt_rec_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

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
value|XFS_BTREE_REC_ADDR(XFS_INOBT_BLOCK_SIZE(0,cur), xfs_inobt, bb, i, \ 		XFS_INOBT_BLOCK_MAXRECS(0, cur))
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
name|XFSSO_XFS_INOBT_KEY_ADDR
operator|)
end_if

begin_function_decl
name|xfs_inobt_key_t
modifier|*
name|xfs_inobt_key_addr
parameter_list|(
name|xfs_inobt_block_t
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
name|XFSSO_XFS_INOBT_KEY_ADDR
operator|)
end_if

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
value|xfs_inobt_key_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

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
value|XFS_BTREE_KEY_ADDR(XFS_INOBT_BLOCK_SIZE(1,cur), xfs_inobt, bb, i, \ 		XFS_INOBT_BLOCK_MAXRECS(1, cur))
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
name|XFSSO_XFS_INOBT_PTR_ADDR
operator|)
end_if

begin_function_decl
name|xfs_inobt_ptr_t
modifier|*
name|xfs_inobt_ptr_addr
parameter_list|(
name|xfs_inobt_block_t
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
name|XFSSO_XFS_INOBT_PTR_ADDR
operator|)
end_if

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
value|xfs_inobt_ptr_addr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

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
value|XFS_BTREE_PTR_ADDR(XFS_INOBT_BLOCK_SIZE(1,cur), xfs_inobt, bb, i, \ 		XFS_INOBT_BLOCK_MAXRECS(1, cur))
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
name|xfs_inobt_decrement
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
name|xfs_inobt_delete
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
name|xfs_inobt_get_rec
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agino_t
modifier|*
name|ino
parameter_list|,
comment|/* output: starting inode of chunk */
name|__int32_t
modifier|*
name|fcnt
parameter_list|,
comment|/* output: number of free inodes */
name|xfs_inofree_t
modifier|*
name|free
parameter_list|,
comment|/* output: free inode mask */
name|int
modifier|*
name|stat
parameter_list|,
comment|/* output: success/failure */
name|xfs_arch_t
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output: architecture */
end_comment

begin_comment
comment|/*  * Increment cursor by one record at the level.  * For nonzero levels the leaf-ward information is untouched.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_inobt_increment
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
name|xfs_inobt_insert
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
comment|/*  * Lookup the record equal to ino in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_inobt_lookup_eq
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agino_t
name|ino
parameter_list|,
comment|/* starting inode of chunk */
name|__int32_t
name|fcnt
parameter_list|,
comment|/* free inode count */
name|xfs_inofree_t
name|free
parameter_list|,
comment|/* free inode mask */
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
comment|/*  * Lookup the first record greater than or equal to ino  * in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_inobt_lookup_ge
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agino_t
name|ino
parameter_list|,
comment|/* starting inode of chunk */
name|__int32_t
name|fcnt
parameter_list|,
comment|/* free inode count */
name|xfs_inofree_t
name|free
parameter_list|,
comment|/* free inode mask */
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
comment|/*  * Lookup the first record less than or equal to ino  * in the btree given by cur.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_inobt_lookup_le
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agino_t
name|ino
parameter_list|,
comment|/* starting inode of chunk */
name|__int32_t
name|fcnt
parameter_list|,
comment|/* free inode count */
name|xfs_inofree_t
name|free
parameter_list|,
comment|/* free inode mask */
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
comment|/*  * Update the record referred to by cur, to the value given  * by [ino, fcnt, free].  * This either works (return 0) or gets an EFSCORRUPTED error.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_inobt_update
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|xfs_agino_t
name|ino
parameter_list|,
comment|/* starting inode of chunk */
name|__int32_t
name|fcnt
parameter_list|,
comment|/* free inode count */
name|xfs_inofree_t
name|free
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free inode mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_IALLOC_BTREE_H__ */
end_comment

end_unit

