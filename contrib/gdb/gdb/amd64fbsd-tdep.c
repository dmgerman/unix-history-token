begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for FreeBSD/amd64.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|"osabi.h"
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
name|amd64fbsd_sigcontext_addr
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
comment|/* The `struct sigcontext' (which really is an `ucontext_t' on      FreeBSD/amd64) lives at a fixed offset in the signal frame.  See<machine/sigframe.h>.  */
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
operator|+
literal|16
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* FreeBSD 5.1-RELEASE or later.  */
end_comment

begin_comment
comment|/* Mapping between the general-purpose registers in `struct reg'    format and GDB's register cache layout.     Note that some registers are 32-bit, but since we're little-endian    we get away with that.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amd64fbsd_r_reg_offset
index|[]
init|=
block|{
literal|14
operator|*
literal|8
block|,
comment|/* %rax */
literal|11
operator|*
literal|8
block|,
comment|/* %rbx */
literal|13
operator|*
literal|8
block|,
comment|/* %rcx */
literal|12
operator|*
literal|8
block|,
comment|/* %rdx */
literal|9
operator|*
literal|8
block|,
comment|/* %rsi */
literal|8
operator|*
literal|8
block|,
comment|/* %rdi */
literal|10
operator|*
literal|8
block|,
comment|/* %rbp */
literal|20
operator|*
literal|8
block|,
comment|/* %rsp */
literal|7
operator|*
literal|8
block|,
comment|/* %r8 ... */
literal|6
operator|*
literal|8
block|,
literal|5
operator|*
literal|8
block|,
literal|4
operator|*
literal|8
block|,
literal|3
operator|*
literal|8
block|,
literal|2
operator|*
literal|8
block|,
literal|1
operator|*
literal|8
block|,
literal|0
operator|*
literal|8
block|,
comment|/* ... %r15 */
literal|17
operator|*
literal|8
block|,
comment|/* %rip */
literal|19
operator|*
literal|8
block|,
comment|/* %eflags */
literal|18
operator|*
literal|8
block|,
comment|/* %cs */
literal|21
operator|*
literal|8
block|,
comment|/* %ss */
operator|-
literal|1
block|,
comment|/* %ds */
operator|-
literal|1
block|,
comment|/* %es */
operator|-
literal|1
block|,
comment|/* %fs */
operator|-
literal|1
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Location of the signal trampoline.  */
end_comment

begin_decl_stmt
name|CORE_ADDR
name|amd64fbsd_sigtramp_start_addr
init|=
literal|0x7fffffffffc0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CORE_ADDR
name|amd64fbsd_sigtramp_end_addr
init|=
literal|0x7fffffffffe0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
name|int
name|amd64fbsd_sc_reg_offset
index|[]
init|=
block|{
literal|24
operator|+
literal|6
operator|*
literal|8
block|,
comment|/* %rax */
literal|24
operator|+
literal|7
operator|*
literal|8
block|,
comment|/* %rbx */
literal|24
operator|+
literal|3
operator|*
literal|8
block|,
comment|/* %rcx */
literal|24
operator|+
literal|2
operator|*
literal|8
block|,
comment|/* %rdx */
literal|24
operator|+
literal|1
operator|*
literal|8
block|,
comment|/* %rsi */
literal|24
operator|+
literal|0
operator|*
literal|8
block|,
comment|/* %rdi */
literal|24
operator|+
literal|8
operator|*
literal|8
block|,
comment|/* %rbp */
literal|24
operator|+
literal|22
operator|*
literal|8
block|,
comment|/* %rsp */
literal|24
operator|+
literal|4
operator|*
literal|8
block|,
comment|/* %r8 ... */
literal|24
operator|+
literal|5
operator|*
literal|8
block|,
literal|24
operator|+
literal|9
operator|*
literal|8
block|,
literal|24
operator|+
literal|10
operator|*
literal|8
block|,
literal|24
operator|+
literal|11
operator|*
literal|8
block|,
literal|24
operator|+
literal|12
operator|*
literal|8
block|,
literal|24
operator|+
literal|13
operator|*
literal|8
block|,
literal|24
operator|+
literal|14
operator|*
literal|8
block|,
comment|/* ... %r15 */
literal|24
operator|+
literal|19
operator|*
literal|8
block|,
comment|/* %rip */
literal|24
operator|+
literal|21
operator|*
literal|8
block|,
comment|/* %eflags */
literal|24
operator|+
literal|20
operator|*
literal|8
block|,
comment|/* %cs */
literal|24
operator|+
literal|23
operator|*
literal|8
block|,
comment|/* %ss */
operator|-
literal|1
block|,
comment|/* %ds */
operator|-
literal|1
block|,
comment|/* %es */
operator|-
literal|1
block|,
comment|/* %fs */
operator|-
literal|1
comment|/* %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|amd64fbsd_init_abi
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
name|tdep
operator|->
name|gregset_reg_offset
operator|=
name|amd64fbsd_r_reg_offset
expr_stmt|;
name|tdep
operator|->
name|gregset_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64fbsd_r_reg_offset
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|sizeof_gregset
operator|=
literal|22
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
name|sigtramp_start
operator|=
name|amd64fbsd_sigtramp_start_addr
expr_stmt|;
name|tdep
operator|->
name|sigtramp_end
operator|=
name|amd64fbsd_sigtramp_end_addr
expr_stmt|;
name|tdep
operator|->
name|sigcontext_addr
operator|=
name|amd64fbsd_sigcontext_addr
expr_stmt|;
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|amd64fbsd_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|amd64fbsd_sc_reg_offset
argument_list|)
expr_stmt|;
comment|/* FreeBSD uses SVR4-style shared libraries.  */
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
name|_initialize_amd64fbsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_amd64fbsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_i386
argument_list|,
name|bfd_mach_x86_64
argument_list|,
name|GDB_OSABI_FREEBSD_ELF
argument_list|,
name|amd64fbsd_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

