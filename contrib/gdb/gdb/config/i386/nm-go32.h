begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native definitions for Intel x86 running DJGPP.    Copyright 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|I386_USE_GENERIC_WATCHPOINTS
end_define

begin_include
include|#
directive|include
file|"i386/nm-i386.h"
end_include

begin_comment
comment|/* Support for hardware-assisted breakpoints and watchpoints.  */
end_comment

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_CONTROL
parameter_list|(
name|VAL
parameter_list|)
value|go32_set_dr7 (VAL)
end_define

begin_function_decl
specifier|extern
name|void
name|go32_set_dr7
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_SET_ADDR
parameter_list|(
name|N
parameter_list|,
name|ADDR
parameter_list|)
value|go32_set_dr (N,ADDR)
end_define

begin_function_decl
specifier|extern
name|void
name|go32_set_dr
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|I386_DR_LOW_RESET_ADDR
parameter_list|(
name|N
parameter_list|)
end_define

begin_define
define|#
directive|define
name|I386_DR_LOW_GET_STATUS
parameter_list|()
value|go32_get_dr6 ()
end_define

begin_function_decl
specifier|extern
name|unsigned
name|go32_get_dr6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

