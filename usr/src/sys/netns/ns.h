begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ns.h	6.12 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Constants and Structures defined by the Xerox Network Software  * per "Internet Transport Protocols", XSIS 028112, December 1981  */
end_comment

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_RI
value|1
end_define

begin_comment
comment|/* Routing Information */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_ECHO
value|2
end_define

begin_comment
comment|/* Echo Protocol */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_ERROR
value|3
end_define

begin_comment
comment|/* Error Protocol */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_PE
value|4
end_define

begin_comment
comment|/* Packet Exchange */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_SPP
value|5
end_define

begin_comment
comment|/* Sequenced Packet */
end_comment

begin_define
define|#
directive|define
name|NSPROTO_RAW
value|255
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_define
define|#
directive|define
name|NSPROTO_MAX
value|256
end_define

begin_comment
comment|/* Placemarker*/
end_comment

begin_comment
comment|/*  * Port/Socket numbers: network standard functions  */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RI
value|1
end_define

begin_comment
comment|/* Routing Information */
end_comment

begin_define
define|#
directive|define
name|NSPORT_ECHO
value|2
end_define

begin_comment
comment|/* Echo */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RE
value|3
end_define

begin_comment
comment|/* Router Error */
end_comment

begin_comment
comment|/*  * Ports< NSPORT_RESERVED are reserved for priveleged  * processes (e.g. root).  */
end_comment

begin_define
define|#
directive|define
name|NSPORT_RESERVED
value|3000
end_define

begin_comment
comment|/* flags passed to ns_output as last parameter */
end_comment

begin_define
define|#
directive|define
name|NS_FORWARDING
value|0x1
end_define

begin_comment
comment|/* most of idp header exists */
end_comment

begin_define
define|#
directive|define
name|NS_ROUTETOIF
value|0x10
end_define

begin_comment
comment|/* same as SO_DONTROUTE */
end_comment

begin_define
define|#
directive|define
name|NS_ALLOWBROADCAST
value|SO_BROADCAST
end_define

begin_comment
comment|/* can send broadcast packets */
end_comment

begin_define
define|#
directive|define
name|NS_MAXHOPS
value|15
end_define

begin_comment
comment|/* flags passed to get/set socket option */
end_comment

begin_define
define|#
directive|define
name|SO_HEADERS_ON_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|SO_HEADERS_ON_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|SO_DEFAULT_HEADERS
value|3
end_define

begin_define
define|#
directive|define
name|SO_LAST_HEADER
value|4
end_define

begin_define
define|#
directive|define
name|SO_NSIP_ROUTE
value|5
end_define

begin_define
define|#
directive|define
name|SO_SEQNO
value|6
end_define

begin_define
define|#
directive|define
name|SO_ALL_PACKETS
value|7
end_define

begin_define
define|#
directive|define
name|SO_MTU
value|8
end_define

begin_comment
comment|/*  * NS addressing  */
end_comment

begin_union
union|union
name|ns_host
block|{
name|u_char
name|c_host
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|s_host
index|[
literal|3
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ns_net
block|{
name|u_char
name|c_net
index|[
literal|4
index|]
decl_stmt|;
name|u_short
name|s_net
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_union
union|union
name|ns_net_u
block|{
name|union
name|ns_net
name|net_e
decl_stmt|;
name|u_long
name|long_e
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ns_addr
block|{
name|union
name|ns_net
name|x_net
decl_stmt|;
name|union
name|ns_host
name|x_host
decl_stmt|;
name|u_short
name|x_port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket address, Xerox style  */
end_comment

begin_struct
struct|struct
name|sockaddr_ns
block|{
name|u_short
name|sns_family
decl_stmt|;
name|struct
name|ns_addr
name|sns_addr
decl_stmt|;
name|char
name|sns_zero
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sns_port
value|sns_addr.x_port
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|ns_netof
parameter_list|(
name|a
parameter_list|)
value|(*(long *)& ((a).x_net))
end_define

begin_comment
comment|/* XXX - not needed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ns_neteqnn
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a).s_net[0]==(b).s_net[0])&& \ 					((a).s_net[1]==(b).s_net[1]))
end_define

begin_define
define|#
directive|define
name|ns_neteq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ns_neteqnn((a).x_net, (b).x_net)
end_define

begin_define
define|#
directive|define
name|satons_addr
parameter_list|(
name|sa
parameter_list|)
value|(((struct sockaddr_ns *)&(sa))->sns_addr)
end_define

begin_define
define|#
directive|define
name|ns_hosteqnh
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s).s_host[0] == (t).s_host[0]&& \ 	(s).s_host[1] == (t).s_host[1]&& (s).s_host[2] == (t).s_host[2])
end_define

begin_define
define|#
directive|define
name|ns_hosteq
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(ns_hosteqnh((s).x_host,(t).x_host))
end_define

begin_define
define|#
directive|define
name|ns_nullhost
parameter_list|(
name|x
parameter_list|)
value|(((x).x_host.s_host[0]==0)&& \ 	((x).x_host.s_host[1]==0)&& ((x).x_host.s_host[2]==0))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ntohl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_comment
comment|/*  * Macros for number representation conversion.  */
end_comment

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ntohl
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|lint
argument_list|)
operator|)
end_if

begin_decl_stmt
name|u_short
name|ntohs
argument_list|()
decl_stmt|,
name|htons
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ntohl
argument_list|()
decl_stmt|,
name|htonl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|nsdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_thishost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_zerohost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_host
name|ns_broadhost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_net
name|ns_zeronet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ns_net
name|ns_broadnet
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_short
name|ns_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

