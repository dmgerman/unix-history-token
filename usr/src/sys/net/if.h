begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if.h	4.13	82/05/24	*/
end_comment

begin_comment
comment|/*  * Structures defining a network interface, providing a packet  * transport mechanism (ala level 0 of the PUP protocols).  *  * Each interface accepts output datagrams of a specified maximum  * length, and provides higher level routines with input datagrams  * received from its medium.  *  * Output occurs when the routine if_output is called, with three parameters:  *	(*ifp->if_output)(ifp, m, dst)  * Here m is the mbuf chain to be sent and dst is the destination address.  * The output routine encapsulates the supplied datagram if necessary,  * and then transmits it on its medium.  *  * On input, each interface unwraps the data received by it, and either  * places it on the input queue of a internetwork datagram routine  * and posts the associated software interrupt, or passes the datagram to a raw  * packet input routine.  *  * Routines exist for locating interfaces by their addresses  * or for locating a interface on a certain network, as well as more general  * routing and gateway routines maintaining information used to locate  * interfaces.  These routines live in the files if.c and route.c  */
end_comment

begin_comment
comment|/*  * Structure defining a queue for a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
end_comment

begin_struct
struct|struct
name|ifnet
block|{
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* name, e.g. ``en'' or ``lo'' */
name|short
name|if_unit
decl_stmt|;
comment|/* sub-unit for lower level driver */
name|short
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|short
name|if_net
decl_stmt|;
comment|/* network number of interface */
name|short
name|if_flags
decl_stmt|;
comment|/* up/down, broadcast, etc. */
name|int
name|if_host
index|[
literal|2
index|]
decl_stmt|;
comment|/* local net host number */
name|struct
name|sockaddr
name|if_addr
decl_stmt|;
comment|/* address of interface */
union|union
block|{
name|struct
name|sockaddr
name|ifu_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|ifu_dstaddr
decl_stmt|;
block|}
name|if_ifu
union|;
define|#
directive|define
name|if_broadaddr
value|if_ifu.ifu_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|if_dstaddr
value|if_ifu.ifu_dstaddr
comment|/* other end of p-to-p link */
struct|struct
name|ifqueue
block|{
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|int
name|ifq_len
decl_stmt|;
name|int
name|ifq_maxlen
decl_stmt|;
name|int
name|ifq_drops
decl_stmt|;
block|}
name|if_snd
struct|;
comment|/* output queue */
comment|/* procedure handles */
name|int
function_decl|(
modifier|*
name|if_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* init routine */
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* output routine */
name|int
function_decl|(
modifier|*
name|if_ubareset
function_decl|)
parameter_list|()
function_decl|;
comment|/* uba reset routine */
comment|/* generic interface statistics */
name|int
name|if_ipackets
decl_stmt|;
comment|/* packets received on interface */
name|int
name|if_ierrors
decl_stmt|;
comment|/* input errors on interface */
name|int
name|if_opackets
decl_stmt|;
comment|/* packets sent on interface */
name|int
name|if_oerrors
decl_stmt|;
comment|/* output errors on interface */
name|int
name|if_collisions
decl_stmt|;
comment|/* collisions on csma interfaces */
comment|/* end statistics */
name|struct
name|ifnet
modifier|*
name|if_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IFF_UP
value|0x1
end_define

begin_comment
comment|/* interface is up */
end_comment

begin_define
define|#
directive|define
name|IFF_BROADCAST
value|0x2
end_define

begin_comment
comment|/* broadcast address valid */
end_comment

begin_define
define|#
directive|define
name|IFF_DEBUG
value|0x4
end_define

begin_comment
comment|/* turn on debugging */
end_comment

begin_define
define|#
directive|define
name|IFF_ROUTE
value|0x8
end_define

begin_comment
comment|/* routing entry installed */
end_comment

begin_define
define|#
directive|define
name|IFF_POINTOPOINT
value|0x10
end_define

begin_comment
comment|/* interface is point-to-point link */
end_comment

begin_comment
comment|/*  * Output queues (ifp->if_snd) and internetwork datagram level (pup level 1)  * input routines have queues of messages stored on ifqueue structures  * (defined above).  Entries are added to and deleted from these structures  * by these macros, which should be called with ipl raised to splimp().  */
end_comment

begin_define
define|#
directive|define
name|IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len>= (ifq)->ifq_maxlen)
end_define

begin_define
define|#
directive|define
name|IF_DROP
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_drops++)
end_define

begin_define
define|#
directive|define
name|IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m)->m_act = 0; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_head = m; \ 	else \ 		(ifq)->ifq_tail->m_act = m; \ 	(ifq)->ifq_tail = m; \ 	(ifq)->ifq_len++; \ }
end_define

begin_define
define|#
directive|define
name|IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m)->m_act = (ifq)->ifq_head; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_tail = (m); \ 	(ifq)->ifq_head = (m); \ 	(ifq)->ifq_len++; \ }
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m) = (ifq)->ifq_head; \ 	if (m) { \ 		if (((ifq)->ifq_head = (m)->m_act) == 0) \ 			(ifq)->ifq_tail = 0; \ 		(m)->m_act = 0; \ 		(ifq)->ifq_len--; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IFQ_MAXLEN
value|50
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|ifqueue
name|rawintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raw packet input queue */
end_comment

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifnet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|if_ifwithaddr
argument_list|()
decl_stmt|,
modifier|*
name|if_ifwithnet
argument_list|()
decl_stmt|,
modifier|*
name|if_ifwithaf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|ifnet
modifier|*
name|if_ifonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|if_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

