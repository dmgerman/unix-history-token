begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)pmap_clnt.h	2.1 88/07/29 4.0 RPCSRC; from 1.11 88/02/08 SMI */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * pmap_clnt.h  * Supplies C routines to get to portmap services.  *  * Copyright (C) 1984, Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Usage:  *	success = pmap_set(program, version, protocol, port);  *	success = pmap_unset(program, version);  *	port = pmap_getport(address, program, version, protocol);  *	head = pmap_getmaps(address);  *	clnt_stat = pmap_rmtcall(address, program, version, procedure,  *		xdrargs, argsp, xdrres, resp, tout, port_ptr)  *		(works for udp only.)   * 	clnt_stat = clnt_broadcast(program, version, procedure,  *		xdrargs, argsp,	xdrres, resp, eachresult)  *		(like pmap_rmtcall, except the call is broadcasted to all  *		locally connected nets.  For each valid response received,  *		the procedure eachresult is called.  Its form is:  *	done = eachresult(resp, raddr)  *		bool_t done;  *		caddr_t resp;  *		struct sockaddr_in raddr;  *		where resp points to the results of the call and raddr is the  *		address if the responder to the broadcast.  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|pmap_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|pmap_unset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pmaplist
modifier|*
name|pmap_getmaps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|clnt_stat
name|pmap_rmtcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|clnt_stat
name|clnt_broadcast
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|pmap_getport
parameter_list|()
function_decl|;
end_function_decl

end_unit

