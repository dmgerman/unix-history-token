begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to GNU/Linux on IA-64 running AIX.    Copyright 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_AIX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_AIX_H
end_define

begin_include
include|#
directive|include
file|"ia64/tm-ia64.h"
end_include

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_define
define|#
directive|define
name|TARGET_ELF64
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_aix_in_sigtramp
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|func_name
parameter_list|)
value|ia64_aix_in_sigtramp (pc, func_name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef TM_AIX_H */
end_comment

end_unit

