begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)raw_cb.h	7.7 (Berkeley) %G%  */
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
modifier|*
name|rcb_faddr
decl_stmt|;
comment|/* destination address */
name|struct
name|sockaddr
modifier|*
name|rcb_laddr
decl_stmt|;
comment|/* socket's address */
name|struct
name|sockproto
name|rcb_proto
decl_stmt|;
comment|/* protocol family, protocol */
block|}
struct|;
end_struct

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
value|8192
end_define

begin_define
define|#
directive|define
name|RAWRCVQ
value|8192
end_define

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

begin_decl_stmt
name|int
name|raw_attach
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|raw_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|raw_detach
name|__P
argument_list|(
operator|(
expr|struct
name|rawcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|raw_disconnect
name|__P
argument_list|(
operator|(
expr|struct
name|rawcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|raw_init
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
name|raw_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockproto
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|raw_usrreq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

