begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)timedc.h	2.4 (Berkeley) %G%  */
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
name|ON
value|1
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
name|MSGS
value|6
end_define

begin_define
define|#
directive|define
name|TRIALS
value|5
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

begin_struct
struct|struct
name|cmd
block|{
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* command name */
name|char
modifier|*
name|c_help
decl_stmt|;
comment|/* help message */
name|int
function_decl|(
modifier|*
name|c_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to do the work */
name|int
name|c_priv
decl_stmt|;
comment|/* privileged command */
block|}
struct|;
end_struct

end_unit

