begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1996 Christos Zoulas.   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Christos Zoulas.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SOCKET_H_
end_define

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_struct_decl
struct_decl|struct
name|sockaddr_un
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|svr4_sockaddr_in
block|{
name|u_char
name|sin_family
decl_stmt|;
name|u_short
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|u_char
name|sin_zero
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|sockaddr_un
modifier|*
name|svr4_find_socket
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|file
operator|*
operator|,
name|udev_t
operator|,
name|ino_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|svr4_delete_socket
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|file
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_add_socket
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVR4_SOCKET_H_ */
end_comment

end_unit

