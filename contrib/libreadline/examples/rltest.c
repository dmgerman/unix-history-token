begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Testing Readline			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
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

begin_include
include|#
directive|include
file|"history.h"
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

begin_include
include|#
directive|include
file|<readline/history.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|HIST_ENTRY
modifier|*
modifier|*
name|history_list
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|char
modifier|*
name|temp
decl_stmt|,
modifier|*
name|prompt
decl_stmt|;
name|int
name|done
decl_stmt|;
name|temp
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
name|prompt
operator|=
literal|"readline$ "
expr_stmt|;
name|done
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|!
name|done
condition|)
block|{
name|temp
operator|=
name|readline
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
comment|/* Test for EOF. */
if|if
condition|(
operator|!
name|temp
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* If there is anything on the line, print it and remember it. */
if|if
condition|(
operator|*
name|temp
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\r\n"
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|add_history
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
comment|/* Check for `command' that we handle. */
if|if
condition|(
name|strcmp
argument_list|(
name|temp
argument_list|,
literal|"quit"
argument_list|)
operator|==
literal|0
condition|)
name|done
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|temp
argument_list|,
literal|"list"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|HIST_ENTRY
modifier|*
modifier|*
name|list
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|list
operator|=
name|history_list
argument_list|()
expr_stmt|;
if|if
condition|(
name|list
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|list
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%d: %s\r\n"
argument_list|,
name|i
argument_list|,
name|list
index|[
name|i
index|]
operator|->
name|line
argument_list|)
expr_stmt|;
block|}
block|}
name|free
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

