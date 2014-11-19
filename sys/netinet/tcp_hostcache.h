begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Andre Oppermann, Internet Business Solutions AG  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Many thanks to jlemon for basic structure of tcp_syncache which is being  * followed here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_HOSTCACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_HOSTCACHE_H_
end_define

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|hc_qhead
argument_list|,
name|hc_metrics
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hc_head
block|{
name|struct
name|hc_qhead
name|hch_bucket
decl_stmt|;
name|u_int
name|hch_length
decl_stmt|;
name|struct
name|mtx
name|hch_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hc_metrics
block|{
comment|/* housekeeping */
name|TAILQ_ENTRY
argument_list|(
argument|hc_metrics
argument_list|)
name|rmx_q
expr_stmt|;
name|struct
name|hc_head
modifier|*
name|rmx_head
decl_stmt|;
comment|/* head of bucket tail queue */
name|struct
name|in_addr
name|ip4
decl_stmt|;
comment|/* IP address */
name|struct
name|in6_addr
name|ip6
decl_stmt|;
comment|/* IP6 address */
name|uint32_t
name|ip6_zoneid
decl_stmt|;
comment|/* IPv6 scope zone id */
comment|/* endpoint specific values for tcp */
name|u_long
name|rmx_mtu
decl_stmt|;
comment|/* MTU for this path */
name|u_long
name|rmx_ssthresh
decl_stmt|;
comment|/* outbound gateway buffer limit */
name|u_long
name|rmx_rtt
decl_stmt|;
comment|/* estimated round trip time */
name|u_long
name|rmx_rttvar
decl_stmt|;
comment|/* estimated rtt variance */
name|u_long
name|rmx_bandwidth
decl_stmt|;
comment|/* estimated bandwidth */
name|u_long
name|rmx_cwnd
decl_stmt|;
comment|/* congestion window */
name|u_long
name|rmx_sendpipe
decl_stmt|;
comment|/* outbound delay-bandwidth product */
name|u_long
name|rmx_recvpipe
decl_stmt|;
comment|/* inbound delay-bandwidth product */
comment|/* TCP hostcache internal data */
name|int
name|rmx_expire
decl_stmt|;
comment|/* lifetime for object */
name|u_long
name|rmx_hits
decl_stmt|;
comment|/* number of hits */
name|u_long
name|rmx_updates
decl_stmt|;
comment|/* number of updates */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcp_hostcache
block|{
name|struct
name|hc_head
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
name|cache_count
decl_stmt|;
name|u_int
name|cache_limit
decl_stmt|;
name|int
name|expire
decl_stmt|;
name|int
name|prune
decl_stmt|;
name|int
name|purgeall
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETINET_TCP_HOSTCACHE_H_*/
end_comment

end_unit

