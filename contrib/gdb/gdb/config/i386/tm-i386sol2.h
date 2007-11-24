begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i386 running Solaris 2.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386SOL2_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386SOL2_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* The SunPRO compiler puts out 0 instead of the address in N_SO symbols,    and for SunPRO 3.0, N_FUN symbols too.  */
end_comment

begin_define
define|#
directive|define
name|SOFUN_ADDRESS_MAYBE_MISSING
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|sunpro_static_transform_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STATIC_TRANSFORM_NAME
parameter_list|(
name|x
parameter_list|)
value|sunpro_static_transform_name (x)
end_define

begin_define
define|#
directive|define
name|IS_STATIC_TRANSFORM_NAME
parameter_list|(
name|name
parameter_list|)
value|((name)[0] == '.')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386SOL2_H */
end_comment

end_unit

