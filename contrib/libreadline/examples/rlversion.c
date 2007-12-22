begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rlversion -- print out readline's version number  */
end_comment

begin_comment
comment|/* Copyright (C) 1987-2002 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"posixstat.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|READLINE_LIBRARY
end_ifdef

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<readline/readline.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|rl_library_version
condition|?
name|rl_library_version
else|:
literal|"unknown"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

