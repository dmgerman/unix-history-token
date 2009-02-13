begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IP_DIVERT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IP_DIVERT_H_
end_define

begin_comment
comment|/*  * Sysctl declaration.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_divert
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Divert socket definitions.  */
end_comment

begin_struct
struct|struct
name|divert_tag
block|{
name|u_int32_t
name|info
decl_stmt|;
comment|/* port& flags */
name|u_int16_t
name|cookie
decl_stmt|;
comment|/* ipfw rule number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Return the divert cookie associated with the mbuf; if any.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int16_t
name|divert_cookie
parameter_list|(
name|struct
name|m_tag
modifier|*
name|mtag
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|divert_tag
operator|*
operator|)
operator|(
name|mtag
operator|+
literal|1
operator|)
operator|)
operator|->
name|cookie
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|divert_find_cookie
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|struct
name|m_tag
modifier|*
name|mtag
init|=
name|m_tag_find
argument_list|(
name|m
argument_list|,
name|PACKET_TAG_DIVERT
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
return|return
name|mtag
condition|?
name|divert_cookie
argument_list|(
name|mtag
argument_list|)
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Return the divert info associated with the mbuf; if any.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int32_t
name|divert_info
parameter_list|(
name|struct
name|m_tag
modifier|*
name|mtag
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|divert_tag
operator|*
operator|)
operator|(
name|mtag
operator|+
literal|1
operator|)
operator|)
operator|->
name|info
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|divert_find_info
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|struct
name|m_tag
modifier|*
name|mtag
init|=
name|m_tag_find
argument_list|(
name|m
argument_list|,
name|PACKET_TAG_DIVERT
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
return|return
name|mtag
condition|?
name|divert_info
argument_list|(
name|mtag
argument_list|)
else|:
literal|0
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|void
name|ip_divert_packet_t
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|incoming
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|ip_divert_packet_t
modifier|*
name|ip_divert_ptr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|div_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|div_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|div_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IP_DIVERT_H_ */
end_comment

end_unit

