begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)routed.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTOCOLS_ROUTED_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTOCOLS_ROUTED_H_
end_define

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
comment|/*  * Timer values used in managing the routing table.  * Complete tables are broadcast every SUPPLY_INTERVAL seconds.  * If changes occur between updates, dynamic updates containing only changes  * may be sent.  When these are sent, a timer is set for a random value  * between MIN_WAITTIME and MAX_WAITTIME, and no additional dynamic updates  * are sent until the timer expires.  *  * Every update of a routing entry forces an entry's timer to be reset.  * After EXPIRE_TIME without updates, the entry is marked invalid,  * but held onto until GARBAGE_TIME so that others may  * see it "be deleted".  */
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
name|MIN_WAITTIME
value|2
end_define

begin_comment
comment|/* min. interval to broadcast changes */
end_comment

begin_define
define|#
directive|define
name|MAX_WAITTIME
value|5
end_define

begin_comment
comment|/* max. time to delay changes */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ROUTED_H_ */
end_comment

end_unit

