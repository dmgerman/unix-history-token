begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ho-sysv.h  System V specific header file.    Copyright (C) 1987, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HO_USG
end_define

begin_define
define|#
directive|define
name|setbuffer
parameter_list|(
name|stream
parameter_list|,
name|buf
parameter_list|,
name|size
parameter_list|)
value|setvbuf((stream), (buf), _IOLBF, (size))
end_define

begin_function_decl
specifier|extern
name|int
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end of ho-sysv.h */
end_comment

end_unit

