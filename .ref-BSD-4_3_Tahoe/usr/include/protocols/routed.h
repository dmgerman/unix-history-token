begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)protocol.h	5.1 (Berkeley) 6/4/85  */
end_comment

begin_comment
comment|/*  * Routing Information Protocol  *  * Derived from Xerox NS Routing Information Protocol  * by changing 32-bit net numbers to sockaddr's and  * padding stuff to 32-bit boundaries.  */
end_comment

begin_define
define|#
directive|define
name|RIPVERSION
value|1
end_define

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
name|rip_vers
decl_stmt|;
comment|/* protocol version # */
name|u_char
name|rip_res1
index|[
literal|2
index|]
decl_stmt|;
comment|/* pad to 32-bit boundary */
union|union
block|{
name|struct
name|netinfo
name|ru_nets
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length... */
name|char
name|ru_tracefile
index|[
literal|1
index|]
decl_stmt|;
comment|/* ditto ... */
block|}
name|ripun
union|;
define|#
directive|define
name|rip_nets
value|ripun.ru_nets
define|#
directive|define
name|rip_tracefile
value|ripun.ru_tracefile
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packet types.  */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_REQUEST
value|1
end_define

begin_comment
comment|/* want info */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_RESPONSE
value|2
end_define

begin_comment
comment|/* responding to request */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_TRACEON
value|3
end_define

begin_comment
comment|/* turn tracing on */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_TRACEOFF
value|4
end_define

begin_comment
comment|/* turn it off */
end_comment

begin_define
define|#
directive|define
name|RIPCMD_MAX
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RIPCMDS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ripcmds
index|[
name|RIPCMD_MAX
index|]
init|=
block|{
literal|"#0"
block|,
literal|"REQUEST"
block|,
literal|"RESPONSE"
block|,
literal|"TRACEON"
block|,
literal|"TRACEOFF"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
value|512
end_define

begin_comment
comment|/* max broadcast size */
end_comment

begin_comment
comment|/*  * Timer values used in managing the routing table.  * Every update forces an entry's timer to be reset.  After  * EXPIRE_TIME without updates, the entry is marked invalid,  * but held onto until GARBAGE_TIME so that others may  * see it "be deleted".  */
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
name|SUPPLY_INTERVAL
value|30
end_define

begin_comment
comment|/* time to supply tables */
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
name|GARBAGE_TIME
value|240
end_define

begin_comment
comment|/* time to garbage collect */
end_comment

end_unit

