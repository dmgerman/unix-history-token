begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)exit.c	5.4 (Berkeley) 2/23/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"atexit.h"
end_include

begin_function_decl
name|void
function_decl|(
modifier|*
name|__cleanup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Exit, flushing stdio buffers if necessary.  */
end_comment

begin_function
name|void
name|exit
parameter_list|(
name|status
parameter_list|)
name|int
name|status
decl_stmt|;
block|{
specifier|register
name|struct
name|atexit
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
for|for
control|(
name|p
operator|=
name|__atexit
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
for|for
control|(
name|n
operator|=
name|p
operator|->
name|ind
init|;
operator|--
name|n
operator|>=
literal|0
condition|;
control|)
call|(
modifier|*
name|p
operator|->
name|fns
index|[
name|n
index|]
call|)
argument_list|()
expr_stmt|;
if|if
condition|(
name|__cleanup
condition|)
call|(
modifier|*
name|__cleanup
call|)
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
comment|/* We'll never get here; this just surpresses a warning. */
while|while
condition|(
literal|1
condition|)
block|{
empty_stmt|;
block|}
block|}
end_function

end_unit

