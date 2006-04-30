begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for FreeBSD/i386.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|"osabi.h"
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
comment|/* FreeBSD 3.0-RELEASE or later.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|i386fbsd_r_reg_offset
index|[]
init|=
block|{
literal|9
operator|*
literal|4
block|,
literal|8
operator|*
literal|4
block|,
literal|7
operator|*
literal|4
block|,
literal|6
operator|*
literal|4
block|,
comment|/* %eax, %ecx, %edx, %ebx */
literal|15
operator|*
literal|4
block|,
literal|4
operator|*
literal|4
block|,
comment|/* %esp, %ebp */
literal|3
operator|*
literal|4
block|,
literal|2
operator|*
literal|4
block|,
comment|/* %esi, %edi */
literal|12
operator|*
literal|4
block|,
literal|14
operator|*
literal|4
block|,
comment|/* %eip, %eflags */
literal|13
operator|*
literal|4
block|,
literal|16
operator|*
literal|4
block|,
comment|/* %cs, %ss */
literal|1
operator|*
literal|4
block|,
literal|0
operator|*
literal|4
block|,
operator|-
literal|1
block|,
operator|-
literal|1
comment|/* %ds, %es, %fs, %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sigtramp routine location.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|i386fbsd_sigtramp_start_addr
init|=
literal|0xbfbfdf20
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|i386fbsd_sigtramp_end_addr
init|=
literal|0xbfbfdff0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|i386fbsd_sc_reg_offset
index|[]
init|=
block|{
literal|8
operator|+
literal|14
operator|*
literal|4
block|,
comment|/* %eax */
literal|8
operator|+
literal|13
operator|*
literal|4
block|,
comment|/* %ecx */
literal|8
operator|+
literal|12
operator|*
literal|4
block|,
comment|/* %edx */
literal|8
operator|+
literal|11
operator|*
literal|4
block|,
comment|/* %ebx */
literal|8
operator|+
literal|0
operator|*
literal|4
block|,
comment|/* %esp */
literal|8
operator|+
literal|1
operator|*
literal|4
block|,
comment|/* %ebp */
literal|8
operator|+
literal|10
operator|*
literal|4
block|,
comment|/* %esi */
literal|8
operator|+
literal|9
operator|*
literal|4
block|,
comment|/* %edi */
literal|8
operator|+
literal|3
operator|*
literal|4
block|,
comment|/* %eip */
literal|8
operator|+
literal|4
operator|*
literal|4
block|,
comment|/* %eflags */
literal|8
operator|+
literal|7
operator|*
literal|4
block|,
comment|/* %cs */
literal|8
operator|+
literal|8
operator|*
literal|4
block|,
comment|/* %ss */
literal|8
operator|+
literal|6
operator|*
literal|4
block|,
comment|/* %ds */
literal|8
operator|+
literal|5
operator|*
literal|4
block|,
comment|/* %es */
literal|8
operator|+
literal|15
operator|*
literal|4
block|,
comment|/* %fs */
literal|8
operator|+
literal|16
operator|*
literal|4
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|i386fbsdaout_init_abi
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
comment|/* Obviously FreeBSD is BSD-based.  */
name|i386bsd_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* FreeBSD has a different `struct reg', and reserves some space for      its FPU emulator in `struct fpreg'.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|i386fbsd_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386fbsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|18
operator|*
literal|4
expr_stmt|;
name|tdep
operator|->
name|sizeof_fpregset
operator|=
literal|176
expr_stmt|;
comment|/* FreeBSD uses -freg-struct-return by default.  */
name|tdep
operator|->
name|struct_return
operator|=
name|reg_struct_return
expr_stmt|;
comment|/* FreeBSD uses a different memory layout.  */
name|tdep
operator|->
name|sigtramp_start
operator|=
name|i386fbsd_sigtramp_start_addr
expr_stmt|;
name|tdep
operator|->
name|sigtramp_end
operator|=
name|i386fbsd_sigtramp_end_addr
expr_stmt|;
comment|/* FreeBSD has a more complete `struct sigcontext'.  */
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|i386fbsd_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386fbsd_sc_reg_offset
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|i386fbsd_init_abi
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
comment|/* It's almost identical to FreeBSD a.out.  */
name|i386fbsdaout_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* Except that it uses ELF.  */
name|i386_elf_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* FreeBSD ELF uses SVR4-style shared libraries.  */
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

begin_comment
comment|/* FreeBSD 4.0-RELEASE or later.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|i386fbsd4_r_reg_offset
index|[]
init|=
block|{
literal|10
operator|*
literal|4
block|,
literal|9
operator|*
literal|4
block|,
literal|8
operator|*
literal|4
block|,
literal|7
operator|*
literal|4
block|,
comment|/* %eax, %ecx, %edx, %ebx */
literal|16
operator|*
literal|4
block|,
literal|5
operator|*
literal|4
block|,
comment|/* %esp, %ebp */
literal|4
operator|*
literal|4
block|,
literal|3
operator|*
literal|4
block|,
comment|/* %esi, %edi */
literal|13
operator|*
literal|4
block|,
literal|15
operator|*
literal|4
block|,
comment|/* %eip, %eflags */
literal|14
operator|*
literal|4
block|,
literal|17
operator|*
literal|4
block|,
comment|/* %cs, %ss */
literal|2
operator|*
literal|4
block|,
literal|1
operator|*
literal|4
block|,
literal|0
operator|*
literal|4
block|,
literal|18
operator|*
literal|4
comment|/* %ds, %es, %fs, %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
name|int
name|i386fbsd4_sc_reg_offset
index|[]
init|=
block|{
literal|20
operator|+
literal|11
operator|*
literal|4
block|,
comment|/* %eax */
literal|20
operator|+
literal|10
operator|*
literal|4
block|,
comment|/* %ecx */
literal|20
operator|+
literal|9
operator|*
literal|4
block|,
comment|/* %edx */
literal|20
operator|+
literal|8
operator|*
literal|4
block|,
comment|/* %ebx */
literal|20
operator|+
literal|17
operator|*
literal|4
block|,
comment|/* %esp */
literal|20
operator|+
literal|6
operator|*
literal|4
block|,
comment|/* %ebp */
literal|20
operator|+
literal|5
operator|*
literal|4
block|,
comment|/* %esi */
literal|20
operator|+
literal|4
operator|*
literal|4
block|,
comment|/* %edi */
literal|20
operator|+
literal|14
operator|*
literal|4
block|,
comment|/* %eip */
literal|20
operator|+
literal|16
operator|*
literal|4
block|,
comment|/* %eflags */
literal|20
operator|+
literal|15
operator|*
literal|4
block|,
comment|/* %cs */
literal|20
operator|+
literal|18
operator|*
literal|4
block|,
comment|/* %ss */
literal|20
operator|+
literal|3
operator|*
literal|4
block|,
comment|/* %ds */
literal|20
operator|+
literal|2
operator|*
literal|4
block|,
comment|/* %es */
literal|20
operator|+
literal|1
operator|*
literal|4
block|,
comment|/* %fs */
literal|20
operator|+
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
name|i386fbsd4_init_abi
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
comment|/* Inherit stuff from older releases.  We assume that FreeBSD      4.0-RELEASE always uses ELF.  */
name|i386fbsd_init_abi
argument_list|(
name|info
argument_list|,
name|gdbarch
argument_list|)
expr_stmt|;
comment|/* FreeBSD 4.0 introduced a new `struct reg'.  */
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|i386fbsd4_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386fbsd4_r_reg_offset
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
comment|/* FreeBSD 4.0 introduced a new `struct sigcontext'.  */
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|i386fbsd4_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386fbsd4_sc_reg_offset
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
name|_initialize_i386fbsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386fbsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_FREEBSD_AOUT
argument_list|,
name|i386fbsdaout_init_abi
argument_list|)
expr_stmt|;
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_FREEBSD_ELF
argument_list|,
name|i386fbsd4_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

