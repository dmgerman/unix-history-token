begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"probe.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_comment
comment|/* Does select() alter the passed time value ? */
end_comment

begin_function
specifier|static
name|int
name|select_changes_time
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timeval
name|t
decl_stmt|;
name|t
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|=
literal|100000
expr_stmt|;
name|select
argument_list|(
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
name|t
operator|.
name|tv_usec
operator|!=
literal|100000
return|;
block|}
end_function

begin_function
name|void
name|probe_Init
parameter_list|(
name|struct
name|probe
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|select_changes_time
operator|=
name|select_changes_time
argument_list|()
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|log_Printf
argument_list|(
name|LogDEBUG
argument_list|,
literal|"Select changes time: %s\n"
argument_list|,
name|p
operator|->
name|select_changes_time
condition|?
literal|"yes"
else|:
literal|"no"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

