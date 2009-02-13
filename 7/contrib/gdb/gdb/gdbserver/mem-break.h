begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Memory breakpoint interfaces for the remote server for GDB.    Copyright 2002    Free Software Foundation, Inc.     Contributed by MontaVista Software.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEM_BREAK_H
end_ifndef

begin_define
define|#
directive|define
name|MEM_BREAK_H
end_define

begin_comment
comment|/* Breakpoints are opaque.  */
end_comment

begin_comment
comment|/* Create a new breakpoint at WHERE, and call HANDLER when    it is hit.  */
end_comment

begin_function_decl
name|void
name|set_breakpoint_at
parameter_list|(
name|CORE_ADDR
name|where
parameter_list|,
name|void
function_decl|(
modifier|*
name|handler
function_decl|)
parameter_list|(
name|CORE_ADDR
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a reinsertion breakpoint at STOP_AT for the breakpoint    currently at STOP_PC (and temporarily remove the breakpoint at    STOP_PC).  */
end_comment

begin_function_decl
name|void
name|reinsert_breakpoint_by_bp
parameter_list|(
name|CORE_ADDR
name|stop_pc
parameter_list|,
name|CORE_ADDR
name|stop_at
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Change the status of the breakpoint at WHERE to inserted.  */
end_comment

begin_function_decl
name|void
name|reinsert_breakpoint
parameter_list|(
name|CORE_ADDR
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Change the status of the breakpoint at WHERE to uninserted.  */
end_comment

begin_function_decl
name|void
name|uninsert_breakpoint
parameter_list|(
name|CORE_ADDR
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See if any breakpoint claims ownership of STOP_PC.  Call the handler for    the breakpoint, if found.  */
end_comment

begin_function_decl
name|int
name|check_breakpoints
parameter_list|(
name|CORE_ADDR
name|stop_pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See if any breakpoints shadow the target memory area from MEM_ADDR    to MEM_ADDR + MEM_LEN.  Update the data already read from the target    (in BUF) if necessary.  */
end_comment

begin_function_decl
name|void
name|check_mem_read
parameter_list|(
name|CORE_ADDR
name|mem_addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|mem_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* See if any breakpoints shadow the target memory area from MEM_ADDR    to MEM_ADDR + MEM_LEN.  Update the data to be written to the target    (in BUF) if necessary, as well as the original data for any breakpoints.  */
end_comment

begin_function_decl
name|void
name|check_mem_write
parameter_list|(
name|CORE_ADDR
name|mem_addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|mem_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the byte pattern to insert for memory breakpoints.  This function    must be called before any breakpoints are set.  */
end_comment

begin_function_decl
name|void
name|set_breakpoint_data
parameter_list|(
specifier|const
name|char
modifier|*
name|bp_data
parameter_list|,
name|int
name|bp_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MEM_BREAK_H */
end_comment

end_unit

