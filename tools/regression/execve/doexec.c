begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: doexec.c,v 1.8 2003/07/26 19:38:48 salo Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *          This product includes software developed for the  *          NetBSD Project.  See http://www.NetBSD.org/ for  *          information about NetBSD.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
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
name|argv
index|[]
decl_stmt|;
block|{
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: %s<progname>\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
name|unsetenv
argument_list|(
literal|"LANG"
argument_list|)
expr_stmt|;
comment|/* we compare C error strings */
if|if
condition|(
name|execve
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
operator|&
name|argv
index|[
literal|1
index|]
argument_list|,
name|NULL
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

