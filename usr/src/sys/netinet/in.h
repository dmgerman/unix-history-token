begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)in.h	7.8 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Constants and structures defined by the internet system,  * Per RFC 790, September 1981.  */
end_comment

begin_comment
comment|/*  * Protocols  */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IP
value|0
end_define

begin_comment
comment|/* dummy for IP */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_ICMP
value|1
end_define

begin_comment
comment|/* control message protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_GGP
value|3
end_define

begin_comment
comment|/* gateway^2 (deprecated) */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TCP
value|6
end_define

begin_comment
comment|/* tcp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_EGP
value|8
end_define

begin_comment
comment|/* exterior gateway protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_PUP
value|12
end_define

begin_comment
comment|/* pup */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_UDP
value|17
end_define

begin_comment
comment|/* user datagram protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_IDP
value|22
end_define

begin_comment
comment|/* xns idp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_TP
value|29
end_define

begin_comment
comment|/* tp-4 w/ class negotiation */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_EON
value|80
end_define

begin_comment
comment|/* ISO cnlp */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_RAW
value|255
end_define

begin_comment
comment|/* raw IP packet */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAX
value|256
end_define

begin_comment
comment|/*  * Ports< IPPORT_RESERVED are reserved for  * privileged processes (e.g. root).  * Ports> IPPORT_USERRESERVED are reserved  * for servers, not necessarily privileged.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_RESERVED
value|1024
end_define

begin_define
define|#
directive|define
name|IPPORT_USERRESERVED
value|5000
end_define

begin_comment
comment|/*  * Link numbers  */
end_comment

begin_define
define|#
directive|define
name|IMPLINK_IP
value|155
end_define

begin_define
define|#
directive|define
name|IMPLINK_LOWEXPER
value|156
end_define

begin_define
define|#
directive|define
name|IMPLINK_HIGHEXPER
value|158
end_define

begin_comment
comment|/*  * Internet address (a structure for historical reasons)  */
end_comment

begin_struct
struct|struct
name|in_addr
block|{
name|u_long
name|s_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions of bits in internet address integers.  * On subnets, the decomposition of addresses to host and net parts  * is done according to subnet mask, not the masks here.  */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSA
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0x80000000) == 0)
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_NET
value|0xff000000
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_NSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_HOST
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_MAX
value|128
end_define

begin_define
define|#
directive|define
name|IN_CLASSB
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xc0000000) == 0x80000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_NET
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_NSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_HOST
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_MAX
value|65536
end_define

begin_define
define|#
directive|define
name|IN_CLASSC
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xe0000000) == 0xc0000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_NET
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_NSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IN_CLASSC_HOST
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IN_CLASSD
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xf0000000) == 0xe0000000)
end_define

begin_define
define|#
directive|define
name|IN_MULTICAST
parameter_list|(
name|i
parameter_list|)
value|IN_CLASSD(i)
end_define

begin_define
define|#
directive|define
name|IN_EXPERIMENTAL
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xe0000000) == 0xe0000000)
end_define

begin_define
define|#
directive|define
name|IN_BADCLASS
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|INADDR_ANY
value|(u_long)0x00000000
end_define

begin_define
define|#
directive|define
name|INADDR_BROADCAST
value|(u_long)0xffffffff
end_define

begin_comment
comment|/* must be masked */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|INADDR_NONE
value|0xffffffff
end_define

begin_comment
comment|/* -1 return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IN_LOOPBACKNET
value|127
end_define

begin_comment
comment|/* official! */
end_comment

begin_comment
comment|/*  * Socket address, internet style.  */
end_comment

begin_struct
struct|struct
name|sockaddr_in
block|{
name|u_char
name|sin_len
decl_stmt|;
name|u_char
name|sin_family
decl_stmt|;
name|u_short
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|char
name|sin_zero
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Options for use with [gs]etsockopt at the IP level.  */
end_comment

begin_define
define|#
directive|define
name|IP_OPTIONS
value|1
end_define

begin_comment
comment|/* set/get IP per-packet options */
end_comment

begin_define
define|#
directive|define
name|IP_HDRINCL
value|2
end_define

begin_comment
comment|/* header is included with data */
end_comment

begin_define
define|#
directive|define
name|IP_TOS
value|3
end_define

begin_comment
comment|/* IP type of service and precedence */
end_comment

begin_define
define|#
directive|define
name|IP_TTL
value|4
end_define

begin_comment
comment|/* IP time to live */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|inetdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|protosw
name|inetsw
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_addr
name|in_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|u_long
name|in_netof
argument_list|()
decl_stmt|,
name|in_lnaof
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

