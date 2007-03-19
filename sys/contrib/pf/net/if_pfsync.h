begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: if_pfsync.h,v 1.19 2005/01/20 17:47:38 mcbride Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Michael Shalayeff  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_PFSYNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_PFSYNC_H_
end_define

begin_define
define|#
directive|define
name|PFSYNC_ID_LEN
value|sizeof(u_int64_t)
end_define

begin_struct
struct|struct
name|pfsync_state_scrub
block|{
name|u_int16_t
name|pfss_flags
decl_stmt|;
name|u_int8_t
name|pfss_ttl
decl_stmt|;
comment|/* stashed TTL		*/
name|u_int8_t
name|scrub_flag
decl_stmt|;
name|u_int32_t
name|pfss_ts_mod
decl_stmt|;
comment|/* timestamp modulation	*/
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_host
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
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_peer
block|{
name|struct
name|pfsync_state_scrub
name|scrub
decl_stmt|;
comment|/* state is scrubbed	*/
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
name|u_int16_t
name|mss
decl_stmt|;
comment|/* Maximum segment size option	*/
name|u_int8_t
name|state
decl_stmt|;
comment|/* active state level		*/
name|u_int8_t
name|wscale
decl_stmt|;
comment|/* window scaling factor	*/
name|u_int8_t
name|scrub_flag
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state
block|{
name|u_int32_t
name|id
index|[
literal|2
index|]
decl_stmt|;
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|pfsync_state_host
name|lan
decl_stmt|;
name|struct
name|pfsync_state_host
name|gwy
decl_stmt|;
name|struct
name|pfsync_state_host
name|ext
decl_stmt|;
name|struct
name|pfsync_state_peer
name|src
decl_stmt|;
name|struct
name|pfsync_state_peer
name|dst
decl_stmt|;
name|struct
name|pf_addr
name|rt_addr
decl_stmt|;
name|u_int32_t
name|rule
decl_stmt|;
name|u_int32_t
name|anchor
decl_stmt|;
name|u_int32_t
name|nat_rule
decl_stmt|;
name|u_int32_t
name|creation
decl_stmt|;
name|u_int32_t
name|expire
decl_stmt|;
name|u_int32_t
name|packets
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|bytes
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|creatorid
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
name|log
decl_stmt|;
name|u_int8_t
name|allow_opts
decl_stmt|;
name|u_int8_t
name|timeout
decl_stmt|;
name|u_int8_t
name|sync_flags
decl_stmt|;
name|u_int8_t
name|updates
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSYNC_FLAG_COMPRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|PFSYNC_FLAG_STALE
value|0x02
end_define

begin_struct
struct|struct
name|pfsync_state_upd
block|{
name|u_int32_t
name|id
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|pfsync_state_peer
name|src
decl_stmt|;
name|struct
name|pfsync_state_peer
name|dst
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|expire
decl_stmt|;
name|u_int8_t
name|timeout
decl_stmt|;
name|u_int8_t
name|updates
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_del
block|{
name|u_int32_t
name|id
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|state
decl_stmt|;
block|}
name|src
struct|;
struct|struct
block|{
name|u_int8_t
name|state
decl_stmt|;
block|}
name|dst
struct|;
name|u_int8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_upd_req
block|{
name|u_int32_t
name|id
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|pad
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_clr
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|pad
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|pfsync_state_bus
block|{
name|u_int32_t
name|creatorid
decl_stmt|;
name|u_int32_t
name|endtime
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
define|#
directive|define
name|PFSYNC_BUS_START
value|1
define|#
directive|define
name|PFSYNC_BUS_END
value|2
name|u_int8_t
name|pad
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_union
union|union
name|sc_statep
block|{
name|struct
name|pfsync_state
modifier|*
name|s
decl_stmt|;
name|struct
name|pfsync_state_upd
modifier|*
name|u
decl_stmt|;
name|struct
name|pfsync_state_del
modifier|*
name|d
decl_stmt|;
name|struct
name|pfsync_state_clr
modifier|*
name|c
decl_stmt|;
name|struct
name|pfsync_state_bus
modifier|*
name|b
decl_stmt|;
name|struct
name|pfsync_state_upd_req
modifier|*
name|r
decl_stmt|;
block|}
union|;
end_union

begin_decl_stmt
specifier|extern
name|int
name|pfsync_sync_ok
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|pfsync_softc
block|{
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
else|#
directive|else
name|struct
name|ifnet
name|sc_if
decl_stmt|;
endif|#
directive|endif
name|struct
name|ifnet
modifier|*
name|sc_sync_ifp
decl_stmt|;
name|struct
name|ip_moptions
name|sc_imo
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|callout
name|sc_tmo
decl_stmt|;
name|struct
name|callout
name|sc_bulk_tmo
decl_stmt|;
name|struct
name|callout
name|sc_bulkfail_tmo
decl_stmt|;
else|#
directive|else
name|struct
name|timeout
name|sc_tmo
decl_stmt|;
name|struct
name|timeout
name|sc_bulk_tmo
decl_stmt|;
name|struct
name|timeout
name|sc_bulkfail_tmo
decl_stmt|;
endif|#
directive|endif
name|struct
name|in_addr
name|sc_sync_peer
decl_stmt|;
name|struct
name|in_addr
name|sc_sendaddr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|sc_mbuf
decl_stmt|;
comment|/* current cumulative mbuf */
name|struct
name|mbuf
modifier|*
name|sc_mbuf_net
decl_stmt|;
comment|/* current cumulative mbuf */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|ifqueue
name|sc_ifq
decl_stmt|;
name|struct
name|callout
name|sc_send_tmo
decl_stmt|;
endif|#
directive|endif
name|union
name|sc_statep
name|sc_statep
decl_stmt|;
name|union
name|sc_statep
name|sc_statep_net
decl_stmt|;
name|u_int32_t
name|sc_ureq_received
decl_stmt|;
name|u_int32_t
name|sc_ureq_sent
decl_stmt|;
name|int
name|sc_bulk_tries
decl_stmt|;
name|int
name|sc_maxcount
decl_stmt|;
comment|/* number of states in mtu */
name|int
name|sc_maxupdates
decl_stmt|;
comment|/* number of updates/state */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|LIST_ENTRY
argument_list|(
argument|pfsync_softc
argument_list|)
name|sc_next
expr_stmt|;
name|eventhandler_tag
name|sc_detachtag
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pfsync_header
block|{
name|u_int8_t
name|version
decl_stmt|;
define|#
directive|define
name|PFSYNC_VERSION
value|2
name|u_int8_t
name|af
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
define|#
directive|define
name|PFSYNC_ACT_CLR
value|0
comment|/* clear all states */
define|#
directive|define
name|PFSYNC_ACT_INS
value|1
comment|/* insert state */
define|#
directive|define
name|PFSYNC_ACT_UPD
value|2
comment|/* update state */
define|#
directive|define
name|PFSYNC_ACT_DEL
value|3
comment|/* delete state */
define|#
directive|define
name|PFSYNC_ACT_UPD_C
value|4
comment|/* "compressed" state update */
define|#
directive|define
name|PFSYNC_ACT_DEL_C
value|5
comment|/* "compressed" state delete */
define|#
directive|define
name|PFSYNC_ACT_INS_F
value|6
comment|/* insert fragment */
define|#
directive|define
name|PFSYNC_ACT_DEL_F
value|7
comment|/* delete fragments */
define|#
directive|define
name|PFSYNC_ACT_UREQ
value|8
comment|/* request "uncompressed" state */
define|#
directive|define
name|PFSYNC_ACT_BUS
value|9
comment|/* Bulk Update Status */
define|#
directive|define
name|PFSYNC_ACT_MAX
value|10
name|u_int8_t
name|count
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSYNC_BULKPACKETS
value|1
end_define

begin_comment
comment|/* # of packets per timeout */
end_comment

begin_define
define|#
directive|define
name|PFSYNC_MAX_BULKTRIES
value|12
end_define

begin_define
define|#
directive|define
name|PFSYNC_HDRLEN
value|sizeof(struct pfsync_header)
end_define

begin_define
define|#
directive|define
name|PFSYNC_ACTIONS
define|\
value|"CLR ST", "INS ST", "UPD ST", "DEL ST", \ 	"UPD ST COMP", "DEL ST COMP", "INS FR", "DEL FR", \ 	"UPD REQ", "BLK UPD STAT"
end_define

begin_define
define|#
directive|define
name|PFSYNC_DFLTTL
value|255
end_define

begin_struct
struct|struct
name|pfsyncstats
block|{
name|u_int64_t
name|pfsyncs_ipackets
decl_stmt|;
comment|/* total input packets, IPv4 */
name|u_int64_t
name|pfsyncs_ipackets6
decl_stmt|;
comment|/* total input packets, IPv6 */
name|u_int64_t
name|pfsyncs_badif
decl_stmt|;
comment|/* not the right interface */
name|u_int64_t
name|pfsyncs_badttl
decl_stmt|;
comment|/* TTL is not PFSYNC_DFLTTL */
name|u_int64_t
name|pfsyncs_hdrops
decl_stmt|;
comment|/* packets shorter than hdr */
name|u_int64_t
name|pfsyncs_badver
decl_stmt|;
comment|/* bad (incl unsupp) version */
name|u_int64_t
name|pfsyncs_badact
decl_stmt|;
comment|/* bad action */
name|u_int64_t
name|pfsyncs_badlen
decl_stmt|;
comment|/* data length does not match */
name|u_int64_t
name|pfsyncs_badauth
decl_stmt|;
comment|/* bad authentication */
name|u_int64_t
name|pfsyncs_stale
decl_stmt|;
comment|/* stale state */
name|u_int64_t
name|pfsyncs_badval
decl_stmt|;
comment|/* bad values */
name|u_int64_t
name|pfsyncs_badstate
decl_stmt|;
comment|/* insert/lookup failed */
name|u_int64_t
name|pfsyncs_opackets
decl_stmt|;
comment|/* total output packets, IPv4 */
name|u_int64_t
name|pfsyncs_opackets6
decl_stmt|;
comment|/* total output packets, IPv6 */
name|u_int64_t
name|pfsyncs_onomem
decl_stmt|;
comment|/* no memory for an mbuf */
name|u_int64_t
name|pfsyncs_oerrors
decl_stmt|;
comment|/* ip output error */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration structure for SIOCSETPFSYNC SIOCGETPFSYNC  */
end_comment

begin_struct
struct|struct
name|pfsyncreq
block|{
name|char
name|pfsyncr_syncdev
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|in_addr
name|pfsyncr_syncpeer
decl_stmt|;
name|int
name|pfsyncr_maxupdates
decl_stmt|;
name|int
name|pfsyncr_authlevel
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|SIOCSETPFSYNC
value|_IOW('i', 247, struct ifreq)
end_define

begin_define
define|#
directive|define
name|SIOCGETPFSYNC
value|_IOWR('i', 248, struct ifreq)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pf_state_peer_hton
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {		\ 	(d)->seqlo = htonl((s)->seqlo);		\ 	(d)->seqhi = htonl((s)->seqhi);		\ 	(d)->seqdiff = htonl((s)->seqdiff);	\ 	(d)->max_win = htons((s)->max_win);	\ 	(d)->mss = htons((s)->mss);		\ 	(d)->state = (s)->state;		\ 	(d)->wscale = (s)->wscale;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|pf_state_peer_ntoh
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {		\ 	(d)->seqlo = ntohl((s)->seqlo);		\ 	(d)->seqhi = ntohl((s)->seqhi);		\ 	(d)->seqdiff = ntohl((s)->seqdiff);	\ 	(d)->max_win = ntohs((s)->max_win);	\ 	(d)->mss = ntohs((s)->mss);		\ 	(d)->state = (s)->state;		\ 	(d)->wscale = (s)->wscale;		\ } while (0)
end_define

begin_define
define|#
directive|define
name|pf_state_host_hton
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {				\ 	bcopy(&(s)->addr,&(d)->addr, sizeof((d)->addr));	\ 	(d)->port = (s)->port;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|pf_state_host_ntoh
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|do {				\ 	bcopy(&(s)->addr,&(d)->addr, sizeof((d)->addr));	\ 	(d)->port = (s)->port;					\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|void
name|pfsync_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|__unused
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|pfsync_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pfsync_clear_states
parameter_list|(
name|u_int32_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfsync_pack_state
parameter_list|(
name|u_int8_t
parameter_list|,
name|struct
name|pf_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pfsync_insert_state
parameter_list|(
name|st
parameter_list|)
value|do {				\ 	if ((st->rule.ptr->rule_flag& PFRULE_NOSYNC) ||	\ 	    (st->proto == IPPROTO_PFSYNC))			\ 		st->sync_flags |= PFSTATE_NOSYNC;		\ 	else if (!st->sync_flags)				\ 		pfsync_pack_state(PFSYNC_ACT_INS, (st), 1);	\ 	st->sync_flags&= ~PFSTATE_FROMSYNC;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|pfsync_update_state
parameter_list|(
name|st
parameter_list|)
value|do {				\ 	if (!st->sync_flags)					\ 		pfsync_pack_state(PFSYNC_ACT_UPD, (st), 	\ 		    PFSYNC_FLAG_COMPRESS);			\ 	st->sync_flags&= ~PFSTATE_FROMSYNC;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|pfsync_delete_state
parameter_list|(
name|st
parameter_list|)
value|do {				\ 	if (!st->sync_flags)					\ 		pfsync_pack_state(PFSYNC_ACT_DEL, (st),		\ 		    PFSYNC_FLAG_COMPRESS);			\ 	st->sync_flags&= ~PFSTATE_FROMSYNC;			\ } while (0)
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
comment|/* _NET_IF_PFSYNC_H_ */
end_comment

end_unit

