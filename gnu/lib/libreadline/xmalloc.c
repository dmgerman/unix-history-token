begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- safe versions of malloc and realloc */
end_comment

begin_comment
comment|/* Copyright (C) 1991 Free Software Foundation, Inc.     This file is part of GNU Readline, a library for reading lines    of text with interactive input and history editing.     Readline is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 1, or (at your option) any    later version.     Readline is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with Readline; see the file COPYING.  If not, write to the Free    Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ALREADY_HAVE_XMALLOC
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_function_decl
specifier|static
name|void
name|memory_error_and_abort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*		   Memory Allocation and Deallocation.		    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Return a pointer to free()able block of memory large enough    to hold BYTES number of bytes.  If the memory cannot be allocated,    print an error message and abort. */
end_comment

begin_function
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
argument_list|(
literal|"xmalloc"
argument_list|)
expr_stmt|;
return|return
operator|(
name|temp
operator|)
return|;
block|}
end_function

begin_function
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
argument_list|(
literal|"xrealloc"
argument_list|)
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
parameter_list|(
name|fname
parameter_list|)
name|char
modifier|*
name|fname
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Out of virtual memory!\n"
argument_list|,
name|fname
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
comment|/* !ALREADY_HAVE_XMALLOC */
end_comment

end_unit

