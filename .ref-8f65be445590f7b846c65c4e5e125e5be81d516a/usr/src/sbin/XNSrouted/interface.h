begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)interface.h	5.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

begin_comment
comment|/*  * An ``interface'' is similar to an ifnet structure,  * except it doesn't contain q'ing info, and it also  * handles ``logical'' interfaces (remote gateways  * that we want to keep polling even if they go down).  * The list of interfaces which we maintain is used  * in supplying the gratuitous routing table updates.  * We list only one address for  each interface, the AF_XNS one.  */
end_comment

begin_define
define|#
directive|define
name|NIFADDR
value|3
end_define

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
comment|/*XNS Specific entry */
struct|struct
name|sameq
block|{
name|struct
name|sameq
modifier|*
name|n
decl_stmt|;
comment|/* q of other pt-to-pt links */
name|struct
name|sameq
modifier|*
name|p
decl_stmt|;
comment|/* with same net # */
block|}
name|int_sq
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 0x1 to 0x10 are reused from the kernel's ifnet definitions,  * the others agree with the RTS_ flags defined elsewhere.  */
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

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithdstaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithnet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_iflookup
parameter_list|()
function_decl|;
end_function_decl

end_unit

