begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 23 May 93*/
end_comment

begin_comment
comment|/*  * testsyscall.c  *  * Test program to call the sample loaded system call.  *  * 23 May 93	Terry Lambert		Original  *  *  * Copyright (c) 1993 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|char
name|buf
index|[
literal|80
index|]
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"Table offset as reported by modstat: "
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
name|stdin
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"[ABORT]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|err
operator|=
name|syscall
argument_list|(
name|atoi
argument_list|(
name|buf
argument_list|)
comment|/* no arguments*/
argument_list|)
operator|)
condition|)
name|perror
argument_list|(
literal|"syscall"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|err
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

