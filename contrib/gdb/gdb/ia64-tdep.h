begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for the ia64.     Copyright 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IA64_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|IA64_TDEP_H
end_define

begin_include
include|#
directive|include
file|"osabi.h"
end_include

begin_comment
comment|/* Target-dependent structure in gdbarch.  */
end_comment

begin_struct
struct|struct
name|gdbarch_tdep
block|{
name|enum
name|gdb_osabi
name|osabi
decl_stmt|;
comment|/* OS/ABI of inferior.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|sigcontext_register_address
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* OS specific function which, given a frame address 			   and register number, returns the offset to the 			   given register from the start of the frame. */
name|CORE_ADDR
function_decl|(
modifier|*
name|find_global_pointer
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIGCONTEXT_REGISTER_ADDRESS
define|\
value|(gdbarch_tdep (current_gdbarch)->sigcontext_register_address)
end_define

begin_define
define|#
directive|define
name|FIND_GLOBAL_POINTER
define|\
value|(gdbarch_tdep (current_gdbarch)->find_global_pointer)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|ia64_generic_find_global_pointer
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IA64_TDEP_H */
end_comment

end_unit

