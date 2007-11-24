begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for NetBSD/amd64.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"gdb_assert.h"
end_include

begin_include
include|#
directive|include
file|"amd64-tdep.h"
end_include

begin_include
include|#
directive|include
file|"amd64-nat.h"
end_include

begin_comment
comment|/* Mapping between the general-purpose registers in NetBSD/amd64    `struct reg' format and GDB's register cache layout for    NetBSD/i386.     Note that most (if not all) NetBSD/amd64 registers are 64-bit,    while the NetBSD/i386 registers are all 32-bit, but since we're    little-endian we get away with that.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amd64nbsd32_r_reg_offset
index|[]
init|=
block|{
literal|14
operator|*
literal|8
block|,
comment|/* %eax */
literal|3
operator|*
literal|8
block|,
comment|/* %ecx */
literal|2
operator|*
literal|8
block|,
comment|/* %edx */
literal|13
operator|*
literal|8
block|,
comment|/* %ebx */
literal|24
operator|*
literal|8
block|,
comment|/* %esp */
literal|12
operator|*
literal|8
block|,
comment|/* %ebp */
literal|1
operator|*
literal|8
block|,
comment|/* %esi */
literal|0
operator|*
literal|8
block|,
comment|/* %edi */
literal|21
operator|*
literal|8
block|,
comment|/* %eip */
literal|23
operator|*
literal|8
block|,
comment|/* %eflags */
literal|22
operator|*
literal|8
block|,
comment|/* %cs */
literal|25
operator|*
literal|8
block|,
comment|/* %ss */
literal|18
operator|*
literal|8
block|,
comment|/* %ds */
literal|17
operator|*
literal|8
block|,
comment|/* %es */
literal|16
operator|*
literal|8
block|,
comment|/* %fs */
literal|15
operator|*
literal|8
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_amd64nbsd_nat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_amd64nbsd_nat
parameter_list|(
name|void
parameter_list|)
block|{
name|amd64_native_gregset32_reg_offset
operator|=
name|amd64nbsd32_r_reg_offset
expr_stmt|;
name|amd64_native_gregset32_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64nbsd32_r_reg_offset
argument_list|)
expr_stmt|;
name|amd64_native_gregset64_reg_offset
operator|=
name|amd64nbsd_r_reg_offset
expr_stmt|;
block|}
end_function

end_unit

