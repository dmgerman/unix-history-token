begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defs.h	5.5 (Berkeley) 2/14/86";  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_include
include|#
directive|include
file|<netns/idp.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|pdp11
argument_list|)
end_if

begin_define
define|#
directive|define
name|xnnet
parameter_list|(
name|x
parameter_list|)
value|((u_long) (x)->rip_dst[1]<< 16 | (u_long) (x)->rip_dst[0] )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xnnet
parameter_list|(
name|x
parameter_list|)
value|((u_long) (x)->rip_dst[0]<< 16 | (u_long) (x)->rip_dst[1] )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IDPPORT_RIF
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"table.h"
end_include

begin_include
include|#
directive|include
file|"af.h"
end_include

begin_comment
comment|/*  * When we find any interfaces marked down we rescan the  * kernel every CHECK_INTERVAL seconds to see if they've  * come up.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_INTERVAL
value|(5*60)
end_define

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|(bcmp((caddr_t)(a1), (caddr_t)(a2), sizeof (struct sockaddr)) == 0)
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(b):(a))
end_define

begin_decl_stmt
name|struct
name|sockaddr_ns
name|addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Daemon's Address */
end_comment

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Socket to listen on */
end_comment

begin_decl_stmt
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|supplier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process should supply updates */
end_comment

begin_decl_stmt
name|int
name|install
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1 call kernel */
end_comment

begin_decl_stmt
name|int
name|lookforinterfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1 probe kernel for new up interfaces */
end_comment

begin_decl_stmt
name|int
name|performnlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if 1 check if /vmunix has changed */
end_comment

begin_decl_stmt
name|int
name|externalinterfaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of remote and local interfaces */
end_comment

begin_decl_stmt
name|int
name|timeval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local idea of time */
end_comment

begin_decl_stmt
name|int
name|noteremoterequests
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* squawk on requests from non-local nets */
end_comment

begin_decl_stmt
name|char
name|packet
index|[
name|MAXPACKETSIZE
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|idp
argument_list|)
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rip
modifier|*
name|msg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendmsg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|supply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|timer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

end_unit

