begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ex_stop.c	8.4 (Berkeley) 10/28/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"excmd.h"
end_include

begin_include
include|#
directive|include
file|"sex/sex_screen.h"
end_include

begin_comment
comment|/*  * ex_stop -- :stop[!]  *	      :suspend[!]  *	Suspend execution.  */
end_comment

begin_function
name|int
name|ex_stop
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|cmdp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
decl_stmt|;
name|EXCMDARG
modifier|*
name|cmdp
decl_stmt|;
block|{
comment|/* For some strange reason, the force flag turns off autowrite. */
if|if
condition|(
name|F_ISSET
argument_list|(
name|ep
argument_list|,
name|F_MODIFIED
argument_list|)
operator|&&
name|O_ISSET
argument_list|(
name|sp
argument_list|,
name|O_AUTOWRITE
argument_list|)
operator|&&
operator|!
name|F_ISSET
argument_list|(
name|cmdp
argument_list|,
name|E_FORCE
argument_list|)
condition|)
block|{
if|if
condition|(
name|file_write
argument_list|(
operator|(
name|sp
operator|)
argument_list|,
operator|(
name|ep
operator|)
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FS_ALL
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|sex_refresh
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|sp
operator|->
name|s_suspend
argument_list|(
name|sp
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

