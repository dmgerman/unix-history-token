begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_TRANS_SPACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_TRANS_SPACE_H__
end_define

begin_comment
comment|/*  * Components of space reservations.  */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_CONTIG_EXTENTS_PER_BLOCK
parameter_list|(
name|mp
parameter_list|)
define|\
value|(((mp)->m_alloc_mxr[0]) - ((mp)->m_alloc_mnr[0]))
end_define

begin_define
define|#
directive|define
name|XFS_EXTENTADD_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|(XFS_BM_MAXLEVELS(mp,w) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_NEXTENTADD_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|,
name|w
parameter_list|)
define|\
value|(((b + XFS_MAX_CONTIG_EXTENTS_PER_BLOCK(mp) - 1) / \ 	  XFS_MAX_CONTIG_EXTENTS_PER_BLOCK(mp)) * \ 	  XFS_EXTENTADD_SPACE_RES(mp,w))
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_1B
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|((w) == XFS_DATA_FORK ? (mp)->m_dirblkfsbs : 1)
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_DBS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|(XFS_DA_NODE_MAXDEPTH + \ 	 ((XFS_DIR_IS_V2(mp)&& (w) == XFS_DATA_FORK) ? 2 : 0))
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_BLOCKS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|(XFS_DAENTER_1B(mp,w) * XFS_DAENTER_DBS(mp,w))
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_BMAP1B
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|XFS_NEXTENTADD_SPACE_RES(mp, XFS_DAENTER_1B(mp, w), w)
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_BMAPS
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|(XFS_DAENTER_DBS(mp,w) * XFS_DAENTER_BMAP1B(mp,w))
end_define

begin_define
define|#
directive|define
name|XFS_DAENTER_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
define|\
value|(XFS_DAENTER_BLOCKS(mp,w) + XFS_DAENTER_BMAPS(mp,w))
end_define

begin_define
define|#
directive|define
name|XFS_DAREMOVE_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|w
parameter_list|)
value|XFS_DAENTER_BMAPS(mp,w)
end_define

begin_define
define|#
directive|define
name|XFS_DIRENTER_MAX_SPLIT
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|(((mp)->m_sb.sb_blocksize == 512&& \ 	  XFS_DIR_IS_V1(mp)&& \ 	  (nl)>= XFS_DIR_LEAF_CAN_DOUBLE_SPLIT_LEN) ? 2 : 1)
end_define

begin_define
define|#
directive|define
name|XFS_DIRENTER_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|(XFS_DAENTER_SPACE_RES(mp, XFS_DATA_FORK) * \ 	 XFS_DIRENTER_MAX_SPLIT(mp,nl))
end_define

begin_define
define|#
directive|define
name|XFS_DIRREMOVE_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DAREMOVE_SPACE_RES(mp, XFS_DATA_FORK)
end_define

begin_define
define|#
directive|define
name|XFS_IALLOC_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(XFS_IALLOC_BLOCKS(mp) + XFS_IN_MAXLEVELS(mp)-1)
end_define

begin_comment
comment|/*  * Space reservation values for various transactions.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ADDAFORK_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|((mp)->m_dirblkfsbs + \ 	 (XFS_DIR_IS_V1(mp) ? 0 : XFS_DAENTER_BMAP1B(mp, XFS_DATA_FORK)))
end_define

begin_define
define|#
directive|define
name|XFS_ATTRRM_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DAREMOVE_SPACE_RES(mp, XFS_ATTR_FORK)
end_define

begin_comment
comment|/* This macro is not used - see inline code in xfs_attr_set */
end_comment

begin_define
define|#
directive|define
name|XFS_ATTRSET_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|v
parameter_list|)
define|\
value|(XFS_DAENTER_SPACE_RES(mp, XFS_ATTR_FORK) + XFS_B_TO_FSB(mp, v))
end_define

begin_define
define|#
directive|define
name|XFS_CREATE_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|(XFS_IALLOC_SPACE_RES(mp) + XFS_DIRENTER_SPACE_RES(mp,nl))
end_define

begin_define
define|#
directive|define
name|XFS_DIOSTRAT_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|v
parameter_list|)
define|\
value|(XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK) + (v))
end_define

begin_define
define|#
directive|define
name|XFS_GROWFS_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(2 * XFS_AG_MAXLEVELS(mp))
end_define

begin_define
define|#
directive|define
name|XFS_GROWFSRT_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|)
define|\
value|((b) + XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK))
end_define

begin_define
define|#
directive|define
name|XFS_LINK_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|XFS_DIRENTER_SPACE_RES(mp,nl)
end_define

begin_define
define|#
directive|define
name|XFS_MKDIR_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|(XFS_IALLOC_SPACE_RES(mp) + XFS_DIRENTER_SPACE_RES(mp,nl))
end_define

begin_define
define|#
directive|define
name|XFS_QM_DQALLOC_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|(XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK) + \ 	 XFS_DQUOT_CLUSTER_SIZE_FSB)
end_define

begin_define
define|#
directive|define
name|XFS_QM_QINOCREATE_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_IALLOC_SPACE_RES(mp)
end_define

begin_define
define|#
directive|define
name|XFS_REMOVE_SPACE_RES
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DIRREMOVE_SPACE_RES(mp)
end_define

begin_define
define|#
directive|define
name|XFS_RENAME_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|)
define|\
value|(XFS_DIRREMOVE_SPACE_RES(mp) + XFS_DIRENTER_SPACE_RES(mp,nl))
end_define

begin_define
define|#
directive|define
name|XFS_SYMLINK_SPACE_RES
parameter_list|(
name|mp
parameter_list|,
name|nl
parameter_list|,
name|b
parameter_list|)
define|\
value|(XFS_IALLOC_SPACE_RES(mp) + XFS_DIRENTER_SPACE_RES(mp,nl) + (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_TRANS_SPACE_H__ */
end_comment

end_unit

