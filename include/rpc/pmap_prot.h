begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pmap_prot.h,v 1.8 2000/06/02 22:57:55 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009, Sun Microsystems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  * - Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  * - Redistributions in binary form must reproduce the above copyright notice,  *   this list of conditions and the following disclaimer in the documentation  *   and/or other materials provided with the distribution.  * - Neither the name of Sun Microsystems, Inc. nor the names of its  *   contributors may be used to endorse or promote products derived  *   from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: @(#)pmap_prot.h 1.14 88/02/08 SMI   *	from: @(#)pmap_prot.h	2.1 88/07/29 4.0 RPCSRC  * $FreeBSD$  */
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

