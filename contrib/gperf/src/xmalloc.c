begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Provide a useful malloc sanity checker and an efficient buffered memory    allocator that reduces calls to malloc.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Grabs SIZE bytes of dynamic memory or dies trying! */
end_comment

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
name|size
parameter_list|)
name|int
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
name|char
modifier|*
name|temp
init|=
name|malloc
argument_list|(
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|temp
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"out of virtual memory\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|temp
return|;
block|}
end_function

begin_comment
comment|/* Determine default alignment.  If your C compiler does not    like this then try something like #define DEFAULT_ALIGNMENT 8. */
end_comment

begin_struct
struct|struct
name|fooalign
block|{
name|char
name|x
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALIGNMENT
value|((char *)&((struct fooalign *) 0)->d - (char *)0)
end_define

begin_comment
comment|/* Provide an abstraction that cuts down on the number of    calls to MALLOC by buffering the memory pool from which    items are allocated. */
end_comment

begin_function
name|char
modifier|*
name|buffered_malloc
parameter_list|(
name|size
parameter_list|)
name|int
name|size
decl_stmt|;
block|{
name|char
modifier|*
name|temp
decl_stmt|;
specifier|static
name|char
modifier|*
name|buf_start
init|=
literal|0
decl_stmt|;
comment|/* Large array used to reduce calls to NEW. */
specifier|static
name|char
modifier|*
name|buf_end
init|=
literal|0
decl_stmt|;
comment|/* Indicates end of BUF_START. */
specifier|static
name|int
name|buf_size
init|=
literal|4
operator|*
name|BUFSIZ
decl_stmt|;
comment|/* Size of buffer pointed to by BUF_START. */
comment|/* Align this on correct boundaries, just to be safe... */
name|size
operator|=
operator|(
operator|(
name|size
operator|+
name|ALIGNMENT
operator|-
literal|1
operator|)
operator|/
name|ALIGNMENT
operator|)
operator|*
name|ALIGNMENT
expr_stmt|;
comment|/* If we are about to overflow our buffer we'll just grab another      chunk of memory.  Since we never free the original memory it      doesn't matter that no one points to the beginning of that      chunk.  Furthermore, as a heuristic, we double the      size of the new buffer! */
if|if
condition|(
name|buf_start
operator|+
name|size
operator|>=
name|buf_end
condition|)
block|{
name|buf_size
operator|=
name|buf_size
operator|*
literal|2
operator|>
name|size
condition|?
name|buf_size
operator|*
literal|2
else|:
name|size
expr_stmt|;
name|buf_start
operator|=
name|xmalloc
argument_list|(
name|buf_size
argument_list|)
expr_stmt|;
name|buf_end
operator|=
name|buf_start
operator|+
name|buf_size
expr_stmt|;
block|}
name|temp
operator|=
name|buf_start
expr_stmt|;
name|buf_start
operator|+=
name|size
expr_stmt|;
return|return
name|temp
return|;
block|}
end_function

end_unit

