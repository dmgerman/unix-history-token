begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	routed.h	82/05/22	4.1	*/
end_comment

begin_comment
comment|/*  * Routing Information Protocol  */
end_comment

begin_struct
struct|struct
name|netinfo
block|{
name|struct
name|sockaddr
name|rip_dst
decl_stmt|;
comment|/* destination net/host */
name|int
name|rip_metric
decl_stmt|;
comment|/* cost of route */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rip
block|{
name|u_char
name|rip_cmd
decl_stmt|;
comment|/* request/response */
name|u_char
name|rip_res1
index|[
literal|3
index|]
decl_stmt|;
comment|/* pad to 32-bit boundary */
name|struct
name|netinfo
name|rip_nets
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length... */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RIPCMD_REQUEST
value|0x1
end_define

begin_comment
comment|/* want info */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_RESPONSE
value|0x2
end_define

begin_comment
comment|/* responding to request */
end_comment

begin_define
define|#
directive|define
name|IPPORT_ROUTESERVER
value|520
end_define

begin_comment
comment|/* well-known port */
end_comment

begin_define
define|#
directive|define
name|HOPCNT_INFINITY
value|16
end_define

begin_comment
comment|/* per Xerox NS */
end_comment

begin_define
define|#
directive|define
name|MAXPACKETSIZE
value|1024
end_define

begin_comment
comment|/* max broadcast size */
end_comment

begin_comment
comment|/*  * Timer values used in managing the routing table "cache".  * Every update forces an entry's timer to be reset.  After  * EXPIRE_TIME without updates, the entry is marked invalid,  * but held onto until GARBAGE_TIME so that others may  * see it "be deleted".  */
end_comment

begin_define
define|#
directive|define
name|TIMER_RATE
value|30
end_define

begin_comment
comment|/* alarm clocks every 30 seconds */
end_comment

begin_define
define|#
directive|define
name|GARBAGE_TIME
value|210
end_define

begin_comment
comment|/* time to garbage collect */
end_comment

begin_define
define|#
directive|define
name|EXPIRE_TIME
value|180
end_define

begin_comment
comment|/* time to mark entry invalid */
end_comment

begin_define
define|#
directive|define
name|SUPPLY_INTERVAL
value|30
end_define

begin_comment
comment|/* time to supply tables */
end_comment

end_unit

