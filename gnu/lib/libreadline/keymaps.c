begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* keymaps.c -- Functions and keymaps for the GNU Readline library. */
end_comment

begin_comment
comment|/* Copyright (C) 1988, 1989, 1991 Free Software Foundation, Inc.     This file is part of GNU Readline, a library for reading lines    of text with interactive input and history editing.     Readline is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     Readline is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_include
include|#
directive|include
file|"keymaps.h"
end_include

begin_include
include|#
directive|include
file|"emacs_keymap.c"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VI_MODE
end_ifdef

begin_include
include|#
directive|include
file|"vi_keymap.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Remove these declarations when we have a complete libgnu.a. */
end_comment

begin_comment
comment|/* #define STATIC_MALLOC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STATIC_MALLOC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STATIC_MALLOC */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*		      Functions for manipulating Keymaps.	    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Return a new, empty keymap.    Free it with free() when you are done. */
end_comment

begin_function
name|Keymap
name|rl_make_bare_keymap
parameter_list|()
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|Keymap
name|keymap
init|=
operator|(
name|Keymap
operator|)
name|xmalloc
argument_list|(
literal|128
operator|*
sizeof|sizeof
argument_list|(
name|KEYMAP_ENTRY
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|128
condition|;
name|i
operator|++
control|)
block|{
name|keymap
index|[
name|i
index|]
operator|.
name|type
operator|=
name|ISFUNC
expr_stmt|;
name|keymap
index|[
name|i
index|]
operator|.
name|function
operator|=
operator|(
name|Function
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|'A'
init|;
name|i
operator|<
operator|(
literal|'Z'
operator|+
literal|1
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|keymap
index|[
name|i
index|]
operator|.
name|type
operator|=
name|ISFUNC
expr_stmt|;
name|keymap
index|[
name|i
index|]
operator|.
name|function
operator|=
name|rl_do_lowercase_version
expr_stmt|;
block|}
return|return
operator|(
name|keymap
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Return a new keymap which is a copy of MAP. */
end_comment

begin_function
name|Keymap
name|rl_copy_keymap
parameter_list|(
name|map
parameter_list|)
name|Keymap
name|map
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|Keymap
name|temp
init|=
name|rl_make_bare_keymap
argument_list|()
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|128
condition|;
name|i
operator|++
control|)
block|{
name|temp
index|[
name|i
index|]
operator|.
name|type
operator|=
name|map
index|[
name|i
index|]
operator|.
name|type
expr_stmt|;
name|temp
index|[
name|i
index|]
operator|.
name|function
operator|=
name|map
index|[
name|i
index|]
operator|.
name|function
expr_stmt|;
block|}
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Return a new keymap with the printing characters bound to rl_insert,    the uppercase Meta characters bound to run their lowercase equivalents,    and the Meta digits bound to produce numeric arguments. */
end_comment

begin_function
name|Keymap
name|rl_make_keymap
parameter_list|()
block|{
extern|extern rl_insert (
block|)
operator|,
function|rl_rubout
parameter_list|()
function|;
end_function

begin_decl_stmt
specifier|register
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Keymap
name|newmap
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|newmap
operator|=
name|rl_make_bare_keymap
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* All printing characters are self-inserting. */
end_comment

begin_for
for|for
control|(
name|i
operator|=
literal|' '
init|;
name|i
operator|<
literal|126
condition|;
name|i
operator|++
control|)
name|newmap
index|[
name|i
index|]
operator|.
name|function
operator|=
name|rl_insert
expr_stmt|;
end_for

begin_expr_stmt
name|newmap
index|[
name|TAB
index|]
operator|.
name|function
operator|=
name|rl_insert
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|newmap
index|[
name|RUBOUT
index|]
operator|.
name|function
operator|=
name|rl_rubout
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|newmap
index|[
name|CTRL
argument_list|(
literal|'H'
argument_list|)
index|]
operator|.
name|function
operator|=
name|rl_rubout
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|newmap
operator|)
return|;
end_return

begin_comment
unit|}
comment|/* Free the storage associated with MAP. */
end_comment

begin_expr_stmt
unit|rl_discard_keymap
operator|(
name|map
operator|)
name|Keymap
argument_list|(
name|map
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|!
name|map
condition|)
return|return;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|128
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|map
index|[
name|i
index|]
operator|.
name|type
condition|)
block|{
case|case
name|ISFUNC
case|:
break|break;
case|case
name|ISKMAP
case|:
name|rl_discard_keymap
argument_list|(
operator|(
name|Keymap
operator|)
name|map
index|[
name|i
index|]
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
case|case
name|ISMACR
case|:
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|map
index|[
name|i
index|]
operator|.
name|function
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|STATIC_MALLOC
end_ifdef

begin_escape
end_escape

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			xmalloc and xrealloc ()		     	    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_function_decl
specifier|static
name|void
name|memory_error_and_abort
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|char
modifier|*
name|xmalloc
parameter_list|(
name|bytes
parameter_list|)
name|int
name|bytes
decl_stmt|;
block|{
name|char
modifier|*
name|temp
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|bytes
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|temp
condition|)
name|memory_error_and_abort
argument_list|()
expr_stmt|;
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|xrealloc
parameter_list|(
name|pointer
parameter_list|,
name|bytes
parameter_list|)
name|char
modifier|*
name|pointer
decl_stmt|;
name|int
name|bytes
decl_stmt|;
block|{
name|char
modifier|*
name|temp
decl_stmt|;
if|if
condition|(
operator|!
name|pointer
condition|)
name|temp
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
else|else
name|temp
operator|=
operator|(
name|char
operator|*
operator|)
name|realloc
argument_list|(
name|pointer
argument_list|,
name|bytes
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|temp
condition|)
name|memory_error_and_abort
argument_list|()
expr_stmt|;
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|memory_error_and_abort
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"readline: Out of virtual memory!\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STATIC_MALLOC */
end_comment

end_unit

