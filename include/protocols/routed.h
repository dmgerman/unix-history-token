begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)routed.h	8.1 (Berkeley) 6/2/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ROUTED_H_
end_ifndef

begin_define
define|#
directive|define
name|_ROUTED_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Routing Information Protocol  *  * Derived from Xerox NS Routing Information Protocol  * by changing 32-bit net numbers to sockaddr's and  * padding stuff to 32-bit boundaries.  */
define|#
directive|define
name|RIPv1
value|1
define|#
directive|define
name|RIPv2
value|2
ifndef|#
directive|ifndef
name|RIPVERSION
define|#
directive|define
name|RIPVERSION
value|RIPv1
endif|#
directive|endif
define|#
directive|define
name|RIP_PORT
value|520
if|#
directive|if
name|RIPVERSION
operator|==
literal|1
comment|/* Note that this so called sockaddr has a 2-byte sa_family and no sa_len.  * It is not a UNIX sockaddr, but the shape of an address as defined  * in RIPv1.  It is still defined to allow old versions of programs  * such as `gated` to use this file to define RIPv1.  */
struct|struct
name|netinfo
block|{
name|struct
name|sockaddr
name|rip_dst
decl_stmt|;
comment|/* destination net/host */
name|u_int32_t
name|rip_metric
decl_stmt|;
comment|/* cost of route */
block|}
struct|;
else|#
directive|else
struct|struct
name|netinfo
block|{
name|u_int16_t
name|n_family
decl_stmt|;
define|#
directive|define
name|RIP_AF_INET
value|htons(AF_INET)
define|#
directive|define
name|RIP_AF_UNSPEC
value|0
define|#
directive|define
name|RIP_AF_AUTH
value|0xffff
name|u_int16_t
name|n_tag
decl_stmt|;
comment|/* optional in RIPv2 */
name|u_int32_t
name|n_dst
decl_stmt|;
comment|/* destination net or host */
define|#
directive|define
name|RIP_DEFAULT
value|0
name|u_int32_t
name|n_mask
decl_stmt|;
comment|/* netmask in RIPv2 */
name|u_int32_t
name|n_nhop
decl_stmt|;
comment|/* optional next hop in RIPv2 */
name|u_int32_t
name|n_metric
decl_stmt|;
comment|/* cost of route */
block|}
struct|;
endif|#
directive|endif
comment|/* RIPv2 authentication */
struct|struct
name|netauth
block|{
name|u_int16_t
name|a_family
decl_stmt|;
comment|/* always RIP_AF_AUTH */
name|u_int16_t
name|a_type
decl_stmt|;
define|#
directive|define
name|RIP_AUTH_NONE
value|0
define|#
directive|define
name|RIP_AUTH_PW
value|htons(2)
comment|/* password type */
define|#
directive|define
name|RIP_AUTH_MD5
value|htons(3)
comment|/* Keyed MD5 */
union|union
block|{
define|#
directive|define
name|RIP_AUTH_PW_LEN
value|16
name|u_int8_t
name|au_pw
index|[
name|RIP_AUTH_PW_LEN
index|]
decl_stmt|;
struct|struct
name|a_md5
block|{
name|int16_t
name|md5_pkt_len
decl_stmt|;
comment|/* RIP-II packet length */
name|int8_t
name|md5_keyid
decl_stmt|;
comment|/* key ID and auth data len */
name|int8_t
name|md5_auth_len
decl_stmt|;
comment|/* 16 */
name|u_int32_t
name|md5_seqno
decl_stmt|;
comment|/* sequence number */
name|u_int32_t
name|rsvd
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be 0 */
define|#
directive|define
name|RIP_AUTH_MD5_LEN
value|RIP_AUTH_PW_LEN
block|}
name|a_md5
struct|;
block|}
name|au
union|;
block|}
struct|;
struct|struct
name|rip
block|{
name|u_int8_t
name|rip_cmd
decl_stmt|;
comment|/* request/response */
name|u_int8_t
name|rip_vers
decl_stmt|;
comment|/* protocol version # */
name|u_int16_t
name|rip_res1
decl_stmt|;
comment|/* pad to 32-bit boundary */
union|union
block|{
comment|/* variable length... */
name|struct
name|netinfo
name|ru_nets
index|[
literal|1
index|]
decl_stmt|;
name|int8_t
name|ru_tracefile
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|netauth
name|ru_auth
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ripun
union|;
define|#
directive|define
name|rip_nets
value|ripun.ru_nets
define|#
directive|define
name|rip_auths
value|ripun.ru_auth
define|#
directive|define
name|rip_tracefile
value|ripun.ru_tracefile
block|}
struct|;
comment|/* Packet types.  */
define|#
directive|define
name|RIPCMD_REQUEST
value|1
comment|/* want info */
define|#
directive|define
name|RIPCMD_RESPONSE
value|2
comment|/* responding to request */
define|#
directive|define
name|RIPCMD_TRACEON
value|3
comment|/* turn tracing on */
define|#
directive|define
name|RIPCMD_TRACEOFF
value|4
comment|/* turn it off */
comment|/* Gated extended RIP to include a "poll" command instead of using  * RIPCMD_REQUEST with (RIP_AF_UNSPEC, RIP_DEFAULT).  RFC 1058 says  * command 5 is used by Sun Microsystems for its own purposes.  */
define|#
directive|define
name|RIPCMD_POLL
value|5
define|#
directive|define
name|RIPCMD_MAX
value|6
ifdef|#
directive|ifdef
name|RIPCMDS
specifier|const
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
endif|#
directive|endif
define|#
directive|define
name|HOPCNT_INFINITY
value|16
define|#
directive|define
name|MAXPACKETSIZE
value|512
comment|/* max broadcast size */
define|#
directive|define
name|NETS_LEN
value|((MAXPACKETSIZE-sizeof(struct rip))	\ 		      / sizeof(struct netinfo) +1)
define|#
directive|define
name|INADDR_RIP_GROUP
value|(u_int32_t)0xe0000009
comment|/* 224.0.0.9 */
comment|/* Timer values used in managing the routing table.  *  * Complete tables are broadcast every SUPPLY_INTERVAL seconds.  * If changes occur between updates, dynamic updates containing only changes  * may be sent.  When these are sent, a timer is set for a random value  * between MIN_WAITTIME and MAX_WAITTIME, and no additional dynamic updates  * are sent until the timer expires.  *  * Every update of a routing entry forces an entry's timer to be reset.  * After EXPIRE_TIME without updates, the entry is marked invalid,  * but held onto until GARBAGE_TIME so that others may see it, to  * "poison" the bad route.  */
define|#
directive|define
name|SUPPLY_INTERVAL
value|30
comment|/* time to supply tables */
define|#
directive|define
name|MIN_WAITTIME
value|2
comment|/* min sec until next flash updates */
define|#
directive|define
name|MAX_WAITTIME
value|5
comment|/* max sec until flash update */
define|#
directive|define
name|STALE_TIME
value|90
comment|/* switch to a new gateway */
define|#
directive|define
name|EXPIRE_TIME
value|180
comment|/* time to mark entry invalid */
define|#
directive|define
name|GARBAGE_TIME
value|240
comment|/* time to garbage collect */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ROUTED_H_ */
end_comment

end_unit

