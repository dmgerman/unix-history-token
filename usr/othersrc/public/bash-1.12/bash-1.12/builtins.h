begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* builtins.h -- What a builtin looks like, and where to find them. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ALIAS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"alias.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The thing that we build the array of builtins out of. */
end_comment

begin_struct
struct|struct
name|builtin
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|Function
modifier|*
name|function
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|char
modifier|*
modifier|*
name|long_doc
decl_stmt|;
comment|/* NULL terminated array of strings. */
name|char
modifier|*
name|short_doc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Found in builtins.c, created by builtins/mkbuiltins. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|builtin
name|shell_builtins
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_shell_builtins
decl_stmt|;
end_decl_stmt

end_unit

