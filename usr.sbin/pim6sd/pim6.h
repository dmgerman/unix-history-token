begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 LSIIT Laboratory.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PIM6_H
end_ifndef

begin_define
define|#
directive|define
name|PIM6_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<netinet6/ip6_mroute.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in6
name|allpim6routers_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pim6_send_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pim6_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_pim6
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_pim6
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|src
operator|,
expr|struct
name|sockaddr_in6
operator|*
name|dst
operator|,
name|int
name|type
operator|,
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

