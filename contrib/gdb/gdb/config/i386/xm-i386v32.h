begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for i386, running System V 3.2.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/xm-i386v.h"
end_include

begin_comment
comment|/* Apparently there is inconsistency among various System V's about what    the name of this field is.  */
end_comment

begin_define
define|#
directive|define
name|U_FPSTATE
parameter_list|(
name|u
parameter_list|)
value|u.u_fps.u_fpstate
end_define

end_unit

