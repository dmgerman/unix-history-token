begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 - 1999  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|"prutil.h"
end_include

begin_function
name|int
name|memlock
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|e
init|=
literal|0
decl_stmt|;
comment|/* Is memory locking configured? 	 */
name|errno
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|sysconf
argument_list|(
name|_SC_MEMLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
comment|/* This isn't valid - may be a standard violation 			 */
name|quit
argument_list|(
literal|"(should not happen) sysconf(_SC_MEMLOCK)"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Memory locking is not supported in this environment.\n"
argument_list|)
expr_stmt|;
name|e
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
comment|/* Lock yourself in memory: 	 */
if|if
condition|(
name|mlockall
argument_list|(
name|MCL_CURRENT
operator||
name|MCL_FUTURE
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"mlockall(MCL_CURRENT | MCL_FUTURE)"
argument_list|)
expr_stmt|;
name|e
operator|=
name|errno
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|munlockall
argument_list|()
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
literal|"munlockall"
argument_list|)
expr_stmt|;
name|e
operator|=
name|errno
expr_stmt|;
block|}
return|return
name|e
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|NO_MEMLOCK
end_ifdef

begin_function
name|int
name|mlockall
parameter_list|(
name|int
name|flags
parameter_list|)
block|{
return|return
name|EOPNOTSUPP
return|;
block|}
end_function

begin_function
name|int
name|munlockall
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EOPNOTSUPP
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STANDALONE_TESTS
end_ifdef

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
return|return
name|memlock
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

