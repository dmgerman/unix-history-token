begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: key.h,v 1.21 2001/07/27 03:51:30 itojun Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPSEC_KEY_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPSEC_KEY_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_struct_decl
struct_decl|struct
name|secasindex
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|sockaddr_union
union_decl|;
end_union_decl

begin_function_decl
specifier|extern
name|void
name|key_addref
parameter_list|(
name|struct
name|secpolicy
modifier|*
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|key_havesp
parameter_list|(
name|u_int
name|dir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_allocsp
parameter_list|(
name|struct
name|secpolicyindex
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_allocsp2
parameter_list|(
name|u_int32_t
name|spi
parameter_list|,
name|union
name|sockaddr_union
modifier|*
name|dst
parameter_list|,
name|u_int8_t
name|proto
parameter_list|,
name|u_int
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|secpolicy
modifier|*
name|key_newsp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern struct secpolicy *key_gettunnel(const struct sockaddr *, 	const struct sockaddr *, const struct sockaddr *, 	const struct sockaddr *, const char*, int);
endif|#
directive|endif
end_endif

begin_comment
comment|/* NB: prepend with _ for KAME IPv6 compatbility */
end_comment

begin_function_decl
specifier|extern
name|void
name|_key_freesp
parameter_list|(
name|struct
name|secpolicy
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KEY_ALLOCSP
parameter_list|(
name|spidx
parameter_list|,
name|dir
parameter_list|)
define|\
value|key_allocsp(spidx, dir, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|KEY_ALLOCSP2
parameter_list|(
name|spi
parameter_list|,
name|dst
parameter_list|,
name|proto
parameter_list|,
name|dir
parameter_list|)
define|\
value|key_allocsp2(spi, dst, proto, dir, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|KEY_NEWSP
parameter_list|()
define|\
value|key_newsp(__FILE__, __LINE__)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|KEY_GETTUNNEL
parameter_list|(
name|osrc
parameter_list|,
name|odst
parameter_list|,
name|isrc
parameter_list|,
name|idst
parameter_list|)
define|\
value|key_gettunnel(osrc, odst, isrc, idst, __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KEY_FREESP
parameter_list|(
name|spp
parameter_list|)
define|\
value|_key_freesp(spp, __FILE__, __LINE__)
end_define

begin_function_decl
specifier|extern
name|struct
name|secasvar
modifier|*
name|key_allocsa
parameter_list|(
name|union
name|sockaddr_union
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int32_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|key_addrefsa
parameter_list|(
name|struct
name|secasvar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|key_freesav
parameter_list|(
name|struct
name|secasvar
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KEY_ALLOCSA
parameter_list|(
name|dst
parameter_list|,
name|proto
parameter_list|,
name|spi
parameter_list|)
define|\
value|key_allocsa(dst, proto, spi, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|KEY_ADDREFSA
parameter_list|(
name|sav
parameter_list|)
define|\
value|key_addrefsa(sav, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|KEY_FREESAV
parameter_list|(
name|psav
parameter_list|)
define|\
value|key_freesav(psav, __FILE__, __LINE__)
end_define

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
specifier|const
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

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|key_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|IPSEC_NAT_T
end_ifdef

begin_function_decl
name|u_int16_t
name|key_portfromsaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KEY_PORTFROMSADDR
parameter_list|(
name|saddr
parameter_list|)
define|\
value|key_portfromsaddr((struct sockaddr *)(saddr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SAH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_MISC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SAQ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_SAR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPSEC_INPCB
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
comment|/* _NETIPSEC_KEY_H_ */
end_comment

end_unit

