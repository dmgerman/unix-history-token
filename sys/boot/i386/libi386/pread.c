begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * From: $NetBSD: pread.c,v 1.2 1997/03/22 01:48:38 thorpej Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/* read into destination in flat addr space */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"libi386.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SAVE_MEMORY
end_ifdef

begin_define
define|#
directive|define
name|BUFSIZE
value|(1*1024)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUFSIZE
value|(4*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|buf
index|[
name|BUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|pread
parameter_list|(
name|fd
parameter_list|,
name|dest
parameter_list|,
name|size
parameter_list|)
name|int
name|fd
decl_stmt|;
name|vm_offset_t
name|dest
decl_stmt|;
name|int
name|size
decl_stmt|;
block|{
name|int
name|rsize
decl_stmt|;
name|rsize
operator|=
name|size
expr_stmt|;
while|while
condition|(
name|rsize
operator|>
literal|0
condition|)
block|{
name|int
name|count
decl_stmt|,
name|got
decl_stmt|;
name|count
operator|=
operator|(
name|rsize
operator|<
name|BUFSIZE
condition|?
name|rsize
else|:
name|BUFSIZE
operator|)
expr_stmt|;
name|got
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
expr_stmt|;
if|if
condition|(
name|got
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* put to physical space */
name|vpbcopy
argument_list|(
name|buf
argument_list|,
name|dest
argument_list|,
name|got
argument_list|)
expr_stmt|;
name|dest
operator|+=
name|got
expr_stmt|;
name|rsize
operator|-=
name|got
expr_stmt|;
if|if
condition|(
name|got
operator|<
name|count
condition|)
break|break;
comment|/* EOF */
block|}
return|return
operator|(
name|size
operator|-
name|rsize
operator|)
return|;
block|}
end_function

end_unit

