begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *   * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SOCKET_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: sockbuf.c,v 1.3 1999/12/02 16:58:29 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|set_buffer_size
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|read
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|SO_RCVBUF
argument_list|)
operator|&&
name|defined
argument_list|(
name|SO_SNDBUF
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETSOCKOPT
argument_list|)
name|size_t
name|size
init|=
literal|4194304
decl_stmt|;
while|while
condition|(
name|size
operator|>=
literal|131072
operator|&&
name|setsockopt
argument_list|(
name|fd
argument_list|,
name|SOL_SOCKET
argument_list|,
name|read
condition|?
name|SO_RCVBUF
else|:
name|SO_SNDBUF
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|&
name|size
argument_list|,
sizeof|sizeof
argument_list|(
name|size
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
name|size
operator|/=
literal|2
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

