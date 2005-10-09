begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	layer1.c - isdndecode, decode and print layer 1 information  *	-----------------------------------------------------------  *  *	$Id: layer1.c,v 1.4 1999/12/13 21:25:25 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:50:34 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"decode.h"
end_include

begin_comment
comment|/*---------------------------------------------------------------------------*  *	decode layer 1 information  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|layer1
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
block|{
switch|switch
condition|(
operator|*
name|buf
condition|)
block|{
case|case
name|INFO0
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO0 (No Signal)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO1_8
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO1 (Activation Request, Priority = 8)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO1_10
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO1 (Activation Request, Priority = 10)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO2
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO2 (Pending Activation)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO3
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO3 (Synchronized)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO4_8
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO4 (Activated, Priority = 8/9)\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|INFO4_10
case|:
name|strcpy
argument_list|(
name|buffer
argument_list|,
literal|"L1 INFO4 (Activated, Priority = 10/11)\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|sprintf
argument_list|(
name|buffer
argument_list|,
literal|"L1 ERROR, invalid INFO value 0x%x!\n"
argument_list|,
operator|*
name|buf
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* EOF */
end_comment

end_unit

