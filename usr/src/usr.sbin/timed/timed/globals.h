begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_comment
comment|/*	@(#)globals.h	1.1	(Berkeley)	%G%	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
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

end_unit

