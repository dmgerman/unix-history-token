begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_function
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
name|__restrict
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|from
parameter_list|)
block|{
name|char
modifier|*
name|save
init|=
name|to
decl_stmt|;
for|for
control|(
init|;
operator|(
operator|*
name|to
operator|=
operator|*
name|from
operator|)
operator|!=
literal|0
condition|;
operator|++
name|from
operator|,
operator|++
name|to
control|)
empty_stmt|;
return|return
operator|(
name|save
operator|)
return|;
block|}
end_function

end_unit

