begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"roken.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: bswap.c,v 1.3 2001/05/18 15:32:11 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BSWAP32
end_ifndef

begin_function
name|unsigned
name|int
name|bswap32
parameter_list|(
name|unsigned
name|int
name|val
parameter_list|)
block|{
return|return
operator|(
name|val
operator|&
literal|0xff
operator|)
operator|<<
literal|24
operator||
operator|(
name|val
operator|&
literal|0xff00
operator|)
operator|<<
literal|8
operator||
operator|(
name|val
operator|&
literal|0xff0000
operator|)
operator|>>
literal|8
operator||
operator|(
name|val
operator|&
literal|0xff000000
operator|)
operator|>>
literal|24
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BSWAP16
end_ifndef

begin_function
name|unsigned
name|short
name|bswap16
parameter_list|(
name|unsigned
name|short
name|val
parameter_list|)
block|{
return|return
operator|(
name|val
operator|&
literal|0xff
operator|)
operator|<<
literal|8
operator||
operator|(
name|val
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

