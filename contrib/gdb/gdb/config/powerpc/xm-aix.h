begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for hosting on an PowerPC, for GDB, the GNU debugger.    Copyright 1995, 1996, 2000 Free Software Foundation, Inc.    Contributed by Cygnus Corporation.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"xm-aix4.h"
end_include

begin_comment
comment|/* This doesn't seem to be declared in any header file I can find.  */
end_comment

begin_function_decl
name|char
modifier|*
name|termdef
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* UINT_MAX is defined in<sys/limits.h> as a decimal constant (4294967295)    which is too large to fit in a signed int when it is parsed by the    compiler, so it issues a diagnostic.  Just undef it here so that we    use gdb's version in defs.h */
end_comment

begin_undef
undef|#
directive|undef
name|UINT_MAX
end_undef

end_unit

