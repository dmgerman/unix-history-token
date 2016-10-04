begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ar5315reg.h,v 1.3 2011/07/07 05:06:44 matt Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2006 Urbana-Champaign Independent Media Center.  * Copyright (c) 2006 Garrett D'Amore.  * All rights reserved.  *  * This code was written by Garrett D'Amore for the Champaign-Urbana  * Community Wireless Network Project.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgements:  *      This product includes software developed by the Urbana-Champaign  *      Independent Media Center.  *	This product includes software developed by Garrett D'Amore.  * 4. Urbana-Champaign Independent Media Center's name and Garrett  *    D'Amore's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER AND GARRETT D'AMORE ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER OR GARRETT D'AMORE BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_ATHEROS_AR5315REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_ATHEROS_AR5315REG_H_
end_define

begin_define
define|#
directive|define
name|AR5315_MEM0_BASE
value|0x00000000
end_define

begin_comment
comment|/* sdram */
end_comment

begin_define
define|#
directive|define
name|AR5315_MEM1_BASE
value|0x08000000
end_define

begin_comment
comment|/* spi flash */
end_comment

begin_define
define|#
directive|define
name|AR5315_WLAN_BASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_BASE
value|0x10100000
end_define

begin_define
define|#
directive|define
name|AR5315_SDRAMCTL_BASE
value|0x10300000
end_define

begin_define
define|#
directive|define
name|AR5315_LOCAL_BASE
value|0x10400000
end_define

begin_comment
comment|/* local bus */
end_comment

begin_define
define|#
directive|define
name|AR5315_ENET_BASE
value|0x10500000
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_BASE
value|0x11000000
end_define

begin_define
define|#
directive|define
name|AR5315_UART_BASE
value|0x11100000
end_define

begin_define
define|#
directive|define
name|AR5315_SPI_BASE
value|0x11300000
end_define

begin_comment
comment|/* spi flash */
end_comment

begin_define
define|#
directive|define
name|AR5315_BOOTROM_BASE
value|0x1FC00000
end_define

begin_comment
comment|/* boot rom */
end_comment

begin_define
define|#
directive|define
name|AR5315_CONFIG_BASE
value|0x087D0000
end_define

begin_comment
comment|/* flash start */
end_comment

begin_define
define|#
directive|define
name|AR5315_CONFIG_END
value|0x087FF000
end_define

begin_comment
comment|/* flash end */
end_comment

begin_define
define|#
directive|define
name|AR5315_RADIO_END
value|0x1FFFF000
end_define

begin_comment
comment|/* radio end */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AR5315_PCIEXT_BASE
value|0x80000000
end_define

begin_comment
comment|/* pci external */
end_comment

begin_define
define|#
directive|define
name|AR5315_RAM2_BASE
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|AR5315_RAM3_BASE
value|0xe0000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SYSREG registers  -- offset relative to AR531X_SYSREG_BASE  */
end_comment

begin_define
define|#
directive|define
name|AR5315_SYSREG_COLDRESET
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_RESETCTL
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ARB_CTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_ENDIAN
value|0x000c
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_NMI_CTL
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_SREV
value|0x0014
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_IF_CTL
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_MISC_INTSTAT
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_MISC_INTMASK
value|0x0024
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_GISR
value|0x0028
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_TIMER
value|0x0030
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_RELOAD
value|0x0034
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_WDOG_TIMER
value|0x0038
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_WDOG_CTL
value|0x003c
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_PERFCNT0
value|0x0048
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_PERFCNT1
value|0x004c
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ERR0
value|0x0050
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ERR1
value|0x0054
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ERR2
value|0x0058
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ERR3
value|0x005c
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AHB_ERR4
value|0x0060
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_PLLC_CTL
value|0x0064
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_PLLV_CTL
value|0x0068
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_CPUCLK
value|0x006c
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_AMBACLK
value|0x0070
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_SYNCCLK
value|0x0074
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_DSL_SLEEP_CTL
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_DSL_SLEEP_DUR
value|0x0084
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_GPIO_DI
value|0x0088
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_GPIO_DO
value|0x0090
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_GPIO_CR
value|0x0098
end_define

begin_define
define|#
directive|define
name|AR5315_SYSREG_GPIO_INT
value|0x00a0
end_define

begin_define
define|#
directive|define
name|AR5315_GPIO_PINS
value|23
end_define

begin_comment
comment|/* Cold resets (AR5315_SYSREG_COLDRESET) */
end_comment

begin_define
define|#
directive|define
name|AR5315_COLD_AHB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR5315_COLD_APB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR5315_COLD_CPU
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AR5315_COLD_CPU_WARM
value|0x00000008
end_define

begin_comment
comment|/* Resets (AR5315_SYSREG_RESETCTL) */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_WARM_WLAN0_MAC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR5315_RESET_WARM_WLAN0_BB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AR5315_RESET_MPEGTS
value|0x00000004
end_define

begin_comment
comment|/* MPEG-TS */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_PCIDMA
value|0x00000008
end_define

begin_comment
comment|/* PCI dma */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_MEMCTL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AR5315_RESET_LOCAL
value|0x00000020
end_define

begin_comment
comment|/* local bus */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_I2C
value|0x00000040
end_define

begin_comment
comment|/* i2c */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_SPI
value|0x00000080
end_define

begin_comment
comment|/* SPI */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_UART
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AR5315_RESET_IR
value|0x00000200
end_define

begin_comment
comment|/* infrared */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_PHY0
value|0x00000400
end_define

begin_comment
comment|/* enet phy */
end_comment

begin_define
define|#
directive|define
name|AR5315_RESET_ENET0
value|0x00000800
end_define

begin_comment
comment|/* Watchdog control (AR5315_SYSREG_WDOG_CTL) */
end_comment

begin_define
define|#
directive|define
name|AR5315_WDOG_CTL_IGNORE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5315_WDOG_CTL_NMI
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR5315_WDOG_CTL_RESET
value|0x0002
end_define

begin_comment
comment|/* AR5315 AHB arbitration control (AR5315_SYSREG_AHB_ARB_CTL) */
end_comment

begin_define
define|#
directive|define
name|AR5315_ARB_CPU
value|0x00001
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_WLAN
value|0x00002
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_MPEGTS
value|0x00004
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_LOCAL
value|0x00008
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_PCI
value|0x00010
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_ENET
value|0x00020
end_define

begin_define
define|#
directive|define
name|AR5315_ARB_RETRY
value|0x00100
end_define

begin_comment
comment|/* AR5315 endianness control (AR5315_SYSREG_ENDIAN) */
end_comment

begin_define
define|#
directive|define
name|AR5315_ENDIAN_AHB
value|0x00001
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_WLAN
value|0x00002
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_MPEGTS
value|0x00004
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_PCI
value|0x00008
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_MEMCTL
value|0x00010
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_LOCAL
value|0x00020
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_ENET
value|0x00040
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_MERGE
value|0x00200
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_CPU
value|0x00400
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_PCIAHB
value|0x00800
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_PCIAHB_BRIDGE
value|0x01000
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_SPI
value|0x08000
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_CPU_DRAM
value|0x10000
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_CPU_PCI
value|0x20000
end_define

begin_define
define|#
directive|define
name|AR5315_ENDIAN_CPU_MMR
value|0x40000
end_define

begin_comment
comment|/* AR5315 AHB error bits */
end_comment

begin_define
define|#
directive|define
name|AR5315_AHB_ERROR_DET
value|1
end_define

begin_comment
comment|/* error detected */
end_comment

begin_define
define|#
directive|define
name|AR5315_AHB_ERROR_OVR
value|2
end_define

begin_comment
comment|/* AHB overflow */
end_comment

begin_define
define|#
directive|define
name|AR5315_AHB_ERROR_WDT
value|4
end_define

begin_comment
comment|/* wdt (not hresp) */
end_comment

begin_comment
comment|/* AR5315 clocks */
end_comment

begin_define
define|#
directive|define
name|AR5315_PLLC_REF_DIV
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0x3)
end_define

begin_define
define|#
directive|define
name|AR5315_PLLC_FB_DIV
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0x7c)>> 2)
end_define

begin_define
define|#
directive|define
name|AR5315_PLLC_DIV_2
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0x80)>> 7)
end_define

begin_define
define|#
directive|define
name|AR5315_PLLC_CLKC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0x1c000)>> 14)
end_define

begin_define
define|#
directive|define
name|AR5315_PLLC_CLKM
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0x700000)>> 20)
end_define

begin_define
define|#
directive|define
name|AR5315_CLOCKCTL_SELECT
parameter_list|(
name|reg
parameter_list|)
value|((reg)& 0x3)
end_define

begin_define
define|#
directive|define
name|AR5315_CLOCKCTL_DIV
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& 0xc)>> 2)
end_define

begin_comment
comment|/*  * SDRAMCTL registers  -- offset relative to SDRAMCTL  */
end_comment

begin_define
define|#
directive|define
name|AR5315_SDRAMCTL_MEM_CFG
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5315_MEM_CFG_DATA_WIDTH
value|__BITS(13,14)
end_define

begin_define
define|#
directive|define
name|AR5315_MEM_CFG_COL_WIDTH
value|__BITS(9,12)
end_define

begin_define
define|#
directive|define
name|AR5315_MEM_CFG_ROW_WIDTH
value|__BITS(5,8)
end_define

begin_comment
comment|/* memory config 1 bits */
end_comment

begin_define
define|#
directive|define
name|AR531X_MEM_CFG1_BANK0
value|__BITS(8,10)
end_define

begin_define
define|#
directive|define
name|AR531X_MEM_CFG1_BANK1
value|__BITS(12,14)
end_define

begin_comment
comment|/*  * PCI configuration stuff.  I don't pretend to fully understand these  * registers, they seem to be magic numbers in the Linux code.  */
end_comment

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_RC
value|0x4000
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_SCR
value|0x4004
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_INTPEND
value|0x4008
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_SFR
value|0x400c
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_PCICFG
value|0x4010
end_define

begin_define
define|#
directive|define
name|AR5315_PCI_MAC_SREV
value|0x4020
end_define

begin_define
define|#
directive|define
name|PCI_MAC_RC_MAC
value|0x1
end_define

begin_define
define|#
directive|define
name|PCI_MAC_RC_BB
value|0x2
end_define

begin_define
define|#
directive|define
name|PCI_MAC_SCR_SLM_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PCI_MAC_SCR_SLM_FWAKE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_MAC_SCR_SLM_FSLEEP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_MAC_SCR_SLM_NORMAL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCI_MAC_PCICFG_SPWR_DN
value|0x00010000
end_define

begin_comment
comment|/* IRQS */
end_comment

begin_define
define|#
directive|define
name|AR5315_CPU_IRQ_MISC
value|0
end_define

begin_define
define|#
directive|define
name|AR5315_CPU_IRQ_WLAN
value|1
end_define

begin_define
define|#
directive|define
name|AR5315_CPU_IRQ_ENET
value|2
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_UART
value|0
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_I2C
value|1
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_SPI
value|2
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_AHBE
value|3
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_AHPE
value|4
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_TIMER
value|5
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_GPIO
value|6
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_WDOG
value|7
end_define

begin_define
define|#
directive|define
name|AR5315_MISC_IRQ_IR
value|8
end_define

begin_define
define|#
directive|define
name|AR5315_APB_BASE
value|AR5315_SYSREG_BASE
end_define

begin_define
define|#
directive|define
name|AR5315_APB_SIZE
value|0x06000000
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

begin_comment
comment|/* Helpers from NetBSD cdefs.h */
end_comment

begin_comment
comment|/* __BIT(n): nth bit, where __BIT(0) == 0x1. */
end_comment

begin_define
define|#
directive|define
name|__BIT
parameter_list|(
name|__n
parameter_list|)
define|\
value|(((__n)>= NBBY * sizeof(uintmax_t)) ? 0 : ((uintmax_t)1<< (__n)))
end_define

begin_comment
comment|/* __BITS(m, n): bits m through n, m< n. */
end_comment

begin_define
define|#
directive|define
name|__BITS
parameter_list|(
name|__m
parameter_list|,
name|__n
parameter_list|)
define|\
value|((__BIT(MAX((__m), (__n)) + 1) - 1) ^ (__BIT(MIN((__m), (__n))) - 1))
end_define

begin_comment
comment|/* find least significant bit that is set */
end_comment

begin_define
define|#
directive|define
name|__LOWEST_SET_BIT
parameter_list|(
name|__mask
parameter_list|)
value|((((__mask) - 1)& (__mask)) ^ (__mask))
end_define

begin_define
define|#
directive|define
name|__SHIFTOUT
parameter_list|(
name|__x
parameter_list|,
name|__mask
parameter_list|)
value|(((__x)& (__mask)) / __LOWEST_SET_BIT(__mask))
end_define

begin_define
define|#
directive|define
name|__SHIFTOUT_MASK
parameter_list|(
name|__mask
parameter_list|)
value|__SHIFTOUT((__mask), (__mask))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_ATHEROS_AR531XREG_H_ */
end_comment

end_unit

