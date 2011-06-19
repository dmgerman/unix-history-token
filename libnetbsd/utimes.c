begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: utimes.c,v 1.4 2008/04/29 08:13:38 martin Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Your OS is old, eh?  * Emulate utimes(2) using utime(2), but losing sub-second granularity.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<utime.h>
end_include

begin_function
name|int
name|utimes
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|times
parameter_list|)
block|{
if|if
condition|(
name|times
operator|!=
name|NULL
condition|)
block|{
name|struct
name|utimbuf
name|ut
decl_stmt|;
name|ut
operator|.
name|actime
operator|=
name|times
index|[
literal|0
index|]
operator|.
name|tv_sec
expr_stmt|;
name|ut
operator|.
name|modtime
operator|=
name|times
index|[
literal|1
index|]
operator|.
name|tv_sec
expr_stmt|;
return|return
operator|(
name|utime
argument_list|(
name|path
argument_list|,
operator|&
name|ut
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
name|utime
argument_list|(
name|path
argument_list|,
name|NULL
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

