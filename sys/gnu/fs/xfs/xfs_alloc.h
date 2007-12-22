begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ALLOC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ALLOC_H__
end_define

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
name|xfs_perag
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Freespace allocation types.  Argument to xfs_alloc_[v]extent.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xfs_alloctype
block|{
name|XFS_ALLOCTYPE_ANY_AG
block|,
comment|/* allocate anywhere, use rotor */
name|XFS_ALLOCTYPE_FIRST_AG
block|,
comment|/* ... start at ag 0 */
name|XFS_ALLOCTYPE_START_AG
block|,
comment|/* anywhere, start in this a.g. */
name|XFS_ALLOCTYPE_THIS_AG
block|,
comment|/* anywhere in this a.g. */
name|XFS_ALLOCTYPE_START_BNO
block|,
comment|/* near this block else anywhere */
name|XFS_ALLOCTYPE_NEAR_BNO
block|,
comment|/* in this a.g. and near this block */
name|XFS_ALLOCTYPE_THIS_BNO
comment|/* at exactly this block */
block|}
name|xfs_alloctype_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for xfs_alloc_fix_freelist.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOC_FLAG_TRYLOCK
value|0x00000001
end_define

begin_comment
comment|/* use trylock for buffer locking */
end_comment

begin_comment
comment|/*  * Argument structure for xfs_alloc routines.  * This is turned into a structure to avoid having 20 arguments passed  * down several levels of the stack.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_alloc_arg
block|{
name|struct
name|xfs_trans
modifier|*
name|tp
decl_stmt|;
comment|/* transaction pointer */
name|struct
name|xfs_mount
modifier|*
name|mp
decl_stmt|;
comment|/* file system mount point */
name|struct
name|xfs_buf
modifier|*
name|agbp
decl_stmt|;
comment|/* buffer for a.g. freelist header */
name|struct
name|xfs_perag
modifier|*
name|pag
decl_stmt|;
comment|/* per-ag struct for this agno */
name|xfs_fsblock_t
name|fsbno
decl_stmt|;
comment|/* file system block number */
name|xfs_agnumber_t
name|agno
decl_stmt|;
comment|/* allocation group number */
name|xfs_agblock_t
name|agbno
decl_stmt|;
comment|/* allocation group-relative block # */
name|xfs_extlen_t
name|minlen
decl_stmt|;
comment|/* minimum size of extent */
name|xfs_extlen_t
name|maxlen
decl_stmt|;
comment|/* maximum size of extent */
name|xfs_extlen_t
name|mod
decl_stmt|;
comment|/* mod value for extent size */
name|xfs_extlen_t
name|prod
decl_stmt|;
comment|/* prod value for extent size */
name|xfs_extlen_t
name|minleft
decl_stmt|;
comment|/* min blocks must be left after us */
name|xfs_extlen_t
name|total
decl_stmt|;
comment|/* total blocks needed in xaction */
name|xfs_extlen_t
name|alignment
decl_stmt|;
comment|/* align answer to multiple of this */
name|xfs_extlen_t
name|minalignslop
decl_stmt|;
comment|/* slop for minlen+alignment calcs */
name|xfs_extlen_t
name|len
decl_stmt|;
comment|/* output: actual size of extent */
name|xfs_alloctype_t
name|type
decl_stmt|;
comment|/* allocation type XFS_ALLOCTYPE_... */
name|xfs_alloctype_t
name|otype
decl_stmt|;
comment|/* original allocation type */
name|char
name|wasdel
decl_stmt|;
comment|/* set if allocation was prev delayed */
name|char
name|wasfromfl
decl_stmt|;
comment|/* set if allocation is from freelist */
name|char
name|isfl
decl_stmt|;
comment|/* set if is freelist blocks - !acctg */
name|char
name|userdata
decl_stmt|;
comment|/* set if this is user data */
block|}
name|xfs_alloc_arg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Defines for userdata  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOC_USERDATA
value|1
end_define

begin_comment
comment|/* allocation is for user data*/
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOC_INITIAL_USER_DATA
value|2
end_define

begin_comment
comment|/* special case start of file */
end_comment

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
name|XFS_ALLOC_TRACE
argument_list|)
end_if

begin_comment
comment|/*  * Allocation tracing buffer size.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOC_TRACE_SIZE
value|4096
end_define

begin_decl_stmt
specifier|extern
name|ktrace_t
modifier|*
name|xfs_alloc_trace_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Types for alloc tracing.  */
end_comment

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_ALLOC
value|1
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_FREE
value|2
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_MODAGF
value|3
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_BUSY
value|4
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_UNBUSY
value|5
end_define

begin_define
define|#
directive|define
name|XFS_ALLOC_KTRACE_BUSYSEARCH
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compute and fill in value of m_ag_maxlevels.  */
end_comment

begin_function_decl
name|void
name|xfs_alloc_compute_maxlevels
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
comment|/*  * Get a block from the freelist.  * Returns with the buffer for the block gotten.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_get_freelist
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
name|agbp
parameter_list|,
comment|/* buffer containing the agf structure */
name|xfs_agblock_t
modifier|*
name|bnop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* block address retrieved from freelist */
end_comment

begin_comment
comment|/*  * Log the given fields from the agf structure.  */
end_comment

begin_function_decl
name|void
name|xfs_alloc_log_agf
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
comment|/* buffer for a.g. freelist header */
name|int
name|fields
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mask of fields to be logged (XFS_AGF_...) */
end_comment

begin_comment
comment|/*  * Interface for inode allocation to force the pag data to be initialized.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_pagf_init
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
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XFS_ALLOC_FLAGS_... */
end_comment

begin_comment
comment|/*  * Put the block on the freelist for the allocation group.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_put_freelist
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
name|agbp
parameter_list|,
comment|/* buffer for a.g. freelist header */
name|struct
name|xfs_buf
modifier|*
name|agflbp
parameter_list|,
comment|/* buffer for a.g. free block array */
name|xfs_agblock_t
name|bno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* block being freed */
end_comment

begin_comment
comment|/*  * Read in the allocation group header (free/alloc section).  */
end_comment

begin_function_decl
name|int
comment|/* error  */
name|xfs_alloc_read_agf
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* mount point structure */
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
name|int
name|flags
parameter_list|,
comment|/* XFS_ALLOC_FLAG_... */
name|struct
name|xfs_buf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* buffer for the ag freelist header */
end_comment

begin_comment
comment|/*  * Allocate an extent (variable-size).  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_alloc_vextent
parameter_list|(
name|xfs_alloc_arg_t
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocation argument structure */
end_comment

begin_comment
comment|/*  * Free an extent.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_free_extent
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_fsblock_t
name|bno
parameter_list|,
comment|/* starting block number of extent */
name|xfs_extlen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* length of extent */
end_comment

begin_function_decl
name|void
name|xfs_alloc_mark_busy
parameter_list|(
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
name|xfs_agnumber_t
name|agno
parameter_list|,
name|xfs_agblock_t
name|bno
parameter_list|,
name|xfs_extlen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_alloc_clear_busy
parameter_list|(
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
name|xfs_agnumber_t
name|ag
parameter_list|,
name|int
name|idx
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
comment|/* __XFS_ALLOC_H__ */
end_comment

end_unit

