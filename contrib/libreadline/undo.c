begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* readline.c -- a general facility for reading lines of input    with emacs style editing and completion. */
end_comment

begin_comment
comment|/* Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_define
define|#
directive|define
name|READLINE_LIBRARY
end_define

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
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* for _POSIX_VERSION */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UNISTD_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STDLIB_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"ansi_stdlib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STDLIB_H */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* System-specific feature definitions and include files. */
end_comment

begin_include
include|#
directive|include
file|"rldefs.h"
end_include

begin_comment
comment|/* Some standard library routines. */
end_comment

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

begin_include
include|#
directive|include
file|"rlprivate.h"
end_include

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|do { int t; t = s; s = e; e = t; } while (0)
end_define

begin_comment
comment|/* Non-zero tells rl_delete_text and rl_insert_text to not add to    the undo list. */
end_comment

begin_decl_stmt
name|int
name|_rl_doing_an_undo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How many unclosed undo groups we currently have. */
end_comment

begin_decl_stmt
name|int
name|_rl_undo_group_level
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The current undo list for THE_LINE. */
end_comment

begin_decl_stmt
name|UNDO_LIST
modifier|*
name|rl_undo_list
init|=
operator|(
name|UNDO_LIST
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Undo, and Undoing			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Remember how to undo something.  Concatenate some undos if that    seems right. */
end_comment

begin_function
name|void
name|rl_add_undo
parameter_list|(
name|what
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|,
name|text
parameter_list|)
name|enum
name|undo_code
name|what
decl_stmt|;
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|{
name|UNDO_LIST
modifier|*
name|temp
init|=
operator|(
name|UNDO_LIST
operator|*
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|UNDO_LIST
argument_list|)
argument_list|)
decl_stmt|;
name|temp
operator|->
name|what
operator|=
name|what
expr_stmt|;
name|temp
operator|->
name|start
operator|=
name|start
expr_stmt|;
name|temp
operator|->
name|end
operator|=
name|end
expr_stmt|;
name|temp
operator|->
name|text
operator|=
name|text
expr_stmt|;
name|temp
operator|->
name|next
operator|=
name|rl_undo_list
expr_stmt|;
name|rl_undo_list
operator|=
name|temp
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Free the existing undo list. */
end_comment

begin_function
name|void
name|free_undo_list
parameter_list|()
block|{
while|while
condition|(
name|rl_undo_list
condition|)
block|{
name|UNDO_LIST
modifier|*
name|release
init|=
name|rl_undo_list
decl_stmt|;
name|rl_undo_list
operator|=
name|rl_undo_list
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|release
operator|->
name|what
operator|==
name|UNDO_DELETE
condition|)
name|free
argument_list|(
name|release
operator|->
name|text
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|release
argument_list|)
expr_stmt|;
block|}
name|rl_undo_list
operator|=
operator|(
name|UNDO_LIST
operator|*
operator|)
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Undo the next thing in the list.  Return 0 if there    is nothing to undo, or non-zero if there was. */
end_comment

begin_function
name|int
name|rl_do_undo
parameter_list|()
block|{
name|UNDO_LIST
modifier|*
name|release
decl_stmt|;
name|int
name|waiting_for_begin
init|=
literal|0
decl_stmt|;
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
define|#
directive|define
name|TRANS
parameter_list|(
name|i
parameter_list|)
value|((i) == -1 ? rl_point : ((i) == -2 ? rl_end : (i)))
do|do
block|{
if|if
condition|(
operator|!
name|rl_undo_list
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|_rl_doing_an_undo
operator|=
literal|1
expr_stmt|;
comment|/* To better support vi-mode, a start or end value of -1 means 	 rl_point, and a value of -2 means rl_end. */
if|if
condition|(
name|rl_undo_list
operator|->
name|what
operator|==
name|UNDO_DELETE
operator|||
name|rl_undo_list
operator|->
name|what
operator|==
name|UNDO_INSERT
condition|)
block|{
name|start
operator|=
name|TRANS
argument_list|(
name|rl_undo_list
operator|->
name|start
argument_list|)
expr_stmt|;
name|end
operator|=
name|TRANS
argument_list|(
name|rl_undo_list
operator|->
name|end
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|rl_undo_list
operator|->
name|what
condition|)
block|{
comment|/* Undoing deletes means inserting some text. */
case|case
name|UNDO_DELETE
case|:
name|rl_point
operator|=
name|start
expr_stmt|;
name|rl_insert_text
argument_list|(
name|rl_undo_list
operator|->
name|text
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|rl_undo_list
operator|->
name|text
argument_list|)
expr_stmt|;
break|break;
comment|/* Undoing inserts means deleting some text. */
case|case
name|UNDO_INSERT
case|:
name|rl_delete_text
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
name|rl_point
operator|=
name|start
expr_stmt|;
break|break;
comment|/* Undoing an END means undoing everything 'til we get to a BEGIN. */
case|case
name|UNDO_END
case|:
name|waiting_for_begin
operator|++
expr_stmt|;
break|break;
comment|/* Undoing a BEGIN means that we are done with this group. */
case|case
name|UNDO_BEGIN
case|:
if|if
condition|(
name|waiting_for_begin
condition|)
name|waiting_for_begin
operator|--
expr_stmt|;
else|else
name|ding
argument_list|()
expr_stmt|;
break|break;
block|}
name|_rl_doing_an_undo
operator|=
literal|0
expr_stmt|;
name|release
operator|=
name|rl_undo_list
expr_stmt|;
name|rl_undo_list
operator|=
name|rl_undo_list
operator|->
name|next
expr_stmt|;
name|free
argument_list|(
name|release
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|waiting_for_begin
condition|)
do|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|TRANS
end_undef

begin_function
name|int
name|_rl_fix_last_undo_of_type
parameter_list|(
name|type
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
name|int
name|type
decl_stmt|,
name|start
decl_stmt|,
name|end
decl_stmt|;
block|{
name|UNDO_LIST
modifier|*
name|rl
decl_stmt|;
for|for
control|(
name|rl
operator|=
name|rl_undo_list
init|;
name|rl
condition|;
name|rl
operator|=
name|rl
operator|->
name|next
control|)
block|{
if|if
condition|(
name|rl
operator|->
name|what
operator|==
name|type
condition|)
block|{
name|rl
operator|->
name|start
operator|=
name|start
expr_stmt|;
name|rl
operator|->
name|end
operator|=
name|end
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Begin a group.  Subsequent undos are undone as an atomic operation. */
end_comment

begin_function
name|int
name|rl_begin_undo_group
parameter_list|()
block|{
name|rl_add_undo
argument_list|(
name|UNDO_BEGIN
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_rl_undo_group_level
operator|++
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* End an undo group started with rl_begin_undo_group (). */
end_comment

begin_function
name|int
name|rl_end_undo_group
parameter_list|()
block|{
name|rl_add_undo
argument_list|(
name|UNDO_END
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|_rl_undo_group_level
operator|--
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Save an undo entry for the text from START to END. */
end_comment

begin_function
name|int
name|rl_modifying
parameter_list|(
name|start
parameter_list|,
name|end
parameter_list|)
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
block|{
if|if
condition|(
name|start
operator|>
name|end
condition|)
block|{
name|SWAP
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|start
operator|!=
name|end
condition|)
block|{
name|char
modifier|*
name|temp
init|=
name|rl_copy_text
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
decl_stmt|;
name|rl_begin_undo_group
argument_list|()
expr_stmt|;
name|rl_add_undo
argument_list|(
name|UNDO_DELETE
argument_list|,
name|start
argument_list|,
name|end
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|rl_add_undo
argument_list|(
name|UNDO_INSERT
argument_list|,
name|start
argument_list|,
name|end
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|rl_end_undo_group
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Revert the current line to its previous state. */
end_comment

begin_function
name|int
name|rl_revert_line
parameter_list|(
name|count
parameter_list|,
name|key
parameter_list|)
name|int
name|count
decl_stmt|,
name|key
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|rl_undo_list
condition|)
name|ding
argument_list|()
expr_stmt|;
else|else
block|{
while|while
condition|(
name|rl_undo_list
condition|)
name|rl_do_undo
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Do some undoing of things that were done. */
end_comment

begin_function
name|int
name|rl_undo_command
parameter_list|(
name|count
parameter_list|,
name|key
parameter_list|)
name|int
name|count
decl_stmt|,
name|key
decl_stmt|;
block|{
if|if
condition|(
name|count
operator|<
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Nothing to do. */
while|while
condition|(
name|count
condition|)
block|{
if|if
condition|(
name|rl_do_undo
argument_list|()
condition|)
name|count
operator|--
expr_stmt|;
else|else
block|{
name|ding
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

