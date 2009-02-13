begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/******************************************************************************  *  * Filename: p_string.c  *  * Instantiation of basic string operations to prevent inclusion of full  * string library.  These are simple implementations not necessarily optimized  * for speed, but rather to show intent.  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  * 12JAN2005	kb_admin	minor updates  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/*  * .KB_C_FN_DEFINITION_START  * int p_strlen(char *)  *  This global function returns the number of bytes starting at the pointer  * before (not including) the string termination character ('/0').  * .KB_C_FN_DEFINITION_END  */
end_comment

begin_function
name|int
name|p_strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|buffer
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|ptr
init|=
name|buffer
decl_stmt|;
while|while
condition|(
operator|*
name|ptr
operator|++
condition|)
continue|continue;
return|return
operator|(
name|ptr
operator|-
name|buffer
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

