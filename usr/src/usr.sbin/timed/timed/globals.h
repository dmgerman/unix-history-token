begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*	@(#)globals.h	1.2	(Berkeley)	%G%	*/
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

begin_define
define|#
directive|define
name|RANGE
value|20
end_define

begin_define
define|#
directive|define
name|MSGS
value|5
end_define

begin_define
define|#
directive|define
name|TRIALS
value|6
end_define

begin_define
define|#
directive|define
name|SAMPLEINTVL
value|240
end_define

begin_define
define|#
directive|define
name|MAXSEQ
value|30000
end_define

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
name|NHOSTS
value|30
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
name|char
modifier|*
name|addr
decl_stmt|;
name|int
name|length
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

begin_decl_stmt
name|u_long
name|mynet
decl_stmt|,
name|netmask
decl_stmt|;
end_decl_stmt

end_unit

