begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|RCSNETHDR
value|"$Header: net.h,v 1.14 85/07/31 09:32:54 walsh Exp $"
end_define

begin_comment
comment|/*  * dummy protocol number(s) for raw input.  Not real like UDPROTO/TCPROTO/...  */
end_comment

begin_define
define|#
directive|define
name|NETLOG_PROTO
value|62
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/*  * Software interrupt version  *  * This version of the network code runs off software interrupts rather than  * as a separate process.  The software interrupt level for the network is  * higher than the software level for the clock (so you can enter the network  * in routines called from timeouts).  User process routines switch into  * network code by doing splnet().  */
end_comment

begin_comment
comment|/* splnet is defined in ../sys/asm.sed */
end_comment

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|mtpr(SIRR, 12)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|n_short
typedef|;
end_typedef

begin_comment
comment|/* short as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_long
typedef|;
end_typedef

begin_comment
comment|/* long as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|sequence
typedef|;
end_typedef

begin_comment
comment|/* sequence numbers in tcp */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|net_t
typedef|;
end_typedef

begin_comment
comment|/* network number */
end_comment

begin_comment
comment|/*  * This structure describes the work that the finite state machine  * procedure is supposed to do.  At one time, these were chained  * together and batch processing performed on them.  Code would need  * reworking to go back to that method since work entry has pointer  * to tcpcb, which may have been closed and freed.  */
end_comment

begin_struct
struct|struct
name|work
block|{
name|short
name|w_type
decl_stmt|;
comment|/* what to do with entry */
name|short
name|w_stype
decl_stmt|;
comment|/* subtype for timer names */
name|struct
name|tcpcb
modifier|*
name|w_tcb
decl_stmt|;
comment|/* -> tcb for entry */
name|char
modifier|*
name|w_dat
decl_stmt|;
comment|/* -> work data chain */
block|}
struct|;
end_struct

begin_comment
comment|/*  * No need to spl when enter network via action, since network is only  * accessed via softare interrupt [splnet], tcp_usrreq(), and tcp_timeo()  * which splnet().  */
end_comment

begin_define
define|#
directive|define
name|w_alloc
parameter_list|(
name|type
parameter_list|,
name|stype
parameter_list|,
name|tp
parameter_list|,
name|m
parameter_list|)
define|\
value|{									\ 	struct work w;							\ 									\ 	w.w_type = type; w.w_stype = stype; w.w_tcb = tp; 		\ 	w.w_dat = (char *)m;						\ 	(void) action(&w);						\ }
end_define

begin_define
define|#
directive|define
name|NETHASH
parameter_list|(
name|x
parameter_list|)
value|((u_long) iptonet(x))
end_define

begin_define
define|#
directive|define
name|HOSTHASH
parameter_list|(
name|x
parameter_list|)
value|((u_long) htonl((u_long) (x)))
end_define

begin_comment
comment|/* make an ip addr */
end_comment

begin_define
define|#
directive|define
name|ipaddr
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((long)(((z)<<24)|((y)<<16)|((x)<<8)|(w)))
end_define

begin_struct
struct|struct
name|dfilter
block|{
name|struct
name|in_addr
name|foreign_host
decl_stmt|;
name|struct
name|in_addr
name|local_host
decl_stmt|;
name|u_short
name|foreign_port
decl_stmt|;
name|u_short
name|local_port
decl_stmt|;
name|int
name|matches
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|u_long
name|iptime
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|dfilter
name|tcp_dfilter
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|in_addr
name|icmp_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|in_addr
name|redir_addr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_comment
comment|/* replace with dynamic estimate of remote send buffering */
end_comment

begin_define
define|#
directive|define
name|MINTCPBUF
value|256
end_define

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

end_unit

