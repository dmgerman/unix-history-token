begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Oleksandr Tymoshenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AR71XX_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_AR71XX_REG_H_
end_define

begin_comment
comment|/* PCI region */
end_comment

begin_define
define|#
directive|define
name|AR71XX_PCI_MEM_BASE
value|0x10000000
end_define

begin_comment
comment|/*   * PCI mem windows is 0x08000000 bytes long but we exclude control   * region from the resource manager  */
end_comment

begin_define
define|#
directive|define
name|AR71XX_PCI_MEM_SIZE
value|0x07000000
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_IRQ_START
value|0
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_IRQ_END
value|2
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_NIRQS
value|3
end_define

begin_comment
comment|/*  * PCI devices slots are starting from this number  */
end_comment

begin_define
define|#
directive|define
name|AR71XX_PCI_BASE_SLOT
value|17
end_define

begin_comment
comment|/* PCI config registers */
end_comment

begin_define
define|#
directive|define
name|AR71XX_PCI_LCONF_CMD
value|0x17010000
end_define

begin_define
define|#
directive|define
name|PCI_LCONF_CMD_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_LCONF_CMD_WRITE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_LCONF_WRITE_DATA
value|0x17010004
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_LCONF_READ_DATA
value|0x17010008
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_CONF_ADDR
value|0x1701000C
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_CONF_CMD
value|0x17010010
end_define

begin_define
define|#
directive|define
name|PCI_CONF_CMD_READ
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|PCI_CONF_CMD_WRITE
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_CONF_WRITE_DATA
value|0x17010014
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_CONF_READ_DATA
value|0x17010018
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_ERROR
value|0x1701001C
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_ERROR_ADDR
value|0x17010020
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_AHB_ERROR
value|0x17010024
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_AHB_ERROR_ADDR
value|0x17010028
end_define

begin_comment
comment|/* APB region */
end_comment

begin_comment
comment|/*  * Size is not really true actual APB window size is   * 0x01000000 but it should handle OHCI memory as well  * because this controller's interrupt is routed through   * APB.   */
end_comment

begin_define
define|#
directive|define
name|AR71XX_APB_BASE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|AR71XX_APB_SIZE
value|0x06000000
end_define

begin_comment
comment|/* DDR registers */
end_comment

begin_define
define|#
directive|define
name|AR71XX_DDR_CONFIG
value|0x18000000
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_CONFIG2
value|0x18000004
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_MODE_REGISTER
value|0x18000008
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_EXT_MODE_REGISTER
value|0x1800000C
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_CONTROL
value|0x18000010
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_REFRESH
value|0x18000014
end_define

begin_define
define|#
directive|define
name|AR71XX_DDR_RD_DATA_THIS_CYCLE
value|0x18000018
end_define

begin_define
define|#
directive|define
name|AR71XX_TAP_CONTROL0
value|0x1800001C
end_define

begin_define
define|#
directive|define
name|AR71XX_TAP_CONTROL1
value|0x18000020
end_define

begin_define
define|#
directive|define
name|AR71XX_TAP_CONTROL2
value|0x18000024
end_define

begin_define
define|#
directive|define
name|AR71XX_TAP_CONTROL3
value|0x18000028
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW0
value|0x1800007C
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW1
value|0x18000080
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW2
value|0x18000084
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW3
value|0x18000088
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW4
value|0x1800008C
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW5
value|0x18000090
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW6
value|0x18000094
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_WINDOW7
value|0x18000098
end_define

begin_define
define|#
directive|define
name|AR71XX_WB_FLUSH_GE0
value|0x1800009C
end_define

begin_define
define|#
directive|define
name|AR71XX_WB_FLUSH_GE1
value|0x180000A0
end_define

begin_define
define|#
directive|define
name|AR71XX_WB_FLUSH_USB
value|0x180000A4
end_define

begin_define
define|#
directive|define
name|AR71XX_WB_FLUSH_PCI
value|0x180000A8
end_define

begin_comment
comment|/*  * Values for PCI_WINDOW_X registers   */
end_comment

begin_define
define|#
directive|define
name|PCI_WINDOW0_ADDR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW1_ADDR
value|0x11000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW2_ADDR
value|0x12000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW3_ADDR
value|0x13000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW4_ADDR
value|0x14000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW5_ADDR
value|0x15000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW6_ADDR
value|0x16000000
end_define

begin_define
define|#
directive|define
name|PCI_WINDOW7_ADDR
value|0x17000000
end_define

begin_comment
comment|/* This value enables acces to PCI config registers */
end_comment

begin_define
define|#
directive|define
name|PCI_WINDOW7_CONF_ADDR
value|0x07000000
end_define

begin_define
define|#
directive|define
name|AR71XX_UART_ADDR
value|0x18020000
end_define

begin_define
define|#
directive|define
name|AR71XX_UART_THR
value|0x0
end_define

begin_define
define|#
directive|define
name|AR71XX_UART_LSR
value|0x14
end_define

begin_define
define|#
directive|define
name|AR71XX_UART_LSR_THRE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR71XX_UART_LSR_TEMT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR71XX_USB_CTRL_FLADJ
value|0x18030000
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_HOST_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A5_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A4_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A3_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A2_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A1_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|USB_CTRL_FLADJ_A0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR71XX_USB_CTRL_CONFIG
value|0x18030004
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_OHCI_DES_SWAP
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_OHCI_BUF_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_EHCI_DES_SWAP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_EHCI_BUF_SWAP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_DISABLE_XTL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_OVERRIDE_XTL
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_CLK_SEL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_CLK_SEL_MASK
value|3
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_CLK_SEL_12
value|0
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_CLK_SEL_24
value|1
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_CLK_SEL_48
value|2
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_OVER_CURRENT_AS_GPIO
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_SS_SIMULATION_MODE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_RESUME_UTMI_PLS_DIS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|USB_CTRL_CONFIG_UTMI_BACKWARD_ENB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_BASE
value|0x18040000
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_OE
value|0x00
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_IN
value|0x04
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_OUT
value|0x08
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_SET
value|0x0c
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_CLEAR
value|0x10
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_INT
value|0x14
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_INT_TYPE
value|0x18
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_INT_POLARITY
value|0x1c
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_INT_PENDING
value|0x20
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_INT_MASK
value|0x24
end_define

begin_define
define|#
directive|define
name|AR71XX_GPIO_FUNCTION
value|0x28
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC_STEREO_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC_SLIC_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC_SPI_CS2_EN
value|(1<< 13)
end_define

begin_comment
comment|/* CS2 is shared with GPIO_1 */
end_comment

begin_define
define|#
directive|define
name|GPIO_FUNC_SPI_CS1_EN
value|(1<< 12)
end_define

begin_comment
comment|/* CS1 is shared with GPIO_0 */
end_comment

begin_define
define|#
directive|define
name|GPIO_FUNC_UART_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC_USB_OC_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GPIO_FUNC_USB_CLK_EN
value|(0)
end_define

begin_define
define|#
directive|define
name|AR71XX_BASE_FREQ
value|40000000
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_CPU_BASE
value|0x18050000
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_CPU_CONFIG
value|0x18050000
end_define

begin_define
define|#
directive|define
name|PLL_SW_UPDATE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|PLL_LOCKED
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PLL_AHB_DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PLL_AHB_DIV_MASK
value|7
end_define

begin_define
define|#
directive|define
name|PLL_DDR_DIV_SEL_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|PLL_DDR_DIV_SEL_MASK
value|3
end_define

begin_define
define|#
directive|define
name|PLL_CPU_DIV_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PLL_CPU_DIV_SEL_MASK
value|3
end_define

begin_define
define|#
directive|define
name|PLL_LOOP_BW_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PLL_LOOP_BW_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PLL_DIV_IN_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|PLL_DIV_IN_MASK
value|3
end_define

begin_define
define|#
directive|define
name|PLL_DIV_OUT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PLL_DIV_OUT_MASK
value|3
end_define

begin_define
define|#
directive|define
name|PLL_FB_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PLL_FB_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|PLL_BYPASS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PLL_POWER_DOWN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_SEC_CONFIG
value|0x18050004
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_ETH0_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_ETH1_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_CPU_CLK_CTRL
value|0x18050008
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_ETH_INT0_CLK
value|0x18050010
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_ETH_INT1_CLK
value|0x18050014
end_define

begin_define
define|#
directive|define
name|XPLL_ETH_INT_CLK_10
value|0x00991099
end_define

begin_define
define|#
directive|define
name|XPLL_ETH_INT_CLK_100
value|0x00441011
end_define

begin_define
define|#
directive|define
name|XPLL_ETH_INT_CLK_1000
value|0x13110000
end_define

begin_define
define|#
directive|define
name|XPLL_ETH_INT_CLK_1000_GMII
value|0x14110000
end_define

begin_define
define|#
directive|define
name|PLL_ETH_INT_CLK_10
value|0x00991099
end_define

begin_define
define|#
directive|define
name|PLL_ETH_INT_CLK_100
value|0x00001099
end_define

begin_define
define|#
directive|define
name|PLL_ETH_INT_CLK_1000
value|0x00110000
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_ETH_EXT_CLK
value|0x18050018
end_define

begin_define
define|#
directive|define
name|AR71XX_PLL_PCI_CLK
value|0x1805001C
end_define

begin_comment
comment|/* Reset block */
end_comment

begin_define
define|#
directive|define
name|AR71XX_RST_BLOCK_BASE
value|0x18060000
end_define

begin_define
define|#
directive|define
name|AR71XX_RST_WDOG_CONTROL
value|0x18060008
end_define

begin_define
define|#
directive|define
name|RST_WDOG_LAST
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|RST_WDOG_ACTION_MASK
value|3
end_define

begin_define
define|#
directive|define
name|RST_WDOG_ACTION_RESET
value|3
end_define

begin_define
define|#
directive|define
name|RST_WDOG_ACTION_NMI
value|2
end_define

begin_define
define|#
directive|define
name|RST_WDOG_ACTION_GP_INTR
value|1
end_define

begin_define
define|#
directive|define
name|RST_WDOG_ACTION_NOACTION
value|0
end_define

begin_define
define|#
directive|define
name|AR71XX_RST_WDOG_TIMER
value|0x1806000C
end_define

begin_comment
comment|/*   * APB interrupt status and mask register and interrupt bit numbers for   */
end_comment

begin_define
define|#
directive|define
name|AR71XX_MISC_INTR_STATUS
value|0x18060010
end_define

begin_define
define|#
directive|define
name|AR71XX_MISC_INTR_MASK
value|0x18060014
end_define

begin_define
define|#
directive|define
name|MISC_INTR_TIMER
value|0
end_define

begin_define
define|#
directive|define
name|MISC_INTR_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|MISC_INTR_GPIO
value|2
end_define

begin_define
define|#
directive|define
name|MISC_INTR_UART
value|3
end_define

begin_define
define|#
directive|define
name|MISC_INTR_WATCHDOG
value|4
end_define

begin_define
define|#
directive|define
name|MISC_INTR_PERF
value|5
end_define

begin_define
define|#
directive|define
name|MISC_INTR_OHCI
value|6
end_define

begin_define
define|#
directive|define
name|MISC_INTR_DMA
value|7
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_INTR_STATUS
value|0x18060018
end_define

begin_define
define|#
directive|define
name|AR71XX_PCI_INTR_MASK
value|0x1806001C
end_define

begin_define
define|#
directive|define
name|PCI_INTR_CORE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR71XX_RST_RESET
value|0x18060024
end_define

begin_define
define|#
directive|define
name|RST_RESET_FULL_CHIP
value|(1<< 24)
end_define

begin_comment
comment|/* Same as pulling 							     the reset pin */
end_comment

begin_define
define|#
directive|define
name|RST_RESET_CPU_COLD
value|(1<< 20)
end_define

begin_comment
comment|/* Cold reset */
end_comment

begin_define
define|#
directive|define
name|RST_RESET_GE1_MAC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RST_RESET_GE1_PHY
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RST_RESET_GE0_MAC
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RST_RESET_GE0_PHY
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RST_RESET_USB_OHCI_DLL
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RST_RESET_USB_HOST
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RST_RESET_USB_PHY
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RST_RESET_PCI_BUS
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RST_RESET_PCI_CORE
value|(1<<  0)
end_define

begin_comment
comment|/* Chipset revision details */
end_comment

begin_define
define|#
directive|define
name|AR71XX_RST_RESET_REG_REV_ID
value|0x18060090
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_MASK
value|0xfff0
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR71XX
value|0x00a0
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR913X
value|0x00b0
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR7240
value|0x00c0
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR7241
value|0x0100
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR7242
value|0x1100
end_define

begin_comment
comment|/* AR71XX chipset revision details */
end_comment

begin_define
define|#
directive|define
name|AR71XX_REV_ID_MINOR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR71XX_REV_ID_MINOR_AR7130
value|0x0
end_define

begin_define
define|#
directive|define
name|AR71XX_REV_ID_MINOR_AR7141
value|0x1
end_define

begin_define
define|#
directive|define
name|AR71XX_REV_ID_MINOR_AR7161
value|0x2
end_define

begin_define
define|#
directive|define
name|AR71XX_REV_ID_REVISION_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR71XX_REV_ID_REVISION_SHIFT
value|2
end_define

begin_comment
comment|/* AR724X chipset revision details */
end_comment

begin_define
define|#
directive|define
name|AR724X_REV_ID_REVISION_MASK
value|0x3
end_define

begin_comment
comment|/* AR91XX chipset revision details */
end_comment

begin_define
define|#
directive|define
name|AR91XX_REV_ID_MINOR_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR91XX_REV_ID_MINOR_AR9130
value|0x0
end_define

begin_define
define|#
directive|define
name|AR91XX_REV_ID_MINOR_AR9132
value|0x1
end_define

begin_define
define|#
directive|define
name|AR91XX_REV_ID_REVISION_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR91XX_REV_ID_REVISION_SHIFT
value|2
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AR71XX_MII_MODE_NONE
init|=
literal|0
block|,
name|AR71XX_MII_MODE_GMII
block|,
name|AR71XX_MII_MODE_MII
block|,
name|AR71XX_MII_MODE_RGMII
block|,
name|AR71XX_MII_MODE_RMII
block|,
name|AR71XX_MII_MODE_SGMII
comment|/* not hardware defined, though! */
block|}
name|ar71xx_mii_mode
typedef|;
end_typedef

begin_comment
comment|/*  * AR71xx MII control region  */
end_comment

begin_define
define|#
directive|define
name|AR71XX_MII0_CTRL
value|0x18070000
end_define

begin_define
define|#
directive|define
name|MII_CTRL_SPEED_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MII_CTRL_SPEED_MASK
value|3
end_define

begin_define
define|#
directive|define
name|MII_CTRL_SPEED_10
value|0
end_define

begin_define
define|#
directive|define
name|MII_CTRL_SPEED_100
value|1
end_define

begin_define
define|#
directive|define
name|MII_CTRL_SPEED_1000
value|2
end_define

begin_define
define|#
directive|define
name|MII_CTRL_IF_MASK
value|3
end_define

begin_define
define|#
directive|define
name|MII_CTRL_IF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MII0_CTRL_IF_GMII
value|0
end_define

begin_define
define|#
directive|define
name|MII0_CTRL_IF_MII
value|1
end_define

begin_define
define|#
directive|define
name|MII0_CTRL_IF_RGMII
value|2
end_define

begin_define
define|#
directive|define
name|MII0_CTRL_IF_RMII
value|3
end_define

begin_define
define|#
directive|define
name|AR71XX_MII1_CTRL
value|0x18070004
end_define

begin_define
define|#
directive|define
name|MII1_CTRL_IF_RGMII
value|0
end_define

begin_define
define|#
directive|define
name|MII1_CTRL_IF_RMII
value|1
end_define

begin_comment
comment|/*  * GigE adapters region  */
end_comment

begin_define
define|#
directive|define
name|AR71XX_MAC0_BASE
value|0x19000000
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC1_BASE
value|0x1A000000
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_CFG1
value|0x00
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_SOFT_RESET
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_SIMUL_RESET
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_MAC_RX_BLOCK_RESET
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_MAC_TX_BLOCK_RESET
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_RX_FUNC_RESET
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_TX_FUNC_RESET
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_LOOPBACK
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_RXFLOW_CTRL
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_TXFLOW_CTRL
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_SYNC_RX
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_RX_ENABLE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_SYNC_TX
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|MAC_CFG1_TX_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_CFG2
value|0x04
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_PREAMBLE_LEN_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_PREAMBLE_LEN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_IFACE_MODE_1000
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_IFACE_MODE_10_100
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_IFACE_MODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_IFACE_MODE_MASK
value|3
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_HUGE_FRAME
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_LENGTH_FIELD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_ENABLE_PADCRC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_ENABLE_CRC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MAC_CFG2_FULL_DUPLEX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_IFG
value|0x08
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_HDUPLEX
value|0x0C
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MAX_FRAME_LEN
value|0x10
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_CFG
value|0x20
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_RESET
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_SCAN_AUTO_INC
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_PREAMBLE_SUP
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_SELECT_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_SELECT_MASK_AR933X
value|0xf
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_4
value|0
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_6
value|2
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_8
value|3
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_10
value|4
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_14
value|5
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_20
value|6
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_28
value|7
end_define

begin_comment
comment|/* .. and the AR933x/AR934x extensions */
end_comment

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_34
value|8
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_42
value|9
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_50
value|10
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_58
value|11
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_66
value|12
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_74
value|13
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_82
value|14
end_define

begin_define
define|#
directive|define
name|MAC_MII_CFG_CLOCK_DIV_98
value|15
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_CMD
value|0x24
end_define

begin_define
define|#
directive|define
name|MAC_MII_CMD_SCAN_CYCLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MAC_MII_CMD_READ
value|1
end_define

begin_define
define|#
directive|define
name|MAC_MII_CMD_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_ADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|MAC_MII_PHY_ADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MAC_MII_PHY_ADDR_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|MAC_MII_REG_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_CONTROL
value|0x2C
end_define

begin_define
define|#
directive|define
name|MAC_MII_CONTROL_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|MAC_MII_STATUS_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_MII_INDICATOR
value|0x34
end_define

begin_define
define|#
directive|define
name|MAC_MII_INDICATOR_NOT_VALID
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MAC_MII_INDICATOR_SCANNING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MAC_MII_INDICATOR_BUSY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_IFCONTROL
value|0x38
end_define

begin_define
define|#
directive|define
name|MAC_IFCONTROL_SPEED
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_STA_ADDR1
value|0x40
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_STA_ADDR2
value|0x44
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_CFG0
value|0x48
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_TX_FABRIC
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_TX_SYSTEM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_RX_FABRIC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_RX_SYSTEM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_WATERMARK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_ALL
value|((1<< 5) - 1)
end_define

begin_define
define|#
directive|define
name|FIFO_CFG0_ENABLE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_CFG1
value|0x4C
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_CFG2
value|0x50
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_TX_THRESHOLD
value|0x54
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RX_FILTMATCH
value|0x58
end_define

begin_comment
comment|/*   * These flags applicable both to AR71XX_MAC_FIFO_RX_FILTMASK and  * to AR71XX_MAC_FIFO_RX_FILTMATCH  */
end_comment

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_UNICAST
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_TRUNC_FRAME
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_VLAN_TAG
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_UNSUP_OPCODE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_PAUSE_FRAME
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_CTRL_FRAME
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_LONG_EVENT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_DRIBBLE_NIBBLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_BCAST
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_MCAST
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_OK
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_OORANGE
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_LEN_MSMTCH
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_CRC_ERROR
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_CODE_ERROR
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_FALSE_CARRIER
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_RX_DV_EVENT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MATCH_DROP_EVENT
value|(1<<  0)
end_define

begin_comment
comment|/*  * Exclude unicast and truncated frames from matching  */
end_comment

begin_define
define|#
directive|define
name|FIFO_RX_FILTMATCH_DEFAULT
define|\
value|(FIFO_RX_MATCH_VLAN_TAG		| \ 				FIFO_RX_MATCH_UNSUP_OPCODE	| \ 				FIFO_RX_MATCH_PAUSE_FRAME	| \ 				FIFO_RX_MATCH_CTRL_FRAME	| \ 				FIFO_RX_MATCH_LONG_EVENT	| \ 				FIFO_RX_MATCH_DRIBBLE_NIBBLE	| \ 				FIFO_RX_MATCH_BCAST		| \ 				FIFO_RX_MATCH_MCAST		| \ 				FIFO_RX_MATCH_OK		| \ 				FIFO_RX_MATCH_OORANGE		| \ 				FIFO_RX_MATCH_LEN_MSMTCH	| \ 				FIFO_RX_MATCH_CRC_ERROR		| \ 				FIFO_RX_MATCH_CODE_ERROR	| \ 				FIFO_RX_MATCH_FALSE_CARRIER	| \ 				FIFO_RX_MATCH_RX_DV_EVENT	| \ 				FIFO_RX_MATCH_DROP_EVENT)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RX_FILTMASK
value|0x5C
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_BYTE_MODE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_NO_SHORT_FRAME
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_BIT17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_BIT16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_TRUNC_FRAME
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_LONG_EVENT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_VLAN_TAG
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_UNSUP_OPCODE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_PAUSE_FRAME
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_CTRL_FRAME
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_DRIBBLE_NIBBLE
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_BCAST
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_MCAST
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_OK
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_OORANGE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_LEN_MSMTCH
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_CODE_ERROR
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_FALSE_CARRIER
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_RX_DV_EVENT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|FIFO_RX_MASK_DROP_EVENT
value|(1<<  0)
end_define

begin_comment
comment|/*  *  Len. mismatch, unsup. opcode and short frmae bits excluded  */
end_comment

begin_define
define|#
directive|define
name|FIFO_RX_FILTMASK_DEFAULT
define|\
value|(FIFO_RX_MASK_NO_SHORT_FRAME	| \ 				FIFO_RX_MASK_BIT17		| \ 				FIFO_RX_MASK_BIT16		| \ 				FIFO_RX_MASK_TRUNC_FRAME	| \ 				FIFO_RX_MASK_LONG_EVENT		| \ 				FIFO_RX_MASK_VLAN_TAG		| \ 				FIFO_RX_MASK_PAUSE_FRAME	| \ 				FIFO_RX_MASK_CTRL_FRAME		| \ 				FIFO_RX_MASK_DRIBBLE_NIBBLE	| \ 				FIFO_RX_MASK_BCAST		| \ 				FIFO_RX_MASK_MCAST		| \ 				FIFO_RX_MASK_OK			| \ 				FIFO_RX_MASK_OORANGE		| \ 				FIFO_RX_MASK_CODE_ERROR		| \ 				FIFO_RX_MASK_FALSE_CARRIER	| \ 				FIFO_RX_MASK_RX_DV_EVENT	| \ 				FIFO_RX_MASK_DROP_EVENT)
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM0
value|0x60
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM1
value|0x64
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM2
value|0x68
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM3
value|0x6C
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM4
value|0x70
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM5
value|0x74
end_define

begin_define
define|#
directive|define
name|AR71XX_MAC_FIFO_RAM6
value|0x78
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_TX_CONTROL
value|0x180
end_define

begin_define
define|#
directive|define
name|DMA_TX_CONTROL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_TX_DESC
value|0x184
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_TX_STATUS
value|0x188
end_define

begin_define
define|#
directive|define
name|DMA_TX_STATUS_PCOUNT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|DMA_TX_STATUS_PCOUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_TX_STATUS_BUS_ERROR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DMA_TX_STATUS_UNDERRUN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DMA_TX_STATUS_PKT_SENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_RX_CONTROL
value|0x18C
end_define

begin_define
define|#
directive|define
name|DMA_RX_CONTROL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_RX_DESC
value|0x190
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_RX_STATUS
value|0x194
end_define

begin_define
define|#
directive|define
name|DMA_RX_STATUS_PCOUNT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|DMA_RX_STATUS_PCOUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_RX_STATUS_BUS_ERROR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DMA_RX_STATUS_OVERFLOW
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DMA_RX_STATUS_PKT_RECVD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_INTR
value|0x198
end_define

begin_define
define|#
directive|define
name|AR71XX_DMA_INTR_STATUS
value|0x19C
end_define

begin_define
define|#
directive|define
name|DMA_INTR_ALL
value|((1<< 8) - 1)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_RX_BUS_ERROR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_RX_OVERFLOW
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_RX_PKT_RCVD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_TX_BUS_ERROR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_TX_UNDERRUN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DMA_INTR_TX_PKT_SENT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR71XX_SPI_BASE
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|AR71XX_SPI_FS
value|0x00
end_define

begin_define
define|#
directive|define
name|AR71XX_SPI_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|SPI_CTRL_REMAP_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SPI_CTRL_CLOCK_DIVIDER_MASK
value|((1<< 6) - 1)
end_define

begin_define
define|#
directive|define
name|AR71XX_SPI_IO_CTRL
value|0x08
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_CS2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_CS1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_CS0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_CSMASK
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_CLK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SPI_IO_CTRL_DO
value|1
end_define

begin_define
define|#
directive|define
name|AR71XX_SPI_RDS
value|0x0C
end_define

begin_define
define|#
directive|define
name|ATH_READ_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|*((volatile uint32_t *)MIPS_PHYS_TO_KSEG1((reg)))
end_define

begin_comment
comment|/*  * Note: Don't put a flush read here; some users (eg the AR724x PCI fixup code)  * requires write-only space to certain registers.  Doing the read afterwards  * causes things to break.  */
end_comment

begin_define
define|#
directive|define
name|ATH_WRITE_REG
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|*((volatile uint32_t *)MIPS_PHYS_TO_KSEG1((reg))) = (val)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|ar71xx_ddr_flush
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|ATH_WRITE_REG
argument_list|(
name|reg
argument_list|,
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|ATH_READ_REG
argument_list|(
name|reg
argument_list|)
operator|&
literal|0x1
operator|)
condition|)
empty_stmt|;
name|ATH_WRITE_REG
argument_list|(
name|reg
argument_list|,
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|ATH_READ_REG
argument_list|(
name|reg
argument_list|)
operator|&
literal|0x1
operator|)
condition|)
empty_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ar71xx_write_pll
parameter_list|(
name|uint32_t
name|cfg_reg
parameter_list|,
name|uint32_t
name|pll_reg
parameter_list|,
name|uint32_t
name|pll
parameter_list|,
name|uint32_t
name|pll_reg_shift
parameter_list|)
block|{
name|uint32_t
name|sec_cfg
decl_stmt|;
comment|/* set PLL registers */
name|sec_cfg
operator|=
name|ATH_READ_REG
argument_list|(
name|cfg_reg
argument_list|)
expr_stmt|;
name|sec_cfg
operator|&=
operator|~
operator|(
literal|3
operator|<<
name|pll_reg_shift
operator|)
expr_stmt|;
name|sec_cfg
operator||=
operator|(
literal|2
operator|<<
name|pll_reg_shift
operator|)
expr_stmt|;
name|ATH_WRITE_REG
argument_list|(
name|cfg_reg
argument_list|,
name|sec_cfg
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|ATH_WRITE_REG
argument_list|(
name|pll_reg
argument_list|,
name|pll
argument_list|)
expr_stmt|;
name|sec_cfg
operator||=
operator|(
literal|3
operator|<<
name|pll_reg_shift
operator|)
expr_stmt|;
name|ATH_WRITE_REG
argument_list|(
name|cfg_reg
argument_list|,
name|sec_cfg
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
name|sec_cfg
operator|&=
operator|~
operator|(
literal|3
operator|<<
name|pll_reg_shift
operator|)
expr_stmt|;
name|ATH_WRITE_REG
argument_list|(
name|cfg_reg
argument_list|,
name|sec_cfg
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|100
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AR71XX_REG_H_ */
end_comment

end_unit

