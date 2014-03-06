begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcbind.h,v 1.1 2000/06/03 00:47:21 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/* #ident	"@(#)rpcbind.h 1.4 90/04/12 SMI" */
end_comment

begin_comment
comment|/*  * rpcbind.h  * The common header declarations  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|rpcbind_h
end_ifndef

begin_define
define|#
directive|define
name|rpcbind_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PORTMAP
end_ifdef

begin_include
include|#
directive|include
file|<rpc/pmap_prot.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<rpc/rpcb_prot.h>
end_include

begin_comment
comment|/*  * Stuff for the rmtcall service  */
end_comment

begin_struct
struct|struct
name|encap_parms
block|{
name|u_int32_t
name|arglen
decl_stmt|;
name|char
modifier|*
name|args
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|r_rmtcall_args
block|{
name|u_int32_t
name|rmt_prog
decl_stmt|;
name|u_int32_t
name|rmt_vers
decl_stmt|;
name|u_int32_t
name|rmt_proc
decl_stmt|;
name|int
name|rmt_localvers
decl_stmt|;
comment|/* whether to send port # or uaddr */
name|char
modifier|*
name|rmt_uaddr
decl_stmt|;
name|struct
name|encap_parms
name|rmt_args
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|debugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doabort
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LIBWRAP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|libwrap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|verboselog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insecure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|oldstyle_local
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rpcblist_ptr
name|list_rbl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of version 3& 4 rpcbind services */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PORTMAP
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pmaplist
modifier|*
name|list_pml
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of version 2 rpcbind services */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|udptrans
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of UDP transport */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tcptrans
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of TCP transport */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|udp_uaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Universal UDP address */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tcp_uaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Universal TCP address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|add_bndlist
parameter_list|(
name|struct
name|netconfig
modifier|*
parameter_list|,
name|struct
name|netbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|is_bound
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mergeaddr
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netconfig
modifier|*
name|rpcbind_get_conf
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_procinfo
parameter_list|(
name|rpcvers_t
parameter_list|,
name|rpcproc_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_set
parameter_list|(
name|rpcvers_t
parameter_list|,
name|bool_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_unset
parameter_list|(
name|rpcvers_t
parameter_list|,
name|bool_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_getaddr
parameter_list|(
name|rpcvers_t
parameter_list|,
name|rpcprog_t
parameter_list|,
name|rpcvers_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbs_rmtcall
parameter_list|(
name|rpcvers_t
parameter_list|,
name|rpcproc_t
parameter_list|,
name|rpcprog_t
parameter_list|,
name|rpcvers_t
parameter_list|,
name|rpcproc_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|rpcblist_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_getstat
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcb_service_3
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcb_service_4
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Common functions shared between versions */
end_comment

begin_function_decl
name|void
modifier|*
name|rpcbproc_set_com
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_unset_com
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|map_set
parameter_list|(
name|RPCB
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool_t
name|map_unset
parameter_list|(
name|RPCB
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|delete_prog
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_getaddr_com
parameter_list|(
name|RPCB
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_gettime_com
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_uaddr2taddr_com
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rpcbproc_taddr2uaddr_com
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|create_rmtcall_fd
parameter_list|(
name|struct
name|netconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbproc_callit_com
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcvers_t
parameter_list|,
name|rpcvers_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|my_svc_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpcbind_abort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reap
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|toggle_verboselog
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_access
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|rpcproc_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_callit
parameter_list|(
name|SVCXPRT
modifier|*
parameter_list|,
name|struct
name|r_rmtcall_args
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logit
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|rpcproc_t
parameter_list|,
name|rpcprog_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_loopback
parameter_list|(
name|struct
name|netbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PORTMAP
end_ifdef

begin_function_decl
specifier|extern
name|void
name|pmap_service
parameter_list|(
name|struct
name|svc_req
modifier|*
parameter_list|,
name|SVCXPRT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|write_warmstart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_warmstart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|addrmerge
parameter_list|(
name|struct
name|netbuf
modifier|*
name|caller
parameter_list|,
name|char
modifier|*
name|serv_uaddr
parameter_list|,
name|char
modifier|*
name|clnt_uaddr
parameter_list|,
name|char
modifier|*
name|netid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|listen_addr
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|network_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sockaddr
modifier|*
name|local_sa
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For different getaddr semantics */
end_comment

begin_define
define|#
directive|define
name|RPCB_ALLVERS
value|0
end_define

begin_define
define|#
directive|define
name|RPCB_ONEVERS
value|1
end_define

begin_comment
comment|/* To convert a struct sockaddr to IPv4 or IPv6 address */
end_comment

begin_define
define|#
directive|define
name|SA2SIN
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in *)(sa))
end_define

begin_define
define|#
directive|define
name|SA2SINADDR
parameter_list|(
name|sa
parameter_list|)
value|(SA2SIN(sa)->sin_addr)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|SA2SIN6
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_in6 *)(sa))
end_define

begin_define
define|#
directive|define
name|SA2SIN6ADDR
parameter_list|(
name|sa
parameter_list|)
value|(SA2SIN6(sa)->sin6_addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rpcbind_h */
end_comment

end_unit

