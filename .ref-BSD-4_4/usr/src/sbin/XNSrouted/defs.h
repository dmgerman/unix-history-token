begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/5/93  */
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
name|int
name|r
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routing socket to install updates with */
end_comment

begin_decl_stmt
name|struct
name|sockaddr_ns
name|ns_netmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used in installing routes */
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

begin_function_decl
name|int
name|sndmsg
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
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtioctl
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ADD
value|1
end_define

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_define
define|#
directive|define
name|CHANGE
value|3
end_define

end_unit

