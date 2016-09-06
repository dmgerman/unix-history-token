begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_udma_config UDMA Config  * @ingroup group_udma_api  *  UDMA Config API  *  @{  * @file   al_hal_udma_config.h  *  * @brief C Header file for the Universal DMA HAL driver for configuration APIs  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_CONFIG_H__
end_define

begin_include
include|#
directive|include
file|<al_hal_udma.h>
end_include

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* *INDENT-ON* */
comment|/** Scheduling mode */
enum|enum
name|al_udma_sch_mode
block|{
name|STRICT
block|,
comment|/* Strict */
name|SRR
block|,
comment|/* Simple Sound Rubin */
name|DWRR
comment|/* Deficit Weighted Round Rubin */
block|}
enum|;
comment|/** AXI configuration */
struct|struct
name|al_udma_axi_conf
block|{
name|uint32_t
name|axi_timeout
decl_stmt|;
comment|/* Timeout for AXI transactions  */
name|uint8_t
name|arb_promotion
decl_stmt|;
comment|/* arbitration promotion */
name|al_bool
name|swap_8_bytes
decl_stmt|;
comment|/* enable 8 bytes swap instead of 4 bytes */
name|al_bool
name|swap_s2m_data
decl_stmt|;
name|al_bool
name|swap_s2m_desc
decl_stmt|;
name|al_bool
name|swap_m2s_data
decl_stmt|;
name|al_bool
name|swap_m2s_desc
decl_stmt|;
block|}
struct|;
comment|/** UDMA AXI M2S configuration */
struct|struct
name|al_udma_axi_submaster
block|{
name|uint8_t
name|id
decl_stmt|;
comment|/* AXI ID */
name|uint8_t
name|cache_type
decl_stmt|;
name|uint8_t
name|burst
decl_stmt|;
name|uint16_t
name|used_ext
decl_stmt|;
name|uint8_t
name|bus_size
decl_stmt|;
name|uint8_t
name|qos
decl_stmt|;
name|uint8_t
name|prot
decl_stmt|;
name|uint8_t
name|max_beats
decl_stmt|;
block|}
struct|;
comment|/** UDMA AXI M2S configuration */
struct|struct
name|al_udma_m2s_axi_conf
block|{
name|struct
name|al_udma_axi_submaster
name|comp_write
decl_stmt|;
name|struct
name|al_udma_axi_submaster
name|data_read
decl_stmt|;
name|struct
name|al_udma_axi_submaster
name|desc_read
decl_stmt|;
name|al_bool
name|break_on_max_boundary
decl_stmt|;
comment|/* Data read break on max boundary */
name|uint8_t
name|min_axi_beats
decl_stmt|;
comment|/* Minimum burst for writing completion desc. */
name|uint8_t
name|ostand_max_data_read
decl_stmt|;
name|uint8_t
name|ostand_max_desc_read
decl_stmt|;
name|uint8_t
name|ostand_max_comp_req
decl_stmt|;
name|uint8_t
name|ostand_max_comp_write
decl_stmt|;
block|}
struct|;
comment|/** UDMA AXI S2M configuration */
struct|struct
name|al_udma_s2m_axi_conf
block|{
name|struct
name|al_udma_axi_submaster
name|data_write
decl_stmt|;
name|struct
name|al_udma_axi_submaster
name|desc_read
decl_stmt|;
name|struct
name|al_udma_axi_submaster
name|comp_write
decl_stmt|;
name|al_bool
name|break_on_max_boundary
decl_stmt|;
comment|/* Data read break on max boundary */
name|uint8_t
name|min_axi_beats
decl_stmt|;
comment|/* Minimum burst for writing completion desc. */
name|uint8_t
name|ostand_max_data_req
decl_stmt|;
name|uint8_t
name|ostand_max_data_write
decl_stmt|;
name|uint8_t
name|ostand_max_comp_req
decl_stmt|;
name|uint8_t
name|ostand_max_comp_write
decl_stmt|;
name|uint8_t
name|ostand_max_desc_read
decl_stmt|;
name|uint8_t
name|ack_fifo_depth
decl_stmt|;
comment|/* size of the stream application ack fifo */
block|}
struct|;
comment|/** M2S error logging */
struct|struct
name|al_udma_err_log
block|{
name|uint32_t
name|error_status
decl_stmt|;
name|uint32_t
name|header
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
comment|/** M2S max packet size configuration */
struct|struct
name|al_udma_m2s_pkt_len_conf
block|{
name|uint32_t
name|max_pkt_size
decl_stmt|;
name|al_bool
name|encode_64k_as_zero
decl_stmt|;
block|}
struct|;
comment|/** M2S Descriptor Prefetch configuration */
struct|struct
name|al_udma_m2s_desc_pref_conf
block|{
name|uint8_t
name|desc_fifo_depth
decl_stmt|;
name|enum
name|al_udma_sch_mode
name|sch_mode
decl_stmt|;
comment|/* Scheduling mode 					* (either strict or RR) */
name|uint8_t
name|max_desc_per_packet
decl_stmt|;
comment|/* max number of descriptors to 					 * prefetch */
comment|/* in one burst (5b) */
name|uint8_t
name|pref_thr
decl_stmt|;
name|uint8_t
name|min_burst_above_thr
decl_stmt|;
comment|/* min burst size when fifo above 					* pref_thr (4b) 					*/
name|uint8_t
name|min_burst_below_thr
decl_stmt|;
comment|/* min burst size when fifo below 					* pref_thr (4b) 					*/
name|uint8_t
name|max_pkt_limit
decl_stmt|;
comment|/* maximum number of packets in the data 					* read FIFO, defined based on header 					* FIFO size 					*/
name|uint16_t
name|data_fifo_depth
decl_stmt|;
comment|/* maximum number of data beats in the 					* data read FIFO, 					* defined based on header FIFO size 					*/
block|}
struct|;
comment|/** S2M Descriptor Prefetch configuration */
struct|struct
name|al_udma_s2m_desc_pref_conf
block|{
name|uint8_t
name|desc_fifo_depth
decl_stmt|;
name|enum
name|al_udma_sch_mode
name|sch_mode
decl_stmt|;
comment|/* Scheduling mode * 					* (either strict or RR) 					*/
name|al_bool
name|q_promotion
decl_stmt|;
comment|/* enable promotion */
name|al_bool
name|force_promotion
decl_stmt|;
comment|/* force promotion  */
name|al_bool
name|en_pref_prediction
decl_stmt|;
comment|/* enable prefetch prediction */
name|uint8_t
name|promotion_th
decl_stmt|;
comment|/* Threshold for queue promotion */
name|uint8_t
name|pref_thr
decl_stmt|;
name|uint8_t
name|min_burst_above_thr
decl_stmt|;
comment|/* min burst size when fifo above 	 	 	 	 	 * pref_thr (4b) 	 	 	 	 	 */
name|uint8_t
name|min_burst_below_thr
decl_stmt|;
comment|/* min burst size when fifo below 	 	 	 	 	 * pref_thr (4b) 	 	 	 	 	 */
name|uint8_t
name|a_full_thr
decl_stmt|;
comment|/* almost full threshold */
block|}
struct|;
comment|/** S2M Data write configuration */
struct|struct
name|al_udma_s2m_data_write_conf
block|{
name|uint16_t
name|data_fifo_depth
decl_stmt|;
comment|/* maximum number of data beats in the 					 * data write FIFO, defined based on 					 * header FIFO size 					 */
name|uint8_t
name|max_pkt_limit
decl_stmt|;
comment|/* maximum number of packets in the 					* data write FIFO,defined based on 					* header FIFO size 					*/
name|uint8_t
name|fifo_margin
decl_stmt|;
name|uint32_t
name|desc_wait_timer
decl_stmt|;
comment|/* waiting time for the host to write 					* new descriptor to the queue 					* (for the current packet in process) 					*/
name|uint32_t
name|flags
decl_stmt|;
comment|/* bitwise of flags of s2m 					 * data_cfg_2 register 					 */
block|}
struct|;
comment|/** S2M Completion configuration */
struct|struct
name|al_udma_s2m_completion_conf
block|{
name|uint8_t
name|desc_size
decl_stmt|;
comment|/* Size of completion descriptor 					 * in words 					 */
name|al_bool
name|cnt_words
decl_stmt|;
comment|/* Completion fifo in use counter: 	 	 	 	 	 * AL_TRUE words, AL_FALS descriptors 	 	 	 	 	 */
name|al_bool
name|q_promotion
decl_stmt|;
comment|/* Enable promotion of the current 					 * unack in progress */
comment|/* in the completion write scheduler */
name|al_bool
name|force_rr
decl_stmt|;
comment|/* force RR arbitration in the 					*  scheduler 					*/
comment|//	uint8_t ack_fifo_depth;		/* size of the stream application ack fifo */
name|uint8_t
name|q_free_min
decl_stmt|;
comment|/* minimum number of free completion 					 * entries 					 */
comment|/* to qualify for promotion */
name|uint16_t
name|comp_fifo_depth
decl_stmt|;
comment|/* Size of completion fifo in words */
name|uint16_t
name|unack_fifo_depth
decl_stmt|;
comment|/* Size of unacked fifo in descs */
name|uint32_t
name|timeout
decl_stmt|;
comment|/* Ack timout from stream interface */
block|}
struct|;
comment|/** M2S UDMA DWRR configuration */
struct|struct
name|al_udma_m2s_dwrr_conf
block|{
name|al_bool
name|enable_dwrr
decl_stmt|;
name|uint8_t
name|inc_factor
decl_stmt|;
name|uint8_t
name|weight
decl_stmt|;
name|al_bool
name|pkt_mode
decl_stmt|;
name|uint32_t
name|deficit_init_val
decl_stmt|;
block|}
struct|;
comment|/** M2S DMA Rate Limitation mode */
struct|struct
name|al_udma_m2s_rlimit_mode
block|{
name|al_bool
name|pkt_mode_en
decl_stmt|;
name|uint16_t
name|short_cycle_sz
decl_stmt|;
name|uint32_t
name|token_init_val
decl_stmt|;
block|}
struct|;
comment|/** M2S Stream/Q Rate Limitation */
struct|struct
name|al_udma_m2s_rlimit_cfg
block|{
name|uint32_t
name|max_burst_sz
decl_stmt|;
comment|/* maximum number of accumulated bytes in the 				 * token counter 				 */
name|uint16_t
name|long_cycle_sz
decl_stmt|;
comment|/* number of short cycles between token fill */
name|uint32_t
name|long_cycle
decl_stmt|;
comment|/* number of bits to add in each long cycle */
name|uint32_t
name|short_cycle
decl_stmt|;
comment|/* number of bits to add in each cycle */
name|uint32_t
name|mask
decl_stmt|;
comment|/* mask the different types of rate limiters */
block|}
struct|;
enum|enum
name|al_udma_m2s_rlimit_action
block|{
name|AL_UDMA_STRM_RLIMIT_ENABLE
block|,
name|AL_UDMA_STRM_RLIMIT_PAUSE
block|,
name|AL_UDMA_STRM_RLIMIT_RESET
block|}
enum|;
comment|/** M2S UDMA Q scheduling configuration */
struct|struct
name|al_udma_m2s_q_dwrr_conf
block|{
name|uint32_t
name|max_deficit_cnt_sz
decl_stmt|;
comment|/*maximum number of accumulated bytes 					* in the deficit counter 					*/
name|al_bool
name|strict
decl_stmt|;
comment|/* bypass DWRR */
name|uint8_t
name|axi_qos
decl_stmt|;
name|uint16_t
name|q_qos
decl_stmt|;
name|uint8_t
name|weight
decl_stmt|;
block|}
struct|;
comment|/** M2S UDMA / UDMA Q scheduling configuration */
struct|struct
name|al_udma_m2s_sc
block|{
name|enum
name|al_udma_sch_mode
name|sch_mode
decl_stmt|;
comment|/* Scheduling Mode */
name|struct
name|al_udma_m2s_dwrr_conf
name|dwrr
decl_stmt|;
comment|/* DWRR configuration */
block|}
struct|;
comment|/** UDMA / UDMA Q rate limitation configuration */
struct|struct
name|al_udma_m2s_rlimit
block|{
name|struct
name|al_udma_m2s_rlimit_mode
name|rlimit_mode
decl_stmt|;
comment|/* rate limitation enablers */
if|#
directive|if
literal|0
block|struct al_udma_tkn_bkt_conf token_bkt;
comment|/* Token Bucket configuration */
endif|#
directive|endif
block|}
struct|;
comment|/** UDMA Data read configuration */
struct|struct
name|al_udma_m2s_data_rd_conf
block|{
name|uint8_t
name|max_rd_d_beats
decl_stmt|;
comment|/* max burst size for reading data 					 * (in AXI beats-128b) (5b) 					 */
name|uint8_t
name|max_rd_d_out_req
decl_stmt|;
comment|/* max number of outstanding data 					 * read requests (6b) 					 */
name|uint16_t
name|max_rd_d_out_beats
decl_stmt|;
comment|/* max num. of data read beats (10b) */
block|}
struct|;
comment|/** M2S UDMA completion and application timeouts */
struct|struct
name|al_udma_m2s_comp_timeouts
block|{
name|enum
name|al_udma_sch_mode
name|sch_mode
decl_stmt|;
comment|/* Scheduling mode 					 * (either strict or RR) 					 */
name|al_bool
name|enable_q_promotion
decl_stmt|;
name|uint8_t
name|unack_fifo_depth
decl_stmt|;
comment|/* unacked desc fifo size */
name|uint8_t
name|comp_fifo_depth
decl_stmt|;
comment|/* desc fifo size */
name|uint32_t
name|coal_timeout
decl_stmt|;
comment|/* (24b) */
name|uint32_t
name|app_timeout
decl_stmt|;
comment|/* (24b) */
block|}
struct|;
comment|/** S2M UDMA per queue completion configuration */
struct|struct
name|al_udma_s2m_q_comp_conf
block|{
name|al_bool
name|dis_comp_coal
decl_stmt|;
comment|/* disable completion coalescing */
name|al_bool
name|en_comp_ring_update
decl_stmt|;
comment|/* enable writing completion descs */
name|uint32_t
name|comp_timer
decl_stmt|;
comment|/* completion coalescing timer */
name|al_bool
name|en_hdr_split
decl_stmt|;
comment|/* enable header split */
name|al_bool
name|force_hdr_split
decl_stmt|;
comment|/* force header split */
name|uint16_t
name|hdr_split_size
decl_stmt|;
comment|/* size used for the header split */
name|uint8_t
name|q_qos
decl_stmt|;
comment|/* queue QoS */
block|}
struct|;
comment|/** UDMA per queue VMID control configuration */
struct|struct
name|al_udma_gen_vmid_q_conf
block|{
comment|/* Enable usage of the VMID per queue according to 'vmid' */
name|al_bool
name|queue_en
decl_stmt|;
comment|/* Enable usage of the VMID from the descriptor buffer address 63:48 */
name|al_bool
name|desc_en
decl_stmt|;
comment|/* VMID to be applied when 'queue_en' is asserted */
name|uint16_t
name|vmid
decl_stmt|;
comment|/* VMADDR to be applied to msbs when 'desc_en' is asserted. 	 * Relevant for revisions>= AL_UDMA_REV_ID_REV2 */
name|uint16_t
name|vmaddr
decl_stmt|;
block|}
struct|;
comment|/** UDMA VMID control configuration */
struct|struct
name|al_udma_gen_vmid_conf
block|{
comment|/* TX queue configuration */
name|struct
name|al_udma_gen_vmid_q_conf
name|tx_q_conf
index|[
name|DMA_MAX_Q
index|]
decl_stmt|;
comment|/* RX queue configuration */
name|struct
name|al_udma_gen_vmid_q_conf
name|rx_q_conf
index|[
name|DMA_MAX_Q
index|]
decl_stmt|;
block|}
struct|;
comment|/** UDMA VMID MSIX control configuration */
struct|struct
name|al_udma_gen_vmid_msix_conf
block|{
comment|/* Enable write to all VMID_n registers in the MSI-X Controller */
name|al_bool
name|access_en
decl_stmt|;
comment|/* use VMID_n [7:0] from MSI-X Controller for MSI-X message */
name|al_bool
name|sel
decl_stmt|;
block|}
struct|;
comment|/** UDMA per Tx queue advanced VMID control configuration */
struct|struct
name|al_udma_gen_vmid_advanced_tx_q_conf
block|{
comment|/********************************************************************** 	 * Tx Data VMID 	 **********************************************************************/
comment|/* Tx data VMID enable */
name|al_bool
name|tx_q_data_vmid_en
decl_stmt|;
comment|/* 	 * For Tx data reads, replacement bits for the original address. 	 * The number of bits replaced is determined according to 	 * 'tx_q_addr_hi_sel' 	 */
name|unsigned
name|int
name|tx_q_addr_hi
decl_stmt|;
comment|/* 	 * For Tx data reads, 6 bits serving the number of bits taken from the 	 * extra register on account of bits coming from the original address 	 * field. 	 * When 'tx_q_addr_hi_sel'=32 all of 'tx_q_addr_hi' will be taken. 	 * When 'tx_q_addr_hi_sel'=0 none of it will be taken, and when any 	 * value in between, it will start from the MSB bit and sweep down as 	 * many bits as needed. For example if 'tx_q_addr_hi_sel'=8, the final 	 * address [63:56] will carry 'tx_q_addr_hi'[31:24] while [55:32] will 	 * carry the original buffer address[55:32]. 	 */
name|unsigned
name|int
name|tx_q_addr_hi_sel
decl_stmt|;
comment|/* 	 * Tx data read VMID 	 * Masked per bit with 'tx_q_data_vmid_mask' 	 */
name|unsigned
name|int
name|tx_q_data_vmid
decl_stmt|;
comment|/* 	 * Tx data read VMID mask 	 * Each '1' selects from the buffer address, each '0' selects from 	 * 'tx_q_data_vmid' 	 */
name|unsigned
name|int
name|tx_q_data_vmid_mask
decl_stmt|;
comment|/********************************************************************** 	 * Tx prefetch VMID 	 **********************************************************************/
comment|/* Tx prefetch VMID enable */
name|al_bool
name|tx_q_prefetch_vmid_en
decl_stmt|;
comment|/* Tx prefetch VMID */
name|unsigned
name|int
name|tx_q_prefetch_vmid
decl_stmt|;
comment|/********************************************************************** 	 * Tx completion VMID 	 **********************************************************************/
comment|/* Tx completion VMID enable */
name|al_bool
name|tx_q_compl_vmid_en
decl_stmt|;
comment|/* Tx completion VMID */
name|unsigned
name|int
name|tx_q_compl_vmid
decl_stmt|;
block|}
struct|;
comment|/** UDMA per Rx queue advanced VMID control configuration */
struct|struct
name|al_udma_gen_vmid_advanced_rx_q_conf
block|{
comment|/********************************************************************** 	 * Rx Data VMID 	 **********************************************************************/
comment|/* Rx data VMID enable */
name|al_bool
name|rx_q_data_vmid_en
decl_stmt|;
comment|/* 	 * For Rx data writes, replacement bits for the original address. 	 * The number of bits replaced is determined according to 	 * 'rx_q_addr_hi_sel' 	 */
name|unsigned
name|int
name|rx_q_addr_hi
decl_stmt|;
comment|/* 	 * For Rx data writes, 6 bits serving the number of bits taken from the 	 * extra register on account of bits coming from the original address 	 * field. 	 */
name|unsigned
name|int
name|rx_q_addr_hi_sel
decl_stmt|;
comment|/* 	 * Rx data write VMID 	 * Masked per bit with 'rx_q_data_vmid_mask' 	 */
name|unsigned
name|int
name|rx_q_data_vmid
decl_stmt|;
comment|/* Rx data write VMID mask */
name|unsigned
name|int
name|rx_q_data_vmid_mask
decl_stmt|;
comment|/********************************************************************** 	 * Rx Data Buffer 2 VMID 	 **********************************************************************/
comment|/* Rx data buff2 VMID enable */
name|al_bool
name|rx_q_data_buff2_vmid_en
decl_stmt|;
comment|/* 	 * For Rx data buff2 writes, replacement bits for the original address. 	 * The number of bits replaced is determined according to 	 * 'rx_q_data_buff2_addr_hi_sel' 	 */
name|unsigned
name|int
name|rx_q_data_buff2_addr_hi
decl_stmt|;
comment|/* 	 * For Rx data buff2 writes, 6 bits serving the number of bits taken 	 * from the extra register on account of bits coming from the original 	 * address field. 	 */
name|unsigned
name|int
name|rx_q_data_buff2_addr_hi_sel
decl_stmt|;
comment|/* 	 * Rx data buff2 write VMID 	 * Masked per bit with 'rx_q_data_buff2_mask' 	 */
name|unsigned
name|int
name|rx_q_data_buff2_vmid
decl_stmt|;
comment|/* Rx data buff2 write VMID mask */
name|unsigned
name|int
name|rx_q_data_buff2_mask
decl_stmt|;
comment|/********************************************************************** 	 * Rx DDP VMID 	 **********************************************************************/
comment|/* Rx DDP write VMID enable */
name|al_bool
name|rx_q_ddp_vmid_en
decl_stmt|;
comment|/* 	 * For Rx DDP writes, replacement bits for the original address. 	 * The number of bits replaced is determined according to 	 * 'rx_q_ddp_addr_hi_sel' 	 */
name|unsigned
name|int
name|rx_q_ddp_addr_hi
decl_stmt|;
comment|/* 	 * For Rx DDP writes, 6 bits serving the number of bits taken from the 	 * extra register on account of bits coming from the original address 	 * field. 	 */
name|unsigned
name|int
name|rx_q_ddp_addr_hi_sel
decl_stmt|;
comment|/* 	 * Rx DDP write VMID 	 * Masked per bit with 'rx_q_ddp_mask' 	 */
name|unsigned
name|int
name|rx_q_ddp_vmid
decl_stmt|;
comment|/* Rx DDP write VMID mask */
name|unsigned
name|int
name|rx_q_ddp_mask
decl_stmt|;
comment|/********************************************************************** 	 * Rx prefetch VMID 	 **********************************************************************/
comment|/* Rx prefetch VMID enable */
name|al_bool
name|rx_q_prefetch_vmid_en
decl_stmt|;
comment|/* Rx prefetch VMID */
name|unsigned
name|int
name|rx_q_prefetch_vmid
decl_stmt|;
comment|/********************************************************************** 	 * Rx completion VMID 	 **********************************************************************/
comment|/* Rx completion VMID enable */
name|al_bool
name|rx_q_compl_vmid_en
decl_stmt|;
comment|/* Rx completion VMID */
name|unsigned
name|int
name|rx_q_compl_vmid
decl_stmt|;
block|}
struct|;
comment|/**  * Header split, buffer 2 per queue configuration  * When header split is enabled, Buffer_2 is used as an address for the header  * data. Buffer_2 is defined as 32-bits in the RX descriptor and it is defined  * that the MSB ([63:32]) of Buffer_1 is used as address [63:32] for the header  * address.  */
struct|struct
name|al_udma_gen_hdr_split_buff2_q_conf
block|{
comment|/* 	 * MSB of the 64-bit address (bits [63:32]) that can be used for header 	 * split for this queue 	 */
name|unsigned
name|int
name|addr_msb
decl_stmt|;
comment|/* 	 * Determine how to select the MSB (bits [63:32]) of the address when 	 * header split is enabled (4 bits, one per byte) 	 * - Bits [3:0]: 	 *	[0] â selector for bits [39:32] 	 *	[1] â selector for bits [47:40] 	 *	[2] â selector for bits [55:48] 	 *	[3] â selector for bits [63:55] 	 * - Bit value: 	 *	0 â Use Buffer_1 (legacy operation) 	 *	1 â Use the queue configuration 'addr_msb' 	 */
name|unsigned
name|int
name|add_msb_sel
decl_stmt|;
block|}
struct|;
comment|/* Report Error - to be used for abort */
name|void
name|al_udma_err_report
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|)
function_decl|;
comment|/* Statistics - TBD */
name|void
name|al_udma_stats_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|)
function_decl|;
comment|/* Misc configurations */
comment|/* Configure AXI configuration */
name|int
name|al_udma_axi_set
parameter_list|(
name|struct
name|udma_gen_axi
modifier|*
name|axi_regs
parameter_list|,
name|struct
name|al_udma_axi_conf
modifier|*
name|axi
parameter_list|)
function_decl|;
comment|/* Configure UDMA AXI M2S configuration */
name|int
name|al_udma_m2s_axi_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_axi_conf
modifier|*
name|axi_m2s
parameter_list|)
function_decl|;
comment|/* Configure UDMA AXI S2M configuration */
name|int
name|al_udma_s2m_axi_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_s2m_axi_conf
modifier|*
name|axi_s2m
parameter_list|)
function_decl|;
comment|/* Configure M2S packet len */
name|int
name|al_udma_m2s_packet_size_cfg_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_pkt_len_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* Configure M2S UDMA descriptor prefetch */
name|int
name|al_udma_m2s_pref_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_desc_pref_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_pref_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_desc_pref_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* set m2s packet's max descriptors (including meta descriptors) */
define|#
directive|define
name|AL_UDMA_M2S_MAX_ALLOWED_DESCS_PER_PACKET
value|31
name|int
name|al_udma_m2s_max_descs_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint8_t
name|max_descs
parameter_list|)
function_decl|;
comment|/* set s2m packets' max descriptors */
define|#
directive|define
name|AL_UDMA_S2M_MAX_ALLOWED_DESCS_PER_PACKET
value|31
name|int
name|al_udma_s2m_max_descs_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint8_t
name|max_descs
parameter_list|)
function_decl|;
comment|/* Configure S2M UDMA descriptor prefetch */
name|int
name|al_udma_s2m_pref_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_s2m_desc_pref_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_pref_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_desc_pref_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* Configure S2M UDMA data write */
name|int
name|al_udma_s2m_data_write_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_s2m_data_write_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* Configure the s2m full line write feature */
name|int
name|al_udma_s2m_full_line_write_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|umda
parameter_list|,
name|al_bool
name|enable
parameter_list|)
function_decl|;
comment|/* Configure S2M UDMA completion */
name|int
name|al_udma_s2m_completion_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_s2m_completion_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* Configure the M2S UDMA scheduling mode */
name|int
name|al_udma_m2s_sc_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_dwrr_conf
modifier|*
name|sched
parameter_list|)
function_decl|;
comment|/* Configure the M2S UDMA rate limitation */
name|int
name|al_udma_m2s_rlimit_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_rlimit_mode
modifier|*
name|mode
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_rlimit_reset
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|)
function_decl|;
comment|/* Configure the M2S Stream rate limitation */
name|int
name|al_udma_m2s_strm_rlimit_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_rlimit_cfg
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_strm_rlimit_act
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|enum
name|al_udma_m2s_rlimit_action
name|act
parameter_list|)
function_decl|;
comment|/* Configure the M2S UDMA Q rate limitation */
name|int
name|al_udma_m2s_q_rlimit_set
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|struct
name|al_udma_m2s_rlimit_cfg
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_q_rlimit_act
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|enum
name|al_udma_m2s_rlimit_action
name|act
parameter_list|)
function_decl|;
comment|/* Configure the M2S UDMA Q scheduling mode */
name|int
name|al_udma_m2s_q_sc_set
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|struct
name|al_udma_m2s_q_dwrr_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_q_sc_pause
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|al_bool
name|set
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_q_sc_reset
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|)
function_decl|;
comment|/* M2S UDMA completion and application timeouts */
name|int
name|al_udma_m2s_comp_timeouts_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_comp_timeouts
modifier|*
name|conf
parameter_list|)
function_decl|;
name|int
name|al_udma_m2s_comp_timeouts_get
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|struct
name|al_udma_m2s_comp_timeouts
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* UDMA get revision */
specifier|static
name|INLINE
name|unsigned
name|int
name|al_udma_get_revision
parameter_list|(
name|struct
name|unit_regs
name|__iomem
modifier|*
name|unit_regs
parameter_list|)
block|{
return|return
operator|(
name|al_reg_read32
argument_list|(
operator|&
name|unit_regs
operator|->
name|gen
operator|.
name|dma_misc
operator|.
name|revision
argument_list|)
operator|&
name|UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_MASK
operator|)
operator|>>
name|UDMA_GEN_DMA_MISC_REVISION_PROGRAMMING_ID_SHIFT
return|;
block|}
comment|/**  * S2M UDMA Configure the expected behavior of Rx/S2M UDMA when there are no Rx Descriptors.  *  * @param udma  * @param drop_packet when set to true, the UDMA will drop packet.  * @param gen_interrupt when set to true, the UDMA will generate  *        no_desc_hint interrupt when a packet received and the UDMA  *	  doesn't find enough free descriptors for it.  * @param wait_for_desc_timeout timeout in SB cycles to wait for new  *	  descriptors before dropping the packets.  *	  Notes:  *		- The hint interrupt is raised immediately without waiting  *		for new descs.  *		- value 0 means wait for ever.  *  * Notes:  * - When get_interrupt is set, the API won't program the iofic to unmask this  * interrupt, in this case the callee should take care for doing that unmask  * using the al_udma_iofic_config() API.  *  * - The hardware's default configuration is: no drop packet, generate hint  * interrupt.  * - This API must be called once and before enabling the UDMA  *  * @return 0 if no error found.  */
name|int
name|al_udma_s2m_no_desc_cfg_set
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|al_bool
name|drop_packet
parameter_list|,
name|al_bool
name|gen_interrupt
parameter_list|,
name|uint32_t
name|wait_for_desc_timeout
parameter_list|)
function_decl|;
comment|/**  * S2M UDMA configure a queue's completion update  *  * @param q_udma  * @param enable set to true to enable completion update  *  * completion update better be disabled for tx queues as those descriptors  * doesn't carry useful information, thus disabling it saves DMA accesses.  *  * @return 0 if no error found.  */
name|int
name|al_udma_s2m_q_compl_updade_config
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|al_bool
name|enable
parameter_list|)
function_decl|;
comment|/**  * S2M UDMA configure a queue's completion descriptors coalescing  *  * @param q_udma  * @param enable set to true to enable completion coalescing  * @param coal_timeout in South Bridge cycles.  *  * @return 0 if no error found.  */
name|int
name|al_udma_s2m_q_compl_coal_config
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|al_bool
name|enable
parameter_list|,
name|uint32_t
name|coal_timeout
parameter_list|)
function_decl|;
comment|/**  * S2M UDMA configure completion descriptors write burst parameters  *  * @param udma  * @param burst_size completion descriptors write burst size in bytes.  *  * @return 0 if no error found.  */
name|int
name|al_udma_s2m_compl_desc_burst_config
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint16_t
name|burst_size
parameter_list|)
function_decl|;
comment|/**  * S2M UDMA configure a queue's completion header split  *  * @param q_udma  * @param enable set to true to enable completion header split  * @param force_hdr_split the header split length will be taken from the queue configuration  * @param hdr_len header split length.  *  * @return 0 if no error found.  */
name|int
name|al_udma_s2m_q_compl_hdr_split_config
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|al_bool
name|enable
parameter_list|,
name|al_bool
name|force_hdr_split
parameter_list|,
name|uint32_t
name|hdr_len
parameter_list|)
function_decl|;
comment|/* S2M UDMA per queue completion configuration */
name|int
name|al_udma_s2m_q_comp_set
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|udma_q
parameter_list|,
name|struct
name|al_udma_s2m_q_comp_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/** UDMA VMID control configuration */
name|void
name|al_udma_gen_vmid_conf_set
parameter_list|(
name|struct
name|unit_regs
name|__iomem
modifier|*
name|unit_regs
parameter_list|,
name|struct
name|al_udma_gen_vmid_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/** UDMA VMID MSIX control configuration */
name|void
name|al_udma_gen_vmid_msix_conf_set
parameter_list|(
name|struct
name|unit_regs
name|__iomem
modifier|*
name|unit_regs
parameter_list|,
name|struct
name|al_udma_gen_vmid_msix_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/** UDMA VMID control advanced Tx queue configuration */
name|void
name|al_udma_gen_vmid_advanced_tx_q_conf
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|q
parameter_list|,
name|struct
name|al_udma_gen_vmid_advanced_tx_q_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/** UDMA VMID control advanced Rx queue configuration */
name|void
name|al_udma_gen_vmid_advanced_rx_q_conf
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|q
parameter_list|,
name|struct
name|al_udma_gen_vmid_advanced_rx_q_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/** UDMA header split buffer 2 Rx queue configuration */
name|void
name|al_udma_gen_hdr_split_buff2_rx_q_conf
parameter_list|(
name|struct
name|al_udma_q
modifier|*
name|q
parameter_list|,
name|struct
name|al_udma_gen_hdr_split_buff2_q_conf
modifier|*
name|conf
parameter_list|)
function_decl|;
comment|/* *INDENT-OFF* */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_comment
comment|/** @} end of UDMA config group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_UDMA_CONFIG_H__ */
end_comment

end_unit

