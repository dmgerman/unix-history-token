begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_l1lib.c - general useful L1 procedures  *	------------------------------------------  *  *	$Id: i4b_l1lib.c,v 1.3 2000/05/29 15:41:41 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon May 29 15:24:21 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_trace.h>
end_include

begin_include
include|#
directive|include
file|<i4b/layer1/i4b_l1.h>
end_include

begin_define
define|#
directive|define
name|TEL_IDLE_MIN
value|(BCH_MAX_DATALEN/2)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	telephony silence detection  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|int
name|i4b_l1_bchan_tel_silence
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
block|{
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|j
init|=
literal|0
decl_stmt|;
comment|/* count idle bytes */
for|for
control|(
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|data
operator|>=
literal|0xaa
operator|)
operator|&&
operator|(
operator|*
name|data
operator|<=
literal|0xac
operator|)
condition|)
name|j
operator|++
expr_stmt|;
name|data
operator|++
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|NOTDEF
name|printf
argument_list|(
literal|"i4b_l1_bchan_tel_silence: got %d silence bytes in frame\n"
argument_list|,
name|j
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|j
operator|<
operator|(
name|TEL_IDLE_MIN
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
else|else
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

