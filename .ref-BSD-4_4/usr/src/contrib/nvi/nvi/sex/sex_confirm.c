begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)sex_confirm.c	8.1 (Berkeley) 6/9/93"
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

begin_define
define|#
directive|define
name|CONFIRMCHAR
value|'y'
end_define

begin_comment
comment|/* Make change character. */
end_comment

begin_define
define|#
directive|define
name|QUITCHAR
value|'q'
end_define

begin_comment
comment|/* Quit character. */
end_comment

begin_function
name|enum
name|confirmation
name|sex_confirm
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|fp
parameter_list|,
name|tp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
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
name|recno_t
name|cnt
decl_stmt|;
if|if
condition|(
name|ex_print
argument_list|(
name|sp
argument_list|,
name|ep
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
name|QUIT
operator|)
return|;
for|for
control|(
name|cnt
operator|=
name|fp
operator|->
name|cno
init|;
name|cnt
condition|;
operator|--
name|cnt
control|)
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|' '
argument_list|,
name|sp
operator|->
name|stdfp
argument_list|)
expr_stmt|;
for|for
control|(
name|cnt
operator|=
name|tp
operator|->
name|cno
init|;
name|cnt
condition|;
operator|--
name|cnt
control|)
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'^'
argument_list|,
name|sp
operator|->
name|stdfp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|sp
operator|->
name|stdfp
argument_list|,
literal|"[ynq]"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|term_key
argument_list|(
name|sp
argument_list|,
literal|0
argument_list|)
condition|)
block|{
case|case
name|CONFIRMCHAR
case|:
return|return
operator|(
name|YES
operator|)
return|;
case|case
name|QUITCHAR
case|:
return|return
operator|(
name|QUIT
operator|)
return|;
default|default:
return|return
operator|(
name|NO
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_block

end_unit

