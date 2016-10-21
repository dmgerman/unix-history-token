begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_rtwnreg.h,v 1.3 2015/06/14 08:02:47 stsp Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015 Stefan Sperling<stsp@openbsd.org>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92CE_REG_H
end_ifndef

begin_define
define|#
directive|define
name|R92CE_REG_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_reg.h>
end_include

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_comment
comment|/* System Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_PCIE_MIO_INTF
value|0x0e4
end_define

begin_define
define|#
directive|define
name|R92C_PCIE_MIO_INTD
value|0x0e8
end_define

begin_comment
comment|/* PCIe Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_PCIE_CTRL_REG
value|0x300
end_define

begin_define
define|#
directive|define
name|R92C_INT_MIG
value|0x304
end_define

begin_define
define|#
directive|define
name|R92C_BCNQ_DESA
value|0x308
end_define

begin_define
define|#
directive|define
name|R92C_HQ_DESA
value|0x310
end_define

begin_define
define|#
directive|define
name|R92C_MGQ_DESA
value|0x318
end_define

begin_define
define|#
directive|define
name|R92C_VOQ_DESA
value|0x320
end_define

begin_define
define|#
directive|define
name|R92C_VIQ_DESA
value|0x328
end_define

begin_define
define|#
directive|define
name|R92C_BEQ_DESA
value|0x330
end_define

begin_define
define|#
directive|define
name|R92C_BKQ_DESA
value|0x338
end_define

begin_define
define|#
directive|define
name|R92C_RX_DESA
value|0x340
end_define

begin_define
define|#
directive|define
name|R92C_DBI
value|0x348
end_define

begin_define
define|#
directive|define
name|R92C_MDIO
value|0x354
end_define

begin_define
define|#
directive|define
name|R92C_DBG_SEL
value|0x360
end_define

begin_define
define|#
directive|define
name|R92C_PCIE_HRPWM
value|0x361
end_define

begin_define
define|#
directive|define
name|R92C_PCIE_HCPWM
value|0x363
end_define

begin_define
define|#
directive|define
name|R92C_UART_CTRL
value|0x364
end_define

begin_define
define|#
directive|define
name|R92C_UART_TX_DES
value|0x370
end_define

begin_define
define|#
directive|define
name|R92C_UART_RX_DES
value|0x378
end_define

begin_comment
comment|/* Bits for R92C_GPIO_MUXCFG. */
end_comment

begin_define
define|#
directive|define
name|R92C_GPIO_MUXCFG_RFKILL
value|0x0008
end_define

begin_comment
comment|/* Bits for R92C_GPIO_IO_SEL. */
end_comment

begin_define
define|#
directive|define
name|R92C_GPIO_IO_SEL_RFKILL
value|0x0008
end_define

begin_comment
comment|/* Bits for R92C_LEDCFG2. */
end_comment

begin_define
define|#
directive|define
name|R92C_LEDCFG2_EN
value|0x60
end_define

begin_define
define|#
directive|define
name|R92C_LEDCFG2_DIS
value|0x68
end_define

begin_comment
comment|/* Bits for R92C_HIMR. */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_ROK
value|0x00000001
end_define

begin_comment
comment|/* receive DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_VODOK
value|0x00000002
end_define

begin_comment
comment|/* AC_VO DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_VIDOK
value|0x00000004
end_define

begin_comment
comment|/* AC_VI DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BEDOK
value|0x00000008
end_define

begin_comment
comment|/* AC_BE DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BKDOK
value|0x00000010
end_define

begin_comment
comment|/* AC_BK DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_TXBDER
value|0x00000020
end_define

begin_comment
comment|/* beacon transmit error */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_MGNTDOK
value|0x00000040
end_define

begin_comment
comment|/* management queue DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_TBDOK
value|0x00000080
end_define

begin_comment
comment|/* beacon transmit OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_HIGHDOK
value|0x00000100
end_define

begin_comment
comment|/* high queue DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BDOK
value|0x00000200
end_define

begin_comment
comment|/* beacon queue DMA OK */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_ATIMEND
value|0x00000400
end_define

begin_comment
comment|/* ATIM window end interrupt */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_RDU
value|0x00000800
end_define

begin_comment
comment|/* Rx descriptor unavailable */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_RXFOVW
value|0x00001000
end_define

begin_comment
comment|/* receive FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNINT
value|0x00002000
end_define

begin_comment
comment|/* beacon DMA interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_PSTIMEOUT
value|0x00004000
end_define

begin_comment
comment|/* powersave timeout */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_TXFOVW
value|0x00008000
end_define

begin_comment
comment|/* transmit FIFO overflow */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_TIMEOUT1
value|0x00010000
end_define

begin_comment
comment|/* timeout interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_TIMEOUT2
value|0x00020000
end_define

begin_comment
comment|/* timeout interrupt 2 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK1
value|0x00040000
end_define

begin_comment
comment|/* beacon queue DMA OK (1) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK2
value|0x00080000
end_define

begin_comment
comment|/* beacon queue DMA OK (2) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK3
value|0x00100000
end_define

begin_comment
comment|/* beacon queue DMA OK (3) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK4
value|0x00200000
end_define

begin_comment
comment|/* beacon queue DMA OK (4) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK5
value|0x00400000
end_define

begin_comment
comment|/* beacon queue DMA OK (5) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK6
value|0x00800000
end_define

begin_comment
comment|/* beacon queue DMA OK (6) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK7
value|0x01000000
end_define

begin_comment
comment|/* beacon queue DMA OK (7) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDOK8
value|0x02000000
end_define

begin_comment
comment|/* beacon queue DMA OK (8) */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT1
value|0x04000000
end_define

begin_comment
comment|/* beacon DMA interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT2
value|0x08000000
end_define

begin_comment
comment|/* beacon DMA interrupt 2 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT3
value|0x10000000
end_define

begin_comment
comment|/* beacon DMA interrupt 3 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT4
value|0x20000000
end_define

begin_comment
comment|/* beacon DMA interrupt 4 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT5
value|0x40000000
end_define

begin_comment
comment|/* beacon DMA interrupt 5 */
end_comment

begin_define
define|#
directive|define
name|R92C_IMR_BCNDMAINT6
value|0x80000000
end_define

begin_comment
comment|/* beacon DMA interrupt 6 */
end_comment

begin_comment
comment|/* Shortcut. */
end_comment

begin_define
define|#
directive|define
name|R92C_IBSS_INT_MASK
define|\
value|(R92C_IMR_BCNINT | R92C_IMR_TBDOK | R92C_IMR_TBDER)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R92CE_REG_H */
end_comment

end_unit

