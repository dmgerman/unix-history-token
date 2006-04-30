begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i387-specific utility functions, for the remote server for GDB.    Copyright 2000, 2001, 2002    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I387_FP_H
end_ifndef

begin_define
define|#
directive|define
name|I387_FP_H
end_define

begin_function_decl
name|void
name|i387_cache_to_fsave
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i387_fsave_to_cache
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i387_cache_to_fxsave
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i387_fxsave_to_cache
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|num_xmm_registers
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I387_FP_H */
end_comment

end_unit

