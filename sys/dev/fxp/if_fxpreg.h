begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, David Greenman  * Copyright (c) 2001 Jonathan Lemon<jlemon@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|FXP_VENDORID_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|FXP_PCI_MMBA
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_PCI_IOBA
value|0x14
end_define

begin_comment
comment|/*  * Control/status registers.  */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_SCB_RUSCUS
value|0
end_define

begin_comment
comment|/* scb_rus/scb_cus (1 byte) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_SCB_STATACK
value|1
end_define

begin_comment
comment|/* scb_statack (1 byte) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_SCB_COMMAND
value|2
end_define

begin_comment
comment|/* scb_command (1 byte) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_SCB_INTRCNTL
value|3
end_define

begin_comment
comment|/* scb_intrcntl (1 byte) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_SCB_GENERAL
value|4
end_define

begin_comment
comment|/* scb_general (4 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_PORT
value|8
end_define

begin_comment
comment|/* port (4 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_FLASHCONTROL
value|12
end_define

begin_comment
comment|/* flash control (2 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_EEPROMCONTROL
value|14
end_define

begin_comment
comment|/* eeprom control (2 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_MDICONTROL
value|16
end_define

begin_comment
comment|/* mdi control (4 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_FLOWCONTROL
value|0x19
end_define

begin_comment
comment|/* flow control (2 bytes) */
end_comment

begin_define
define|#
directive|define
name|FXP_CSR_GENCONTROL
value|0x1C
end_define

begin_comment
comment|/* general control (1 byte) */
end_comment

begin_comment
comment|/*  * FOR REFERENCE ONLY, the old definition of FXP_CSR_SCB_RUSCUS:  *  *	volatile u_int8_t	:2,  *				scb_rus:4,  *				scb_cus:2;  */
end_comment

begin_define
define|#
directive|define
name|FXP_PORT_SOFTWARE_RESET
value|0
end_define

begin_define
define|#
directive|define
name|FXP_PORT_SELFTEST
value|1
end_define

begin_define
define|#
directive|define
name|FXP_PORT_SELECTIVE_RESET
value|2
end_define

begin_define
define|#
directive|define
name|FXP_PORT_DUMP
value|3
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_SUSPENDED
value|1
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_NORESOURCES
value|2
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_READY
value|4
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_SUSP_NORBDS
value|9
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_NORES_NORBDS
value|10
end_define

begin_define
define|#
directive|define
name|FXP_SCB_RUS_READY_NORBDS
value|12
end_define

begin_define
define|#
directive|define
name|FXP_SCB_CUS_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|FXP_SCB_CUS_SUSPENDED
value|1
end_define

begin_define
define|#
directive|define
name|FXP_SCB_CUS_ACTIVE
value|2
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTR_DISABLE
value|0x01
end_define

begin_comment
comment|/* Disable all interrupts */
end_comment

begin_define
define|#
directive|define
name|FXP_SCB_INTR_SWI
value|0x02
end_define

begin_comment
comment|/* Generate SWI */
end_comment

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_FCP
value|0x04
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_ER
value|0x08
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_RNR
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_CNA
value|0x20
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_FR
value|0x40
end_define

begin_define
define|#
directive|define
name|FXP_SCB_INTMASK_CXTNO
value|0x80
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_FCP
value|0x01
end_define

begin_comment
comment|/* Flow Control Pause */
end_comment

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_ER
value|0x02
end_define

begin_comment
comment|/* Early Receive */
end_comment

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_SWI
value|0x04
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_MDI
value|0x08
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_RNR
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_CNA
value|0x20
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_FR
value|0x40
end_define

begin_define
define|#
directive|define
name|FXP_SCB_STATACK_CXTNO
value|0x80
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_START
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_RESUME
value|0x20
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_DUMP_ADR
value|0x40
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_DUMP
value|0x50
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_BASE
value|0x60
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_CU_DUMPRESET
value|0x70
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_NOP
value|0
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_START
value|1
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_RESUME
value|2
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_ABORT
value|4
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_LOADHDS
value|5
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_BASE
value|6
end_define

begin_define
define|#
directive|define
name|FXP_SCB_COMMAND_RU_RBDRESUME
value|7
end_define

begin_comment
comment|/*  * Command block definitions  */
end_comment

begin_struct
struct|struct
name|fxp_cb_nop
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fxp_cb_ias
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
name|u_int8_t
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I hate bit-fields :-( */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|__FXP_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a, b
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a, b, c
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a, b, c, d
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|a, b, c, d, e
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD6
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|a, b, c, d, e, f
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD7
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|a, b, c, d, e, f, g
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
value|a, b, c, d, e, f, g, h
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FXP_BITFIELD2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|c, b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|d, c, b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|e, d, c, b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD6
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|f, e, d, c, b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD7
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|)
value|g, f, e, d, c, b, a
end_define

begin_define
define|#
directive|define
name|__FXP_BITFIELD8
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|)
value|h, g, f, e, d, c, b, a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|fxp_cb_config
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
comment|/* Bytes 0 - 21 -- common to all i8255x */
name|u_int
name|__FXP_BITFIELD2
argument_list|(
name|byte_count
operator|:
literal|6
argument_list|, :
literal|2
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD3
argument_list|(
name|rx_fifo_limit
operator|:
literal|4
argument_list|,
name|tx_fifo_limit
operator|:
literal|3
argument_list|, :
literal|1
argument_list|)
decl_stmt|;
name|u_int8_t
name|adaptive_ifs
decl_stmt|;
name|u_int
name|__FXP_BITFIELD5
argument_list|(
name|mwi_enable
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|type_enable
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|read_align_en
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|end_wr_on_cl
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
argument_list|:
literal|4
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD2
argument_list|(
name|rx_dma_bytecount
operator|:
literal|7
argument_list|, :
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD2
argument_list|(
name|tx_dma_bytecount
operator|:
literal|7
argument_list|,
name|dma_mbce
operator|:
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD8
argument_list|(
name|late_scb
operator|:
literal|1
argument_list|,
comment|/* 7 */
name|direct_dma_dis
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|tno_int_or_tco_en
operator|:
literal|1
argument_list|,
comment|/* 7,9 */
name|ci_int
operator|:
literal|1
argument_list|,
name|ext_txcb_dis
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|ext_stats_dis
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|keep_overrun_rx
operator|:
literal|1
argument_list|,
name|save_bf
operator|:
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD6
argument_list|(
name|disc_short_rx
operator|:
literal|1
argument_list|,
name|underrun_retry
operator|:
literal|2
argument_list|, 			    :
literal|2
argument_list|,
name|ext_rfa
operator|:
literal|1
argument_list|,
comment|/* 550 */
name|two_frames
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|dyn_tbd
operator|:
literal|1
argument_list|)
decl_stmt|;
comment|/* 8,9 */
name|u_int
name|__FXP_BITFIELD3
argument_list|(
name|mediatype
operator|:
literal|1
argument_list|,
comment|/* 7 */
argument_list|:
literal|6
argument_list|,
name|csma_dis
operator|:
literal|1
argument_list|)
decl_stmt|;
comment|/* 8,9 */
name|u_int
name|__FXP_BITFIELD6
argument_list|(
name|tcp_udp_cksum
operator|:
literal|1
argument_list|,
comment|/* 9 */
argument_list|:
literal|3
argument_list|,
name|vlan_tco
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|link_wake_en
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|arp_wake_en
operator|:
literal|1
argument_list|,
comment|/* 8 */
name|mc_wake_en
operator|:
literal|1
argument_list|)
decl_stmt|;
comment|/* 8 */
name|u_int
name|__FXP_BITFIELD4
argument_list|(:
literal|3
argument_list|,
name|nsai
operator|:
literal|1
argument_list|,
name|preamble_length
operator|:
literal|2
argument_list|,
name|loopback
operator|:
literal|2
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD2
argument_list|(
name|linear_priority
operator|:
literal|3
argument_list|,
comment|/* 7 */
argument_list|:
literal|5
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD3
argument_list|(
name|linear_pri_mode
operator|:
literal|1
argument_list|,
comment|/* 7 */
argument_list|:
literal|3
argument_list|,
name|interfrm_spacing
operator|:
literal|4
argument_list|)
decl_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
name|__FXP_BITFIELD8
argument_list|(
name|promiscuous
operator|:
literal|1
argument_list|,
name|bcast_disable
operator|:
literal|1
argument_list|,
name|wait_after_win
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
argument_list|:
literal|1
argument_list|,
name|ignore_ul
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|crc16_en
operator|:
literal|1
argument_list|,
comment|/* 9 */
argument_list|:
literal|1
argument_list|,
name|crscdt
operator|:
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|fc_delay_lsb
range|:
literal|8
decl_stmt|;
comment|/* 8,9 */
name|u_int
name|fc_delay_msb
range|:
literal|8
decl_stmt|;
comment|/* 8,9 */
name|u_int
name|__FXP_BITFIELD6
argument_list|(
name|stripping
operator|:
literal|1
argument_list|,
name|padding
operator|:
literal|1
argument_list|,
name|rcv_crc_xfer
operator|:
literal|1
argument_list|,
name|long_rx_en
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|pri_fc_thresh
operator|:
literal|3
argument_list|,
comment|/* 8,9 */
argument_list|:
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD8
argument_list|(
name|ia_wake_en
operator|:
literal|1
argument_list|,
comment|/* 8 */
name|magic_pkt_dis
operator|:
literal|1
argument_list|,
comment|/* 8,9,!9ER */
name|tx_fc_dis
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|rx_fc_restop
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|rx_fc_restart
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|fc_filter
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|force_fdx
operator|:
literal|1
argument_list|,
name|fdx_pin_en
operator|:
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD4
argument_list|(:
literal|5
argument_list|,
name|pri_fc_loc
operator|:
literal|1
argument_list|,
comment|/* 8,9 */
name|multi_ia
operator|:
literal|1
argument_list|, 			    :
literal|1
argument_list|)
decl_stmt|;
name|u_int
name|__FXP_BITFIELD3
argument_list|(:
literal|3
argument_list|,
name|mc_all
operator|:
literal|1
argument_list|, :
literal|4
argument_list|)
decl_stmt|;
comment|/* Bytes 22 - 31 -- i82550 only */
name|u_int
name|__FXP_BITFIELD3
argument_list|(
name|gamla_rx
operator|:
literal|1
argument_list|,
name|vlan_drop_en
operator|:
literal|1
argument_list|, 			    :
literal|6
argument_list|)
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXMCADDR
value|80
end_define

begin_struct
struct|struct
name|fxp_cb_mcs
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
name|u_int16_t
name|mc_cnt
decl_stmt|;
name|u_int8_t
name|mc_addr
index|[
name|MAXMCADDR
index|]
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXUCODESIZE
value|192
end_define

begin_struct
struct|struct
name|fxp_cb_ucode
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
name|u_int32_t
name|ucode
index|[
name|MAXUCODESIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Number of DMA segments in a TxCB.  */
end_comment

begin_define
define|#
directive|define
name|FXP_NTXSEG
value|32
end_define

begin_struct
struct|struct
name|fxp_tbd
block|{
name|u_int32_t
name|tb_addr
decl_stmt|;
name|u_int32_t
name|tb_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fxp_ipcb
block|{
comment|/* 	 * The following fields are valid only when 	 * using the IPCB command block for TX checksum offload 	 * (and TCP large send, VLANs, and (I think) IPsec). To use 	 * them, you must enable extended TxCBs (available only 	 * on the 82559 and later) and use the IPCBXMIT command. 	 * Note that Intel defines the IPCB to be 32 bytes long, 	 * the last 8 bytes of which comprise the first entry 	 * in the TBD array (see note below). This means we only 	 * have to define 8 extra bytes here.          */
name|u_int16_t
name|ipcb_schedule_low
decl_stmt|;
name|u_int8_t
name|ipcb_ip_schedule
decl_stmt|;
name|u_int8_t
name|ipcb_ip_activation_high
decl_stmt|;
name|u_int16_t
name|ipcb_vlan_id
decl_stmt|;
name|u_int8_t
name|ipcb_ip_header_offset
decl_stmt|;
name|u_int8_t
name|ipcb_tcp_header_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fxp_cb_tx
block|{
name|u_int16_t
name|cb_status
decl_stmt|;
name|u_int16_t
name|cb_command
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
name|u_int32_t
name|tbd_array_addr
decl_stmt|;
name|u_int16_t
name|byte_count
decl_stmt|;
name|u_int8_t
name|tx_threshold
decl_stmt|;
name|u_int8_t
name|tbd_number
decl_stmt|;
comment|/* 	 * The following structure isn't actually part of the TxCB, 	 * unless the extended TxCB feature is being used.  In this 	 * case, the first two elements of the structure below are  	 * fetched along with the TxCB. 	 */
union|union
block|{
name|struct
name|fxp_ipcb
name|ipcb
decl_stmt|;
name|struct
name|fxp_tbd
name|tbd
index|[
name|FXP_NTXSEG
index|]
decl_stmt|;
block|}
name|tx_cb_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tbd
value|tx_cb_u.tbd
end_define

begin_define
define|#
directive|define
name|ipcb_schedule_low
value|tx_cb_u.ipcb.ipcb_schedule_low
end_define

begin_define
define|#
directive|define
name|ipcb_ip_schedule
value|tx_cb_u.ipcb.ipcb_ip_schedule
end_define

begin_define
define|#
directive|define
name|ipcb_ip_activation_high
value|tx_cb_u.ipcb.ipcb_ip_activation_high
end_define

begin_define
define|#
directive|define
name|ipcb_vlan_id
value|tx_cb_u.ipcb.ipcb_vlan_id
end_define

begin_define
define|#
directive|define
name|ipcb_ip_header_offset
value|tx_cb_u.ipcb.ipcb_ip_header_offset
end_define

begin_define
define|#
directive|define
name|ipcb_tcp_header_offset
value|tx_cb_u.ipcb.ipcb_tcp_header_offset
end_define

begin_comment
comment|/*  * IPCB field definitions  */
end_comment

begin_define
define|#
directive|define
name|FXP_IPCB_IP_CHECKSUM_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_IPCB_TCPUDP_CHECKSUM_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|FXP_IPCB_TCP_PACKET
value|0x40
end_define

begin_define
define|#
directive|define
name|FXP_IPCB_LARGESEND_ENABLE
value|0x80
end_define

begin_define
define|#
directive|define
name|FXP_IPCB_HARDWAREPARSING_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|FXP_IPCB_INSERTVLAN_ENABLE
value|0x02
end_define

begin_comment
comment|/*  * Control Block (CB) definitions  */
end_comment

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_STATUS_OK
value|0x2000
end_define

begin_define
define|#
directive|define
name|FXP_CB_STATUS_C
value|0x8000
end_define

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_NOP
value|0x0
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_IAS
value|0x1
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_CONFIG
value|0x2
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_MCAS
value|0x3
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_XMIT
value|0x4
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_UCODE
value|0x5
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_DUMP
value|0x6
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_DIAG
value|0x7
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_LOADFILT
value|0x8
end_define

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_IPCBXMIT
value|0x9
end_define

begin_comment
comment|/* command flags */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_SF
value|0x0008
end_define

begin_comment
comment|/* simple/flexible mode */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_I
value|0x2000
end_define

begin_comment
comment|/* generate interrupt on completion */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_S
value|0x4000
end_define

begin_comment
comment|/* suspend on completion */
end_comment

begin_define
define|#
directive|define
name|FXP_CB_COMMAND_EL
value|0x8000
end_define

begin_comment
comment|/* end of list */
end_comment

begin_comment
comment|/*  * RFA definitions  */
end_comment

begin_struct
struct|struct
name|fxp_rfa
block|{
name|u_int16_t
name|rfa_status
decl_stmt|;
name|u_int16_t
name|rfa_control
decl_stmt|;
name|u_int32_t
name|link_addr
decl_stmt|;
name|u_int32_t
name|rbd_addr
decl_stmt|;
name|u_int16_t
name|actual_size
decl_stmt|;
name|u_int16_t
name|size
decl_stmt|;
comment|/* 	 * The following fields are only available when using 	 * extended receive mode on an 82550/82551 chipset. 	 */
name|u_int16_t
name|rfax_vlan_id
decl_stmt|;
name|u_int8_t
name|rfax_rx_parser_sts
decl_stmt|;
name|u_int8_t
name|rfax_rsvd0
decl_stmt|;
name|u_int16_t
name|rfax_security_sts
decl_stmt|;
name|u_int8_t
name|rfax_csum_sts
decl_stmt|;
name|u_int8_t
name|rfax_zerocopy_sts
decl_stmt|;
name|u_int8_t
name|rfax_pad
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|FXP_RFAX_LEN
value|16
end_define

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_RCOL
value|0x0001
end_define

begin_comment
comment|/* receive collision */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_IAMATCH
value|0x0002
end_define

begin_comment
comment|/* 0 = matches station address */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_NOAMATCH
value|0x0004
end_define

begin_comment
comment|/* 1 = doesn't match anything */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_PARSE
value|0x0008
end_define

begin_comment
comment|/* pkt parse ok (82550/1 only) */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_S4
value|0x0010
end_define

begin_comment
comment|/* receive error from PHY */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_TL
value|0x0020
end_define

begin_comment
comment|/* type/length */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_FTS
value|0x0080
end_define

begin_comment
comment|/* frame too short */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_OVERRUN
value|0x0100
end_define

begin_comment
comment|/* DMA overrun */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_RNR
value|0x0200
end_define

begin_comment
comment|/* no resources */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_ALIGN
value|0x0400
end_define

begin_comment
comment|/* alignment error */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_CRC
value|0x0800
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_OK
value|0x2000
end_define

begin_comment
comment|/* packet received okay */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_STATUS_C
value|0x8000
end_define

begin_comment
comment|/* packet reception complete */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_CONTROL_SF
value|0x08
end_define

begin_comment
comment|/* simple/flexible memory mode */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_CONTROL_H
value|0x10
end_define

begin_comment
comment|/* header RFD */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_CONTROL_S
value|0x4000
end_define

begin_comment
comment|/* suspend after reception */
end_comment

begin_define
define|#
directive|define
name|FXP_RFA_CONTROL_EL
value|0x8000
end_define

begin_comment
comment|/* end of list */
end_comment

begin_comment
comment|/* Bits in the 'csum_sts' byte */
end_comment

begin_define
define|#
directive|define
name|FXP_RFDX_CS_TCPUDP_CSUM_BIT_VALID
value|0x10
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_CS_TCPUDP_CSUM_VALID
value|0x20
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_CS_IP_CSUM_BIT_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_CS_IP_CSUM_VALID
value|0x02
end_define

begin_comment
comment|/* Bits in the 'packet parser' byte */
end_comment

begin_define
define|#
directive|define
name|FXP_RFDX_P_PARSE_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_P_CSUM_PROTOCOL_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_P_TCP_PACKET
value|0x00
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_P_UDP_PACKET
value|0x01
end_define

begin_define
define|#
directive|define
name|FXP_RFDX_P_IP_PACKET
value|0x03
end_define

begin_comment
comment|/*  * Statistics dump area definitions  */
end_comment

begin_struct
struct|struct
name|fxp_stats
block|{
name|u_int32_t
name|tx_good
decl_stmt|;
name|u_int32_t
name|tx_maxcols
decl_stmt|;
name|u_int32_t
name|tx_latecols
decl_stmt|;
name|u_int32_t
name|tx_underruns
decl_stmt|;
name|u_int32_t
name|tx_lostcrs
decl_stmt|;
name|u_int32_t
name|tx_deffered
decl_stmt|;
name|u_int32_t
name|tx_single_collisions
decl_stmt|;
name|u_int32_t
name|tx_multiple_collisions
decl_stmt|;
name|u_int32_t
name|tx_total_collisions
decl_stmt|;
name|u_int32_t
name|rx_good
decl_stmt|;
name|u_int32_t
name|rx_crc_errors
decl_stmt|;
name|u_int32_t
name|rx_alignment_errors
decl_stmt|;
name|u_int32_t
name|rx_rnr_errors
decl_stmt|;
name|u_int32_t
name|rx_overrun_errors
decl_stmt|;
name|u_int32_t
name|rx_cdt_errors
decl_stmt|;
name|u_int32_t
name|rx_shortframes
decl_stmt|;
name|u_int32_t
name|completion_status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FXP_STATS_DUMP_COMPLETE
value|0xa005
end_define

begin_define
define|#
directive|define
name|FXP_STATS_DR_COMPLETE
value|0xa007
end_define

begin_comment
comment|/*  * Serial EEPROM control register bits  */
end_comment

begin_define
define|#
directive|define
name|FXP_EEPROM_EESK
value|0x01
end_define

begin_comment
comment|/* shift clock */
end_comment

begin_define
define|#
directive|define
name|FXP_EEPROM_EECS
value|0x02
end_define

begin_comment
comment|/* chip select */
end_comment

begin_define
define|#
directive|define
name|FXP_EEPROM_EEDI
value|0x04
end_define

begin_comment
comment|/* data in */
end_comment

begin_define
define|#
directive|define
name|FXP_EEPROM_EEDO
value|0x08
end_define

begin_comment
comment|/* data out */
end_comment

begin_comment
comment|/*  * Serial EEPROM opcodes, including start bit  */
end_comment

begin_define
define|#
directive|define
name|FXP_EEPROM_OPC_ERASE
value|0x4
end_define

begin_define
define|#
directive|define
name|FXP_EEPROM_OPC_WRITE
value|0x5
end_define

begin_define
define|#
directive|define
name|FXP_EEPROM_OPC_READ
value|0x6
end_define

begin_comment
comment|/*  * Management Data Interface opcodes  */
end_comment

begin_define
define|#
directive|define
name|FXP_MDI_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|FXP_MDI_READ
value|0x2
end_define

begin_comment
comment|/*  * PHY device types  */
end_comment

begin_define
define|#
directive|define
name|FXP_PHY_DEVICE_MASK
value|0x3f00
end_define

begin_define
define|#
directive|define
name|FXP_PHY_SERIAL_ONLY
value|0x8000
end_define

begin_define
define|#
directive|define
name|FXP_PHY_NONE
value|0
end_define

begin_define
define|#
directive|define
name|FXP_PHY_82553A
value|1
end_define

begin_define
define|#
directive|define
name|FXP_PHY_82553C
value|2
end_define

begin_define
define|#
directive|define
name|FXP_PHY_82503
value|3
end_define

begin_define
define|#
directive|define
name|FXP_PHY_DP83840
value|4
end_define

begin_define
define|#
directive|define
name|FXP_PHY_80C240
value|5
end_define

begin_define
define|#
directive|define
name|FXP_PHY_80C24
value|6
end_define

begin_define
define|#
directive|define
name|FXP_PHY_82555
value|7
end_define

begin_define
define|#
directive|define
name|FXP_PHY_DP83840A
value|10
end_define

begin_define
define|#
directive|define
name|FXP_PHY_82555B
value|11
end_define

begin_comment
comment|/*  * Chip revision values.  */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82557
value|1
end_define

begin_comment
comment|/* catchall 82557 chip type */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82558_A4
value|4
end_define

begin_comment
comment|/* 82558 A4 stepping */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82558_B0
value|5
end_define

begin_comment
comment|/* 82558 B0 stepping */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82559_A0
value|8
end_define

begin_comment
comment|/* 82559 A0 stepping */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82559S_A
value|9
end_define

begin_comment
comment|/* 82559S A stepping */
end_comment

begin_define
define|#
directive|define
name|FXP_REV_82550
value|12
end_define

begin_define
define|#
directive|define
name|FXP_REV_82550_C
value|13
end_define

begin_comment
comment|/* 82550 C stepping */
end_comment

end_unit

