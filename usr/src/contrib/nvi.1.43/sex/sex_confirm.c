begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)sex_confirm.c	9.3 (Berkeley) 11/13/94"
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|"compat.h"
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
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
file|"sex_screen.h"
end_include

begin_function
name|enum
name|confirm
name|sex_confirm
parameter_list|(
name|sp
parameter_list|,
name|fp
parameter_list|,
name|tp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|MARK
modifier|*
name|fp
decl_stmt|,
decl|*
name|tp
decl_stmt|;
end_function

begin_block
block|{
name|enum
name|confirm
name|rval
decl_stmt|;
name|CH
name|ikey
decl_stmt|;
if|if
condition|(
name|ex_print
argument_list|(
name|sp
argument_list|,
name|fp
argument_list|,
name|tp
argument_list|,
literal|0
argument_list|)
condition|)
return|return
operator|(
name|CONF_QUIT
operator|)
return|;
if|if
condition|(
name|ex_scprint
argument_list|(
name|sp
argument_list|,
name|fp
argument_list|,
name|tp
argument_list|)
condition|)
return|return
operator|(
name|CONF_QUIT
operator|)
return|;
if|if
condition|(
name|term_key
argument_list|(
name|sp
argument_list|,
operator|&
name|ikey
argument_list|,
literal|0
argument_list|)
operator|!=
name|INP_OK
condition|)
name|rval
operator|=
name|CONF_QUIT
expr_stmt|;
else|else
switch|switch
condition|(
name|ikey
operator|.
name|ch
condition|)
block|{
case|case
name|CH_YES
case|:
name|rval
operator|=
name|CONF_YES
expr_stmt|;
break|break;
case|case
name|CH_QUIT
case|:
name|rval
operator|=
name|CONF_QUIT
expr_stmt|;
break|break;
default|default:
case|case
name|CH_NO
case|:
name|rval
operator|=
name|CONF_NO
expr_stmt|;
break|break;
block|}
comment|/* 	 * XXX 	 * This should almost certainly be fed through the ex print routines 	 * -- leave it alone until we make nvi wide character clean. 	 */
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|sp
operator|->
name|stdfp
argument_list|,
literal|"%c\n"
argument_list|,
name|ikey
operator|.
name|ch
argument_list|)
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_block

end_unit

