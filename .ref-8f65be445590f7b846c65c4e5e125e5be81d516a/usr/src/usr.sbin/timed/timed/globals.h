begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)globals.h	2.7 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SAMPLEINTVL
value|240
end_define

begin_comment
comment|/* synch() freq for master, sec */
end_comment

begin_define
define|#
directive|define
name|MAXADJ
value|20
end_define

begin_comment
comment|/* max correction (sec) for adjtime */
end_comment

begin_comment
comment|/*  * Parameters for network time measurement  * of each host using ICMP timestamp requests.  */
end_comment

begin_define
define|#
directive|define
name|RANGE
value|20
end_define

begin_comment
comment|/* best expected round-trip time, ms */
end_comment

begin_define
define|#
directive|define
name|MSGS
value|5
end_define

begin_comment
comment|/* # of timestamp replies to average */
end_comment

begin_define
define|#
directive|define
name|TRIALS
value|10
end_define

begin_comment
comment|/* max # of timestamp echos sent */
end_comment

begin_define
define|#
directive|define
name|MINTOUT
value|360
end_define

begin_define
define|#
directive|define
name|MAXTOUT
value|900
end_define

begin_define
define|#
directive|define
name|GOOD
value|1
end_define

begin_define
define|#
directive|define
name|UNREACHABLE
value|2
end_define

begin_define
define|#
directive|define
name|NONSTDTIME
value|3
end_define

begin_define
define|#
directive|define
name|HOSTDOWN
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_comment
comment|/*  * Global and per-network states.  */
end_comment

begin_define
define|#
directive|define
name|NOMASTER
value|0
end_define

begin_comment
comment|/* no master on any network */
end_comment

begin_define
define|#
directive|define
name|SLAVE
value|1
end_define

begin_define
define|#
directive|define
name|MASTER
value|2
end_define

begin_define
define|#
directive|define
name|IGNORE
value|4
end_define

begin_define
define|#
directive|define
name|ALL
value|(SLAVE|MASTER|IGNORE)
end_define

begin_define
define|#
directive|define
name|SUBMASTER
value|(SLAVE|MASTER)
end_define

begin_define
define|#
directive|define
name|NHOSTS
value|100
end_define

begin_comment
comment|/* max number of hosts controlled by timed */
end_comment

begin_struct
struct|struct
name|host
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
name|long
name|delta
decl_stmt|;
name|u_short
name|seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netinfo
block|{
name|struct
name|netinfo
modifier|*
name|next
decl_stmt|;
name|u_long
name|net
decl_stmt|;
name|u_long
name|mask
decl_stmt|;
name|struct
name|in_addr
name|my_addr
decl_stmt|;
name|struct
name|sockaddr_in
name|dest_addr
decl_stmt|;
comment|/* broadcast addr or point-point */
name|long
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|netinfo
modifier|*
name|nettab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|from
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netinfo
modifier|*
name|fromnet
decl_stmt|,
modifier|*
name|slavenet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tracefile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|host
name|hp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|backoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|delay1
decl_stmt|,
name|delay2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|slvcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nslavenets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of nets were I could be a slave */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nmasternets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of nets were I could be a master */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nignorednets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of ignored nets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nnets
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of nets I am connected to */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

