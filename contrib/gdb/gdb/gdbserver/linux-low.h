begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal interfaces for the GNU/Linux specific target code for gdbserver.    Copyright 2002, Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_USR_REGISTERS
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|regmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_regs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|cannot_fetch_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cannot_store_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_REGSETS
end_ifdef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|regset_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|regset_info
block|{
name|int
name|get_request
decl_stmt|,
name|set_request
decl_stmt|;
name|int
name|size
decl_stmt|;
name|regset_func
name|fill_function
decl_stmt|,
name|store_function
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|regset_info
name|target_regsets
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

