begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.11	82/11/02	*/
end_comment

begin_comment
comment|/*  * Internal data structure definitions for  * user routing process.  Based on Xerox NS  * protocol specs with mods relevant to more  * general addressing scheme.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/in.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|"rip.h"
end_include

begin_comment
comment|/*  * Trace record format.  */
end_comment

begin_struct
struct|struct
name|iftrace
block|{
name|time_t
name|ift_stamp
decl_stmt|;
comment|/* time stamp */
name|struct
name|sockaddr
name|ift_who
decl_stmt|;
comment|/* from/to */
name|char
modifier|*
name|ift_packet
decl_stmt|;
comment|/* pointer to packet */
name|short
name|ift_size
decl_stmt|;
comment|/* size of packet */
name|short
name|ift_metric
decl_stmt|;
comment|/* metric on associated metric */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per interface packet tracing buffers.  An incoming and  * outgoing circular buffer of packets is maintained, per  * interface, for debugging.  Buffers are dumped whenever  * an interface is marked down.  */
end_comment

begin_struct
struct|struct
name|ifdebug
block|{
name|struct
name|iftrace
modifier|*
name|ifd_records
decl_stmt|;
comment|/* array of trace records */
name|struct
name|iftrace
modifier|*
name|ifd_front
decl_stmt|;
comment|/* next empty trace record */
name|struct
name|interface
modifier|*
name|ifd_if
decl_stmt|;
comment|/* for locating stuff */
block|}
struct|;
end_struct

begin_comment
comment|/*  * An ``interface'' is similar to an ifnet structure,  * except it doesn't contain q'ing info, and it also  * handles ``logical'' interfaces (remote gateways  * that we want to keep polling even if they go down).  * The list of interfaces which we maintain is used  * in supplying the gratuitous routing table updates.  */
end_comment

begin_struct
struct|struct
name|interface
block|{
name|struct
name|interface
modifier|*
name|int_next
decl_stmt|;
name|struct
name|sockaddr
name|int_addr
decl_stmt|;
comment|/* address on this host */
union|union
block|{
name|struct
name|sockaddr
name|intu_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|intu_dstaddr
decl_stmt|;
block|}
name|int_intu
union|;
define|#
directive|define
name|int_broadaddr
value|int_intu.intu_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|int_dstaddr
value|int_intu.intu_dstaddr
comment|/* other end of p-to-p link */
name|int
name|int_metric
decl_stmt|;
comment|/* init's routing entry */
name|int
name|int_flags
decl_stmt|;
comment|/* see below */
name|int
name|int_net
decl_stmt|;
comment|/* network # */
name|struct
name|ifdebug
name|int_input
decl_stmt|,
name|int_output
decl_stmt|;
comment|/* packet tracing stuff */
name|int
name|int_ipackets
decl_stmt|;
comment|/* input packets received */
name|int
name|int_opackets
decl_stmt|;
comment|/* output packets sent */
name|char
modifier|*
name|int_name
decl_stmt|;
comment|/* from kernel if structure */
name|u_short
name|int_transitions
decl_stmt|;
comment|/* times gone up-down */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 0x1 to 0x10 are reused from the kernel's ifnet definitions,  * the others agree with the RTS_ flags defined below  */
end_comment

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

begin_define
define|#
directive|define
name|IFF_PASSIVE
value|0x20
end_define

begin_comment
comment|/* can't tell if up/down */
end_comment

begin_define
define|#
directive|define
name|IFF_INTERFACE
value|0x40
end_define

begin_comment
comment|/* hardware interface */
end_comment

begin_define
define|#
directive|define
name|IFF_REMOTE
value|0x80
end_define

begin_comment
comment|/* interface isn't on this machine */
end_comment

begin_comment
comment|/*  * Routing table structure; differs a bit from kernel tables.  *  * Note: the union below must agree in the first 4 members  * so the ioctl's will work.  */
end_comment

begin_struct
struct|struct
name|rthash
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rt_entry
block|{
name|struct
name|rt_entry
modifier|*
name|rt_forw
decl_stmt|;
name|struct
name|rt_entry
modifier|*
name|rt_back
decl_stmt|;
union|union
block|{
name|struct
name|rtentry
name|rtu_rt
decl_stmt|;
struct|struct
block|{
name|u_long
name|rtu_hash
decl_stmt|;
name|struct
name|sockaddr
name|rtu_dst
decl_stmt|;
name|struct
name|sockaddr
name|rtu_router
decl_stmt|;
name|short
name|rtu_flags
decl_stmt|;
name|short
name|rtu_state
decl_stmt|;
name|int
name|rtu_timer
decl_stmt|;
name|int
name|rtu_metric
decl_stmt|;
name|struct
name|interface
modifier|*
name|rtu_ifp
decl_stmt|;
block|}
name|rtu_entry
struct|;
block|}
name|rt_rtu
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rt_rt
value|rt_rtu.rtu_rt
end_define

begin_comment
comment|/* pass to ioctl */
end_comment

begin_define
define|#
directive|define
name|rt_hash
value|rt_rtu.rtu_entry.rtu_hash
end_define

begin_comment
comment|/* for net or host */
end_comment

begin_define
define|#
directive|define
name|rt_dst
value|rt_rtu.rtu_entry.rtu_dst
end_define

begin_comment
comment|/* match value */
end_comment

begin_define
define|#
directive|define
name|rt_router
value|rt_rtu.rtu_entry.rtu_router
end_define

begin_comment
comment|/* who to forward to */
end_comment

begin_define
define|#
directive|define
name|rt_flags
value|rt_rtu.rtu_entry.rtu_flags
end_define

begin_comment
comment|/* kernel flags */
end_comment

begin_define
define|#
directive|define
name|rt_timer
value|rt_rtu.rtu_entry.rtu_timer
end_define

begin_comment
comment|/* for invalidation */
end_comment

begin_define
define|#
directive|define
name|rt_state
value|rt_rtu.rtu_entry.rtu_state
end_define

begin_comment
comment|/* see below */
end_comment

begin_define
define|#
directive|define
name|rt_metric
value|rt_rtu.rtu_entry.rtu_metric
end_define

begin_comment
comment|/* cost of route */
end_comment

begin_define
define|#
directive|define
name|rt_ifp
value|rt_rtu.rtu_entry.rtu_ifp
end_define

begin_comment
comment|/* interface to take */
end_comment

begin_define
define|#
directive|define
name|ROUTEHASHSIZ
value|19
end_define

begin_comment
comment|/*  * "State" of routing table entry.  */
end_comment

begin_define
define|#
directive|define
name|RTS_CHANGED
value|0x1
end_define

begin_comment
comment|/* route has been altered recently */
end_comment

begin_define
define|#
directive|define
name|RTS_PASSIVE
value|0x20
end_define

begin_comment
comment|/* don't time out route */
end_comment

begin_define
define|#
directive|define
name|RTS_INTERFACE
value|0x40
end_define

begin_comment
comment|/* route is for network interface */
end_comment

begin_define
define|#
directive|define
name|RTS_REMOTE
value|0x80
end_define

begin_comment
comment|/* route is for ``remote'' entity */
end_comment

begin_decl_stmt
name|struct
name|rthash
name|nethash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|,
name|hosthash
index|[
name|ROUTEHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rt_entry
modifier|*
name|rtlookup
argument_list|()
decl_stmt|,
modifier|*
name|rtfind
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Per address family routines.  */
end_comment

begin_struct
struct|struct
name|afswitch
block|{
name|int
function_decl|(
modifier|*
name|af_hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* returns keys based on address */
name|int
function_decl|(
modifier|*
name|af_netmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* verifies net # matching */
name|int
function_decl|(
modifier|*
name|af_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* interprets address for sending */
name|int
function_decl|(
modifier|*
name|af_portmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* packet from some other router? */
name|int
function_decl|(
modifier|*
name|af_portcheck
function_decl|)
parameter_list|()
function_decl|;
comment|/* packet from priviledged peer? */
name|int
function_decl|(
modifier|*
name|af_checkhost
function_decl|)
parameter_list|()
function_decl|;
comment|/* tells if address for host or net */
name|int
function_decl|(
modifier|*
name|af_canon
function_decl|)
parameter_list|()
function_decl|;
comment|/* canonicalize address for compares */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure returned by af_hash routines.  */
end_comment

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
comment|/* host based hash */
name|u_int
name|afh_nethash
decl_stmt|;
comment|/* network based hash */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[
name|AF_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table proper */
end_comment

begin_comment
comment|/*  * When we find any interfaces marked down we rescan the  * kernel every CHECK_INTERVAL seconds to see if they've  * come up.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_INTERVAL
value|(1*60)
end_define

begin_define
define|#
directive|define
name|LOOPBACKNET
value|0177
end_define

begin_comment
comment|/* casts to keep lint happy */
end_comment

begin_define
define|#
directive|define
name|insque
parameter_list|(
name|q
parameter_list|,
name|p
parameter_list|)
value|_insque((caddr_t)q,(caddr_t)p)
end_define

begin_define
define|#
directive|define
name|remque
parameter_list|(
name|q
parameter_list|)
value|_remque((caddr_t)q)
end_define

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_decl_stmt
name|struct
name|sockaddr_in
name|routingaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sockaddr_in
name|noroutingaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snoroute
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket with no routing */
end_comment

begin_decl_stmt
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|supplier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process should supply updates */
end_comment

begin_decl_stmt
name|int
name|install
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1 call kernel */
end_comment

begin_decl_stmt
name|int
name|lookforinterfaces
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|performnlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|externalinterfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of remote and local interfaces */
end_comment

begin_decl_stmt
name|int
name|timeval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Packet tracing stuff.  */
end_comment

begin_decl_stmt
name|int
name|tracing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* on/off */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|ftrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output trace file */
end_comment

begin_define
define|#
directive|define
name|TRACE_ACTION
parameter_list|(
name|action
parameter_list|,
name|route
parameter_list|)
define|\
value|{ if (tracing) \ 		traceaction(ftrace, "action", route); \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_INPUT
parameter_list|(
name|ifp
parameter_list|,
name|from
parameter_list|,
name|size
parameter_list|)
define|\
value|{ if (tracing) { \ 		ifp = if_iflookup(from); \ 		if (ifp) \ 			trace(&ifp->int_input, from, packet, size, \ 				ifp->int_metric); \ 	  } \ 	}
end_define

begin_define
define|#
directive|define
name|TRACE_OUTPUT
parameter_list|(
name|ifp
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|)
define|\
value|{ if (tracing) \ 		trace(&ifp->int_output, to, packet, size, ifp->int_metric); \ 	}
end_define

begin_decl_stmt
name|char
name|packet
index|[
name|MAXPACKETSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rip
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|interface
modifier|*
name|if_ifwithaddr
argument_list|()
decl_stmt|,
modifier|*
name|if_ifwithnet
argument_list|()
decl_stmt|,
modifier|*
name|if_iflookup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|,
name|exit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sendmsg
argument_list|()
decl_stmt|,
name|supply
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|timer
argument_list|()
decl_stmt|,
name|cleanup
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

