begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common definitions for remote server for GDB.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_function_decl
name|void
name|read_inferior_memory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|mywait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|myresume
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mythread_alive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create_inferior
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|registers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inferior_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cont_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|general_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|thread_from_wait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|old_thread_from_wait
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|remote_send
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putpkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remote_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_ok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_enn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|convert_ascii_to_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|convert_int_to_ascii
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prepare_resume_reply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_m_packet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_M_packet
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|jmp_buf
name|toplevel
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|perror_with_name
parameter_list|()
function_decl|;
end_function_decl

end_unit

