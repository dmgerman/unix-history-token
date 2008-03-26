begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pmap_prot.h,v 1.8 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *  * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *  * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  *  *	from: @(#)pmap_prot.h 1.14 88/02/08 SMI   *	from: @(#)pmap_prot.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * pmap_prot.h  * Protocol for the local binder service, or pmap.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  *  * The following procedures are supported by the protocol:  *  * PMAPPROC_NULL() returns ()  * 	takes nothing, returns nothing  *  * PMAPPROC_SET(struct pmap) returns (bool_t)  * 	TRUE is success, FALSE is failure.  Registers the tuple  *	[prog, vers, prot, port].  *  * PMAPPROC_UNSET(struct pmap) returns (bool_t)  *	TRUE is success, FALSE is failure.  Un-registers pair  *	[prog, vers].  prot and port are ignored.  *  * PMAPPROC_GETPORT(struct pmap) returns (long unsigned).  *	0 is failure.  Otherwise returns the port number where the pair  *	[prog, vers] is registered.  It may lie!  *  * PMAPPROC_DUMP() RETURNS (struct pmaplist *)  *  * PMAPPROC_CALLIT(unsigned, unsigned, unsigned, string<>)  * 	RETURNS (port, string<>);  * usage: encapsulatedresults = PMAPPROC_CALLIT(prog, vers, proc, encapsulatedargs);  * 	Calls the procedure on the local machine.  If it is not registered,  *	this procedure is quite; ie it does not return error information!!!  *	This procedure only is supported on rpc/udp and calls via  *	rpc/udp.  This routine only passes null authentication parameters.  *	This file has no interface to xdr routines for PMAPPROC_CALLIT.  *  * The service supports remote procedure calls on udp/ip or tcp/ip socket 111.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_PMAP_PROT_H
end_ifndef

begin_define
define|#
directive|define
name|_RPC_PMAP_PROT_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|PMAPPORT
value|((u_short)111)
end_define

begin_define
define|#
directive|define
name|PMAPPROG
value|((u_long)100000)
end_define

begin_define
define|#
directive|define
name|PMAPVERS
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|PMAPVERS_PROTO
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|PMAPVERS_ORIG
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_SET
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_UNSET
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_GETPORT
value|((u_long)3)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_DUMP
value|((u_long)4)
end_define

begin_define
define|#
directive|define
name|PMAPPROC_CALLIT
value|((u_long)5)
end_define

begin_struct
struct|struct
name|pmap
block|{
name|long
name|unsigned
name|pm_prog
decl_stmt|;
name|long
name|unsigned
name|pm_vers
decl_stmt|;
name|long
name|unsigned
name|pm_prot
decl_stmt|;
name|long
name|unsigned
name|pm_port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmaplist
block|{
name|struct
name|pmap
name|pml_map
decl_stmt|;
name|struct
name|pmaplist
modifier|*
name|pml_next
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|bool_t
name|xdr_pmap
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|pmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_pmaplist
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|pmaplist
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_pmaplist_ptr
parameter_list|(
name|XDR
modifier|*
parameter_list|,
name|struct
name|pmaplist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RPC_PMAP_PROT_H */
end_comment

end_unit

