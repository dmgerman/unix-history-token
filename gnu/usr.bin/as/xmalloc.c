begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c - get memory or bust     Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*   NAME   xmalloc() - get memory or bust   INDEX   xmalloc() uses malloc()    SYNOPSIS   char *	my_memory;    my_memory = xmalloc(42); / * my_memory gets address of 42 chars * /    DESCRIPTION    Use xmalloc() as an "error-free" malloc(). It does almost the same job.   When it cannot honour your request for memory it BOMBS your program   with a "virtual memory exceeded" message. Malloc() returns NULL and   does not bomb your program.    SEE ALSO   malloc()    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_define
define|#
directive|define
name|error
value|as_fatal
end_define

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
name|n
parameter_list|)
name|long
name|n
decl_stmt|;
block|{
name|char
modifier|*
name|retval
decl_stmt|;
name|void
name|error
parameter_list|()
function_decl|;
if|if
condition|(
operator|(
name|retval
operator|=
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|n
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
literal|"virtual memory exceeded"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/* end of xmalloc.c */
end_comment

end_unit

