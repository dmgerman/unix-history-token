begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ns_pcb.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNS_NS_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNS_NS_PCB_H_
end_define

begin_comment
comment|/*  * Ns protocol interface control block.  */
end_comment

begin_struct
struct|struct
name|nspcb
block|{
name|struct
name|nspcb
modifier|*
name|nsp_next
decl_stmt|;
comment|/* doubly linked list */
name|struct
name|nspcb
modifier|*
name|nsp_prev
decl_stmt|;
name|struct
name|socket
modifier|*
name|nsp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|ns_addr
name|nsp_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|ns_addr
name|nsp_laddr
decl_stmt|;
comment|/* socket's address */
name|caddr_t
name|nsp_pcb
decl_stmt|;
comment|/* protocol specific stuff */
name|struct
name|route
name|nsp_route
decl_stmt|;
comment|/* routing information */
name|struct
name|ns_addr
name|nsp_lastdst
decl_stmt|;
comment|/* validate cached route for dg socks*/
name|long
name|nsp_notify_param
decl_stmt|;
comment|/* extra info passed via ns_pcbnotify*/
name|short
name|nsp_flags
decl_stmt|;
name|u_char
name|nsp_dpt
decl_stmt|;
comment|/* default packet type for idp_output*/
name|u_char
name|nsp_rpt
decl_stmt|;
comment|/* last received packet type by 								idp_input() */
block|}
struct|;
end_struct

begin_comment
comment|/* possible flags */
end_comment

begin_define
define|#
directive|define
name|NSP_IN_ABORT
value|0x1
end_define

begin_comment
comment|/* calling abort through socket */
end_comment

begin_define
define|#
directive|define
name|NSP_RAWIN
value|0x2
end_define

begin_comment
comment|/* show headers on input */
end_comment

begin_define
define|#
directive|define
name|NSP_RAWOUT
value|0x4
end_define

begin_comment
comment|/* show header on output */
end_comment

begin_define
define|#
directive|define
name|NSP_ALL_PACKETS
value|0x8
end_define

begin_comment
comment|/* Turn off higher proto processing */
end_comment

begin_define
define|#
directive|define
name|NS_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|nsp_lport
value|nsp_laddr.x_port
end_define

begin_define
define|#
directive|define
name|nsp_fport
value|nsp_faddr.x_port
end_define

begin_define
define|#
directive|define
name|sotonspcb
parameter_list|(
name|so
parameter_list|)
value|((struct nspcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Nominal space allocated to a ns socket.  */
end_comment

begin_define
define|#
directive|define
name|NSSNDQ
value|2048
end_define

begin_define
define|#
directive|define
name|NSRCVQ
value|2048
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|nspcb
name|nspcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list */
end_comment

begin_function_decl
name|struct
name|nspcb
modifier|*
name|ns_pcblookup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

