begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- safe versions of malloc and realloc */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     This file has appeared in prior works by the Free Software Foundation;    thus it carries copyright dates from 1988 through 1993.     Copyright (C) 1988, 1989, 1990, 1991, 1992, 1993 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ALREADY_HAVE_XMALLOC
argument_list|)
end_if

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

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|void
modifier|*
name|xmalloc
parameter_list|(
name|bytes
parameter_list|)
name|int
name|bytes
decl_stmt|;
block|{
name|void
modifier|*
name|temp
init|=
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
name|void
modifier|*
name|xrealloc
parameter_list|(
name|pointer
parameter_list|,
name|bytes
parameter_list|)
name|void
modifier|*
name|pointer
decl_stmt|;
name|int
name|bytes
decl_stmt|;
block|{
name|void
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
name|malloc
argument_list|(
name|bytes
argument_list|)
expr_stmt|;
else|else
name|temp
operator|=
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

