begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Target-specific functions for ARM running under NetBSD.    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"osabi.h"
end_include

begin_include
include|#
directive|include
file|"arch-utils.h"
end_include

begin_include
include|#
directive|include
file|"arm-tdep.h"
end_include

begin_include
include|#
directive|include
file|"solib-svr4.h"
end_include

begin_comment
comment|/* Description of the longjmp buffer.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FBSD_JB_PC
value|24
end_define

begin_define
define|#
directive|define
name|ARM_FBSD_JB_ELEMENT_SIZE
value|INT_REGISTER_SIZE
end_define

begin_function
specifier|static
name|void
name|arm_freebsd_init_abi_common
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
name|tdep
operator|->
name|lowest_pc
operator|=
literal|0x8000
expr_stmt|;
name|tdep
operator|->
name|jb_pc
operator|=
name|ARM_FBSD_JB_PC
expr_stmt|;
name|tdep
operator|->
name|jb_elt_size
operator|=
name|ARM_FBSD_JB_ELEMENT_SIZE
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|arm_freebsd_elf_init_abi
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
name|arm_freebsd_init_abi_common
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
name|tdep
operator|->
name|fp_model
operator|=
name|ARM_FLOAT_SOFT_VFP
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_armfbsd_tdep
parameter_list|(
name|void
parameter_list|)
block|{
name|gdbarch_register_osabi
argument_list|(
name|bfd_arch_arm
argument_list|,
literal|0
argument_list|,
name|GDB_OSABI_FREEBSD_ELF
argument_list|,
name|arm_freebsd_elf_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

