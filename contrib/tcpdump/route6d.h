begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /tcpdump/master/tcpdump/route6d.h,v 1.2 2000/04/28 11:14:49 itojun Exp $  */
end_comment

begin_define
define|#
directive|define
name|RIP6_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|RIP6_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|RIP6_RESPONSE
value|2
end_define

begin_struct
struct|struct
name|netinfo6
block|{
name|struct
name|in6_addr
name|rip6_dest
decl_stmt|;
name|u_int16_t
name|rip6_tag
decl_stmt|;
name|u_int8_t
name|rip6_plen
decl_stmt|;
name|u_int8_t
name|rip6_metric
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rip6
block|{
name|u_int8_t
name|rip6_cmd
decl_stmt|;
name|u_int8_t
name|rip6_vers
decl_stmt|;
name|u_int8_t
name|rip6_res1
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
name|struct
name|netinfo6
name|ru6_nets
index|[
literal|1
index|]
decl_stmt|;
name|char
name|ru6_tracefile
index|[
literal|1
index|]
decl_stmt|;
block|}
name|rip6un
union|;
define|#
directive|define
name|rip6_nets
value|rip6un.ru6_nets
define|#
directive|define
name|rip6_tracefile
value|rip6un.ru6_tracefile
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOPCNT_INFINITY6
value|16
end_define

begin_define
define|#
directive|define
name|MAXRTE
value|24
end_define

begin_define
define|#
directive|define
name|NEXTHOP_METRIC
value|0xff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|SUPPLY_INTERVAL6
value|30
end_define

begin_define
define|#
directive|define
name|RIP_LIFETIME
value|180
end_define

begin_define
define|#
directive|define
name|RIP_HOLDDOWN
value|120
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INTERVAL6
value|5
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INTERVAL6_MIN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* only for debugging; can not wait for 30sec to appear a bug */
end_comment

begin_define
define|#
directive|define
name|SUPPLY_INTERVAL6
value|10
end_define

begin_define
define|#
directive|define
name|RIP_LIFETIME
value|60
end_define

begin_define
define|#
directive|define
name|RIP_HOLDDOWN
value|40
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INTERVAL6
value|5
end_define

begin_define
define|#
directive|define
name|RIP_TRIG_INTERVAL6_MIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RIP6_PORT
value|521
end_define

begin_define
define|#
directive|define
name|RIP6_DEST
value|"ff02::9"
end_define

end_unit

