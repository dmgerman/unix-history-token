begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for OpenBSD/amd64.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
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
file|"regset.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"gdb_assert.h"
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
end_include

begin_include
include|#
directive|include
file|"amd64-tdep.h"
end_include

begin_include
include|#
directive|include
file|"i387-tdep.h"
end_include

begin_include
include|#
directive|include
file|"solib-svr4.h"
end_include

begin_comment
comment|/* Support for core dumps.  */
end_comment

begin_function
specifier|static
name|void
name|amd64obsd_supply_regset
parameter_list|(
specifier|const
name|struct
name|regset
modifier|*
name|regset
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|regnum
parameter_list|,
specifier|const
name|void
modifier|*
name|regs
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
specifier|const
name|struct
name|gdbarch_tdep
modifier|*
name|tdep
init|=
name|regset
operator|->
name|descr
decl_stmt|;
name|gdb_assert
argument_list|(
name|len
operator|>=
name|tdep
operator|->
name|sizeof_gregset
operator|+
name|I387_SIZEOF_FXSAVE
argument_list|)
expr_stmt|;
name|i386_supply_gregset
argument_list|(
name|regset
argument_list|,
name|regcache
argument_list|,
name|regnum
argument_list|,
name|regs
argument_list|,
name|tdep
operator|->
name|sizeof_gregset
argument_list|)
expr_stmt|;
name|amd64_supply_fxsave
argument_list|(
name|regcache
argument_list|,
name|regnum
argument_list|,
operator|(
name|char
operator|*
operator|)
name|regs
operator|+
name|tdep
operator|->
name|sizeof_gregset
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|const
name|struct
name|regset
modifier|*
name|amd64obsd_regset_from_core_section
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|sect_name
parameter_list|,
name|size_t
name|sect_size
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
comment|/* OpenBSD core dumps don't use seperate register sets for the      general-purpose and floating-point registers.  */
if|if
condition|(
name|strcmp
argument_list|(
name|sect_name
argument_list|,
literal|".reg"
argument_list|)
operator|==
literal|0
operator|&&
name|sect_size
operator|>=
name|tdep
operator|->
name|sizeof_gregset
operator|+
name|I387_SIZEOF_FXSAVE
condition|)
block|{
if|if
condition|(
name|tdep
operator|->
name|gregset
operator|==
name|NULL
condition|)
block|{
name|tdep
operator|->
name|gregset
operator|=
name|XMALLOC
argument_list|(
expr|struct
name|regset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|gregset
operator|->
name|descr
operator|=
name|tdep
expr_stmt|;
name|tdep
operator|->
name|gregset
operator|->
name|supply_regset
operator|=
name|amd64obsd_supply_regset
expr_stmt|;
block|}
return|return
name|tdep
operator|->
name|gregset
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Support for signal handlers.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|amd64obsd_page_size
init|=
literal|4096
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|amd64obsd_pc_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
name|CORE_ADDR
name|start_pc
init|=
operator|(
name|pc
operator|&
operator|~
operator|(
name|amd64obsd_page_size
operator|-
literal|1
operator|)
operator|)
decl_stmt|;
specifier|const
name|char
name|sigreturn
index|[]
init|=
block|{
literal|0x48
block|,
literal|0xc7
block|,
literal|0xc0
block|,
literal|0x67
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* movq $SYS_sigreturn, %rax */
literal|0xcd
block|,
literal|0x80
comment|/* int $0x80 */
block|}
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
if|if
condition|(
name|name
condition|)
return|return
literal|0
return|;
comment|/* If we can't read the instructions at START_PC, return zero.  */
name|buf
operator|=
name|alloca
argument_list|(
sizeof|sizeof
name|sigreturn
argument_list|)
expr_stmt|;
if|if
condition|(
name|target_read_memory
argument_list|(
name|start_pc
operator|+
literal|0x7
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
name|sigreturn
argument_list|)
condition|)
return|return
literal|0
return|;
comment|/* Check for sigreturn(2).  */
if|if
condition|(
name|memcmp
argument_list|(
name|buf
argument_list|,
name|sigreturn
argument_list|,
sizeof|sizeof
name|sigreturn
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Assuming NEXT_FRAME is for a frame following a BSD sigtramp    routine, return the address of the associated sigcontext structure.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|amd64obsd_sigcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
block|{
comment|/* The %rsp register points at `struct sigcontext' upon entry of a      signal trampoline.  */
return|return
name|frame_unwind_register_unsigned
argument_list|(
name|next_frame
argument_list|,
name|AMD64_RSP_REGNUM
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* OpenBSD 3.5 or later.  */
end_comment

begin_comment
comment|/* Mapping between the general-purpose registers in `struct reg'    format and GDB's register cache layout.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
name|int
name|amd64obsd_r_reg_offset
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
literal|15
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
literal|16
operator|*
literal|8
block|,
comment|/* %rip */
literal|17
operator|*
literal|8
block|,
comment|/* %eflags */
literal|18
operator|*
literal|8
block|,
comment|/* %cs */
literal|19
operator|*
literal|8
block|,
comment|/* %ss */
literal|20
operator|*
literal|8
block|,
comment|/* %ds */
literal|21
operator|*
literal|8
block|,
comment|/* %es */
literal|22
operator|*
literal|8
block|,
comment|/* %fs */
literal|23
operator|*
literal|8
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amd64obsd_sc_reg_offset
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
comment|/* %r8 ... */
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
name|amd64obsd_init_abi
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
name|amd64_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* Initialize general-purpose register set details.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|amd64obsd_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64obsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|24
operator|*
literal|8
expr_stmt|;
name|set_gdbarch_regset_from_core_section
argument_list|(
name|gdbarch
argument_list|,
name|amd64obsd_regset_from_core_section
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
name|set_gdbarch_pc_in_sigtramp
argument_list|(
name|gdbarch
argument_list|,
name|amd64obsd_pc_in_sigtramp
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sigcontext_addr
operator|=
name|amd64obsd_sigcontext_addr
expr_stmt|;
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|amd64obsd_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64obsd_sc_reg_offset
argument_list|)
expr_stmt|;
comment|/* OpenBSD uses SVR4-style shared libraries.  */
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
name|_initialize_amd64obsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_amd64obsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* The OpenBSD/amd64 native dependent code makes this assumption.  */
name|gdb_assert
argument_list|(
name|ARRAY_SIZE
argument_list|(
name|amd64obsd_r_reg_offset
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
name|GDB_OSABI_OPENBSD_ELF
argument_list|,
name|amd64obsd_init_abi
argument_list|)
expr_stmt|;
comment|/* OpenBSD uses traditional (a.out) NetBSD-style core dumps.  */
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
name|bfd_mach_x86_64
argument_list|,
name|GDB_OSABI_NETBSD_AOUT
argument_list|,
name|amd64obsd_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

