begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
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

begin_define
define|#
directive|define
name|XFS_MASK32HI
parameter_list|(
name|n
parameter_list|)
value|xfs_mask32hi(n)
end_define

begin_function
specifier|static
specifier|inline
name|__uint32_t
name|xfs_mask32hi
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
name|__uint32_t
operator|)
operator|-
literal|1
operator|<<
operator|(
literal|32
operator|-
operator|(
name|n
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_MASK64HI
parameter_list|(
name|n
parameter_list|)
value|xfs_mask64hi(n)
end_define

begin_function
specifier|static
specifier|inline
name|__uint64_t
name|xfs_mask64hi
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
name|__uint64_t
operator|)
operator|-
literal|1
operator|<<
operator|(
literal|64
operator|-
operator|(
name|n
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_MASK32LO
parameter_list|(
name|n
parameter_list|)
value|xfs_mask32lo(n)
end_define

begin_function
specifier|static
specifier|inline
name|__uint32_t
name|xfs_mask32lo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
operator|(
name|__uint32_t
operator|)
literal|1
operator|<<
operator|(
name|n
operator|)
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_MASK64LO
parameter_list|(
name|n
parameter_list|)
value|xfs_mask64lo(n)
end_define

begin_function
specifier|static
specifier|inline
name|__uint64_t
name|xfs_mask64lo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
operator|(
name|__uint64_t
operator|)
literal|1
operator|<<
operator|(
name|n
operator|)
operator|)
operator|-
literal|1
return|;
block|}
end_function

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

