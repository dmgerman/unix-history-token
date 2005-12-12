begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_MACROS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_MACROS_H__
end_define

begin_comment
comment|/*  * Set for debug kernels and simulation  * These replacements save space.  * Used in xfs_macros.c.  */
end_comment

begin_define
define|#
directive|define
name|XFS_WANT_SPACE_C
define|\
value|(!defined(_STANDALONE)&& defined(DEBUG))
end_define

begin_comment
comment|/*  * Set for debug simulation and kernel builds, but not for standalone.  * These replacements do not save space.  * Used in xfs_macros.c.  */
end_comment

begin_define
define|#
directive|define
name|XFS_WANT_FUNCS_C
define|\
value|(!defined(_STANDALONE)&& defined(DEBUG))
end_define

begin_comment
comment|/*  * Corresponding names used in .h files.  */
end_comment

begin_define
define|#
directive|define
name|XFS_WANT_SPACE
value|(XFS_WANT_SPACE_C&& !defined(XFS_MACRO_C))
end_define

begin_define
define|#
directive|define
name|XFS_WANT_FUNCS
value|(XFS_WANT_FUNCS_C&& !defined(XFS_MACRO_C))
end_define

begin_comment
comment|/*  * These are the macros that get turned into functions to save space.  */
end_comment

begin_define
define|#
directive|define
name|XFSSO_NULLSTARTBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_AGB_TO_DADDR
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_AGB_TO_FSB
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_AGINO_TO_INO
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_ALLOC_BLOCK_MINRECS
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_ATTR_SF_NEXTENTRY
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_BLOCK_DMAXRECS
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_BLOCK_IMAXRECS
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_BLOCK_IMINRECS
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_INIT
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_PTR_IADDR
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAP_SANITY_CHECK
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_BMAPI_AFLAG
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_CFORK_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DA_COOKIE_BNO
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DA_COOKIE_ENTRY
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DADDR_TO_AGBNO
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DADDR_TO_FSB
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DFORK_PTR
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DIR_SF_GET_DIRINO
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DIR_SF_NEXTENTRY
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_DIR_SF_PUT_DIRINO
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_FILBLKS_MIN
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_FSB_SANITY_CHECK
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_FSB_TO_DADDR
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_FSB_TO_DB
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IALLOC_INODES
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_ASIZE
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_DSIZE
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_NEXT_SET
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_NEXTENTS
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_IFORK_PTR
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_ILOG_FBROOT
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_ILOG_FEXT
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_INO_MASK
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_INO_TO_FSB
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_INODE_CLEAR_READ_AHEAD
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_MIN_FREELIST
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_SB_GOOD_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XFS_SB_VERSION_HASNLINK
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XLOG_GRANT_ADD_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|XFSSO_XLOG_GRANT_SUB_SPACE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_MACROS_H__ */
end_comment

end_unit

