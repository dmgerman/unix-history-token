begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Christopher G. Demetriou  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: ftime.c,v 1.3 1994/05/06 06:42:21 cgd Exp $"
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_macro
name|ftime
argument_list|(
argument|tbp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeb
modifier|*
name|tbp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|timezone
name|tz
decl_stmt|;
name|struct
name|timeval
name|t
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|t
argument_list|,
operator|&
name|tz
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|tbp
operator|->
name|millitm
operator|=
name|t
operator|.
name|tv_usec
operator|/
literal|1000
expr_stmt|;
name|tbp
operator|->
name|time
operator|=
name|t
operator|.
name|tv_sec
expr_stmt|;
name|tbp
operator|->
name|timezone
operator|=
name|tz
operator|.
name|tz_minuteswest
expr_stmt|;
name|tbp
operator|->
name|dstflag
operator|=
name|tz
operator|.
name|tz_dsttime
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

