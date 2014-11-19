begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* Contains descriptor definitions for Osprey */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9300_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9300_DESC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ar9300_freebsd_inc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Osprey Status Descriptor. */
end_comment

begin_struct
struct|struct
name|ar9300_txs
block|{
name|u_int32_t
name|ds_info
decl_stmt|;
name|u_int32_t
name|status1
decl_stmt|;
name|u_int32_t
name|status2
decl_stmt|;
name|u_int32_t
name|status3
decl_stmt|;
name|u_int32_t
name|status4
decl_stmt|;
name|u_int32_t
name|status5
decl_stmt|;
name|u_int32_t
name|status6
decl_stmt|;
name|u_int32_t
name|status7
decl_stmt|;
name|u_int32_t
name|status8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ar9300_rxs
block|{
name|u_int32_t
name|ds_info
decl_stmt|;
name|u_int32_t
name|status1
decl_stmt|;
name|u_int32_t
name|status2
decl_stmt|;
name|u_int32_t
name|status3
decl_stmt|;
name|u_int32_t
name|status4
decl_stmt|;
name|u_int32_t
name|status5
decl_stmt|;
name|u_int32_t
name|status6
decl_stmt|;
name|u_int32_t
name|status7
decl_stmt|;
name|u_int32_t
name|status8
decl_stmt|;
name|u_int32_t
name|status9
decl_stmt|;
name|u_int32_t
name|status10
decl_stmt|;
name|u_int32_t
name|status11
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Transmit Control Descriptor */
end_comment

begin_struct
struct|struct
name|ar9300_txc
block|{
name|u_int32_t
name|ds_info
decl_stmt|;
comment|/* descriptor information */
name|u_int32_t
name|ds_link
decl_stmt|;
comment|/* link pointer */
name|u_int32_t
name|ds_data0
decl_stmt|;
comment|/* data pointer to 1st buffer */
name|u_int32_t
name|ds_ctl3
decl_stmt|;
comment|/* DMA control 3  */
name|u_int32_t
name|ds_data1
decl_stmt|;
comment|/* data pointer to 2nd buffer */
name|u_int32_t
name|ds_ctl5
decl_stmt|;
comment|/* DMA control 5  */
name|u_int32_t
name|ds_data2
decl_stmt|;
comment|/* data pointer to 3rd buffer */
name|u_int32_t
name|ds_ctl7
decl_stmt|;
comment|/* DMA control 7  */
name|u_int32_t
name|ds_data3
decl_stmt|;
comment|/* data pointer to 4th buffer */
name|u_int32_t
name|ds_ctl9
decl_stmt|;
comment|/* DMA control 9  */
name|u_int32_t
name|ds_ctl10
decl_stmt|;
comment|/* DMA control 10 */
name|u_int32_t
name|ds_ctl11
decl_stmt|;
comment|/* DMA control 11 */
name|u_int32_t
name|ds_ctl12
decl_stmt|;
comment|/* DMA control 12 */
name|u_int32_t
name|ds_ctl13
decl_stmt|;
comment|/* DMA control 13 */
name|u_int32_t
name|ds_ctl14
decl_stmt|;
comment|/* DMA control 14 */
name|u_int32_t
name|ds_ctl15
decl_stmt|;
comment|/* DMA control 15 */
name|u_int32_t
name|ds_ctl16
decl_stmt|;
comment|/* DMA control 16 */
name|u_int32_t
name|ds_ctl17
decl_stmt|;
comment|/* DMA control 17 */
name|u_int32_t
name|ds_ctl18
decl_stmt|;
comment|/* DMA control 18 */
name|u_int32_t
name|ds_ctl19
decl_stmt|;
comment|/* DMA control 19 */
name|u_int32_t
name|ds_ctl20
decl_stmt|;
comment|/* DMA control 20 */
name|u_int32_t
name|ds_ctl21
decl_stmt|;
comment|/* DMA control 21 */
name|u_int32_t
name|ds_ctl22
decl_stmt|;
comment|/* DMA control 22 */
name|u_int32_t
name|ds_pad
index|[
literal|9
index|]
decl_stmt|;
comment|/* pad to cache line (128 bytes/32 dwords) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AR9300RXS
parameter_list|(
name|_rxs
parameter_list|)
value|((struct ar9300_rxs *)(_rxs))
end_define

begin_define
define|#
directive|define
name|AR9300TXS
parameter_list|(
name|_txs
parameter_list|)
value|((struct ar9300_txs *)(_txs))
end_define

begin_define
define|#
directive|define
name|AR9300TXC
parameter_list|(
name|_ds
parameter_list|)
value|((struct ar9300_txc *)(_ds))
end_define

begin_define
define|#
directive|define
name|AR9300TXC_CONST
parameter_list|(
name|_ds
parameter_list|)
value|((const struct ar9300_txc *)(_ds))
end_define

begin_comment
comment|/* ds_info */
end_comment

begin_define
define|#
directive|define
name|AR_desc_len
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_rx_priority
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_tx_qcu_num
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|AR_tx_qcu_num_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_ctrl_stat
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_ctrl_stat_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_tx_rx_desc
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_tx_rx_desc_S
value|15
end_define

begin_define
define|#
directive|define
name|AR_desc_id
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|AR_desc_id_S
value|16
end_define

begin_comment
comment|/***********  * TX Desc *  ***********/
end_comment

begin_comment
comment|/* ds_ctl3 */
end_comment

begin_comment
comment|/* ds_ctl5 */
end_comment

begin_comment
comment|/* ds_ctl7 */
end_comment

begin_comment
comment|/* ds_ctl9 */
end_comment

begin_define
define|#
directive|define
name|AR_buf_len
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|AR_buf_len_S
value|16
end_define

begin_comment
comment|/* ds_ctl10 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_desc_id
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|AR_tx_desc_id_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_tx_ptr_chk_sum
value|0x0000ffff
end_define

begin_comment
comment|/* ds_ctl11 */
end_comment

begin_define
define|#
directive|define
name|AR_frame_len
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_virt_more_frag
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_tx_ctl_rsvd00
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AR_low_rx_chain
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AR_tx_clear_retry
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_xmit_power0
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|AR_xmit_power0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_rts_enable
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_veol
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_clr_dest_mask
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf0
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf1
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf2
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf3
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_TxBfSteered
value|0x1e000000
end_define

begin_comment
comment|/* for tx_bf*/
end_comment

begin_define
define|#
directive|define
name|AR_tx_intr_req
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_dest_idx_valid
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_cts_enable
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl12 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_ctl_rsvd02
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|AR_paprd_chain_mask
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|AR_paprd_chain_mask_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_tx_more
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_dest_idx
value|0x000fe000
end_define

begin_define
define|#
directive|define
name|AR_dest_idx_S
value|13
end_define

begin_define
define|#
directive|define
name|AR_frame_type
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|AR_frame_type_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_no_ack
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_insert_ts
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_corrupt_fcs
value|0x04000000
end_define

begin_define
define|#
directive|define
name|AR_ext_only
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AR_ext_and_ctl
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_more_aggr
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_is_aggr
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_more_rifs
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_loc_mode
value|0x00000100
end_define

begin_comment
comment|/* Positioning bit in TX desc */
end_comment

begin_comment
comment|/* ds_ctl13 */
end_comment

begin_define
define|#
directive|define
name|AR_burst_dur
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_burst_dur_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_dur_update_ena
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries0
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries0_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries1
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries1_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries2
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries3
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_data_tries3_S
value|28
end_define

begin_comment
comment|/* ds_ctl14 */
end_comment

begin_define
define|#
directive|define
name|AR_xmit_rate0
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate1
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate1_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate2
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate2_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate3
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_rate3_S
value|24
end_define

begin_comment
comment|/* ds_ctl15 */
end_comment

begin_define
define|#
directive|define
name|AR_packet_dur0
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_packet_dur0_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_qual0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_packet_dur1
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|AR_packet_dur1_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_qual1
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl16 */
end_comment

begin_define
define|#
directive|define
name|AR_packet_dur2
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|AR_packet_dur2_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_qual2
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_packet_dur3
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|AR_packet_dur3_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_qual3
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl17 */
end_comment

begin_define
define|#
directive|define
name|AR_aggr_len
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|AR_aggr_len_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_tx_ctl_rsvd60
value|0x00030000
end_define

begin_define
define|#
directive|define
name|AR_pad_delim
value|0x03fc0000
end_define

begin_define
define|#
directive|define
name|AR_pad_delim_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_encr_type
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|AR_encr_type_S
value|26
end_define

begin_define
define|#
directive|define
name|AR_tx_dc_ap_sta_sel
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_tx_ctl_rsvd61
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR_calibrating
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_ldpc
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl18 */
end_comment

begin_define
define|#
directive|define
name|AR_2040_0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_gi0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_chain_sel0
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|AR_chain_sel0_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_2040_1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_gi1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_chain_sel1
value|0x00000380
end_define

begin_define
define|#
directive|define
name|AR_chain_sel1_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_2040_2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AR_gi2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AR_chain_sel2
value|0x00007000
end_define

begin_define
define|#
directive|define
name|AR_chain_sel2_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_2040_3
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AR_gi3
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_chain_sel3
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|AR_chain_sel3_S
value|17
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_rate
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|AR_rts_cts_rate_S
value|20
end_define

begin_define
define|#
directive|define
name|AR_stbc0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_stbc1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_stbc2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_stbc3
value|0x80000000
end_define

begin_comment
comment|/* ds_ctl19 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_ant0
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|AR_tx_ant_sel0
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_RTS_HTC_TRQ
value|0x10000000
end_define

begin_comment
comment|/* bit 28 for rts_htc_TRQ*/
end_comment

begin_comment
comment|/*for tx_bf*/
end_comment

begin_define
define|#
directive|define
name|AR_not_sounding
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_ness
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR_ness_S
value|30
end_define

begin_comment
comment|/* ds_ctl20 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_ant1
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|AR_xmit_power1
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_power1_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_tx_ant_sel1
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_ness1
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR_ness1_S
value|30
end_define

begin_comment
comment|/* ds_ctl21 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_ant2
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|AR_xmit_power2
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_power2_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_tx_ant_sel2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_ness2
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR_ness2_S
value|30
end_define

begin_comment
comment|/* ds_ctl22 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_ant3
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|AR_xmit_power3
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|AR_xmit_power3_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_tx_ant_sel3
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AR_ness3
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR_ness3_S
value|30
end_define

begin_comment
comment|/*************  * TX Status *  *************/
end_comment

begin_comment
comment|/* ds_status1 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_status_rsvd
value|0x0000ffff
end_define

begin_comment
comment|/* ds_status2 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_rssi_ant00
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant00_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant01
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant01_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant02
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant02_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd00
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|AR_tx_ba_status
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd01
value|0x80000000
end_define

begin_comment
comment|/* ds_status3 */
end_comment

begin_define
define|#
directive|define
name|AR_frm_xmit_ok
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_excessive_retries
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_fifounderrun
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_filtered
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_rts_fail_cnt
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|AR_rts_fail_cnt_S
value|4
end_define

begin_define
define|#
directive|define
name|AR_data_fail_cnt
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|AR_data_fail_cnt_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_virt_retry_cnt
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|AR_virt_retry_cnt_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_tx_delim_underrun
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_tx_data_underrun
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_desc_cfg_err
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_tx_timer_expired
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd10
value|0xfff00000
end_define

begin_comment
comment|/* ds_status7 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_rssi_ant10
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant10_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant11
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant11_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant12
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_ant12_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_combined
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_tx_rssi_combined_S
value|24
end_define

begin_comment
comment|/* ds_status8 */
end_comment

begin_define
define|#
directive|define
name|AR_tx_done
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_seq_num
value|0x00001ffe
end_define

begin_define
define|#
directive|define
name|AR_seq_num_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd80
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|AR_tx_op_exceeded
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd81
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|AR_TXBFStatus
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|AR_TXBFStatus_S
value|18
end_define

begin_define
define|#
directive|define
name|AR_tx_bf_bw_mismatch
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf_stream_miss
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AR_final_tx_idx
value|0x00600000
end_define

begin_define
define|#
directive|define
name|AR_final_tx_idx_S
value|21
end_define

begin_define
define|#
directive|define
name|AR_tx_bf_dest_miss
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AR_tx_bf_expired
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR_power_mgmt
value|0x02000000
end_define

begin_define
define|#
directive|define
name|AR_tx_status_rsvd83
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|AR_tx_tid
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|AR_tx_tid_S
value|28
end_define

begin_define
define|#
directive|define
name|AR_tx_fast_ts
value|0x08000000
end_define

begin_comment
comment|/* 27th bit for locationing */
end_comment

begin_comment
comment|/*************  * Rx Status *  *************/
end_comment

begin_comment
comment|/* ds_status1 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_rssi_ant00
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant00_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant01
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant01_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant02
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant02_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_rx_rate
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_rx_rate_S
value|24
end_define

begin_comment
comment|/* ds_status2 */
end_comment

begin_define
define|#
directive|define
name|AR_data_len
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|AR_data_len_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_rx_more
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AR_num_delim
value|0x003fc000
end_define

begin_define
define|#
directive|define
name|AR_num_delim_S
value|14
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data_S
value|22
end_define

begin_define
define|#
directive|define
name|AR_rx_status_rsvd10
value|0xff800000
end_define

begin_comment
comment|/* ds_status4 */
end_comment

begin_define
define|#
directive|define
name|AR_gi
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_2040
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_parallel40
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_parallel40_S
value|2
end_define

begin_define
define|#
directive|define
name|AR_rx_stbc
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_rx_not_sounding
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_rx_ness
value|0x00000060
end_define

begin_define
define|#
directive|define
name|AR_rx_ness_S
value|5
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data_valid
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data_valid_S
value|7
end_define

begin_define
define|#
directive|define
name|AR_rx_antenna
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|AR_rx_antenna_S
value|8
end_define

begin_comment
comment|/* ds_status5 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_rssi_ant10
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant10_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant11
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant11_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant12
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_ant12_S
value|16
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_combined
value|0xff000000
end_define

begin_define
define|#
directive|define
name|AR_rx_rssi_combined_S
value|24
end_define

begin_comment
comment|/* ds_status6 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_evm0
value|status6
end_define

begin_comment
comment|/* ds_status7 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_evm1
value|status7
end_define

begin_comment
comment|/* ds_status8 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_evm2
value|status8
end_define

begin_comment
comment|/* ds_status9 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_evm3
value|status9
end_define

begin_comment
comment|/* ds_status11 */
end_comment

begin_define
define|#
directive|define
name|AR_rx_done
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_rx_frame_ok
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR_crc_err
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR_decrypt_crc_err
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AR_phyerr
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR_michael_err
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AR_pre_delim_crc_err
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AR_apsd_trig
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AR_rx_key_idx_valid
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR_key_idx
value|0x0000fe00
end_define

begin_define
define|#
directive|define
name|AR_key_idx_S
value|9
end_define

begin_define
define|#
directive|define
name|AR_phy_err_code
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|AR_phy_err_code_S
value|8
end_define

begin_define
define|#
directive|define
name|AR_rx_more_aggr
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR_rx_aggr
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AR_post_delim_crc_err
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AR_rx_status_rsvd71
value|0x01f80000
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data_type
value|0x06000000
end_define

begin_define
define|#
directive|define
name|AR_hw_upload_data_type_S
value|25
end_define

begin_define
define|#
directive|define
name|AR_position_bit
value|0x08000000
end_define

begin_comment
comment|/* positioning bit */
end_comment

begin_define
define|#
directive|define
name|AR_hi_rx_chain
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR_rx_first_aggr
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AR_decrypt_busy_err
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AR_key_miss
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TXCTL_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|11
end_define

begin_define
define|#
directive|define
name|TXCTL_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|12
end_define

begin_define
define|#
directive|define
name|TXSTATUS_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|TXSTATUS_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|7
end_define

begin_define
define|#
directive|define
name|RXCTL_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|RXCTL_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|RXSTATUS_OFFSET
parameter_list|(
name|ah
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|RXSTATUS_NUMWORDS
parameter_list|(
name|ah
parameter_list|)
value|11
end_define

begin_define
define|#
directive|define
name|TXC_INFO
parameter_list|(
name|_qcu
parameter_list|)
value|(ATHEROS_VENDOR_ID<< AR_desc_id_S) \                         | (1<< AR_tx_rx_desc_S) \                         | (1<< AR_ctrl_stat_S) \                         | (_qcu<< AR_tx_qcu_num_S) \                         | (0x17)
end_define

begin_define
define|#
directive|define
name|VALID_KEY_TYPES
define|\
value|((1<< HAL_KEY_TYPE_CLEAR) | (1<< HAL_KEY_TYPE_WEP)|\          (1<< HAL_KEY_TYPE_AES)   | (1<< HAL_KEY_TYPE_TKIP))
end_define

begin_define
define|#
directive|define
name|is_valid_key_type
parameter_list|(
name|_t
parameter_list|)
value|((1<< (_t))& VALID_KEY_TYPES)
end_define

begin_define
define|#
directive|define
name|set_11n_tries
parameter_list|(
name|_series
parameter_list|,
name|_index
parameter_list|)
define|\
value|(SM((_series)[_index].Tries, AR_xmit_data_tries##_index))
end_define

begin_define
define|#
directive|define
name|set_11n_rate
parameter_list|(
name|_series
parameter_list|,
name|_index
parameter_list|)
define|\
value|(SM((_series)[_index].Rate, AR_xmit_rate##_index))
end_define

begin_define
define|#
directive|define
name|set_11n_pkt_dur_rts_cts
parameter_list|(
name|_series
parameter_list|,
name|_index
parameter_list|)
define|\
value|(SM((_series)[_index].PktDuration, AR_packet_dur##_index) |\          ((_series)[_index].RateFlags& HAL_RATESERIES_RTS_CTS   ?\          AR_rts_cts_qual##_index : 0))
end_define

begin_define
define|#
directive|define
name|not_two_stream_rate
parameter_list|(
name|_rate
parameter_list|)
value|(((_rate)>0x8f) || ((_rate)<0x88))
end_define

begin_define
define|#
directive|define
name|set_11n_tx_bf_ldpc
parameter_list|(
name|_series
parameter_list|)
define|\
value|((( not_two_stream_rate((_series)[0].Rate)&& (not_two_stream_rate((_series)[1].Rate)|| \         (!(_series)[1].Tries))&& (not_two_stream_rate((_series)[2].Rate)||(!(_series)[2].Tries)) \&& (not_two_stream_rate((_series)[3].Rate)||(!(_series)[3].Tries)))) \         ? AR_ldpc : 0)
end_define

begin_define
define|#
directive|define
name|set_11n_rate_flags
parameter_list|(
name|_series
parameter_list|,
name|_index
parameter_list|)
define|\
value|((_series)[_index].RateFlags& HAL_RATESERIES_2040 ? AR_2040_##_index : 0) \         |((_series)[_index].RateFlags& HAL_RATESERIES_HALFGI ? AR_gi##_index : 0) \         |((_series)[_index].RateFlags& HAL_RATESERIES_STBC ? AR_stbc##_index : 0) \         |SM((_series)[_index].ChSel, AR_chain_sel##_index)
end_define

begin_define
define|#
directive|define
name|set_11n_tx_power
parameter_list|(
name|_index
parameter_list|,
name|_txpower
parameter_list|)
define|\
value|SM(_txpower, AR_xmit_power##_index)
end_define

begin_define
define|#
directive|define
name|IS_3CHAIN_TX
parameter_list|(
name|_ah
parameter_list|)
value|(AH9300(_ah)->ah_tx_chainmask == 7)
end_define

begin_comment
comment|/*  * Descriptor Access Functions  */
end_comment

begin_comment
comment|/* XXX valid Tx rates will change for 3 stream support */
end_comment

begin_define
define|#
directive|define
name|VALID_PKT_TYPES
define|\
value|((1<<HAL_PKT_TYPE_NORMAL)|(1<<HAL_PKT_TYPE_ATIM)|\          (1<<HAL_PKT_TYPE_PSPOLL)|(1<<HAL_PKT_TYPE_PROBE_RESP)|\          (1<<HAL_PKT_TYPE_BEACON))
end_define

begin_define
define|#
directive|define
name|is_valid_pkt_type
parameter_list|(
name|_t
parameter_list|)
value|((1<<(_t))& VALID_PKT_TYPES)
end_define

begin_define
define|#
directive|define
name|VALID_TX_RATES
define|\
value|((1<<0x0b)|(1<<0x0f)|(1<<0x0a)|(1<<0x0e)|(1<<0x09)|(1<<0x0d)|\          (1<<0x08)|(1<<0x0c)|(1<<0x1b)|(1<<0x1a)|(1<<0x1e)|(1<<0x19)|\          (1<<0x1d)|(1<<0x18)|(1<<0x1c))
end_define

begin_define
define|#
directive|define
name|is_valid_tx_rate
parameter_list|(
name|_r
parameter_list|)
value|((1<<(_r))& VALID_TX_RATES)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* TX common functions */
end_comment

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_update_tx_trig_level
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|HAL_BOOL
name|IncTrigLevel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int16_t
name|ar9300_get_tx_trig_level
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_set_tx_queue_props
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|q
parameter_list|,
specifier|const
name|HAL_TXQ_INFO
modifier|*
name|q_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_get_tx_queue_props
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|q
parameter_list|,
name|HAL_TXQ_INFO
modifier|*
name|q_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar9300_setup_tx_queue
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_TX_QUEUE
name|type
parameter_list|,
specifier|const
name|HAL_TXQ_INFO
modifier|*
name|q_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_release_tx_queue
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_reset_tx_queue
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_get_tx_dp
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_set_tx_dp
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|,
name|u_int32_t
name|txdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_start_tx_dma
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_num_tx_pending
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_stop_tx_dma
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|,
name|u_int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_stop_tx_dma_indv_que
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|q
parameter_list|,
name|u_int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_abort_tx_dma
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_get_tx_intr_queue
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_tx_req_intr_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_fill_tx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|HAL_DMA_ADDR
modifier|*
name|buf_addr
parameter_list|,
name|u_int32_t
modifier|*
name|seg_len
parameter_list|,
name|u_int
name|desc_id
parameter_list|,
name|u_int
name|qcu
parameter_list|,
name|HAL_KEY_TYPE
name|key_type
parameter_list|,
name|HAL_BOOL
name|first_seg
parameter_list|,
name|HAL_BOOL
name|last_seg
parameter_list|,
specifier|const
name|void
modifier|*
name|ds0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_desc_link
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|u_int32_t
name|link
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_get_desc_link_ptr
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|u_int32_t
modifier|*
modifier|*
name|link
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_clear_tx_desc_status
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_SWRETRY
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ar9300_clear_dest_mask
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_proc_tx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_get_raw_tx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_get_tx_rate_code
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|ath_tx_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_calc_tx_airtime
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|ath_tx_status
modifier|*
parameter_list|,
name|HAL_BOOL
name|comp_wastedt
parameter_list|,
name|u_int8_t
name|nbad
parameter_list|,
name|u_int8_t
name|nframes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_setup_tx_status_ring
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_paprd_tx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|int
name|chain_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HAL_STATUS
name|ar9300_is_tx_done
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_tx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|u_int
name|pkt_len
parameter_list|,
name|HAL_PKT_TYPE
name|type
parameter_list|,
name|u_int
name|tx_power
parameter_list|,
name|u_int
name|key_ix
parameter_list|,
name|HAL_KEY_TYPE
name|key_type
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_rx_chainmask
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|rxchainmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_update_loc_ctl_reg
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|int
name|pos_bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* for tx_bf*/
end_comment

begin_define
define|#
directive|define
name|ar9300_set_11n_txbf_cal
parameter_list|(
name|ah
parameter_list|,
name|ds
parameter_list|,
name|cal_pos
parameter_list|,
name|code_rate
parameter_list|,
name|cec
parameter_list|,
name|opt
parameter_list|)
end_define

begin_comment
comment|/* for tx_bf*/
end_comment

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_rate_scenario
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|void
modifier|*
name|lastds
parameter_list|,
name|u_int
name|dur_update_en
parameter_list|,
name|u_int
name|rts_cts_rate
parameter_list|,
name|u_int
name|rts_cts_duration
parameter_list|,
name|HAL_11N_RATE_SERIES
name|series
index|[]
parameter_list|,
name|u_int
name|nseries
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|u_int32_t
name|smartAntenna
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_aggr_first
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|,
name|u_int
name|aggr_len
parameter_list|,
name|u_int
name|num_delims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_aggr_middle
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|,
name|u_int
name|num_delims
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_aggr_last
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_clr_11n_aggr
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_burst_duration
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|,
name|u_int
name|burst_duration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_rifs_burst_middle
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_rifs_burst_last
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_clr_11n_rifs_burst
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_aggr_rifs_burst
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_11n_virtual_more_frag
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
name|ds
parameter_list|,
name|u_int
name|vmf
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|AH_PRIVATE_DIAG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ar9300__cont_tx_mode
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|void
modifier|*
name|ds
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RX common functions */
end_comment

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_get_rx_dp
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ath
parameter_list|,
name|HAL_RX_QUEUE
name|qtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_rx_dp
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
name|rxdp
parameter_list|,
name|HAL_RX_QUEUE
name|qtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_enable_receive
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_stop_dma_receive
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_start_pcu_receive
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|is_scanning
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_stop_pcu_receive
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_multicast_filter
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
name|filter0
parameter_list|,
name|u_int32_t
name|filter1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ar9300_get_rx_filter
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_set_rx_filter
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
name|bits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_set_rx_sel_evm
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
parameter_list|,
name|HAL_BOOL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_BOOL
name|ar9300_set_rx_abort
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_proc_rx_desc
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_get_rx_key_idx
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HAL_STATUS
name|ar9300_proc_rx_desc_fast
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|struct
name|ath_desc
modifier|*
parameter_list|,
name|struct
name|ath_rx_status
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
name|ar9300_promisc_mode
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_read_pktlog_reg
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar9300_write_pktlog_reg
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|HAL_BOOL
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
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
comment|/* _ATH_AR9300_DESC_H_ */
end_comment

end_unit

