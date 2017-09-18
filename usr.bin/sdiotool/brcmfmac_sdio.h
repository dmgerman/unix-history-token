begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Broadcom Corporation  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SDIO_FUNC_0
value|0
end_define

begin_define
define|#
directive|define
name|SDIO_FUNC_1
value|1
end_define

begin_define
define|#
directive|define
name|SDIO_FUNC_2
value|2
end_define

begin_define
define|#
directive|define
name|SDIOD_FBR_SIZE
value|0x100
end_define

begin_comment
comment|/* io_en */
end_comment

begin_define
define|#
directive|define
name|SDIO_FUNC_ENABLE_1
value|0x02
end_define

begin_define
define|#
directive|define
name|SDIO_FUNC_ENABLE_2
value|0x04
end_define

begin_comment
comment|/* io_rdys */
end_comment

begin_define
define|#
directive|define
name|SDIO_FUNC_READY_1
value|0x02
end_define

begin_define
define|#
directive|define
name|SDIO_FUNC_READY_2
value|0x04
end_define

begin_comment
comment|/* intr_status */
end_comment

begin_define
define|#
directive|define
name|INTR_STATUS_FUNC1
value|0x2
end_define

begin_define
define|#
directive|define
name|INTR_STATUS_FUNC2
value|0x4
end_define

begin_comment
comment|/* Maximum number of I/O funcs */
end_comment

begin_define
define|#
directive|define
name|SDIOD_MAX_IOFUNCS
value|7
end_define

begin_comment
comment|/* mask of register map */
end_comment

begin_define
define|#
directive|define
name|REG_F0_REG_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|REG_F1_MISC_MASK
value|0x1FFFF
end_define

begin_comment
comment|/* as of sdiod rev 0, supports 3 functions */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_NUM_FUNCTION
value|3
end_define

begin_comment
comment|/* function 0 vendor specific CCCR registers */
end_comment

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCAP
value|0xf0
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCAP_CMD14_SUPPORT
value|0x02
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCAP_CMD14_EXT
value|0x04
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCAP_CMD_NODEC
value|0x08
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCTRL
value|0xf1
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_CARDCTRL_WLANRESET
value|0x02
end_define

begin_define
define|#
directive|define
name|SDIO_CCCR_BRCM_SEPINT
value|0xf2
end_define

begin_define
define|#
directive|define
name|SDIO_SEPINT_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SDIO_SEPINT_OE
value|0x02
end_define

begin_define
define|#
directive|define
name|SDIO_SEPINT_ACT_HI
value|0x04
end_define

begin_comment
comment|/* function 1 miscellaneous registers */
end_comment

begin_comment
comment|/* sprom command and status */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SPROM_CS
value|0x10000
end_define

begin_comment
comment|/* sprom info register */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SPROM_INFO
value|0x10001
end_define

begin_comment
comment|/* sprom indirect access data byte 0 */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SPROM_DATA_LOW
value|0x10002
end_define

begin_comment
comment|/* sprom indirect access data byte 1 */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SPROM_DATA_HIGH
value|0x10003
end_define

begin_comment
comment|/* sprom indirect access addr byte 0 */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SPROM_ADDR_LOW
value|0x10004
end_define

begin_comment
comment|/* gpio select */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_GPIO_SELECT
value|0x10005
end_define

begin_comment
comment|/* gpio output */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_GPIO_OUT
value|0x10006
end_define

begin_comment
comment|/* gpio enable */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_GPIO_EN
value|0x10007
end_define

begin_comment
comment|/* rev< 7, watermark for sdio device */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_WATERMARK
value|0x10008
end_define

begin_comment
comment|/* control busy signal generation */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_DEVICE_CTL
value|0x10009
end_define

begin_comment
comment|/* SB Address Window Low (b15) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SBADDRLOW
value|0x1000A
end_define

begin_comment
comment|/* SB Address Window Mid (b23:b16) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SBADDRMID
value|0x1000B
end_define

begin_comment
comment|/* SB Address Window High (b31:b24)    */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SBADDRHIGH
value|0x1000C
end_define

begin_comment
comment|/* Frame Control (frame term/abort) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_FRAMECTRL
value|0x1000D
end_define

begin_comment
comment|/* ChipClockCSR (ALP/HT ctl/status) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_CHIPCLKCSR
value|0x1000E
end_define

begin_comment
comment|/* SdioPullUp (on cmd, d0-d2) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SDIOPULLUP
value|0x1000F
end_define

begin_comment
comment|/* Write Frame Byte Count Low */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WFRAMEBCLO
value|0x10019
end_define

begin_comment
comment|/* Write Frame Byte Count High */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WFRAMEBCHI
value|0x1001A
end_define

begin_comment
comment|/* Read Frame Byte Count Low */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_RFRAMEBCLO
value|0x1001B
end_define

begin_comment
comment|/* Read Frame Byte Count High */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_RFRAMEBCHI
value|0x1001C
end_define

begin_comment
comment|/* MesBusyCtl (rev 11) */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_MESBUSYCTRL
value|0x1001D
end_define

begin_comment
comment|/* Sdio Core Rev 12 */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WAKEUPCTRL
value|0x1001E
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WCTRL_ALPWAIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WCTRL_ALPWAIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WCTRL_HTWAIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_WCTRL_HTWAIT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR
value|0x1001F
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR_KSO_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR_KSO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR_KSO_EN
value|1
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR_DEVON_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_SLEEPCSR_DEVON_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_MISC_REG_START
value|0x10000
end_define

begin_comment
comment|/* f1 misc register start */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_FUNC1_MISC_REG_LIMIT
value|0x1001F
end_define

begin_comment
comment|/* f1 misc register end */
end_comment

begin_comment
comment|/* function 1 OCP space */
end_comment

begin_comment
comment|/* sb offset addr is<= 15 bits, 32k */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SB_OFT_ADDR_MASK
value|0x07FFF
end_define

begin_define
define|#
directive|define
name|SBSDIO_SB_OFT_ADDR_LIMIT
value|0x08000
end_define

begin_comment
comment|/* with b15, maps to 32-bit SB access */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SB_ACCESS_2_4B_FLAG
value|0x08000
end_define

begin_comment
comment|/* valid bits in SBSDIO_FUNC1_SBADDRxxx regs */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SBADDRLOW_MASK
value|0x80
end_define

begin_comment
comment|/* Valid bits in SBADDRLOW */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SBADDRMID_MASK
value|0xff
end_define

begin_comment
comment|/* Valid bits in SBADDRMID */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SBADDRHIGH_MASK
value|0xffU
end_define

begin_comment
comment|/* Valid bits in SBADDRHIGH */
end_comment

begin_comment
comment|/* Address bits from SBADDR regs */
end_comment

begin_define
define|#
directive|define
name|SBSDIO_SBWINDOW_MASK
value|0xffff8000
end_define

begin_define
define|#
directive|define
name|SDIOH_READ
value|0
end_define

begin_comment
comment|/* Read request */
end_comment

begin_define
define|#
directive|define
name|SDIOH_WRITE
value|1
end_define

begin_comment
comment|/* Write request */
end_comment

begin_define
define|#
directive|define
name|SDIOH_DATA_FIX
value|0
end_define

begin_comment
comment|/* Fixed addressing */
end_comment

begin_define
define|#
directive|define
name|SDIOH_DATA_INC
value|1
end_define

begin_comment
comment|/* Incremental addressing */
end_comment

begin_comment
comment|/* internal return code */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_comment
comment|/* Packet alignment for most efficient SDIO (can change based on platform) */
end_comment

begin_define
define|#
directive|define
name|BRCMF_SDALIGN
value|(1<< 6)
end_define

begin_comment
comment|/**  * enum brcmf_sdiod_state - the state of the bus.  *  * @BRCMF_SDIOD_DOWN: Device can be accessed, no DPC.  * @BRCMF_SDIOD_DATA: Ready for data transfers, DPC enabled.  * @BRCMF_SDIOD_NOMEDIUM: No medium access to dongle possible.  */
end_comment

begin_enum
enum|enum
name|brcmf_sdiod_state
block|{
name|BRCMF_SDIOD_DOWN
block|,
name|BRCMF_SDIOD_DATA
block|,
name|BRCMF_SDIOD_NOMEDIUM
block|}
enum|;
end_enum

end_unit

