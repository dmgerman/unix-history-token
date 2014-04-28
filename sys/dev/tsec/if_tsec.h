begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006-2007 Semihalf, Piotr Kruszynski  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_TSEC_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_TSEC_H
end_define

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_define
define|#
directive|define
name|TSEC_RX_NUM_DESC
value|256
end_define

begin_define
define|#
directive|define
name|TSEC_TX_NUM_DESC
value|256
end_define

begin_comment
comment|/* Interrupt Coalescing types */
end_comment

begin_define
define|#
directive|define
name|TSEC_IC_RX
value|0
end_define

begin_define
define|#
directive|define
name|TSEC_IC_TX
value|1
end_define

begin_comment
comment|/* eTSEC ID */
end_comment

begin_define
define|#
directive|define
name|TSEC_ETSEC_ID
value|0x0124
end_define

begin_comment
comment|/* Frame sizes */
end_comment

begin_define
define|#
directive|define
name|TSEC_MIN_FRAME_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|TSEC_MAX_FRAME_SIZE
value|9600
end_define

begin_struct
struct|struct
name|tsec_softc
block|{
comment|/* XXX MII bus requires that struct ifnet is first!!! */
name|struct
name|ifnet
modifier|*
name|tsec_ifp
decl_stmt|;
name|struct
name|mtx
name|transmit_lock
decl_stmt|;
comment|/* transmitter lock */
name|struct
name|mtx
name|receive_lock
decl_stmt|;
comment|/* receiver lock */
name|phandle_t
name|node
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|device_t
name|tsec_miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|tsec_mii
decl_stmt|;
comment|/* MII media control */
name|int
name|tsec_link
decl_stmt|;
name|bus_dma_tag_t
name|tsec_tx_dtag
decl_stmt|;
comment|/* TX descriptors tag */
name|bus_dmamap_t
name|tsec_tx_dmap
decl_stmt|;
comment|/* TX descriptors map */
name|struct
name|tsec_desc
modifier|*
name|tsec_tx_vaddr
decl_stmt|;
comment|/* vadress of TX descriptors */
name|uint32_t
name|tsec_tx_raddr
decl_stmt|;
comment|/* real adress of TX descriptors */
name|bus_dma_tag_t
name|tsec_rx_dtag
decl_stmt|;
comment|/* RX descriptors tag */
name|bus_dmamap_t
name|tsec_rx_dmap
decl_stmt|;
comment|/* RX descriptors map */
name|struct
name|tsec_desc
modifier|*
name|tsec_rx_vaddr
decl_stmt|;
comment|/* vadress of RX descriptors */
name|uint32_t
name|tsec_rx_raddr
decl_stmt|;
comment|/* real adress of RX descriptors */
name|bus_dma_tag_t
name|tsec_tx_mtag
decl_stmt|;
comment|/* TX mbufs tag */
name|bus_dma_tag_t
name|tsec_rx_mtag
decl_stmt|;
comment|/* TX mbufs tag */
struct|struct
name|rx_data_type
block|{
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* mbuf map */
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|uint32_t
name|paddr
decl_stmt|;
comment|/* DMA addres of buffer */
block|}
name|rx_data
index|[
name|TSEC_RX_NUM_DESC
index|]
struct|;
name|uint32_t
name|tx_cur_desc_cnt
decl_stmt|;
name|uint32_t
name|tx_dirty_desc_cnt
decl_stmt|;
name|uint32_t
name|rx_cur_desc_cnt
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_rres
decl_stmt|;
comment|/* register resource */
name|int
name|sc_rrid
decl_stmt|;
comment|/* register rid */
struct|struct
block|{
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
block|}
name|sc_bas
struct|;
name|struct
name|resource
modifier|*
name|sc_transmit_ires
decl_stmt|;
name|void
modifier|*
name|sc_transmit_ihand
decl_stmt|;
name|int
name|sc_transmit_irid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_receive_ires
decl_stmt|;
name|void
modifier|*
name|sc_receive_ihand
decl_stmt|;
name|int
name|sc_receive_irid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_error_ires
decl_stmt|;
name|void
modifier|*
name|sc_error_ihand
decl_stmt|;
name|int
name|sc_error_irid
decl_stmt|;
name|int
name|tsec_if_flags
decl_stmt|;
name|int
name|is_etsec
decl_stmt|;
comment|/* Watchdog and MII tick related */
name|struct
name|callout
name|tsec_callout
decl_stmt|;
name|int
name|tsec_watchdog
decl_stmt|;
comment|/* TX maps */
name|bus_dmamap_t
name|tx_map_data
index|[
name|TSEC_TX_NUM_DESC
index|]
decl_stmt|;
comment|/* unused TX maps data */
name|uint32_t
name|tx_map_unused_get_cnt
decl_stmt|;
name|uint32_t
name|tx_map_unused_put_cnt
decl_stmt|;
name|bus_dmamap_t
modifier|*
name|tx_map_unused_data
index|[
name|TSEC_TX_NUM_DESC
index|]
decl_stmt|;
comment|/* used TX maps data */
name|uint32_t
name|tx_map_used_get_cnt
decl_stmt|;
name|uint32_t
name|tx_map_used_put_cnt
decl_stmt|;
name|bus_dmamap_t
modifier|*
name|tx_map_used_data
index|[
name|TSEC_TX_NUM_DESC
index|]
decl_stmt|;
comment|/* mbufs in TX queue */
name|uint32_t
name|tx_mbuf_used_get_cnt
decl_stmt|;
name|uint32_t
name|tx_mbuf_used_put_cnt
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tx_mbuf_used_data
index|[
name|TSEC_TX_NUM_DESC
index|]
decl_stmt|;
comment|/* interrupt coalescing */
name|struct
name|mtx
name|ic_lock
decl_stmt|;
name|uint32_t
name|rx_ic_time
decl_stmt|;
comment|/* RW, valid values 0..65535 */
name|uint32_t
name|rx_ic_count
decl_stmt|;
comment|/* RW, valid values 0..255 */
name|uint32_t
name|tx_ic_time
decl_stmt|;
name|uint32_t
name|tx_ic_count
decl_stmt|;
comment|/* currently received frame */
name|struct
name|mbuf
modifier|*
name|frame
decl_stmt|;
name|int
name|phyaddr
decl_stmt|;
name|bus_space_tag_t
name|phy_bst
decl_stmt|;
name|bus_space_handle_t
name|phy_bsh
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* interface to get/put generic objects */
end_comment

begin_define
define|#
directive|define
name|TSEC_CNT_INIT
parameter_list|(
name|cnt
parameter_list|,
name|wrap
parameter_list|)
value|((cnt) = ((wrap) - 1))
end_define

begin_define
define|#
directive|define
name|TSEC_INC
parameter_list|(
name|count
parameter_list|,
name|wrap
parameter_list|)
value|(count = ((count) + 1)& ((wrap) - 1))
end_define

begin_define
define|#
directive|define
name|TSEC_GET_GENERIC
parameter_list|(
name|hand
parameter_list|,
name|tab
parameter_list|,
name|count
parameter_list|,
name|wrap
parameter_list|)
define|\
value|((hand)->tab[TSEC_INC((hand)->count, wrap)])
end_define

begin_define
define|#
directive|define
name|TSEC_PUT_GENERIC
parameter_list|(
name|hand
parameter_list|,
name|tab
parameter_list|,
name|count
parameter_list|,
name|wrap
parameter_list|,
name|val
parameter_list|)
define|\
value|((hand)->tab[TSEC_INC((hand)->count, wrap)] = val)
end_define

begin_define
define|#
directive|define
name|TSEC_BACK_GENERIC
parameter_list|(
name|sc
parameter_list|,
name|count
parameter_list|,
name|wrap
parameter_list|)
value|do {			\ 		if ((sc)->count> 0)				\ 			(sc)->count--;				\ 		else						\ 			(sc)->count = (wrap) - 1;		\ } while (0)
end_define

begin_comment
comment|/* TX maps interface */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_MAP_CNT_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 		TSEC_CNT_INIT((sc)->tx_map_unused_get_cnt, TSEC_TX_NUM_DESC);	\ 		TSEC_CNT_INIT((sc)->tx_map_unused_put_cnt, TSEC_TX_NUM_DESC);	\ 		TSEC_CNT_INIT((sc)->tx_map_used_get_cnt, TSEC_TX_NUM_DESC);	\ 		TSEC_CNT_INIT((sc)->tx_map_used_put_cnt, TSEC_TX_NUM_DESC);	\ } while (0)
end_define

begin_comment
comment|/* interface to get/put unused TX maps */
end_comment

begin_define
define|#
directive|define
name|TSEC_ALLOC_TX_MAP
parameter_list|(
name|sc
parameter_list|)
define|\
value|TSEC_GET_GENERIC(sc, tx_map_unused_data, tx_map_unused_get_cnt,	\ 		TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_FREE_TX_MAP
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|TSEC_PUT_GENERIC(sc, tx_map_unused_data, tx_map_unused_put_cnt,	\ 		TSEC_TX_NUM_DESC, val)
end_define

begin_comment
comment|/* interface to get/put used TX maps */
end_comment

begin_define
define|#
directive|define
name|TSEC_GET_TX_MAP
parameter_list|(
name|sc
parameter_list|)
define|\
value|TSEC_GET_GENERIC(sc, tx_map_used_data, tx_map_used_get_cnt,	\ 		TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_PUT_TX_MAP
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|TSEC_PUT_GENERIC(sc, tx_map_used_data, tx_map_used_put_cnt,	\ 		TSEC_TX_NUM_DESC, val)
end_define

begin_comment
comment|/* interface to get/put TX mbufs in send queue */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_MBUF_CNT_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 		TSEC_CNT_INIT((sc)->tx_mbuf_used_get_cnt, TSEC_TX_NUM_DESC);	\ 		TSEC_CNT_INIT((sc)->tx_mbuf_used_put_cnt, TSEC_TX_NUM_DESC);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GET_TX_MBUF
parameter_list|(
name|sc
parameter_list|)
define|\
value|TSEC_GET_GENERIC(sc, tx_mbuf_used_data, tx_mbuf_used_get_cnt,	\ 		TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_PUT_TX_MBUF
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|TSEC_PUT_GENERIC(sc, tx_mbuf_used_data, tx_mbuf_used_put_cnt,	\ 		TSEC_TX_NUM_DESC, val)
end_define

begin_define
define|#
directive|define
name|TSEC_EMPTYQ_TX_MBUF
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->tx_mbuf_used_get_cnt == (sc)->tx_mbuf_used_put_cnt)
end_define

begin_comment
comment|/* interface for manage tx tsec_desc */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_DESC_CNT_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 		TSEC_CNT_INIT((sc)->tx_cur_desc_cnt, TSEC_TX_NUM_DESC);		\ 		TSEC_CNT_INIT((sc)->tx_dirty_desc_cnt, TSEC_TX_NUM_DESC);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GET_CUR_TX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&TSEC_GET_GENERIC(sc, tsec_tx_vaddr, tx_cur_desc_cnt,		\ 		TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_GET_DIRTY_TX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&TSEC_GET_GENERIC(sc, tsec_tx_vaddr, tx_dirty_desc_cnt,		\ 		TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_BACK_DIRTY_TX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|TSEC_BACK_GENERIC(sc, tx_dirty_desc_cnt, TSEC_TX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_CUR_DIFF_DIRTY_TX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->tx_cur_desc_cnt != (sc)->tx_dirty_desc_cnt)
end_define

begin_define
define|#
directive|define
name|TSEC_FREE_TX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->tx_cur_desc_cnt< (sc)->tx_dirty_desc_cnt) ?	\ 		((sc)->tx_dirty_desc_cnt - (sc)->tx_cur_desc_cnt - 1)	\ 		:							\ 		(TSEC_TX_NUM_DESC - (sc)->tx_cur_desc_cnt		\ 		+ (sc)->tx_dirty_desc_cnt - 1))
end_define

begin_comment
comment|/* interface for manage rx tsec_desc */
end_comment

begin_define
define|#
directive|define
name|TSEC_RX_DESC_CNT_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 		TSEC_CNT_INIT((sc)->rx_cur_desc_cnt, TSEC_RX_NUM_DESC);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GET_CUR_RX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&TSEC_GET_GENERIC(sc, tsec_rx_vaddr, rx_cur_desc_cnt,	\ 		TSEC_RX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_BACK_CUR_RX_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|TSEC_BACK_GENERIC(sc, rx_cur_desc_cnt, TSEC_RX_NUM_DESC)
end_define

begin_define
define|#
directive|define
name|TSEC_GET_CUR_RX_DESC_CNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|((sc)->rx_cur_desc_cnt)
end_define

begin_comment
comment|/* init all counters (for init only!) */
end_comment

begin_define
define|#
directive|define
name|TSEC_TX_RX_COUNTERS_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {	\ 		TSEC_TX_MAP_CNT_INIT(sc);	\ 		TSEC_TX_MBUF_CNT_INIT(sc);	\ 		TSEC_TX_DESC_CNT_INIT(sc);	\ 		TSEC_RX_DESC_CNT_INIT(sc);	\ } while (0)
end_define

begin_comment
comment|/* read/write bus functions */
end_comment

begin_define
define|#
directive|define
name|TSEC_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_bas.bst, (sc)->sc_bas.bsh, (reg))
end_define

begin_define
define|#
directive|define
name|TSEC_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_bas.bst, (sc)->sc_bas.bsh, (reg), (val))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|tsec_phy_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TSEC_PHY_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&tsec_phy_mtx)
end_define

begin_define
define|#
directive|define
name|TSEC_PHY_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&tsec_phy_mtx)
end_define

begin_define
define|#
directive|define
name|TSEC_PHY_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->phy_bst, (sc)->phy_bsh, (reg))
end_define

begin_define
define|#
directive|define
name|TSEC_PHY_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->phy_bst, (sc)->phy_bsh, (reg), (val))
end_define

begin_comment
comment|/* Lock for transmitter */
end_comment

begin_define
define|#
directive|define
name|TSEC_TRANSMIT_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 		mtx_assert(&(sc)->receive_lock, MA_NOTOWNED);		\ 		mtx_lock(&(sc)->transmit_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_TRANSMIT_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->transmit_lock)
end_define

begin_define
define|#
directive|define
name|TSEC_TRANSMIT_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->transmit_lock, MA_OWNED)
end_define

begin_comment
comment|/* Lock for receiver */
end_comment

begin_define
define|#
directive|define
name|TSEC_RECEIVE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 		mtx_assert(&(sc)->transmit_lock, MA_NOTOWNED);		\ 		mtx_lock(&(sc)->receive_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_RECEIVE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->receive_lock)
end_define

begin_define
define|#
directive|define
name|TSEC_RECEIVE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->receive_lock, MA_OWNED)
end_define

begin_comment
comment|/* Lock for interrupts coalescing */
end_comment

begin_define
define|#
directive|define
name|TSEC_IC_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 		mtx_assert(&(sc)->ic_lock, MA_NOTOWNED);		\ 		mtx_lock(&(sc)->ic_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_IC_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->ic_lock)
end_define

begin_define
define|#
directive|define
name|TSEC_IC_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->ic_lock, MA_OWNED)
end_define

begin_comment
comment|/* Global tsec lock (with all locks) */
end_comment

begin_define
define|#
directive|define
name|TSEC_GLOBAL_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 		if ((mtx_owned(&(sc)->transmit_lock) ? 1 : 0) !=	\ 			(mtx_owned(&(sc)->receive_lock) ? 1 : 0)) {	\ 			panic("tsec deadlock possibility detection!");	\ 		}							\ 		mtx_lock(&(sc)->transmit_lock);				\ 		mtx_lock(&(sc)->receive_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GLOBAL_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|do {		\ 		TSEC_RECEIVE_UNLOCK(sc);	\ 		TSEC_TRANSMIT_UNLOCK(sc);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GLOBAL_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|do {	\ 		TSEC_TRANSMIT_LOCK_ASSERT(sc);	\ 		TSEC_RECEIVE_LOCK_ASSERT(sc);	\ } while (0)
end_define

begin_comment
comment|/* From global to {transmit,receive} */
end_comment

begin_define
define|#
directive|define
name|TSEC_GLOBAL_TO_TRANSMIT_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {	\ 		mtx_unlock(&(sc)->receive_lock);\ } while (0)
end_define

begin_define
define|#
directive|define
name|TSEC_GLOBAL_TO_RECEIVE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {	\ 		mtx_unlock(&(sc)->transmit_lock);\ } while (0)
end_define

begin_struct
struct|struct
name|tsec_desc
block|{
specifier|volatile
name|uint16_t
name|flags
decl_stmt|;
comment|/* descriptor flags */
specifier|volatile
name|uint16_t
name|length
decl_stmt|;
comment|/* buffer length */
specifier|volatile
name|uint32_t
name|bufptr
decl_stmt|;
comment|/* buffer pointer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TSEC_READ_RETRY
value|10000
end_define

begin_define
define|#
directive|define
name|TSEC_READ_DELAY
value|100
end_define

begin_comment
comment|/* Structures and defines for TCP/IP Off-load */
end_comment

begin_struct
struct|struct
name|tsec_tx_fcb
block|{
specifier|volatile
name|uint16_t
name|flags
decl_stmt|;
specifier|volatile
name|uint8_t
name|l4_offset
decl_stmt|;
specifier|volatile
name|uint8_t
name|l3_offset
decl_stmt|;
specifier|volatile
name|uint16_t
name|ph_chsum
decl_stmt|;
specifier|volatile
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tsec_rx_fcb
block|{
specifier|volatile
name|uint16_t
name|flags
decl_stmt|;
specifier|volatile
name|uint8_t
name|rq_index
decl_stmt|;
specifier|volatile
name|uint8_t
name|protocol
decl_stmt|;
specifier|volatile
name|uint16_t
name|unused
decl_stmt|;
specifier|volatile
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TSEC_CHECKSUM_FEATURES
value|(CSUM_IP | CSUM_TCP | CSUM_UDP)
end_define

begin_define
define|#
directive|define
name|TSEC_TX_FCB_IP4
value|TSEC_TX_FCB_L3_IS_IP
end_define

begin_define
define|#
directive|define
name|TSEC_TX_FCB_IP6
value|(TSEC_TX_FCB_L3_IS_IP | TSEC_TX_FCB_L3_IS_IP6)
end_define

begin_define
define|#
directive|define
name|TSEC_TX_FCB_TCP
value|TSEC_TX_FCB_L4_IS_TCP_UDP
end_define

begin_define
define|#
directive|define
name|TSEC_TX_FCB_UDP
value|(TSEC_TX_FCB_L4_IS_TCP_UDP | TSEC_TX_FCB_L4_IS_UDP)
end_define

begin_define
define|#
directive|define
name|TSEC_RX_FCB_IP_CSUM_CHECKED
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& (TSEC_RX_FCB_IP_FOUND | TSEC_RX_FCB_IP6_FOUND |	\ 		TSEC_RX_FCB_IP_CSUM | TSEC_RX_FCB_PARSE_ERROR))			\ 		 == (TSEC_RX_FCB_IP_FOUND | TSEC_RX_FCB_IP_CSUM))
end_define

begin_define
define|#
directive|define
name|TSEC_RX_FCB_TCP_UDP_CSUM_CHECKED
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags& (TSEC_RX_FCB_TCP_UDP_FOUND | TSEC_RX_FCB_TCP_UDP_CSUM	\ 		| TSEC_RX_FCB_PARSE_ERROR))					\ 		== (TSEC_RX_FCB_TCP_UDP_FOUND | TSEC_RX_FCB_TCP_UDP_CSUM))
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|tsec_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|tsec_attach
parameter_list|(
name|struct
name|tsec_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsec_detach
parameter_list|(
name|struct
name|tsec_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsec_error_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsec_receive_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsec_transmit_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsec_miibus_readreg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsec_miibus_writereg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsec_miibus_statchg
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsec_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|int
name|tsec_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tsec_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|void
name|tsec_get_hwaddr
parameter_list|(
name|struct
name|tsec_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_TSEC_H */
end_comment

end_unit

