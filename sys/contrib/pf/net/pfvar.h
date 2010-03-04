begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: pfvar.h,v 1.244 2007/02/23 21:31:51 deraadt Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Daniel Hartmeier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *    - Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *    - Redistributions in binary form must reproduce the above  *      copyright notice, this list of conditions and the following  *      disclaimer in the documentation and/or other materials provided  *      with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PFVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_PFVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/tree.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/radix.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<net/if_clone.h>
end_include

begin_include
include|#
directive|include
file|<net/pf_mtag.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netinet/ip_ipsp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/tcp_fsm.h>
end_include

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip6_hdr
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_struct_decl
struct_decl|struct
name|inpcb
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PF_TCPS_PROXY_SRC
value|((TCP_NSTATES)+0)
end_define

begin_define
define|#
directive|define
name|PF_TCPS_PROXY_DST
value|((TCP_NSTATES)+1)
end_define

begin_define
define|#
directive|define
name|PF_MD5_DIGEST_LENGTH
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MD5_DIGEST_LENGTH
end_ifdef

begin_if
if|#
directive|if
name|PF_MD5_DIGEST_LENGTH
operator|!=
name|MD5_DIGEST_LENGTH
end_if

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
block|{
name|PF_INOUT
block|,
name|PF_IN
block|,
name|PF_OUT
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_LAN_EXT
block|,
name|PF_EXT_GWY
block|,
name|PF_ID
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_PASS
block|,
name|PF_DROP
block|,
name|PF_SCRUB
block|,
name|PF_NOSCRUB
block|,
name|PF_NAT
block|,
name|PF_NONAT
block|,
name|PF_BINAT
block|,
name|PF_NOBINAT
block|,
name|PF_RDR
block|,
name|PF_NORDR
block|,
name|PF_SYNPROXY_DROP
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_RULESET_SCRUB
block|,
name|PF_RULESET_FILTER
block|,
name|PF_RULESET_NAT
block|,
name|PF_RULESET_BINAT
block|,
name|PF_RULESET_RDR
block|,
name|PF_RULESET_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_OP_NONE
block|,
name|PF_OP_IRG
block|,
name|PF_OP_EQ
block|,
name|PF_OP_NE
block|,
name|PF_OP_LT
block|,
name|PF_OP_LE
block|,
name|PF_OP_GT
block|,
name|PF_OP_GE
block|,
name|PF_OP_XRG
block|,
name|PF_OP_RRG
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_DEBUG_NONE
block|,
name|PF_DEBUG_URGENT
block|,
name|PF_DEBUG_MISC
block|,
name|PF_DEBUG_NOISY
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_CHANGE_NONE
block|,
name|PF_CHANGE_ADD_HEAD
block|,
name|PF_CHANGE_ADD_TAIL
block|,
name|PF_CHANGE_ADD_BEFORE
block|,
name|PF_CHANGE_ADD_AFTER
block|,
name|PF_CHANGE_REMOVE
block|,
name|PF_CHANGE_GET_TICKET
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_GET_NONE
block|,
name|PF_GET_CLR_CNTR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Note about PFTM_*: real indices into pf_rule.timeout[] come before  * PFTM_MAX, special cases afterwards. See pf_state_expires().  */
end_comment

begin_enum
enum|enum
block|{
name|PFTM_TCP_FIRST_PACKET
block|,
name|PFTM_TCP_OPENING
block|,
name|PFTM_TCP_ESTABLISHED
block|,
name|PFTM_TCP_CLOSING
block|,
name|PFTM_TCP_FIN_WAIT
block|,
name|PFTM_TCP_CLOSED
block|,
name|PFTM_UDP_FIRST_PACKET
block|,
name|PFTM_UDP_SINGLE
block|,
name|PFTM_UDP_MULTIPLE
block|,
name|PFTM_ICMP_FIRST_PACKET
block|,
name|PFTM_ICMP_ERROR_REPLY
block|,
name|PFTM_OTHER_FIRST_PACKET
block|,
name|PFTM_OTHER_SINGLE
block|,
name|PFTM_OTHER_MULTIPLE
block|,
name|PFTM_FRAG
block|,
name|PFTM_INTERVAL
block|,
name|PFTM_ADAPTIVE_START
block|,
name|PFTM_ADAPTIVE_END
block|,
name|PFTM_SRC_NODE
block|,
name|PFTM_TS_DIFF
block|,
name|PFTM_MAX
block|,
name|PFTM_PURGE
block|,
name|PFTM_UNLINKED
block|,
name|PFTM_UNTIL_PACKET
block|}
enum|;
end_enum

begin_comment
comment|/* PFTM default values */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_FIRST_PACKET_VAL
value|120
end_define

begin_comment
comment|/* First TCP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_OPENING_VAL
value|30
end_define

begin_comment
comment|/* No response yet */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_ESTABLISHED_VAL
value|24*60*60
end_define

begin_comment
comment|/* Established */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_CLOSING_VAL
value|15 * 60
end_define

begin_comment
comment|/* Half closed */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_FIN_WAIT_VAL
value|45
end_define

begin_comment
comment|/* Got both FINs */
end_comment

begin_define
define|#
directive|define
name|PFTM_TCP_CLOSED_VAL
value|90
end_define

begin_comment
comment|/* Got a RST */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_FIRST_PACKET_VAL
value|60
end_define

begin_comment
comment|/* First UDP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_SINGLE_VAL
value|30
end_define

begin_comment
comment|/* Unidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_UDP_MULTIPLE_VAL
value|60
end_define

begin_comment
comment|/* Bidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_ICMP_FIRST_PACKET_VAL
value|20
end_define

begin_comment
comment|/* First ICMP packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_ICMP_ERROR_REPLY_VAL
value|10
end_define

begin_comment
comment|/* Got error response */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_FIRST_PACKET_VAL
value|60
end_define

begin_comment
comment|/* First packet */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_SINGLE_VAL
value|30
end_define

begin_comment
comment|/* Unidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_OTHER_MULTIPLE_VAL
value|60
end_define

begin_comment
comment|/* Bidirectional */
end_comment

begin_define
define|#
directive|define
name|PFTM_FRAG_VAL
value|30
end_define

begin_comment
comment|/* Fragment expire */
end_comment

begin_define
define|#
directive|define
name|PFTM_INTERVAL_VAL
value|10
end_define

begin_comment
comment|/* Expire interval */
end_comment

begin_define
define|#
directive|define
name|PFTM_SRC_NODE_VAL
value|0
end_define

begin_comment
comment|/* Source tracking */
end_comment

begin_define
define|#
directive|define
name|PFTM_TS_DIFF_VAL
value|30
end_define

begin_comment
comment|/* Allowed TS diff */
end_comment

begin_enum
enum|enum
block|{
name|PF_NOPFROUTE
block|,
name|PF_FASTROUTE
block|,
name|PF_ROUTETO
block|,
name|PF_DUPTO
block|,
name|PF_REPLYTO
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_LIMIT_STATES
block|,
name|PF_LIMIT_SRC_NODES
block|,
name|PF_LIMIT_FRAGS
block|,
name|PF_LIMIT_TABLES
block|,
name|PF_LIMIT_TABLE_ENTRIES
block|,
name|PF_LIMIT_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PF_POOL_IDMASK
value|0x0f
end_define

begin_enum
enum|enum
block|{
name|PF_POOL_NONE
block|,
name|PF_POOL_BITMASK
block|,
name|PF_POOL_RANDOM
block|,
name|PF_POOL_SRCHASH
block|,
name|PF_POOL_ROUNDROBIN
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PF_ADDR_ADDRMASK
block|,
name|PF_ADDR_NOROUTE
block|,
name|PF_ADDR_DYNIFTL
block|,
name|PF_ADDR_TABLE
block|,
name|PF_ADDR_RTLABEL
block|,
name|PF_ADDR_URPFFAILED
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PF_POOL_TYPEMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|PF_POOL_STICKYADDR
value|0x20
end_define

begin_define
define|#
directive|define
name|PF_WSCALE_FLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|PF_WSCALE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|PF_LOG
value|0x01
end_define

begin_define
define|#
directive|define
name|PF_LOG_ALL
value|0x02
end_define

begin_define
define|#
directive|define
name|PF_LOG_SOCKET_LOOKUP
value|0x04
end_define

begin_struct
struct|struct
name|pf_addr
block|{
union|union
block|{
name|struct
name|in_addr
name|v4
decl_stmt|;
name|struct
name|in6_addr
name|v6
decl_stmt|;
name|u_int8_t
name|addr8
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|addr16
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|addr32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|pfa
union|;
comment|/* 128-bit address */
define|#
directive|define
name|v4
value|pfa.v4
define|#
directive|define
name|v6
value|pfa.v6
define|#
directive|define
name|addr8
value|pfa.addr8
define|#
directive|define
name|addr16
value|pfa.addr16
define|#
directive|define
name|addr32
value|pfa.addr32
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PF_TABLE_NAME_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PFI_AFLAG_NETWORK
value|0x01
end_define

begin_define
define|#
directive|define
name|PFI_AFLAG_BROADCAST
value|0x02
end_define

begin_define
define|#
directive|define
name|PFI_AFLAG_PEER
value|0x04
end_define

begin_define
define|#
directive|define
name|PFI_AFLAG_MODEMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|PFI_AFLAG_NOALIAS
value|0x08
end_define

begin_struct
struct|struct
name|pf_addr_wrap
block|{
union|union
block|{
struct|struct
block|{
name|struct
name|pf_addr
name|addr
decl_stmt|;
name|struct
name|pf_addr
name|mask
decl_stmt|;
block|}
name|a
struct|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|tblname
index|[
name|PF_TABLE_NAME_SIZE
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
define|#
directive|define
name|RTLABEL_LEN
value|32
endif|#
directive|endif
name|char
name|rtlabelname
index|[
name|RTLABEL_LEN
index|]
decl_stmt|;
name|u_int32_t
name|rtlabel
decl_stmt|;
block|}
name|v
union|;
union|union
block|{
name|struct
name|pfi_dynaddr
modifier|*
name|dyn
decl_stmt|;
name|struct
name|pfr_ktable
modifier|*
name|tbl
decl_stmt|;
name|int
name|dyncnt
decl_stmt|;
name|int
name|tblcnt
decl_stmt|;
block|}
name|p
union|;
name|u_int8_t
name|type
decl_stmt|;
comment|/* PF_ADDR_* */
name|u_int8_t
name|iflags
decl_stmt|;
comment|/* PFI_AFLAG_* */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|pfi_dynaddr
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pfi_dynaddr
argument_list|)
name|entry
expr_stmt|;
name|struct
name|pf_addr
name|pfid_addr4
decl_stmt|;
name|struct
name|pf_addr
name|pfid_mask4
decl_stmt|;
name|struct
name|pf_addr
name|pfid_addr6
decl_stmt|;
name|struct
name|pf_addr
name|pfid_mask6
decl_stmt|;
name|struct
name|pfr_ktable
modifier|*
name|pfid_kt
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|pfid_kif
decl_stmt|;
name|void
modifier|*
name|pfid_hook_cookie
decl_stmt|;
name|int
name|pfid_net
decl_stmt|;
comment|/* mask or 128 */
name|int
name|pfid_acnt4
decl_stmt|;
comment|/* address count IPv4 */
name|int
name|pfid_acnt6
decl_stmt|;
comment|/* address count IPv6 */
name|sa_family_t
name|pfid_af
decl_stmt|;
comment|/* rule af */
name|u_int8_t
name|pfid_iflags
decl_stmt|;
comment|/* PFI_AFLAG_* */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Address manipulation macros  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|splsoftnet
parameter_list|()
value|splnet()
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x) = htonl((__uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x) = htons((__uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohl((__uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohs((__uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|PF_NAME
value|"pf"
end_define

begin_define
define|#
directive|define
name|PR_NOWAIT
value|M_NOWAIT
end_define

begin_define
define|#
directive|define
name|pool_get
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|uma_zalloc(*(p), (f))
end_define

begin_define
define|#
directive|define
name|pool_put
parameter_list|(
name|p
parameter_list|,
name|o
parameter_list|)
value|uma_zfree(*(p), (o))
end_define

begin_define
define|#
directive|define
name|UMA_CREATE
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|desc
parameter_list|)
define|\
value|var = uma_zcreate(desc, sizeof(type),	\ 			NULL, NULL, NULL, NULL, UMA_ALIGN_PTR, 0); \ 		if (var == NULL) break
end_define

begin_define
define|#
directive|define
name|UMA_DESTROY
parameter_list|(
name|var
parameter_list|)
define|\
value|if(var) uma_zdestroy(var)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|pf_task_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PF_ASSERT
parameter_list|(
name|h
parameter_list|)
value|mtx_assert(&pf_task_mtx, (h))
end_define

begin_define
define|#
directive|define
name|PF_LOCK
parameter_list|()
value|do {			\ 	PF_ASSERT(MA_NOTOWNED);			\ 	mtx_lock(&pf_task_mtx);			\ } while(0)
end_define

begin_define
define|#
directive|define
name|PF_UNLOCK
parameter_list|()
value|do {			\ 	PF_ASSERT(MA_OWNED);			\ 	mtx_unlock(&pf_task_mtx);		\ } while(0)
end_define

begin_define
define|#
directive|define
name|PF_COPYIN
parameter_list|(
name|uaddr
parameter_list|,
name|kaddr
parameter_list|,
name|len
parameter_list|,
name|r
parameter_list|)
value|do {	\ 	PF_UNLOCK();				\ 	r = copyin((uaddr), (kaddr), (len));	\ 	PF_LOCK();				\ } while(0)
end_define

begin_define
define|#
directive|define
name|PF_COPYOUT
parameter_list|(
name|kaddr
parameter_list|,
name|uaddr
parameter_list|,
name|len
parameter_list|,
name|r
parameter_list|)
value|do {	\ 	PF_UNLOCK();				\ 	r = copyout((kaddr), (uaddr), (len));	\ 	PF_LOCK();				\ } while(0)
end_define

begin_function_decl
specifier|extern
name|void
name|init_pf_mutex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_pf_mutex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PF_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|PFLOG_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|PFSYNC_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|PFLOG_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|PFLOG_PREFVER
value|PFLOG_MODVER
end_define

begin_define
define|#
directive|define
name|PFLOG_MAXVER
value|1
end_define

begin_define
define|#
directive|define
name|PFSYNC_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|PFSYNC_PREFVER
value|PFSYNC_MODVER
end_define

begin_define
define|#
directive|define
name|PFSYNC_MAXVER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|INET6
end_ifndef

begin_define
define|#
directive|define
name|PF_INET_ONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! INET6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|INET
end_ifndef

begin_define
define|#
directive|define
name|PF_INET6_ONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! INET */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|PF_INET_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PF_INET_INET6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* Both IPv4 and IPv6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PF_INET_INET6
end_ifdef

begin_define
define|#
directive|define
name|PF_AEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((c == AF_INET&& (a)->addr32[0] == (b)->addr32[0]) || \ 	((a)->addr32[3] == (b)->addr32[3]&& \ 	(a)->addr32[2] == (b)->addr32[2]&& \ 	(a)->addr32[1] == (b)->addr32[1]&& \ 	(a)->addr32[0] == (b)->addr32[0])) \  #define PF_ANEQ(a, b, c) \ 	((c == AF_INET&& (a)->addr32[0] != (b)->addr32[0]) || \ 	((a)->addr32[3] != (b)->addr32[3] || \ 	(a)->addr32[2] != (b)->addr32[2] || \ 	(a)->addr32[1] != (b)->addr32[1] || \ 	(a)->addr32[0] != (b)->addr32[0])) \  #define PF_AZERO(a, c) \ 	((c == AF_INET&& !(a)->addr32[0]) || \ 	(!(a)->addr32[0]&& !(a)->addr32[1]&& \ 	!(a)->addr32[2]&& !(a)->addr32[3] )) \  #define PF_MATCHA(n, a, m, b, f) \ 	pf_match_addr(n, a, m, b, f)
end_define

begin_define
define|#
directive|define
name|PF_ACPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_addrcpy(a, b, f)
end_define

begin_define
define|#
directive|define
name|PF_AINC
parameter_list|(
name|a
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_addr_inc(a, f)
end_define

begin_define
define|#
directive|define
name|PF_POOLMASK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_poolmask(a, b, c, d, f)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Just IPv6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PF_INET6_ONLY
end_ifdef

begin_define
define|#
directive|define
name|PF_AEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((a)->addr32[3] == (b)->addr32[3]&& \ 	(a)->addr32[2] == (b)->addr32[2]&& \ 	(a)->addr32[1] == (b)->addr32[1]&& \ 	(a)->addr32[0] == (b)->addr32[0]) \  #define PF_ANEQ(a, b, c) \ 	((a)->addr32[3] != (b)->addr32[3] || \ 	(a)->addr32[2] != (b)->addr32[2] || \ 	(a)->addr32[1] != (b)->addr32[1] || \ 	(a)->addr32[0] != (b)->addr32[0]) \  #define PF_AZERO(a, c) \ 	(!(a)->addr32[0]&& \ 	!(a)->addr32[1]&& \ 	!(a)->addr32[2]&& \ 	!(a)->addr32[3] ) \  #define PF_MATCHA(n, a, m, b, f) \ 	pf_match_addr(n, a, m, b, f)
end_define

begin_define
define|#
directive|define
name|PF_ACPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_addrcpy(a, b, f)
end_define

begin_define
define|#
directive|define
name|PF_AINC
parameter_list|(
name|a
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_addr_inc(a, f)
end_define

begin_define
define|#
directive|define
name|PF_POOLMASK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_poolmask(a, b, c, d, f)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Just IPv4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PF_INET_ONLY
end_ifdef

begin_define
define|#
directive|define
name|PF_AEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((a)->addr32[0] == (b)->addr32[0])
end_define

begin_define
define|#
directive|define
name|PF_ANEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((a)->addr32[0] != (b)->addr32[0])
end_define

begin_define
define|#
directive|define
name|PF_AZERO
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|)
define|\
value|(!(a)->addr32[0])
end_define

begin_define
define|#
directive|define
name|PF_MATCHA
parameter_list|(
name|n
parameter_list|,
name|a
parameter_list|,
name|m
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
define|\
value|pf_match_addr(n, a, m, b, f)
end_define

begin_define
define|#
directive|define
name|PF_ACPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
define|\
value|(a)->v4.s_addr = (b)->v4.s_addr
end_define

begin_define
define|#
directive|define
name|PF_AINC
parameter_list|(
name|a
parameter_list|,
name|f
parameter_list|)
define|\
value|do { \ 		(a)->addr32[0] = htonl(ntohl((a)->addr32[0]) + 1); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PF_POOLMASK
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|f
parameter_list|)
define|\
value|do { \ 		(a)->addr32[0] = ((b)->addr32[0]& (c)->addr32[0]) | \ 		(((c)->addr32[0] ^ 0xffffffff )& (d)->addr32[0]); \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PF_INET_ONLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PF_INET6_ONLY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PF_INET_INET6 */
end_comment

begin_define
define|#
directive|define
name|PF_MISMATCHAW
parameter_list|(
name|aw
parameter_list|,
name|x
parameter_list|,
name|af
parameter_list|,
name|neg
parameter_list|,
name|ifp
parameter_list|)
define|\
value|(								\ 		(((aw)->type == PF_ADDR_NOROUTE&&			\ 		    pf_routable((x), (af), NULL)) ||			\ 		(((aw)->type == PF_ADDR_URPFFAILED&& (ifp) != NULL&&	\ 		    pf_routable((x), (af), (ifp))) ||			\ 		((aw)->type == PF_ADDR_RTLABEL&&			\ 		    !pf_rtlabel_match((x), (af), (aw))) ||		\ 		((aw)->type == PF_ADDR_TABLE&&				\ 		    !pfr_match_addr((aw)->p.tbl, (x), (af))) ||		\ 		((aw)->type == PF_ADDR_DYNIFTL&&			\ 		    !pfi_match_addr((aw)->p.dyn, (x), (af))) || 	\ 		((aw)->type == PF_ADDR_ADDRMASK&&			\ 		    !PF_AZERO(&(aw)->v.a.mask, (af))&&			\ 		    !PF_MATCHA(0,&(aw)->v.a.addr,			\&(aw)->v.a.mask, (x), (af))))) !=			\ 		(neg)							\ 	)
end_define

begin_struct
struct|struct
name|pf_rule_uid
block|{
name|uid_t
name|uid
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|op
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_rule_gid
block|{
name|uid_t
name|gid
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|op
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_rule_addr
block|{
name|struct
name|pf_addr_wrap
name|addr
decl_stmt|;
name|u_int16_t
name|port
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|neg
decl_stmt|;
name|u_int8_t
name|port_op
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_pooladdr
block|{
name|struct
name|pf_addr_wrap
name|addr
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pf_pooladdr
argument_list|)
name|entries
expr_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|kif
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pf_palist
argument_list|,
name|pf_pooladdr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pf_poolhashkey
block|{
union|union
block|{
name|u_int8_t
name|key8
index|[
literal|16
index|]
decl_stmt|;
name|u_int16_t
name|key16
index|[
literal|8
index|]
decl_stmt|;
name|u_int32_t
name|key32
index|[
literal|4
index|]
decl_stmt|;
block|}
name|pfk
union|;
comment|/* 128-bit hash key */
define|#
directive|define
name|key8
value|pfk.key8
define|#
directive|define
name|key16
value|pfk.key16
define|#
directive|define
name|key32
value|pfk.key32
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_pool
block|{
name|struct
name|pf_palist
name|list
decl_stmt|;
name|struct
name|pf_pooladdr
modifier|*
name|cur
decl_stmt|;
name|struct
name|pf_poolhashkey
name|key
decl_stmt|;
name|struct
name|pf_addr
name|counter
decl_stmt|;
name|int
name|tblidx
decl_stmt|;
name|u_int16_t
name|proxy_port
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|port_op
decl_stmt|;
name|u_int8_t
name|opts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A packed Operating System description for fingerprinting */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|pf_osfp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PF_OSFP_ANY
value|((pf_osfp_t)0)
end_define

begin_define
define|#
directive|define
name|PF_OSFP_UNKNOWN
value|((pf_osfp_t)-1)
end_define

begin_define
define|#
directive|define
name|PF_OSFP_NOMATCH
value|((pf_osfp_t)-2)
end_define

begin_struct
struct|struct
name|pf_osfp_entry
block|{
name|SLIST_ENTRY
argument_list|(
argument|pf_osfp_entry
argument_list|)
name|fp_entry
expr_stmt|;
name|pf_osfp_t
name|fp_os
decl_stmt|;
name|int
name|fp_enflags
decl_stmt|;
define|#
directive|define
name|PF_OSFP_EXPANDED
value|0x001
comment|/* expanded entry */
define|#
directive|define
name|PF_OSFP_GENERIC
value|0x002
comment|/* generic signature */
define|#
directive|define
name|PF_OSFP_NODETAIL
value|0x004
comment|/* no p0f details */
define|#
directive|define
name|PF_OSFP_LEN
value|32
name|char
name|fp_class_nm
index|[
name|PF_OSFP_LEN
index|]
decl_stmt|;
name|char
name|fp_version_nm
index|[
name|PF_OSFP_LEN
index|]
decl_stmt|;
name|char
name|fp_subtype_nm
index|[
name|PF_OSFP_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PF_OSFP_ENTRY_EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((a)->fp_os == (b)->fp_os&& \     memcmp((a)->fp_class_nm, (b)->fp_class_nm, PF_OSFP_LEN) == 0&& \     memcmp((a)->fp_version_nm, (b)->fp_version_nm, PF_OSFP_LEN) == 0&& \     memcmp((a)->fp_subtype_nm, (b)->fp_subtype_nm, PF_OSFP_LEN) == 0)
end_define

begin_comment
comment|/* handle pf_osfp_t packing */
end_comment

begin_define
define|#
directive|define
name|_FP_RESERVED_BIT
value|1
end_define

begin_comment
comment|/* For the special negative #defines */
end_comment

begin_define
define|#
directive|define
name|_FP_UNUSED_BITS
value|1
end_define

begin_define
define|#
directive|define
name|_FP_CLASS_BITS
value|10
end_define

begin_comment
comment|/* OS Class (Windows, Linux) */
end_comment

begin_define
define|#
directive|define
name|_FP_VERSION_BITS
value|10
end_define

begin_comment
comment|/* OS version (95, 98, NT, 2.4.54, 3.2) */
end_comment

begin_define
define|#
directive|define
name|_FP_SUBTYPE_BITS
value|10
end_define

begin_comment
comment|/* patch level (NT SP4, SP3, ECN patch) */
end_comment

begin_define
define|#
directive|define
name|PF_OSFP_UNPACK
parameter_list|(
name|osfp
parameter_list|,
name|class
parameter_list|,
name|version
parameter_list|,
name|subtype
parameter_list|)
value|do { \ 	(class) = ((osfp)>> (_FP_VERSION_BITS+_FP_SUBTYPE_BITS))& \ 	    ((1<< _FP_CLASS_BITS) - 1); \ 	(version) = ((osfp)>> _FP_SUBTYPE_BITS)& \ 	    ((1<< _FP_VERSION_BITS) - 1);\ 	(subtype) = (osfp)& ((1<< _FP_SUBTYPE_BITS) - 1); \ } while(0)
end_define

begin_define
define|#
directive|define
name|PF_OSFP_PACK
parameter_list|(
name|osfp
parameter_list|,
name|class
parameter_list|,
name|version
parameter_list|,
name|subtype
parameter_list|)
value|do { \ 	(osfp) = ((class)& ((1<< _FP_CLASS_BITS) - 1))<< (_FP_VERSION_BITS \ 	    + _FP_SUBTYPE_BITS); \ 	(osfp) |= ((version)& ((1<< _FP_VERSION_BITS) - 1))<< \ 	    _FP_SUBTYPE_BITS; \ 	(osfp) |= (subtype)& ((1<< _FP_SUBTYPE_BITS) - 1); \ } while(0)
end_define

begin_comment
comment|/* the fingerprint of an OSes TCP SYN packet */
end_comment

begin_typedef
typedef|typedef
name|u_int64_t
name|pf_tcpopts_t
typedef|;
end_typedef

begin_struct
struct|struct
name|pf_os_fingerprint
block|{
name|SLIST_HEAD
argument_list|(
argument|pf_osfp_enlist
argument_list|,
argument|pf_osfp_entry
argument_list|)
name|fp_oses
expr_stmt|;
comment|/* list of matches */
name|pf_tcpopts_t
name|fp_tcpopts
decl_stmt|;
comment|/* packed TCP options */
name|u_int16_t
name|fp_wsize
decl_stmt|;
comment|/* TCP window size */
name|u_int16_t
name|fp_psize
decl_stmt|;
comment|/* ip->ip_len */
name|u_int16_t
name|fp_mss
decl_stmt|;
comment|/* TCP MSS */
name|u_int16_t
name|fp_flags
decl_stmt|;
define|#
directive|define
name|PF_OSFP_WSIZE_MOD
value|0x0001
comment|/* Window modulus */
define|#
directive|define
name|PF_OSFP_WSIZE_DC
value|0x0002
comment|/* Window don't care */
define|#
directive|define
name|PF_OSFP_WSIZE_MSS
value|0x0004
comment|/* Window multiple of MSS */
define|#
directive|define
name|PF_OSFP_WSIZE_MTU
value|0x0008
comment|/* Window multiple of MTU */
define|#
directive|define
name|PF_OSFP_PSIZE_MOD
value|0x0010
comment|/* packet size modulus */
define|#
directive|define
name|PF_OSFP_PSIZE_DC
value|0x0020
comment|/* packet size don't care */
define|#
directive|define
name|PF_OSFP_WSCALE
value|0x0040
comment|/* TCP window scaling */
define|#
directive|define
name|PF_OSFP_WSCALE_MOD
value|0x0080
comment|/* TCP window scale modulus */
define|#
directive|define
name|PF_OSFP_WSCALE_DC
value|0x0100
comment|/* TCP window scale dont-care */
define|#
directive|define
name|PF_OSFP_MSS
value|0x0200
comment|/* TCP MSS */
define|#
directive|define
name|PF_OSFP_MSS_MOD
value|0x0400
comment|/* TCP MSS modulus */
define|#
directive|define
name|PF_OSFP_MSS_DC
value|0x0800
comment|/* TCP MSS dont-care */
define|#
directive|define
name|PF_OSFP_DF
value|0x1000
comment|/* IPv4 don't fragment bit */
define|#
directive|define
name|PF_OSFP_TS0
value|0x2000
comment|/* Zero timestamp */
define|#
directive|define
name|PF_OSFP_INET6
value|0x4000
comment|/* IPv6 */
name|u_int8_t
name|fp_optcnt
decl_stmt|;
comment|/* TCP option count */
name|u_int8_t
name|fp_wscale
decl_stmt|;
comment|/* TCP window scaling */
name|u_int8_t
name|fp_ttl
decl_stmt|;
comment|/* IPv4 TTL */
define|#
directive|define
name|PF_OSFP_MAXTTL_OFFSET
value|40
comment|/* TCP options packing */
define|#
directive|define
name|PF_OSFP_TCPOPT_NOP
value|0x0
comment|/* TCP NOP option */
define|#
directive|define
name|PF_OSFP_TCPOPT_WSCALE
value|0x1
comment|/* TCP window scaling option */
define|#
directive|define
name|PF_OSFP_TCPOPT_MSS
value|0x2
comment|/* TCP max segment size opt */
define|#
directive|define
name|PF_OSFP_TCPOPT_SACK
value|0x3
comment|/* TCP SACK OK option */
define|#
directive|define
name|PF_OSFP_TCPOPT_TS
value|0x4
comment|/* TCP timestamp option */
define|#
directive|define
name|PF_OSFP_TCPOPT_BITS
value|3
comment|/* bits used by each option */
define|#
directive|define
name|PF_OSFP_MAX_OPTS
define|\
value|(sizeof(((struct pf_os_fingerprint *)0)->fp_tcpopts) * 8) \     / PF_OSFP_TCPOPT_BITS
name|SLIST_ENTRY
argument_list|(
argument|pf_os_fingerprint
argument_list|)
name|fp_next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_osfp_ioctl
block|{
name|struct
name|pf_osfp_entry
name|fp_os
decl_stmt|;
name|pf_tcpopts_t
name|fp_tcpopts
decl_stmt|;
comment|/* packed TCP options */
name|u_int16_t
name|fp_wsize
decl_stmt|;
comment|/* TCP window size */
name|u_int16_t
name|fp_psize
decl_stmt|;
comment|/* ip->ip_len */
name|u_int16_t
name|fp_mss
decl_stmt|;
comment|/* TCP MSS */
name|u_int16_t
name|fp_flags
decl_stmt|;
name|u_int8_t
name|fp_optcnt
decl_stmt|;
comment|/* TCP option count */
name|u_int8_t
name|fp_wscale
decl_stmt|;
comment|/* TCP window scaling */
name|u_int8_t
name|fp_ttl
decl_stmt|;
comment|/* IPv4 TTL */
name|int
name|fp_getnum
decl_stmt|;
comment|/* DIOCOSFPGET number */
block|}
struct|;
end_struct

begin_union
union|union
name|pf_rule_ptr
block|{
name|struct
name|pf_rule
modifier|*
name|ptr
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|PF_ANCHOR_NAME_SIZE
value|64
end_define

begin_struct
struct|struct
name|pf_rule
block|{
name|struct
name|pf_rule_addr
name|src
decl_stmt|;
name|struct
name|pf_rule_addr
name|dst
decl_stmt|;
define|#
directive|define
name|PF_SKIP_IFP
value|0
define|#
directive|define
name|PF_SKIP_DIR
value|1
define|#
directive|define
name|PF_SKIP_AF
value|2
define|#
directive|define
name|PF_SKIP_PROTO
value|3
define|#
directive|define
name|PF_SKIP_SRC_ADDR
value|4
define|#
directive|define
name|PF_SKIP_SRC_PORT
value|5
define|#
directive|define
name|PF_SKIP_DST_ADDR
value|6
define|#
directive|define
name|PF_SKIP_DST_PORT
value|7
define|#
directive|define
name|PF_SKIP_COUNT
value|8
name|union
name|pf_rule_ptr
name|skip
index|[
name|PF_SKIP_COUNT
index|]
decl_stmt|;
define|#
directive|define
name|PF_RULE_LABEL_SIZE
value|64
name|char
name|label
index|[
name|PF_RULE_LABEL_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|PF_QNAME_SIZE
value|64
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|char
name|qname
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
name|char
name|pqname
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|PF_TAG_NAME_SIZE
value|64
name|char
name|tagname
index|[
name|PF_TAG_NAME_SIZE
index|]
decl_stmt|;
name|char
name|match_tagname
index|[
name|PF_TAG_NAME_SIZE
index|]
decl_stmt|;
name|char
name|overload_tblname
index|[
name|PF_TABLE_NAME_SIZE
index|]
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pf_rule
argument_list|)
name|entries
expr_stmt|;
name|struct
name|pf_pool
name|rpool
decl_stmt|;
name|u_int64_t
name|evaluations
decl_stmt|;
name|u_int64_t
name|packets
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|bytes
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|kif
decl_stmt|;
name|struct
name|pf_anchor
modifier|*
name|anchor
decl_stmt|;
name|struct
name|pfr_ktable
modifier|*
name|overload_tbl
decl_stmt|;
name|pf_osfp_t
name|os_fingerprint
decl_stmt|;
name|int
name|rtableid
decl_stmt|;
name|u_int32_t
name|timeout
index|[
name|PFTM_MAX
index|]
decl_stmt|;
name|u_int32_t
name|states
decl_stmt|;
name|u_int32_t
name|max_states
decl_stmt|;
name|u_int32_t
name|src_nodes
decl_stmt|;
name|u_int32_t
name|max_src_nodes
decl_stmt|;
name|u_int32_t
name|max_src_states
decl_stmt|;
name|u_int32_t
name|spare1
decl_stmt|;
comment|/* netgraph */
name|u_int32_t
name|max_src_conn
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|limit
decl_stmt|;
name|u_int32_t
name|seconds
decl_stmt|;
block|}
name|max_src_conn_rate
struct|;
name|u_int32_t
name|qid
decl_stmt|;
name|u_int32_t
name|pqid
decl_stmt|;
name|u_int32_t
name|rt_listid
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
name|u_int32_t
name|prob
decl_stmt|;
name|uid_t
name|cuid
decl_stmt|;
name|pid_t
name|cpid
decl_stmt|;
name|u_int16_t
name|return_icmp
decl_stmt|;
name|u_int16_t
name|return_icmp6
decl_stmt|;
name|u_int16_t
name|max_mss
decl_stmt|;
name|u_int16_t
name|tag
decl_stmt|;
name|u_int16_t
name|match_tag
decl_stmt|;
name|u_int16_t
name|spare2
decl_stmt|;
comment|/* netgraph */
name|struct
name|pf_rule_uid
name|uid
decl_stmt|;
name|struct
name|pf_rule_gid
name|gid
decl_stmt|;
name|u_int32_t
name|rule_flag
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
name|u_int8_t
name|direction
decl_stmt|;
name|u_int8_t
name|log
decl_stmt|;
name|u_int8_t
name|logif
decl_stmt|;
name|u_int8_t
name|quick
decl_stmt|;
name|u_int8_t
name|ifnot
decl_stmt|;
name|u_int8_t
name|match_tag_not
decl_stmt|;
name|u_int8_t
name|natpass
decl_stmt|;
define|#
directive|define
name|PF_STATE_NORMAL
value|0x1
define|#
directive|define
name|PF_STATE_MODULATE
value|0x2
define|#
directive|define
name|PF_STATE_SYNPROXY
value|0x3
name|u_int8_t
name|keep_state
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|code
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|flagset
decl_stmt|;
name|u_int8_t
name|min_ttl
decl_stmt|;
name|u_int8_t
name|allow_opts
decl_stmt|;
name|u_int8_t
name|rt
decl_stmt|;
name|u_int8_t
name|return_ttl
decl_stmt|;
name|u_int8_t
name|tos
decl_stmt|;
name|u_int8_t
name|anchor_relative
decl_stmt|;
name|u_int8_t
name|anchor_wildcard
decl_stmt|;
define|#
directive|define
name|PF_FLUSH
value|0x01
define|#
directive|define
name|PF_FLUSH_GLOBAL
value|0x02
name|u_int8_t
name|flush
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* rule flags */
end_comment

begin_define
define|#
directive|define
name|PFRULE_DROP
value|0x0000
end_define

begin_define
define|#
directive|define
name|PFRULE_RETURNRST
value|0x0001
end_define

begin_define
define|#
directive|define
name|PFRULE_FRAGMENT
value|0x0002
end_define

begin_define
define|#
directive|define
name|PFRULE_RETURNICMP
value|0x0004
end_define

begin_define
define|#
directive|define
name|PFRULE_RETURN
value|0x0008
end_define

begin_define
define|#
directive|define
name|PFRULE_NOSYNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|PFRULE_SRCTRACK
value|0x0020
end_define

begin_comment
comment|/* track source states */
end_comment

begin_define
define|#
directive|define
name|PFRULE_RULESRCTRACK
value|0x0040
end_define

begin_comment
comment|/* per rule */
end_comment

begin_comment
comment|/* scrub flags */
end_comment

begin_define
define|#
directive|define
name|PFRULE_NODF
value|0x0100
end_define

begin_define
define|#
directive|define
name|PFRULE_FRAGCROP
value|0x0200
end_define

begin_comment
comment|/* non-buffering frag cache */
end_comment

begin_define
define|#
directive|define
name|PFRULE_FRAGDROP
value|0x0400
end_define

begin_comment
comment|/* drop funny fragments */
end_comment

begin_define
define|#
directive|define
name|PFRULE_RANDOMID
value|0x0800
end_define

begin_define
define|#
directive|define
name|PFRULE_REASSEMBLE_TCP
value|0x1000
end_define

begin_comment
comment|/* rule flags again */
end_comment

begin_define
define|#
directive|define
name|PFRULE_IFBOUND
value|0x00010000
end_define

begin_comment
comment|/* if-bound */
end_comment

begin_define
define|#
directive|define
name|PFRULE_STATESLOPPY
value|0x00020000
end_define

begin_comment
comment|/* sloppy state tracking */
end_comment

begin_define
define|#
directive|define
name|PFSTATE_HIWAT
value|10000
end_define

begin_comment
comment|/* default state table size */
end_comment

begin_define
define|#
directive|define
name|PFSTATE_ADAPT_START
value|6000
end_define

begin_comment
comment|/* default adaptive timeout start */
end_comment

begin_define
define|#
directive|define
name|PFSTATE_ADAPT_END
value|12000
end_define

begin_comment
comment|/* default adaptive timeout end */
end_comment

begin_struct
struct|struct
name|pf_threshold
block|{
name|u_int32_t
name|limit
decl_stmt|;
define|#
directive|define
name|PF_THRESHOLD_MULT
value|1000
define|#
directive|define
name|PF_THRESHOLD_MAX
value|0xffffffff / PF_THRESHOLD_MULT
name|u_int32_t
name|seconds
decl_stmt|;
name|u_int32_t
name|count
decl_stmt|;
name|u_int32_t
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_src_node
block|{
name|RB_ENTRY
argument_list|(
argument|pf_src_node
argument_list|)
name|entry
expr_stmt|;
name|struct
name|pf_addr
name|addr
decl_stmt|;
name|struct
name|pf_addr
name|raddr
decl_stmt|;
name|union
name|pf_rule_ptr
name|rule
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|kif
decl_stmt|;
name|u_int64_t
name|bytes
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|packets
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|states
decl_stmt|;
name|u_int32_t
name|conn
decl_stmt|;
name|struct
name|pf_threshold
name|conn_rate
decl_stmt|;
name|u_int32_t
name|creation
decl_stmt|;
name|u_int32_t
name|expire
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|ruletype
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSNODE_HIWAT
value|10000
end_define

begin_comment
comment|/* default source node table size */
end_comment

begin_struct
struct|struct
name|pf_state_scrub
block|{
name|struct
name|timeval
name|pfss_last
decl_stmt|;
comment|/* time received last packet	*/
name|u_int32_t
name|pfss_tsecr
decl_stmt|;
comment|/* last echoed timestamp	*/
name|u_int32_t
name|pfss_tsval
decl_stmt|;
comment|/* largest timestamp		*/
name|u_int32_t
name|pfss_tsval0
decl_stmt|;
comment|/* original timestamp		*/
name|u_int16_t
name|pfss_flags
decl_stmt|;
define|#
directive|define
name|PFSS_TIMESTAMP
value|0x0001
comment|/* modulate timestamp		*/
define|#
directive|define
name|PFSS_PAWS
value|0x0010
comment|/* stricter PAWS checks		*/
define|#
directive|define
name|PFSS_PAWS_IDLED
value|0x0020
comment|/* was idle too long.  no PAWS	*/
define|#
directive|define
name|PFSS_DATA_TS
value|0x0040
comment|/* timestamp on data packets	*/
define|#
directive|define
name|PFSS_DATA_NOTS
value|0x0080
comment|/* no timestamp on data packets	*/
name|u_int8_t
name|pfss_ttl
decl_stmt|;
comment|/* stashed TTL			*/
name|u_int8_t
name|pad
decl_stmt|;
name|u_int32_t
name|pfss_ts_mod
decl_stmt|;
comment|/* timestamp modulation		*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_state_host
block|{
name|struct
name|pf_addr
name|addr
decl_stmt|;
name|u_int16_t
name|port
decl_stmt|;
name|u_int16_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_state_peer
block|{
name|u_int32_t
name|seqlo
decl_stmt|;
comment|/* Max sequence number sent	*/
name|u_int32_t
name|seqhi
decl_stmt|;
comment|/* Max the other end ACKd + win	*/
name|u_int32_t
name|seqdiff
decl_stmt|;
comment|/* Sequence number modulator	*/
name|u_int16_t
name|max_win
decl_stmt|;
comment|/* largest window (pre scaling)	*/
name|u_int8_t
name|state
decl_stmt|;
comment|/* active state level		*/
name|u_int8_t
name|wscale
decl_stmt|;
comment|/* window scaling factor	*/
name|u_int16_t
name|mss
decl_stmt|;
comment|/* Maximum segment size option	*/
name|u_int8_t
name|tcp_est
decl_stmt|;
comment|/* Did we reach TCPS_ESTABLISHED */
name|struct
name|pf_state_scrub
modifier|*
name|scrub
decl_stmt|;
comment|/* state is scrubbed		*/
name|u_int8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pf_state_queue
argument_list|,
name|pf_state
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* keep synced with struct pf_state, used in RB_FIND */
end_comment

begin_struct
struct|struct
name|pf_state_cmp
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|struct
name|pf_state_host
name|lan
decl_stmt|;
name|struct
name|pf_state_host
name|gwy
decl_stmt|;
name|struct
name|pf_state_host
name|ext
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|direction
decl_stmt|;
name|u_int8_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_state
block|{
name|u_int64_t
name|id
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|struct
name|pf_state_host
name|lan
decl_stmt|;
name|struct
name|pf_state_host
name|gwy
decl_stmt|;
name|struct
name|pf_state_host
name|ext
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|direction
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|u_int8_t
name|local_flags
decl_stmt|;
define|#
directive|define
name|PFSTATE_EXPIRING
value|0x01
else|#
directive|else
name|u_int8_t
name|pad
decl_stmt|;
endif|#
directive|endif
name|u_int8_t
name|log
decl_stmt|;
name|u_int8_t
name|state_flags
decl_stmt|;
define|#
directive|define
name|PFSTATE_ALLOWOPTS
value|0x01
define|#
directive|define
name|PFSTATE_SLOPPY
value|0x02
name|u_int8_t
name|timeout
decl_stmt|;
name|u_int8_t
name|sync_flags
decl_stmt|;
define|#
directive|define
name|PFSTATE_NOSYNC
value|0x01
define|#
directive|define
name|PFSTATE_FROMSYNC
value|0x02
define|#
directive|define
name|PFSTATE_STALE
value|0x04
union|union
block|{
struct|struct
block|{
name|RB_ENTRY
argument_list|(
argument|pf_state
argument_list|)
name|entry_lan_ext
expr_stmt|;
name|RB_ENTRY
argument_list|(
argument|pf_state
argument_list|)
name|entry_ext_gwy
expr_stmt|;
name|RB_ENTRY
argument_list|(
argument|pf_state
argument_list|)
name|entry_id
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pf_state
argument_list|)
name|entry_list
expr_stmt|;
name|struct
name|pfi_kif
modifier|*
name|kif
decl_stmt|;
block|}
name|s
struct|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
name|u
union|;
name|struct
name|pf_state_peer
name|src
decl_stmt|;
name|struct
name|pf_state_peer
name|dst
decl_stmt|;
name|union
name|pf_rule_ptr
name|rule
decl_stmt|;
name|union
name|pf_rule_ptr
name|anchor
decl_stmt|;
name|union
name|pf_rule_ptr
name|nat_rule
decl_stmt|;
name|struct
name|pf_addr
name|rt_addr
decl_stmt|;
name|struct
name|pfi_kif
modifier|*
name|rt_kif
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|src_node
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|nat_src_node
decl_stmt|;
name|u_int64_t
name|packets
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|bytes
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|creation
decl_stmt|;
name|u_int32_t
name|expire
decl_stmt|;
name|u_int32_t
name|pfsync_time
decl_stmt|;
name|u_int16_t
name|tag
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pf_rulequeue
argument_list|,
name|pf_rule
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|pf_anchor
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|pf_ruleset
block|{
struct|struct
block|{
name|struct
name|pf_rulequeue
name|queues
index|[
literal|2
index|]
decl_stmt|;
struct|struct
block|{
name|struct
name|pf_rulequeue
modifier|*
name|ptr
decl_stmt|;
name|struct
name|pf_rule
modifier|*
modifier|*
name|ptr_array
decl_stmt|;
name|u_int32_t
name|rcount
decl_stmt|;
name|u_int32_t
name|ticket
decl_stmt|;
name|int
name|open
decl_stmt|;
block|}
name|active
struct|,
name|inactive
struct|;
block|}
name|rules
index|[
name|PF_RULESET_MAX
index|]
struct|;
name|struct
name|pf_anchor
modifier|*
name|anchor
decl_stmt|;
name|u_int32_t
name|tticket
decl_stmt|;
name|int
name|tables
decl_stmt|;
name|int
name|topen
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_anchor_global
argument_list|,
name|pf_anchor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_anchor_node
argument_list|,
name|pf_anchor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pf_anchor
block|{
name|RB_ENTRY
argument_list|(
argument|pf_anchor
argument_list|)
name|entry_global
expr_stmt|;
name|RB_ENTRY
argument_list|(
argument|pf_anchor
argument_list|)
name|entry_node
expr_stmt|;
name|struct
name|pf_anchor
modifier|*
name|parent
decl_stmt|;
name|struct
name|pf_anchor_node
name|children
decl_stmt|;
name|char
name|name
index|[
name|PF_ANCHOR_NAME_SIZE
index|]
decl_stmt|;
name|char
name|path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|struct
name|pf_ruleset
name|ruleset
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
comment|/* anchor rules */
name|int
name|match
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_anchor_global
argument_list|,
name|pf_anchor
argument_list|,
name|entry_global
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_anchor_node
argument_list|,
name|pf_anchor
argument_list|,
name|entry_node
argument_list|,
name|pf_anchor_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PF_RESERVED_ANCHOR
value|"_pf"
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_PERSIST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_CONST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_ACTIVE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_INACTIVE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_REFERENCED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_REFDANCHOR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_USRMASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_SETMASK
value|0x0000003C
end_define

begin_define
define|#
directive|define
name|PFR_TFLAG_ALLMASK
value|0x0000003F
end_define

begin_struct
struct|struct
name|pfr_table
block|{
name|char
name|pfrt_anchor
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|pfrt_name
index|[
name|PF_TABLE_NAME_SIZE
index|]
decl_stmt|;
name|u_int32_t
name|pfrt_flags
decl_stmt|;
name|u_int8_t
name|pfrt_fback
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|PFR_FB_NONE
block|,
name|PFR_FB_MATCH
block|,
name|PFR_FB_ADDED
block|,
name|PFR_FB_DELETED
block|,
name|PFR_FB_CHANGED
block|,
name|PFR_FB_CLEARED
block|,
name|PFR_FB_DUPLICATE
block|,
name|PFR_FB_NOTMATCH
block|,
name|PFR_FB_CONFLICT
block|,
name|PFR_FB_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pfr_addr
block|{
union|union
block|{
name|struct
name|in_addr
name|_pfra_ip4addr
decl_stmt|;
name|struct
name|in6_addr
name|_pfra_ip6addr
decl_stmt|;
block|}
name|pfra_u
union|;
name|u_int8_t
name|pfra_af
decl_stmt|;
name|u_int8_t
name|pfra_net
decl_stmt|;
name|u_int8_t
name|pfra_not
decl_stmt|;
name|u_int8_t
name|pfra_fback
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pfra_ip4addr
value|pfra_u._pfra_ip4addr
end_define

begin_define
define|#
directive|define
name|pfra_ip6addr
value|pfra_u._pfra_ip6addr
end_define

begin_enum
enum|enum
block|{
name|PFR_DIR_IN
block|,
name|PFR_DIR_OUT
block|,
name|PFR_DIR_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|PFR_OP_BLOCK
block|,
name|PFR_OP_PASS
block|,
name|PFR_OP_ADDR_MAX
block|,
name|PFR_OP_TABLE_MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PFR_OP_XPASS
value|PFR_OP_ADDR_MAX
end_define

begin_struct
struct|struct
name|pfr_astats
block|{
name|struct
name|pfr_addr
name|pfras_a
decl_stmt|;
name|u_int64_t
name|pfras_packets
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_ADDR_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pfras_bytes
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_ADDR_MAX
index|]
decl_stmt|;
name|long
name|pfras_tzero
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|PFR_REFCNT_RULE
block|,
name|PFR_REFCNT_ANCHOR
block|,
name|PFR_REFCNT_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|pfr_tstats
block|{
name|struct
name|pfr_table
name|pfrts_t
decl_stmt|;
name|u_int64_t
name|pfrts_packets
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_TABLE_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pfrts_bytes
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_TABLE_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pfrts_match
decl_stmt|;
name|u_int64_t
name|pfrts_nomatch
decl_stmt|;
name|long
name|pfrts_tzero
decl_stmt|;
name|int
name|pfrts_cnt
decl_stmt|;
name|int
name|pfrts_refcnt
index|[
name|PFR_REFCNT_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pfrts_name
value|pfrts_t.pfrt_name
end_define

begin_define
define|#
directive|define
name|pfrts_flags
value|pfrts_t.pfrt_flags
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SOCKADDR_UNION_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_SOCKADDR_UNION_DEFINED
end_define

begin_union
union|union
name|sockaddr_union
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SOCKADDR_UNION_DEFINED */
end_comment

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|pfr_kentryworkq
argument_list|,
name|pfr_kentry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pfr_kentry
block|{
name|struct
name|radix_node
name|pfrke_node
index|[
literal|2
index|]
decl_stmt|;
name|union
name|sockaddr_union
name|pfrke_sa
decl_stmt|;
name|u_int64_t
name|pfrke_packets
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_ADDR_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pfrke_bytes
index|[
name|PFR_DIR_MAX
index|]
index|[
name|PFR_OP_ADDR_MAX
index|]
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|pfr_kentry
argument_list|)
name|pfrke_workq
expr_stmt|;
name|long
name|pfrke_tzero
decl_stmt|;
name|u_int8_t
name|pfrke_af
decl_stmt|;
name|u_int8_t
name|pfrke_net
decl_stmt|;
name|u_int8_t
name|pfrke_not
decl_stmt|;
name|u_int8_t
name|pfrke_mark
decl_stmt|;
name|u_int8_t
name|pfrke_intrpool
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|pfr_ktableworkq
argument_list|,
name|pfr_ktable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pfr_ktablehead
argument_list|,
name|pfr_ktable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pfr_ktable
block|{
name|struct
name|pfr_tstats
name|pfrkt_ts
decl_stmt|;
name|RB_ENTRY
argument_list|(
argument|pfr_ktable
argument_list|)
name|pfrkt_tree
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|pfr_ktable
argument_list|)
name|pfrkt_workq
expr_stmt|;
name|struct
name|radix_node_head
modifier|*
name|pfrkt_ip4
decl_stmt|;
name|struct
name|radix_node_head
modifier|*
name|pfrkt_ip6
decl_stmt|;
name|struct
name|pfr_ktable
modifier|*
name|pfrkt_shadow
decl_stmt|;
name|struct
name|pfr_ktable
modifier|*
name|pfrkt_root
decl_stmt|;
name|struct
name|pf_ruleset
modifier|*
name|pfrkt_rs
decl_stmt|;
name|long
name|pfrkt_larg
decl_stmt|;
name|int
name|pfrkt_nflags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pfrkt_t
value|pfrkt_ts.pfrts_t
end_define

begin_define
define|#
directive|define
name|pfrkt_name
value|pfrkt_t.pfrt_name
end_define

begin_define
define|#
directive|define
name|pfrkt_anchor
value|pfrkt_t.pfrt_anchor
end_define

begin_define
define|#
directive|define
name|pfrkt_ruleset
value|pfrkt_t.pfrt_ruleset
end_define

begin_define
define|#
directive|define
name|pfrkt_flags
value|pfrkt_t.pfrt_flags
end_define

begin_define
define|#
directive|define
name|pfrkt_cnt
value|pfrkt_ts.pfrts_cnt
end_define

begin_define
define|#
directive|define
name|pfrkt_refcnt
value|pfrkt_ts.pfrts_refcnt
end_define

begin_define
define|#
directive|define
name|pfrkt_packets
value|pfrkt_ts.pfrts_packets
end_define

begin_define
define|#
directive|define
name|pfrkt_bytes
value|pfrkt_ts.pfrts_bytes
end_define

begin_define
define|#
directive|define
name|pfrkt_match
value|pfrkt_ts.pfrts_match
end_define

begin_define
define|#
directive|define
name|pfrkt_nomatch
value|pfrkt_ts.pfrts_nomatch
end_define

begin_define
define|#
directive|define
name|pfrkt_tzero
value|pfrkt_ts.pfrts_tzero
end_define

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
name|pf_state
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_state_tree_lan_ext
argument_list|,
name|pf_state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_lan_ext
argument_list|,
name|pf_state_compare_lan_ext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
name|pf_state
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_state_tree_ext_gwy
argument_list|,
name|pf_state
argument_list|,
name|u
operator|.
name|s
operator|.
name|entry_ext_gwy
argument_list|,
name|pf_state_compare_ext_gwy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pfi_statehead
argument_list|,
name|pfi_kif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pfi_ifhead
argument_list|,
name|pfi_kif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* keep synced with pfi_kif, used in RB_FIND */
end_comment

begin_struct
struct|struct
name|pfi_kif_cmp
block|{
name|char
name|pfik_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfi_kif
block|{
name|char
name|pfik_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|RB_ENTRY
argument_list|(
argument|pfi_kif
argument_list|)
name|pfik_tree
expr_stmt|;
name|u_int64_t
name|pfik_packets
index|[
literal|2
index|]
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|pfik_bytes
index|[
literal|2
index|]
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|pfik_tzero
decl_stmt|;
name|int
name|pfik_flags
decl_stmt|;
name|struct
name|pf_state_tree_lan_ext
name|pfik_lan_ext
decl_stmt|;
name|struct
name|pf_state_tree_ext_gwy
name|pfik_ext_gwy
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pfi_kif
argument_list|)
name|pfik_w_states
expr_stmt|;
ifndef|#
directive|ifndef
name|__FreeBSD__
name|void
modifier|*
name|pfik_ah_cookie
decl_stmt|;
endif|#
directive|endif
name|struct
name|ifnet
modifier|*
name|pfik_ifp
decl_stmt|;
name|struct
name|ifg_group
modifier|*
name|pfik_group
decl_stmt|;
name|int
name|pfik_states
decl_stmt|;
name|int
name|pfik_rules
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pfi_dynaddr
argument_list|)
name|pfik_dynaddrs
expr_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|pfi_kif_refs
block|{
name|PFI_KIF_REF_NONE
block|,
name|PFI_KIF_REF_STATE
block|,
name|PFI_KIF_REF_RULE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PFI_IFLAG_SKIP
value|0x0100
end_define

begin_comment
comment|/* skip filtering on interface */
end_comment

begin_comment
comment|/* XXX: revisist */
end_comment

begin_define
define|#
directive|define
name|PFI_IFLAG_SETABLE_MASK
value|0x0100
end_define

begin_comment
comment|/* setable via DIOC{SET,CLR}IFFLAG */
end_comment

begin_define
define|#
directive|define
name|PFI_IFLAG_PLACEHOLDER
value|0x8000
end_define

begin_comment
comment|/* placeholder group/interface */
end_comment

begin_struct
struct|struct
name|pf_pdesc
block|{
struct|struct
block|{
name|int
name|done
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
block|}
name|lookup
struct|;
name|u_int64_t
name|tot_len
decl_stmt|;
comment|/* Make Mickey money */
union|union
block|{
name|struct
name|tcphdr
modifier|*
name|tcp
decl_stmt|;
name|struct
name|udphdr
modifier|*
name|udp
decl_stmt|;
name|struct
name|icmp
modifier|*
name|icmp
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|icmp6_hdr
modifier|*
name|icmp6
decl_stmt|;
endif|#
directive|endif
comment|/* INET6 */
name|void
modifier|*
name|any
decl_stmt|;
block|}
name|hdr
union|;
name|struct
name|pf_addr
name|baddr
decl_stmt|;
comment|/* address before translation */
name|struct
name|pf_addr
name|naddr
decl_stmt|;
comment|/* address after translation */
name|struct
name|pf_rule
modifier|*
name|nat_rule
decl_stmt|;
comment|/* nat/rdr rule applied to packet */
name|struct
name|pf_addr
modifier|*
name|src
decl_stmt|;
name|struct
name|pf_addr
modifier|*
name|dst
decl_stmt|;
name|struct
name|ether_header
modifier|*
name|eh
decl_stmt|;
name|struct
name|pf_mtag
modifier|*
name|pf_mtag
decl_stmt|;
name|u_int16_t
modifier|*
name|ip_sum
decl_stmt|;
name|u_int32_t
name|p_len
decl_stmt|;
comment|/* total length of payload */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* Let SCRUB trigger behavior in 					 * state code. Easier than tags */
define|#
directive|define
name|PFDESC_TCP_NORM
value|0x0001
comment|/* TCP shall be statefully scrubbed */
define|#
directive|define
name|PFDESC_IP_REAS
value|0x0002
comment|/* IP frags would've been reassembled */
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|tos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flags for RDR options */
end_comment

begin_define
define|#
directive|define
name|PF_DPORT_RANGE
value|0x01
end_define

begin_comment
comment|/* Dest port uses range */
end_comment

begin_define
define|#
directive|define
name|PF_RPORT_RANGE
value|0x02
end_define

begin_comment
comment|/* RDR'ed port uses range */
end_comment

begin_comment
comment|/* Reasons code for passing/dropping a packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_MATCH
value|0
end_define

begin_comment
comment|/* Explicit match of a rule */
end_comment

begin_define
define|#
directive|define
name|PFRES_BADOFF
value|1
end_define

begin_comment
comment|/* Bad offset for pull_hdr */
end_comment

begin_define
define|#
directive|define
name|PFRES_FRAG
value|2
end_define

begin_comment
comment|/* Dropping following fragment */
end_comment

begin_define
define|#
directive|define
name|PFRES_SHORT
value|3
end_define

begin_comment
comment|/* Dropping short packet */
end_comment

begin_define
define|#
directive|define
name|PFRES_NORM
value|4
end_define

begin_comment
comment|/* Dropping by normalizer */
end_comment

begin_define
define|#
directive|define
name|PFRES_MEMORY
value|5
end_define

begin_comment
comment|/* Dropped due to lacking mem */
end_comment

begin_define
define|#
directive|define
name|PFRES_TS
value|6
end_define

begin_comment
comment|/* Bad TCP Timestamp (RFC1323) */
end_comment

begin_define
define|#
directive|define
name|PFRES_CONGEST
value|7
end_define

begin_comment
comment|/* Congestion (of ipintrq) */
end_comment

begin_define
define|#
directive|define
name|PFRES_IPOPTIONS
value|8
end_define

begin_comment
comment|/* IP option */
end_comment

begin_define
define|#
directive|define
name|PFRES_PROTCKSUM
value|9
end_define

begin_comment
comment|/* Protocol checksum invalid */
end_comment

begin_define
define|#
directive|define
name|PFRES_BADSTATE
value|10
end_define

begin_comment
comment|/* State mismatch */
end_comment

begin_define
define|#
directive|define
name|PFRES_STATEINS
value|11
end_define

begin_comment
comment|/* State insertion failure */
end_comment

begin_define
define|#
directive|define
name|PFRES_MAXSTATES
value|12
end_define

begin_comment
comment|/* State limit */
end_comment

begin_define
define|#
directive|define
name|PFRES_SRCLIMIT
value|13
end_define

begin_comment
comment|/* Source node/conn limit */
end_comment

begin_define
define|#
directive|define
name|PFRES_SYNPROXY
value|14
end_define

begin_comment
comment|/* SYN proxy */
end_comment

begin_define
define|#
directive|define
name|PFRES_MAX
value|15
end_define

begin_comment
comment|/* total+1 */
end_comment

begin_define
define|#
directive|define
name|PFRES_NAMES
value|{ \ 	"match", \ 	"bad-offset", \ 	"fragment", \ 	"short", \ 	"normalize", \ 	"memory", \ 	"bad-timestamp", \ 	"congestion", \ 	"ip-option", \ 	"proto-cksum", \ 	"state-mismatch", \ 	"state-insert", \ 	"state-limit", \ 	"src-limit", \ 	"synproxy", \ 	NULL \ }
end_define

begin_comment
comment|/* Counters for other things we want to keep track of */
end_comment

begin_define
define|#
directive|define
name|LCNT_STATES
value|0
end_define

begin_comment
comment|/* states */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCSTATES
value|1
end_define

begin_comment
comment|/* max-src-states */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCNODES
value|2
end_define

begin_comment
comment|/* max-src-nodes */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCCONN
value|3
end_define

begin_comment
comment|/* max-src-conn */
end_comment

begin_define
define|#
directive|define
name|LCNT_SRCCONNRATE
value|4
end_define

begin_comment
comment|/* max-src-conn-rate */
end_comment

begin_define
define|#
directive|define
name|LCNT_OVERLOAD_TABLE
value|5
end_define

begin_comment
comment|/* entry added to overload table */
end_comment

begin_define
define|#
directive|define
name|LCNT_OVERLOAD_FLUSH
value|6
end_define

begin_comment
comment|/* state entries flushed */
end_comment

begin_define
define|#
directive|define
name|LCNT_MAX
value|7
end_define

begin_comment
comment|/* total+1 */
end_comment

begin_define
define|#
directive|define
name|LCNT_NAMES
value|{ \ 	"max states per rule", \ 	"max-src-states", \ 	"max-src-nodes", \ 	"max-src-conn", \ 	"max-src-conn-rate", \ 	"overload table insertion", \ 	"overload flush states", \ 	NULL \ }
end_define

begin_comment
comment|/* UDP state enumeration */
end_comment

begin_define
define|#
directive|define
name|PFUDPS_NO_TRAFFIC
value|0
end_define

begin_define
define|#
directive|define
name|PFUDPS_SINGLE
value|1
end_define

begin_define
define|#
directive|define
name|PFUDPS_MULTIPLE
value|2
end_define

begin_define
define|#
directive|define
name|PFUDPS_NSTATES
value|3
end_define

begin_comment
comment|/* number of state levels */
end_comment

begin_define
define|#
directive|define
name|PFUDPS_NAMES
value|{ \ 	"NO_TRAFFIC", \ 	"SINGLE", \ 	"MULTIPLE", \ 	NULL \ }
end_define

begin_comment
comment|/* Other protocol state enumeration */
end_comment

begin_define
define|#
directive|define
name|PFOTHERS_NO_TRAFFIC
value|0
end_define

begin_define
define|#
directive|define
name|PFOTHERS_SINGLE
value|1
end_define

begin_define
define|#
directive|define
name|PFOTHERS_MULTIPLE
value|2
end_define

begin_define
define|#
directive|define
name|PFOTHERS_NSTATES
value|3
end_define

begin_comment
comment|/* number of state levels */
end_comment

begin_define
define|#
directive|define
name|PFOTHERS_NAMES
value|{ \ 	"NO_TRAFFIC", \ 	"SINGLE", \ 	"MULTIPLE", \ 	NULL \ }
end_define

begin_define
define|#
directive|define
name|FCNT_STATE_SEARCH
value|0
end_define

begin_define
define|#
directive|define
name|FCNT_STATE_INSERT
value|1
end_define

begin_define
define|#
directive|define
name|FCNT_STATE_REMOVALS
value|2
end_define

begin_define
define|#
directive|define
name|FCNT_MAX
value|3
end_define

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_SEARCH
value|0
end_define

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_INSERT
value|1
end_define

begin_define
define|#
directive|define
name|SCNT_SRC_NODE_REMOVALS
value|2
end_define

begin_define
define|#
directive|define
name|SCNT_MAX
value|3
end_define

begin_define
define|#
directive|define
name|ACTION_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|do { \ 		if ((a) != NULL) \ 			*(a) = (x); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|REASON_SET
parameter_list|(
name|a
parameter_list|,
name|x
parameter_list|)
define|\
value|do { \ 		if ((a) != NULL) \ 			*(a) = (x); \ 		if (x< PFRES_MAX) \ 			pf_status.counters[x]++; \ 	} while (0)
end_define

begin_struct
struct|struct
name|pf_status
block|{
name|u_int64_t
name|counters
index|[
name|PFRES_MAX
index|]
decl_stmt|;
name|u_int64_t
name|lcounters
index|[
name|LCNT_MAX
index|]
decl_stmt|;
comment|/* limit counters */
name|u_int64_t
name|fcounters
index|[
name|FCNT_MAX
index|]
decl_stmt|;
name|u_int64_t
name|scounters
index|[
name|SCNT_MAX
index|]
decl_stmt|;
name|u_int64_t
name|pcounters
index|[
literal|2
index|]
index|[
literal|2
index|]
index|[
literal|3
index|]
decl_stmt|;
name|u_int64_t
name|bcounters
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
name|u_int64_t
name|stateid
decl_stmt|;
name|u_int32_t
name|running
decl_stmt|;
name|u_int32_t
name|states
decl_stmt|;
name|u_int32_t
name|src_nodes
decl_stmt|;
name|u_int32_t
name|since
decl_stmt|;
name|u_int32_t
name|debug
decl_stmt|;
name|u_int32_t
name|hostid
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_int8_t
name|pf_chksum
index|[
name|PF_MD5_DIGEST_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cbq_opts
block|{
name|u_int
name|minburst
decl_stmt|;
name|u_int
name|maxburst
decl_stmt|;
name|u_int
name|pktsize
decl_stmt|;
name|u_int
name|maxpktsize
decl_stmt|;
name|u_int
name|ns_per_byte
decl_stmt|;
name|u_int
name|maxidle
decl_stmt|;
name|int
name|minidle
decl_stmt|;
name|u_int
name|offtime
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|priq_opts
block|{
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hfsc_opts
block|{
comment|/* real-time service curve */
name|u_int
name|rtsc_m1
decl_stmt|;
comment|/* slope of the 1st segment in bps */
name|u_int
name|rtsc_d
decl_stmt|;
comment|/* the x-projection of m1 in msec */
name|u_int
name|rtsc_m2
decl_stmt|;
comment|/* slope of the 2nd segment in bps */
comment|/* link-sharing service curve */
name|u_int
name|lssc_m1
decl_stmt|;
name|u_int
name|lssc_d
decl_stmt|;
name|u_int
name|lssc_m2
decl_stmt|;
comment|/* upper-limit service curve */
name|u_int
name|ulsc_m1
decl_stmt|;
name|u_int
name|ulsc_d
decl_stmt|;
name|u_int
name|ulsc_m2
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_altq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|void
modifier|*
name|altq_disc
decl_stmt|;
comment|/* discipline-specific state */
name|TAILQ_ENTRY
argument_list|(
argument|pf_altq
argument_list|)
name|entries
expr_stmt|;
comment|/* scheduler spec */
name|u_int8_t
name|scheduler
decl_stmt|;
comment|/* scheduler type */
name|u_int16_t
name|tbrsize
decl_stmt|;
comment|/* tokenbucket regulator size */
name|u_int32_t
name|ifbandwidth
decl_stmt|;
comment|/* interface bandwidth */
comment|/* queue spec */
name|char
name|qname
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
comment|/* queue name */
name|char
name|parent
index|[
name|PF_QNAME_SIZE
index|]
decl_stmt|;
comment|/* parent name */
name|u_int32_t
name|parent_qid
decl_stmt|;
comment|/* parent queue id */
name|u_int32_t
name|bandwidth
decl_stmt|;
comment|/* queue bandwidth */
name|u_int8_t
name|priority
decl_stmt|;
comment|/* priority */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|u_int8_t
name|local_flags
decl_stmt|;
comment|/* dynamic interface */
define|#
directive|define
name|PFALTQ_FLAG_IF_REMOVED
value|0x01
endif|#
directive|endif
name|u_int16_t
name|qlimit
decl_stmt|;
comment|/* queue size limit */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* misc flags */
union|union
block|{
name|struct
name|cbq_opts
name|cbq_opts
decl_stmt|;
name|struct
name|priq_opts
name|priq_opts
decl_stmt|;
name|struct
name|hfsc_opts
name|hfsc_opts
decl_stmt|;
block|}
name|pq_u
union|;
name|u_int32_t
name|qid
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_define
define|#
directive|define
name|PF_TAG_GENERATED
value|0x01
end_define

begin_define
define|#
directive|define
name|PF_TAG_FRAGCACHE
value|0x02
end_define

begin_define
define|#
directive|define
name|PF_TAG_TRANSLATE_LOCALHOST
value|0x04
end_define

begin_struct
struct|struct
name|pf_mtag
block|{
name|void
modifier|*
name|hdr
decl_stmt|;
comment|/* saved hdr pos in mbuf, for ECN */
name|u_int
name|rtableid
decl_stmt|;
comment|/* alternate routing table id */
name|u_int32_t
name|qid
decl_stmt|;
comment|/* queue id */
name|u_int16_t
name|tag
decl_stmt|;
comment|/* tag id */
name|u_int8_t
name|flags
decl_stmt|;
name|u_int8_t
name|routed
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
comment|/* for ECN */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pf_tag
block|{
name|u_int16_t
name|tag
decl_stmt|;
comment|/* tag id */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_tagname
block|{
name|TAILQ_ENTRY
argument_list|(
argument|pf_tagname
argument_list|)
name|entries
expr_stmt|;
name|char
name|name
index|[
name|PF_TAG_NAME_SIZE
index|]
decl_stmt|;
name|u_int16_t
name|tag
decl_stmt|;
name|int
name|ref
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFFRAG_FRENT_HIWAT
value|5000
end_define

begin_comment
comment|/* Number of fragment entries */
end_comment

begin_define
define|#
directive|define
name|PFFRAG_FRAG_HIWAT
value|1000
end_define

begin_comment
comment|/* Number of fragmented packets */
end_comment

begin_define
define|#
directive|define
name|PFFRAG_FRCENT_HIWAT
value|50000
end_define

begin_comment
comment|/* Number of fragment cache entries */
end_comment

begin_define
define|#
directive|define
name|PFFRAG_FRCACHE_HIWAT
value|10000
end_define

begin_comment
comment|/* Number of fragment descriptors */
end_comment

begin_define
define|#
directive|define
name|PFR_KTABLE_HIWAT
value|1000
end_define

begin_comment
comment|/* Number of tables */
end_comment

begin_define
define|#
directive|define
name|PFR_KENTRY_HIWAT
value|200000
end_define

begin_comment
comment|/* Number of table entries */
end_comment

begin_define
define|#
directive|define
name|PFR_KENTRY_HIWAT_SMALL
value|100000
end_define

begin_comment
comment|/* Number of table entries (tiny hosts) */
end_comment

begin_comment
comment|/*  * ioctl parameter structures  */
end_comment

begin_struct
struct|struct
name|pfioc_pooladdr
block|{
name|u_int32_t
name|action
decl_stmt|;
name|u_int32_t
name|ticket
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
name|u_int32_t
name|r_num
decl_stmt|;
name|u_int8_t
name|r_action
decl_stmt|;
name|u_int8_t
name|r_last
decl_stmt|;
name|u_int8_t
name|af
decl_stmt|;
name|char
name|anchor
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|struct
name|pf_pooladdr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_rule
block|{
name|u_int32_t
name|action
decl_stmt|;
name|u_int32_t
name|ticket
decl_stmt|;
name|u_int32_t
name|pool_ticket
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
name|char
name|anchor
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|anchor_call
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|struct
name|pf_rule
name|rule
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_natlook
block|{
name|struct
name|pf_addr
name|saddr
decl_stmt|;
name|struct
name|pf_addr
name|daddr
decl_stmt|;
name|struct
name|pf_addr
name|rsaddr
decl_stmt|;
name|struct
name|pf_addr
name|rdaddr
decl_stmt|;
name|u_int16_t
name|sport
decl_stmt|;
name|u_int16_t
name|dport
decl_stmt|;
name|u_int16_t
name|rsport
decl_stmt|;
name|u_int16_t
name|rdport
decl_stmt|;
name|sa_family_t
name|af
decl_stmt|;
name|u_int8_t
name|proto
decl_stmt|;
name|u_int8_t
name|direction
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_state
block|{
name|u_int32_t
name|nr
decl_stmt|;
name|struct
name|pf_state
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_src_node_kill
block|{
comment|/* XXX returns the number of src nodes killed in psnk_af */
name|sa_family_t
name|psnk_af
decl_stmt|;
name|struct
name|pf_rule_addr
name|psnk_src
decl_stmt|;
name|struct
name|pf_rule_addr
name|psnk_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_state_kill
block|{
comment|/* XXX returns the number of states killed in psk_af */
name|sa_family_t
name|psk_af
decl_stmt|;
name|int
name|psk_proto
decl_stmt|;
name|struct
name|pf_rule_addr
name|psk_src
decl_stmt|;
name|struct
name|pf_rule_addr
name|psk_dst
decl_stmt|;
name|char
name|psk_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_states
block|{
name|int
name|ps_len
decl_stmt|;
union|union
block|{
name|caddr_t
name|psu_buf
decl_stmt|;
name|struct
name|pf_state
modifier|*
name|psu_states
decl_stmt|;
block|}
name|ps_u
union|;
define|#
directive|define
name|ps_buf
value|ps_u.psu_buf
define|#
directive|define
name|ps_states
value|ps_u.psu_states
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_src_nodes
block|{
name|int
name|psn_len
decl_stmt|;
union|union
block|{
name|caddr_t
name|psu_buf
decl_stmt|;
name|struct
name|pf_src_node
modifier|*
name|psu_src_nodes
decl_stmt|;
block|}
name|psn_u
union|;
define|#
directive|define
name|psn_buf
value|psn_u.psu_buf
define|#
directive|define
name|psn_src_nodes
value|psn_u.psu_src_nodes
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_if
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_tm
block|{
name|int
name|timeout
decl_stmt|;
name|int
name|seconds
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_limit
block|{
name|int
name|index
decl_stmt|;
name|unsigned
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_altq
block|{
name|u_int32_t
name|action
decl_stmt|;
name|u_int32_t
name|ticket
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
name|struct
name|pf_altq
name|altq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_qstats
block|{
name|u_int32_t
name|ticket
decl_stmt|;
name|u_int32_t
name|nr
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|nbytes
decl_stmt|;
name|u_int8_t
name|scheduler
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pfioc_ruleset
block|{
name|u_int32_t
name|nr
decl_stmt|;
name|char
name|path
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|name
index|[
name|PF_ANCHOR_NAME_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PF_RULESET_ALTQ
value|(PF_RULESET_MAX)
end_define

begin_define
define|#
directive|define
name|PF_RULESET_TABLE
value|(PF_RULESET_MAX+1)
end_define

begin_struct
struct|struct
name|pfioc_trans
block|{
name|int
name|size
decl_stmt|;
comment|/* number of elements */
name|int
name|esize
decl_stmt|;
comment|/* size of each element in bytes */
struct|struct
name|pfioc_trans_e
block|{
name|int
name|rs_num
decl_stmt|;
name|char
name|anchor
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|u_int32_t
name|ticket
decl_stmt|;
block|}
modifier|*
name|array
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFR_FLAG_ATOMIC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_DUMMY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_FEEDBACK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_CLSTATS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_ADDRSTOO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_REPLACE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_ALLRSETS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PFR_FLAG_ALLMASK
value|0x0000007F
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|PFR_FLAG_USERIOCTL
value|0x10000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pfioc_table
block|{
name|struct
name|pfr_table
name|pfrio_table
decl_stmt|;
name|void
modifier|*
name|pfrio_buffer
decl_stmt|;
name|int
name|pfrio_esize
decl_stmt|;
name|int
name|pfrio_size
decl_stmt|;
name|int
name|pfrio_size2
decl_stmt|;
name|int
name|pfrio_nadd
decl_stmt|;
name|int
name|pfrio_ndel
decl_stmt|;
name|int
name|pfrio_nchange
decl_stmt|;
name|int
name|pfrio_flags
decl_stmt|;
name|u_int32_t
name|pfrio_ticket
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pfrio_exists
value|pfrio_nadd
end_define

begin_define
define|#
directive|define
name|pfrio_nzero
value|pfrio_nadd
end_define

begin_define
define|#
directive|define
name|pfrio_nmatch
value|pfrio_nadd
end_define

begin_define
define|#
directive|define
name|pfrio_naddr
value|pfrio_size2
end_define

begin_define
define|#
directive|define
name|pfrio_setflag
value|pfrio_size2
end_define

begin_define
define|#
directive|define
name|pfrio_clrflag
value|pfrio_nadd
end_define

begin_struct
struct|struct
name|pfioc_iface
block|{
name|char
name|pfiio_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|void
modifier|*
name|pfiio_buffer
decl_stmt|;
name|int
name|pfiio_esize
decl_stmt|;
name|int
name|pfiio_size
decl_stmt|;
name|int
name|pfiio_nzero
decl_stmt|;
name|int
name|pfiio_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ioctl operations  */
end_comment

begin_define
define|#
directive|define
name|DIOCSTART
value|_IO  ('D',  1)
end_define

begin_define
define|#
directive|define
name|DIOCSTOP
value|_IO  ('D',  2)
end_define

begin_define
define|#
directive|define
name|DIOCADDRULE
value|_IOWR('D',  4, struct pfioc_rule)
end_define

begin_define
define|#
directive|define
name|DIOCGETRULES
value|_IOWR('D',  6, struct pfioc_rule)
end_define

begin_define
define|#
directive|define
name|DIOCGETRULE
value|_IOWR('D',  7, struct pfioc_rule)
end_define

begin_comment
comment|/* XXX cut 8 - 17 */
end_comment

begin_define
define|#
directive|define
name|DIOCCLRSTATES
value|_IOWR('D', 18, struct pfioc_state_kill)
end_define

begin_define
define|#
directive|define
name|DIOCGETSTATE
value|_IOWR('D', 19, struct pfioc_state)
end_define

begin_define
define|#
directive|define
name|DIOCSETSTATUSIF
value|_IOWR('D', 20, struct pfioc_if)
end_define

begin_define
define|#
directive|define
name|DIOCGETSTATUS
value|_IOWR('D', 21, struct pf_status)
end_define

begin_define
define|#
directive|define
name|DIOCCLRSTATUS
value|_IO  ('D', 22)
end_define

begin_define
define|#
directive|define
name|DIOCNATLOOK
value|_IOWR('D', 23, struct pfioc_natlook)
end_define

begin_define
define|#
directive|define
name|DIOCSETDEBUG
value|_IOWR('D', 24, u_int32_t)
end_define

begin_define
define|#
directive|define
name|DIOCGETSTATES
value|_IOWR('D', 25, struct pfioc_states)
end_define

begin_define
define|#
directive|define
name|DIOCCHANGERULE
value|_IOWR('D', 26, struct pfioc_rule)
end_define

begin_comment
comment|/* XXX cut 26 - 28 */
end_comment

begin_define
define|#
directive|define
name|DIOCSETTIMEOUT
value|_IOWR('D', 29, struct pfioc_tm)
end_define

begin_define
define|#
directive|define
name|DIOCGETTIMEOUT
value|_IOWR('D', 30, struct pfioc_tm)
end_define

begin_define
define|#
directive|define
name|DIOCADDSTATE
value|_IOWR('D', 37, struct pfioc_state)
end_define

begin_define
define|#
directive|define
name|DIOCCLRRULECTRS
value|_IO  ('D', 38)
end_define

begin_define
define|#
directive|define
name|DIOCGETLIMIT
value|_IOWR('D', 39, struct pfioc_limit)
end_define

begin_define
define|#
directive|define
name|DIOCSETLIMIT
value|_IOWR('D', 40, struct pfioc_limit)
end_define

begin_define
define|#
directive|define
name|DIOCKILLSTATES
value|_IOWR('D', 41, struct pfioc_state_kill)
end_define

begin_define
define|#
directive|define
name|DIOCSTARTALTQ
value|_IO  ('D', 42)
end_define

begin_define
define|#
directive|define
name|DIOCSTOPALTQ
value|_IO  ('D', 43)
end_define

begin_define
define|#
directive|define
name|DIOCADDALTQ
value|_IOWR('D', 45, struct pfioc_altq)
end_define

begin_define
define|#
directive|define
name|DIOCGETALTQS
value|_IOWR('D', 47, struct pfioc_altq)
end_define

begin_define
define|#
directive|define
name|DIOCGETALTQ
value|_IOWR('D', 48, struct pfioc_altq)
end_define

begin_define
define|#
directive|define
name|DIOCCHANGEALTQ
value|_IOWR('D', 49, struct pfioc_altq)
end_define

begin_define
define|#
directive|define
name|DIOCGETQSTATS
value|_IOWR('D', 50, struct pfioc_qstats)
end_define

begin_define
define|#
directive|define
name|DIOCBEGINADDRS
value|_IOWR('D', 51, struct pfioc_pooladdr)
end_define

begin_define
define|#
directive|define
name|DIOCADDADDR
value|_IOWR('D', 52, struct pfioc_pooladdr)
end_define

begin_define
define|#
directive|define
name|DIOCGETADDRS
value|_IOWR('D', 53, struct pfioc_pooladdr)
end_define

begin_define
define|#
directive|define
name|DIOCGETADDR
value|_IOWR('D', 54, struct pfioc_pooladdr)
end_define

begin_define
define|#
directive|define
name|DIOCCHANGEADDR
value|_IOWR('D', 55, struct pfioc_pooladdr)
end_define

begin_comment
comment|/* XXX cut 55 - 57 */
end_comment

begin_define
define|#
directive|define
name|DIOCGETRULESETS
value|_IOWR('D', 58, struct pfioc_ruleset)
end_define

begin_define
define|#
directive|define
name|DIOCGETRULESET
value|_IOWR('D', 59, struct pfioc_ruleset)
end_define

begin_define
define|#
directive|define
name|DIOCRCLRTABLES
value|_IOWR('D', 60, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRADDTABLES
value|_IOWR('D', 61, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRDELTABLES
value|_IOWR('D', 62, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRGETTABLES
value|_IOWR('D', 63, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRGETTSTATS
value|_IOWR('D', 64, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRCLRTSTATS
value|_IOWR('D', 65, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRCLRADDRS
value|_IOWR('D', 66, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRADDADDRS
value|_IOWR('D', 67, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRDELADDRS
value|_IOWR('D', 68, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRSETADDRS
value|_IOWR('D', 69, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRGETADDRS
value|_IOWR('D', 70, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRGETASTATS
value|_IOWR('D', 71, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRCLRASTATS
value|_IOWR('D', 72, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRTSTADDRS
value|_IOWR('D', 73, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRSETTFLAGS
value|_IOWR('D', 74, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCRINADEFINE
value|_IOWR('D', 77, struct pfioc_table)
end_define

begin_define
define|#
directive|define
name|DIOCOSFPFLUSH
value|_IO('D', 78)
end_define

begin_define
define|#
directive|define
name|DIOCOSFPADD
value|_IOWR('D', 79, struct pf_osfp_ioctl)
end_define

begin_define
define|#
directive|define
name|DIOCOSFPGET
value|_IOWR('D', 80, struct pf_osfp_ioctl)
end_define

begin_define
define|#
directive|define
name|DIOCXBEGIN
value|_IOWR('D', 81, struct pfioc_trans)
end_define

begin_define
define|#
directive|define
name|DIOCXCOMMIT
value|_IOWR('D', 82, struct pfioc_trans)
end_define

begin_define
define|#
directive|define
name|DIOCXROLLBACK
value|_IOWR('D', 83, struct pfioc_trans)
end_define

begin_define
define|#
directive|define
name|DIOCGETSRCNODES
value|_IOWR('D', 84, struct pfioc_src_nodes)
end_define

begin_define
define|#
directive|define
name|DIOCCLRSRCNODES
value|_IO('D', 85)
end_define

begin_define
define|#
directive|define
name|DIOCSETHOSTID
value|_IOWR('D', 86, u_int32_t)
end_define

begin_define
define|#
directive|define
name|DIOCIGETIFACES
value|_IOWR('D', 87, struct pfioc_iface)
end_define

begin_define
define|#
directive|define
name|DIOCSETIFFLAG
value|_IOWR('D', 89, struct pfioc_iface)
end_define

begin_define
define|#
directive|define
name|DIOCCLRIFFLAG
value|_IOWR('D', 90, struct pfioc_iface)
end_define

begin_define
define|#
directive|define
name|DIOCKILLSRCNODES
value|_IOWR('D', 91, struct pfioc_src_node_kill)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_struct
struct|struct
name|pf_ifspeed
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_int32_t
name|baudrate
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DIOCGIFSPEED
value|_IOWR('D', 92, struct pf_ifspeed)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_src_tree
argument_list|,
name|pf_src_node
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_src_tree
argument_list|,
name|pf_src_node
argument_list|,
name|entry
argument_list|,
name|pf_src_compare
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_src_tree
name|tree_src_tracking
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|pf_state_tree_id
argument_list|,
name|pf_state
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|pf_state_tree_id
argument_list|,
name|pf_state
argument_list|,
name|entry_id
argument_list|,
name|pf_state_compare_id
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_state_tree_id
name|tree_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_state_queue
name|state_list
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pf_poolqueue
argument_list|,
name|pf_pool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_poolqueue
name|pf_pools
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|pf_altqqueue
argument_list|,
name|pf_altq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_altqqueue
name|pf_altqs
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_palist
name|pf_pabuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ticket_altqs_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ticket_altqs_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|altqs_inactive_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|ticket_pabuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_altqqueue
modifier|*
name|pf_altqs_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_altqqueue
modifier|*
name|pf_altqs_inactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_poolqueue
modifier|*
name|pf_pools_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_poolqueue
modifier|*
name|pf_pools_inactive
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|pf_tbladdr_setup
parameter_list|(
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_tbladdr_remove
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_tbladdr_copyout
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_calc_skip_steps
parameter_list|(
name|struct
name|pf_rulequeue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|pf_altq_ifnet_event
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pf_src_tree_pl
decl_stmt|,
name|pf_rule_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pf_state_pl
decl_stmt|,
name|pf_altq_pl
decl_stmt|,
name|pf_pooladdr_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pfr_ktable_pl
decl_stmt|,
name|pfr_kentry_pl
decl_stmt|,
name|pfr_kentry_pl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pf_cache_pl
decl_stmt|,
name|pf_cent_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pf_state_scrub_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pfi_addr_pl
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|pf_src_tree_pl
decl_stmt|,
name|pf_rule_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|pf_state_pl
decl_stmt|,
name|pf_altq_pl
decl_stmt|,
name|pf_pooladdr_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|pf_state_scrub_pl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|pf_purge_thread
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
specifier|extern
name|int
name|pf_purge_expired_src_nodes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pf_purge_expired_states
parameter_list|(
name|u_int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|pf_purge_expired_src_nodes
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_purge_expired_states
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|pf_unlink_state
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_free_state
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pf_insert_state
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pf_insert_src_node
parameter_list|(
name|struct
name|pf_src_node
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_src_tree_remove_state
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pf_state
modifier|*
name|pf_find_state_byid
parameter_list|(
name|struct
name|pf_state_cmp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|pf_state
modifier|*
name|pf_find_state_all
parameter_list|(
name|struct
name|pf_state_cmp
modifier|*
name|key
parameter_list|,
name|u_int8_t
name|tree
parameter_list|,
name|int
modifier|*
name|more
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_print_state
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pf_print_flags
parameter_list|(
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
name|pf_cksum_fixup
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ifnet
modifier|*
name|sync_ifp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_rule
name|pf_default_rule
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pf_addrcpy
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_rm_rule
parameter_list|(
name|struct
name|pf_rulequeue
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|pf_test
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|pf_test
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|pf_test6
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|pf_test6
parameter_list|(
name|int
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|ether_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|pf_poolmask
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_addr_inc
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|u_int32_t
name|pf_new_isn
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|pf_pull_hdr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_change_a
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int16_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pflog_packet
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|u_int8_t
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match_addr
parameter_list|(
name|u_int8_t
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match
parameter_list|(
name|u_int8_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match_port
parameter_list|(
name|u_int8_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match_uid
parameter_list|(
name|u_int8_t
parameter_list|,
name|uid_t
parameter_list|,
name|uid_t
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_match_gid
parameter_list|(
name|u_int8_t
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_normalize_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_normalize_ip
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_normalize_ip6
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_normalize_tcp
parameter_list|(
name|int
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_normalize_tcp_cleanup
parameter_list|(
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_normalize_tcp_init
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|pf_state_peer
modifier|*
parameter_list|,
name|struct
name|pf_state_peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_normalize_tcp_stateful
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|tcphdr
modifier|*
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|,
name|struct
name|pf_state_peer
modifier|*
parameter_list|,
name|struct
name|pf_state_peer
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|pf_state_expires
parameter_list|(
specifier|const
name|struct
name|pf_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_purge_expired_fragments
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_routable
parameter_list|(
name|struct
name|pf_addr
modifier|*
name|addr
parameter_list|,
name|sa_family_t
name|af
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_rtlabel_match
parameter_list|(
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|,
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|pf_socket_lookup
parameter_list|(
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|inpcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|pf_socket_lookup
parameter_list|(
name|int
parameter_list|,
name|struct
name|pf_pdesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|pfr_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_match_addr
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfr_update_stats
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_pool_get
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfr_dynaddr_update
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|,
name|struct
name|pfi_dynaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pfr_ktable
modifier|*
name|pfr_attach_table
parameter_list|(
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfr_detach_table
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_clr_tables
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_add_tables
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_del_tables
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_get_tables
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_get_tstats
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_tstats
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_clr_tstats
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_set_tflags
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_clr_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_insert_kentry
parameter_list|(
name|struct
name|pfr_ktable
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_add_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_del_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_set_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_get_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_get_astats
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_astats
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_clr_astats
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_tst_addrs
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_ina_begin
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_ina_rollback
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_ina_commit
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfr_ina_define
parameter_list|(
name|struct
name|pfr_table
modifier|*
parameter_list|,
name|struct
name|pfr_addr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pfi_statehead
name|pfi_statehead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pfi_kif
modifier|*
name|pfi_all
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pfi_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|void
name|pfi_cleanup
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
name|struct
name|pfi_kif
modifier|*
name|pfi_kif_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_kif_ref
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|enum
name|pfi_kif_refs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_kif_unref
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|enum
name|pfi_kif_refs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_kif_match
parameter_list|(
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_attach_ifnet
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_detach_ifnet
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_attach_ifgroup
parameter_list|(
name|struct
name|ifg_group
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_detach_ifgroup
parameter_list|(
name|struct
name|ifg_group
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_group_change
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_match_addr
parameter_list|(
name|struct
name|pfi_dynaddr
modifier|*
parameter_list|,
name|struct
name|pf_addr
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_dynaddr_setup
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|,
name|sa_family_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_dynaddr_remove
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_dynaddr_copyout
parameter_list|(
name|struct
name|pf_addr_wrap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfi_fill_oldstatus
parameter_list|(
name|struct
name|pf_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_clr_istats
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_get_ifaces
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|pfi_kif
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_set_flags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfi_clear_flags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|pf_tagname2tag
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_tag2tagname
parameter_list|(
name|u_int16_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_tag_ref
parameter_list|(
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_tag_unref
parameter_list|(
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_tag_packet
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|pf_mtag
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|pf_qname2qid
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_qid2qname
parameter_list|(
name|u_int32_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_qid_unref
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_function_decl
name|struct
name|pf_mtag
modifier|*
name|pf_find_mtag
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_mtag
modifier|*
name|pf_get_mtag
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|pf_status
name|pf_status
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_decl_stmt
specifier|extern
name|uma_zone_t
name|pf_frent_pl
decl_stmt|,
name|pf_frag_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|pf_consistency_lock
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|pool
name|pf_frent_pl
decl_stmt|,
name|pf_frag_pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|pf_consistency_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pf_pool_limit
block|{
name|void
modifier|*
name|pp
decl_stmt|;
name|unsigned
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pf_pool_limit
name|pf_pool_limits
index|[
name|PF_LIMIT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_struct
struct|struct
name|pf_frent
block|{
name|LIST_ENTRY
argument_list|(
argument|pf_frent
argument_list|)
name|fr_next
expr_stmt|;
name|struct
name|ip
modifier|*
name|fr_ip
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|fr_m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_frcache
block|{
name|LIST_ENTRY
argument_list|(
argument|pf_frcache
argument_list|)
name|fr_next
expr_stmt|;
name|uint16_t
name|fr_off
decl_stmt|;
name|uint16_t
name|fr_end
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pf_fragment
block|{
name|RB_ENTRY
argument_list|(
argument|pf_fragment
argument_list|)
name|fr_entry
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|pf_fragment
argument_list|)
name|frag_next
expr_stmt|;
name|struct
name|in_addr
name|fr_src
decl_stmt|;
name|struct
name|in_addr
name|fr_dst
decl_stmt|;
name|u_int8_t
name|fr_p
decl_stmt|;
comment|/* protocol of this fragment */
name|u_int8_t
name|fr_flags
decl_stmt|;
comment|/* status flags */
name|u_int16_t
name|fr_id
decl_stmt|;
comment|/* fragment id for reassemble */
name|u_int16_t
name|fr_max
decl_stmt|;
comment|/* fragment data max */
name|u_int32_t
name|fr_timeout
decl_stmt|;
define|#
directive|define
name|fr_queue
value|fr_u.fru_queue
define|#
directive|define
name|fr_cache
value|fr_u.fru_cache
union|union
block|{
name|LIST_HEAD
argument_list|(
argument|pf_fragq
argument_list|,
argument|pf_frent
argument_list|)
name|fru_queue
expr_stmt|;
comment|/* buffering */
name|LIST_HEAD
argument_list|(
argument|pf_cacheq
argument_list|,
argument|pf_frcache
argument_list|)
name|fru_cache
expr_stmt|;
comment|/* non-buf */
block|}
name|fr_u
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (__FreeBSD__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pf_anchor_global
name|pf_anchors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pf_anchor
name|pf_main_anchor
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pf_main_ruleset
value|pf_main_anchor.ruleset
end_define

begin_comment
comment|/* these ruleset functions can be linked into userland programs (pfctl) */
end_comment

begin_function_decl
name|int
name|pf_get_ruleset_number
parameter_list|(
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_init_ruleset
parameter_list|(
name|struct
name|pf_ruleset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_anchor_setup
parameter_list|(
name|struct
name|pf_rule
modifier|*
parameter_list|,
specifier|const
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_anchor_copyout
parameter_list|(
specifier|const
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
specifier|const
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pfioc_rule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_anchor_remove
parameter_list|(
name|struct
name|pf_rule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_remove_if_empty_ruleset
parameter_list|(
name|struct
name|pf_ruleset
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_anchor
modifier|*
name|pf_find_anchor
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_ruleset
modifier|*
name|pf_find_ruleset
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_ruleset
modifier|*
name|pf_find_or_create_ruleset
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_rs_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_comment
comment|/* ?!? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|pf_anchor_copyout
parameter_list|(
specifier|const
name|struct
name|pf_ruleset
modifier|*
parameter_list|,
specifier|const
name|struct
name|pf_rule
modifier|*
parameter_list|,
name|struct
name|pfioc_rule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_anchor_remove
parameter_list|(
name|struct
name|pf_rule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* The fingerprint functions can be linked into userland programs (tcpdump) */
end_comment

begin_function_decl
name|int
name|pf_osfp_add
parameter_list|(
name|struct
name|pf_osfp_ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|struct
name|pf_osfp_enlist
modifier|*
name|pf_osfp_fingerprint
parameter_list|(
name|struct
name|pf_pdesc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|struct
name|pf_osfp_enlist
modifier|*
name|pf_osfp_fingerprint_hdr
parameter_list|(
specifier|const
name|struct
name|ip
modifier|*
parameter_list|,
specifier|const
name|struct
name|ip6_hdr
modifier|*
parameter_list|,
specifier|const
name|struct
name|tcphdr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_osfp_flush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_osfp_get
parameter_list|(
name|struct
name|pf_osfp_ioctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|pf_osfp_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pf_osfp_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|pf_osfp_initialize
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
name|int
name|pf_osfp_match
parameter_list|(
name|struct
name|pf_osfp_enlist
modifier|*
parameter_list|,
name|pf_osfp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pf_os_fingerprint
modifier|*
name|pf_osfp_validate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PFVAR_H_ */
end_comment

end_unit

