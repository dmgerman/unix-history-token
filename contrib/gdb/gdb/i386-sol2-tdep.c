begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for Solaris x86.    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"osabi.h"
end_include

begin_include
include|#
directive|include
file|"i386-tdep.h"
end_include

begin_comment
comment|/* From<ia32/sys/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|i386_sol2_gregset_reg_offset
index|[]
init|=
block|{
literal|11
operator|*
literal|4
block|,
comment|/* %eax */
literal|10
operator|*
literal|4
block|,
comment|/* %ecx */
literal|9
operator|*
literal|4
block|,
comment|/* %edx */
literal|8
operator|*
literal|4
block|,
comment|/* %ebx */
literal|17
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
literal|14
operator|*
literal|4
block|,
comment|/* %eip */
literal|16
operator|*
literal|4
block|,
comment|/* %eflags */
literal|15
operator|*
literal|4
block|,
comment|/* %cs */
literal|18
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
name|int
name|i386_sol2_pc_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
comment|/* Signal handler frames under Solaris 2 are recognized by a return      address of 0xffffffff.  */
return|return
operator|(
name|pc
operator|==
literal|0xffffffff
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Solaris doesn't have a `struct sigcontext', but it does have a    `mcontext_t' that contains the saved set of machine registers.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386_sol2_mcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
block|{
name|CORE_ADDR
name|sp
decl_stmt|,
name|ucontext_addr
decl_stmt|;
name|sp
operator|=
name|frame_unwind_register_unsigned
argument_list|(
name|next_frame
argument_list|,
name|I386_ESP_REGNUM
argument_list|)
expr_stmt|;
name|ucontext_addr
operator|=
name|get_frame_memory_unsigned
argument_list|(
name|next_frame
argument_list|,
name|sp
operator|+
literal|8
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
name|ucontext_addr
operator|+
literal|36
return|;
block|}
end_function

begin_comment
comment|/* Solaris 2.  */
end_comment

begin_function
specifier|static
name|void
name|i386_sol2_init_abi
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
comment|/* Solaris is SVR4-based.  */
name|i386_svr4_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* Solaris reserves space for its FPU emulator in `fpregset_t'.      There is also some space reserved for the registers of a Weitek      math coprocessor.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|i386_sol2_gregset_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386_sol2_gregset_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|19
operator|*
literal|4
expr_stmt|;
name|tdep
operator|->
name|sizeof_fpregset
operator|=
literal|380
expr_stmt|;
name|tdep
operator|->
name|sigcontext_addr
operator|=
name|i386_sol2_mcontext_addr
expr_stmt|;
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|tdep
operator|->
name|gregset_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|tdep
operator|->
name|gregset_num_regs
expr_stmt|;
comment|/* Signal trampolines are slightly different from SVR4.  */
name|set_gdbarch_pc_in_sigtramp
argument_list|(
name|gdbarch
argument_list|,
name|i386_sol2_pc_in_sigtramp
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_function
specifier|static
name|enum
name|gdb_osabi
name|i386_sol2_osabi_sniffer
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
comment|/* If we have a section named .SUNW_version, then it is almost      certainly Solaris 2.  */
if|if
condition|(
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
literal|".SUNW_version"
argument_list|)
condition|)
return|return
name|GDB_OSABI_SOLARIS
return|;
return|return
name|GDB_OSABI_UNKNOWN
return|;
block|}
end_function

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_i386_sol2_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386_sol2_tdep
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Register an ELF OS ABI sniffer for Solaris 2 binaries.  */
name|gdbarch_register_osabi_sniffer
argument_list|(
name|bfd_arch_i386
argument_list|,
name|bfd_target_elf_flavour
argument_list|,
name|i386_sol2_osabi_sniffer
argument_list|)
expr_stmt|;
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_SOLARIS
argument_list|,
name|i386_sol2_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

