begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcbind.h,v 1.1 2000/06/03 00:47:21 fvdl Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
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

begin_decl_stmt
name|int
name|add_bndlist
name|__P
argument_list|(
operator|(
expr|struct
name|netconfig
operator|*
operator|,
expr|struct
name|netbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|is_bound
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mergeaddr
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|netconfig
modifier|*
name|rpcbind_get_conf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_procinfo
name|__P
argument_list|(
operator|(
name|rpcvers_t
operator|,
name|rpcproc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_set
name|__P
argument_list|(
operator|(
name|rpcvers_t
operator|,
name|bool_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_unset
name|__P
argument_list|(
operator|(
name|rpcvers_t
operator|,
name|bool_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_getaddr
name|__P
argument_list|(
operator|(
name|rpcvers_t
operator|,
name|rpcprog_t
operator|,
name|rpcvers_t
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbs_rmtcall
name|__P
argument_list|(
operator|(
name|rpcvers_t
operator|,
name|rpcproc_t
operator|,
name|rpcprog_t
operator|,
name|rpcvers_t
operator|,
name|rpcproc_t
operator|,
name|char
operator|*
operator|,
name|rpcblist_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_getstat
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcb_service_3
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcb_service_4
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Common functions shared between versions */
end_comment

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_set_com
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_unset_com
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|map_set
name|__P
argument_list|(
operator|(
name|RPCB
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool_t
name|map_unset
name|__P
argument_list|(
operator|(
name|RPCB
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|delete_prog
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_getaddr_com
name|__P
argument_list|(
operator|(
name|RPCB
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_gettime_com
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_uaddr2taddr_com
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|rpcbproc_taddr2uaddr_com
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|create_rmtcall_fd
name|__P
argument_list|(
operator|(
expr|struct
name|netconfig
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbproc_callit_com
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|,
name|rpcvers_t
operator|,
name|rpcvers_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|my_svc_run
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpcbind_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reap
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|toggle_verboselog
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_access
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
name|rpcproc_t
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|check_callit
name|__P
argument_list|(
operator|(
name|SVCXPRT
operator|*
operator|,
expr|struct
name|r_rmtcall_args
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logit
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|rpcproc_t
operator|,
name|rpcprog_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_loopback
name|__P
argument_list|(
operator|(
expr|struct
name|netbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PORTMAP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|pmap_service
name|__P
argument_list|(
operator|(
expr|struct
name|svc_req
operator|*
operator|,
name|SVCXPRT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|write_warmstart
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_warmstart
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|addrmerge
name|__P
argument_list|(
operator|(
expr|struct
name|netbuf
operator|*
name|caller
operator|,
name|char
operator|*
name|serv_uaddr
operator|,
name|char
operator|*
name|clnt_uaddr
operator|,
name|char
operator|*
name|netid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|network_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|local_sa
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rpcbind_h */
end_comment

end_unit

