begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	interface.h	4.2	84/04/09	*/
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

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
name|u_long
name|int_net
decl_stmt|;
comment|/* network # */
name|u_long
name|int_netmask
decl_stmt|;
comment|/* net mask for addr */
name|u_long
name|int_subnet
decl_stmt|;
comment|/* subnet # */
name|u_long
name|int_subnetmask
decl_stmt|;
comment|/* subnet mask for addr */
name|int
name|int_metric
decl_stmt|;
comment|/* init's routing entry */
name|int
name|int_flags
decl_stmt|;
comment|/* see below */
comment|/*	struct	ifdebug int_input, int_output;	/* packet tracing stuff */
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
name|int
name|int_egpsock
decl_stmt|;
comment|/* egp raw socket */
name|int
name|int_icmpsock
decl_stmt|;
comment|/* icmp raw socket */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 0x1 to 0x100 are reused from the kernel's ifnet definitions,  * the others agree with the RTS_ flags defined elsewhere.  */
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
value|0x2000
end_define

begin_comment
comment|/* can't tell if up/down */
end_comment

begin_define
define|#
directive|define
name|IFF_INTERFACE
value|0x4000
end_define

begin_comment
comment|/* hardware interface */
end_comment

begin_define
define|#
directive|define
name|IFF_REMOTE
value|0x8000
end_define

begin_comment
comment|/* interface isn't on this machine */
end_comment

begin_comment
comment|/* struct	interface *if_ifwithaddr(); struct	interface *if_ifwithnet(); struct	interface *if_iflookup(); */
end_comment

end_unit

