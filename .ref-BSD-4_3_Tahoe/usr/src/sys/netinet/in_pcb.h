begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)in_pcb.h	7.3 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Common structure pcb for internet protocol implementation.  * Here are stored pointers to local and foreign host table  * entries, local and foreign socket numbers, and pointers  * up (to a socket structure) and down (to a protocol-specific)  * control block.  */
end_comment

begin_struct
struct|struct
name|inpcb
block|{
name|struct
name|inpcb
modifier|*
name|inp_next
decl_stmt|,
modifier|*
name|inp_prev
decl_stmt|;
comment|/* pointers to other pcb's */
name|struct
name|inpcb
modifier|*
name|inp_head
decl_stmt|;
comment|/* pointer back to chain of inpcb's 					   for this protocol */
name|struct
name|in_addr
name|inp_faddr
decl_stmt|;
comment|/* foreign host table entry */
name|u_short
name|inp_fport
decl_stmt|;
comment|/* foreign port */
name|struct
name|in_addr
name|inp_laddr
decl_stmt|;
comment|/* local host table entry */
name|u_short
name|inp_lport
decl_stmt|;
comment|/* local port */
name|struct
name|socket
modifier|*
name|inp_socket
decl_stmt|;
comment|/* back pointer to socket */
name|caddr_t
name|inp_ppcb
decl_stmt|;
comment|/* pointer to per-protocol pcb */
name|struct
name|route
name|inp_route
decl_stmt|;
comment|/* placeholder for routing entry */
name|struct
name|mbuf
modifier|*
name|inp_options
decl_stmt|;
comment|/* IP options */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INPLOOKUP_WILDCARD
value|1
end_define

begin_define
define|#
directive|define
name|INPLOOKUP_SETLOCAL
value|2
end_define

begin_define
define|#
directive|define
name|sotoinpcb
parameter_list|(
name|so
parameter_list|)
value|((struct inpcb *)(so)->so_pcb)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|inpcb
modifier|*
name|in_pcblookup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

