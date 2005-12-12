begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_IALLOC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_IALLOC_H__
end_define

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dinode
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
comment|/*  * Allocation parameters for inode allocation.  */
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
name|XFSSO_XFS_IALLOC_INODES
operator|)
end_if

begin_function_decl
name|int
name|xfs_ialloc_inodes
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
name|XFSSO_XFS_IALLOC_INODES
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_IALLOC_INODES
parameter_list|(
name|mp
parameter_list|)
value|xfs_ialloc_inodes(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_IALLOC_INODES
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_ialloc_inos)
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
name|XFSSO_XFS_IALLOC_BLOCKS
operator|)
end_if

begin_function_decl
name|xfs_extlen_t
name|xfs_ialloc_blocks
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
name|XFSSO_XFS_IALLOC_BLOCKS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_IALLOC_BLOCKS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ialloc_blocks(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_IALLOC_BLOCKS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_ialloc_blks)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For small block file systems, move inodes in clusters of this size.  * When we don't have a lot of memory, however, we go a bit smaller  * to reduce the number of AGI and ialloc btree blocks we need to keep  * around for xfs_dilocate().  We choose which one to use in  * xfs_mount_int().  */
end_comment

begin_define
define|#
directive|define
name|XFS_INODE_BIG_CLUSTER_SIZE
value|8192
end_define

begin_define
define|#
directive|define
name|XFS_INODE_SMALL_CLUSTER_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|XFS_INODE_CLUSTER_SIZE
parameter_list|(
name|mp
parameter_list|)
value|(mp)->m_inode_cluster_size
end_define

begin_comment
comment|/*  * Make an inode pointer out of the buffer/offset.  */
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
name|XFSSO_XFS_MAKE_IPTR
operator|)
end_if

begin_function_decl
name|struct
name|xfs_dinode
modifier|*
name|xfs_make_iptr
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|struct
name|xfs_buf
modifier|*
name|b
parameter_list|,
name|int
name|o
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
name|XFSSO_XFS_MAKE_IPTR
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_MAKE_IPTR
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|)
value|xfs_make_iptr(mp,b,o)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MAKE_IPTR
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|)
define|\
value|((xfs_dinode_t *)(xfs_buf_offset(b, (o)<< (mp)->m_sb.sb_inodelog)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Find a free (set) bit in the inode bitmask.  */
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
name|XFSSO_XFS_IALLOC_FIND_FREE
operator|)
end_if

begin_function_decl
name|int
name|xfs_ialloc_find_free
parameter_list|(
name|xfs_inofree_t
modifier|*
name|fp
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
name|XFSSO_XFS_IALLOC_FIND_FREE
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_IALLOC_FIND_FREE
parameter_list|(
name|fp
parameter_list|)
value|xfs_ialloc_find_free(fp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_IALLOC_FIND_FREE
parameter_list|(
name|fp
parameter_list|)
value|xfs_lowbit64(*(fp))
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

begin_comment
comment|/*  * Prototypes for visible xfs_ialloc.c routines.  */
end_comment

begin_comment
comment|/*  * Allocate an inode on disk.  * Mode is used to tell whether the new inode will need space, and whether  * it is a directory.  *  * To work within the constraint of one allocation per transaction,  * xfs_dialloc() is designed to be called twice if it has to do an  * allocation to make more free inodes.  If an inode is  * available without an allocation, agbp would be set to the current  * agbp and alloc_done set to false.  * If an allocation needed to be done, agbp would be set to the  * inode header of the allocation group and alloc_done set to true.  * The caller should then commit the current transaction and allocate a new  * transaction.  xfs_dialloc() should then be called again with  * the agbp value returned from the previous call.  *  * Once we successfully pick an inode its number is returned and the  * on-disk data structures are updated.  The inode itself is not read  * in, since doing so would break ordering constraints with xfs_reclaim.  *  * *agbp should be set to NULL on the first call, *alloc_done set to FALSE.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_dialloc
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_ino_t
name|parent
parameter_list|,
comment|/* parent inode (directory) */
name|mode_t
name|mode
parameter_list|,
comment|/* mode bits for new inode */
name|int
name|okalloc
parameter_list|,
comment|/* ok to allocate more space */
name|struct
name|xfs_buf
modifier|*
modifier|*
name|agbp
parameter_list|,
comment|/* buf for a.g. inode header */
name|boolean_t
modifier|*
name|alloc_done
parameter_list|,
comment|/* an allocation was done to replenish 					   the free inodes */
name|xfs_ino_t
modifier|*
name|inop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* inode number allocated */
end_comment

begin_comment
comment|/*  * Free disk inode.  Carefully avoids touching the incore inode, all  * manipulations incore are the caller's responsibility.  * The on-disk inode is not changed by this operation, only the  * btree (free inode mask) is changed.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_difree
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_ino_t
name|inode
parameter_list|,
comment|/* inode to be freed */
name|struct
name|xfs_bmap_free
modifier|*
name|flist
parameter_list|,
comment|/* extents to free */
name|int
modifier|*
name|delete
parameter_list|,
comment|/* set if inode cluster was deleted */
name|xfs_ino_t
modifier|*
name|first_ino
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* first inode in deleted cluster */
end_comment

begin_comment
comment|/*  * Return the location of the inode in bno/len/off,  * for mapping it into a buffer.  */
end_comment

begin_function_decl
name|int
name|xfs_dilocate
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount structure */
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_ino_t
name|ino
parameter_list|,
comment|/* inode to locate */
name|xfs_fsblock_t
modifier|*
name|bno
parameter_list|,
comment|/* output: block containing inode */
name|int
modifier|*
name|len
parameter_list|,
comment|/* output: num blocks in cluster*/
name|int
modifier|*
name|off
parameter_list|,
comment|/* output: index in block of inode */
name|uint
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* flags for inode btree lookup */
end_comment

begin_comment
comment|/*  * Compute and fill in value of m_in_maxlevels.  */
end_comment

begin_function_decl
name|void
name|xfs_ialloc_compute_maxlevels
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* file system mount structure */
end_comment

begin_comment
comment|/*  * Log specified fields for the ag hdr (inode section)  */
end_comment

begin_function_decl
name|void
name|xfs_ialloc_log_agi
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|,
comment|/* allocation group header buffer */
name|int
name|fields
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bitmask of fields to log */
end_comment

begin_comment
comment|/*  * Read in the allocation group header (inode allocation section)  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_ialloc_read_agi
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount structure */
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
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocation group hdr buf */
end_comment

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
comment|/* __XFS_IALLOC_H__ */
end_comment

end_unit

