begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Low level Unix child interface to ttrace, for GDB when running under HP-UX.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFTTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|INFTTRACE_H
end_define

begin_function_decl
specifier|extern
name|int
name|parent_attach_all
parameter_list|(
name|int
parameter_list|,
name|PTRACE_ARG3_TYPE
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|hppa_switched_threads
parameter_list|(
name|pid_t
name|gdb_pid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

