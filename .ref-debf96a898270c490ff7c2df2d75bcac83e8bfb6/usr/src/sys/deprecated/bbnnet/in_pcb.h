begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSINPCBHDR
value|"$Header: in_pcb.h,v 1.7 85/07/31 09:31:17 walsh Exp $"
end_define

begin_comment
comment|/*  * Common structure pcb for internet protocol implementation.  * Here are stored pointers to local and foreign host table  * entries, local and foreign socket numbers, and pointers  * up (to a socket structure) and down (to a protocol-specific)  * control block.  */
end_comment

begin_define
define|#
directive|define
name|MAX_IPOPTLEN
value|60
end_define

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
name|in_addr
name|inp_faddr
decl_stmt|;
comment|/* foreign host table entry */
name|struct
name|in_addr
name|inp_laddr
decl_stmt|;
comment|/* local host table entry */
name|u_short
name|inp_fport
decl_stmt|;
comment|/* foreign port */
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
comment|/* routing entry */
name|char
name|inp_optlen
decl_stmt|;
name|char
name|inp_options
index|[
name|MAX_IPOPTLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * protocol specific structure passed to some pcb controlling routines.  * new in 4.3 because addition of new protocols required a more generalized  * in_pcbbind().  rootport<= resvport<= maxport.  non-superuser can  * bind rootport -> maxport, but kernel will bind resvport -> maxport so  * that projects can test things without being root and without fearing  * someone may accidentally take their port.  */
end_comment

begin_struct
struct|struct
name|pr_advice
block|{
name|u_short
name|rootport
decl_stmt|;
comment|/* ports reserved exclusively for root */
name|u_short
name|resvport
decl_stmt|;
comment|/* ports reserved from random allocation */
name|u_short
name|maxport
decl_stmt|;
comment|/* absolute max port */
name|u_short
name|nowport
decl_stmt|;
comment|/* port last used, initialize to resvport! */
name|u_short
name|portsize
decl_stmt|;
comment|/* size of port (in bytes) */
name|int
function_decl|(
modifier|*
name|bind_used
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine called to check before binding */
block|}
struct|;
end_struct

begin_comment
comment|/*  * protocol specific setsockopt/getsockopt calls.  */
end_comment

begin_define
define|#
directive|define
name|SO_IPROUTE
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
specifier|extern
name|struct
name|inpcb
modifier|*
name|in_pcblookup
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|uwake
parameter_list|(
name|inp
parameter_list|)
define|\
value|{						\ 	sbwakeup(&inp->inp_socket->so_rcv);	\ 	sbwakeup(&inp->inp_socket->so_snd);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

