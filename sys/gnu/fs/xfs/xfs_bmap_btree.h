begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
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
name|__be16
name|bb_level
decl_stmt|;
comment|/* 0 is a leaf */
name|__be16
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

begin_ifndef
ifndef|#
directive|ifndef
name|XFS_NATIVE_HOST
end_ifndef

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

begin_comment
comment|/* XFS_NATIVE_HOST */
end_comment

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

begin_define
define|#
directive|define
name|ISNULLSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|isnullstartblock(x)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|isnullstartblock
parameter_list|(
name|xfs_fsblock_t
name|x
parameter_list|)
block|{
return|return
operator|(
operator|(
name|x
operator|)
operator|&
name|STARTBLOCKMASK
operator|)
operator|==
name|STARTBLOCKMASK
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ISNULLDSTARTBLOCK
parameter_list|(
name|x
parameter_list|)
value|isnulldstartblock(x)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|isnulldstartblock
parameter_list|(
name|xfs_dfsbno_t
name|x
parameter_list|)
block|{
return|return
operator|(
operator|(
name|x
operator|)
operator|&
name|DSTARTBLOCKMASK
operator|)
operator|==
name|DSTARTBLOCKMASK
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NULLSTARTBLOCK
parameter_list|(
name|k
parameter_list|)
value|nullstartblock(k)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_fsblock_t
name|nullstartblock
parameter_list|(
name|int
name|k
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|k
operator|<
operator|(
literal|1
operator|<<
name|STARTBLOCKVALBITS
operator|)
argument_list|)
expr_stmt|;
return|return
name|STARTBLOCKMASK
operator||
operator|(
name|k
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|STARTBLOCKVAL
parameter_list|(
name|x
parameter_list|)
value|startblockval(x)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_filblks_t
name|startblockval
parameter_list|(
name|xfs_fsblock_t
name|x
parameter_list|)
block|{
return|return
call|(
name|xfs_filblks_t
call|)
argument_list|(
operator|(
name|x
operator|)
operator|&
operator|~
name|STARTBLOCKMASK
argument_list|)
return|;
block|}
end_function

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
block|,
name|XFS_EXT_INVALID
block|}
name|xfs_exntst_t
typedef|;
end_typedef

begin_comment
comment|/*  * Extent state and extent format macros.  */
end_comment

begin_define
define|#
directive|define
name|XFS_EXTFMT_INODE
parameter_list|(
name|x
parameter_list|)
define|\
value|(XFS_SB_VERSION_HASEXTFLGBIT(&((x)->i_mount->m_sb)) ? \ 		XFS_EXTFMT_HASSTATE : XFS_EXTFMT_NOSTATE)
end_define

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

begin_define
define|#
directive|define
name|XFS_BUF_TO_BMBT_BLOCK
parameter_list|(
name|bp
parameter_list|)
value|((xfs_bmbt_block_t *)XFS_BUF_PTR(bp))
end_define

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
value|((int)XFS_IFORK_PTR((cur)->bc_private.b.ip, \ 		    (cur)->bc_private.b.whichfork)->if_broot_bytes)
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BMAP_RBLOCK_DSIZE(lev,cur) : XFS_BMAP_IBLOCK_SIZE(lev,cur)))
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BMAP_RBLOCK_ISIZE(lev,cur) : XFS_BMAP_IBLOCK_SIZE(lev,cur)))
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 		XFS_BTREE_BLOCK_MAXRECS(XFS_BMAP_RBLOCK_DSIZE(lev,cur), \ 			xfs_bmdr, (lev) == 0) : \ 		((cur)->bc_mp->m_bmap_dmxr[(lev) != 0])))
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 			XFS_BTREE_BLOCK_MAXRECS(XFS_BMAP_RBLOCK_ISIZE(lev,cur),\ 				xfs_bmbt, (lev) == 0) : \ 			((cur)->bc_mp->m_bmap_dmxr[(lev) != 0])))
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 			XFS_BTREE_BLOCK_MINRECS(XFS_BMAP_RBLOCK_DSIZE(lev,cur),\ 				xfs_bmdr, (lev) == 0) : \ 			((cur)->bc_mp->m_bmap_dmnr[(lev) != 0])))
end_define

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
value|(((lev) == (cur)->bc_nlevels - 1 ? \ 			XFS_BTREE_BLOCK_MINRECS(XFS_BMAP_RBLOCK_ISIZE(lev,cur),\ 				xfs_bmbt, (lev) == 0) : \ 			((cur)->bc_mp->m_bmap_dmnr[(lev) != 0])))
end_define

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
value|(XFS_BTREE_REC_ADDR(XFS_BMAP_BLOCK_DSIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

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
value|(XFS_BTREE_REC_ADDR(XFS_BMAP_BLOCK_ISIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

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
value|(XFS_BTREE_KEY_ADDR(XFS_BMAP_BLOCK_DSIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

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
value|(XFS_BTREE_KEY_ADDR(XFS_BMAP_BLOCK_ISIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

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
value|(XFS_BTREE_PTR_ADDR(XFS_BMAP_BLOCK_DSIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_DMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

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
value|(XFS_BTREE_PTR_ADDR(XFS_BMAP_BLOCK_ISIZE(			\ 			be16_to_cpu((bb)->bb_level), cur),		\ 			xfs_bmbt, bb, i, XFS_BMAP_BLOCK_IMAXRECS(	\ 				be16_to_cpu((bb)->bb_level), cur)))
end_define

begin_comment
comment|/*  * These are to be used when we know the size of the block and  * we don't have a cursor.  */
end_comment

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
value|(XFS_BTREE_REC_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz)))
end_define

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
value|(XFS_BTREE_KEY_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz)))
end_define

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
value|(XFS_BTREE_PTR_ADDR(sz,xfs_bmbt,bb,i,XFS_BMAP_BROOT_MAXRECS(sz)))
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_NUMRECS
parameter_list|(
name|bb
parameter_list|)
value|be16_to_cpu((bb)->bb_numrecs)
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_MAXRECS
parameter_list|(
name|sz
parameter_list|)
value|XFS_BTREE_BLOCK_MAXRECS(sz,xfs_bmbt,0)
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
define|\
value|(int)(sizeof(xfs_bmbt_block_t) + \ 	       ((nrecs) * (sizeof(xfs_bmbt_key_t) + sizeof(xfs_bmbt_ptr_t))))
end_define

begin_define
define|#
directive|define
name|XFS_BMAP_BROOT_SPACE
parameter_list|(
name|bb
parameter_list|)
define|\
value|(XFS_BMAP_BROOT_SPACE_CALC(be16_to_cpu((bb)->bb_numrecs)))
end_define

begin_define
define|#
directive|define
name|XFS_BMDR_SPACE_CALC
parameter_list|(
name|nrecs
parameter_list|)
define|\
value|(int)(sizeof(xfs_bmdr_block_t) + \ 	       ((nrecs) * (sizeof(xfs_bmbt_key_t) + sizeof(xfs_bmbt_ptr_t))))
end_define

begin_comment
comment|/*  * Maximum number of bmap btree levels.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BM_MAXLEVELS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|((mp)->m_bm_maxlevels[(w)])
end_define

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
value|(be32_to_cpu((bb)->bb_magic) == XFS_BMAP_MAGIC&& \ 	 be16_to_cpu((bb)->bb_level) == level&& \ 	 be16_to_cpu((bb)->bb_numrecs)> 0&& \ 	 be16_to_cpu((bb)->bb_numrecs)<= (mp)->m_bmap_dmxr[(level) != 0])
end_define

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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
name|xfs_exntst_t
name|xfs_bmbt_get_state
parameter_list|(
name|xfs_bmbt_rec_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|XFS_NATIVE_HOST
end_ifndef

begin_function_decl
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
value|xfs_bmbt_get_all(r, s)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_state
parameter_list|(
name|r
parameter_list|)
value|xfs_bmbt_get_state(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_blockcount
parameter_list|(
name|r
parameter_list|)
value|xfs_bmbt_get_blockcount(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_startblock
parameter_list|(
name|r
parameter_list|)
value|xfs_bmbt_get_blockcount(r)
end_define

begin_define
define|#
directive|define
name|xfs_bmbt_disk_get_startoff
parameter_list|(
name|r
parameter_list|)
value|xfs_bmbt_get_startoff(r)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XFS_NATIVE_HOST */
end_comment

begin_function_decl
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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

begin_comment
comment|/*  * Give the bmap btree a new root block.  Copy the old broot contents  * down into a real block and make the broot point to it.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_bmbt_newroot
parameter_list|(
name|struct
name|xfs_btree_cur
modifier|*
name|cur
parameter_list|,
name|int
modifier|*
name|lflags
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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
specifier|extern
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

begin_ifndef
ifndef|#
directive|ifndef
name|XFS_NATIVE_HOST
end_ifndef

begin_function_decl
specifier|extern
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
specifier|extern
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
value|xfs_bmbt_set_allf(r, o, b, c, v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XFS_NATIVE_HOST */
end_comment

begin_function_decl
specifier|extern
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
specifier|extern
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
name|DEBUG
end_ifdef

begin_comment
comment|/*  * Get the data from the pointed-to record.  */
end_comment

begin_function_decl
specifier|extern
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

