begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ar5312reg.h,v 1.4 2011/07/07 05:06:44 matt Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2006 Urbana-Champaign Independent Media Center.  * Copyright (c) 2006 Garrett D'Amore.  * All rights reserved.  *  * This code was written by Garrett D'Amore for the Champaign-Urbana  * Community Wireless Network Project.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgements:  *      This product includes software developed by the Urbana-Champaign  *      Independent Media Center.  *	This product includes software developed by Garrett D'Amore.  * 4. Urbana-Champaign Independent Media Center's name and Garrett  *    D'Amore's name may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER AND GARRETT D'AMORE ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE URBANA-CHAMPAIGN INDEPENDENT  * MEDIA CENTER OR GARRETT D'AMORE BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_ATHEROS_AR5312REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_ATHEROS_AR5312REG_H_
end_define

begin_define
define|#
directive|define
name|AR5312_MEM0_BASE
value|0x00000000
end_define

begin_comment
comment|/* sdram */
end_comment

begin_define
define|#
directive|define
name|AR5312_MEM1_BASE
value|0x08000000
end_define

begin_comment
comment|/* sdram/flash */
end_comment

begin_define
define|#
directive|define
name|AR5312_MEM3_BASE
value|0x10000000
end_define

begin_comment
comment|/* flash */
end_comment

begin_define
define|#
directive|define
name|AR5312_WLAN0_BASE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|AR5312_ENET0_BASE
value|0x18100000
end_define

begin_define
define|#
directive|define
name|AR5312_ENET1_BASE
value|0x18200000
end_define

begin_define
define|#
directive|define
name|AR5312_SDRAMCTL_BASE
value|0x18300000
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_BASE
value|0x18400000
end_define

begin_define
define|#
directive|define
name|AR5312_WLAN1_BASE
value|0x18500000
end_define

begin_define
define|#
directive|define
name|AR5312_UART0_BASE
value|0x1C000000
end_define

begin_comment
comment|/* high speed */
end_comment

begin_define
define|#
directive|define
name|AR5312_UART1_BASE
value|0x1C001000
end_define

begin_define
define|#
directive|define
name|AR5312_GPIO_BASE
value|0x1C002000
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_BASE
value|0x1C003000
end_define

begin_define
define|#
directive|define
name|AR5312_UARTDMA_BASE
value|0x1C004000
end_define

begin_define
define|#
directive|define
name|AR5312_FLASH_BASE
value|0x1E000000
end_define

begin_define
define|#
directive|define
name|AR5312_FLASH_END
value|0x20000000
end_define

begin_comment
comment|/* possibly aliased */
end_comment

begin_comment
comment|/*  * FLASHCTL registers  -- offset relative to AR531X_FLASHCTL_BASE  */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_0
value|0x00
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_1
value|0x04
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_2
value|0x08
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_IDCY
value|__BITS(0,3)
end_define

begin_comment
comment|/* idle cycle turn */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_WST1
value|__BITS(5,9)
end_define

begin_comment
comment|/* wait state 1 */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_RBLE
value|__BIT(10)
end_define

begin_comment
comment|/* rd byte enable */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_WST2
value|__BITS(11,15)
end_define

begin_comment
comment|/* wait state 1 */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC
value|__BITS(16,18)
end_define

begin_comment
comment|/* addr chk */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_128K
value|0
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_256K
value|1
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_512K
value|2
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_1M
value|3
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_2M
value|4
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_4M
value|5
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_8M
value|6
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AC_16M
value|7
end_define

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_E
value|__BIT(19)
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_BUSERR
value|__BIT(24)
end_define

begin_comment
comment|/* buserr */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_WPERR
value|__BIT(25)
end_define

begin_comment
comment|/* wperr */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_WP
value|__BIT(26)
end_define

begin_comment
comment|/* wp */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_BM
value|__BIT(27)
end_define

begin_comment
comment|/* bm */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_MW
value|__BITS(28,29)
end_define

begin_comment
comment|/* mem width */
end_comment

begin_define
define|#
directive|define
name|AR5312_FLASHCTL_AT
value|__BITS(31,30)
end_define

begin_comment
comment|/* access type */
end_comment

begin_comment
comment|/*  * GPIO registers  -- offset relative to AR531X_GPIO_BASE  */
end_comment

begin_define
define|#
directive|define
name|AR5312_GPIO_DO
value|0
end_define

begin_define
define|#
directive|define
name|AR5312_GPIO_DI
value|4
end_define

begin_define
define|#
directive|define
name|AR5312_GPIO_CR
value|8
end_define

begin_define
define|#
directive|define
name|AR5312_GPIO_PINS
value|8
end_define

begin_comment
comment|/*  * SYSREG registers  -- offset relative to AR531X_SYSREG_BASE  */
end_comment

begin_define
define|#
directive|define
name|AR5312_SYSREG_TIMER
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_TIMER_RELOAD
value|0x0004
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_WDOG_CTL
value|0x0008
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_WDOG_TIMER
value|0x000c
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_MISC_INTSTAT
value|0x0010
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_MISC_INTMASK
value|0x0014
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_INTSTAT
value|0x0018
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_RESETCTL
value|0x0020
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_CLOCKCTL
value|0x0064
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_SCRATCH
value|0x006c
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_AHBPERR
value|0x0070
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_PROC
value|0x0074
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_AHBDMAE
value|0x0078
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|AR5312_SYSREG_REVISION
value|0x0090
end_define

begin_comment
comment|/* WDOG_CTL watchdog control bits */
end_comment

begin_define
define|#
directive|define
name|AR5312_WDOG_CTL_IGNORE
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5312_WDOG_CTL_NMI
value|0x0001
end_define

begin_define
define|#
directive|define
name|AR5312_WDOG_CTL_RESET
value|0x0002
end_define

begin_comment
comment|/* Resets */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_SYSTEM
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_CPU
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WLAN0
value|__BIT(2)
end_define

begin_comment
comment|/* mac& bb */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_PHY0
value|__BIT(3)
end_define

begin_comment
comment|/* enet phy */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_PHY1
value|__BIT(4)
end_define

begin_comment
comment|/* enet phy */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_ENET0
value|__BIT(5)
end_define

begin_comment
comment|/* mac */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_ENET1
value|__BIT(6)
end_define

begin_comment
comment|/* mac */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_UART0
value|__BIT(8)
end_define

begin_comment
comment|/* mac */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_WLAN1
value|__BIT(9)
end_define

begin_comment
comment|/* mac& bb */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_APB
value|__BIT(10)
end_define

begin_comment
comment|/* bridge */
end_comment

begin_define
define|#
directive|define
name|AR5312_RESET_WARM_CPU
value|__BIT(16)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WARM_WLAN0_MAC
value|__BIT(17)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WARM_WLAN0_BB
value|__BIT(18)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_NMI
value|__BIT(20)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WARM_WLAN1_MAC
value|__BIT(21)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WARM_WLAN1_BB
value|__BIT(22)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_LOCAL_BUS
value|__BIT(23)
end_define

begin_define
define|#
directive|define
name|AR5312_RESET_WDOG
value|__BIT(24)
end_define

begin_comment
comment|/* AR5312/2312 clockctl bits */
end_comment

begin_define
define|#
directive|define
name|AR5312_CLOCKCTL_PREDIVIDE
value|__BITS(4,5)
end_define

begin_define
define|#
directive|define
name|AR5312_CLOCKCTL_MULTIPLIER
value|__BITS(8,12)
end_define

begin_define
define|#
directive|define
name|AR5312_CLOCKCTL_DOUBLER
value|__BIT(16)
end_define

begin_comment
comment|/* AR2313 clockctl */
end_comment

begin_define
define|#
directive|define
name|AR2313_CLOCKCTL_PREDIVIDE
value|__BITS(12,13)
end_define

begin_define
define|#
directive|define
name|AR2313_CLOCKCTL_MULTIPLIER
value|__BITS(16,20)
end_define

begin_comment
comment|/* Enables */
end_comment

begin_define
define|#
directive|define
name|AR5312_ENABLE_WLAN0
value|__BIT(0)
end_define

begin_define
define|#
directive|define
name|AR5312_ENABLE_ENET0
value|__BIT(1)
end_define

begin_define
define|#
directive|define
name|AR5312_ENABLE_ENET1
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|AR5312_ENABLE_WLAN1
value|__BITS(7,8)
end_define

begin_comment
comment|/* both DMA and PIO */
end_comment

begin_comment
comment|/* Revision ids */
end_comment

begin_define
define|#
directive|define
name|AR5312_REVISION_WMAC_MAJOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_WMAC_MINOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xf)
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_WMAC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MAJOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0xf)
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MINOR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xf)
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MAJ_AR5311
value|0x1
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MAJ_AR5312
value|0x4
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MAJ_AR2313
value|0x5
end_define

begin_define
define|#
directive|define
name|AR5312_REVISION_MAJ_AR5315
value|0xB
end_define

begin_comment
comment|/*  * SDRAMCTL registers  -- offset relative to SDRAMCTL  */
end_comment

begin_define
define|#
directive|define
name|AR5312_SDRAMCTL_MEM_CFG0
value|0x0000
end_define

begin_define
define|#
directive|define
name|AR5312_SDRAMCTL_MEM_CFG1
value|0x0004
end_define

begin_comment
comment|/* memory config 1 bits */
end_comment

begin_define
define|#
directive|define
name|AR5312_MEM_CFG1_BANK0
value|__BITS(8,10)
end_define

begin_define
define|#
directive|define
name|AR5312_MEM_CFG1_BANK1
value|__BITS(12,15)
end_define

begin_comment
comment|/* helper macro for accessing system registers without bus space */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|x
parameter_list|)
value|*((volatile uint32_t *)(MIPS_PHYS_TO_KSEG1((x))))
end_define

begin_define
define|#
directive|define
name|GETSYSREG
parameter_list|(
name|x
parameter_list|)
value|REGVAL((x) + AR5312_SYSREG_BASE)
end_define

begin_define
define|#
directive|define
name|PUTSYSREG
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(REGVAL((x) + AR5312_SYSREG_BASE)) = (v)
end_define

begin_define
define|#
directive|define
name|GETSDRAMREG
parameter_list|(
name|x
parameter_list|)
value|REGVAL((x) + AR5312_SDRAMCTL_BASE)
end_define

begin_define
define|#
directive|define
name|PUTSDRAMREG
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(REGVAL((x) + AR5312_SDRAMCTL_BASE)) = (v)
end_define

begin_comment
comment|/*  * Interrupts.  */
end_comment

begin_define
define|#
directive|define
name|AR5312_IRQ_WLAN0
value|0
end_define

begin_define
define|#
directive|define
name|AR5312_IRQ_ENET0
value|1
end_define

begin_define
define|#
directive|define
name|AR5312_IRQ_ENET1
value|2
end_define

begin_define
define|#
directive|define
name|AR5312_IRQ_WLAN1
value|3
end_define

begin_define
define|#
directive|define
name|AR5312_IRQ_MISC
value|4
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_TIMER
value|1
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_AHBPERR
value|2
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_AHBDMAE
value|3
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_GPIO
value|4
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_UART0
value|5
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_UART0_DMA
value|6
end_define

begin_define
define|#
directive|define
name|AR5312_MISC_IRQ_WDOG
value|7
end_define

begin_comment
comment|/*  * Board data.  This is located in flash somewhere, ar531x_board_info  * locates it.  */
end_comment

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_soc.h>
end_include

begin_comment
comment|/* XXX really doesn't belong in hal */
end_comment

begin_comment
comment|/* XXX write-around for now */
end_comment

begin_define
define|#
directive|define
name|AR5312_BOARD_MAGIC
value|AR531X_BD_MAGIC
end_define

begin_comment
comment|/* config bits */
end_comment

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_ENET0
value|BD_ENET0
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_ENET1
value|BD_ENET1
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_UART1
value|BD_UART1
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_UART0
value|BD_UART0
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_RSTFACTORY
value|BD_RSTFACTORY
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_SYSLED
value|BD_SYSLED
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_EXTUARTCLK
value|BD_EXTUARTCLK
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_CPUFREQ
value|BD_CPUFREQ
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_SYSFREQ
value|BD_SYSFREQ
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN0
value|BD_WLAN0
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_MEMCAP
value|BD_MEMCAP
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_DISWDOG
value|BD_DISWATCHDOG
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN1
value|BD_WLAN1
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_AR2312
value|BD_ISCASPER
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN0_2G
value|BD_WLAN0_2G_EN
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN0_5G
value|BD_WLAN0_5G_EN
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN1_2G
value|BD_WLAN1_2G_EN
end_define

begin_define
define|#
directive|define
name|AR5312_BOARD_CONFIG_WLAN1_5G
value|BD_WLAN1_5G_EN
end_define

begin_define
define|#
directive|define
name|AR5312_APB_BASE
value|AR5312_UART0_BASE
end_define

begin_define
define|#
directive|define
name|AR5312_APB_SIZE
value|0x02000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_ATHEROS_AR531XREG_H_ */
end_comment

end_unit

