begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  * Copyright (c) 2004-2006 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ipx_pcb.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_IPX_PCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_IPX_PCB_H_
end_define

begin_comment
comment|/*  * IPX protocol interface control block.  */
end_comment

begin_struct
struct|struct
name|ipxpcb
block|{
name|LIST_ENTRY
argument_list|(
argument|ipxpcb
argument_list|)
name|ipxp_list
expr_stmt|;
name|struct
name|socket
modifier|*
name|ipxp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|ipx_addr
name|ipxp_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|ipx_addr
name|ipxp_laddr
decl_stmt|;
comment|/* socket's address */
name|caddr_t
name|ipxp_pcb
decl_stmt|;
comment|/* protocol specific stuff */
name|struct
name|route
name|ipxp_route
decl_stmt|;
comment|/* routing information */
name|struct
name|ipx_addr
name|ipxp_lastdst
decl_stmt|;
comment|/* validate cached route for dg socks*/
name|short
name|ipxp_flags
decl_stmt|;
name|u_char
name|ipxp_dpt
decl_stmt|;
comment|/* default packet type for ipx_output */
name|u_char
name|ipxp_rpt
decl_stmt|;
comment|/* last received packet type by ipx_input() */
name|struct
name|mtx
name|ipxp_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Additional IPX pcb-related types and variables.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ipxpcbhead
argument_list|,
name|ipxpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipxpcbhead
name|ipxpcb_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipxpcbhead
name|ipxrawpcb_list
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ipxpcb_list_mtx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IPX/SPX PCB flags.  */
end_comment

begin_define
define|#
directive|define
name|IPXP_IN_ABORT
value|0x1
end_define

begin_comment
comment|/* Calling abort through socket. */
end_comment

begin_define
define|#
directive|define
name|IPXP_RAWIN
value|0x2
end_define

begin_comment
comment|/* Show headers on input. */
end_comment

begin_define
define|#
directive|define
name|IPXP_RAWOUT
value|0x4
end_define

begin_comment
comment|/* Show header on output. */
end_comment

begin_define
define|#
directive|define
name|IPXP_ALL_PACKETS
value|0x8
end_define

begin_comment
comment|/* Turn off higher proto processing. */
end_comment

begin_define
define|#
directive|define
name|IPXP_CHECKSUM
value|0x10
end_define

begin_comment
comment|/* Use checksum on this socket. */
end_comment

begin_define
define|#
directive|define
name|IPXP_DROPPED
value|0x20
end_define

begin_comment
comment|/* Connection dropped. */
end_comment

begin_define
define|#
directive|define
name|IPXP_SPX
value|0x40
end_define

begin_comment
comment|/* SPX PCB. */
end_comment

begin_define
define|#
directive|define
name|IPX_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|ipxp_lport
value|ipxp_laddr.x_port
end_define

begin_define
define|#
directive|define
name|ipxp_fport
value|ipxp_faddr.x_port
end_define

begin_define
define|#
directive|define
name|sotoipxpcb
parameter_list|(
name|so
parameter_list|)
value|((struct ipxpcb *)((so)->so_pcb))
end_define

begin_comment
comment|/*  * Nominal space allocated to an IPX socket.  */
end_comment

begin_define
define|#
directive|define
name|IPXSNDQ
value|16384
end_define

begin_define
define|#
directive|define
name|IPXRCVQ
value|40960
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|ipx_pcballoc
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|ipxpcbhead
modifier|*
name|head
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipx_pcbbind
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ipx_pcbconnect
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipx_pcbdetach
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipx_pcbdisconnect
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipx_pcbfree
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ipxpcb
modifier|*
name|ipx_pcblookup
parameter_list|(
name|struct
name|ipx_addr
modifier|*
name|faddr
parameter_list|,
name|int
name|lport
parameter_list|,
name|int
name|wildp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipx_setpeeraddr
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipx_setsockaddr
parameter_list|(
name|struct
name|ipxpcb
modifier|*
name|ipxp
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IPX_LIST_LOCK_INIT
parameter_list|()
value|mtx_init(&ipxpcb_list_mtx, "ipx_list_mtx", \ 				    NULL, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|IPX_LIST_LOCK
parameter_list|()
value|mtx_lock(&ipxpcb_list_mtx)
end_define

begin_define
define|#
directive|define
name|IPX_LIST_UNLOCK
parameter_list|()
value|mtx_unlock(&ipxpcb_list_mtx)
end_define

begin_define
define|#
directive|define
name|IPX_LIST_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&ipxpcb_list_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IPX_LOCK_INIT
parameter_list|(
name|ipx
parameter_list|)
value|mtx_init(&(ipx)->ipxp_mtx, "ipx_mtx", NULL, \ 				    MTX_DEF)
end_define

begin_define
define|#
directive|define
name|IPX_LOCK_DESTROY
parameter_list|(
name|ipx
parameter_list|)
value|mtx_destroy(&(ipx)->ipxp_mtx)
end_define

begin_define
define|#
directive|define
name|IPX_LOCK
parameter_list|(
name|ipx
parameter_list|)
value|mtx_lock(&(ipx)->ipxp_mtx)
end_define

begin_define
define|#
directive|define
name|IPX_UNLOCK
parameter_list|(
name|ipx
parameter_list|)
value|mtx_unlock(&(ipx)->ipxp_mtx)
end_define

begin_define
define|#
directive|define
name|IPX_LOCK_ASSERT
parameter_list|(
name|ipx
parameter_list|)
value|mtx_assert(&(ipx)->ipxp_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_IPX_PCB_H_ */
end_comment

end_unit

