begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IBM PowerPC native-dependent macros for GDB, the GNU debugger.    Copyright 1995, 2000 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_LINUX_H
end_ifndef

begin_include
include|#
directive|include
file|"nm-linux.h"
end_include

begin_define
define|#
directive|define
name|NM_LINUX_H
end_define

begin_comment
comment|/* Return sizeof user struct to callers in less machine dependent routines */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size()
end_define

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef NM_LINUX_H */
end_comment

end_unit

