begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c -- malloc with out of memory checking    Copyright (C) 1990, 1991 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
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
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate N bytes of memory dynamically, with error checking.  */
end_comment

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
name|n
parameter_list|)
name|unsigned
name|n
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|malloc
argument_list|(
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
comment|/* Must exit with 2 for `cmp'.  */
name|error
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
literal|"virtual memory exhausted"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

begin_comment
comment|/* Change the size of an allocated block of memory P to N bytes,    with error checking.    If P is NULL, run xmalloc.    If N is 0, run free and return NULL.  */
end_comment

begin_function
name|char
modifier|*
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
name|unsigned
name|n
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|==
literal|0
condition|)
return|return
name|xmalloc
argument_list|(
name|n
argument_list|)
return|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|p
operator|=
name|realloc
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
comment|/* Must exit with 2 for `cmp'.  */
name|error
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
literal|"virtual memory exhausted"
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

end_unit

