begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000  * Dr. Duncan McLennan Barclay, dmlb@ragnet.demon.co.uk.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DUNCAN BARCLAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DUNCAN BARCLAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*	$NetBSD: if_rayreg.h,v 1.1 2000/01/23 23:59:22 chopps Exp $	*/
end_comment

begin_comment
comment|/*   * Copyright (c) 2000 Christian E. Hopps  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * CCR registers, appearing in the attribute memory space  */
end_comment

begin_define
define|#
directive|define
name|RAY_CCR
value|0xf00
end_define

begin_comment
comment|/* CCR register offset */
end_comment

begin_define
define|#
directive|define
name|RAY_COR
value|(RAY_CCR + 0x00)
end_define

begin_comment
comment|/* config option register */
end_comment

begin_define
define|#
directive|define
name|RAY_CCSR
value|(RAY_CCR + 0x01)
end_define

begin_comment
comment|/* config/status register */
end_comment

begin_define
define|#
directive|define
name|RAY_PIN
value|(RAY_CCR + 0x02)
end_define

begin_comment
comment|/* not used by hw */
end_comment

begin_define
define|#
directive|define
name|RAY_SOCKETCOPY
value|(RAY_CCR + 0x03)
end_define

begin_comment
comment|/* not used by hw */
end_comment

begin_define
define|#
directive|define
name|RAY_HCSIR
value|(RAY_CCR + 0x05)
end_define

begin_comment
comment|/* HCS intr register */
end_comment

begin_define
define|#
directive|define
name|RAY_ECFIR
value|(RAY_CCR + 0x06)
end_define

begin_comment
comment|/* ECF intr register */
end_comment

begin_comment
comment|/*  * We don't seem to be able to access these in a simple manner  */
end_comment

begin_define
define|#
directive|define
name|RAY_AR0
value|(RAY_CCR + 0x08)
end_define

begin_comment
comment|/* authorization register 0 (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_AR1
value|(RAY_CCR + 0x09)
end_define

begin_comment
comment|/* authorization register 1 (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_PMR
value|(RAY_CCR + 0x0a)
end_define

begin_comment
comment|/* program mode register (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_TMR
value|(RAY_CCR + 0x0b)
end_define

begin_comment
comment|/* pc test mode register (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_FCWR
value|(RAY_CCR + 0x10)
end_define

begin_comment
comment|/* frequency control word register */
end_comment

begin_define
define|#
directive|define
name|RAY_TMC1
value|(RAY_CCR + 0x14)
end_define

begin_comment
comment|/* test mode control 1 (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_TMC2
value|(RAY_CCR + 0x15)
end_define

begin_comment
comment|/* test mode control 1 (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_TMC3
value|(RAY_CCR + 0x16)
end_define

begin_comment
comment|/* test mode control 1 (unused) */
end_comment

begin_define
define|#
directive|define
name|RAY_TMC4
value|(RAY_CCR + 0x17)
end_define

begin_comment
comment|/* test mode control 1 (unused) */
end_comment

begin_comment
comment|/*  * COR register bits  */
end_comment

begin_define
define|#
directive|define
name|RAY_COR_CFG_NUM
value|0x01
end_define

begin_comment
comment|/* currently ignored and set */
end_comment

begin_define
define|#
directive|define
name|RAY_COR_CFG_MASK
value|0x3f
end_define

begin_comment
comment|/* mask for function */
end_comment

begin_define
define|#
directive|define
name|RAY_COR_LEVEL_IRQ
value|0x40
end_define

begin_comment
comment|/* currently ignored and set */
end_comment

begin_define
define|#
directive|define
name|RAY_COR_RESET
value|0x80
end_define

begin_comment
comment|/* soft-reset the card */
end_comment

begin_define
define|#
directive|define
name|RAY_COR_DEFAULT
value|(RAY_COR_CFG_NUM | RAY_COR_LEVEL_IRQ)
end_define

begin_comment
comment|/*  * CCS register bits  */
end_comment

begin_define
define|#
directive|define
name|RAY_CCS_NORMAL
value|0x00
end_define

begin_comment
comment|/* normal operation */
end_comment

begin_define
define|#
directive|define
name|RAY_CCS_IRQ
value|0x02
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|RAY_CCS_POWER_DOWN
value|0x04
end_define

begin_comment
comment|/* when written powers down card */
end_comment

begin_comment
comment|/*  * HCSIR bits  *  * the host can only clear this bit.  */
end_comment

begin_define
define|#
directive|define
name|RAY_HCSIR_IRQ
value|0x01
end_define

begin_comment
comment|/* indicates an interrupt */
end_comment

begin_comment
comment|/*  * ECFIR values  */
end_comment

begin_define
define|#
directive|define
name|RAY_ECFIR_IRQ
value|0x01
end_define

begin_comment
comment|/* interrupt the card */
end_comment

begin_comment
comment|/*  * AR0 values  * used for testing/programming the card (unused)  */
end_comment

begin_define
define|#
directive|define
name|RAY_AR0_ON
value|0x57
end_define

begin_comment
comment|/*  * AR1 values  * used for testing/programming the card (unused)  */
end_comment

begin_define
define|#
directive|define
name|RAY_AR1_ON
value|0x82
end_define

begin_comment
comment|/*  * PMR bits   * these are used to program the card (unused)  */
end_comment

begin_define
define|#
directive|define
name|RAY_PMR_NORMAL
value|0x00
end_define

begin_comment
comment|/* normal operation */
end_comment

begin_define
define|#
directive|define
name|RAY_PMR_PC2PM
value|0x02
end_define

begin_comment
comment|/* grant access to firmware flash */
end_comment

begin_define
define|#
directive|define
name|RAY_PMR_PC2CAL
value|0x10
end_define

begin_comment
comment|/* read access to the A/D modem inp */
end_comment

begin_define
define|#
directive|define
name|RAY_PMR_MLSE
value|0x20
end_define

begin_comment
comment|/* read access to the MSLE prom */
end_comment

begin_comment
comment|/*  * TMR bits  * get access to test modes (unused)  */
end_comment

begin_define
define|#
directive|define
name|RAY_TMR_NORMAL
value|0x00
end_define

begin_comment
comment|/* normal operation */
end_comment

begin_define
define|#
directive|define
name|RAY_TMR_TEST
value|0x08
end_define

begin_comment
comment|/* test mode */
end_comment

begin_comment
comment|/*  * FCWR -- frequency control word, values from [0x02,0xA6] map to  * RF frequency values.  */
end_comment

begin_comment
comment|/*  * 48k of memory  */
end_comment

begin_define
define|#
directive|define
name|RAY_SRAM_MEM_BASE
value|0
end_define

begin_define
define|#
directive|define
name|RAY_SRAM_MEM_SIZE
value|0xc000
end_define

begin_comment
comment|/*  * offsets into shared ram  */
end_comment

begin_define
define|#
directive|define
name|RAY_SCB_BASE
value|0x0000
end_define

begin_comment
comment|/* cfg/status/ctl area */
end_comment

begin_define
define|#
directive|define
name|RAY_STATUS_BASE
value|0x0100
end_define

begin_define
define|#
directive|define
name|RAY_HOST_TO_ECF_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|RAY_ECF_TO_HOST_BASE
value|0x0300
end_define

begin_define
define|#
directive|define
name|RAY_CCS_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|RAY_RCS_BASE
value|0x0800
end_define

begin_define
define|#
directive|define
name|RAY_APOINT_TIM_BASE
value|0x0c00
end_define

begin_define
define|#
directive|define
name|RAY_SSID_LIST_BASE
value|0x0d00
end_define

begin_define
define|#
directive|define
name|RAY_TX_BASE
value|0x1000
end_define

begin_define
define|#
directive|define
name|RAY_TX_SIZE
value|0x7000
end_define

begin_define
define|#
directive|define
name|RAY_TX_END
value|0x8000
end_define

begin_define
define|#
directive|define
name|RAY_RX_BASE
value|0x8000
end_define

begin_define
define|#
directive|define
name|RAY_RX_END
value|0xc000
end_define

begin_define
define|#
directive|define
name|RAY_RX_MASK
value|0x3fff
end_define

begin_comment
comment|/*  * Startup reporting stucture  */
end_comment

begin_struct
struct|struct
name|ray_ecf_startup_v4
block|{
name|u_int8_t
name|e_status
decl_stmt|;
name|u_int8_t
name|e_station_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|e_prg_cksum
decl_stmt|;
name|u_int8_t
name|e_cis_cksum
decl_stmt|;
name|u_int8_t
name|e_resv0
index|[
literal|7
index|]
decl_stmt|;
name|u_int8_t
name|e_japan_callsign
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ray_ecf_startup_v5
block|{
name|u_int8_t
name|e_status
decl_stmt|;
name|u_int8_t
name|e_station_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|e_resv0
decl_stmt|;
name|u_int8_t
name|e_rates
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|e_japan_callsign
index|[
literal|12
index|]
decl_stmt|;
name|u_int8_t
name|e_prg_cksum
decl_stmt|;
name|u_int8_t
name|e_cis_cksum
decl_stmt|;
name|u_int8_t
name|e_fw_build_string
decl_stmt|;
name|u_int8_t
name|e_fw_build
decl_stmt|;
name|u_int8_t
name|e_fw_resv
decl_stmt|;
name|u_int8_t
name|e_asic_version
decl_stmt|;
name|u_int8_t
name|e_tibsize
decl_stmt|;
name|u_int8_t
name|e_resv1
index|[
literal|29
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Startup status word result codes  */
end_comment

begin_define
define|#
directive|define
name|RAY_ECFS_RESERVED0
value|0x01
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_PROC_SELF_TEST
value|0x02
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_PROG_MEM_CHECKSUM
value|0x04
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_DATA_MEM_TEST
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_RX_CALIBRATION
value|0x10
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_FW_VERSION_COMPAT
value|0x20
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_RERSERVED1
value|0x40
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_TEST_COMPLETE
value|0x80
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_CARD_OK
value|RAY_ECFS_TEST_COMPLETE
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_PRINTFB
define|\
value|"\020"			\ 	"\001RESERVED0"		\ 	"\002PROC_SELF_TEST"	\ 	"\003PROG_MEM_CHECKSUM"	\ 	"\004DATA_MEM_TEST"	\ 	"\005RX_CALIBRATION"	\ 	"\006FW_VERSION_COMPAT"	\ 	"\007RERSERVED1"	\ 	"\010TEST_COMPLETE"
end_define

begin_comment
comment|/*  * Firmware build codes  */
end_comment

begin_define
define|#
directive|define
name|RAY_ECFS_BUILD_4
value|0x55
end_define

begin_define
define|#
directive|define
name|RAY_ECFS_BUILD_5
value|0x5
end_define

begin_comment
comment|/*  * System Control Block  */
end_comment

begin_define
define|#
directive|define
name|RAY_SCB_CCSI
value|0x00
end_define

begin_comment
comment|/* host CCS index */
end_comment

begin_define
define|#
directive|define
name|RAY_SCB_RCSI
value|0x01
end_define

begin_comment
comment|/* ecf RCS index */
end_comment

begin_comment
comment|/*  * command control structures (for CCSR commands)  */
end_comment

begin_comment
comment|/*  * commands for CCSR  */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_DOWNLOAD_PARAMS
value|0x01
end_define

begin_comment
comment|/* download start params */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_UPDATE_PARAMS
value|0x02
end_define

begin_comment
comment|/* update params */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_REPORT_PARAMS
value|0x03
end_define

begin_comment
comment|/* report params */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_UPDATE_MCAST
value|0x04
end_define

begin_comment
comment|/* update mcast list */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_UPDATE_APM
value|0x05
end_define

begin_comment
comment|/* update power saving mode */
end_comment

begin_define
define|#
directive|define
name|RAY_CMD_START_NET
value|0x06
end_define

begin_define
define|#
directive|define
name|RAY_CMD_JOIN_NET
value|0x07
end_define

begin_define
define|#
directive|define
name|RAY_CMD_START_ASSOC
value|0x08
end_define

begin_define
define|#
directive|define
name|RAY_CMD_TX_REQ
value|0x09
end_define

begin_define
define|#
directive|define
name|RAY_CMD_TEST_MEM
value|0x0a
end_define

begin_define
define|#
directive|define
name|RAY_CMD_SHUTDOWN
value|0x0b
end_define

begin_define
define|#
directive|define
name|RAY_CMD_DUMP_MEM
value|0x0c
end_define

begin_define
define|#
directive|define
name|RAY_CMD_START_TIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|RAY_CMD_MAX
value|0x0e
end_define

begin_comment
comment|/*  * unsolicted commands from the ECF  */
end_comment

begin_define
define|#
directive|define
name|RAY_ECMD_RX_DONE
value|0x80
end_define

begin_comment
comment|/* process rx packet */
end_comment

begin_define
define|#
directive|define
name|RAY_ECMD_REJOIN_DONE
value|0x81
end_define

begin_comment
comment|/* rejoined the network */
end_comment

begin_define
define|#
directive|define
name|RAY_ECMD_ROAM_START
value|0x82
end_define

begin_comment
comment|/* romaining started */
end_comment

begin_define
define|#
directive|define
name|RAY_ECMD_JAPAN_CALL_SIGNAL
value|0x83
end_define

begin_comment
comment|/* japan test thing */
end_comment

begin_comment
comment|/*  * Configure/status/control memory  */
end_comment

begin_struct
struct|struct
name|ray_csc
block|{
name|u_int8_t
name|csc_mrxo_own
decl_stmt|;
comment|/* 0 ECF writes, 1 host write */
name|u_int8_t
name|csc_mrxc_own
decl_stmt|;
comment|/* 0 ECF writes, 1 host write */
name|u_int8_t
name|csc_rxhc_own
decl_stmt|;
comment|/* 0 ECF writes, 1 host write */
name|u_int8_t
name|csc_resv
decl_stmt|;
name|u_int16_t
name|csc_mrx_overflow
decl_stmt|;
comment|/* ECF incs on rx overflow */
name|u_int16_t
name|csc_mrx_cksum
decl_stmt|;
comment|/* ECF incs on cksum error */
name|u_int16_t
name|csc_rx_hcksum
decl_stmt|;
comment|/* ECF incs on header cksum error */
name|u_int8_t
name|csc_rx_noise
decl_stmt|;
comment|/* average RSL measuremant */
block|}
struct|;
end_struct

begin_comment
comment|/*  * CCS area  */
end_comment

begin_define
define|#
directive|define
name|RAY_CCS_LINK_NULL
value|0xff
end_define

begin_define
define|#
directive|define
name|RAY_CCS_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|RAY_CCS_TX_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|RAY_CCS_TX_LAST
value|13
end_define

begin_define
define|#
directive|define
name|RAY_CCS_NTX
value|(RAY_CCS_TX_LAST - RAY_CCS_TX_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|RAY_TX_BUF_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|RAY_CCS_CMD_FIRST
value|14
end_define

begin_define
define|#
directive|define
name|RAY_CCS_CMD_LAST
value|63
end_define

begin_define
define|#
directive|define
name|RAY_CCS_NCMD
value|(RAY_CCS_CMD_LAST - RAY_CCS_CMD_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|RAY_CCS_LAST
value|63
end_define

begin_define
define|#
directive|define
name|RAY_CCS_INDEX
parameter_list|(
name|ccs
parameter_list|)
value|(((ccs) - RAY_CCS_BASE) / RAY_CCS_SIZE)
end_define

begin_define
define|#
directive|define
name|RAY_CCS_ADDRESS
parameter_list|(
name|i
parameter_list|)
value|(RAY_CCS_BASE + (i) * RAY_CCS_SIZE)
end_define

begin_comment
comment|/*  * RCS area  */
end_comment

begin_define
define|#
directive|define
name|RAY_RCS_FIRST
value|64
end_define

begin_define
define|#
directive|define
name|RAY_RCS_LAST
value|127
end_define

begin_comment
comment|/*  * CCS commands  */
end_comment

begin_struct
struct|struct
name|ray_cmd
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RAY_CCS_STATUS_FREE
value|0x0
end_define

begin_define
define|#
directive|define
name|RAY_CCS_STATUS_BUSY
value|0x1
end_define

begin_define
define|#
directive|define
name|RAY_CCS_STATUS_COMPLETE
value|0x2
end_define

begin_define
define|#
directive|define
name|RAY_CCS_STATUS_FAIL
value|0x3
end_define

begin_define
define|#
directive|define
name|RAY_CCS_STATUS_STRINGS
value|{	\     "free",				\     "busy",				\     "complete",				\     "fail"				\ }
end_define

begin_comment
comment|/* RAY_CMD_UPDATE_PARAMS */
end_comment

begin_struct
struct|struct
name|ray_cmd_update
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_paramid
decl_stmt|;
name|u_int8_t
name|c_nparam
decl_stmt|;
name|u_int8_t
name|c_failcause
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_REPORT_PARAMS */
end_comment

begin_struct
struct|struct
name|ray_cmd_report
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_paramid
decl_stmt|;
name|u_int8_t
name|c_nparam
decl_stmt|;
name|u_int8_t
name|c_failcause
decl_stmt|;
name|u_int8_t
name|c_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_UPDATE_MCAST */
end_comment

begin_struct
struct|struct
name|ray_cmd_update_mcast
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_nmcast
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_UPDATE_APM */
end_comment

begin_struct
struct|struct
name|ray_cmd_udpate_apm
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_START_NET and RAY_CMD_JOIN_NET */
end_comment

begin_struct
struct|struct
name|ray_cmd_net
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_upd_param
decl_stmt|;
name|u_int8_t
name|c_bss_id
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|c_inited
decl_stmt|;
name|u_int8_t
name|c_def_txrate
decl_stmt|;
name|u_int8_t
name|c_encrypt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Parameters passed in HOST_TO_ECF section when c_upd_param is set in  * ray_cmd_net. */
end_comment

begin_struct
struct|struct
name|ray_net_params
block|{
name|u_int8_t
name|p_net_type
decl_stmt|;
name|u_int8_t
name|p_ssid
index|[
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|p_privacy_must_start
decl_stmt|;
name|u_int8_t
name|p_privacy_can_join
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_START_ASSOC */
end_comment

begin_struct
struct|struct
name|ray_cmd_update_assoc
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_astatus
decl_stmt|;
name|u_int8_t
name|c_aid
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_TX_REQ */
end_comment

begin_struct
struct|struct
name|ray_cmd_tx
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_bufp
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|c_len
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|c_resv
index|[
literal|5
index|]
decl_stmt|;
name|u_int8_t
name|c_tx_rate
decl_stmt|;
name|u_int8_t
name|c_apm_mode
decl_stmt|;
name|u_int8_t
name|c_nretry
decl_stmt|;
name|u_int8_t
name|c_antenna
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ray_cmd_tx_4
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_bufp
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|c_len
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|c_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|c_apm_mode
decl_stmt|;
name|u_int8_t
name|c_nretry
decl_stmt|;
name|u_int8_t
name|c_antenna
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_DUMP_MEM */
end_comment

begin_struct
struct|struct
name|ray_cmd_dump_mem
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_memtype
decl_stmt|;
name|u_int8_t
name|c_memp
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|c_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_CMD_START_TIMER */
end_comment

begin_struct
struct|struct
name|ray_cmd_start_timer
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_duration
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* RAY_ECMD_RX_DONE */
end_comment

begin_struct
struct|struct
name|ray_cmd_rx
block|{
name|u_int8_t
name|c_status
decl_stmt|;
comment|/* ccs generic header */
name|u_int8_t
name|c_cmd
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_link
decl_stmt|;
comment|/* " */
name|u_int8_t
name|c_bufp
index|[
literal|2
index|]
decl_stmt|;
comment|/* buffer pointer */
name|u_int8_t
name|c_len
index|[
literal|2
index|]
decl_stmt|;
comment|/* length */
name|u_int8_t
name|c_siglev
decl_stmt|;
comment|/* signal level */
name|u_int8_t
name|c_nextfrag
decl_stmt|;
comment|/* next fragment in packet */
name|u_int8_t
name|c_pktlen
index|[
literal|2
index|]
decl_stmt|;
comment|/* total packet length */
name|u_int8_t
name|c_antenna
decl_stmt|;
comment|/* ant. with best reception */
name|u_int8_t
name|c_updbss
decl_stmt|;
comment|/* only 1 for beacon messages */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transmit scratch space and phy header structures  */
end_comment

begin_struct
struct|struct
name|ray_tx_tib
block|{
name|u_int8_t
name|t_ccs_index
decl_stmt|;
name|u_int8_t
name|t_psm
decl_stmt|;
name|u_int8_t
name|t_pass_fail
decl_stmt|;
name|u_int8_t
name|t_retry_count
decl_stmt|;
name|u_int8_t
name|t_max_retries
decl_stmt|;
name|u_int8_t
name|t_frags_remaining
decl_stmt|;
name|u_int8_t
name|t_no_rb
decl_stmt|;
name|u_int8_t
name|t_rts_reqd
decl_stmt|;
name|u_int8_t
name|t_csma_tx_cntrl_2
decl_stmt|;
name|u_int8_t
name|t_sifs_tx_cntrl_2
decl_stmt|;
name|u_int8_t
name|t_tx_dma_addr_1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_tx_dma_addr_2
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_var_dur_2mhz
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_var_dur_1mhz
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_max_dur_2mhz
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_max_dur_1mhz
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_hdr_len
decl_stmt|;
name|u_int8_t
name|t_max_frag_len
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_var_len
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_phy_hdr_4
decl_stmt|;
name|u_int8_t
name|t_mac_hdr_1
decl_stmt|;
name|u_int8_t
name|t_mac_hdr_2
decl_stmt|;
name|u_int8_t
name|t_sid
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ray_tx_phy_header
block|{
name|u_int8_t
name|t_sfd
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|t_hdr_3
decl_stmt|;
name|u_int8_t
name|t_hdr_4
decl_stmt|;
block|}
struct|;
end_struct

end_unit

