begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1998, 1999  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|AN_TIMEOUT
value|65536
end_define

begin_comment
comment|/* Default network name: ANY */
end_comment

begin_define
define|#
directive|define
name|AN_DEFAULT_NETNAME
value|"ANY"
end_define

begin_comment
comment|/* The nodename must be less than 16 bytes */
end_comment

begin_define
define|#
directive|define
name|AN_DEFAULT_NODENAME
value|"FreeBSD"
end_define

begin_define
define|#
directive|define
name|AN_DEFAULT_IBSS
value|"FreeBSD IBSS"
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(sc->an_btag, sc->an_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(sc->an_btag, sc->an_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(sc->an_btag, sc->an_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(sc->an_btag, sc->an_bhandle, reg)
end_define

begin_comment
comment|/*  * Size of Aironet I/O space.  */
end_comment

begin_define
define|#
directive|define
name|AN_IOSIZ
value|0x40
end_define

begin_comment
comment|/*  * Hermes register definitions and what little I know about them.  */
end_comment

begin_comment
comment|/* Hermes command/status registers. */
end_comment

begin_define
define|#
directive|define
name|AN_COMMAND
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_PARAM0
value|0x02
end_define

begin_define
define|#
directive|define
name|AN_PARAM1
value|0x04
end_define

begin_define
define|#
directive|define
name|AN_PARAM2
value|0x06
end_define

begin_define
define|#
directive|define
name|AN_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|AN_RESP0
value|0x0A
end_define

begin_define
define|#
directive|define
name|AN_RESP1
value|0x0C
end_define

begin_define
define|#
directive|define
name|AN_RESP2
value|0x0E
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT
value|0x10
end_define

begin_comment
comment|/* Command register */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_BUSY
value|0x8000
end_define

begin_comment
comment|/* busy bit */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_NO_ACK
value|0x0080
end_define

begin_comment
comment|/* don't acknowledge command */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_CODE_MASK
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_CMD_QUAL_MASK
value|0x7F00
end_define

begin_comment
comment|/* Command codes */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_NOOP
value|0x0000
end_define

begin_comment
comment|/* no-op */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_ENABLE
value|0x0001
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_DISABLE
value|0x0002
end_define

begin_comment
comment|/* disable */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_FORCE_SYNCLOSS
value|0x0003
end_define

begin_comment
comment|/* force loss of sync */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_FW_RESTART
value|0x0004
end_define

begin_comment
comment|/* firmware resrart */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_HOST_SLEEP
value|0x0005
end_define

begin_define
define|#
directive|define
name|AN_CMD_MAGIC_PKT
value|0x0006
end_define

begin_define
define|#
directive|define
name|AN_CMD_READCFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_CMD_ALLOC_MEM
value|0x000A
end_define

begin_comment
comment|/* allocate NIC memory */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_TX
value|0x000B
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|AN_CMD_DEALLOC_MEM
value|0x000C
end_define

begin_define
define|#
directive|define
name|AN_CMD_NOOP2
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_CMD_ACCESS
value|0x0021
end_define

begin_define
define|#
directive|define
name|AN_CMD_ALLOC_BUF
value|0x0028
end_define

begin_define
define|#
directive|define
name|AN_CMD_PSP_NODES
value|0x0030
end_define

begin_define
define|#
directive|define
name|AN_CMD_SET_PHYREG
value|0x003E
end_define

begin_define
define|#
directive|define
name|AN_CMD_TX_TEST
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_CMD_SLEEP
value|0x0085
end_define

begin_define
define|#
directive|define
name|AN_CMD_SAVECFG
value|0x0108
end_define

begin_comment
comment|/*  * Reclaim qualifier bit, applicable to the  * TX command.  */
end_comment

begin_define
define|#
directive|define
name|AN_RECLAIM
value|0x0100
end_define

begin_comment
comment|/* reclaim NIC memory */
end_comment

begin_comment
comment|/*  * ACCESS command qualifier bits.  */
end_comment

begin_define
define|#
directive|define
name|AN_ACCESS_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_ACCESS_WRITE
value|0x0100
end_define

begin_comment
comment|/*  * PROGRAM command qualifier bits.  */
end_comment

begin_define
define|#
directive|define
name|AN_PROGRAM_DISABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_ENABLE_RAM
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_ENABLE_NVRAM
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_PROGRAM_NVRAM
value|0x0300
end_define

begin_comment
comment|/* Status register values */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_CMD_CODE
value|0x003F
end_define

begin_define
define|#
directive|define
name|AN_STAT_CMD_RESULT
value|0x7F00
end_define

begin_comment
comment|/* Linkstat register */
end_comment

begin_define
define|#
directive|define
name|AN_LINKSTAT_ASSOCIATED
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_AUTHFAIL
value|0x0300
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_ASSOC_FAIL
value|0x8400
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_DISASSOC
value|0x8200
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_DEAUTH
value|0x8100
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_TSF
value|0x8004
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_HOSTREQ
value|0x8003
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_AVGRETRY
value|0x8002
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_MAXRETRY
value|0x8001
end_define

begin_define
define|#
directive|define
name|AN_LINKSTAT_SYNCLOST_MISSBEACON
value|0x8000
end_define

begin_comment
comment|/* memory handle management registers */
end_comment

begin_define
define|#
directive|define
name|AN_RX_FID
value|0x20
end_define

begin_define
define|#
directive|define
name|AN_ALLOC_FID
value|0x22
end_define

begin_define
define|#
directive|define
name|AN_TX_CMP_FID
value|0x24
end_define

begin_comment
comment|/*  * Buffer Access Path (BAP) registers.  * These are I/O channels. I believe you can use each one for  * any desired purpose independently of the other. In general  * though, we use BAP1 for reading and writing LTV records and  * reading received data frames, and BAP0 for writing transmit  * frames. This is a convention though, not a rule.  */
end_comment

begin_define
define|#
directive|define
name|AN_SEL0
value|0x18
end_define

begin_define
define|#
directive|define
name|AN_SEL1
value|0x1A
end_define

begin_define
define|#
directive|define
name|AN_OFF0
value|0x1C
end_define

begin_define
define|#
directive|define
name|AN_OFF1
value|0x1E
end_define

begin_define
define|#
directive|define
name|AN_DATA0
value|0x36
end_define

begin_define
define|#
directive|define
name|AN_DATA1
value|0x38
end_define

begin_define
define|#
directive|define
name|AN_BAP0
value|AN_DATA0
end_define

begin_define
define|#
directive|define
name|AN_BAP1
value|AN_DATA1
end_define

begin_define
define|#
directive|define
name|AN_OFF_BUSY
value|0x8000
end_define

begin_define
define|#
directive|define
name|AN_OFF_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|AN_OFF_DONE
value|0x2000
end_define

begin_define
define|#
directive|define
name|AN_OFF_DATAOFF
value|0x0FFF
end_define

begin_comment
comment|/* Event registers */
end_comment

begin_define
define|#
directive|define
name|AN_EVENT_STAT
value|0x30
end_define

begin_comment
comment|/* Event status */
end_comment

begin_define
define|#
directive|define
name|AN_INT_EN
value|0x32
end_define

begin_comment
comment|/* Interrupt enable/disable */
end_comment

begin_define
define|#
directive|define
name|AN_EVENT_ACK
value|0x34
end_define

begin_comment
comment|/* Ack event */
end_comment

begin_comment
comment|/* Events */
end_comment

begin_define
define|#
directive|define
name|AN_EV_CLR_STUCK_BUSY
value|0x4000
end_define

begin_comment
comment|/* clear stuck busy bit */
end_comment

begin_define
define|#
directive|define
name|AN_EV_WAKEREQUEST
value|0x2000
end_define

begin_comment
comment|/* awaken from PSP mode */
end_comment

begin_define
define|#
directive|define
name|AN_EV_AWAKE
value|0x0100
end_define

begin_comment
comment|/* station woke up from PSP mode*/
end_comment

begin_define
define|#
directive|define
name|AN_EV_LINKSTAT
value|0x0080
end_define

begin_comment
comment|/* link status available */
end_comment

begin_define
define|#
directive|define
name|AN_EV_CMD
value|0x0010
end_define

begin_comment
comment|/* command completed */
end_comment

begin_define
define|#
directive|define
name|AN_EV_ALLOC
value|0x0008
end_define

begin_comment
comment|/* async alloc/reclaim completed */
end_comment

begin_define
define|#
directive|define
name|AN_EV_TX_EXC
value|0x0004
end_define

begin_comment
comment|/* async xmit completed with failure */
end_comment

begin_define
define|#
directive|define
name|AN_EV_TX
value|0x0002
end_define

begin_comment
comment|/* async xmit completed succesfully */
end_comment

begin_define
define|#
directive|define
name|AN_EV_RX
value|0x0001
end_define

begin_comment
comment|/* async rx completed */
end_comment

begin_define
define|#
directive|define
name|AN_INTRS
define|\
value|(AN_EV_RX|AN_EV_TX|AN_EV_TX_EXC|AN_EV_ALLOC|AN_EV_LINKSTAT)
end_define

begin_comment
comment|/* Host software registers */
end_comment

begin_define
define|#
directive|define
name|AN_SW0
value|0x28
end_define

begin_define
define|#
directive|define
name|AN_SW1
value|0x2A
end_define

begin_define
define|#
directive|define
name|AN_SW2
value|0x2C
end_define

begin_define
define|#
directive|define
name|AN_SW3
value|0x2E
end_define

begin_define
define|#
directive|define
name|AN_CNTL
value|0x14
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA
value|0xC000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA_STAT
value|0xC000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_DIS_STAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_ENA_CNTL
value|0x8000
end_define

begin_define
define|#
directive|define
name|AN_CNTL_AUX_DIS_CNTL
value|0x4000
end_define

begin_define
define|#
directive|define
name|AN_AUX_PAGE
value|0x3A
end_define

begin_define
define|#
directive|define
name|AN_AUX_OFFSET
value|0x3C
end_define

begin_define
define|#
directive|define
name|AN_AUX_DATA
value|0x3E
end_define

begin_comment
comment|/*  * Length, Type, Value (LTV) record definitions and RID values.  */
end_comment

begin_struct
struct|struct
name|an_ltv_gen
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * General configuration information.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_GENCONFIG
value|0xFF10
end_define

begin_struct
struct|struct
name|an_ltv_genconfig
block|{
comment|/* General configuration. */
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* XXXX */
name|u_int16_t
name|an_opmode
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|an_rxmode
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_fragthresh
decl_stmt|;
comment|/* 0x06 */
name|u_int16_t
name|an_rtsthresh
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x0A */
name|u_int8_t
name|an_rates
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int16_t
name|an_shortretry_limit
decl_stmt|;
comment|/* 0x18 */
name|u_int16_t
name|an_longretry_limit
decl_stmt|;
comment|/* 0x1A */
name|u_int16_t
name|an_tx_msdu_lifetime
decl_stmt|;
comment|/* 0x1C */
name|u_int16_t
name|an_rx_msdu_lifetime
decl_stmt|;
comment|/* 0x1E */
name|u_int16_t
name|an_stationary
decl_stmt|;
comment|/* 0x20 */
name|u_int16_t
name|an_ordering
decl_stmt|;
comment|/* 0x22 */
name|u_int16_t
name|an_devtype
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_rsvd0
index|[
literal|5
index|]
decl_stmt|;
comment|/* 0x26 */
comment|/* Scanning associating. */
name|u_int16_t
name|an_scanmode
decl_stmt|;
comment|/* 0x30 */
name|u_int16_t
name|an_probedelay
decl_stmt|;
comment|/* 0x32 */
name|u_int16_t
name|an_probe_energy_timeout
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_probe_response_timeout
decl_stmt|;
comment|/*0x36 */
name|u_int16_t
name|an_beacon_listen_timeout
decl_stmt|;
comment|/*0x38 */
name|u_int16_t
name|an_ibss_join_net_timeout
decl_stmt|;
comment|/*0x3A */
name|u_int16_t
name|an_auth_timeout
decl_stmt|;
comment|/* 0x3C */
name|u_int16_t
name|an_authtype
decl_stmt|;
comment|/* 0x3E */
name|u_int16_t
name|an_assoc_timeout
decl_stmt|;
comment|/* 0x40 */
name|u_int16_t
name|an_specified_ap_timeout
decl_stmt|;
comment|/* 0x42 */
name|u_int16_t
name|an_offline_scan_interval
decl_stmt|;
comment|/*0x44 */
name|u_int16_t
name|an_offline_scan_duration
decl_stmt|;
comment|/*0x46 */
name|u_int16_t
name|an_link_loss_delay
decl_stmt|;
comment|/* 0x48 */
name|u_int16_t
name|an_max_beacon_lost_time
decl_stmt|;
comment|/* 0x4A */
name|u_int16_t
name|an_refresh_interval
decl_stmt|;
comment|/* 0x4C */
name|u_int16_t
name|an_rsvd1
decl_stmt|;
comment|/* 0x4E */
comment|/* Power save operation */
name|u_int16_t
name|an_psave_mode
decl_stmt|;
comment|/* 0x50 */
name|u_int16_t
name|an_sleep_for_dtims
decl_stmt|;
comment|/* 0x52 */
name|u_int16_t
name|an_listen_interval
decl_stmt|;
comment|/* 0x54 */
name|u_int16_t
name|an_fast_listen_interval
decl_stmt|;
comment|/* 0x56 */
name|u_int16_t
name|an_listen_decay
decl_stmt|;
comment|/* 0x58 */
name|u_int16_t
name|an_fast_listen_decay
decl_stmt|;
comment|/* 0x5A */
name|u_int16_t
name|an_rsvd2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x5C */
comment|/* Ad-hoc (or AP) operation. */
name|u_int16_t
name|an_beacon_period
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_atim_duration
decl_stmt|;
comment|/* 0x62 */
name|u_int16_t
name|an_rsvd3
decl_stmt|;
comment|/* 0x64 */
name|u_int16_t
name|an_ds_channel
decl_stmt|;
comment|/* 0x66 */
name|u_int16_t
name|an_rsvd4
decl_stmt|;
comment|/* 0x68 */
name|u_int16_t
name|an_dtim_period
decl_stmt|;
comment|/* 0x6A */
name|u_int16_t
name|an_rsvd5
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x6C */
comment|/* Radio operation. */
name|u_int16_t
name|an_radiotype
decl_stmt|;
comment|/* 0x70 */
name|u_int16_t
name|an_diversity
decl_stmt|;
comment|/* 0x72 */
name|u_int16_t
name|an_tx_power
decl_stmt|;
comment|/* 0x74 */
name|u_int16_t
name|an_rss_thresh
decl_stmt|;
comment|/* 0x76 */
name|u_int16_t
name|an_rsvd6
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x78 */
comment|/* Aironet extensions. */
name|u_int8_t
name|an_nodename
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x80 */
name|u_int16_t
name|an_arl_thresh
decl_stmt|;
comment|/* 0x90 */
name|u_int16_t
name|an_arl_decay
decl_stmt|;
comment|/* 0x92 */
name|u_int16_t
name|an_arl_delay
decl_stmt|;
comment|/* 0x94 */
name|u_int8_t
name|an_rsvd7
decl_stmt|;
comment|/* 0x96 */
name|u_int8_t
name|an_rsvd8
decl_stmt|;
comment|/* 0x97 */
name|u_int8_t
name|an_magic_packet_action
decl_stmt|;
comment|/* 0x98 */
name|u_int8_t
name|an_magic_packet_ctl
decl_stmt|;
comment|/* 0x99 */
name|u_int16_t
name|an_rsvd9
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_OPMODE_IBSS_ADHOC
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_INFRASTRUCTURE_STATION
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP_REPEATER
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_UNMODIFIED_PAYLOAD
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AIRONET_EXTENSIONS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_OPMODE_AP_EXTENSIONS
value|0x0400
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_BC_MC_ADDR
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_BC_ADDR
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_ADDR
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_80211_MONITOR_CURBSS
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_80211_MONITOR_ANYBSS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_LAN_MONITOR_CURBSS
value|0x0005
end_define

begin_define
define|#
directive|define
name|AN_RXMODE_NO_8023_HEADER
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_RATE_1MBPS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RATE_2MBPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_RATE_5_5MBPS
value|0x000B
end_define

begin_define
define|#
directive|define
name|AN_RATE_11MBPS
value|0x0016
end_define

begin_define
define|#
directive|define
name|AN_DEVTYPE_PC4500
value|0x0065
end_define

begin_define
define|#
directive|define
name|AN_DEVTYPE_PC4800
value|0x006D
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_ACTIVE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_PASSIVE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_SCANMODE_AIRONET_ACTIVE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_OPEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_SHAREDKEY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_AUTHTYPE_EXCLUDE_UNENCRYPTED
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_CAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_PSP
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_PSAVE_PSP_CAM
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_80211_FH
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_80211_DS
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RADIOTYPE_LM2000_DS
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_FACTORY_DEFAULT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_1_ONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_2_ONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_DIVERSITY_ANTENNA_1_AND_2
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_FACTORY_DEFAULT
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_50MW
value|50
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_100MW
value|100
end_define

begin_define
define|#
directive|define
name|AN_TXPOWER_250MW
value|250
end_define

begin_comment
comment|/*  * Valid SSID list. You can specify up to three SSIDs denoting  * the service sets that you want to join. The first SSID always  * defaults to "tsunami" which is a handy way to detect the  * card.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_SSIDLIST
value|0xFF11
end_define

begin_struct
struct|struct
name|an_ltv_ssidlist
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_ssid1_len
decl_stmt|;
name|char
name|an_ssid1
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|an_ssid2_len
decl_stmt|;
name|char
name|an_ssid2
index|[
literal|32
index|]
decl_stmt|;
name|u_int16_t
name|an_ssid3_len
decl_stmt|;
name|char
name|an_ssid3
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_DEF_SSID_LEN
value|7
end_define

begin_define
define|#
directive|define
name|AN_DEF_SSID
value|"tsunami"
end_define

begin_comment
comment|/*  * Valid AP list.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_APLIST
value|0xFF12
end_define

begin_struct
struct|struct
name|an_ltv_aplist
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int8_t
name|an_ap1
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap2
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap3
index|[
literal|8
index|]
decl_stmt|;
name|u_int8_t
name|an_ap4
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Driver name.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_DRVNAME
value|0xFF13
end_define

begin_struct
struct|struct
name|an_ltv_drvname
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int8_t
name|an_drvname
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Frame encapsulation.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_ENCAP
value|0xFF14
end_define

begin_struct
struct|struct
name|an_rid_encap
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_ethertype_default
decl_stmt|;
name|u_int16_t
name|an_action_default
decl_stmt|;
name|u_int16_t
name|an_ethertype0
decl_stmt|;
name|u_int16_t
name|an_action0
decl_stmt|;
name|u_int16_t
name|an_ethertype1
decl_stmt|;
name|u_int16_t
name|an_action1
decl_stmt|;
name|u_int16_t
name|an_ethertype2
decl_stmt|;
name|u_int16_t
name|an_action2
decl_stmt|;
name|u_int16_t
name|an_ethertype3
decl_stmt|;
name|u_int16_t
name|an_action3
decl_stmt|;
name|u_int16_t
name|an_ethertype4
decl_stmt|;
name|u_int16_t
name|an_action4
decl_stmt|;
name|u_int16_t
name|an_ethertype5
decl_stmt|;
name|u_int16_t
name|an_action5
decl_stmt|;
name|u_int16_t
name|an_ethertype6
decl_stmt|;
name|u_int16_t
name|an_action6
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_ENCAP_ACTION_RX
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_ENCAP_ACTION_TX
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_RXENCAP_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_RXENCAP_RFC1024
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_TXENCAP_RFC1024
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_TXENCAP_80211
value|0x0002
end_define

begin_comment
comment|/*  * Actual config, same structure as general config (read only).  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_ACTUALCFG
value|0xFF20
end_define

begin_comment
comment|/*  * Card capabilities (read only).  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_CAPABILITIES
value|0xFF00
end_define

begin_struct
struct|struct
name|an_ltv_caps
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* XXXX */
name|u_int8_t
name|an_oui
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x02 */
name|u_int8_t
name|an_rsvd0
decl_stmt|;
comment|/* 0x05 */
name|u_int16_t
name|an_prodnum
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|an_manufname
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_prodname
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x28 */
name|u_int8_t
name|an_prodvers
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_oemaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x40 */
name|u_int8_t
name|an_aironetaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x46 */
name|u_int16_t
name|an_radiotype
decl_stmt|;
comment|/* 0x4C */
name|u_int16_t
name|an_regdomain
decl_stmt|;
comment|/* 0x4E */
name|u_int8_t
name|an_callid
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x50 */
name|u_int8_t
name|an_rates
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x56 */
name|u_int8_t
name|an_rx_diversity
decl_stmt|;
comment|/* 0x5E */
name|u_int8_t
name|an_tx_diversity
decl_stmt|;
comment|/* 0x5F */
name|u_int16_t
name|an_tx_powerlevels
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_hwrev
decl_stmt|;
comment|/* 0x70 */
name|u_int16_t
name|an_hwcaps
decl_stmt|;
comment|/* 0x72 */
name|u_int16_t
name|an_temprange
decl_stmt|;
comment|/* 0x74 */
name|u_int16_t
name|an_fwrev
decl_stmt|;
comment|/* 0x76 */
name|u_int16_t
name|an_fwsubrev
decl_stmt|;
comment|/* 0x78 */
name|u_int16_t
name|an_ifacerev
decl_stmt|;
comment|/* 0x7A */
name|u_int16_t
name|an_softcaps
decl_stmt|;
comment|/* 0x7C */
name|u_int16_t
name|an_bootblockrev
decl_stmt|;
comment|/* 0x7E */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Access point (read only)  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_APINFO
value|0xFF01
end_define

begin_struct
struct|struct
name|an_ltv_apinfo
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
name|u_int16_t
name|an_tim_addr
decl_stmt|;
name|u_int16_t
name|an_airo_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Radio info (read only).  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_RADIOINFO
value|0xFF02
end_define

begin_struct
struct|struct
name|an_ltv_radioinfo
block|{
name|u_int16_t
name|an_len
decl_stmt|;
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* ??? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status (read only). Note: the manual claims this RID is 108 bytes  * long (0x6A is the last datum, which is 2 bytes long) however when  * this RID is read from the NIC, it returns a length of 110. To be  * on the safe side, this structure is padded with an extra 16-bit  * word. (There is a misprint in the manual which says the macaddr  * field is 8 bytes long.)  *  * Also, the channel_set and current_channel fields appear to be  * reversed. Either that, or the hop_period field is unused.  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_STATUS
value|0xFF50
end_define

begin_struct
struct|struct
name|an_ltv_status
block|{
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int8_t
name|an_macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x02 */
name|u_int16_t
name|an_opmode
decl_stmt|;
comment|/* 0x08 */
name|u_int16_t
name|an_errcode
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|an_cur_signal_quality
decl_stmt|;
comment|/* 0x0C */
name|u_int16_t
name|an_ssidlen
decl_stmt|;
comment|/* 0x0E */
name|u_int8_t
name|an_ssid
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|an_ap_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x30 */
name|u_int8_t
name|an_cur_bssid
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x40 */
name|u_int8_t
name|an_prev_bssid1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x46 */
name|u_int8_t
name|an_prev_bssid2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x4C */
name|u_int8_t
name|an_prev_bssid3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x52 */
name|u_int16_t
name|an_beacon_period
decl_stmt|;
comment|/* 0x58 */
name|u_int16_t
name|an_dtim_period
decl_stmt|;
comment|/* 0x5A */
name|u_int16_t
name|an_atim_duration
decl_stmt|;
comment|/* 0x5C */
name|u_int16_t
name|an_hop_period
decl_stmt|;
comment|/* 0x5E */
name|u_int16_t
name|an_cur_channel
decl_stmt|;
comment|/* 0x62 */
name|u_int16_t
name|an_channel_set
decl_stmt|;
comment|/* 0x60 */
name|u_int16_t
name|an_hops_to_backbone
decl_stmt|;
comment|/* 0x64 */
name|u_int16_t
name|an_ap_total_load
decl_stmt|;
comment|/* 0x66 */
name|u_int16_t
name|an_our_generated_load
decl_stmt|;
comment|/* 0x68 */
name|u_int16_t
name|an_accumulated_arl
decl_stmt|;
comment|/* 0x6A */
name|u_int16_t
name|an_rsvd0
index|[
literal|10
index|]
decl_stmt|;
comment|/* 0x6C */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_CONFIGURED
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_MAC_ENABLED
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_RX_ENABLED
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_IN_SYNC
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_ASSOCIATED
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_STATUS_OPMODE_ERROR
value|0x8000
end_define

begin_comment
comment|/*  * Statistics  */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_CUM
value|0xFF60
end_define

begin_comment
comment|/* Cumulative 16-bit stats counters */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_DELTA
value|0xFF61
end_define

begin_comment
comment|/* 16-bit stats (since last clear) */
end_comment

begin_define
define|#
directive|define
name|AN_RID_16BITS_DELTACLR
value|0xFF62
end_define

begin_comment
comment|/* 16-bit stats, clear on read */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_CUM
value|0xFF68
end_define

begin_comment
comment|/* Cumulative 32-bit stats counters */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_DELTA
value|0xFF69
end_define

begin_comment
comment|/* 32-bit stats (since last clear) */
end_comment

begin_define
define|#
directive|define
name|AN_RID_32BITS_DELTACLR
value|0xFF6A
end_define

begin_comment
comment|/* 32-bit stats, clear on read */
end_comment

begin_comment
comment|/*  * Grrr. The manual says the statistics record is 384 bytes in length,  * but the card says the record is 404 bytes. There's some padding left  * at the end of this structure to account for any discrepancies.  */
end_comment

begin_struct
struct|struct
name|an_ltv_stats
block|{
name|u_int16_t
name|an_fudge
decl_stmt|;
name|u_int16_t
name|an_len
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_type
decl_stmt|;
comment|/* 0xXX */
name|u_int16_t
name|an_spacer
decl_stmt|;
comment|/* 0x02 */
name|u_int32_t
name|an_rx_overruns
decl_stmt|;
comment|/* 0x04 */
name|u_int32_t
name|an_rx_plcp_csum_errs
decl_stmt|;
comment|/* 0x08 */
name|u_int32_t
name|an_rx_plcp_format_errs
decl_stmt|;
comment|/* 0x0C */
name|u_int32_t
name|an_rx_plcp_len_errs
decl_stmt|;
comment|/* 0x10 */
name|u_int32_t
name|an_rx_mac_crc_errs
decl_stmt|;
comment|/* 0x14 */
name|u_int32_t
name|an_rx_mac_crc_ok
decl_stmt|;
comment|/* 0x18 */
name|u_int32_t
name|an_rx_wep_errs
decl_stmt|;
comment|/* 0x1C */
name|u_int32_t
name|an_rx_wep_ok
decl_stmt|;
comment|/* 0x20 */
name|u_int32_t
name|an_retry_long
decl_stmt|;
comment|/* 0x24 */
name|u_int32_t
name|an_retry_short
decl_stmt|;
comment|/* 0x28 */
name|u_int32_t
name|an_retry_max
decl_stmt|;
comment|/* 0x2C */
name|u_int32_t
name|an_no_ack
decl_stmt|;
comment|/* 0x30 */
name|u_int32_t
name|an_no_cts
decl_stmt|;
comment|/* 0x34 */
name|u_int32_t
name|an_rx_ack_ok
decl_stmt|;
comment|/* 0x38 */
name|u_int32_t
name|an_rx_cts_ok
decl_stmt|;
comment|/* 0x3C */
name|u_int32_t
name|an_tx_ack_ok
decl_stmt|;
comment|/* 0x40 */
name|u_int32_t
name|an_tx_rts_ok
decl_stmt|;
comment|/* 0x44 */
name|u_int32_t
name|an_tx_cts_ok
decl_stmt|;
comment|/* 0x48 */
name|u_int32_t
name|an_tx_lmac_mcasts
decl_stmt|;
comment|/* 0x4C */
name|u_int32_t
name|an_tx_lmac_bcasts
decl_stmt|;
comment|/* 0x50 */
name|u_int32_t
name|an_tx_lmac_ucast_frags
decl_stmt|;
comment|/* 0x54 */
name|u_int32_t
name|an_tx_lmac_ucasts
decl_stmt|;
comment|/* 0x58 */
name|u_int32_t
name|an_tx_beacons
decl_stmt|;
comment|/* 0x5C */
name|u_int32_t
name|an_rx_beacons
decl_stmt|;
comment|/* 0x60 */
name|u_int32_t
name|an_tx_single_cols
decl_stmt|;
comment|/* 0x64 */
name|u_int32_t
name|an_tx_multi_cols
decl_stmt|;
comment|/* 0x68 */
name|u_int32_t
name|an_tx_defers_no
decl_stmt|;
comment|/* 0x6C */
name|u_int32_t
name|an_tx_defers_prot
decl_stmt|;
comment|/* 0x70 */
name|u_int32_t
name|an_tx_defers_energy
decl_stmt|;
comment|/* 0x74 */
name|u_int32_t
name|an_rx_dups
decl_stmt|;
comment|/* 0x78 */
name|u_int32_t
name|an_rx_partial
decl_stmt|;
comment|/* 0x7C */
name|u_int32_t
name|an_tx_too_old
decl_stmt|;
comment|/* 0x80 */
name|u_int32_t
name|an_rx_too_old
decl_stmt|;
comment|/* 0x84 */
name|u_int32_t
name|an_lostsync_max_retries
decl_stmt|;
comment|/* 0x88 */
name|u_int32_t
name|an_lostsync_missed_beacons
decl_stmt|;
comment|/* 0x8C */
name|u_int32_t
name|an_lostsync_arl_exceeded
decl_stmt|;
comment|/*0x90 */
name|u_int32_t
name|an_lostsync_deauthed
decl_stmt|;
comment|/* 0x94 */
name|u_int32_t
name|an_lostsync_disassociated
decl_stmt|;
comment|/*0x98 */
name|u_int32_t
name|an_lostsync_tsf_timing
decl_stmt|;
comment|/* 0x9C */
name|u_int32_t
name|an_tx_host_mcasts
decl_stmt|;
comment|/* 0xA0 */
name|u_int32_t
name|an_tx_host_bcasts
decl_stmt|;
comment|/* 0xA4 */
name|u_int32_t
name|an_tx_host_ucasts
decl_stmt|;
comment|/* 0xA8 */
name|u_int32_t
name|an_tx_host_failed
decl_stmt|;
comment|/* 0xAC */
name|u_int32_t
name|an_rx_host_mcasts
decl_stmt|;
comment|/* 0xB0 */
name|u_int32_t
name|an_rx_host_bcasts
decl_stmt|;
comment|/* 0xB4 */
name|u_int32_t
name|an_rx_host_ucasts
decl_stmt|;
comment|/* 0xB8 */
name|u_int32_t
name|an_rx_host_discarded
decl_stmt|;
comment|/* 0xBC */
name|u_int32_t
name|an_tx_hmac_mcasts
decl_stmt|;
comment|/* 0xC0 */
name|u_int32_t
name|an_tx_hmac_bcasts
decl_stmt|;
comment|/* 0xC4 */
name|u_int32_t
name|an_tx_hmac_ucasts
decl_stmt|;
comment|/* 0xC8 */
name|u_int32_t
name|an_tx_hmac_failed
decl_stmt|;
comment|/* 0xCC */
name|u_int32_t
name|an_rx_hmac_mcasts
decl_stmt|;
comment|/* 0xD0 */
name|u_int32_t
name|an_rx_hmac_bcasts
decl_stmt|;
comment|/* 0xD4 */
name|u_int32_t
name|an_rx_hmac_ucasts
decl_stmt|;
comment|/* 0xD8 */
name|u_int32_t
name|an_rx_hmac_discarded
decl_stmt|;
comment|/* 0xDC */
name|u_int32_t
name|an_tx_hmac_accepted
decl_stmt|;
comment|/* 0xE0 */
name|u_int32_t
name|an_ssid_mismatches
decl_stmt|;
comment|/* 0xE4 */
name|u_int32_t
name|an_ap_mismatches
decl_stmt|;
comment|/* 0xE8 */
name|u_int32_t
name|an_rates_mismatches
decl_stmt|;
comment|/* 0xEC */
name|u_int32_t
name|an_auth_rejects
decl_stmt|;
comment|/* 0xF0 */
name|u_int32_t
name|an_auth_timeouts
decl_stmt|;
comment|/* 0xF4 */
name|u_int32_t
name|an_assoc_rejects
decl_stmt|;
comment|/* 0xF8 */
name|u_int32_t
name|an_assoc_timeouts
decl_stmt|;
comment|/* 0xFC */
name|u_int32_t
name|an_reason_outside_table
decl_stmt|;
comment|/* 0x100 */
name|u_int32_t
name|an_reason1
decl_stmt|;
comment|/* 0x104 */
name|u_int32_t
name|an_reason2
decl_stmt|;
comment|/* 0x108 */
name|u_int32_t
name|an_reason3
decl_stmt|;
comment|/* 0x10C */
name|u_int32_t
name|an_reason4
decl_stmt|;
comment|/* 0x110 */
name|u_int32_t
name|an_reason5
decl_stmt|;
comment|/* 0x114 */
name|u_int32_t
name|an_reason6
decl_stmt|;
comment|/* 0x118 */
name|u_int32_t
name|an_reason7
decl_stmt|;
comment|/* 0x11C */
name|u_int32_t
name|an_reason8
decl_stmt|;
comment|/* 0x120 */
name|u_int32_t
name|an_reason9
decl_stmt|;
comment|/* 0x124 */
name|u_int32_t
name|an_reason10
decl_stmt|;
comment|/* 0x128 */
name|u_int32_t
name|an_reason11
decl_stmt|;
comment|/* 0x12C */
name|u_int32_t
name|an_reason12
decl_stmt|;
comment|/* 0x130 */
name|u_int32_t
name|an_reason13
decl_stmt|;
comment|/* 0x134 */
name|u_int32_t
name|an_reason14
decl_stmt|;
comment|/* 0x138 */
name|u_int32_t
name|an_reason15
decl_stmt|;
comment|/* 0x13C */
name|u_int32_t
name|an_reason16
decl_stmt|;
comment|/* 0x140 */
name|u_int32_t
name|an_reason17
decl_stmt|;
comment|/* 0x144 */
name|u_int32_t
name|an_reason18
decl_stmt|;
comment|/* 0x148 */
name|u_int32_t
name|an_reason19
decl_stmt|;
comment|/* 0x14C */
name|u_int32_t
name|an_rx_mgmt_pkts
decl_stmt|;
comment|/* 0x150 */
name|u_int32_t
name|an_tx_mgmt_pkts
decl_stmt|;
comment|/* 0x154 */
name|u_int32_t
name|an_rx_refresh_pkts
decl_stmt|;
comment|/* 0x158 */
name|u_int32_t
name|an_tx_refresh_pkts
decl_stmt|;
comment|/* 0x15C */
name|u_int32_t
name|an_rx_poll_pkts
decl_stmt|;
comment|/* 0x160 */
name|u_int32_t
name|an_tx_poll_pkts
decl_stmt|;
comment|/* 0x164 */
name|u_int32_t
name|an_host_retries
decl_stmt|;
comment|/* 0x168 */
name|u_int32_t
name|an_lostsync_hostreq
decl_stmt|;
comment|/* 0x16C */
name|u_int32_t
name|an_host_tx_bytes
decl_stmt|;
comment|/* 0x170 */
name|u_int32_t
name|an_host_rx_bytes
decl_stmt|;
comment|/* 0x174 */
name|u_int32_t
name|an_uptime_usecs
decl_stmt|;
comment|/* 0x178 */
name|u_int32_t
name|an_uptime_secs
decl_stmt|;
comment|/* 0x17C */
name|u_int32_t
name|an_lostsync_better_ap
decl_stmt|;
comment|/* 0x180 */
name|u_int32_t
name|an_rsvd
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receive frame structure.  */
end_comment

begin_struct
struct|struct
name|an_rxframe
block|{
name|u_int32_t
name|an_rx_time
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_rx_status
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_rx_payload_len
decl_stmt|;
comment|/* 0x06 */
name|u_int8_t
name|an_rsvd0
decl_stmt|;
comment|/* 0x08 */
name|u_int8_t
name|an_rx_signal_strength
decl_stmt|;
comment|/* 0x09 */
name|u_int8_t
name|an_rx_rate
decl_stmt|;
comment|/* 0x0A */
name|u_int8_t
name|an_rx_chan
decl_stmt|;
comment|/* 0x0B */
name|u_int8_t
name|an_rx_assoc_cnt
decl_stmt|;
comment|/* 0x0C */
name|u_int8_t
name|an_rsvd1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x0D */
name|u_int8_t
name|an_plcp_hdr
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x10 */
name|u_int16_t
name|an_frame_ctl
decl_stmt|;
comment|/* 0x14 */
name|u_int16_t
name|an_duration
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|an_addr1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x18 */
name|u_int8_t
name|an_addr2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x1E */
name|u_int8_t
name|an_addr3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_seq_ctl
decl_stmt|;
comment|/* 0x2A */
name|u_int8_t
name|an_addr4
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x2C */
name|u_int16_t
name|an_gaplen
decl_stmt|;
comment|/* 0x32 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_RXGAP_MAX
value|8
end_define

begin_comment
comment|/*  * Transmit frame structure.  */
end_comment

begin_struct
struct|struct
name|an_txframe
block|{
name|u_int32_t
name|an_tx_sw
decl_stmt|;
comment|/* 0x00 */
name|u_int16_t
name|an_tx_status
decl_stmt|;
comment|/* 0x04 */
name|u_int16_t
name|an_tx_payload_len
decl_stmt|;
comment|/* 0x06 */
name|u_int16_t
name|an_tx_ctl
decl_stmt|;
comment|/* 0x08 */
name|u_int16_t
name|an_tx_assoc_id
decl_stmt|;
comment|/* 0x0A */
name|u_int16_t
name|an_tx_retry
decl_stmt|;
comment|/* 0x0C */
name|u_int8_t
name|an_tx_assoc_cnt
decl_stmt|;
comment|/* 0x0E */
name|u_int8_t
name|an_tx_rate
decl_stmt|;
comment|/* 0x0F */
name|u_int8_t
name|an_tx_max_long_retries
decl_stmt|;
comment|/* 0x10 */
name|u_int8_t
name|an_tx_max_short_retries
decl_stmt|;
comment|/*0x11 */
name|u_int8_t
name|an_rsvd0
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x12 */
name|u_int16_t
name|an_frame_ctl
decl_stmt|;
comment|/* 0x14 */
name|u_int16_t
name|an_duration
decl_stmt|;
comment|/* 0x16 */
name|u_int8_t
name|an_addr1
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x18 */
name|u_int8_t
name|an_addr2
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x1E */
name|u_int8_t
name|an_addr3
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x24 */
name|u_int16_t
name|an_seq_ctl
decl_stmt|;
comment|/* 0x2A */
name|u_int8_t
name|an_addr4
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x2C */
name|u_int16_t
name|an_gaplen
decl_stmt|;
comment|/* 0x32 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_rxframe_802_3
block|{
name|u_int16_t
name|an_rx_802_3_status
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_rx_802_3_payload_len
decl_stmt|;
comment|/* 0x36 */
name|u_int8_t
name|an_rx_dst_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_rx_src_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x3E */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_RXGAP_MAX
value|8
end_define

begin_struct
struct|struct
name|an_txframe_802_3
block|{
comment|/*  * Transmit 802.3 header structure.  */
name|u_int16_t
name|an_tx_802_3_status
decl_stmt|;
comment|/* 0x34 */
name|u_int16_t
name|an_tx_802_3_payload_len
decl_stmt|;
comment|/* 0x36 */
name|u_int8_t
name|an_tx_dst_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x38 */
name|u_int8_t
name|an_tx_src_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 0x3E */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_TXSTAT_EXCESS_RETRY
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_LIFE_EXCEEDED
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_AID_FAIL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_MAC_DISABLED
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXSTAT_ASSOC_LOST
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_RSVD
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_TXOK_INTR
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_TXERR_INTR
value|0x0004
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_HEADER_TYPE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_PAYLOAD_TYPE
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_NORELEASE
value|0x0020
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_NORETRIES
value|0x0040
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_CLEAR_AID
value|0x0080
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_STRICT_ORDER
value|0x0100
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_USE_RTS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AN_HEADERTYPE_8023
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_HEADERTYPE_80211
value|0x0008
end_define

begin_define
define|#
directive|define
name|AN_PAYLOADTYPE_ETHER
value|0x0000
end_define

begin_define
define|#
directive|define
name|AN_PAYLOADTYPE_LLC
value|0x0010
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_80211
define|\
value|(AN_TXCTL_TXOK_INTR|AN_TXCTL_TXERR_INTR|AN_HEADERTYPE_80211|	\ 	AN_PAYLOADTYPE_LLC|AN_TXCTL_NORELEASE)
end_define

begin_define
define|#
directive|define
name|AN_TXCTL_8023
define|\
value|(AN_TXCTL_TXOK_INTR|AN_TXCTL_TXERR_INTR|AN_HEADERTYPE_8023|	\ 	AN_PAYLOADTYPE_ETHER|AN_TXCTL_NORELEASE)
end_define

begin_define
define|#
directive|define
name|AN_TXGAP_80211
value|0
end_define

begin_define
define|#
directive|define
name|AN_TXGAP_8023
value|0
end_define

begin_struct
struct|struct
name|an_802_3_hdr
block|{
name|u_int16_t
name|an_8023_status
decl_stmt|;
name|u_int16_t
name|an_8023_payload_len
decl_stmt|;
name|u_int8_t
name|an_8023_dst_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|an_8023_src_addr
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|an_8023_dat
index|[
literal|3
index|]
decl_stmt|;
comment|/* SNAP header */
name|u_int16_t
name|an_8023_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_snap_hdr
block|{
name|u_int16_t
name|an_snap_dat
index|[
literal|3
index|]
decl_stmt|;
comment|/* SNAP header */
name|u_int16_t
name|an_snap_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AN_TX_RING_CNT
value|4
end_define

begin_define
define|#
directive|define
name|AN_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|an_tx_ring_data
block|{
name|u_int16_t
name|an_tx_fids
index|[
name|AN_TX_RING_CNT
index|]
decl_stmt|;
name|u_int16_t
name|an_tx_ring
index|[
name|AN_TX_RING_CNT
index|]
decl_stmt|;
name|int
name|an_tx_prod
decl_stmt|;
name|int
name|an_tx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|an_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|int
name|an_unit
decl_stmt|;
name|int
name|port_rid
decl_stmt|;
comment|/* resource id for port range */
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
comment|/* resource for port range */
name|int
name|irq_rid
decl_stmt|;
comment|/* resource id for irq */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* resource for irq */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* handle for irq handler */
name|bus_space_handle_t
name|an_bhandle_p
decl_stmt|;
name|bus_space_handle_t
name|an_bhandle
decl_stmt|;
name|bus_space_tag_t
name|an_btag
decl_stmt|;
name|struct
name|an_ltv_genconfig
name|an_config
decl_stmt|;
name|struct
name|an_ltv_caps
name|an_caps
decl_stmt|;
name|struct
name|an_ltv_ssidlist
name|an_ssidlist
decl_stmt|;
name|struct
name|an_ltv_aplist
name|an_aplist
decl_stmt|;
name|int
name|an_tx_rate
decl_stmt|;
name|int
name|an_rxmode
decl_stmt|;
name|int
name|an_gone
decl_stmt|;
name|int
name|an_if_flags
decl_stmt|;
name|u_int8_t
name|an_txbuf
index|[
literal|1536
index|]
decl_stmt|;
name|struct
name|an_tx_ring_data
name|an_rdata
decl_stmt|;
name|struct
name|an_ltv_stats
name|an_stats
decl_stmt|;
name|struct
name|an_ltv_status
name|an_status
decl_stmt|;
name|u_int8_t
name|an_associated
decl_stmt|;
ifdef|#
directive|ifdef
name|ANCACHE
name|int
name|an_sigitems
decl_stmt|;
name|struct
name|an_sigcache
name|an_sigcache
index|[
name|MAXANCACHE
index|]
decl_stmt|;
name|int
name|an_nextitem
decl_stmt|;
endif|#
directive|endif
name|struct
name|callout_handle
name|an_stat_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|an_release_resources
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|an_alloc_port
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|an_alloc_memory
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|an_alloc_irq
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|an_probe
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|an_shutdown
name|__P
argument_list|(
operator|(
name|device_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|an_attach
name|__P
argument_list|(
operator|(
expr|struct
name|an_softc
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|an_stop
name|__P
argument_list|(
operator|(
expr|struct
name|an_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|driver_intr_t
name|an_intr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AN_802_3_OFFSET
value|0x2E
end_define

begin_define
define|#
directive|define
name|AN_802_11_OFFSET
value|0x44
end_define

begin_define
define|#
directive|define
name|AN_802_11_OFFSET_RAW
value|0x3C
end_define

begin_define
define|#
directive|define
name|AN_STAT_BADCRC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AN_STAT_UNDECRYPTABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|AN_STAT_ERRSTAT
value|0x0003
end_define

begin_define
define|#
directive|define
name|AN_STAT_MAC_PORT
value|0x0700
end_define

begin_define
define|#
directive|define
name|AN_STAT_1042
value|0x2000
end_define

begin_comment
comment|/* RFC1042 encoded */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_TUNNEL
value|0x4000
end_define

begin_comment
comment|/* Bridge-tunnel encoded */
end_comment

begin_define
define|#
directive|define
name|AN_STAT_WMP_MSG
value|0x6000
end_define

begin_comment
comment|/* WaveLAN-II management protocol */
end_comment

begin_define
define|#
directive|define
name|AN_RXSTAT_MSG_TYPE
value|0xE000
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_802_3
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_802_11
value|0x11
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_E_II
value|0x0E
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_1042
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_ENC_TX_TUNNEL
value|0xF8
end_define

begin_define
define|#
directive|define
name|AN_TXCNTL_MACPORT
value|0x00FF
end_define

begin_define
define|#
directive|define
name|AN_TXCNTL_STRUCTTYPE
value|0xFF00
end_define

begin_comment
comment|/*  * SNAP (sub-network access protocol) constants for transmission  * of IP datagrams over IEEE 802 networks, taken from RFC1042.  * We need these for the LLC/SNAP header fields in the TX/RX frame  * structure.  */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_K1
value|0xaa
end_define

begin_comment
comment|/* assigned global SAP for SNAP */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_K2
value|0x00
end_define

begin_define
define|#
directive|define
name|AN_SNAP_CONTROL
value|0x03
end_define

begin_comment
comment|/* unnumbered information format */
end_comment

begin_define
define|#
directive|define
name|AN_SNAP_WORD0
value|(AN_SNAP_K1 | (AN_SNAP_K1<< 8))
end_define

begin_define
define|#
directive|define
name|AN_SNAP_WORD1
value|(AN_SNAP_K2 | (AN_SNAP_CONTROL<< 8))
end_define

begin_define
define|#
directive|define
name|AN_SNAPHDR_LEN
value|0x6
end_define

end_unit

