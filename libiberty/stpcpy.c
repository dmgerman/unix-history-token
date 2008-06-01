begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implement the stpcpy function.    Copyright (C) 2003 Free Software Foundation, Inc.    Written by Kaveh R. Ghazi<ghazi@caip.rutgers.edu>.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* stpcpy (char *@var{dst}, const char *@var{src})  Copies the string @var{src} into @var{dst}.  Returns a pointer to @var{dst} + strlen(@var{src}).  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function_decl
specifier|extern
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PTR
name|memcpy
parameter_list|(
name|PTR
parameter_list|,
specifier|const
name|PTR
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|stpcpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
specifier|const
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|src
argument_list|)
decl_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|len
operator|+
literal|1
argument_list|)
operator|+
name|len
return|;
block|}
end_function

end_unit

