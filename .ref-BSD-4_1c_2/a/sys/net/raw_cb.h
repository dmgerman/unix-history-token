begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	raw_cb.h	4.4	82/04/10	*/
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
name|caddr_t
name|rcb_pcb
decl_stmt|;
comment|/* protocol specific stuff */
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

