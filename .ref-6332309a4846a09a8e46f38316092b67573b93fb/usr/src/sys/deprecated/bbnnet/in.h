begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
value|2
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
name|IPPROTO_HMP
value|20
end_define

begin_comment
comment|/* host monitoring protocol */
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
name|IPPROTO_RDP
value|27
end_define

begin_comment
comment|/* reliabe datagram protocol */
end_comment

begin_define
define|#
directive|define
name|IPPROTO_MAX
value|256
end_define

begin_comment
comment|/*  * historical and inaccurate.  See protocol .h files if you care  * about reserved ports.  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_RESERVED
value|1024
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

begin_ifdef
ifdef|#
directive|ifdef
name|when_convince_berk
end_ifdef

begin_comment
comment|/*  * Internet layers for getsockopt()/setsockopt()  * (gaps left in case we forgot something)  */
end_comment

begin_define
define|#
directive|define
name|SOL_INPROTO
value|2
end_define

begin_comment
comment|/* tcp/udp/hmp/rdp */
end_comment

begin_define
define|#
directive|define
name|SOL_INRAW
value|4
end_define

begin_comment
comment|/* ip */
end_comment

begin_define
define|#
directive|define
name|SOL_INETHER
value|6
end_define

begin_comment
comment|/* ARP, etc. */
end_comment

begin_define
define|#
directive|define
name|SOL_INIFADDR
value|8
end_define

begin_comment
comment|/* interface addrs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|INADDR_ANY
value|((u_long) 0x00000000)
end_define

begin_define
define|#
directive|define
name|INADDR_BROADCAST
value|((u_long) 0xffffffff)
end_define

begin_comment
comment|/* must be masked */
end_comment

begin_comment
comment|/*  * Socket address, internet style.  */
end_comment

begin_struct
struct|struct
name|sockaddr_in
block|{
name|short
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
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

begin_comment
comment|/*  * Treat a sockaddr as a sockaddr_in, and retrieve the IP address  * associated with it.  */
end_comment

begin_define
define|#
directive|define
name|satoipa
parameter_list|(
name|x
parameter_list|)
value|(((struct sockaddr_in *) (x)) ->sin_addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

