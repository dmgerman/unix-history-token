begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2007-2009 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_TDMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_TDMA_H_
end_define

begin_comment
comment|/*  * TDMA-mode implementation definitions.  */
end_comment

begin_define
define|#
directive|define
name|TDMA_SUBTYPE_PARAM
value|0x01
end_define

begin_define
define|#
directive|define
name|TDMA_VERSION_V2
value|2
end_define

begin_define
define|#
directive|define
name|TDMA_VERSION
value|TDMA_VERSION_V2
end_define

begin_comment
comment|/* NB: we only support 2 right now but protocol handles up to 8 */
end_comment

begin_define
define|#
directive|define
name|TDMA_MAXSLOTS
value|2
end_define

begin_comment
comment|/* max slots/sta's */
end_comment

begin_define
define|#
directive|define
name|TDMA_PARAM_LEN_V2
value|sizeof(struct ieee80211_tdma_param)
end_define

begin_comment
comment|/*  * TDMA information element.  */
end_comment

begin_struct
struct|struct
name|ieee80211_tdma_param
block|{
name|u_int8_t
name|tdma_id
decl_stmt|;
comment|/* IEEE80211_ELEMID_VENDOR */
name|u_int8_t
name|tdma_len
decl_stmt|;
name|u_int8_t
name|tdma_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* TDMA_OUI */
name|u_int8_t
name|tdma_type
decl_stmt|;
comment|/* TDMA_OUI_TYPE */
name|u_int8_t
name|tdma_subtype
decl_stmt|;
comment|/* TDMA_SUBTYPE_PARAM */
name|u_int8_t
name|tdma_version
decl_stmt|;
comment|/* spec revision */
name|u_int8_t
name|tdma_slot
decl_stmt|;
comment|/* station slot # [0..7] */
name|u_int8_t
name|tdma_slotcnt
decl_stmt|;
comment|/* bss slot count [1..8] */
name|u_int16_t
name|tdma_slotlen
decl_stmt|;
comment|/* bss slot len (100us) */
name|u_int8_t
name|tdma_bintval
decl_stmt|;
comment|/* beacon interval (superframes) */
name|u_int8_t
name|tdma_inuse
index|[
literal|1
index|]
decl_stmt|;
comment|/* slot occupancy map */
name|u_int8_t
name|tdma_pad
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|tdma_tstamp
index|[
literal|8
index|]
decl_stmt|;
comment|/* timestamp from last beacon */
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Implementation state.  */
end_comment

begin_struct
struct|struct
name|ieee80211_tdma_state
block|{
name|u_int
name|tdma_slotlen
decl_stmt|;
comment|/* bss slot length (us) */
name|uint8_t
name|tdma_version
decl_stmt|;
comment|/* protocol version to use */
name|uint8_t
name|tdma_slotcnt
decl_stmt|;
comment|/* bss slot count */
name|uint8_t
name|tdma_bintval
decl_stmt|;
comment|/* beacon interval (slots) */
name|uint8_t
name|tdma_slot
decl_stmt|;
comment|/* station slot # */
name|uint8_t
name|tdma_inuse
index|[
literal|1
index|]
decl_stmt|;
comment|/* mask of slots in use */
name|uint8_t
name|tdma_active
index|[
literal|1
index|]
decl_stmt|;
comment|/* mask of active slots */
name|int
name|tdma_count
decl_stmt|;
comment|/* active/inuse countdown */
name|void
modifier|*
name|tdma_peer
decl_stmt|;
comment|/* peer station cookie */
name|struct
name|timeval
name|tdma_lastprint
decl_stmt|;
comment|/* time of last rate-limited printf */
name|int
name|tdma_fails
decl_stmt|;
comment|/* fail count for rate-limiting */
comment|/* parent method pointers */
name|int
function_decl|(
modifier|*
name|tdma_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tdma_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
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
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|tdma_opdetach
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TDMA_UPDATE_SLOT
value|0x0001
end_define

begin_comment
comment|/* tdma_slot changed */
end_comment

begin_define
define|#
directive|define
name|TDMA_UPDATE_SLOTCNT
value|0x0002
end_define

begin_comment
comment|/* tdma_slotcnt changed */
end_comment

begin_define
define|#
directive|define
name|TDMA_UPDATE_SLOTLEN
value|0x0004
end_define

begin_comment
comment|/* tdma_slotlen changed */
end_comment

begin_define
define|#
directive|define
name|TDMA_UPDATE_BINTVAL
value|0x0008
end_define

begin_comment
comment|/* tdma_bintval changed */
end_comment

begin_function_decl
name|void
name|ieee80211_tdma_vattach
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_tdma_getslot
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_parse_tdma
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|ie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
modifier|*
name|ieee80211_add_tdma
parameter_list|(
name|uint8_t
modifier|*
name|frm
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_beacon_offsets
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_tdma_update_beacon
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|,
name|struct
name|ieee80211_beacon_offsets
modifier|*
name|bo
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
comment|/* !_NET80211_IEEE80211_TDMA_H_ */
end_comment

end_unit

