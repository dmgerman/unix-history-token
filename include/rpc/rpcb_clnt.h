begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rpcb_clnt.h,v 1.1 2000/06/02 22:57:56 fvdl Exp $	*/
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
comment|/*  * rpcb_clnt.h  * Supplies C routines to get to rpcbid services.  *  */
end_comment

begin_comment
comment|/*  * Usage:  *	success = rpcb_set(program, version, nconf, address);  *	success = rpcb_unset(program, version, nconf);  *	success = rpcb_getaddr(program, version, nconf, host);  *	head = rpcb_getmaps(nconf, host);  *	clnt_stat = rpcb_rmtcall(nconf, host, program, version, procedure,  *		xdrargs, argsp, xdrres, resp, tout, addr_ptr)  *	success = rpcb_gettime(host, timep)  *	uaddr = rpcb_taddr2uaddr(nconf, taddr);  *	taddr = rpcb_uaddr2uaddr(nconf, uaddr);  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCB_CLNT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCB_CLNT_H
end_define

begin_comment
comment|/* #pragma ident	"@(#)rpcb_clnt.h	1.13	94/04/25 SMI" */
end_comment

begin_comment
comment|/* rpcb_clnt.h 1.3 88/12/05 SMI */
end_comment

begin_include
include|#
directive|include
file|<rpc/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpcb_prot.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|rpcb_set
name|__P
argument_list|(
operator|(
specifier|const
name|rpcprog_t
operator|,
specifier|const
name|rpcvers_t
operator|,
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
expr|struct
name|netbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|rpcb_unset
name|__P
argument_list|(
operator|(
specifier|const
name|rpcprog_t
operator|,
specifier|const
name|rpcvers_t
operator|,
specifier|const
expr|struct
name|netconfig
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rpcblist
modifier|*
name|rpcb_getmaps
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|clnt_stat
name|rpcb_rmtcall
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|rpcprog_t
operator|,
specifier|const
name|rpcvers_t
operator|,
specifier|const
name|rpcproc_t
operator|,
specifier|const
name|xdrproc_t
operator|,
specifier|const
name|caddr_t
operator|,
specifier|const
name|xdrproc_t
operator|,
specifier|const
name|caddr_t
operator|,
specifier|const
expr|struct
name|timeval
operator|,
specifier|const
expr|struct
name|netbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|rpcb_getaddr
name|__P
argument_list|(
operator|(
specifier|const
name|rpcprog_t
operator|,
specifier|const
name|rpcvers_t
operator|,
specifier|const
expr|struct
name|netconfig
operator|*
operator|,
expr|struct
name|netbuf
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool_t
name|rpcb_gettime
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rpcb_taddr2uaddr
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
specifier|extern
name|struct
name|netbuf
modifier|*
name|rpcb_uaddr2taddr
name|__P
argument_list|(
operator|(
expr|struct
name|netconfig
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_RPCB_CLNT_H */
end_comment

end_unit

