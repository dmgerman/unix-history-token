begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ieee8023ad_impl.h,v 1.2 2005/12/10 23:21:39 elad Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c)2005 YAMAMOTO Takashi,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * IEEE802.3ad LACP  *  * implementation details.  */
end_comment

begin_define
define|#
directive|define
name|LACP_TIMER_CURRENT_WHILE
value|0
end_define

begin_define
define|#
directive|define
name|LACP_TIMER_PERIODIC
value|1
end_define

begin_define
define|#
directive|define
name|LACP_TIMER_WAIT_WHILE
value|2
end_define

begin_define
define|#
directive|define
name|LACP_NTIMER
value|3
end_define

begin_define
define|#
directive|define
name|LACP_TIMER_ARM
parameter_list|(
name|port
parameter_list|,
name|timer
parameter_list|,
name|val
parameter_list|)
define|\
value|(port)->lp_timer[(timer)] = (val)
end_define

begin_define
define|#
directive|define
name|LACP_TIMER_DISARM
parameter_list|(
name|port
parameter_list|,
name|timer
parameter_list|)
define|\
value|(port)->lp_timer[(timer)] = 0
end_define

begin_define
define|#
directive|define
name|LACP_TIMER_ISARMED
parameter_list|(
name|port
parameter_list|,
name|timer
parameter_list|)
define|\
value|((port)->lp_timer[(timer)]> 0)
end_define

begin_comment
comment|/*  * IEEE802.3ad LACP  *  * protocol definitions.  */
end_comment

begin_define
define|#
directive|define
name|LACP_STATE_ACTIVITY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_TIMEOUT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_AGGREGATION
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_SYNC
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_COLLECTING
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_DISTRIBUTING
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_DEFAULTED
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|LACP_STATE_EXPIRED
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|LACP_PORT_NTT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LACP_PORT_PROMISC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LACP_PORT_LADDRCHANGED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LACP_PORT_ATTACHED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LACP_PORT_LARVAL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LACP_PORT_DETACHING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LACP_STATE_BITS
define|\
value|"\020"			\ 	"\001ACTIVITY"		\ 	"\002TIMEOUT"		\ 	"\003AGGREGATION"	\ 	"\004SYNC"		\ 	"\005COLLECTING"	\ 	"\006DISTRIBUTING"	\ 	"\007DEFAULTED"		\ 	"\010EXPIRED"
end_define

begin_comment
comment|/*  * IEEE802.3 slow protocols  *  * protocol (on-wire) definitions.  *  * XXX should be elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|SLOWPROTOCOLS_SUBTYPE_LACP
value|1
end_define

begin_define
define|#
directive|define
name|SLOWPROTOCOLS_SUBTYPE_MARKER
value|2
end_define

begin_struct
struct|struct
name|slowprothdr
block|{
name|uint8_t
name|sph_subtype
decl_stmt|;
name|uint8_t
name|sph_version
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * TLV on-wire structure.  */
end_comment

begin_struct
struct|struct
name|tlvhdr
block|{
name|uint8_t
name|tlv_type
decl_stmt|;
name|uint8_t
name|tlv_length
decl_stmt|;
comment|/* uint8_t tlv_value[]; */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * ... and our implementation.  */
end_comment

begin_define
define|#
directive|define
name|TLV_SET
parameter_list|(
name|tlv
parameter_list|,
name|type
parameter_list|,
name|length
parameter_list|)
define|\
value|do { \ 		(tlv)->tlv_type = (type); \ 		(tlv)->tlv_length = sizeof(*tlv) + (length); \ 	} while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_struct
struct|struct
name|tlv_template
block|{
name|uint8_t
name|tmpl_type
decl_stmt|;
name|uint8_t
name|tmpl_length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lacp_systemid
block|{
name|uint16_t
name|lsi_prio
decl_stmt|;
name|uint8_t
name|lsi_mac
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
name|lacp_portid
block|{
name|uint16_t
name|lpi_prio
decl_stmt|;
name|uint16_t
name|lpi_portno
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|lacp_peerinfo
block|{
name|struct
name|lacp_systemid
name|lip_systemid
decl_stmt|;
name|uint16_t
name|lip_key
decl_stmt|;
name|struct
name|lacp_portid
name|lip_portid
decl_stmt|;
name|uint8_t
name|lip_state
decl_stmt|;
name|uint8_t
name|lip_resv
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
name|lacp_collectorinfo
block|{
name|uint16_t
name|lci_maxdelay
decl_stmt|;
name|uint8_t
name|lci_resv
index|[
literal|12
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|lacpdu
block|{
name|struct
name|ether_header
name|ldu_eh
decl_stmt|;
name|struct
name|slowprothdr
name|ldu_sph
decl_stmt|;
name|struct
name|tlvhdr
name|ldu_tlv_actor
decl_stmt|;
name|struct
name|lacp_peerinfo
name|ldu_actor
decl_stmt|;
name|struct
name|tlvhdr
name|ldu_tlv_partner
decl_stmt|;
name|struct
name|lacp_peerinfo
name|ldu_partner
decl_stmt|;
name|struct
name|tlvhdr
name|ldu_tlv_collector
decl_stmt|;
name|struct
name|lacp_collectorinfo
name|ldu_collector
decl_stmt|;
name|struct
name|tlvhdr
name|ldu_tlv_term
decl_stmt|;
name|uint8_t
name|ldu_resv
index|[
literal|50
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|LACP_TRANSIT_DELAY
value|1000
end_define

begin_comment
comment|/* in msec */
end_comment

begin_enum
enum|enum
name|lacp_selected
block|{
name|LACP_UNSELECTED
block|,
name|LACP_STANDBY
block|,
comment|/* not used in this implementation */
name|LACP_SELECTED
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|lacp_mux_state
block|{
name|LACP_MUX_DETACHED
block|,
name|LACP_MUX_WAITING
block|,
name|LACP_MUX_ATTACHED
block|,
name|LACP_MUX_COLLECTING
block|,
name|LACP_MUX_DISTRIBUTING
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|lacp_port
block|{
name|TAILQ_ENTRY
argument_list|(
argument|lacp_port
argument_list|)
name|lp_dist_q
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|lacp_port
argument_list|)
name|lp_next
expr_stmt|;
name|struct
name|lacp_softc
modifier|*
name|lp_lsc
decl_stmt|;
name|struct
name|trunk_port
modifier|*
name|lp_trunk
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|lp_ifp
decl_stmt|;
name|struct
name|lacp_peerinfo
name|lp_partner
decl_stmt|;
name|struct
name|lacp_peerinfo
name|lp_actor
decl_stmt|;
define|#
directive|define
name|lp_state
value|lp_actor.lip_state
define|#
directive|define
name|lp_key
value|lp_actor.lip_key
name|struct
name|timeval
name|lp_last_lacpdu
decl_stmt|;
name|int
name|lp_lacpdu_sent
decl_stmt|;
name|enum
name|lacp_mux_state
name|lp_mux_state
decl_stmt|;
name|enum
name|lacp_selected
name|lp_selected
decl_stmt|;
name|int
name|lp_flags
decl_stmt|;
name|u_int
name|lp_media
decl_stmt|;
comment|/* XXX redundant */
name|int
name|lp_timer
index|[
name|LACP_NTIMER
index|]
decl_stmt|;
name|struct
name|lacp_aggregator
modifier|*
name|lp_aggregator
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lacp_aggregator
block|{
name|TAILQ_ENTRY
argument_list|(
argument|lacp_aggregator
argument_list|)
name|la_q
expr_stmt|;
name|int
name|la_refcnt
decl_stmt|;
comment|/* num of ports which selected us */
name|int
name|la_nports
decl_stmt|;
comment|/* num of distributing ports  */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|lacp_port
argument_list|)
name|la_ports
expr_stmt|;
comment|/* distributing ports */
name|struct
name|lacp_peerinfo
name|la_partner
decl_stmt|;
name|struct
name|lacp_peerinfo
name|la_actor
decl_stmt|;
name|int
name|la_pending
decl_stmt|;
comment|/* number of ports which is waiting wait_while */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lacp_softc
block|{
name|struct
name|trunk_softc
modifier|*
name|lsc_trunk
decl_stmt|;
name|struct
name|lacp_aggregator
modifier|*
name|lsc_active_aggregator
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|lacp_aggregator
argument_list|)
name|lsc_aggregators
expr_stmt|;
name|boolean_t
name|lsc_suppress_distributing
decl_stmt|;
name|struct
name|callout
name|lsc_transit_callout
decl_stmt|;
name|struct
name|callout
name|lsc_callout
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|lacp_port
argument_list|)
name|lsc_ports
expr_stmt|;
name|u_int32_t
name|lsc_hashkey
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LACP_TYPE_ACTORINFO
value|1
end_define

begin_define
define|#
directive|define
name|LACP_TYPE_PARTNERINFO
value|2
end_define

begin_define
define|#
directive|define
name|LACP_TYPE_COLLECTORINFO
value|3
end_define

begin_comment
comment|/* timeout values (in sec) */
end_comment

begin_define
define|#
directive|define
name|LACP_FAST_PERIODIC_TIME
value|(1)
end_define

begin_define
define|#
directive|define
name|LACP_SLOW_PERIODIC_TIME
value|(30)
end_define

begin_define
define|#
directive|define
name|LACP_SHORT_TIMEOUT_TIME
value|(3 * LACP_FAST_PERIODIC_TIME)
end_define

begin_define
define|#
directive|define
name|LACP_LONG_TIMEOUT_TIME
value|(3 * LACP_SLOW_PERIODIC_TIME)
end_define

begin_define
define|#
directive|define
name|LACP_CHURN_DETECTION_TIME
value|(60)
end_define

begin_define
define|#
directive|define
name|LACP_AGGREGATE_WAIT_TIME
value|(2)
end_define

begin_comment
comment|/* int tlv_check(const void *, size_t, const struct tlvhdr *,     const struct tlv_template *, boolean_t); */
end_comment

begin_comment
comment|/*  * IEEE802.3ad marker protocol  *  * protocol (on-wire) definitions.  */
end_comment

begin_struct
struct|struct
name|markerdu
block|{
name|struct
name|ether_header
name|mdu_eh
decl_stmt|;
name|struct
name|slowprothdr
name|mdu_sph
decl_stmt|;
name|struct
name|tlvhdr
name|mdu_tlv
decl_stmt|;
name|uint16_t
name|mdu_rq_port
decl_stmt|;
name|uint8_t
name|mdu_rq_system
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|mdu_rq_xid
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|mdu_pad
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|tlvhdr
name|mdu_tlv_term
decl_stmt|;
name|uint8_t
name|mdu_resv
index|[
literal|90
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|MARKER_TYPE_INFO
value|1
end_define

begin_define
define|#
directive|define
name|MARKER_TYPE_RESPONSE
value|2
end_define

begin_define
define|#
directive|define
name|LACP_STATE_EQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|mask
parameter_list|)
define|\
value|((((s1) ^ (s2))& (mask)) == 0)
end_define

begin_define
define|#
directive|define
name|LACP_PORT
parameter_list|(
name|_tp
parameter_list|)
value|((struct lacp_port *)(_tp)->tp_psc)
end_define

begin_define
define|#
directive|define
name|LACP_SOFTC
parameter_list|(
name|_tr
parameter_list|)
value|((struct lacp_softc *)(_tr)->tr_psc)
end_define

begin_function_decl
name|int
name|lacp_input
parameter_list|(
name|struct
name|trunk_port
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
name|lacp_marker_input
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|trunk_port
modifier|*
name|lacp_select_tx_port
parameter_list|(
name|struct
name|trunk_softc
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
name|lacp_attach
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lacp_detach
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lacp_init
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lacp_stop
parameter_list|(
name|struct
name|trunk_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lacp_port_create
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lacp_port_destroy
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lacp_linkstate
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lacp_port_isactive
parameter_list|(
name|struct
name|trunk_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* following constants don't include terminating NUL */
end_comment

begin_define
define|#
directive|define
name|LACP_MACSTR_MAX
value|(2*6 + 5)
end_define

begin_define
define|#
directive|define
name|LACP_SYSTEMPRIOSTR_MAX
value|(4)
end_define

begin_define
define|#
directive|define
name|LACP_SYSTEMIDSTR_MAX
value|(LACP_SYSTEMPRIOSTR_MAX + 1 + LACP_MACSTR_MAX)
end_define

begin_define
define|#
directive|define
name|LACP_PORTPRIOSTR_MAX
value|(4)
end_define

begin_define
define|#
directive|define
name|LACP_PORTNOSTR_MAX
value|(4)
end_define

begin_define
define|#
directive|define
name|LACP_PORTIDSTR_MAX
value|(LACP_PORTPRIOSTR_MAX + 1 + LACP_PORTNOSTR_MAX)
end_define

begin_define
define|#
directive|define
name|LACP_KEYSTR_MAX
value|(4)
end_define

begin_define
define|#
directive|define
name|LACP_PARTNERSTR_MAX
define|\
value|(1 + LACP_SYSTEMIDSTR_MAX + 1 + LACP_KEYSTR_MAX + 1 \ 	+ LACP_PORTIDSTR_MAX + 1)
end_define

begin_define
define|#
directive|define
name|LACP_LAGIDSTR_MAX
define|\
value|(1 + LACP_PARTNERSTR_MAX + 1 + LACP_PARTNERSTR_MAX + 1)
end_define

begin_define
define|#
directive|define
name|LACP_STATESTR_MAX
value|(255)
end_define

begin_comment
comment|/* XXX */
end_comment

end_unit

