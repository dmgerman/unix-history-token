begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for the GNU Hurd.    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
file|"i386-tdep.h"
end_include

begin_function
specifier|static
name|void
name|i386gnu_init_abi
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
comment|/* GNU uses ELF.  */
name|i386_elf_init_abi
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
literal|20
expr_stmt|;
comment|/* From<bits/setjmp.h>.  */
block|}
end_function

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_initialize_i386gnu_tdep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_i386gnu_tdep
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
name|GDB_OSABI_HURD
argument_list|,
name|i386gnu_init_abi
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

