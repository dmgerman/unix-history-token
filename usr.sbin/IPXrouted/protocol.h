begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * This file includes significant work done at Cornell University by  * Bill Nesheim.  That work included by permission.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)protocol.h	8.1 (Berkeley) 6/5/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * IPX Routing Information Protocol  *  */
end_comment

begin_struct
struct|struct
name|netinfo
block|{
name|union
name|ipx_net
name|rip_dst
decl_stmt|;
comment|/* destination net */
name|u_short
name|rip_metric
decl_stmt|;
comment|/* cost of route */
name|u_short
name|rip_ticks
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
comment|/* per IPX */
end_comment

begin_define
define|#
directive|define
name|DSTNETS_ALL
value|0xffffffff
end_define

begin_comment
comment|/* per IPX */
end_comment

begin_define
define|#
directive|define
name|MAXRXPACKETSIZE
value|1500
end_define

begin_comment
comment|/* max rx broadcast size */
end_comment

begin_define
define|#
directive|define
name|MAXRIPNETS
value|50
end_define

begin_comment
comment|/* max nets in tx packet */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|ipx_net
name|ipx_anynet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|union
name|ipx_net
name|ipx_zeronet
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
name|RIP_INTERVAL
value|60
end_define

begin_comment
comment|/* time to supply rip tables */
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

