begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for OpenBSD/i386.     Copyright 1988, 1989, 1991, 1992, 1994, 1996, 2000, 2001, 2002,    2003, 2004    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|"regset.h"
end_include

begin_include
include|#
directive|include
file|"osabi.h"
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
file|"i386-tdep.h"
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
comment|/* Support for signal handlers.  */
end_comment

begin_comment
comment|/* Since OpenBSD 3.2, the sigtramp routine is mapped at a random page    in virtual memory.  The randomness makes it somewhat tricky to    detect it, but fortunately we can rely on the fact that the start    of the sigtramp routine is page-aligned.  By the way, the mapping    is read-only, so you cannot place a breakpoint in the signal    trampoline.  */
end_comment

begin_comment
comment|/* Default page size.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|i386obsd_page_size
init|=
literal|4096
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return whether PC is in an OpenBSD sigtramp routine.  */
end_comment

begin_function
specifier|static
name|int
name|i386obsd_pc_in_sigtramp
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
name|i386obsd_page_size
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
literal|0xb8
block|,
literal|0x67
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* movl $SYS_sigreturn, %eax */
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
comment|/* Avoid reading memory from the target if possible.  If we're in a      named function, we're certainly not in a sigtramp routine      provided by the kernel.  Take synthetic function names into      account though.  */
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
operator|!=
literal|'<'
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
literal|0x14
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
operator|==
literal|0
condition|)
return|return
literal|1
return|;
comment|/* Check for a traditional BSD sigtramp routine.  */
return|return
name|i386bsd_pc_in_sigtramp
argument_list|(
name|pc
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the start address of the sigtramp routine.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386obsd_sigtramp_start
parameter_list|(
name|CORE_ADDR
name|pc
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
name|i386obsd_page_size
operator|-
literal|1
operator|)
operator|)
decl_stmt|;
if|if
condition|(
name|i386bsd_pc_in_sigtramp
argument_list|(
name|pc
argument_list|,
name|NULL
argument_list|)
condition|)
return|return
name|i386bsd_sigtramp_start
argument_list|(
name|pc
argument_list|)
return|;
return|return
name|start_pc
return|;
block|}
end_function

begin_comment
comment|/* Return the end address of the sigtramp routine.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386obsd_sigtramp_end
parameter_list|(
name|CORE_ADDR
name|pc
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
name|i386obsd_page_size
operator|-
literal|1
operator|)
operator|)
decl_stmt|;
if|if
condition|(
name|i386bsd_pc_in_sigtramp
argument_list|(
name|pc
argument_list|,
name|NULL
argument_list|)
condition|)
return|return
name|i386bsd_sigtramp_end
argument_list|(
name|pc
argument_list|)
return|;
return|return
name|start_pc
operator|+
literal|0x22
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Mapping between the general-purpose registers in `struct reg'    format and GDB's register cache layout.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|i386obsd_r_reg_offset
index|[]
init|=
block|{
literal|0
operator|*
literal|4
block|,
comment|/* %eax */
literal|1
operator|*
literal|4
block|,
comment|/* %ecx */
literal|2
operator|*
literal|4
block|,
comment|/* %edx */
literal|3
operator|*
literal|4
block|,
comment|/* %ebx */
literal|4
operator|*
literal|4
block|,
comment|/* %esp */
literal|5
operator|*
literal|4
block|,
comment|/* %ebp */
literal|6
operator|*
literal|4
block|,
comment|/* %esi */
literal|7
operator|*
literal|4
block|,
comment|/* %edi */
literal|8
operator|*
literal|4
block|,
comment|/* %eip */
literal|9
operator|*
literal|4
block|,
comment|/* %eflags */
literal|10
operator|*
literal|4
block|,
comment|/* %cs */
literal|11
operator|*
literal|4
block|,
comment|/* %ss */
literal|12
operator|*
literal|4
block|,
comment|/* %ds */
literal|13
operator|*
literal|4
block|,
comment|/* %es */
literal|14
operator|*
literal|4
block|,
comment|/* %fs */
literal|15
operator|*
literal|4
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|i386obsd_aout_supply_regset
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
name|I387_SIZEOF_FSAVE
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
name|i387_supply_fsave
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
name|i386obsd_aout_regset_from_core_section
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
comment|/* OpenBSD a.out core dumps don't use seperate register sets for the      general-purpose and floating-point registers.  */
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
name|I387_SIZEOF_FSAVE
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
name|i386obsd_aout_supply_regset
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
comment|/* Sigtramp routine location for OpenBSD 3.1 and earlier releases.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|i386obsd_sigtramp_start_addr
init|=
literal|0xbfbfdf20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|i386obsd_sigtramp_end_addr
init|=
literal|0xbfbfdff0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
name|int
name|i386obsd_sc_reg_offset
index|[
name|I386_NUM_GREGS
index|]
init|=
block|{
literal|10
operator|*
literal|4
block|,
comment|/* %eax */
literal|9
operator|*
literal|4
block|,
comment|/* %ecx */
literal|8
operator|*
literal|4
block|,
comment|/* %edx */
literal|7
operator|*
literal|4
block|,
comment|/* %ebx */
literal|14
operator|*
literal|4
block|,
comment|/* %esp */
literal|6
operator|*
literal|4
block|,
comment|/* %ebp */
literal|5
operator|*
literal|4
block|,
comment|/* %esi */
literal|4
operator|*
literal|4
block|,
comment|/* %edi */
literal|11
operator|*
literal|4
block|,
comment|/* %eip */
literal|13
operator|*
literal|4
block|,
comment|/* %eflags */
literal|12
operator|*
literal|4
block|,
comment|/* %cs */
literal|15
operator|*
literal|4
block|,
comment|/* %ss */
literal|3
operator|*
literal|4
block|,
comment|/* %ds */
literal|2
operator|*
literal|4
block|,
comment|/* %es */
literal|1
operator|*
literal|4
block|,
comment|/* %fs */
literal|0
operator|*
literal|4
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|i386obsd_init_abi
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
comment|/* Obviously OpenBSD is BSD-based.  */
name|i386bsd_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* OpenBSD has a different `struct reg'.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|i386obsd_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386obsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|16
operator|*
literal|4
expr_stmt|;
comment|/* OpenBSD uses -freg-struct-return by default.  */
name|tdep
operator|->
name|struct_return
operator|=
name|reg_struct_return
expr_stmt|;
comment|/* OpenBSD uses a different memory layout.  */
name|tdep
operator|->
name|sigtramp_start
operator|=
name|i386obsd_sigtramp_start_addr
expr_stmt|;
name|tdep
operator|->
name|sigtramp_end
operator|=
name|i386obsd_sigtramp_end_addr
expr_stmt|;
name|set_gdbarch_pc_in_sigtramp
argument_list|(
name|gdbarch
argument_list|,
name|i386obsd_pc_in_sigtramp
argument_list|)
expr_stmt|;
name|set_gdbarch_sigtramp_start
argument_list|(
name|gdbarch
argument_list|,
name|i386obsd_sigtramp_start
argument_list|)
expr_stmt|;
name|set_gdbarch_sigtramp_end
argument_list|(
name|gdbarch
argument_list|,
name|i386obsd_sigtramp_end
argument_list|)
expr_stmt|;
comment|/* OpenBSD has a `struct sigcontext' that's different from the      origional 4.3 BSD.  */
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|i386obsd_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386obsd_sc_reg_offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* OpenBSD a.out.  */
end_comment

begin_function
specifier|static
name|void
name|i386obsd_aout_init_abi
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
name|i386obsd_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* OpenBSD a.out has a single register set.  */
name|set_gdbarch_regset_from_core_section
argument_list|(
name|gdbarch
argument_list|,
name|i386obsd_aout_regset_from_core_section
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* OpenBSD ELF.  */
end_comment

begin_function
specifier|static
name|void
name|i386obsd_elf_init_abi
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
comment|/* It's still OpenBSD.  */
name|i386obsd_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* But ELF-based.  */
name|i386_elf_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* OpenBSD ELF uses SVR4-style shared libraries.  */
name|set_gdbarch_in_solib_call_trampoline
argument_list|(
name|gdbarch
argument_list|,
name|generic_in_solib_call_trampoline
argument_list|)
expr_stmt|;
name|set_solib_svr4_fetch_link_map_offsets
argument_list|(
name|gdbarch
argument_list|,
name|svr4_ilp32_fetch_link_map_offsets
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
name|_initialize_i386obsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386obsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* FIXME: kettenis/20021020: Since OpenBSD/i386 binaries are      indistingushable from NetBSD/i386 a.out binaries, building a GDB      that should support both these targets will probably not work as      expected.  */
define|#
directive|define
name|GDB_OSABI_OPENBSD_AOUT
value|GDB_OSABI_NETBSD_AOUT
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_OPENBSD_AOUT
argument_list|,
name|i386obsd_aout_init_abi
argument_list|)
expr_stmt|;
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_OPENBSD_ELF
argument_list|,
name|i386obsd_elf_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

