begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)protocol.h	5.4 (Berkeley) 2/14/86";  *  * Includes material written at Cornell University by Bill Nesheim,  * by permission of the author.  */
end_comment

begin_comment
comment|/*  * Xerox Routing Information Protocol  *  */
end_comment

begin_struct
struct|struct
name|netinfo
block|{
name|union
name|ns_net
name|rip_dst
decl_stmt|;
comment|/* destination net */
name|u_short
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
name|u_short
name|rip_cmd
decl_stmt|;
comment|/* request/response */
name|struct
name|netinfo
name|rip_nets
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable length */
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
name|RIPCMD_MAX
value|3
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
name|DSTNETS_ALL
value|0xffffffff
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

begin_decl_stmt
specifier|extern
name|union
name|ns_net
name|ns_anynet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ns_net
name|ns_zeronet
decl_stmt|;
end_decl_stmt

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

