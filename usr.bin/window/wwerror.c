begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)wwerror.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_function
name|char
modifier|*
name|wwerror
parameter_list|()
block|{
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
switch|switch
condition|(
name|wwerrno
condition|)
block|{
case|case
name|WWE_NOERR
case|:
return|return
literal|"No error"
return|;
case|case
name|WWE_SYS
case|:
return|return
name|strerror
argument_list|(
name|errno
argument_list|)
return|;
case|case
name|WWE_NOMEM
case|:
return|return
literal|"Out of memory"
return|;
case|case
name|WWE_TOOMANY
case|:
return|return
literal|"Too many windows"
return|;
case|case
name|WWE_NOPTY
case|:
return|return
literal|"Out of pseudo-terminals"
return|;
case|case
name|WWE_SIZE
case|:
return|return
literal|"Bad window size"
return|;
case|case
name|WWE_BADTERM
case|:
return|return
literal|"Unknown terminal type"
return|;
case|case
name|WWE_CANTDO
case|:
return|return
literal|"Can't run window on this terminal"
return|;
default|default:
return|return
literal|"Unknown error"
return|;
block|}
block|}
end_function

end_unit

