begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* in.h 4.7 82/01/24 */
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
name|IPPROTO_GG
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
comment|/*  * Port/socket numbers: network standard functions  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_ECHO
value|7
end_define

begin_define
define|#
directive|define
name|IPPORT_DISCARD
value|9
end_define

begin_define
define|#
directive|define
name|IPPORT_SYSTAT
value|11
end_define

begin_define
define|#
directive|define
name|IPPORT_DAYTIME
value|13
end_define

begin_define
define|#
directive|define
name|IPPORT_NETSTAT
value|15
end_define

begin_define
define|#
directive|define
name|IPPORT_FTP
value|21
end_define

begin_define
define|#
directive|define
name|IPPORT_TELNET
value|23
end_define

begin_define
define|#
directive|define
name|IPPORT_SMTP
value|25
end_define

begin_define
define|#
directive|define
name|IPPORT_TIMESERVER
value|37
end_define

begin_define
define|#
directive|define
name|IPPORT_NAMESERVER
value|42
end_define

begin_define
define|#
directive|define
name|IPPORT_WHOIS
value|43
end_define

begin_define
define|#
directive|define
name|IPPORT_MTP
value|57
end_define

begin_comment
comment|/*  * Port/socket numbers: host specific functions  */
end_comment

begin_define
define|#
directive|define
name|IPPORT_TFTP
value|69
end_define

begin_define
define|#
directive|define
name|IPPORT_RJE
value|77
end_define

begin_define
define|#
directive|define
name|IPPORT_FINGER
value|79
end_define

begin_define
define|#
directive|define
name|IPPORT_TTYLINK
value|87
end_define

begin_define
define|#
directive|define
name|IPPORT_SUPDUP
value|95
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
comment|/*  * Internet address (old style... should be updated)  */
end_comment

begin_struct
struct|struct
name|in_addr
block|{
union|union
block|{
struct|struct
block|{
name|u_char
name|s_b1
decl_stmt|,
name|s_b2
decl_stmt|,
name|s_b3
decl_stmt|,
name|s_b4
decl_stmt|;
block|}
name|S_un_b
struct|;
struct|struct
block|{
name|u_short
name|s_w1
decl_stmt|,
name|s_w2
decl_stmt|;
block|}
name|S_un_w
struct|;
name|u_long
name|s_l
decl_stmt|;
block|}
name|S_un
union|;
define|#
directive|define
name|s_addr
value|S_un.s_l
comment|/* can be used for most tcp& ip code */
define|#
directive|define
name|s_host
value|S_un.S_un_b.s_b2
comment|/* host on imp */
define|#
directive|define
name|s_net
value|S_un.S_un_b.s_b1
comment|/* network */
define|#
directive|define
name|s_imp
value|S_un.S_un_w.s_w2
comment|/* imp */
define|#
directive|define
name|s_lhost
value|S_un.S_un_b.s_b1
comment|/* net library format host on imp */
define|#
directive|define
name|s_lnet
value|S_un.S_un_b.s_b2
comment|/* net library format network */
block|}
struct|;
end_struct

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

end_unit

