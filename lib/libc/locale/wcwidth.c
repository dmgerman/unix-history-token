begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_define
define|#
directive|define
name|_CTYPE_SWM
value|0xe0000000L
end_define

begin_comment
comment|/* Mask to get screen width data */
end_comment

begin_define
define|#
directive|define
name|_CTYPE_SWS
value|30
end_define

begin_comment
comment|/* Bits to shift to get width */
end_comment

begin_function
name|int
name|wcwidth
parameter_list|(
name|wchar_t
name|wc
parameter_list|)
block|{
name|unsigned
name|int
name|x
decl_stmt|;
if|if
condition|(
name|wc
operator|==
literal|L'
expr|\0'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|x
operator|=
operator|(
name|unsigned
name|int
operator|)
name|__maskrune
argument_list|(
name|wc
argument_list|,
name|_CTYPE_SWM
operator||
name|_CTYPE_R
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|&
name|_CTYPE_SWM
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|x
operator|&
name|_CTYPE_SWM
operator|)
operator|>>
name|_CTYPE_SWS
operator|)
return|;
return|return
operator|(
operator|(
name|x
operator|&
name|_CTYPE_R
operator|)
operator|!=
literal|0
condition|?
literal|1
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

