begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002, 2003 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_NODE_H_
end_define

begin_define
define|#
directive|define
name|IEEE80211_PSCAN_WAIT
value|5
end_define

begin_comment
comment|/* passive scan wait */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_TRANS_WAIT
value|5
end_define

begin_comment
comment|/* transition wait */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_WAIT
value|5
end_define

begin_comment
comment|/* inactivity timer interval */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_INACT_MAX
value|(300/IEEE80211_INACT_WAIT)
end_define

begin_define
define|#
directive|define
name|IEEE80211_NODE_HASHSIZE
value|32
end_define

begin_comment
comment|/* simple hash is enough for variation of macaddr */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_NODE_HASH
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((u_int8_t *)(addr))[IEEE80211_ADDR_LEN - 1] % IEEE80211_NODE_HASHSIZE)
end_define

begin_define
define|#
directive|define
name|IEEE80211_RATE_SIZE
value|8
end_define

begin_comment
comment|/* 802.11 standard */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_RATE_MAXSIZE
value|15
end_define

begin_comment
comment|/* max rates we'll handle */
end_comment

begin_struct
struct|struct
name|ieee80211_rateset
block|{
name|u_int8_t
name|rs_nrates
decl_stmt|;
name|u_int8_t
name|rs_rates
index|[
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Node specific information.  Note that drivers are expected  * to derive from this structure to add device-specific per-node  * state.  This is done by overriding the ic_node_* methods in  * the ieee80211com structure.  */
end_comment

begin_struct
struct|struct
name|ieee80211_node
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_list
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ieee80211_node
argument_list|)
name|ni_hash
expr_stmt|;
name|u_int
name|ni_refcnt
decl_stmt|;
comment|/* hardware */
name|u_int8_t
name|ni_rssi
decl_stmt|;
comment|/* recv ssi */
name|u_int32_t
name|ni_rstamp
decl_stmt|;
comment|/* recv timestamp */
name|u_int8_t
name|ni_rantenna
decl_stmt|;
comment|/* recv antenna */
comment|/* header */
name|u_int8_t
name|ni_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ni_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* beacon, probe response */
name|u_int8_t
name|ni_tstamp
index|[
literal|8
index|]
decl_stmt|;
comment|/* from last rcv'd beacon */
name|u_int16_t
name|ni_intval
decl_stmt|;
comment|/* beacon interval */
name|u_int16_t
name|ni_capinfo
decl_stmt|;
comment|/* capabilities */
name|u_int8_t
name|ni_esslen
decl_stmt|;
name|u_int8_t
name|ni_essid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|struct
name|ieee80211_rateset
name|ni_rates
decl_stmt|;
comment|/* negotiated rate set */
name|u_int8_t
modifier|*
name|ni_country
decl_stmt|;
comment|/* country information XXX */
name|struct
name|ieee80211_channel
modifier|*
name|ni_chan
decl_stmt|;
name|u_int16_t
name|ni_fhdwell
decl_stmt|;
comment|/* FH only */
name|u_int8_t
name|ni_fhindex
decl_stmt|;
comment|/* FH only */
name|u_int8_t
name|ni_erp
decl_stmt|;
comment|/* 11g only */
ifdef|#
directive|ifdef
name|notyet
comment|/* DTIM and contention free period (CFP) */
name|u_int8_t
name|ni_dtimperiod
decl_stmt|;
name|u_int8_t
name|ni_cfpperiod
decl_stmt|;
comment|/* # of DTIMs between CFPs */
name|u_int16_t
name|ni_cfpduremain
decl_stmt|;
comment|/* remaining cfp duration */
name|u_int16_t
name|ni_cfpmaxduration
decl_stmt|;
comment|/* max CFP duration in TU */
name|u_int16_t
name|ni_nextdtim
decl_stmt|;
comment|/* time to next DTIM */
name|u_int16_t
name|ni_timoffset
decl_stmt|;
endif|#
directive|endif
comment|/* others */
name|u_int16_t
name|ni_associd
decl_stmt|;
comment|/* assoc response */
name|u_int16_t
name|ni_txseq
decl_stmt|;
comment|/* seq to be transmitted */
name|u_int16_t
name|ni_rxseq
decl_stmt|;
comment|/* seq previous received */
name|int
name|ni_fails
decl_stmt|;
comment|/* failure count to associate */
name|int
name|ni_inact
decl_stmt|;
comment|/* inactivity mark count */
name|int
name|ni_txrate
decl_stmt|;
comment|/* index to ni_rates[] */
block|}
struct|;
end_struct

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ieee80211_node
operator|*
name|ieee80211_ref_node
argument_list|(
argument|struct ieee80211_node *ni
argument_list|)
block|{
name|atomic_add_int
argument_list|(
operator|&
name|ni
operator|->
name|ni_refcnt
argument_list|,
literal|1
argument_list|)
block|;
return|return
name|ni
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|void
name|ieee80211_unref_node
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
modifier|*
name|ni
parameter_list|)
block|{
name|atomic_subtract_int
argument_list|(
operator|&
operator|(
operator|*
name|ni
operator|)
operator|->
name|ni_refcnt
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|*
name|ni
operator|=
name|NULL
expr_stmt|;
comment|/* guard against use */
block|}
end_function

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_node_attach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_node_lateattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_node_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_begin_scan
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_next_scan
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_end_scan
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_alloc_node
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_dup_bss
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_find_node
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ieee80211_node
modifier|*
name|ieee80211_lookup_node
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
name|macaddr
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_free_node
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_free_allnodes
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
name|ieee80211_iter_func
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|ieee80211_iterate_nodes
parameter_list|(
name|struct
name|ieee80211com
modifier|*
name|ic
parameter_list|,
name|ieee80211_iter_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_timeout_nodes
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ieee80211_create_ibss
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_NODE_H_ */
end_comment

end_unit

