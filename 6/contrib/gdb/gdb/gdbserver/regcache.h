begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Register support routines for the remote server for GDB.    Copyright 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|REGCACHE_H
end_define

begin_struct_decl
struct_decl|struct
name|inferior_list_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/* Create a new register cache for INFERIOR.  */
end_comment

begin_function_decl
name|void
modifier|*
name|new_register_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Release all memory associated with the register cache for INFERIOR.  */
end_comment

begin_function_decl
name|void
name|free_register_cache
parameter_list|(
name|void
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Invalidate cached registers for one or all threads.  */
end_comment

begin_function_decl
name|void
name|regcache_invalidate_one
parameter_list|(
name|struct
name|inferior_list_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regcache_invalidate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert all registers to a string in the currently specified remote    format.  */
end_comment

begin_function_decl
name|void
name|registers_to_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert a string to register values and fill our register cache.  */
end_comment

begin_function_decl
name|void
name|registers_from_string
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the size in bytes of a string-encoded register packet.  */
end_comment

begin_function_decl
name|int
name|registers_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a pointer to the description of register ``n''.  */
end_comment

begin_function_decl
name|struct
name|reg
modifier|*
name|find_register_by_number
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_size
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_regno
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|gdbserver_expedite_regs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|supply_register
parameter_list|(
name|int
name|n
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|supply_register_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|collect_register
parameter_list|(
name|int
name|n
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|collect_register_as_string
parameter_list|(
name|int
name|n
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|collect_register_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REGCACHE_H */
end_comment

end_unit

