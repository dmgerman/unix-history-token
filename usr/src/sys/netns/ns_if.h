begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ns_if.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Interface address, xerox version.  One of these structures  * is allocated for each interface with an internet address.  * The ifaddr structure contains the protocol-independent part  * of the structure and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|ns_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
comment|/*	union	ns_net	ia_net;		/* network number of interface */
define|#
directive|define
name|ia_net
value|ia_addr.sns_addr.x_net
name|struct
name|ns_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of xerox addresses */
name|struct
name|sockaddr_ns
name|ia_addr
decl_stmt|;
comment|/* reserve space for my address */
name|struct
name|sockaddr_ns
name|ia_dstaddr
decl_stmt|;
comment|/* space for my broadcast address */
define|#
directive|define
name|ia_broadaddr
value|ia_dstaddr
name|struct
name|sockaddr_ns
name|ia_netmask
decl_stmt|;
comment|/* space for my network mask */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ns_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|sockaddr_ns
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_ns
name|ifra_broadaddr
decl_stmt|;
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
block|}
struct|;
end_struct

begin_comment
comment|/*  * Given a pointer to an ns_ifaddr (ifaddr),  * return a pointer to the addr as a sockadd_ns.  */
end_comment

begin_define
define|#
directive|define
name|IA_SNS
parameter_list|(
name|ia
parameter_list|)
value|(&(((struct ns_ifaddr *)(ia))->ia_addr))
end_define

begin_comment
comment|/* This is not the right place for this but where is? */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NS
value|0x0600
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NSIP
end_ifdef

begin_struct
struct|struct
name|nsip_req
block|{
name|struct
name|sockaddr
name|rq_ns
decl_stmt|;
comment|/* must be ns format destination */
name|struct
name|sockaddr
name|rq_ip
decl_stmt|;
comment|/* must be ip format gateway */
name|short
name|rq_flags
decl_stmt|;
block|}
struct|;
end_struct

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
name|struct
name|ns_ifaddr
modifier|*
name|ns_ifaddr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|ns_ifaddr
modifier|*
name|ns_iaonnetof
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ifqueue
name|nsintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XNS input packet queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

