begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by the 3am Software Foundry ("3am").  It was developed by Matt Thomas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_FLOW_H
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_FLOW_H
end_define

begin_struct
struct|struct
name|ipflow
block|{
name|LIST_ENTRY
argument_list|(
argument|ipflow
argument_list|)
name|ipf_next
expr_stmt|;
comment|/* next ipflow in bucket */
name|struct
name|in_addr
name|ipf_dst
decl_stmt|;
comment|/* destination address */
name|struct
name|in_addr
name|ipf_src
decl_stmt|;
comment|/* source address */
name|u_int8_t
name|ipf_tos
decl_stmt|;
comment|/* type-of-service */
name|struct
name|route
name|ipf_ro
decl_stmt|;
comment|/* associated route entry */
name|u_long
name|ipf_uses
decl_stmt|;
comment|/* number of uses in this period */
name|int
name|ipf_timer
decl_stmt|;
comment|/* remaining lifetime of this entry */
name|u_long
name|ipf_dropped
decl_stmt|;
comment|/* ENOBUFS returned by if_output */
name|u_long
name|ipf_errors
decl_stmt|;
comment|/* other errors returned by if_output */
name|u_long
name|ipf_last_uses
decl_stmt|;
comment|/* number of uses in last period */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

