begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, Mike Mitchell  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipxip.h  *  * $Id: ipx_ip.h,v 1.11 1997/06/26 19:35:50 jhay Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPXIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPXIP_H_
end_define

begin_struct
struct|struct
name|ifnet_en
block|{
name|struct
name|ifnet
name|ifen_ifnet
decl_stmt|;
name|struct
name|route
name|ifen_route
decl_stmt|;
name|struct
name|in_addr
name|ifen_src
decl_stmt|;
name|struct
name|in_addr
name|ifen_dst
decl_stmt|;
name|struct
name|ifnet_en
modifier|*
name|ifen_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOMTU
value|(1024+512)
end_define

begin_comment
comment|/* XXX this is TINY_LOMTU */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|ipxip_ctlinput
name|__P
argument_list|(
operator|(
name|int
name|cmd
operator|,
expr|struct
name|sockaddr
operator|*
name|sa
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipxip_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|,
name|int
name|hlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipxip_route
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockopt
operator|*
name|sopt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_IPXIP_H_ */
end_comment

end_unit

