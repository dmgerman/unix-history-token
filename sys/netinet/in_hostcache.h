begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1997 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_HOSTCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_IN_HOSTCACHE_H
value|1
end_define

begin_comment
comment|/*  * This file defines the particular structures contained in the host cache  * for the use of IP.  */
end_comment

begin_comment
comment|/*  * An IP host cache entry.  Note that we include the srtt/var here,  * with the expectation that it might be used to keep a persistent,  * cross-connection view of this statistic.  */
end_comment

begin_struct
struct|struct
name|in_hcentry
block|{
name|struct
name|hcentry
name|inhc_hc
decl_stmt|;
name|u_long
name|inhc_pmtu
decl_stmt|;
name|u_long
name|inhc_recvpipe
decl_stmt|;
name|u_long
name|inhc_sendpipe
decl_stmt|;
name|u_long
name|inhc_pksent
decl_stmt|;
name|u_long
name|inhc_flags
decl_stmt|;
name|u_long
name|inhc_ssthresh
decl_stmt|;
name|int
name|inhc_srtt
decl_stmt|;
comment|/* VJ RTT estimator */
name|int
name|inhc_srttvar
decl_stmt|;
comment|/* VJ */
name|u_int
name|inhc_rttmin
decl_stmt|;
comment|/* VJ */
name|int
name|inhc_rxt
decl_stmt|;
comment|/* TCP retransmit timeout */
name|u_long
name|inhc_cc
decl_stmt|;
comment|/* deliberate type pun with tcp_cc */
name|u_long
name|inhc_ccsent
decl_stmt|;
comment|/* as above */
name|u_short
name|inhc_mssopt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|inhc_addr
parameter_list|(
name|inhc
parameter_list|)
value|((struct sockaddr_in *)(inhc)->inhc_hc.hc_host)
end_define

begin_comment
comment|/* Flags for inhc_flags... */
end_comment

begin_define
define|#
directive|define
name|INHC_LOCAL
value|0x0001
end_define

begin_comment
comment|/* this address is local */
end_comment

begin_define
define|#
directive|define
name|INHC_BROADCAST
value|0x0002
end_define

begin_comment
comment|/* this address is broadcast */
end_comment

begin_define
define|#
directive|define
name|INHC_MULTICAST
value|0x0004
end_define

begin_comment
comment|/* this address is multicast */
end_comment

begin_define
define|#
directive|define
name|INHC_REDUCEDMTU
value|0x0008
end_define

begin_comment
comment|/* we reduced the mtu via PMTU discovery */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * inhc_alloc can block while adding a new entry to the cache;  * inhc_lookup will does not add new entries and so can be called  * in non-process context.  */
end_comment

begin_function_decl
name|struct
name|in_hcentry
modifier|*
name|inhc_alloc
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|sin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|inhc_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_hcentry
modifier|*
name|inhc_lookup
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|sin
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|inhc_ref
parameter_list|(
name|inhc
parameter_list|)
value|(hc_ref(&(inhc)->inhc_hc))
end_define

begin_define
define|#
directive|define
name|inhc_rele
parameter_list|(
name|inhc
parameter_list|)
value|(hc_rele(&(inhc)->inhc_hc))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_IN_HOSTCACHE_H */
end_comment

end_unit

