begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for GDB, the GNU debugger.    Copyright 2001    Free Software Foundation, Inc.    Contributed by Jiri Smid, SuSE Labs.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X86_64_TDEP_H
end_ifndef

begin_define
define|#
directive|define
name|X86_64_TDEP_H
end_define

begin_include
include|#
directive|include
file|"i386-tdep.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|x86_64_num_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x86_64_num_gregs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|x86_64_register_number
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|x86_64_register_name
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|gdbarch_frame_saved_pc_ftype
name|x86_64_linux_frame_saved_pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gdbarch_saved_pc_after_call_ftype
name|x86_64_linux_saved_pc_after_call
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

