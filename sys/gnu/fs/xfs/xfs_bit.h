begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2002 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BIT_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BIT_H__
end_define

begin_comment
comment|/*  * XFS bit manipulation routines.  */
end_comment

begin_comment
comment|/*  * masks with n high/low bits set, 32-bit values& 64-bit values  */
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
name|XFSSO_XFS_MASK32HI
operator|)
end_if

begin_function_decl
name|__uint32_t
name|xfs_mask32hi
parameter_list|(
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
name|XFSSO_XFS_MASK32HI
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_MASK32HI
parameter_list|(
name|n
parameter_list|)
value|xfs_mask32hi(n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MASK32HI
parameter_list|(
name|n
parameter_list|)
value|((__uint32_t)-1<< (32 - (n)))
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
name|XFSSO_XFS_MASK64HI
operator|)
end_if

begin_function_decl
name|__uint64_t
name|xfs_mask64hi
parameter_list|(
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
name|XFSSO_XFS_MASK64HI
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_MASK64HI
parameter_list|(
name|n
parameter_list|)
value|xfs_mask64hi(n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MASK64HI
parameter_list|(
name|n
parameter_list|)
value|((__uint64_t)-1<< (64 - (n)))
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
name|XFSSO_XFS_MASK32LO
operator|)
end_if

begin_function_decl
name|__uint32_t
name|xfs_mask32lo
parameter_list|(
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
name|XFSSO_XFS_MASK32LO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_MASK32LO
parameter_list|(
name|n
parameter_list|)
value|xfs_mask32lo(n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MASK32LO
parameter_list|(
name|n
parameter_list|)
value|(((__uint32_t)1<< (n)) - 1)
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
name|XFSSO_XFS_MASK64LO
operator|)
end_if

begin_function_decl
name|__uint64_t
name|xfs_mask64lo
parameter_list|(
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
name|XFSSO_XFS_MASK64LO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_MASK64LO
parameter_list|(
name|n
parameter_list|)
value|xfs_mask64lo(n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MASK64LO
parameter_list|(
name|n
parameter_list|)
value|(((__uint64_t)1<< (n)) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get high bit set out of 32-bit argument, -1 if none set */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_highbit32
parameter_list|(
name|__uint32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get low bit set out of 64-bit argument, -1 if none set */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_lowbit64
parameter_list|(
name|__uint64_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get high bit set out of 64-bit argument, -1 if none set */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_highbit64
parameter_list|(
name|__uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Count set bits in map starting with start_bit */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_count_bits
parameter_list|(
name|uint
modifier|*
name|map
parameter_list|,
name|uint
name|size
parameter_list|,
name|uint
name|start_bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Count continuous one bits in map starting with start_bit */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_contig_bits
parameter_list|(
name|uint
modifier|*
name|map
parameter_list|,
name|uint
name|size
parameter_list|,
name|uint
name|start_bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find next set bit in map */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_next_bit
parameter_list|(
name|uint
modifier|*
name|map
parameter_list|,
name|uint
name|size
parameter_list|,
name|uint
name|start_bit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_BIT_H__ */
end_comment

end_unit

