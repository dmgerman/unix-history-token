begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).   * All rights reserved.   *  * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   *  * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *  * 3. Neither the name of KTH nor the names of its contributors may be  *    used to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY KTH AND ITS CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KTH OR ITS CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_comment
comment|/* $Id: hash.h,v 1.1 1999/03/22 19:16:25 joda Exp $ */
end_comment

begin_comment
comment|/* stuff in common between md4, md5, and sha1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__hash_h__
end_ifndef

begin_define
define|#
directive|define
name|__hash_h__
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(b):(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Vector Crays doesn't have a good 32-bit type, or more precisely,    int32_t as defined by<bind/bitypes.h> isn't 32 bits, and we don't    want to depend in being able to redefine this type.  To cope with    this we have to clamp the result in some places to [0,2^32); no    need to do this on other machines.  Did I say this was a mess?    */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAY
end_ifdef

begin_define
define|#
directive|define
name|CRAYFIX
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xffffffff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CRAYFIX
parameter_list|(
name|X
parameter_list|)
value|(X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|u_int32_t
name|cshift
parameter_list|(
name|u_int32_t
name|x
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
block|{
name|x
operator|=
name|CRAYFIX
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|CRAYFIX
argument_list|(
operator|(
name|x
operator|<<
name|n
operator|)
operator||
operator|(
name|x
operator|>>
operator|(
literal|32
operator|-
name|n
operator|)
operator|)
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hash_h__ */
end_comment

end_unit

