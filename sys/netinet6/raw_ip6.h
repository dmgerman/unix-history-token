begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: raw_ip6.h,v 1.2 2001/05/27 13:28:35 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2001 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET6_RAW_IP6_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET6_RAW_IP6_H_
end_define

begin_comment
comment|/*  * ICMPv6 stat is counted separately.  see netinet/icmp6.h  */
end_comment

begin_struct
struct|struct
name|rip6stat
block|{
name|u_quad_t
name|rip6s_ipackets
decl_stmt|;
comment|/* total input packets */
name|u_quad_t
name|rip6s_isum
decl_stmt|;
comment|/* input checksum computations */
name|u_quad_t
name|rip6s_badsum
decl_stmt|;
comment|/* of above, checksum error */
name|u_quad_t
name|rip6s_nosock
decl_stmt|;
comment|/* no matching socket */
name|u_quad_t
name|rip6s_nosockmcast
decl_stmt|;
comment|/* of above, arrived as multicast */
name|u_quad_t
name|rip6s_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|u_quad_t
name|rip6s_opackets
decl_stmt|;
comment|/* total output packets */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|rip6stat
name|rip6stat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

