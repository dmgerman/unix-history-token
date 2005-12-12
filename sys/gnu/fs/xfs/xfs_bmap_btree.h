begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.	 Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BMAP_BTREE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BMAP_BTREE_H__
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_MAGIC
value|0x424d4150
end_define

begin_comment
comment|/* 'BMAP' */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_btree_cur
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_btree_lblock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Bmap root header, on-disk form only.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmdr_block
block|{
name|__uint16_t
name|bb_level
decl_stmt|;
comment|/* 0 is a leaf */
name|__uint16_t
name|bb_numrecs
decl_stmt|;
comment|/* current # of data records */
block|}
name|xfs_bmdr_block_t
typedef|;
end_typedef

begin_comment
comment|/*  * Bmap btree record and extent descriptor.  * For 32-bit kernels,  *  l0:31 is an extent flag (value 1 indicates non-normal).  *  l0:0-30 and l1:9-31 are startoff.  *  l1:0-8, l2:0-31, and l3:21-31 are startblock.  *  l3:0-20 are blockcount.  * For 64-bit kernels,  *  l0:63 is an extent flag (value 1 indicates non-normal).  *  l0:9-62 are startoff.  *  l0:0-8 and l1:21-63 are startblock.  *  l1:0-20 are blockcount.  */
end_comment

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|BMBT_TOTAL_BITLEN
value|128
end_define

begin_comment
comment|/* 128 bits, 16 bytes */
end_comment

begin_define
define|#
directive|define
name|BMBT_EXNTFLAG_BITOFF
value|0
end_define

begin_define
define|#
directive|define
name|BMBT_EXNTFLAG_BITLEN
value|1
end_define

begin_define
define|#
directive|define
name|BMBT_STARTOFF_BITOFF
value|(BMBT_EXNTFLAG_BITOFF + BMBT_EXNTFLAG_BITLEN)
end_define

begin_define
define|#
directive|define
name|BMBT_STARTOFF_BITLEN
value|54
end_define

begin_define
define|#
directive|define
name|BMBT_STARTBLOCK_BITOFF
value|(BMBT_STARTOFF_BITOFF + BMBT_STARTOFF_BITLEN)
end_define

begin_define
define|#
directive|define
name|BMBT_STARTBLOCK_BITLEN
value|52
end_define

begin_define
define|#
directive|define
name|BMBT_BLOCKCOUNT_BITOFF
define|\
value|(BMBT_STARTBLOCK_BITOFF + BMBT_STARTBLOCK_BITLEN)
end_define

begin_define
define|#
directive|define
name|BMBT_BLOCKCOUNT_BITLEN
value|(BMBT_TOTAL_BITLEN - BMBT_BLOCKCOUNT_BITOFF)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BMBT_TOTAL_BITLEN
value|128
end_define

begin_comment
comment|/* 128 bits, 16 bytes */
end_comment

begin_define
define|#
directive|define
name|BMBT_EXNTFLAG_BITOFF
value|63
end_define

begin_define
define|#
directive|define
name|BMBT_EXNTFLAG_BITLEN
value|1
end_define

begin_define
define|#
directive|define
name|BMBT_STARTOFF_BITOFF
value|(BMBT_EXNTFLAG_BITOFF - BMBT_STARTOFF_BITLEN)
end_define

begin_define
define|#
directive|define
name|BMBT_STARTOFF_BITLEN
value|54
end_define

begin_define
define|#
directive|define
name|BMBT_STARTBLOCK_BITOFF
value|85
end_define

begin_comment
comment|/* 128 - 43 (other 9 is in first word) */
end_comment

begin_define
define|#
directive|define
name|BMBT_STARTBLOCK_BITLEN
value|52
end_define

begin_define
define|#
directive|define
name|BMBT_BLOCKCOUNT_BITOFF
value|64
end_define

begin_comment
comment|/* Start of second 64 bit container */
end_comment

begin_define
define|#
directive|define
name|BMBT_BLOCKCOUNT_BITLEN
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BMBT_USE_64
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmbt_rec_32
block|{
name|__uint32_t
name|l0
decl_stmt|,
name|l1
decl_stmt|,
name|l2
decl_stmt|,
name|l3
decl_stmt|;
block|}
name|xfs_bmbt_rec_32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmbt_rec_64
block|{
name|__uint64_t
name|l0
decl_stmt|,
name|l1
decl_stmt|;
block|}
name|xfs_bmbt_rec_64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_bmbt_rec_base_t
typedef|;
end_typedef

begin_comment
comment|/* use this for casts */
end_comment

begin_typedef
typedef|typedef
name|xfs_bmbt_rec_64_t
name|xfs_bmbt_rec_t
typedef|,
name|xfs_bmdr_rec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Values and macros for delayed-allocation startblock fields.  */
end_comment

begin_define
define|#
directive|define
name|STARTBLOCKVALBITS
value|17
end_define

begin_define
define|#
directive|define
name|STARTBLOCKMASKBITS
value|(15 + XFS_BIG_BLKNOS * 20)
end_define

begin_define
define|#
directive|define
name|DSTARTBLOCKMASKBITS
value|(15 + 20)
end_define

begin_define
define|#
directive|define
name|STARTBLOCKMASK
define|\
value|(((((xfs_fsblock_t)1)<< STARTBLOCKMASKBITS) - 1)<< STARTBLOCKVALBITS)
end_define

begin_define
define|#
directive|define
name|DSTARTBLOCKMASK
define|\
value|(((((xfs_dfsbno_t)1)<< DSTARTBLOCKMASKBITS) - 1)<< STARTBLOCKVALBITS)
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
name|XFSSO_ISNULLSTARTBLOCK
operator|)
end_if

begin_function_decl
name|int
name|isnullstartblock
parameter_list|(
name|xfs_fsblock_t
name|x
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
name|XFSSO_ISNULLSTARTBLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|ISNULLSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|isnullstartblock(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISNULLSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& STARTBLOCKMASK) == STARTBLOCKMASK)
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
name|XFSSO_ISNULLDSTARTBLOCK
operator|)
end_if

begin_function_decl
name|int
name|isnulldstartblock
parameter_list|(
name|xfs_dfsbno_t
name|x
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
name|XFSSO_ISNULLDSTARTBLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|ISNULLDSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|isnulldstartblock(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISNULLDSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& DSTARTBLOCKMASK) == DSTARTBLOCKMASK)
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
name|XFSSO_NULLSTARTBLOCK
operator|)
end_if

begin_function_decl
name|xfs_fsblock_t
name|nullstartblock
parameter_list|(
name|int
name|k
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
name|XFSSO_NULLSTARTBLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|NULLSTARTBLOCK
parameter_list|(
name|k
parameter_list|)
value|nullstartblock(k)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULLSTARTBLOCK
parameter_list|(
name|k
parameter_list|)
define|\
value|((ASSERT(k< (1<< STARTBLOCKVALBITS))), (STARTBLOCKMASK | (k)))
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
name|XFSSO_STARTBLOCKVAL
operator|)
end_if

begin_function_decl
name|xfs_filblks_t
name|startblockval
parameter_list|(
name|xfs_fsblock_t
name|x
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
name|XFSSO_STARTBLOCKVAL
operator|)
end_if

begin_define
define|#
directive|define
name|STARTBLOCKVAL
parameter_list|(
name|x
parameter_list|)
value|startblockval(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTBLOCKVAL
parameter_list|(
name|x
parameter_list|)
value|((xfs_filblks_t)((x)& ~STARTBLOCKMASK))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Possible extent formats.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XFS_EXTFMT_NOSTATE
init|=
literal|0
block|,
name|XFS_EXTFMT_HASSTATE
block|}
name|xfs_exntfmt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Possible extent states.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XFS_EXT_NORM
block|,
name|XFS_EXT_UNWRITTEN
block|,
name|XFS_EXT_DMAPI_OFFLINE
block|}
name|xfs_exntst_t
typedef|;
end_typedef

begin_comment
comment|/*  * Extent state and extent format macros.  */
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
name|XFSSO_XFS_EXTFMT_INODE
operator|)
end_if

begin_function_decl
name|xfs_exntfmt_t
name|xfs_extfmt_inode
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
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
name|XFSSO_XFS_EXTFMT_INODE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_EXTFMT_INODE
parameter_list|(
name|x
parameter_list|)
value|xfs_extfmt_inode(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_EXTFMT_INODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(XFS_SB_VERSION_HASEXTFLGBIT(&((x)->i_mount->m_sb)) ? \ 	XFS_EXTFMT_HASSTATE : XFS_EXTFMT_NOSTATE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISUNWRITTEN
parameter_list|(
name|x
parameter_list|)
value|((x)->br_state == XFS_EXT_UNWRITTEN)
end_define

begin_comment
comment|/*  * Incore version of above.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmbt_irec
block|{
name|xfs_fileoff_t
name|br_startoff
decl_stmt|;
comment|/* starting file offset */
name|xfs_fsblock_t
name|br_startblock
decl_stmt|;
comment|/* starting block number */
name|xfs_filblks_t
name|br_blockcount
decl_stmt|;
comment|/* number of blocks */
name|xfs_exntst_t
name|br_state
decl_stmt|;
comment|/* extent state */
block|}
name|xfs_bmbt_irec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Key structure for non-leaf levels of the tree.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_bmbt_key
block|{
name|xfs_dfiloff_t
name|br_startoff
decl_stmt|;
comment|/* starting file offset */
block|}
name|xfs_bmbt_key_t
operator|,
name|xfs_bmdr_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xfs_dfsbno_t
name|xfs_bmbt_ptr_t
typedef|,
name|xfs_bmdr_ptr_t
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
name|xfs_btree_lblock
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BUF_TO_BMBT_BLOCK
operator|)
end_if

begin_function_decl
name|xfs_bmbt_block_t
modifier|*
name|xfs_buf_to_bmbt_block
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
name|XFSSO_XFS_BUF_TO_BMBT_BLOCK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BUF_TO_BMBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_to_bmbt_block(bp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BUF_TO_BMBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_bmbt_block_t *)(XFS_BUF_PTR(bp)))
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
name|XFSSO_XFS_BMAP_RBLOCK_DSIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_rblock_dsize
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
name|XFSSO_XFS_BMAP_RBLOCK_DSIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_RBLOCK_DSIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_rblock_dsize(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_RBLOCK_DSIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|((cur)->bc_private.b.forksize)
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
name|XFSSO_XFS_BMAP_RBLOCK_ISIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_rblock_isize
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
name|XFSSO_XFS_BMAP_RBLOCK_ISIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_RBLOCK_ISIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_rblock_isize(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_RBLOCK_ISIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((int)XFS_IFORK_PTR((cur)->bc_private.b.ip, \ 			    (cur)->bc_private.b.whichfork)->if_broot_bytes)
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
name|XFSSO_XFS_BMAP_IBLOCK_SIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_iblock_size
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
name|XFSSO_XFS_BMAP_IBLOCK_SIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_IBLOCK_SIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_iblock_size(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_IBLOCK_SIZE
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
name|XFSSO_XFS_BMAP_BLOCK_DSIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_dsize
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
name|XFSSO_XFS_BMAP_BLOCK_DSIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DSIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_dsize(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DSIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BMAP_RBLOCK_DSIZE(lev,cur) : \ 		XFS_BMAP_IBLOCK_SIZE(lev,cur))
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
name|XFSSO_XFS_BMAP_BLOCK_ISIZE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_isize
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
name|XFSSO_XFS_BMAP_BLOCK_ISIZE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_ISIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_isize(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_ISIZE
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BMAP_RBLOCK_ISIZE(lev,cur) : \ 		XFS_BMAP_IBLOCK_SIZE(lev,cur))
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
name|XFSSO_XFS_BMAP_BLOCK_DMAXRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_dmaxrecs
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
name|XFSSO_XFS_BMAP_BLOCK_DMAXRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DMAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_dmaxrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DMAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BTREE_BLOCK_MAXRECS(XFS_BMAP_RBLOCK_DSIZE(lev,cur), \ 			xfs_bmdr, (lev) == 0) : \ 		((cur)->bc_mp->m_bmap_dmxr[(lev) != 0]))
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
name|XFSSO_XFS_BMAP_BLOCK_IMAXRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_imaxrecs
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
name|XFSSO_XFS_BMAP_BLOCK_IMAXRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_IMAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_imaxrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_IMAXRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BTREE_BLOCK_MAXRECS(XFS_BMAP_RBLOCK_ISIZE(lev,cur), \ 			xfs_bmbt, (lev) == 0) : \ 		((cur)->bc_mp->m_bmap_dmxr[(lev) != 0]))
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
name|XFSSO_XFS_BMAP_BLOCK_DMINRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_dminrecs
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
name|XFSSO_XFS_BMAP_BLOCK_DMINRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DMINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_dminrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_DMINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BTREE_BLOCK_MINRECS(XFS_BMAP_RBLOCK_DSIZE(lev,cur), \ 			xfs_bmdr, (lev) == 0) : \ 		((cur)->bc_mp->m_bmap_dmnr[(lev) != 0]))
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
name|XFSSO_XFS_BMAP_BLOCK_IMINRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_block_iminrecs
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
name|XFSSO_XFS_BMAP_BLOCK_IMINRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_IMINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_block_iminrecs(lev,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BLOCK_IMINRECS
parameter_list|(
name|lev
parameter_list|,
name|cur
parameter_list|)
define|\
value|((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BTREE_BLOCK_MINRECS(XFS_BMAP_RBLOCK_ISIZE(lev,cur), \ 			xfs_bmbt, (lev) == 0) : \ 		((cur)->bc_mp->m_bmap_dmnr[(lev) != 0]))
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
name|XFSSO_XFS_BMAP_REC_DADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_bmap_rec_daddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_REC_DADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_REC_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_rec_daddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_REC_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_REC_ADDR(XFS_BMAP_BLOCK_DSIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
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
name|XFSSO_XFS_BMAP_REC_IADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_bmap_rec_iaddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_REC_IADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_REC_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_rec_iaddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_REC_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_REC_ADDR(XFS_BMAP_BLOCK_ISIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
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
name|XFSSO_XFS_BMAP_KEY_DADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_key_t
modifier|*
name|xfs_bmap_key_daddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_KEY_DADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_KEY_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_key_daddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_KEY_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_KEY_ADDR(XFS_BMAP_BLOCK_DSIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
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
name|XFSSO_XFS_BMAP_KEY_IADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_key_t
modifier|*
name|xfs_bmap_key_iaddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_KEY_IADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_KEY_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_key_iaddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_KEY_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_KEY_ADDR(XFS_BMAP_BLOCK_ISIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
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
name|XFSSO_XFS_BMAP_PTR_DADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_ptr_t
modifier|*
name|xfs_bmap_ptr_daddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_PTR_DADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_PTR_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_ptr_daddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_PTR_DADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_PTR_ADDR(XFS_BMAP_BLOCK_DSIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
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
name|XFSSO_XFS_BMAP_PTR_IADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_ptr_t
modifier|*
name|xfs_bmap_ptr_iaddr
parameter_list|(
name|xfs_bmbt_block_t
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
name|XFSSO_XFS_BMAP_PTR_IADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_PTR_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
value|xfs_bmap_ptr_iaddr(bb,i,cur)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_PTR_IADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|cur
parameter_list|)
define|\
value|XFS_BTREE_PTR_ADDR(XFS_BMAP_BLOCK_ISIZE(		\ 		INT_GET((bb)->bb_level, ARCH_CONVERT), cur),	\ 		xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 			INT_GET((bb)->bb_level, ARCH_CONVERT), cur))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are to be used when we know the size of the block and  * we don't have a cursor.  */
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
name|XFSSO_XFS_BMAP_BROOT_REC_ADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_bmap_broot_rec_addr
parameter_list|(
name|xfs_bmbt_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|int
name|sz
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
name|XFSSO_XFS_BMAP_BROOT_REC_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_REC_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
value|xfs_bmap_broot_rec_addr(bb,i,sz)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_REC_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
define|\
value|XFS_BTREE_REC_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz))
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
name|XFSSO_XFS_BMAP_BROOT_KEY_ADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_key_t
modifier|*
name|xfs_bmap_broot_key_addr
parameter_list|(
name|xfs_bmbt_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|int
name|sz
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
name|XFSSO_XFS_BMAP_BROOT_KEY_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_KEY_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
value|xfs_bmap_broot_key_addr(bb,i,sz)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_KEY_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
define|\
value|XFS_BTREE_KEY_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz))
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
name|XFSSO_XFS_BMAP_BROOT_PTR_ADDR
operator|)
end_if

begin_function_decl
name|xfs_bmbt_ptr_t
modifier|*
name|xfs_bmap_broot_ptr_addr
parameter_list|(
name|xfs_bmbt_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|i
parameter_list|,
name|int
name|sz
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
name|XFSSO_XFS_BMAP_BROOT_PTR_ADDR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_PTR_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
value|xfs_bmap_broot_ptr_addr(bb,i,sz)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_PTR_ADDR
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|,
name|sz
parameter_list|)
define|\
value|XFS_BTREE_PTR_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz))
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
name|XFSSO_XFS_BMAP_BROOT_NUMRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_broot_numrecs
parameter_list|(
name|xfs_bmdr_block_t
modifier|*
name|bb
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
name|XFSSO_XFS_BMAP_BROOT_NUMRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_NUMRECS
parameter_list|(
name|bb
parameter_list|)
value|xfs_bmap_broot_numrecs(bb)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_NUMRECS
parameter_list|(
name|bb
parameter_list|)
value|(INT_GET((bb)->bb_numrecs, ARCH_CONVERT))
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
name|XFSSO_XFS_BMAP_BROOT_MAXRECS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_broot_maxrecs
parameter_list|(
name|int
name|sz
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
name|XFSSO_XFS_BMAP_BROOT_MAXRECS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_MAXRECS
parameter_list|(
name|sz
parameter_list|)
value|xfs_bmap_broot_maxrecs(sz)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_MAXRECS
parameter_list|(
name|sz
parameter_list|)
value|XFS_BTREE_BLOCK_MAXRECS(sz,xfs_bmbt,0)
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
name|XFSSO_XFS_BMAP_BROOT_SPACE_CALC
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_broot_space_calc
parameter_list|(
name|int
name|nrecs
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
name|XFSSO_XFS_BMAP_BROOT_SPACE_CALC
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
value|xfs_bmap_broot_space_calc(nrecs)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
define|\
value|((int)(sizeof(xfs_bmbt_block_t) + \ 	       ((nrecs) * (sizeof(xfs_bmbt_key_t) + sizeof(xfs_bmbt_ptr_t)))))
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
name|XFSSO_XFS_BMAP_BROOT_SPACE
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_broot_space
parameter_list|(
name|xfs_bmdr_block_t
modifier|*
name|bb
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
name|XFSSO_XFS_BMAP_BROOT_SPACE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE
parameter_list|(
name|bb
parameter_list|)
value|xfs_bmap_broot_space(bb)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE
parameter_list|(
name|bb
parameter_list|)
define|\
value|XFS_BMAP_BROOT_SPACE_CALC(INT_GET((bb)->bb_numrecs, ARCH_CONVERT))
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
name|XFSSO_XFS_BMDR_SPACE_CALC
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmdr_space_calc
parameter_list|(
name|int
name|nrecs
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
name|XFSSO_XFS_BMDR_SPACE_CALC
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMDR_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
value|xfs_bmdr_space_calc(nrecs)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMDR_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
define|\
value|((int)(sizeof(xfs_bmdr_block_t) + \ 	       ((nrecs) * (sizeof(xfs_bmbt_key_t) + sizeof(xfs_bmbt_ptr_t)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Maximum number of bmap btree levels.  */
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
name|XFSSO_XFS_BM_MAXLEVELS
operator|)
end_if

begin_function_decl
name|int
name|xfs_bm_maxlevels
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|int
name|w
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
name|XFSSO_XFS_BM_MAXLEVELS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BM_MAXLEVELS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|xfs_bm_maxlevels(mp,w)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BM_MAXLEVELS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|((mp)->m_bm_maxlevels[w])
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
name|XFSSO_XFS_BMAP_SANITY_CHECK
operator|)
end_if

begin_function_decl
name|int
name|xfs_bmap_sanity_check
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_bmbt_block_t
modifier|*
name|bb
parameter_list|,
name|int
name|level
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
name|XFSSO_XFS_BMAP_SANITY_CHECK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_BMAP_SANITY_CHECK
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|,
name|level
parameter_list|)
define|\
value|xfs_bmap_sanity_check(mp,bb,level)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BMAP_SANITY_CHECK
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|,
name|level
parameter_list|)
define|\
value|(INT_GET((bb)->bb_magic, ARCH_CONVERT) == XFS_BMAP_MAGIC&& \ 	 INT_GET((bb)->bb_level, ARCH_CONVERT) == level&& \ 	 INT_GET((bb)->bb_numrecs, ARCH_CONVERT)> 0&& \ 	 INT_GET((bb)->bb_numrecs, ARCH_CONVERT)<= (mp)->m_bmap_dmxr[(level) != 0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFS_BMBT_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Trace buffer entry types.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGBI
value|1
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGBII
value|2
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGFFFI
value|3
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGI
value|4
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGIFK
value|5
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGIFR
value|6
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_ARGIK
value|7
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_CUR
value|8
end_define

begin_define
define|#
directive|define
name|XFS_BMBT_TRACE_SIZE
value|4096
end_define

begin_comment
comment|/* size of global trace buffer */
end_comment

begin_define
define|#
directive|define
name|XFS_BMBT_KTRACE_SIZE
value|32
end_define

begin_comment
comment|/* size of per-inode trace buffer */
end_comment

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_bmbt_trace_buf
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Prototypes for xfs_bmap.c to call.  */
end_comment

begin_function_decl
name|void
name|xfs_bmdr_to_bmbt
parameter_list|(
name|xfs_bmdr_block_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_bmbt_block_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bmbt_decrement
parameter_list|(
name|struct
name|xfs_btree_cur
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
name|int
name|xfs_bmbt_delete
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_get_all
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_bmbt_block_t
modifier|*
name|xfs_bmbt_get_block
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
name|level
parameter_list|,
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_filblks_t
name|xfs_bmbt_get_blockcount
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_fsblock_t
name|xfs_bmbt_get_startblock
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_fileoff_t
name|xfs_bmbt_get_startoff
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_exntst_t
name|xfs_bmbt_get_state
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|ARCH_CONVERT
operator|!=
name|ARCH_NOCONVERT
end_if

begin_function_decl
name|void
name|xfs_bmbt_disk_get_all
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_exntst_t
name|xfs_bmbt_disk_get_state
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_filblks_t
name|xfs_bmbt_disk_get_blockcount
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_fsblock_t
name|xfs_bmbt_disk_get_startblock
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_fileoff_t
name|xfs_bmbt_disk_get_startoff
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
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
name|xfs_bmbt_disk_get_all
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|xfs_bmbt_get_all(r, s)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_state
parameter_list|(
name|r
parameter_list|)
define|\
value|xfs_bmbt_get_state(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_blockcount
parameter_list|(
name|r
parameter_list|)
define|\
value|xfs_bmbt_get_blockcount(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_startblock
parameter_list|(
name|r
parameter_list|)
define|\
value|xfs_bmbt_get_blockcount(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_startoff
parameter_list|(
name|r
parameter_list|)
define|\
value|xfs_bmbt_get_startoff(r)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|xfs_bmbt_increment
parameter_list|(
name|struct
name|xfs_btree_cur
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
name|int
name|xfs_bmbt_insert
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bmbt_insert_many
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_bmbt_rec_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_log_block
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|struct
name|xfs_buf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_log_recs
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|struct
name|xfs_buf
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
name|xfs_bmbt_lookup_eq
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bmbt_lookup_ge
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bmbt_lookup_le
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Give the bmap btree a new root block.  Copy the old broot contents  * down into a real block and make the broot point to it.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_bmbt_newroot
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
comment|/* btree cursor */
name|int
modifier|*
name|logflags
parameter_list|,
comment|/* logging flags for inode */
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return status - 0 fail */
end_comment

begin_function_decl
name|void
name|xfs_bmbt_set_all
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_set_allf
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_fileoff_t
name|o
parameter_list|,
name|xfs_fsblock_t
name|b
parameter_list|,
name|xfs_filblks_t
name|c
parameter_list|,
name|xfs_exntst_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_set_blockcount
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_filblks_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_set_startblock
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_fsblock_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_set_startoff
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_fileoff_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_set_state
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_exntst_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|ARCH_CONVERT
operator|!=
name|ARCH_NOCONVERT
end_if

begin_function_decl
name|void
name|xfs_bmbt_disk_set_all
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bmbt_disk_set_allf
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|,
name|xfs_fileoff_t
name|o
parameter_list|,
name|xfs_fsblock_t
name|b
parameter_list|,
name|xfs_filblks_t
name|c
parameter_list|,
name|xfs_exntst_t
name|v
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
name|xfs_bmbt_disk_set_all
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
define|\
value|xfs_bmbt_set_all(r, s)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_set_allf
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|v
parameter_list|)
define|\
value|xfs_bmbt_set_allf(r, o, b, c, v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|xfs_bmbt_to_bmdr
parameter_list|(
name|xfs_bmbt_block_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|xfs_bmdr_block_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bmbt_update
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|xfs_fsblock_t
parameter_list|,
name|xfs_filblks_t
parameter_list|,
name|xfs_exntst_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|XFSDEBUG
end_ifdef

begin_comment
comment|/*  * Get the data from the pointed-to record.  */
end_comment

begin_function_decl
name|int
name|xfs_bmbt_get_rec
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
parameter_list|,
name|xfs_fileoff_t
modifier|*
parameter_list|,
name|xfs_fsblock_t
modifier|*
parameter_list|,
name|xfs_filblks_t
modifier|*
parameter_list|,
name|xfs_exntst_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Search an extent list for the extent which includes block  * bno.  */
end_comment

begin_function_decl
name|xfs_bmbt_rec_t
modifier|*
name|xfs_bmap_do_search_extents
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|xfs_extnum_t
parameter_list|,
name|xfs_fileoff_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|xfs_extnum_t
modifier|*
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
parameter_list|,
name|xfs_bmbt_irec_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* __XFS_BMAP_BTREE_H__ */
end_comment

end_unit

