begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_RTALLOC_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_RTALLOC_H__
end_define

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
name|XFS_IS_REALTIME_INODE
parameter_list|(
name|ip
parameter_list|)
value|((ip)->i_d.di_flags& XFS_DIFLAG_REALTIME)
end_define

begin_comment
comment|/* Min and max rt extent sizes, specified in bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_MAX_RTEXTSIZE
value|(1024 * 1024 * 1024)
end_define

begin_comment
comment|/* 1GB */
end_comment

begin_define
define|#
directive|define
name|XFS_DFL_RTEXTSIZE
value|(64 * 1024)
end_define

begin_comment
comment|/* 64KB */
end_comment

begin_define
define|#
directive|define
name|XFS_MIN_RTEXTSIZE
value|(4 * 1024)
end_define

begin_comment
comment|/* 4KB */
end_comment

begin_comment
comment|/*  * Constants for bit manipulations.  */
end_comment

begin_define
define|#
directive|define
name|XFS_NBBYLOG
value|3
end_define

begin_comment
comment|/* log2(NBBY) */
end_comment

begin_define
define|#
directive|define
name|XFS_WORDLOG
value|2
end_define

begin_comment
comment|/* log2(sizeof(xfs_rtword_t)) */
end_comment

begin_define
define|#
directive|define
name|XFS_NBWORDLOG
value|(XFS_NBBYLOG + XFS_WORDLOG)
end_define

begin_define
define|#
directive|define
name|XFS_NBWORD
value|(1<< XFS_NBWORDLOG)
end_define

begin_define
define|#
directive|define
name|XFS_WORDMASK
value|((1<< XFS_WORDLOG) - 1)
end_define

begin_define
define|#
directive|define
name|XFS_BLOCKSIZE
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_sb.sb_blocksize)
end_define

begin_define
define|#
directive|define
name|XFS_BLOCKMASK
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_blockmask)
end_define

begin_define
define|#
directive|define
name|XFS_BLOCKWSIZE
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_blockwsize)
end_define

begin_define
define|#
directive|define
name|XFS_BLOCKWMASK
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_blockwmask)
end_define

begin_comment
comment|/*  * Summary and bit manipulation macros.  */
end_comment

begin_define
define|#
directive|define
name|XFS_SUMOFFS
parameter_list|(
name|mp
parameter_list|,
name|ls
parameter_list|,
name|bb
parameter_list|)
value|((int)((ls) * (mp)->m_sb.sb_rbmblocks + (bb)))
end_define

begin_define
define|#
directive|define
name|XFS_SUMOFFSTOBLOCK
parameter_list|(
name|mp
parameter_list|,
name|s
parameter_list|)
define|\
value|(((s) * (uint)sizeof(xfs_suminfo_t))>> (mp)->m_sb.sb_blocklog)
end_define

begin_define
define|#
directive|define
name|XFS_SUMPTR
parameter_list|(
name|mp
parameter_list|,
name|bp
parameter_list|,
name|so
parameter_list|)
define|\
value|((xfs_suminfo_t *)((char *)XFS_BUF_PTR(bp) + \ 		(((so) * (uint)sizeof(xfs_suminfo_t))& XFS_BLOCKMASK(mp))))
end_define

begin_define
define|#
directive|define
name|XFS_BITTOBLOCK
parameter_list|(
name|mp
parameter_list|,
name|bi
parameter_list|)
value|((bi)>> (mp)->m_blkbit_log)
end_define

begin_define
define|#
directive|define
name|XFS_BLOCKTOBIT
parameter_list|(
name|mp
parameter_list|,
name|bb
parameter_list|)
value|((bb)<< (mp)->m_blkbit_log)
end_define

begin_define
define|#
directive|define
name|XFS_BITTOWORD
parameter_list|(
name|mp
parameter_list|,
name|bi
parameter_list|)
define|\
value|((int)(((bi)>> XFS_NBWORDLOG)& XFS_BLOCKWMASK(mp)))
end_define

begin_define
define|#
directive|define
name|XFS_RTMIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|XFS_RTMAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|XFS_RTLOBIT
parameter_list|(
name|w
parameter_list|)
value|xfs_lowbit32(w)
end_define

begin_define
define|#
directive|define
name|XFS_RTHIBIT
parameter_list|(
name|w
parameter_list|)
value|xfs_highbit32(w)
end_define

begin_if
if|#
directive|if
name|XFS_BIG_BLKNOS
end_if

begin_define
define|#
directive|define
name|XFS_RTBLOCKLOG
parameter_list|(
name|b
parameter_list|)
value|xfs_highbit64(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_RTBLOCKLOG
parameter_list|(
name|b
parameter_list|)
value|xfs_highbit32(b)
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

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_RT
end_ifdef

begin_comment
comment|/*  * Function prototypes for exported functions.  */
end_comment

begin_comment
comment|/*  * Allocate an extent in the realtime subvolume, with the usual allocation  * parameters.  The length units are all in realtime extents, as is the  * result block number.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_rtallocate_extent
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_rtblock_t
name|bno
parameter_list|,
comment|/* starting block number to allocate */
name|xfs_extlen_t
name|minlen
parameter_list|,
comment|/* minimum length to allocate */
name|xfs_extlen_t
name|maxlen
parameter_list|,
comment|/* maximum length to allocate */
name|xfs_extlen_t
modifier|*
name|len
parameter_list|,
comment|/* out: actual length allocated */
name|xfs_alloctype_t
name|type
parameter_list|,
comment|/* allocation type XFS_ALLOCTYPE... */
name|int
name|wasdel
parameter_list|,
comment|/* was a delayed allocation extent */
name|xfs_extlen_t
name|prod
parameter_list|,
comment|/* extent product factor */
name|xfs_rtblock_t
modifier|*
name|rtblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* out: start block allocated */
end_comment

begin_comment
comment|/*  * Free an extent in the realtime subvolume.  Length is expressed in  * realtime extents, as is the block number.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_rtfree_extent
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_rtblock_t
name|bno
parameter_list|,
comment|/* starting block number to free */
name|xfs_extlen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* length of extent freed */
end_comment

begin_comment
comment|/*  * Initialize realtime fields in the mount structure.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_rtmount_init
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
comment|/*  * Get the bitmap and summary inodes into the mount structure  * at mount time.  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_rtmount_inodes
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
comment|/*  * Pick an extent for allocation at the start of a new realtime file.  * Use the sequence number stored in the atime field of the bitmap inode.  * Translate this to a fraction of the rtextents, and return the product  * of rtextents and the fraction.  * The fraction sequence is 0, 1/2, 1/4, 3/4, 1/8, ..., 7/8, 1/16, ...  */
end_comment

begin_function_decl
name|int
comment|/* error */
name|xfs_rtpick_extent
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
name|xfs_extlen_t
name|len
parameter_list|,
comment|/* allocation length (rtextents) */
name|xfs_rtblock_t
modifier|*
name|pick
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* result rt extent */
end_comment

begin_comment
comment|/*  * Debug code: print out the value of a range in the bitmap.  */
end_comment

begin_function_decl
name|void
name|xfs_rtprint_range
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
name|xfs_rtblock_t
name|start
parameter_list|,
comment|/* starting block to print */
name|xfs_extlen_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* length to print */
end_comment

begin_comment
comment|/*  * Debug code: print the summary file.  */
end_comment

begin_function_decl
name|void
name|xfs_rtprint_summary
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* transaction pointer */
end_comment

begin_comment
comment|/*  * Grow the realtime area of the filesystem.  */
end_comment

begin_function_decl
name|int
name|xfs_growfs_rt
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
comment|/* file system mount structure */
name|xfs_growfs_rt_t
modifier|*
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* user supplied growfs struct */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_rtallocate_extent
parameter_list|(
name|t
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|,
name|l
parameter_list|,
name|a
parameter_list|,
name|f
parameter_list|,
name|p
parameter_list|,
name|rb
parameter_list|)
value|(ENOSYS)
end_define

begin_define
define|#
directive|define
name|xfs_rtfree_extent
parameter_list|(
name|t
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|)
value|(ENOSYS)
end_define

begin_define
define|#
directive|define
name|xfs_rtpick_extent
parameter_list|(
name|m
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|,
name|rb
parameter_list|)
value|(ENOSYS)
end_define

begin_define
define|#
directive|define
name|xfs_growfs_rt
parameter_list|(
name|mp
parameter_list|,
name|in
parameter_list|)
value|(ENOSYS)
end_define

begin_define
define|#
directive|define
name|xfs_rtmount_init
parameter_list|(
name|m
parameter_list|)
value|(((mp)->m_sb.sb_rblocks == 0)? 0 : (ENOSYS))
end_define

begin_define
define|#
directive|define
name|xfs_rtmount_inodes
parameter_list|(
name|m
parameter_list|)
value|(((mp)->m_sb.sb_rblocks == 0)? 0 : (ENOSYS))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_XFS_RT */
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
comment|/* __XFS_RTALLOC_H__ */
end_comment

end_unit

