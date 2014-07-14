begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Thomas Skibo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defines for Zynq-7000 SLCR registers.  *  * Most of these registers are initialized by the First Stage Boot  * Loader and are not modified by the kernel.  *  * Reference: Zynq-7000 All Programmable SoC Technical Reference Manual.  * (v1.4) November 16, 2012.  Xilinx doc UG585.  SLCR register definitions  * are in appendix B.28.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZY7_SLCR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZY7_SLCR_H_
end_define

begin_define
define|#
directive|define
name|ZY7_SCLR_SCL
value|0x0000
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LOCK
value|0x0004
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LOCK_MAGIC
value|0x767b
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_UNLOCK
value|0x0008
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_UNLOCK_MAGIC
value|0xdf0d
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LOCKSTA
value|0x000c
end_define

begin_comment
comment|/* PLL controls. */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_PLL_CTRL
value|0x0100
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_PLL_CTRL
value|0x0104
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_IO_PLL_CTRL
value|0x0108
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_RESET
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_PWRDWN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_BYPASS_QUAL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_BYPASS_FORCE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_FDIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CTRL_FDIV_MASK
value|(0x7f<<12)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STATUS
value|0x010c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_ARM_PLL_LOCK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_DDR_PLL_LOCK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_IO_PLL_LOCK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_ARM_PLL_STABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_DDR_PLL_STABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_STAT_IO_PLL_STABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_PLL_CFG
value|0x0110
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_PLL_CFG
value|0x0114
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_IO_PLL_CFG
value|0x0118
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_RES_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_RES_MASK
value|(0xf<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_PLL_CP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_PLL_CP_MASK
value|(0xf<<8)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_LOCK_CNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PLL_CFG_LOCK_CNT_MASK
value|(0x3ff<<12)
end_define

begin_comment
comment|/* Clock controls. */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL
value|0x0120
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_CPU_PERI_CLKACT
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_CPU_1XCLKACT
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_CPU_2XCLKACT
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_CPU_3OR2XCLKACT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_CPU_6OR4XCLKACT
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_SRCSEL_MASK
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_SRCSEL_ARM_PLL
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_SRCSEL_DDR_PLL
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_SRCSEL_IO_PLL
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_DIVISOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_ARM_CLK_CTRL_DIVISOR_MASK
value|(0x3f<<8)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL
value|0x0124
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_2XCLK_DIV_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_2XCLK_DIV_MASK
value|(0x3f<<26)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_3XCLK_DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_3XCLK_DIV_MASK
value|(0x3f<<20)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_2XCLKACT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CLK_CTRL_3XCLKACT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL
value|0x0128
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL_DIVISOR1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL_DIVISOR1_MASK
value|(0x3f<<20)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL_DIVISOR0_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL_DIVISOR0_MASK
value|(0x3f<<8)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DCI_CLK_CTRL_CLKACT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL
value|0x012c
end_define

begin_comment
comment|/* amba periph clk ctrl */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_SMC_CPU_1XCLKACT
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_LQSPI_CPU_1XCLKACT
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_GPIO_CPU_1XCLKACT
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_UART1_CPU_1XCLKACT
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_UART0_CPU_1XCLKACT
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_I2C1_CPU_1XCLKACT
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_I2C0_CPU_1XCLKACT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_CAN1_CPU_1XCLKACT
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_CAN0_CPU_1XCLKACT
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_SPI1_CPU_1XCLKACT
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_SPI0_CPU_1XCLKACT
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_SDI1_CPU_1XCLKACT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_SDI0_CPU_1XCLKACT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_GEM1_CPU_1XCLKACT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_GEM0_CPU_1XCLKACT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_USB1_CPU_1XCLKACT
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_USB0_CPU_1XCLKACT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APER_CLK_CTRL_DMA_CPU_1XCLKACT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_USB0_CLK_CTRL
value|0x0130
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_USB1_CLK_CTRL
value|0x0134
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM0_RCLK_CTRL
value|0x0138
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM1_RCLK_CTRL
value|0x013c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM0_CLK_CTRL
value|0x0140
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM1_CLK_CTRL
value|0x0144
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR1_MASK
value|(0x3f<<20)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR1_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR_MASK
value|(0x3f<<8)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_DIVISOR_MAX
value|0x3f
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_SRCSEL_MASK
value|(7<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_SRCSEL_IO_PLL
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_SRCSEL_ARM_PLL
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_SRCSEL_DDR_PLL
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_SRCSEL_EMIO_CLK
value|(4<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_CLK_CTRL_CLKACT
value|1
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SMC_CLK_CTRL
value|0x0148
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LQSPI_CLK_CTRL
value|0x014c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SDIO_CLK_CTRL
value|0x0150
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_UART_CLK_CTRL
value|0x0154
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SPI_CLK_CTRL
value|0x0158
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_CAN_CLK_CTRL
value|0x015c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_CAN_MIOCLK_CTRL
value|0x0160
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DBG_CLK_CTRL
value|0x0164
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PCAP_CLK_CTRL
value|0x0168
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_TOPSW_CLK_CTRL
value|0x016c
end_define

begin_comment
comment|/* central intercnn clk ctrl */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA0_CLK_CTRL
value|0x0170
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA1_CLK_CTRL
value|0x0180
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA2_CLK_CTRL
value|0x0190
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA3_CLK_CTRL
value|0x01a0
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_CLK_621_TRUE
value|0x01c4
end_define

begin_comment
comment|/* cpu clock ratio mode */
end_comment

begin_comment
comment|/* Reset controls. */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_RST_CTRL
value|0x0200
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_RST_CTRL_SOFT_RESET
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_RST_CTRL
value|0x0204
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_TOPSW_RST_CTRL
value|0x0208
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DMAC_RST_CTRL
value|0x020c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_USB_RST_CTRL
value|0x0210
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GEM_RST_CTRL
value|0x0214
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SDIO_RST_CTRL
value|0x0218
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SPI_RST_CTRL
value|0x021c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_CAN_RST_CTRL
value|0x0220
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_I2C_RST_CTRL
value|0x0224
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_UART_RST_CTRL
value|0x0228
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIO_RST_CTRL
value|0x022c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LQSPI_RST_CTRL
value|0x0230
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SMC_RST_CTRL
value|0x0234
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_OCM_RST_CTRL
value|0x0238
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DEVCI_RST_CTRL
value|0x023c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL
value|0x0240
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL_FPGA3_OUT_RST
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL_FPGA2_OUT_RST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL_FPGA1_OUT_RST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL_FPGA0_OUT_RST
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_FPGA_RST_CTRL_RST_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_A9_CPU_RST_CTRL
value|0x0244
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_RS_AWDT_CTRL
value|0x024c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT
value|0x0258
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_STATE_MASK
value|(0xff<<24)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_POR
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_SRST_B
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_DBG_RST
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_SLC_RST
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_AWDT1_RST
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_AWDT0_RST
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_SWDT_RST
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_REBOOT_STAT_BOOTROM_ERR_CODE_MASK
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE
value|0x025c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_PLL_BYPASS
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_JTAG_INDEP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_MASK
value|7
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_JTAG
value|0
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_QUAD_SPI
value|1
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_NOR
value|2
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_NAND
value|4
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_BOOT_MODE_BOOTDEV_SD_CARD
value|5
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_APU_CTRL
value|0x0300
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_WDT_CLK_SEL
value|0x0304
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE
value|0x0530
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_REVISION_MASK
value|(0xf<<28)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_REVISION_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_FAMILY_MASK
value|(0x7f<<21)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_FAMILY_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_SUB_FAMILY_MASK
value|(0xf<<17)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_SUB_FAMILY_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_DEVICE_MASK
value|(0x1f<<12)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_DEVICE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_MNFR_ID_MASK
value|(0x7ff<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_PSS_IDCODE_MNFR_ID_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_URGENT
value|0x0600
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CAL_START
value|0x060c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_REF_START
value|0x0614
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_CMD_STA
value|0x0618
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_URGENT_SEL
value|0x061c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDR_DFI_STATUS
value|0x0620
end_define

begin_comment
comment|/* MIO Pin controls */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN
parameter_list|(
name|n
parameter_list|)
value|(0x0700+(n)*4)
end_define

begin_comment
comment|/* 0-53 */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_RCVR_DIS
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_PULLUP_EN
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_MASK
value|(7<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_LVTTL
value|(0<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_LVCMOS18
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_LVCMOS25
value|(2<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_LVCMOS33
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_IO_TYPE_HSTL
value|(4<<9)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L2_SEL_MASK
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L2_SEL_L3_MUX
value|(0<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L2_SEL_SRAM_NOR_CS0
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L2_SEL_NAND_CS
value|(2<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L2_SEL_SDIO0_PC
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L1_SEL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_L0_SEL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_PIN_TRI_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_LOOPBACK
value|0x0804
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_LOOPBACK_I2C0_I2C1
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_LOOPBACK_CAN0_CAN1
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_LOOPBACK_UA0_UA1
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_LOOPBACK_SPI0_SPI1
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_MST_TRI0
value|0x080c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_MIO_MST_TRI1
value|0x0810
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SD0_WP_CD_SEL
value|0x0830
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_SD1_WP_CD_SEL
value|0x0834
end_define

begin_comment
comment|/* PS-PL level shifter control. */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN
value|0x900
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN_USER_LVL_IN_EN_0
value|(1<<3)
end_define

begin_comment
comment|/* PL to PS */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN_USER_LVL_OUT_EN_0
value|(1<<2)
end_define

begin_comment
comment|/* PS to PL */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN_USER_LVL_IN_EN_1
value|(1<<1)
end_define

begin_comment
comment|/* PL to PS */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN_USER_LVL_OUT_EN_1
value|(1<<0)
end_define

begin_comment
comment|/* PS to PL */
end_comment

begin_define
define|#
directive|define
name|ZY7_SLCR_LVL_SHFTR_EN_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_OCM_CFG
value|0x0910
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CTRL
value|0x0b00
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CFG_CMOS18
value|0x0b04
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CFG_CMOS25
value|0x0b08
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CFG_CMOS33
value|0x0b0c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CFG_LVTTL
value|0x0b10
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_CFG_HSTL
value|0x0b14
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_GPIOB_DRVR_BIAS_CTRL
value|0x0b18
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_ADDR0
value|0x0b40
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_ADDR1
value|0x0b44
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DATA0
value|0x0b48
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DATA1
value|0x0b4c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DIFF0
value|0x0b50
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DIFF1
value|0x0b54
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_CLK
value|0x0b58
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DRIVE_SLEW_ADDR
value|0x0b5c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DRIVE_SLEW_DATA
value|0x0b60
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DRIVE_SLEW_DIFF
value|0x0b64
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DRIVE_SLEW_CLK
value|0x0b68
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DDR_CTRL
value|0x0b6c
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DCI_CTRL
value|0x0b70
end_define

begin_define
define|#
directive|define
name|ZY7_SLCR_DDRIOB_DCI_STATUS
value|0x0b74
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|void
name|zy7_slcr_preload_pl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|zy7_slcr_postload_pl
parameter_list|(
name|int
name|en_level_shifters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cgem_set_ref_clk
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|frequency
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
comment|/* _ZY7_SLCR_H_ */
end_comment

end_unit

