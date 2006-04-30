begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Handle shared libraries for GDB, the GNU Debugger.     Copyright 2000, 2004    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_comment
comment|/* Critical offsets and sizes which describe struct r_debug and    struct link_map on SVR4-like targets.  All offsets and sizes are    in bytes unless otherwise specified.  */
end_comment

begin_struct
struct|struct
name|link_map_offsets
block|{
comment|/* Size of struct r_debug (or equivalent), or at least enough of it to        be able to obtain the r_map field.  */
name|int
name|r_debug_size
decl_stmt|;
comment|/* Offset to the r_map field in struct r_debug.  */
name|int
name|r_map_offset
decl_stmt|;
comment|/* Size of the r_map field in struct r_debug.  */
name|int
name|r_map_size
decl_stmt|;
comment|/* Size of struct link_map (or equivalent), or at least enough of it        to be able to obtain the fields below.  */
name|int
name|link_map_size
decl_stmt|;
comment|/* Offset to l_addr field in struct link_map.  */
name|int
name|l_addr_offset
decl_stmt|;
comment|/* Size of l_addr field in struct link_map.  */
name|int
name|l_addr_size
decl_stmt|;
comment|/* Offset to l_next field in struct link_map.  */
name|int
name|l_next_offset
decl_stmt|;
comment|/* Size of l_next field in struct link_map.  */
name|int
name|l_next_size
decl_stmt|;
comment|/* Offset to l_prev field in struct link_map.  */
name|int
name|l_prev_offset
decl_stmt|;
comment|/* Size of l_prev field in struct link_map.  */
name|int
name|l_prev_size
decl_stmt|;
comment|/* Offset to l_name field in struct link_map.  */
name|int
name|l_name_offset
decl_stmt|;
comment|/* Size of l_name field in struct link_map.  */
name|int
name|l_name_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* set_solib_svr4_fetch_link_map_offsets() is intended to be called by    a<arch>_gdbarch_init() function.  It is used to establish an    architecture specific link_map_offsets fetcher for the architecture    being defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_solib_svr4_fetch_link_map_offsets
argument_list|(
expr|struct
name|gdbarch
operator|*
name|gdbarch
argument_list|,
expr|struct
name|link_map_offsets
operator|*
call|(
modifier|*
name|func
call|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is called by thread_db.c.  Return the address of the    link map for the given objfile.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|svr4_fetch_objfile_link_map
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* legacy_svr4_fetch_link_map_offsets_hook is a pointer to a function    which is used to fetch link map offsets.  It will only be set    by solib-legacy.c, if at all. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|link_map_offsets
modifier|*
function_decl|(
modifier|*
name|legacy_svr4_fetch_link_map_offsets_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch (and possibly build) an appropriate `struct link_map_offsets'    for ILP32 and LP64 SVR4 systems.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|link_map_offsets
modifier|*
name|svr4_ilp32_fetch_link_map_offsets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|link_map_offsets
modifier|*
name|svr4_lp64_fetch_link_map_offsets
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

