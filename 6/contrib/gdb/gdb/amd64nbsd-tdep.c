begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for NetBSD/amd64.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"arch-utils.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"osabi.h"
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
file|"nbsd-tdep.h"
end_include

begin_include
include|#
directive|include
file|"solib-svr4.h"
end_include

begin_comment
comment|/* Support for signal handlers.  */
end_comment

begin_comment
comment|/* Assuming NEXT_FRAME is for a frame following a BSD sigtramp    routine, return the address of the associated sigcontext structure.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|amd64nbsd_sigcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
block|{
name|CORE_ADDR
name|sp
decl_stmt|;
comment|/* The stack pointer points at `struct sigcontext' upon entry of a      signal trampoline.  */
name|sp
operator|=
name|frame_unwind_register_unsigned
argument_list|(
name|next_frame
argument_list|,
name|AMD64_RSP_REGNUM
argument_list|)
expr_stmt|;
return|return
name|sp
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* NetBSD 2.0 or later.  */
end_comment

begin_comment
comment|/* Mapping between the general-purpose registers in `struct reg'    format and GDB's register cache layout.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
name|int
name|amd64nbsd_r_reg_offset
index|[]
init|=
block|{
literal|14
operator|*
literal|8
block|,
comment|/* %rax */
literal|13
operator|*
literal|8
block|,
comment|/* %rbx */
literal|3
operator|*
literal|8
block|,
comment|/* %rcx */
literal|2
operator|*
literal|8
block|,
comment|/* %rdx */
literal|1
operator|*
literal|8
block|,
comment|/* %rsi */
literal|0
operator|*
literal|8
block|,
comment|/* %rdi */
literal|12
operator|*
literal|8
block|,
comment|/* %rbp */
literal|24
operator|*
literal|8
block|,
comment|/* %rsp */
literal|4
operator|*
literal|8
block|,
comment|/* %r8 .. */
literal|5
operator|*
literal|8
block|,
literal|6
operator|*
literal|8
block|,
literal|7
operator|*
literal|8
block|,
literal|8
operator|*
literal|8
block|,
literal|9
operator|*
literal|8
block|,
literal|10
operator|*
literal|8
block|,
literal|11
operator|*
literal|8
block|,
comment|/* ... %r15 */
literal|21
operator|*
literal|8
block|,
comment|/* %rip */
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

begin_function
specifier|static
name|void
name|amd64nbsd_init_abi
parameter_list|(
name|struct
name|gdbarch_info
name|info
parameter_list|,
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
block|{
name|struct
name|gdbarch_tdep
modifier|*
name|tdep
init|=
name|gdbarch_tdep
argument_list|(
name|gdbarch
argument_list|)
decl_stmt|;
name|int
modifier|*
name|sc_reg_offset
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* Initialize general-purpose register set details first.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|amd64nbsd_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64nbsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|26
operator|*
literal|8
expr_stmt|;
name|amd64_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|jb_pc_offset
operator|=
literal|7
operator|*
literal|8
expr_stmt|;
comment|/* NetBSD has its own convention for signal trampolines.  */
name|set_gdbarch_pc_in_sigtramp
argument_list|(
name|gdbarch
argument_list|,
name|nbsd_pc_in_sigtramp
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sigcontext_addr
operator|=
name|amd64nbsd_sigcontext_addr
expr_stmt|;
comment|/* Initialize the array with register offsets in `struct      sigcontext'.  This `struct sigcontext' has an sc_mcontext member      at offset 32, and in<machine/reg.h> we have an explicit comment      saying that `struct reg' is the same as mcontext.__gregs.  */
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64nbsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|XCALLOC
argument_list|(
name|tdep
operator|->
name|sc_num_regs
argument_list|,
name|int
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|tdep
operator|->
name|sc_num_regs
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|amd64nbsd_r_reg_offset
index|[
name|i
index|]
operator|<
literal|0
condition|)
name|tdep
operator|->
name|sc_reg_offset
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
else|else
name|tdep
operator|->
name|sc_reg_offset
index|[
name|i
index|]
operator|=
literal|32
operator|+
name|amd64nbsd_r_reg_offset
index|[
name|i
index|]
expr_stmt|;
block|}
comment|/* NetBSD uses SVR4-style shared libraries.  */
name|set_solib_svr4_fetch_link_map_offsets
argument_list|(
name|gdbarch
argument_list|,
name|svr4_lp64_fetch_link_map_offsets
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_amd64nbsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_amd64nbsd_ndep
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* The NetBSD/amd64 native dependent code makes this assumption.  */
name|gdb_assert
argument_list|(
name|ARRAY_SIZE
argument_list|(
name|amd64nbsd_r_reg_offset
argument_list|)
operator|==
name|AMD64_NUM_GREGS
argument_list|)
expr_stmt|;
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
name|bfd_mach_x86_64
argument_list|,
name|GDB_OSABI_NETBSD_ELF
argument_list|,
name|amd64nbsd_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

