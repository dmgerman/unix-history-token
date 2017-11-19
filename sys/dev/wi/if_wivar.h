begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-4-Clause  *  * Copyright (c) 2002  *	M Warner Losh<imp@freebsd.org>.  All rights reserved.  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Encryption controls. We can enable or disable encryption as  * well as specify up to 4 encryption keys. We can also specify  * which of the four keys will be used for transmit encryption.  */
end_comment

begin_define
define|#
directive|define
name|WI_RID_ENCRYPTION
value|0xFC20
end_define

begin_define
define|#
directive|define
name|WI_RID_AUTHTYPE
value|0xFC21
end_define

begin_define
define|#
directive|define
name|WI_RID_DEFLT_CRYPT_KEYS
value|0xFCB0
end_define

begin_define
define|#
directive|define
name|WI_RID_TX_CRYPT_KEY
value|0xFCB1
end_define

begin_define
define|#
directive|define
name|WI_RID_WEP_AVAIL
value|0xFD4F
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_TX_CRYPT_KEY
value|0xFC23
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY0
value|0xFC24
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY1
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_MICROWAVE_OVEN
value|0xFC25
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY2
value|0xFC26
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_CRYPT_KEY3
value|0xFC27
end_define

begin_define
define|#
directive|define
name|WI_RID_P2_ENCRYPTION
value|0xFC28
end_define

begin_define
define|#
directive|define
name|WI_RID_ROAMING_MODE
value|0xFC2D
end_define

begin_define
define|#
directive|define
name|WI_RID_CUR_TX_RATE
value|0xFD44
end_define

begin_comment
comment|/* current TX rate */
end_comment

begin_define
define|#
directive|define
name|WI_MAX_AID
value|256
end_define

begin_comment
comment|/* max stations for ap operation */
end_comment

begin_struct
struct|struct
name|wi_vap
block|{
name|struct
name|ieee80211vap
name|wv_vap
decl_stmt|;
name|void
function_decl|(
modifier|*
name|wv_recv_mgmt
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
specifier|const
name|struct
name|ieee80211_rx_stats
modifier|*
name|rxs
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wv_newstate
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
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct wi_vap *)(vap))
end_define

begin_struct
struct|struct
name|wi_softc
block|{
name|struct
name|ieee80211com
name|sc_ic
decl_stmt|;
name|struct
name|mbufq
name|sc_snd
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|callout
name|sc_watchdog
decl_stmt|;
name|int
name|sc_unit
decl_stmt|;
name|int
name|wi_gone
decl_stmt|;
name|int
name|sc_enabled
decl_stmt|;
name|int
name|sc_reset
decl_stmt|;
name|int
name|sc_firmware_type
decl_stmt|;
define|#
directive|define
name|WI_NOTYPE
value|0
define|#
directive|define
name|WI_LUCENT
value|1
define|#
directive|define
name|WI_INTERSIL
value|2
define|#
directive|define
name|WI_SYMBOL
value|3
name|int
name|sc_pri_firmware_ver
decl_stmt|;
comment|/* Primary firmware */
name|int
name|sc_sta_firmware_ver
decl_stmt|;
comment|/* Station firmware */
name|unsigned
name|int
name|sc_nic_id
decl_stmt|;
comment|/* Type of NIC */
name|char
modifier|*
name|sc_nic_name
decl_stmt|;
name|int
name|wi_bus_type
decl_stmt|;
comment|/* Bus attachment type */
name|struct
name|resource
modifier|*
name|local
decl_stmt|;
name|int
name|local_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|iobase
decl_stmt|;
name|int
name|iobase_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|bus_space_handle_t
name|wi_localhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_localtag
decl_stmt|;
name|bus_space_handle_t
name|wi_bhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_btag
decl_stmt|;
name|bus_space_handle_t
name|wi_bmemhandle
decl_stmt|;
name|bus_space_tag_t
name|wi_bmemtag
decl_stmt|;
name|void
modifier|*
name|wi_intrhand
decl_stmt|;
name|struct
name|ieee80211_channel
modifier|*
name|wi_channel
decl_stmt|;
name|int
name|wi_io_addr
decl_stmt|;
name|int
name|wi_cmd_count
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|int
name|sc_bap_id
decl_stmt|;
name|int
name|sc_bap_off
decl_stmt|;
name|int
name|sc_porttype
decl_stmt|;
name|u_int16_t
name|sc_portnum
decl_stmt|;
name|u_int16_t
name|sc_encryption
decl_stmt|;
name|u_int16_t
name|sc_monitor_port
decl_stmt|;
name|u_int16_t
name|sc_chanmask
decl_stmt|;
comment|/* RSSI interpretation */
name|u_int16_t
name|sc_min_rssi
decl_stmt|;
comment|/* clamp sc_min_rssi< RSSI */
name|u_int16_t
name|sc_max_rssi
decl_stmt|;
comment|/* clamp RSSI< sc_max_rssi */
name|u_int16_t
name|sc_dbm_offset
decl_stmt|;
comment|/* dBm ~ RSSI - sc_dbm_offset */
name|int
name|sc_buflen
decl_stmt|;
comment|/* TX buffer size */
name|int
name|sc_ntxbuf
decl_stmt|;
define|#
directive|define
name|WI_NTXBUF
value|3
struct|struct
block|{
name|int
name|d_fid
decl_stmt|;
name|int
name|d_len
decl_stmt|;
block|}
name|sc_txd
index|[
name|WI_NTXBUF
index|]
struct|;
comment|/* TX buffers */
name|int
name|sc_txnext
decl_stmt|;
comment|/* index of next TX */
name|int
name|sc_txcur
decl_stmt|;
comment|/* index of current TX*/
name|int
name|sc_tx_timer
decl_stmt|;
name|struct
name|wi_counters
name|sc_stats
decl_stmt|;
name|u_int16_t
name|sc_ibss_port
decl_stmt|;
name|struct
name|timeval
name|sc_last_syn
decl_stmt|;
name|int
name|sc_false_syns
decl_stmt|;
name|u_int16_t
name|sc_txbuf
index|[
name|IEEE80211_MAX_LEN
operator|/
literal|2
index|]
decl_stmt|;
name|struct
name|wi_tx_radiotap_header
name|sc_tx_th
decl_stmt|;
name|struct
name|wi_rx_radiotap_header
name|sc_rx_th
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* maximum consecutive false change-of-BSSID indications */
end_comment

begin_define
define|#
directive|define
name|WI_MAX_FALSE_SYNS
value|10
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_HAS_ENHSECURITY
value|0x0001
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_HAS_WPASUPPORT
value|0x0002
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_HAS_ROAMING
value|0x0020
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_HAS_FRAGTHR
value|0x0200
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_HAS_DBMADJUST
value|0x0400
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_RUNNING
value|0x0800
end_define

begin_define
define|#
directive|define
name|WI_FLAGS_PROMISC
value|0x1000
end_define

begin_struct
struct|struct
name|wi_card_ident
block|{
name|u_int16_t
name|card_id
decl_stmt|;
name|char
modifier|*
name|card_name
decl_stmt|;
name|u_int8_t
name|firm_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WI_PRISM_MIN_RSSI
value|0x1b
end_define

begin_define
define|#
directive|define
name|WI_PRISM_MAX_RSSI
value|0x9a
end_define

begin_define
define|#
directive|define
name|WI_PRISM_DBM_OFFSET
value|100
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|WI_LUCENT_MIN_RSSI
value|47
end_define

begin_define
define|#
directive|define
name|WI_LUCENT_MAX_RSSI
value|138
end_define

begin_define
define|#
directive|define
name|WI_LUCENT_DBM_OFFSET
value|149
end_define

begin_define
define|#
directive|define
name|WI_RSSI_TO_DBM
parameter_list|(
name|sc
parameter_list|,
name|rssi
parameter_list|)
value|(MIN((sc)->sc_max_rssi, \     MAX((sc)->sc_min_rssi, (rssi))) - (sc)->sc_dbm_offset)
end_define

begin_define
define|#
directive|define
name|WI_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|WI_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|WI_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_function_decl
name|int
name|wi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wi_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wi_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wi_alloc
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wi_free
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|wi_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|wi_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wi_mgmt_xmit
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wi_stop
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wi_init
parameter_list|(
name|struct
name|wi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

