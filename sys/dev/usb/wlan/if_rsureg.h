begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_rsureg.h,v 1.3 2013/04/15 09:23:01 mglocker Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/* USB Requests. */
end_comment

begin_define
define|#
directive|define
name|R92S_REQ_REGS
value|0x05
end_define

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_define
define|#
directive|define
name|R92S_SYSCFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|R92S_SYS_ISO_CTRL
value|(R92S_SYSCFG + 0x000)
end_define

begin_define
define|#
directive|define
name|R92S_SYS_FUNC_EN
value|(R92S_SYSCFG + 0x002)
end_define

begin_define
define|#
directive|define
name|R92S_PMC_FSM
value|(R92S_SYSCFG + 0x004)
end_define

begin_define
define|#
directive|define
name|R92S_SYS_CLKR
value|(R92S_SYSCFG + 0x008)
end_define

begin_define
define|#
directive|define
name|R92S_EE_9346CR
value|(R92S_SYSCFG + 0x00a)
end_define

begin_define
define|#
directive|define
name|R92S_AFE_MISC
value|(R92S_SYSCFG + 0x010)
end_define

begin_define
define|#
directive|define
name|R92S_SPS0_CTRL
value|(R92S_SYSCFG + 0x011)
end_define

begin_define
define|#
directive|define
name|R92S_SPS1_CTRL
value|(R92S_SYSCFG + 0x018)
end_define

begin_define
define|#
directive|define
name|R92S_RF_CTRL
value|(R92S_SYSCFG + 0x01f)
end_define

begin_define
define|#
directive|define
name|R92S_LDOA15_CTRL
value|(R92S_SYSCFG + 0x020)
end_define

begin_define
define|#
directive|define
name|R92S_LDOV12D_CTRL
value|(R92S_SYSCFG + 0x021)
end_define

begin_define
define|#
directive|define
name|R92S_AFE_XTAL_CTRL
value|(R92S_SYSCFG + 0x026)
end_define

begin_define
define|#
directive|define
name|R92S_AFE_PLL_CTRL
value|(R92S_SYSCFG + 0x028)
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL
value|(R92S_SYSCFG + 0x030)
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_TEST
value|(R92S_SYSCFG + 0x034)
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CLK_CTRL
value|(R92S_SYSCFG + 0x2f8)
end_define

begin_define
define|#
directive|define
name|R92S_CMDCTRL
value|0x0040
end_define

begin_define
define|#
directive|define
name|R92S_CR
value|(R92S_CMDCTRL + 0x000)
end_define

begin_define
define|#
directive|define
name|R92S_TCR
value|(R92S_CMDCTRL + 0x004)
end_define

begin_define
define|#
directive|define
name|R92S_RCR
value|(R92S_CMDCTRL + 0x008)
end_define

begin_define
define|#
directive|define
name|R92S_MACIDSETTING
value|0x0050
end_define

begin_define
define|#
directive|define
name|R92S_MACID
value|(R92S_MACIDSETTING + 0x000)
end_define

begin_define
define|#
directive|define
name|R92S_GP
value|0x01e0
end_define

begin_define
define|#
directive|define
name|R92S_GPIO_CTRL
value|(R92S_GP + 0x00c)
end_define

begin_define
define|#
directive|define
name|R92S_GPIO_IO_SEL
value|(R92S_GP + 0x00e)
end_define

begin_define
define|#
directive|define
name|R92S_MAC_PINMUX_CTRL
value|(R92S_GP + 0x011)
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_CTRL
value|0x0370
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_DATA
value|0x0374
end_define

begin_define
define|#
directive|define
name|R92S_USB_HRPWM
value|0xfe58
end_define

begin_comment
comment|/* Bits for R92S_SYS_FUNC_EN. */
end_comment

begin_define
define|#
directive|define
name|R92S_FEN_CPUEN
value|0x0400
end_define

begin_comment
comment|/* Bits for R92S_PMC_FSM. */
end_comment

begin_define
define|#
directive|define
name|R92S_PMC_FSM_CUT_M
value|0x000f8000
end_define

begin_define
define|#
directive|define
name|R92S_PMC_FSM_CUT_S
value|15
end_define

begin_comment
comment|/* Bits for R92S_SYS_CLKR. */
end_comment

begin_define
define|#
directive|define
name|R92S_SYS_CLKSEL
value|0x0001
end_define

begin_define
define|#
directive|define
name|R92S_SYS_PS_CLKSEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|R92S_SYS_CPU_CLKSEL
value|0x0004
end_define

begin_define
define|#
directive|define
name|R92S_MAC_CLK_EN
value|0x0800
end_define

begin_define
define|#
directive|define
name|R92S_SYS_CLK_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|R92S_SWHW_SEL
value|0x4000
end_define

begin_define
define|#
directive|define
name|R92S_FWHW_SEL
value|0x8000
end_define

begin_comment
comment|/* Bits for R92S_EE_9346CR. */
end_comment

begin_define
define|#
directive|define
name|R92S_9356SEL
value|0x10
end_define

begin_define
define|#
directive|define
name|R92S_EEPROM_EN
value|0x20
end_define

begin_comment
comment|/* Bits for R92S_AFE_MISC. */
end_comment

begin_define
define|#
directive|define
name|R92S_AFE_MISC_BGEN
value|0x01
end_define

begin_define
define|#
directive|define
name|R92S_AFE_MISC_MBEN
value|0x02
end_define

begin_define
define|#
directive|define
name|R92S_AFE_MISC_I32_EN
value|0x08
end_define

begin_comment
comment|/* Bits for R92S_SPS1_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_SPS1_LDEN
value|0x01
end_define

begin_define
define|#
directive|define
name|R92S_SPS1_SWEN
value|0x02
end_define

begin_comment
comment|/* Bits for R92S_LDOA15_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_LDA15_EN
value|0x01
end_define

begin_comment
comment|/* Bits for R92S_LDOV12D_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_LDV12_EN
value|0x01
end_define

begin_comment
comment|/* Bits for R92C_EFUSE_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL_DATA_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL_DATA_S
value|0
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL_ADDR_M
value|0x0003ff00
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL_ADDR_S
value|8
end_define

begin_define
define|#
directive|define
name|R92S_EFUSE_CTRL_VALID
value|0x80000000
end_define

begin_comment
comment|/* Bits for R92S_CR. */
end_comment

begin_define
define|#
directive|define
name|R92S_CR_TXDMA_EN
value|0x10
end_define

begin_comment
comment|/* Bits for R92S_TCR. */
end_comment

begin_define
define|#
directive|define
name|R92S_TCR_IMEM_CODE_DONE
value|0x01
end_define

begin_define
define|#
directive|define
name|R92S_TCR_IMEM_CHK_RPT
value|0x02
end_define

begin_define
define|#
directive|define
name|R92S_TCR_EMEM_CODE_DONE
value|0x04
end_define

begin_define
define|#
directive|define
name|R92S_TCR_EMEM_CHK_RPT
value|0x08
end_define

begin_define
define|#
directive|define
name|R92S_TCR_DMEM_CODE_DONE
value|0x10
end_define

begin_define
define|#
directive|define
name|R92S_TCR_IMEM_RDY
value|0x20
end_define

begin_define
define|#
directive|define
name|R92S_TCR_FWRDY
value|0x80
end_define

begin_comment
comment|/* Bits for R92S_GPIO_IO_SEL. */
end_comment

begin_define
define|#
directive|define
name|R92S_GPIO_WPS
value|0x10
end_define

begin_comment
comment|/* Bits for R92S_MAC_PINMUX_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_M
value|0x03
end_define

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_S
value|0
end_define

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_JTAG
value|0
end_define

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_PHYDBG
value|1
end_define

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_BT
value|2
end_define

begin_define
define|#
directive|define
name|R92S_GPIOSEL_GPIO_WLANDBG
value|3
end_define

begin_define
define|#
directive|define
name|R92S_GPIOMUX_EN
value|0x08
end_define

begin_comment
comment|/* Bits for R92S_IOCMD_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R92S_IOCMD_CLASS_M
value|0xff000000
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_CLASS_S
value|24
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_CLASS_BB_RF
value|0xf0
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_VALUE_M
value|0x00ffff00
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_VALUE_S
value|8
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_S
value|0
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_BB_READ
value|0
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_BB_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_RF_READ
value|2
end_define

begin_define
define|#
directive|define
name|R92S_IOCMD_INDEX_RF_WRITE
value|3
end_define

begin_comment
comment|/* Bits for R92S_USB_HRPWM. */
end_comment

begin_define
define|#
directive|define
name|R92S_USB_HRPWM_PS_ALL_ON
value|0x04
end_define

begin_define
define|#
directive|define
name|R92S_USB_HRPWM_PS_ST_ACTIVE
value|0x08
end_define

begin_comment
comment|/*  * Macros to access subfields in registers.  */
end_comment

begin_comment
comment|/* Mask and Shift (getter). */
end_comment

begin_define
define|#
directive|define
name|MS
parameter_list|(
name|val
parameter_list|,
name|field
parameter_list|)
define|\
value|(((val)& field##_M)>> field##_S)
end_define

begin_comment
comment|/* Shift and Mask (setter). */
end_comment

begin_define
define|#
directive|define
name|SM
parameter_list|(
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|(((val)<< field##_S)& field##_M)
end_define

begin_comment
comment|/* Rewrite. */
end_comment

begin_define
define|#
directive|define
name|RW
parameter_list|(
name|var
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
define|\
value|(((var)& ~field##_M) | SM(field, val))
end_define

begin_comment
comment|/*  * Firmware image header.  */
end_comment

begin_struct
struct|struct
name|r92s_fw_priv
block|{
comment|/* QWORD0 */
name|uint16_t
name|signature
decl_stmt|;
name|uint8_t
name|hci_sel
decl_stmt|;
define|#
directive|define
name|R92S_HCI_SEL_PCIE
value|0x01
define|#
directive|define
name|R92S_HCI_SEL_USB
value|0x02
define|#
directive|define
name|R92S_HCI_SEL_SDIO
value|0x04
define|#
directive|define
name|R92S_HCI_SEL_8172
value|0x10
define|#
directive|define
name|R92S_HCI_SEL_AP
value|0x80
name|uint8_t
name|chip_version
decl_stmt|;
name|uint16_t
name|custid
decl_stmt|;
name|uint8_t
name|rf_config
decl_stmt|;
name|uint8_t
name|nendpoints
decl_stmt|;
comment|/* QWORD1 */
name|uint32_t
name|regulatory
decl_stmt|;
name|uint8_t
name|rfintfs
decl_stmt|;
name|uint8_t
name|def_nettype
decl_stmt|;
name|uint8_t
name|turbo_mode
decl_stmt|;
name|uint8_t
name|lowpower_mode
decl_stmt|;
comment|/* QWORD2 */
name|uint8_t
name|lbk_mode
decl_stmt|;
name|uint8_t
name|mp_mode
decl_stmt|;
name|uint8_t
name|vcs_type
decl_stmt|;
define|#
directive|define
name|R92S_VCS_TYPE_DISABLE
value|0
define|#
directive|define
name|R92S_VCS_TYPE_ENABLE
value|1
define|#
directive|define
name|R92S_VCS_TYPE_AUTO
value|2
name|uint8_t
name|vcs_mode
decl_stmt|;
define|#
directive|define
name|R92S_VCS_MODE_NONE
value|0
define|#
directive|define
name|R92S_VCS_MODE_RTS_CTS
value|1
define|#
directive|define
name|R92S_VCS_MODE_CTS2SELF
value|2
name|uint32_t
name|reserved1
decl_stmt|;
comment|/* QWORD3 */
name|uint8_t
name|qos_en
decl_stmt|;
name|uint8_t
name|bw40_en
decl_stmt|;
name|uint8_t
name|amsdu2ampdu_en
decl_stmt|;
name|uint8_t
name|ampdu_en
decl_stmt|;
name|uint8_t
name|rc_offload
decl_stmt|;
name|uint8_t
name|agg_offload
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
comment|/* QWORD4 */
name|uint8_t
name|beacon_offload
decl_stmt|;
name|uint8_t
name|mlme_offload
decl_stmt|;
name|uint8_t
name|hwpc_offload
decl_stmt|;
name|uint8_t
name|tcpcsum_offload
decl_stmt|;
name|uint8_t
name|tcp_offload
decl_stmt|;
name|uint8_t
name|ps_offload
decl_stmt|;
name|uint8_t
name|wwlan_offload
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
comment|/* QWORD5 */
name|uint16_t
name|tcp_tx_len
decl_stmt|;
name|uint16_t
name|tcp_rx_len
decl_stmt|;
name|uint32_t
name|reserved4
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|r92s_fw_hdr
block|{
name|uint16_t
name|signature
decl_stmt|;
name|uint16_t
name|version
decl_stmt|;
name|uint32_t
name|dmemsz
decl_stmt|;
name|uint32_t
name|imemsz
decl_stmt|;
name|uint32_t
name|sramsz
decl_stmt|;
name|uint32_t
name|privsz
decl_stmt|;
name|uint16_t
name|efuse_addr
decl_stmt|;
name|uint16_t
name|h2c_resp_addr
decl_stmt|;
name|uint32_t
name|svnrev
decl_stmt|;
name|uint8_t
name|month
decl_stmt|;
name|uint8_t
name|day
decl_stmt|;
name|uint8_t
name|hour
decl_stmt|;
name|uint8_t
name|minute
decl_stmt|;
name|struct
name|r92s_fw_priv
name|priv
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for FW commands and FW events notifications. */
end_comment

begin_struct
struct|struct
name|r92s_fw_cmd_hdr
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|code
decl_stmt|;
name|uint8_t
name|seq
decl_stmt|;
define|#
directive|define
name|R92S_FW_CMD_MORE
value|0x80
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* FW commands codes. */
end_comment

begin_define
define|#
directive|define
name|R92S_CMD_READ_MACREG
value|0
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_MACREG
value|1
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_BBREG
value|2
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_BBREG
value|3
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_RFREG
value|4
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_RFREG
value|5
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_EEPROM
value|6
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_EEPROM
value|7
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_EFUSE
value|8
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_EFUSE
value|9
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_CAM
value|10
end_define

begin_define
define|#
directive|define
name|R92S_CMD_WRITE_CAM
value|11
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_BCNITV
value|12
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_MBIDCFG
value|13
end_define

begin_define
define|#
directive|define
name|R92S_CMD_JOIN_BSS
value|14
end_define

begin_define
define|#
directive|define
name|R92S_CMD_DISCONNECT
value|15
end_define

begin_define
define|#
directive|define
name|R92S_CMD_CREATE_BSS
value|16
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_OPMODE
value|17
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SITE_SURVEY
value|18
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_AUTH
value|19
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_KEY
value|20
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_STA_KEY
value|21
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_ASSOC_STA
value|22
end_define

begin_define
define|#
directive|define
name|R92S_CMD_DEL_ASSOC_STA
value|23
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_STAPWRSTATE
value|24
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_BASIC_RATE
value|25
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_BASIC_RATE
value|26
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_DATA_RATE
value|27
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_DATA_RATE
value|28
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PHY_INFO
value|29
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_PHY_INFO
value|30
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PHY
value|31
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_PHY
value|32
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_RSSI
value|33
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_GAIN
value|34
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_ATIM
value|35
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PWR_MODE
value|36
end_define

begin_define
define|#
directive|define
name|R92S_CMD_JOIN_BSS_RPT
value|37
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_RA_TABLE
value|38
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_RA_TABLE
value|39
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_CCX_REPORT
value|40
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_DTM_REPORT
value|41
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_TXRATE_STATS
value|42
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_USB_SUSPEND
value|43
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_H2C_LBK
value|44
end_define

begin_define
define|#
directive|define
name|R92S_CMD_ADDBA_REQ
value|45
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_CHANNEL
value|46
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_TXPOWER
value|47
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SWITCH_ANTENNA
value|48
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_CRYSTAL_CAL
value|49
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_SINGLE_CARRIER_TX
value|50
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_SINGLE_TONE_TX
value|51
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_CARRIER_SUPPR_TX
value|52
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_CONTINUOUS_TX
value|53
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SWITCH_BANDWIDTH
value|54
end_define

begin_define
define|#
directive|define
name|R92S_CMD_TX_BEACON
value|55
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_POWER_TRACKING
value|56
end_define

begin_define
define|#
directive|define
name|R92S_CMD_AMSDU_TO_AMPDU
value|57
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_MAC_ADDRESS
value|58
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_H2C_LBK
value|59
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PBREQ_IE
value|60
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_ASSOCREQ_IE
value|61
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PBRESP_IE
value|62
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_ASSOCRESP_IE
value|63
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_CURDATARATE
value|64
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_TXRETRY_CNT
value|65
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_RXRETRY_CNT
value|66
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_BCNOK_CNT
value|67
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_BCNERR_CNT
value|68
end_define

begin_define
define|#
directive|define
name|R92S_CMD_GET_CURTXPWR_LEVEL
value|69
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_DIG
value|70
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_RA
value|71
end_define

begin_define
define|#
directive|define
name|R92S_CMD_SET_PT
value|72
end_define

begin_define
define|#
directive|define
name|R92S_CMD_READ_TSSI
value|73
end_define

begin_comment
comment|/* FW events notifications codes. */
end_comment

begin_define
define|#
directive|define
name|R92S_EVT_READ_MACREG
value|0
end_define

begin_define
define|#
directive|define
name|R92S_EVT_READ_BBREG
value|1
end_define

begin_define
define|#
directive|define
name|R92S_EVT_READ_RFREG
value|2
end_define

begin_define
define|#
directive|define
name|R92S_EVT_READ_EEPROM
value|3
end_define

begin_define
define|#
directive|define
name|R92S_EVT_READ_EFUSE
value|4
end_define

begin_define
define|#
directive|define
name|R92S_EVT_READ_CAM
value|5
end_define

begin_define
define|#
directive|define
name|R92S_EVT_GET_BASICRATE
value|6
end_define

begin_define
define|#
directive|define
name|R92S_EVT_GET_DATARATE
value|7
end_define

begin_define
define|#
directive|define
name|R92S_EVT_SURVEY
value|8
end_define

begin_define
define|#
directive|define
name|R92S_EVT_SURVEY_DONE
value|9
end_define

begin_define
define|#
directive|define
name|R92S_EVT_JOIN_BSS
value|10
end_define

begin_define
define|#
directive|define
name|R92S_EVT_ADD_STA
value|11
end_define

begin_define
define|#
directive|define
name|R92S_EVT_DEL_STA
value|12
end_define

begin_define
define|#
directive|define
name|R92S_EVT_ATIM_DONE
value|13
end_define

begin_define
define|#
directive|define
name|R92S_EVT_TX_REPORT
value|14
end_define

begin_define
define|#
directive|define
name|R92S_EVT_CCX_REPORT
value|15
end_define

begin_define
define|#
directive|define
name|R92S_EVT_DTM_REPORT
value|16
end_define

begin_define
define|#
directive|define
name|R92S_EVT_TXRATE_STATS
value|17
end_define

begin_define
define|#
directive|define
name|R92S_EVT_C2H_LBK
value|18
end_define

begin_define
define|#
directive|define
name|R92S_EVT_FWDBG
value|19
end_define

begin_define
define|#
directive|define
name|R92S_EVT_C2H_FEEDBACK
value|20
end_define

begin_define
define|#
directive|define
name|R92S_EVT_ADDBA
value|21
end_define

begin_define
define|#
directive|define
name|R92S_EVT_C2H_BCN
value|22
end_define

begin_define
define|#
directive|define
name|R92S_EVT_PWR_STATE
value|23
end_define

begin_define
define|#
directive|define
name|R92S_EVT_WPS_PBC
value|24
end_define

begin_define
define|#
directive|define
name|R92S_EVT_ADDBA_REQ_REPORT
value|25
end_define

begin_comment
comment|/* Structure for R92S_CMD_SITE_SURVEY. */
end_comment

begin_struct
struct|struct
name|r92s_fw_cmd_sitesurvey
block|{
name|uint32_t
name|active
decl_stmt|;
name|uint32_t
name|limit
decl_stmt|;
name|uint32_t
name|ssidlen
decl_stmt|;
name|uint8_t
name|ssid
index|[
literal|32
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92S_CMD_SET_AUTH. */
end_comment

begin_struct
struct|struct
name|r92s_fw_cmd_auth
block|{
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|R92S_AUTHMODE_OPEN
value|0
define|#
directive|define
name|R92S_AUTHMODE_SHARED
value|1
define|#
directive|define
name|R92S_AUTHMODE_WPA
value|2
name|uint8_t
name|dot1x
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92S_CMD_SET_KEY. */
end_comment

begin_struct
struct|struct
name|r92s_fw_cmd_set_key
block|{
name|uint8_t
name|algo
decl_stmt|;
define|#
directive|define
name|R92S_KEY_ALGO_NONE
value|0
define|#
directive|define
name|R92S_KEY_ALGO_WEP40
value|1
define|#
directive|define
name|R92S_KEY_ALGO_TKIP
value|2
define|#
directive|define
name|R92S_KEY_ALGO_TKIP_MMIC
value|3
define|#
directive|define
name|R92S_KEY_ALGO_AES
value|4
define|#
directive|define
name|R92S_KEY_ALGO_WEP104
value|5
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|grpkey
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structures for R92S_EVENT_SURVEY/R92S_CMD_JOIN_BSS. */
end_comment

begin_comment
comment|/* NDIS_802_11_SSID. */
end_comment

begin_struct
struct|struct
name|ndis_802_11_ssid
block|{
name|uint32_t
name|ssidlen
decl_stmt|;
name|uint8_t
name|ssid
index|[
literal|32
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* NDIS_802_11_CONFIGURATION_FH. */
end_comment

begin_struct
struct|struct
name|ndis_802_11_configuration_fh
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|hoppattern
decl_stmt|;
name|uint32_t
name|hopset
decl_stmt|;
name|uint32_t
name|dwelltime
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* NDIS_802_11_CONFIGURATION. */
end_comment

begin_struct
struct|struct
name|ndis_802_11_configuration
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|bintval
decl_stmt|;
name|uint32_t
name|atim
decl_stmt|;
name|uint32_t
name|dsconfig
decl_stmt|;
name|struct
name|ndis_802_11_configuration_fh
name|fhconfig
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* NDIS_WLAN_BSSID_EX. */
end_comment

begin_struct
struct|struct
name|ndis_wlan_bssid_ex
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ndis_802_11_ssid
name|ssid
decl_stmt|;
name|uint32_t
name|privacy
decl_stmt|;
name|int32_t
name|rssi
decl_stmt|;
name|uint32_t
name|networktype
decl_stmt|;
define|#
directive|define
name|NDIS802_11FH
value|0
define|#
directive|define
name|NDIS802_11DS
value|1
define|#
directive|define
name|NDIS802_11OFDM5
value|2
define|#
directive|define
name|NDIS802_11OFDM24
value|3
define|#
directive|define
name|NDIS802_11AUTOMODE
value|4
name|struct
name|ndis_802_11_configuration
name|config
decl_stmt|;
name|uint32_t
name|inframode
decl_stmt|;
define|#
directive|define
name|NDIS802_11IBSS
value|0
define|#
directive|define
name|NDIS802_11INFRASTRUCTURE
value|1
define|#
directive|define
name|NDIS802_11AUTOUNKNOWN
value|2
define|#
directive|define
name|NDIS802_11MONITOR
value|3
define|#
directive|define
name|NDIS802_11APMODE
value|4
name|uint8_t
name|supprates
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|ieslen
decl_stmt|;
comment|/* Followed by ``ieslen'' bytes. */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* NDIS_802_11_FIXED_IEs. */
end_comment

begin_struct
struct|struct
name|ndis_802_11_fixed_ies
block|{
name|uint8_t
name|tstamp
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|bintval
decl_stmt|;
name|uint16_t
name|capabilities
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92S_CMD_SET_PWR_MODE. */
end_comment

begin_struct
struct|struct
name|r92s_set_pwr_mode
block|{
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|R92S_PS_MODE_ACTIVE
value|0
define|#
directive|define
name|R92S_PS_MODE_MIN
value|1
define|#
directive|define
name|R92S_PS_MODE_MAX
value|2
define|#
directive|define
name|R92S_PS_MODE_DTIM
value|3
define|#
directive|define
name|R92S_PS_MODE_VOIP
value|4
define|#
directive|define
name|R92S_PS_MODE_UAPSD_WMM
value|5
define|#
directive|define
name|R92S_PS_MODE_UAPSD
value|6
define|#
directive|define
name|R92S_PS_MODE_IBSS
value|7
define|#
directive|define
name|R92S_PS_MODE_WWLAN
value|8
define|#
directive|define
name|R92S_PS_MODE_RADIOOFF
value|9
define|#
directive|define
name|R92S_PS_MODE_DISABLE
value|10
name|uint8_t
name|low_traffic_en
decl_stmt|;
name|uint8_t
name|lpnav_en
decl_stmt|;
name|uint8_t
name|rf_low_snr_en
decl_stmt|;
name|uint8_t
name|dps_en
decl_stmt|;
name|uint8_t
name|bcn_rx_en
decl_stmt|;
name|uint8_t
name|bcn_pass_cnt
decl_stmt|;
name|uint8_t
name|bcn_to
decl_stmt|;
name|uint16_t
name|bcn_itv
decl_stmt|;
name|uint8_t
name|app_itv
decl_stmt|;
name|uint8_t
name|awake_bcn_itv
decl_stmt|;
name|uint8_t
name|smart_ps
decl_stmt|;
name|uint8_t
name|bcn_pass_time
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for event R92S_EVENT_JOIN_BSS. */
end_comment

begin_struct
struct|struct
name|r92s_event_join_bss
block|{
name|uint32_t
name|next
decl_stmt|;
name|uint32_t
name|prev
decl_stmt|;
name|uint32_t
name|networktype
decl_stmt|;
name|uint32_t
name|fixed
decl_stmt|;
name|uint32_t
name|lastscanned
decl_stmt|;
name|uint32_t
name|associd
decl_stmt|;
name|uint32_t
name|join_res
decl_stmt|;
name|struct
name|ndis_wlan_bssid_ex
name|bss
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|R92S_MACID_BSS
value|5
end_define

begin_comment
comment|/* Rx MAC descriptor. */
end_comment

begin_struct
struct|struct
name|r92s_rx_stat
block|{
name|uint32_t
name|rxdw0
decl_stmt|;
define|#
directive|define
name|R92S_RXDW0_PKTLEN_M
value|0x00003fff
define|#
directive|define
name|R92S_RXDW0_PKTLEN_S
value|0
define|#
directive|define
name|R92S_RXDW0_CRCERR
value|0x00004000
define|#
directive|define
name|R92S_RXDW0_INFOSZ_M
value|0x000f0000
define|#
directive|define
name|R92S_RXDW0_INFOSZ_S
value|16
define|#
directive|define
name|R92S_RXDW0_QOS
value|0x00800000
define|#
directive|define
name|R92S_RXDW0_SHIFT_M
value|0x03000000
define|#
directive|define
name|R92S_RXDW0_SHIFT_S
value|24
define|#
directive|define
name|R92S_RXDW0_DECRYPTED
value|0x08000000
name|uint32_t
name|rxdw1
decl_stmt|;
define|#
directive|define
name|R92S_RXDW1_MOREFRAG
value|0x08000000
name|uint32_t
name|rxdw2
decl_stmt|;
define|#
directive|define
name|R92S_RXDW2_FRAG_M
value|0x0000f000
define|#
directive|define
name|R92S_RXDW2_FRAG_S
value|12
define|#
directive|define
name|R92S_RXDW2_PKTCNT_M
value|0x00ff0000
define|#
directive|define
name|R92S_RXDW2_PKTCNT_S
value|16
name|uint32_t
name|rxdw3
decl_stmt|;
define|#
directive|define
name|R92S_RXDW3_RATE_M
value|0x0000003f
define|#
directive|define
name|R92S_RXDW3_RATE_S
value|0
define|#
directive|define
name|R92S_RXDW3_TCPCHKRPT
value|0x00000800
define|#
directive|define
name|R92S_RXDW3_IPCHKRPT
value|0x00001000
define|#
directive|define
name|R92S_RXDW3_TCPCHKVALID
value|0x00002000
define|#
directive|define
name|R92S_RXDW3_HTC
value|0x00004000
name|uint32_t
name|rxdw4
decl_stmt|;
name|uint32_t
name|rxdw5
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Rx PHY descriptor. */
end_comment

begin_struct
struct|struct
name|r92s_rx_phystat
block|{
name|uint32_t
name|phydw0
decl_stmt|;
name|uint32_t
name|phydw1
decl_stmt|;
name|uint32_t
name|phydw2
decl_stmt|;
name|uint32_t
name|phydw3
decl_stmt|;
name|uint32_t
name|phydw4
decl_stmt|;
name|uint32_t
name|phydw5
decl_stmt|;
name|uint32_t
name|phydw6
decl_stmt|;
name|uint32_t
name|phydw7
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Rx PHY CCK descriptor. */
end_comment

begin_struct
struct|struct
name|r92s_rx_cck
block|{
name|uint8_t
name|adc_pwdb
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|sq_rpt
decl_stmt|;
name|uint8_t
name|agc_rpt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Tx MAC descriptor. */
end_comment

begin_struct
struct|struct
name|r92s_tx_desc
block|{
name|uint32_t
name|txdw0
decl_stmt|;
define|#
directive|define
name|R92S_TXDW0_PKTLEN_M
value|0x0000ffff
define|#
directive|define
name|R92S_TXDW0_PKTLEN_S
value|0
define|#
directive|define
name|R92S_TXDW0_OFFSET_M
value|0x00ff0000
define|#
directive|define
name|R92S_TXDW0_OFFSET_S
value|16
define|#
directive|define
name|R92S_TXDW0_TYPE_M
value|0x03000000
define|#
directive|define
name|R92S_TXDW0_TYPE_S
value|24
define|#
directive|define
name|R92S_TXDW0_LSG
value|0x04000000
define|#
directive|define
name|R92S_TXDW0_FSG
value|0x08000000
define|#
directive|define
name|R92S_TXDW0_LINIP
value|0x10000000
define|#
directive|define
name|R92S_TXDW0_OWN
value|0x80000000
name|uint32_t
name|txdw1
decl_stmt|;
define|#
directive|define
name|R92S_TXDW1_MACID_M
value|0x0000001f
define|#
directive|define
name|R92S_TXDW1_MACID_S
value|0
define|#
directive|define
name|R92S_TXDW1_MOREDATA
value|0x00000020
define|#
directive|define
name|R92S_TXDW1_MOREFRAG
value|0x00000040
define|#
directive|define
name|R92S_TXDW1_QSEL_M
value|0x00001f00
define|#
directive|define
name|R92S_TXDW1_QSEL_S
value|8
define|#
directive|define
name|R92S_TXDW1_QSEL_BE
value|0x03
define|#
directive|define
name|R92S_TXDW1_QSEL_H2C
value|0x1f
define|#
directive|define
name|R92S_TXDW1_NONQOS
value|0x00010000
define|#
directive|define
name|R92S_TXDW1_KEYIDX_M
value|0x00060000
define|#
directive|define
name|R92S_TXDW1_KEYIDX_S
value|17
define|#
directive|define
name|R92S_TXDW1_CIPHER_M
value|0x00c00000
define|#
directive|define
name|R92S_TXDW1_CIPHER_S
value|22
define|#
directive|define
name|R92S_TXDW1_CIPHER_WEP
value|1
define|#
directive|define
name|R92S_TXDW1_CIPHER_TKIP
value|2
define|#
directive|define
name|R92S_TXDW1_CIPHER_AES
value|3
define|#
directive|define
name|R92S_TXDW1_HWPC
value|0x80000000
name|uint32_t
name|txdw2
decl_stmt|;
define|#
directive|define
name|R92S_TXDW2_BMCAST
value|0x00000080
define|#
directive|define
name|R92S_TXDW2_AGGEN
value|0x20000000
define|#
directive|define
name|R92S_TXDW2_BK
value|0x40000000
name|uint32_t
name|txdw3
decl_stmt|;
define|#
directive|define
name|R92S_TXDW3_SEQ_M
value|0x0fff0000
define|#
directive|define
name|R92S_TXDW3_SEQ_S
value|16
define|#
directive|define
name|R92S_TXDW3_FRAG_M
value|0xf0000000
define|#
directive|define
name|R92S_TXDW3_FRAG_S
value|28
name|uint32_t
name|txdw4
decl_stmt|;
define|#
directive|define
name|R92S_TXDW4_TXBW
value|0x00040000
name|uint32_t
name|txdw5
decl_stmt|;
define|#
directive|define
name|R92S_TXDW5_DISFB
value|0x00008000
name|uint16_t
name|ipchksum
decl_stmt|;
name|uint16_t
name|tcpchksum
decl_stmt|;
name|uint16_t
name|txbufsize
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|4
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Driver definitions.  */
end_comment

begin_define
define|#
directive|define
name|RSU_RX_LIST_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|RSU_TX_LIST_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|RSU_HOST_CMD_RING_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|RSU_RXBUFSZ
value|(8 * 1024)
end_define

begin_define
define|#
directive|define
name|RSU_TXBUFSZ
define|\
value|((sizeof(struct r92s_tx_desc) + IEEE80211_MAX_LEN + 3)& ~3)
end_define

begin_define
define|#
directive|define
name|RSU_TX_TIMEOUT
value|5000
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|RSU_CMD_TIMEOUT
value|2000
end_define

begin_comment
comment|/* ms */
end_comment

begin_comment
comment|/* Queue ids (used by soft only). */
end_comment

begin_define
define|#
directive|define
name|RSU_QID_BCN
value|0
end_define

begin_define
define|#
directive|define
name|RSU_QID_MGT
value|1
end_define

begin_define
define|#
directive|define
name|RSU_QID_BMC
value|2
end_define

begin_define
define|#
directive|define
name|RSU_QID_VO
value|3
end_define

begin_define
define|#
directive|define
name|RSU_QID_VI
value|4
end_define

begin_define
define|#
directive|define
name|RSU_QID_BE
value|5
end_define

begin_define
define|#
directive|define
name|RSU_QID_BK
value|6
end_define

begin_define
define|#
directive|define
name|RSU_QID_RXOFF
value|7
end_define

begin_define
define|#
directive|define
name|RSU_QID_H2C
value|8
end_define

begin_define
define|#
directive|define
name|RSU_QID_C2H
value|9
end_define

begin_comment
comment|/* Map AC to queue id. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|rsu_ac2qid
index|[
name|WME_NUM_AC
index|]
init|=
block|{
name|RSU_QID_BE
block|,
name|RSU_QID_BK
block|,
name|RSU_QID_VI
block|,
name|RSU_QID_VO
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pipe index to endpoint address mapping. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|r92s_epaddr
index|[]
init|=
block|{
literal|0x83
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x0d
block|,
literal|0x05
block|,
literal|0x07
block|,
literal|0x89
block|,
literal|0x0a
block|,
literal|0x0b
block|,
literal|0x0c
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue id to pipe index mapping for 4 endpoints configurations. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|rsu_qid2idx_4ep
index|[]
init|=
block|{
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|1
block|,
literal|1
block|,
literal|2
block|,
literal|2
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue id to pipe index mapping for 6 endpoints configurations. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|rsu_qid2idx_6ep
index|[]
init|=
block|{
literal|3
block|,
literal|3
block|,
literal|3
block|,
literal|1
block|,
literal|4
block|,
literal|2
block|,
literal|5
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Queue id to pipe index mapping for 11 endpoints configurations. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|rsu_qid2idx_11ep
index|[]
init|=
block|{
literal|7
block|,
literal|9
block|,
literal|8
block|,
literal|1
block|,
literal|4
block|,
literal|2
block|,
literal|5
block|,
literal|0
block|,
literal|3
block|,
literal|6
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|rsu_rx_radiotap_header
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
name|wr_dbm_antsignal
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|RSU_RX_RADIOTAP_PRESENT
define|\
value|(1<< IEEE80211_RADIOTAP_FLAGS |	\ 	 1<< IEEE80211_RADIOTAP_RATE |		\ 	 1<< IEEE80211_RADIOTAP_CHANNEL |	\ 	 1<< IEEE80211_RADIOTAP_DBM_ANTSIGNAL)
end_define

begin_struct
struct|struct
name|rsu_tx_radiotap_header
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
name|__packed
name|__aligned
argument_list|(
literal|8
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|RSU_TX_RADIOTAP_PRESENT
define|\
value|(1<< IEEE80211_RADIOTAP_FLAGS |	\ 	 1<< IEEE80211_RADIOTAP_CHANNEL)
end_define

begin_struct_decl
struct_decl|struct
name|rsu_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|rsu_host_cmd
block|{
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|rsu_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|uint8_t
name|data
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rsu_cmd_newstate
block|{
name|enum
name|ieee80211_state
name|state
decl_stmt|;
name|int
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rsu_cmd_key
block|{
name|struct
name|ieee80211_key
name|key
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rsu_host_cmd_ring
block|{
name|struct
name|rsu_host_cmd
name|cmd
index|[
name|RSU_HOST_CMD_RING_COUNT
index|]
decl_stmt|;
name|int
name|cur
decl_stmt|;
name|int
name|next
decl_stmt|;
name|int
name|queued
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|RSU_BULK_RX
block|,
name|RSU_BULK_TX_BE_BK
block|,
comment|/* = WME_AC_BE/BK */
name|RSU_BULK_TX_VI_VO
block|,
comment|/* = WME_AC_VI/VO */
name|RSU_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|rsu_data
block|{
name|struct
name|rsu_softc
modifier|*
name|sc
decl_stmt|;
name|uint8_t
modifier|*
name|buf
decl_stmt|;
name|uint16_t
name|buflen
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
name|STAILQ_ENTRY
argument_list|(
argument|rsu_data
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rsu_vap
block|{
name|struct
name|ieee80211vap
name|vap
decl_stmt|;
name|struct
name|ieee80211_beacon_offsets
name|bo
decl_stmt|;
name|int
function_decl|(
modifier|*
name|newstate
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
name|RSU_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct rsu_vap *)(vap))
end_define

begin_define
define|#
directive|define
name|RSU_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|RSU_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|RSU_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, MA_OWNED)
end_define

begin_struct
struct|struct
name|rsu_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
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
name|struct
name|usbd_interface
modifier|*
name|sc_iface
decl_stmt|;
name|struct
name|timeout_task
name|calib_task
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|qid2idx
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|u_int
name|cut
decl_stmt|;
name|int
name|scan_pass
decl_stmt|;
name|struct
name|rsu_host_cmd_ring
name|cmdq
decl_stmt|;
name|struct
name|rsu_data
name|sc_rx
index|[
name|RSU_RX_LIST_COUNT
index|]
decl_stmt|;
name|struct
name|rsu_data
name|sc_tx
index|[
name|RSU_TX_LIST_COUNT
index|]
decl_stmt|;
name|struct
name|rsu_data
modifier|*
name|fwcmd_data
decl_stmt|;
name|uint8_t
name|cmd_seq
decl_stmt|;
name|uint8_t
name|rom
index|[
literal|128
index|]
decl_stmt|;
name|uint8_t
name|sc_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|RSU_N_TRANSFER
index|]
decl_stmt|;
name|uint8_t
name|sc_calibrating
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rsu_data
argument_list|)
name|sc_rx_active
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rsu_data
argument_list|)
name|sc_rx_inactive
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rsu_data
argument_list|)
name|sc_tx_active
index|[
name|RSU_N_TRANSFER
index|]
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rsu_data
argument_list|)
name|sc_tx_inactive
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|rsu_data
argument_list|)
name|sc_tx_pending
index|[
name|RSU_N_TRANSFER
index|]
expr_stmt|;
union|union
block|{
name|struct
name|rsu_rx_radiotap_header
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
name|rsu_tx_radiotap_header
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

end_unit

