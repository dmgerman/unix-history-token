begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1987 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)mesg.c	4.7 (Berkeley) 3/1/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * mesg -- set current tty to accept or  *	forbid write permission.  *  *	mesg [y] [n]  *		y allow messages  *		n forbid messages  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tty
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OTHER_WRITE
value|020
end_define

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|struct
name|stat
name|sbuf
decl_stmt|;
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
if|if
condition|(
operator|!
operator|(
name|tty
operator|=
name|ttyname
argument_list|(
literal|2
argument_list|)
operator|)
condition|)
block|{
name|fputs
argument_list|(
literal|"mesg: not a device in /dev.\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|stat
argument_list|(
name|tty
argument_list|,
operator|&
name|sbuf
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"mesg"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
if|if
condition|(
name|sbuf
operator|.
name|st_mode
operator|&
name|OTHER_WRITE
condition|)
block|{
name|fputs
argument_list|(
literal|"is y\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
literal|"is n\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
operator|*
name|argv
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'y'
case|:
name|newmode
argument_list|(
name|sbuf
operator|.
name|st_mode
operator||
name|OTHER_WRITE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'n'
case|:
name|newmode
argument_list|(
name|sbuf
operator|.
name|st_mode
operator|&
operator|~
name|OTHER_WRITE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
default|default:
name|fputs
argument_list|(
literal|"usage: mesg [y|n]\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/*NOTREACHED*/
block|}
end_function

begin_macro
name|newmode
argument_list|(
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|u_short
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chmod
argument_list|(
name|tty
argument_list|,
name|m
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"mesg"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

