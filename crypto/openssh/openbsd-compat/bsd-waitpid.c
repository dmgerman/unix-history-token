begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Ben Lindstrom.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bsd-waitpid.c,v 1.5 2003/06/01 03:23:57 mouring Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_WAITPID
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|"bsd-waitpid.h"
end_include

begin_function
name|pid_t
name|waitpid
parameter_list|(
name|int
name|pid
parameter_list|,
name|int
modifier|*
name|stat_loc
parameter_list|,
name|int
name|options
parameter_list|)
block|{
name|union
name|wait
name|statusp
decl_stmt|;
name|pid_t
name|wait_pid
decl_stmt|;
if|if
condition|(
name|pid
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|pid
operator|!=
operator|-
literal|1
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* wait4() wants pid=0 for indiscriminate wait. */
name|pid
operator|=
literal|0
expr_stmt|;
block|}
name|wait_pid
operator|=
name|wait4
argument_list|(
name|pid
argument_list|,
operator|&
name|statusp
argument_list|,
name|options
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat_loc
condition|)
operator|*
name|stat_loc
operator|=
operator|(
name|int
operator|)
name|statusp
operator|.
name|w_status
expr_stmt|;
return|return
operator|(
name|wait_pid
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_WAITPID */
end_comment

end_unit

