begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* From net/if.h */
end_comment

begin_define
define|#
directive|define
name|IFF_MULTICAST
value|0x800
end_define

begin_comment
comment|/* supports multicast */
end_comment

begin_comment
comment|/* From netinet/in.h */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLHOSTS_GROUP
value|(u_long)0xe0000001
end_define

begin_comment
comment|/* 224.0.0.1   */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_IF
value|0x10
end_define

begin_comment
comment|/* set/get IP multicast interface  */
end_comment

begin_define
define|#
directive|define
name|IP_ADD_MEMBERSHIP
value|0x13
end_define

begin_comment
comment|/* add  an IP group membership     */
end_comment

begin_define
define|#
directive|define
name|IP_MULTICAST_TTL
value|0x11
end_define

begin_comment
comment|/* set/get IP multicast timetolive */
end_comment

begin_comment
comment|/*  * Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.  */
end_comment

begin_struct
struct|struct
name|ip_mreq
block|{
name|struct
name|in_addr
name|imr_multiaddr
decl_stmt|;
comment|/* IP multicast address of group */
name|struct
name|in_addr
name|imr_interface
decl_stmt|;
comment|/* local IP address of interface */
block|}
struct|;
end_struct

end_unit

