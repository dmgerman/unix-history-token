begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993, 1994, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_var.h	8.4 (Berkeley) 5/24/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_SYNCACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_SYNCACHE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|syncache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_function_decl
name|void
name|syncache_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|syncache_unreach
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_expand
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_add
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcpopt
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_chkrst
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syncache_badack
parameter_list|(
name|struct
name|in_conninfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syncache_pcblist
parameter_list|(
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|,
name|int
name|max_pcbs
parameter_list|,
name|int
modifier|*
name|pcbs_exported
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|syncache
block|{
name|TAILQ_ENTRY
argument_list|(
argument|syncache
argument_list|)
name|sc_hash
expr_stmt|;
name|struct
name|in_conninfo
name|sc_inc
decl_stmt|;
comment|/* addresses */
name|int
name|sc_rxttime
decl_stmt|;
comment|/* retransmit time */
name|u_int16_t
name|sc_rxmits
decl_stmt|;
comment|/* retransmit counter */
name|u_int32_t
name|sc_tsreflect
decl_stmt|;
comment|/* timestamp to reflect */
name|u_int32_t
name|sc_ts
decl_stmt|;
comment|/* our timestamp to send */
name|u_int32_t
name|sc_tsoff
decl_stmt|;
comment|/* ts offset w/ syncookies */
name|u_int32_t
name|sc_flowlabel
decl_stmt|;
comment|/* IPv6 flowlabel */
name|tcp_seq
name|sc_irs
decl_stmt|;
comment|/* seq from peer */
name|tcp_seq
name|sc_iss
decl_stmt|;
comment|/* our ISS */
name|struct
name|mbuf
modifier|*
name|sc_ipopts
decl_stmt|;
comment|/* source route */
name|u_int16_t
name|sc_peer_mss
decl_stmt|;
comment|/* peer's MSS */
name|u_int16_t
name|sc_wnd
decl_stmt|;
comment|/* advertised window */
name|u_int8_t
name|sc_ip_ttl
decl_stmt|;
comment|/* IPv4 TTL */
name|u_int8_t
name|sc_ip_tos
decl_stmt|;
comment|/* IPv4 TOS */
name|u_int8_t
name|sc_requested_s_scale
range|:
literal|4
decl_stmt|,
name|sc_requested_r_scale
range|:
literal|4
decl_stmt|;
name|u_int16_t
name|sc_flags
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|TCP_OFFLOAD
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|TCP_OFFLOAD_DISABLE
argument_list|)
name|struct
name|toedev
modifier|*
name|sc_tod
decl_stmt|;
comment|/* entry added by this TOE */
name|void
modifier|*
name|sc_todctx
decl_stmt|;
comment|/* TOE driver context */
endif|#
directive|endif
name|struct
name|label
modifier|*
name|sc_label
decl_stmt|;
comment|/* MAC label reference */
name|struct
name|ucred
modifier|*
name|sc_cred
decl_stmt|;
comment|/* cred cache for jail checks */
ifdef|#
directive|ifdef
name|TCP_RFC7413
name|void
modifier|*
name|sc_tfo_cookie
decl_stmt|;
comment|/* for TCP Fast Open response */
endif|#
directive|endif
name|void
modifier|*
name|sc_pspare
decl_stmt|;
comment|/* TCP_SIGNATURE */
name|u_int32_t
name|sc_spare
index|[
literal|2
index|]
decl_stmt|;
comment|/* UTO */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for the sc_flags field.  */
end_comment

begin_define
define|#
directive|define
name|SCF_NOOPT
value|0x01
end_define

begin_comment
comment|/* no TCP options */
end_comment

begin_define
define|#
directive|define
name|SCF_WINSCALE
value|0x02
end_define

begin_comment
comment|/* negotiated window scaling */
end_comment

begin_define
define|#
directive|define
name|SCF_TIMESTAMP
value|0x04
end_define

begin_comment
comment|/* negotiated timestamps */
end_comment

begin_comment
comment|/* MSS is implicit */
end_comment

begin_define
define|#
directive|define
name|SCF_UNREACH
value|0x10
end_define

begin_comment
comment|/* icmp unreachable received */
end_comment

begin_define
define|#
directive|define
name|SCF_SIGNATURE
value|0x20
end_define

begin_comment
comment|/* send MD5 digests */
end_comment

begin_define
define|#
directive|define
name|SCF_SACK
value|0x80
end_define

begin_comment
comment|/* send SACK option */
end_comment

begin_define
define|#
directive|define
name|SCF_ECN
value|0x100
end_define

begin_comment
comment|/* send ECN setup packet */
end_comment

begin_struct
struct|struct
name|syncache_head
block|{
name|struct
name|mtx
name|sch_mtx
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|sch_head
argument_list|,
argument|syncache
argument_list|)
name|sch_bucket
expr_stmt|;
name|struct
name|callout
name|sch_timer
decl_stmt|;
name|int
name|sch_nextc
decl_stmt|;
name|u_int
name|sch_length
decl_stmt|;
name|struct
name|tcp_syncache
modifier|*
name|sch_sc
decl_stmt|;
name|time_t
name|sch_last_overflow
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SYNCOOKIE_SECRET_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SYNCOOKIE_LIFETIME
value|15
end_define

begin_comment
comment|/* seconds */
end_comment

begin_struct
struct|struct
name|syncookie_secret
block|{
specifier|volatile
name|u_int
name|oddeven
decl_stmt|;
name|uint8_t
name|key
index|[
literal|2
index|]
index|[
name|SYNCOOKIE_SECRET_SIZE
index|]
decl_stmt|;
name|struct
name|callout
name|reseed
decl_stmt|;
name|u_int
name|lifetime
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcp_syncache
block|{
name|struct
name|syncache_head
modifier|*
name|hashbase
decl_stmt|;
name|uma_zone_t
name|zone
decl_stmt|;
name|u_int
name|hashsize
decl_stmt|;
name|u_int
name|hashmask
decl_stmt|;
name|u_int
name|bucket_limit
decl_stmt|;
name|u_int
name|cache_limit
decl_stmt|;
name|u_int
name|rexmt_limit
decl_stmt|;
name|uint32_t
name|hash_secret
decl_stmt|;
name|struct
name|vnet
modifier|*
name|vnet
decl_stmt|;
name|struct
name|syncookie_secret
name|secret
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Internal use for the syncookie functions. */
end_comment

begin_union
union|union
name|syncookie
block|{
name|uint8_t
name|cookie
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|odd_even
range|:
literal|1
decl_stmt|,
name|sack_ok
range|:
literal|1
decl_stmt|,
name|wscale_idx
range|:
literal|3
decl_stmt|,
name|mss_idx
range|:
literal|3
decl_stmt|;
block|}
name|flags
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_TCP_SYNCACHE_H_ */
end_comment

end_unit

