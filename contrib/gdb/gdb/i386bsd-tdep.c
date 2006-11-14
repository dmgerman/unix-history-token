begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for i386 BSD's.     Copyright 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|"i386-tdep.h"
end_include

begin_comment
comment|/* Support for signal handlers.  */
end_comment

begin_comment
comment|/* Return whether PC is in a BSD sigtramp routine.  */
end_comment

begin_function
name|int
name|i386bsd_pc_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
name|struct
name|gdbarch_tdep
modifier|*
name|tdep
init|=
name|gdbarch_tdep
argument_list|(
name|current_gdbarch
argument_list|)
decl_stmt|;
return|return
operator|(
name|pc
operator|>=
name|tdep
operator|->
name|sigtramp_start
operator|&&
name|pc
operator|<
name|tdep
operator|->
name|sigtramp_end
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Assuming NEXT_FRAME is for a frame following a BSD sigtramp    routine, return the address of the associated sigcontext structure.  */
end_comment

begin_function
specifier|static
name|CORE_ADDR
name|i386bsd_sigcontext_addr
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
block|{
name|char
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|CORE_ADDR
name|sp
decl_stmt|;
name|frame_unwind_register
argument_list|(
name|next_frame
argument_list|,
name|I386_ESP_REGNUM
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|sp
operator|=
name|extract_unsigned_integer
argument_list|(
name|buf
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
name|read_memory_unsigned_integer
argument_list|(
name|sp
operator|+
literal|8
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return the start address of the sigtramp routine.  */
end_comment

begin_function
name|CORE_ADDR
name|i386bsd_sigtramp_start
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
block|{
return|return
name|gdbarch_tdep
argument_list|(
name|current_gdbarch
argument_list|)
operator|->
name|sigtramp_start
return|;
block|}
end_function

begin_comment
comment|/* Return the end address of the sigtramp routine.  */
end_comment

begin_function
name|CORE_ADDR
name|i386bsd_sigtramp_end
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
block|{
return|return
name|gdbarch_tdep
argument_list|(
name|current_gdbarch
argument_list|)
operator|->
name|sigtramp_end
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Support for shared libraries.  */
end_comment

begin_comment
comment|/* Return non-zero if we are in a shared library trampoline code stub.  */
end_comment

begin_function
name|int
name|i386bsd_aout_in_solib_call_trampoline
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
block|{
return|return
operator|(
name|name
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"_DYNAMIC"
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Traditional BSD (4.3 BSD, still used for BSDI and 386BSD).  */
end_comment

begin_comment
comment|/* From<machine/signal.h>.  */
end_comment

begin_decl_stmt
name|int
name|i386bsd_sc_reg_offset
index|[]
init|=
block|{
operator|-
literal|1
block|,
comment|/* %eax */
operator|-
literal|1
block|,
comment|/* %ecx */
operator|-
literal|1
block|,
comment|/* %edx */
operator|-
literal|1
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
operator|-
literal|1
block|,
comment|/* %esi */
operator|-
literal|1
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
operator|-
literal|1
block|,
comment|/* %cs */
operator|-
literal|1
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
name|i386bsd_init_abi
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
name|set_gdbarch_pc_in_sigtramp
argument_list|(
name|gdbarch
argument_list|,
name|i386bsd_pc_in_sigtramp
argument_list|)
expr_stmt|;
comment|/* Allow the recognition of sigtramps as a function named<sigtramp>.  */
name|set_gdbarch_sigtramp_start
argument_list|(
name|gdbarch
argument_list|,
name|i386bsd_sigtramp_start
argument_list|)
expr_stmt|;
name|set_gdbarch_sigtramp_end
argument_list|(
name|gdbarch
argument_list|,
name|i386bsd_sigtramp_end
argument_list|)
expr_stmt|;
comment|/* Assume SunOS-style shared libraries.  */
name|set_gdbarch_in_solib_call_trampoline
argument_list|(
name|gdbarch
argument_list|,
name|i386bsd_aout_in_solib_call_trampoline
argument_list|)
expr_stmt|;
name|tdep
operator|->
name|jb_pc_offset
operator|=
literal|0
expr_stmt|;
name|tdep
operator|->
name|sigtramp_start
operator|=
literal|0xfdbfdfc0
expr_stmt|;
name|tdep
operator|->
name|sigtramp_end
operator|=
literal|0xfdbfe000
expr_stmt|;
name|tdep
operator|->
name|sigcontext_addr
operator|=
name|i386bsd_sigcontext_addr
expr_stmt|;
name|tdep
operator|->
name|sc_reg_offset
operator|=
name|i386bsd_sc_reg_offset
expr_stmt|;
name|tdep
operator|->
name|sc_num_regs
operator|=
name|ARRAY_SIZE
argument_list|(
name|i386bsd_sc_reg_offset
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
name|i386bsd_aout_osabi_sniffer
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|bfd_get_target
argument_list|(
name|abfd
argument_list|)
argument_list|,
literal|"a.out-i386-netbsd"
argument_list|)
operator|==
literal|0
condition|)
return|return
name|GDB_OSABI_NETBSD_AOUT
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|bfd_get_target
argument_list|(
name|abfd
argument_list|)
argument_list|,
literal|"a.out-i386-freebsd"
argument_list|)
operator|==
literal|0
condition|)
return|return
name|GDB_OSABI_FREEBSD_AOUT
return|;
return|return
name|GDB_OSABI_UNKNOWN
return|;
block|}
end_function

begin_function
specifier|static
name|enum
name|gdb_osabi
name|i386bsd_core_osabi_sniffer
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|bfd_get_target
argument_list|(
name|abfd
argument_list|)
argument_list|,
literal|"netbsd-core"
argument_list|)
operator|==
literal|0
condition|)
return|return
name|GDB_OSABI_NETBSD_AOUT
return|;
return|return
name|GDB_OSABI_UNKNOWN
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_i386bsd_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386bsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
name|gdbarch_register_osabi_sniffer
argument_list|(
name|bfd_arch_i386
argument_list|,
name|bfd_target_aout_flavour
argument_list|,
name|i386bsd_aout_osabi_sniffer
argument_list|)
expr_stmt|;
comment|/* BFD doesn't set the architecture for NetBSD style a.out core      files.  */
name|gdbarch_register_osabi_sniffer
argument_list|(
name|bfd_arch_unknown
argument_list|,
name|bfd_target_unknown_flavour
argument_list|,
name|i386bsd_core_osabi_sniffer
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

