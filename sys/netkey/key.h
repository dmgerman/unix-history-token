begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: key.h,v 1.20 2001/03/22 08:09:32 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETKEY_KEY_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETKEY_KEY_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|key_cb
name|key_cb
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|secpolicy
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secpolicyindex
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipsecrequest
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|secasvar
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sadb_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sadb_x_policy
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_allocsp
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicyindex
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_gettunnel
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_checkrequest
name|__P
argument_list|(
operator|(
expr|struct
name|ipsecrequest
operator|*
name|isr
operator|,
expr|struct
name|secasindex
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secasvar
modifier|*
name|key_allocsa
name|__P
argument_list|(
operator|(
name|u_int
operator|,
name|caddr_t
operator|,
name|caddr_t
operator|,
name|u_int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_freesp
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_freeso
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_freesav
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_newsp
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
name|struct
name|secpolicy
modifier|*
name|key_msg2sp
name|__P
argument_list|(
operator|(
expr|struct
name|sadb_x_policy
operator|*
operator|,
name|size_t
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mbuf
modifier|*
name|key_sp2msg
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_ismyaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_spdacquire
name|__P
argument_list|(
operator|(
expr|struct
name|secpolicy
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_timehandler
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
name|u_long
name|key_random
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
name|key_randomfill
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_freereg
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|key_parse
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|socket
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_init
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
name|int
name|key_checktunnelsanity
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|,
name|u_int
operator|,
name|caddr_t
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_sa_recordxfer
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_sa_routechange
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|key_sa_stir_iv
name|__P
argument_list|(
operator|(
expr|struct
name|secasvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SECA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MALLOC_DECLARE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETKEY_KEY_H_ */
end_comment

end_unit

