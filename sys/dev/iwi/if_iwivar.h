begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004, 2005  *      Damien Bergamini<damien.bergamini@free.fr>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_struct
struct|struct
name|iwi_rx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wr_ihdr
decl_stmt|;
name|uint8_t
name|wr_flags
decl_stmt|;
name|uint8_t
name|wr_rate
decl_stmt|;
name|uint16_t
name|wr_chan_freq
decl_stmt|;
name|uint16_t
name|wr_chan_flags
decl_stmt|;
name|uint8_t
name|wr_antsignal
decl_stmt|;
name|uint8_t
name|wr_antenna
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWI_RX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_RATE) |				\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL) |				\ 	 (1<< IEEE80211_RADIOTAP_DB_ANTSIGNAL) |			\ 	 (1<< IEEE80211_RADIOTAP_ANTENNA))
end_define

begin_struct
struct|struct
name|iwi_tx_radiotap_header
block|{
name|struct
name|ieee80211_radiotap_header
name|wt_ihdr
decl_stmt|;
name|uint8_t
name|wt_flags
decl_stmt|;
name|uint16_t
name|wt_chan_freq
decl_stmt|;
name|uint16_t
name|wt_chan_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWI_TX_RADIOTAP_PRESENT
define|\
value|((1<< IEEE80211_RADIOTAP_FLAGS) |				\ 	 (1<< IEEE80211_RADIOTAP_CHANNEL))
end_define

begin_struct
struct|struct
name|iwi_cmd_ring
block|{
name|bus_dma_tag_t
name|desc_dmat
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_addr_t
name|physaddr
decl_stmt|;
name|struct
name|iwi_cmd_desc
modifier|*
name|desc
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|queued
decl_stmt|;
name|int
name|cur
decl_stmt|;
name|int
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_tx_data
block|{
name|bus_dmamap_t
name|map
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|ni
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_tx_ring
block|{
name|bus_dma_tag_t
name|desc_dmat
decl_stmt|;
name|bus_dma_tag_t
name|data_dmat
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_addr_t
name|physaddr
decl_stmt|;
name|bus_addr_t
name|csr_ridx
decl_stmt|;
name|bus_addr_t
name|csr_widx
decl_stmt|;
name|struct
name|iwi_tx_desc
modifier|*
name|desc
decl_stmt|;
name|struct
name|iwi_tx_data
modifier|*
name|data
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|queued
decl_stmt|;
name|int
name|cur
decl_stmt|;
name|int
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_rx_data
block|{
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_addr_t
name|physaddr
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_rx_ring
block|{
name|bus_dma_tag_t
name|data_dmat
decl_stmt|;
name|struct
name|iwi_rx_data
modifier|*
name|data
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|cur
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_node
block|{
name|struct
name|ieee80211_node
name|in_node
decl_stmt|;
name|int
name|in_station
decl_stmt|;
define|#
directive|define
name|IWI_MAX_IBSSNODE
value|32
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_fw
block|{
specifier|const
name|struct
name|firmware
modifier|*
name|fp
decl_stmt|;
comment|/* image handle */
specifier|const
name|char
modifier|*
name|data
decl_stmt|;
comment|/* firmware image data */
name|size_t
name|size
decl_stmt|;
comment|/* firmware image size */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* associated image name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwi_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|ieee80211com
name|sc_ic
decl_stmt|;
name|int
function_decl|(
modifier|*
name|sc_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_node_free
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|uint8_t
name|sc_mcast
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|unrhdr
modifier|*
name|sc_unr
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
comment|/* private task queue */
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|700000
name|struct
name|proc
modifier|*
name|sc_tqproc
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWI_FLAG_FW_INITED
value|(1<< 0)
define|#
directive|define
name|IWI_FLAG_SCANNING
value|(1<< 1)
define|#
directive|define
name|IWI_FLAG_FW_LOADING
value|(1<< 2)
define|#
directive|define
name|IWI_FLAG_BUSY
value|(1<< 3)
comment|/* busy sending a command */
define|#
directive|define
name|IWI_FLAG_ASSOCIATED
value|(1<< 4)
comment|/* currently associated  */
name|struct
name|iwi_cmd_ring
name|cmdq
decl_stmt|;
name|struct
name|iwi_tx_ring
name|txq
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
name|struct
name|iwi_rx_ring
name|rxq
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
comment|/* 	 * The card needs external firmware images to work, which is made of a 	 * bootloader, microcode and firmware proper. In version 3.00 and 	 * above, all pieces are contained in a single image, preceded by a 	 * struct iwi_firmware_hdr indicating the size of the 3 pieces. 	 * Old firmware< 3.0 has separate boot and ucode, so we need to 	 * load all of them explicitly. 	 * To avoid issues related to fragmentation, we keep the block of 	 * dma-ble memory around until detach time, and reallocate it when 	 * it becomes too small. fw_dma_size is the size currently allocated. 	 */
name|int
name|fw_dma_size
decl_stmt|;
name|uint32_t
name|fw_flags
decl_stmt|;
comment|/* allocation status */
define|#
directive|define
name|IWI_FW_HAVE_DMAT
value|0x01
define|#
directive|define
name|IWI_FW_HAVE_MAP
value|0x02
define|#
directive|define
name|IWI_FW_HAVE_PHY
value|0x04
name|bus_dma_tag_t
name|fw_dmat
decl_stmt|;
name|bus_dmamap_t
name|fw_map
decl_stmt|;
name|bus_addr_t
name|fw_physaddr
decl_stmt|;
name|void
modifier|*
name|fw_virtaddr
decl_stmt|;
name|enum
name|ieee80211_opmode
name|fw_mode
decl_stmt|;
comment|/* mode of current firmware */
name|struct
name|iwi_fw
name|fw_boot
decl_stmt|;
comment|/* boot firmware */
name|struct
name|iwi_fw
name|fw_uc
decl_stmt|;
comment|/* microcode */
name|struct
name|iwi_fw
name|fw_fw
decl_stmt|;
comment|/* operating mode support */
name|int
name|curchan
decl_stmt|;
comment|/* current h/w channel # */
name|int
name|antenna
decl_stmt|;
name|int
name|dwelltime
decl_stmt|;
name|int
name|bluetooth
decl_stmt|;
name|struct
name|iwi_associate
name|assoc
decl_stmt|;
name|struct
name|iwi_wme_params
name|wme
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|task
name|sc_radiontask
decl_stmt|;
comment|/* radio on processing */
name|struct
name|task
name|sc_radiofftask
decl_stmt|;
comment|/* radio off processing */
name|struct
name|task
name|sc_scanstarttask
decl_stmt|;
comment|/* scan start processing */
name|struct
name|task
name|sc_scanaborttask
decl_stmt|;
comment|/* scan abort processing */
name|struct
name|task
name|sc_scandonetask
decl_stmt|;
comment|/* scan completed processing */
name|struct
name|task
name|sc_scantask
decl_stmt|;
comment|/* scan channel processing */
name|struct
name|task
name|sc_setwmetask
decl_stmt|;
comment|/* set wme params processing */
name|struct
name|task
name|sc_downtask
decl_stmt|;
comment|/* disassociate processing */
name|struct
name|task
name|sc_restarttask
decl_stmt|;
comment|/* restart adapter processing */
name|unsigned
name|int
name|sc_softled
range|:
literal|1
decl_stmt|,
comment|/* enable LED gpio status */
name|sc_ledstate
range|:
literal|1
decl_stmt|,
comment|/* LED on/off state */
name|sc_blinking
range|:
literal|1
decl_stmt|;
comment|/* LED blink operation active */
name|u_int
name|sc_nictype
decl_stmt|;
comment|/* NIC type from EEPROM */
name|u_int
name|sc_ledpin
decl_stmt|;
comment|/* mask for activity LED */
name|u_int
name|sc_ledidle
decl_stmt|;
comment|/* idle polling interval */
name|int
name|sc_ledevent
decl_stmt|;
comment|/* time of last LED event */
name|u_int8_t
name|sc_rxrate
decl_stmt|;
comment|/* current rx rate for LED */
name|u_int8_t
name|sc_rxrix
decl_stmt|;
name|u_int8_t
name|sc_txrate
decl_stmt|;
comment|/* current tx rate for LED */
name|u_int8_t
name|sc_txrix
decl_stmt|;
name|u_int16_t
name|sc_ledoff
decl_stmt|;
comment|/* off time for current blink */
name|struct
name|callout
name|sc_ledtimer
decl_stmt|;
comment|/* led off timer */
name|int
name|sc_tx_timer
decl_stmt|;
name|int
name|sc_rfkill_timer
decl_stmt|;
comment|/* poll for rfkill change */
name|int
name|sc_scan_timer
decl_stmt|;
comment|/* scan request timeout */
name|struct
name|bpf_if
modifier|*
name|sc_drvbpf
decl_stmt|;
union|union
block|{
name|struct
name|iwi_rx_radiotap_header
name|th
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|64
index|]
decl_stmt|;
block|}
name|sc_rxtapu
union|;
define|#
directive|define
name|sc_rxtap
value|sc_rxtapu.th
name|int
name|sc_rxtap_len
decl_stmt|;
union|union
block|{
name|struct
name|iwi_tx_radiotap_header
name|th
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|64
index|]
decl_stmt|;
block|}
name|sc_txtapu
union|;
define|#
directive|define
name|sc_txtap
value|sc_txtapu.th
name|int
name|sc_txtap_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NB.: This models the only instance of async locking in iwi_init_locked  *	and must be kept in sync.  */
end_comment

begin_define
define|#
directive|define
name|IWI_LOCK_DECL
value|int	__waslocked = 0
end_define

begin_comment
comment|//#define	IWI_LOCK_ASSERT(sc)	mtx_assert(&(sc)->sc_mtx, MA_OWNED)
end_comment

begin_define
define|#
directive|define
name|IWI_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	if (!mtx_owned(&(sc)->sc_mtx))	\ 		printf("%s iwi_lock not held\n", __func__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|IWI_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	if (!(__waslocked = mtx_owned(&(sc)->sc_mtx)))	\ 		mtx_lock(&(sc)->sc_mtx);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|IWI_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|do {			\ 	if (!__waslocked)			\ 		mtx_unlock(&(sc)->sc_mtx);	\ } while (0)
end_define

end_unit

