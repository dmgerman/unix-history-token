begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991-2014 Free Software Foundation, Inc.    This file is part of the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_undef
undef|#
directive|undef
name|strcpy
end_undef

begin_comment
comment|/* Copy SRC to DEST.  */
end_comment

begin_function
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|char
modifier|*
name|s
init|=
operator|(
name|char
operator|*
operator|)
name|src
decl_stmt|;
specifier|const
name|ptrdiff_t
name|off
init|=
name|dest
operator|-
name|s
operator|-
literal|1
decl_stmt|;
do|do
block|{
name|c
operator|=
operator|*
name|s
operator|++
expr_stmt|;
name|s
index|[
name|off
index|]
operator|=
name|c
expr_stmt|;
block|}
do|while
condition|(
name|c
operator|!=
literal|'\0'
condition|)
do|;
return|return
name|dest
return|;
block|}
end_function

end_unit

