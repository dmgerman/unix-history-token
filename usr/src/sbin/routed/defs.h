begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/5/93  */
end_comment

begin_comment
comment|/*  * Internal data structure definitions for  * user routing process.  Based on Xerox NS  * protocol specs with mods relevant to more  * general addressing scheme.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<protocols/routed.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
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
value|(1*60)
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

begin_decl_stmt
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of daemon's socket */
end_comment

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* source and sink of all data */
end_comment

begin_decl_stmt
name|int
name|r
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* routing socket */
end_comment

begin_decl_stmt
name|pid_t
name|pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process id for identifying messages */
end_comment

begin_decl_stmt
name|uid_t
name|uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user id for identifying messages */
end_comment

begin_decl_stmt
name|int
name|seqno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sequence number for identifying messages */
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
name|struct
name|timeval
name|now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current idea of time */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|lastbcast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last time all/changes broadcast */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|lastfullupdate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last time full table broadcast */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|nextbcast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time to wait before changes broadcast */
end_comment

begin_decl_stmt
name|int
name|needupdate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we need update at nextbcast */
end_comment

begin_decl_stmt
name|char
name|packet
index|[
name|MAXPACKETSIZE
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
name|struct
name|servent
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|in_addr
name|inet_makeaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inet_addr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inet_maskof
parameter_list|()
function_decl|;
end_function_decl

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

