begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_AG_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_AG_H__
end_define

begin_comment
comment|/*  * Allocation group header  * This is divided into three structures, placed in sequential 512-byte  * buffers after a copy of the superblock (also in a 512-byte buffer).  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_buf
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

begin_define
define|#
directive|define
name|XFS_AGF_MAGIC
value|0x58414746
end_define

begin_comment
comment|/* 'XAGF' */
end_comment

begin_define
define|#
directive|define
name|XFS_AGI_MAGIC
value|0x58414749
end_define

begin_comment
comment|/* 'XAGI' */
end_comment

begin_define
define|#
directive|define
name|XFS_AGF_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|XFS_AGI_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|XFS_AGF_GOOD_VERSION
parameter_list|(
name|v
parameter_list|)
value|((v) == XFS_AGF_VERSION)
end_define

begin_define
define|#
directive|define
name|XFS_AGI_GOOD_VERSION
parameter_list|(
name|v
parameter_list|)
value|((v) == XFS_AGI_VERSION)
end_define

begin_comment
comment|/*  * Btree number 0 is bno, 1 is cnt.  This value gives the size of the  * arrays below.  */
end_comment

begin_define
define|#
directive|define
name|XFS_BTNUM_AGF
value|((int)XFS_BTNUM_CNTi + 1)
end_define

begin_comment
comment|/*  * The second word of agf_levels in the first a.g. overlaps the EFS  * superblock's magic number.  Since the magic numbers valid for EFS  * are> 64k, our value cannot be confused for an EFS superblock's.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_agf
block|{
comment|/* 	 * Common allocation group header information 	 */
name|__be32
name|agf_magicnum
decl_stmt|;
comment|/* magic number == XFS_AGF_MAGIC */
name|__be32
name|agf_versionnum
decl_stmt|;
comment|/* header version == XFS_AGF_VERSION */
name|__be32
name|agf_seqno
decl_stmt|;
comment|/* sequence # starting from 0 */
name|__be32
name|agf_length
decl_stmt|;
comment|/* size in blocks of a.g. */
comment|/* 	 * Freespace information 	 */
name|__be32
name|agf_roots
index|[
name|XFS_BTNUM_AGF
index|]
decl_stmt|;
comment|/* root blocks */
name|__be32
name|agf_spare0
decl_stmt|;
comment|/* spare field */
name|__be32
name|agf_levels
index|[
name|XFS_BTNUM_AGF
index|]
decl_stmt|;
comment|/* btree levels */
name|__be32
name|agf_spare1
decl_stmt|;
comment|/* spare field */
name|__be32
name|agf_flfirst
decl_stmt|;
comment|/* first freelist block's index */
name|__be32
name|agf_fllast
decl_stmt|;
comment|/* last freelist block's index */
name|__be32
name|agf_flcount
decl_stmt|;
comment|/* count of blocks in freelist */
name|__be32
name|agf_freeblks
decl_stmt|;
comment|/* total free blocks */
name|__be32
name|agf_longest
decl_stmt|;
comment|/* longest free space */
block|}
name|xfs_agf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_AGF_MAGICNUM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XFS_AGF_VERSIONNUM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XFS_AGF_SEQNO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XFS_AGF_LENGTH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XFS_AGF_ROOTS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XFS_AGF_LEVELS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XFS_AGF_FLFIRST
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XFS_AGF_FLLAST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XFS_AGF_FLCOUNT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XFS_AGF_FREEBLKS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XFS_AGF_LONGEST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XFS_AGF_NUM_BITS
value|11
end_define

begin_define
define|#
directive|define
name|XFS_AGF_ALL_BITS
value|((1<< XFS_AGF_NUM_BITS) - 1)
end_define

begin_comment
comment|/* disk block (xfs_daddr_t) in the AG */
end_comment

begin_define
define|#
directive|define
name|XFS_AGF_DADDR
parameter_list|(
name|mp
parameter_list|)
value|((xfs_daddr_t)(1<< (mp)->m_sectbb_log))
end_define

begin_define
define|#
directive|define
name|XFS_AGF_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|XFS_HDR_BLOCK(mp, XFS_AGF_DADDR(mp))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_AGF
parameter_list|(
name|bp
parameter_list|)
value|((xfs_agf_t *)XFS_BUF_PTR(bp))
end_define

begin_comment
comment|/*  * Size of the unlinked inode hash table in the agi.  */
end_comment

begin_define
define|#
directive|define
name|XFS_AGI_UNLINKED_BUCKETS
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_agi
block|{
comment|/* 	 * Common allocation group header information 	 */
name|__be32
name|agi_magicnum
decl_stmt|;
comment|/* magic number == XFS_AGI_MAGIC */
name|__be32
name|agi_versionnum
decl_stmt|;
comment|/* header version == XFS_AGI_VERSION */
name|__be32
name|agi_seqno
decl_stmt|;
comment|/* sequence # starting from 0 */
name|__be32
name|agi_length
decl_stmt|;
comment|/* size in blocks of a.g. */
comment|/* 	 * Inode information 	 * Inodes are mapped by interpreting the inode number, so no 	 * mapping data is needed here. 	 */
name|__be32
name|agi_count
decl_stmt|;
comment|/* count of allocated inodes */
name|__be32
name|agi_root
decl_stmt|;
comment|/* root of inode btree */
name|__be32
name|agi_level
decl_stmt|;
comment|/* levels in inode btree */
name|__be32
name|agi_freecount
decl_stmt|;
comment|/* number of free inodes */
name|__be32
name|agi_newino
decl_stmt|;
comment|/* new inode just allocated */
name|__be32
name|agi_dirino
decl_stmt|;
comment|/* last directory inode chunk */
comment|/* 	 * Hash table of inodes which have been unlinked but are 	 * still being referenced. 	 */
name|__be32
name|agi_unlinked
index|[
name|XFS_AGI_UNLINKED_BUCKETS
index|]
decl_stmt|;
block|}
name|xfs_agi_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_AGI_MAGICNUM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XFS_AGI_VERSIONNUM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XFS_AGI_SEQNO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XFS_AGI_LENGTH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XFS_AGI_COUNT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XFS_AGI_ROOT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XFS_AGI_LEVEL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XFS_AGI_FREECOUNT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XFS_AGI_NEWINO
value|0x00000100
end_define

begin_define
define|#
directive|define
name|XFS_AGI_DIRINO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|XFS_AGI_UNLINKED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|XFS_AGI_NUM_BITS
value|11
end_define

begin_define
define|#
directive|define
name|XFS_AGI_ALL_BITS
value|((1<< XFS_AGI_NUM_BITS) - 1)
end_define

begin_comment
comment|/* disk block (xfs_daddr_t) in the AG */
end_comment

begin_define
define|#
directive|define
name|XFS_AGI_DADDR
parameter_list|(
name|mp
parameter_list|)
value|((xfs_daddr_t)(2<< (mp)->m_sectbb_log))
end_define

begin_define
define|#
directive|define
name|XFS_AGI_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|XFS_HDR_BLOCK(mp, XFS_AGI_DADDR(mp))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_AGI
parameter_list|(
name|bp
parameter_list|)
value|((xfs_agi_t *)XFS_BUF_PTR(bp))
end_define

begin_comment
comment|/*  * The third a.g. block contains the a.g. freelist, an array  * of block pointers to blocks owned by the allocation btree code.  */
end_comment

begin_define
define|#
directive|define
name|XFS_AGFL_DADDR
parameter_list|(
name|mp
parameter_list|)
value|((xfs_daddr_t)(3<< (mp)->m_sectbb_log))
end_define

begin_define
define|#
directive|define
name|XFS_AGFL_BLOCK
parameter_list|(
name|mp
parameter_list|)
value|XFS_HDR_BLOCK(mp, XFS_AGFL_DADDR(mp))
end_define

begin_define
define|#
directive|define
name|XFS_AGFL_SIZE
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_sb.sb_sectsize / sizeof(xfs_agblock_t))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TO_AGFL
parameter_list|(
name|bp
parameter_list|)
value|((xfs_agfl_t *)XFS_BUF_PTR(bp))
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_agfl
block|{
name|xfs_agblock_t
name|agfl_bno
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually XFS_AGFL_SIZE(mp) */
block|}
name|xfs_agfl_t
typedef|;
end_typedef

begin_comment
comment|/*  * Busy block/extent entry.  Used in perag to mark blocks that have been freed  * but whose transactions aren't committed to disk yet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_perag_busy
block|{
name|xfs_agblock_t
name|busy_start
decl_stmt|;
name|xfs_extlen_t
name|busy_length
decl_stmt|;
name|struct
name|xfs_trans
modifier|*
name|busy_tp
decl_stmt|;
comment|/* transaction that did the free */
block|}
name|xfs_perag_busy_t
typedef|;
end_typedef

begin_comment
comment|/*  * Per-ag incore structure, copies of information in agf and agi,  * to improve the performance of allocation group selection.  *  * pick sizes which fit in allocation buckets well  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|32
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_PAGB_NUM_SLOTS
value|84
end_define

begin_elif
elif|#
directive|elif
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
end_elif

begin_define
define|#
directive|define
name|XFS_PAGB_NUM_SLOTS
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|xfs_perag
block|{
name|char
name|pagf_init
decl_stmt|;
comment|/* this agf's entry is initialized */
name|char
name|pagi_init
decl_stmt|;
comment|/* this agi's entry is initialized */
name|char
name|pagf_metadata
decl_stmt|;
comment|/* the agf is preferred to be metadata */
name|char
name|pagi_inodeok
decl_stmt|;
comment|/* The agi is ok for inodes */
name|__uint8_t
name|pagf_levels
index|[
name|XFS_BTNUM_AGF
index|]
decl_stmt|;
comment|/* # of levels in bno& cnt btree */
name|__uint32_t
name|pagf_flcount
decl_stmt|;
comment|/* count of blocks in freelist */
name|xfs_extlen_t
name|pagf_freeblks
decl_stmt|;
comment|/* total free blocks */
name|xfs_extlen_t
name|pagf_longest
decl_stmt|;
comment|/* longest free space */
name|xfs_agino_t
name|pagi_freecount
decl_stmt|;
comment|/* number of free inodes */
ifdef|#
directive|ifdef
name|__KERNEL__
name|lock_t
name|pagb_lock
decl_stmt|;
comment|/* lock for pagb_list */
endif|#
directive|endif
name|int
name|pagb_count
decl_stmt|;
comment|/* pagb slots in use */
name|xfs_perag_busy_t
modifier|*
name|pagb_list
decl_stmt|;
comment|/* unstable blocks */
block|}
name|xfs_perag_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_AG_MAXLEVELS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_ag_maxlevels)
end_define

begin_define
define|#
directive|define
name|XFS_MIN_FREELIST_RAW
parameter_list|(
name|bl
parameter_list|,
name|cl
parameter_list|,
name|mp
parameter_list|)
define|\
value|(MIN(bl + 1, XFS_AG_MAXLEVELS(mp)) + MIN(cl + 1, XFS_AG_MAXLEVELS(mp)))
end_define

begin_define
define|#
directive|define
name|XFS_MIN_FREELIST
parameter_list|(
name|a
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_MIN_FREELIST_RAW(		\ 		be32_to_cpu((a)->agf_levels[XFS_BTNUM_BNOi]), \ 		be32_to_cpu((a)->agf_levels[XFS_BTNUM_CNTi]), mp))
end_define

begin_define
define|#
directive|define
name|XFS_MIN_FREELIST_PAG
parameter_list|(
name|pag
parameter_list|,
name|mp
parameter_list|)
define|\
value|(XFS_MIN_FREELIST_RAW(		\ 		(uint_t)(pag)->pagf_levels[XFS_BTNUM_BNOi], \ 		(uint_t)(pag)->pagf_levels[XFS_BTNUM_CNTi], mp))
end_define

begin_define
define|#
directive|define
name|XFS_AGB_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|agno
parameter_list|,
name|agbno
parameter_list|)
define|\
value|(((xfs_fsblock_t)(agno)<< (mp)->m_sb.sb_agblklog) | (agbno))
end_define

begin_define
define|#
directive|define
name|XFS_FSB_TO_AGNO
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
define|\
value|((xfs_agnumber_t)((fsbno)>> (mp)->m_sb.sb_agblklog))
end_define

begin_define
define|#
directive|define
name|XFS_FSB_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|fsbno
parameter_list|)
define|\
value|((xfs_agblock_t)((fsbno)& XFS_MASK32LO((mp)->m_sb.sb_agblklog)))
end_define

begin_define
define|#
directive|define
name|XFS_AGB_TO_DADDR
parameter_list|(
name|mp
parameter_list|,
name|agno
parameter_list|,
name|agbno
parameter_list|)
define|\
value|((xfs_daddr_t)XFS_FSB_TO_BB(mp, \ 		(xfs_fsblock_t)(agno) * (mp)->m_sb.sb_agblocks + (agbno)))
end_define

begin_define
define|#
directive|define
name|XFS_AG_DADDR
parameter_list|(
name|mp
parameter_list|,
name|agno
parameter_list|,
name|d
parameter_list|)
value|(XFS_AGB_TO_DADDR(mp, agno, 0) + (d))
end_define

begin_comment
comment|/*  * For checking for bad ranges of xfs_daddr_t's, covering multiple  * allocation groups or a single xfs_daddr_t that's a superblock copy.  */
end_comment

begin_define
define|#
directive|define
name|XFS_AG_CHECK_DADDR
parameter_list|(
name|mp
parameter_list|,
name|d
parameter_list|,
name|len
parameter_list|)
define|\
value|((len) == 1 ? \ 	    ASSERT((d) == XFS_SB_DADDR || \ 		   XFS_DADDR_TO_AGBNO(mp, d) != XFS_SB_DADDR) : \ 	    ASSERT(XFS_DADDR_TO_AGNO(mp, d) == \ 		   XFS_DADDR_TO_AGNO(mp, (d) + (len) - 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_AG_H__ */
end_comment

end_unit

