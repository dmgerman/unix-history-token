begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	in.h	6.4	85/03/18	*/
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
comment|/*  * Ports< IPPORT_RESERVED are reserved for  * privileged processes (e.g. root).  */
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
comment|/*  * Definitions of bits in internet address integers.  */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSA
parameter_list|(
name|i
parameter_list|)
value|((((long)(i))&0x80000000)==0)
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
value|((((long)(i))&0xc0000000)==0x80000000)
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
value|((((long)(i))&0xc0000000)==0xc0000000)
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
name|INADDR_ANY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|INADDR_BROADCAST
value|0xffffffff
end_define

begin_comment
comment|/*  * Macros for subnetworks.  A subnet is distinguished by  * 	(1) the network number is a `local' network number, and  *	(2) the most significant bit of the host part is set.  * Such addresses include one additional byte in the network number,  * and use one less byte in the host part (i.e., a subnet of a Class A  * network uses the rules for Class B net/host number extraction,  * a Class B subnet is dealt with as if it were a Class C net).  * Subnets of Class C nets are not supported.  */
end_comment

begin_define
define|#
directive|define
name|SUBNETSHIFT
value|8
end_define

begin_comment
comment|/* used to get main net number from subnet */
end_comment

begin_define
define|#
directive|define
name|IN_SUBNETA
parameter_list|(
name|i
parameter_list|)
value|((((long)(i))&0x80800000)==0x00800000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_SUBNET
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_SUBNSHIFT
value|(IN_CLASSA_NSHIFT - SUBNETSHIFT)
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_SUBHOST
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IN_SUBNETB
parameter_list|(
name|i
parameter_list|)
value|((((long)(i))&0xc0008000)==0x80008000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_SUBNET
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_SUBNSHIFT
value|(IN_CLASSB_NSHIFT - SUBNETSHIFT)
end_define

begin_define
define|#
directive|define
name|IN_CLASSA_SUBHOST
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|IN_CLASSB_SUBHOST
value|0x000000ff
end_define

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

