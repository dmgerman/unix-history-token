begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*static char *sccsid = "from: @(#)fclose.c	5.2 (Berkeley) 2/1/91";*/
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: fclose.c,v 1.15 1994/01/27 06:07:48 proven Exp $"
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
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/* Do not reset the fd */
end_comment

begin_expr_stmt
name|fclose
argument_list|(
name|fp
argument_list|)
specifier|register
name|FILE
operator|*
name|fp
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|r
decl_stmt|;
if|if
condition|(
name|fp
operator|->
name|_flags
condition|)
block|{
name|flockfile
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|r
operator|=
name|fp
operator|->
name|_flags
operator|&
name|__SWR
condition|?
name|__sflush
argument_list|(
name|fp
argument_list|)
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|__sclose
argument_list|(
name|fp
argument_list|)
operator|<
literal|0
condition|)
name|r
operator|=
name|EOF
expr_stmt|;
if|if
condition|(
name|fp
operator|->
name|_flags
operator|&
name|__SMBF
condition|)
name|free
argument_list|(
operator|(
name|char
operator|*
operator|)
name|fp
operator|->
name|_bf
operator|.
name|_base
argument_list|)
expr_stmt|;
if|if
condition|(
name|HASUB
argument_list|(
name|fp
argument_list|)
condition|)
name|FREEUB
argument_list|(
name|fp
argument_list|)
expr_stmt|;
if|if
condition|(
name|HASLB
argument_list|(
name|fp
argument_list|)
condition|)
name|FREELB
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|fp
operator|->
name|_flags
operator|=
literal|0
expr_stmt|;
comment|/* release this FILE for reuse, DO THIS LAST */
name|funlockfile
argument_list|(
name|fp
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
name|EOF
operator|)
return|;
block|}
end_block

end_unit

