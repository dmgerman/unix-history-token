begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xrealloc.c -new memory or bust-    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*   NAME 	xrealloc () - get more memory or bust INDEX 	xrealloc () uses realloc () SYNOPSIS 	char   *my_memory;  	my_memory = xrealloc (my_memory, 42); 	/ * my_memory gets (perhaps new) address of 42 chars * /  DESCRIPTION  	Use xrealloc () as an "error-free" realloc ().It does almost the same 	job.  When it cannot honour your request for memory it BOMBS your 	program with a "virtual memory exceeded" message.  Realloc() returns 	NULL and does not bomb your program.  SEE ALSO 	realloc () */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|xrealloc
parameter_list|(
name|ptr
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
name|long
name|n
decl_stmt|;
block|{
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
name|void
name|error
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|ptr
operator|=
name|realloc
argument_list|(
name|ptr
argument_list|,
operator|(
name|unsigned
operator|)
name|n
argument_list|)
operator|)
operator|==
literal|0
condition|)
name|error
argument_list|(
literal|"virtual memory exceeded"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ptr
operator|)
return|;
block|}
end_function

begin_comment
comment|/* end: xrealloc.c */
end_comment

end_unit

