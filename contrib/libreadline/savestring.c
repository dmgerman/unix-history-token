begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* savestring.c  */
end_comment

begin_comment
comment|/* Copyright (C) 1998 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 1, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Backwards compatibility, now that savestring has been removed from    all `public' readline header files. */
end_comment

begin_function
name|char
modifier|*
name|savestring
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|strcpy
argument_list|(
name|xmalloc
argument_list|(
literal|1
operator|+
operator|(
name|int
operator|)
name|strlen
argument_list|(
name|s
argument_list|)
argument_list|)
argument_list|,
operator|(
name|s
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

