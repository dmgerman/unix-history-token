begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)raw_cb.h	7.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Raw protocol interface control block.  Used  * to tie a socket to the generic raw interface.  */
end_comment

begin_struct
struct|struct
name|rawcb
block|{
name|struct
name|rawcb
modifier|*
name|rcb_next
decl_stmt|;
comment|/* doubly linked list */
name|struct
name|rawcb
modifier|*
name|rcb_prev
decl_stmt|;
name|struct
name|socket
modifier|*
name|rcb_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sockaddr
name|rcb_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|sockaddr
name|rcb_laddr
decl_stmt|;
comment|/* socket's address */
name|struct
name|sockproto
name|rcb_proto
decl_stmt|;
comment|/* protocol family, protocol */
name|caddr_t
name|rcb_pcb
decl_stmt|;
comment|/* protocol specific stuff */
name|struct
name|mbuf
modifier|*
name|rcb_options
decl_stmt|;
comment|/* protocol specific options */
name|struct
name|route
name|rcb_route
decl_stmt|;
comment|/* routing information */
name|short
name|rcb_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Since we can't interpret canonical addresses,  * we mark an address present in the flags field.  */
end_comment

begin_define
define|#
directive|define
name|RAW_LADDR
value|01
end_define

begin_define
define|#
directive|define
name|RAW_FADDR
value|02
end_define

begin_define
define|#
directive|define
name|RAW_DONTROUTE
value|04
end_define

begin_comment
comment|/* no routing, default */
end_comment

begin_define
define|#
directive|define
name|sotorawcb
parameter_list|(
name|so
parameter_list|)
value|((struct rawcb *)(so)->so_pcb)
end_define

begin_comment
comment|/*  * Nominal space allocated to a raw socket.  */
end_comment

begin_define
define|#
directive|define
name|RAWSNDQ
value|2048
end_define

begin_define
define|#
directive|define
name|RAWRCVQ
value|2048
end_define

begin_comment
comment|/*  * Format of raw interface header prepended by  * raw_input after call from protocol specific  * input routine.  */
end_comment

begin_struct
struct|struct
name|raw_header
block|{
name|struct
name|sockproto
name|raw_proto
decl_stmt|;
comment|/* format of packet */
name|struct
name|sockaddr
name|raw_dst
decl_stmt|;
comment|/* dst address for rawintr */
name|struct
name|sockaddr
name|raw_src
decl_stmt|;
comment|/* src address for sbappendaddr */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|rawcb
name|rawcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

