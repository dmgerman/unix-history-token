begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ns_pcb.h	7.3 (Berkeley) 6/29/88  */
end_comment

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
name|nspcb
modifier|*
name|nsp_head
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
name|KERNEL
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

end_unit

