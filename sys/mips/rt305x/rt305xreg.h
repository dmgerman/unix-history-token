begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RT305XREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RT305XREG_H_
end_define

begin_comment
comment|/* XXX: must move to config */
end_comment

begin_define
define|#
directive|define
name|RT305X
value|1
end_define

begin_define
define|#
directive|define
name|RT305XF
value|1
end_define

begin_define
define|#
directive|define
name|RT3052F
value|1
end_define

begin_define
define|#
directive|define
name|__U_BOOT__
value|1
end_define

begin_comment
comment|/* XXX: must move to config */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RT3052F
end_ifdef

begin_define
define|#
directive|define
name|PLATFORM_COUNTER_FREQ
value|(384 * 1000 * 1000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RT3050F
end_ifdef

begin_define
define|#
directive|define
name|PLATFORM_COUNTER_FREQ
value|(320 * 1000 * 1000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PLATFORM_COUNTER_FREQ
end_ifndef

begin_error
error|#
directive|error
literal|"Nor RT3052F nor RT3050F defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SYSTEM_CLOCK
value|(PLATFORM_COUNTER_FREQ/3)
end_define

begin_define
define|#
directive|define
name|SDRAM_BASE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SDRAM_END
value|0x03FFFFFF
end_define

begin_define
define|#
directive|define
name|SYSCTL_BASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SYSCTL_END
value|0x100000FF
end_define

begin_define
define|#
directive|define
name|TIMER_BASE
value|0x10000100
end_define

begin_define
define|#
directive|define
name|TIMER_END
value|0x100001FF
end_define

begin_define
define|#
directive|define
name|INTCTL_BASE
value|0x10000200
end_define

begin_define
define|#
directive|define
name|INTCTL_END
value|0x100002FF
end_define

begin_define
define|#
directive|define
name|MEMCTRL_BASE
value|0x10000300
end_define

begin_define
define|#
directive|define
name|MEMCTRL_END
value|0x100003FF
end_define

begin_comment
comment|/* SDRAM& Flash/SRAM */
end_comment

begin_define
define|#
directive|define
name|PCM_BASE
value|0x10000400
end_define

begin_define
define|#
directive|define
name|PCM_END
value|0x100004FF
end_define

begin_define
define|#
directive|define
name|UART_BASE
value|0x10000500
end_define

begin_define
define|#
directive|define
name|UART_END
value|0x100005FF
end_define

begin_define
define|#
directive|define
name|PIO_BASE
value|0x10000600
end_define

begin_define
define|#
directive|define
name|PIO_END
value|0x100006FF
end_define

begin_define
define|#
directive|define
name|GDMA_BASE
value|0x10000700
end_define

begin_define
define|#
directive|define
name|GDMA_END
value|0x100007FF
end_define

begin_comment
comment|/* Generic DMA */
end_comment

begin_define
define|#
directive|define
name|NANDFC_BASE
value|0x10000800
end_define

begin_define
define|#
directive|define
name|NANDFC_END
value|0x100008FF
end_define

begin_comment
comment|/* NAND Flash Controller */
end_comment

begin_define
define|#
directive|define
name|I2C_BASE
value|0x10000900
end_define

begin_define
define|#
directive|define
name|I2C_END
value|0x100009FF
end_define

begin_define
define|#
directive|define
name|I2S_BASE
value|0x10000A00
end_define

begin_define
define|#
directive|define
name|I2S_END
value|0x10000AFF
end_define

begin_define
define|#
directive|define
name|SPI_BASE
value|0x10000B00
end_define

begin_define
define|#
directive|define
name|SPI_END
value|0x10000BFF
end_define

begin_define
define|#
directive|define
name|UARTLITE_BASE
value|0x10000C00
end_define

begin_define
define|#
directive|define
name|UARTLITE_END
value|0x10000CFF
end_define

begin_define
define|#
directive|define
name|FRENG_BASE
value|0x10100000
end_define

begin_define
define|#
directive|define
name|FRENG_END
value|0x1010FFFF
end_define

begin_comment
comment|/* Frame Engine */
end_comment

begin_define
define|#
directive|define
name|ETHSW_BASE
value|0x10110000
end_define

begin_define
define|#
directive|define
name|ETHSW_END
value|0x10117FFF
end_define

begin_comment
comment|/* Ethernet Switch */
end_comment

begin_define
define|#
directive|define
name|ROM_BASE
value|0x10118000
end_define

begin_define
define|#
directive|define
name|ROM_END
value|0x10119FFF
end_define

begin_define
define|#
directive|define
name|WLAN_BASE
value|0x10180000
end_define

begin_define
define|#
directive|define
name|WLAN_END
value|0x101BFFFF
end_define

begin_comment
comment|/* 802.11n MAC/BBP */
end_comment

begin_define
define|#
directive|define
name|USB_OTG_BASE
value|0x101C0000
end_define

begin_define
define|#
directive|define
name|USB_OTG_END
value|0x101FFFFF
end_define

begin_define
define|#
directive|define
name|EMEM_BASE
value|0x1B000000
end_define

begin_define
define|#
directive|define
name|EMEM_END
value|0x1BFFFFFF
end_define

begin_comment
comment|/* External SRAM/Flash */
end_comment

begin_define
define|#
directive|define
name|FLASH_BASE
value|0x1F000000
end_define

begin_define
define|#
directive|define
name|FLASH_END
value|0x1FFFFFFF
end_define

begin_comment
comment|/* Flash window */
end_comment

begin_define
define|#
directive|define
name|OBIO_MEM_BASE
value|SYSCTL_BASE
end_define

begin_define
define|#
directive|define
name|OBIO_MEM_START
value|OBIO_MEM_BASE
end_define

begin_define
define|#
directive|define
name|OBIO_MEM_END
value|FLASH_END
end_define

begin_comment
comment|/* System Control */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_CHIPID0_3
value|0x00
end_define

begin_comment
comment|/* 'R''T''3''0' */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_CHIPID4_7
value|0x04
end_define

begin_comment
comment|/* '5''2'' '' ' */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG
value|0x10
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_INIC_EE_SDRAM
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_INIC_8MB_SDRAM
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_GE0_MODE_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_GE0_MODE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_GE0_MODE_RGMII
value|0
end_define

begin_comment
comment|/* RGMII Mode */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_GE0_MODE_MII
value|1
end_define

begin_comment
comment|/* MII Mode */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_GE0_MODE_REV_MII
value|2
end_define

begin_comment
comment|/*Reversed MII Mode*/
end_comment

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_ADDR_1F00
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BYPASS_PLL
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BIG_ENDIAN
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_CPU_CLK_SEL_384MHZ
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_FLASH16
value|0
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_FLASH8
value|1
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_NANDFLASH
value|2
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_BOOT_FROM_ROM
value|3
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_TEST_CODE_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_TEST_CODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SRAM_CS_MODE_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SRAM_CS_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SRAM_CS_MODE_SRAM
value|0
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SRAM_CS_MODE_WDOG_RST
value|1
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SRAM_CS_MODE_BT_COEX
value|2
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG_SDRAM_CLK_DRV
value|(1<<0)
end_define

begin_comment
comment|/* 8mA/12mA */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_TESTSTAT
value|0x18
end_define

begin_define
define|#
directive|define
name|SYSCTL_TESTSTAT2
value|0x1C
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0
value|0x2C
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_MASK
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_ZERO_DELAY
value|0
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_1NS_DELAY
value|1
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_2NS_DELAY
value|2
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0_SDRAM_CLK_SKEW_3NS_DELAY
value|3
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1
value|0x30
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_PBUS_DIV_CLK_BY2
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_OTG_CLK_EN
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_I2S_CLK_EN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_I2S_CLK_SEL_EXT
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_I2S_CLK_DIV_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_I2S_CLK_DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_PCM_CLK_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_PCM_CLK_SEL_EXT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_PCM_CLK_DIV_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1_PCM_CLK_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL
value|0x34
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_ETHSW
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_OTG
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_FRENG
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_WLAN
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_UARTL
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_SPI
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_I2S
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_I2C
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_DMA
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_PIO
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_UART
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_PCM
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_MC
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_INTC
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_TIMER
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL_SYS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTSTAT
value|0x38
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTSTAT_SWCPURST
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTSTAT_SWSYSRST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTSTAT_WDRST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE
value|0x60
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_RGMII_GPIO_MODE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_SDRAM_GPIO_MODE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_MDIO_GPIO_MODE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_JTAG_GPIO_MODE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTL_GPIO_MODE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_UARTF
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_PCM_UARTF
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_PCM_I2S
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_I2S_UARTF
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_PCM_GPIO
value|(4<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_GPIO_UARTF
value|(5<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_GPIO_I2S
value|(6<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_UARTF_SHARE_MODE_GPIO
value|(7<<2)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_SPI_GPIO_MODE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE_I2C_GPIO_MODE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SYSCTL_MEMO0
value|0x68
end_define

begin_define
define|#
directive|define
name|SYSCTL_MEMO1
value|0x6C
end_define

begin_comment
comment|/* Timer */
end_comment

begin_define
define|#
directive|define
name|TIMER_TMRSTAT
value|0x00
end_define

begin_define
define|#
directive|define
name|TIMER_TMRSTAT_TMR1RST
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TIMER_TMRSTAT_TMR0RST
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TIMER_TMRSTAT_TMR1INT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TIMER_TMRSTAT_TMR0INT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TIMER_TMR0LOAD
value|0x10
end_define

begin_define
define|#
directive|define
name|TIMER_TMR0VAL
value|0x14
end_define

begin_define
define|#
directive|define
name|TIMER_TMR0CTL
value|0x18
end_define

begin_define
define|#
directive|define
name|TIMER_TMR1LOAD
value|0x20
end_define

begin_define
define|#
directive|define
name|TIMER_TMR1VAL
value|0x24
end_define

begin_define
define|#
directive|define
name|TIMER_TMR1CTL
value|0x28
end_define

begin_define
define|#
directive|define
name|TIMER_TMRLOAD_TMR0LOAD_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|TIMER_TMRVAL_TMR0VAL_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_ENABLE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_FREE
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_PERIODIC
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_TIMOUT
value|2
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_MODE_TIMOUT3
value|3
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_4
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_8
value|2
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_16
value|3
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_32
value|4
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_64
value|5
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_128
value|6
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_256
value|7
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_512
value|8
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_1K
value|9
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_2K
value|10
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_4K
value|11
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_8K
value|12
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_16K
value|13
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_32K
value|14
end_define

begin_define
define|#
directive|define
name|TIMER_TMRCTL_PRESCALE_BY_64K
value|15
end_define

begin_comment
comment|/* Interrupt Controller */
end_comment

begin_define
define|#
directive|define
name|IC_IRQ0STAT
value|0x00
end_define

begin_define
define|#
directive|define
name|IC_IRQ1STAT
value|0x04
end_define

begin_define
define|#
directive|define
name|IC_INTTYPE
value|0x20
end_define

begin_define
define|#
directive|define
name|IC_INTRAW
value|0x30
end_define

begin_define
define|#
directive|define
name|IC_INT_ENA
value|0x34
end_define

begin_define
define|#
directive|define
name|IC_INT_DIS
value|0x38
end_define

begin_define
define|#
directive|define
name|IC_OTG
value|18
end_define

begin_define
define|#
directive|define
name|IC_ETHSW
value|17
end_define

begin_define
define|#
directive|define
name|IC_UARTLITE
value|12
end_define

begin_define
define|#
directive|define
name|IC_I2S
value|10
end_define

begin_define
define|#
directive|define
name|IC_PERFC
value|9
end_define

begin_define
define|#
directive|define
name|IC_NAND
value|8
end_define

begin_define
define|#
directive|define
name|IC_DMA
value|7
end_define

begin_define
define|#
directive|define
name|IC_PIO
value|6
end_define

begin_define
define|#
directive|define
name|IC_UART
value|5
end_define

begin_define
define|#
directive|define
name|IC_PCM
value|4
end_define

begin_define
define|#
directive|define
name|IC_ILL_ACCESS
value|3
end_define

begin_define
define|#
directive|define
name|IC_WDTIMER
value|2
end_define

begin_define
define|#
directive|define
name|IC_TIMER0
value|1
end_define

begin_define
define|#
directive|define
name|IC_SYSCTL
value|0
end_define

begin_define
define|#
directive|define
name|IC_LINE_GLOBAL
value|(1<<31)
end_define

begin_comment
comment|/* Only for DIS/ENA regs */
end_comment

begin_define
define|#
directive|define
name|IC_LINE_OTG
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|IC_LINE_ETHSW
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|IC_LINE_UARTLITE
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|IC_LINE_I2S
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|IC_LINE_PERFC
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|IC_LINE_NAND
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|IC_LINE_DMA
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|IC_LINE_PIO
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|IC_LINE_UART
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|IC_LINE_PCM
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|IC_LINE_ILL_ACCESS
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|IC_LINE_WDTIMER
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|IC_LINE_TIMER0
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|IC_LINE_SYSCTL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|IC_INT_MASK
value|0x000617ff
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_INT
value|0x00
end_define

begin_comment
comment|/* Programmed I/O Int Status */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_EDGE
value|0x04
end_define

begin_comment
comment|/* Programmed I/O Edge Status */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_RENA
value|0x08
end_define

begin_comment
comment|/* Programmed I/O Int on Rising */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_FENA
value|0x0C
end_define

begin_comment
comment|/* Programmed I/O Int on Falling */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_DATA
value|0x20
end_define

begin_comment
comment|/* Programmed I/O Data */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_DIR
value|0x24
end_define

begin_comment
comment|/* Programmed I/O Direction */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_POL
value|0x28
end_define

begin_comment
comment|/* Programmed I/O Pin Polarity */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_SET
value|0x2C
end_define

begin_comment
comment|/* Set PIO Data Bit */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_RESET
value|0x30
end_define

begin_comment
comment|/* Clear PIO Data bit */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_TOG
value|0x34
end_define

begin_comment
comment|/* Toggle PIO Data bit */
end_comment

begin_define
define|#
directive|define
name|GPIO39_24_INT
value|0x38
end_define

begin_define
define|#
directive|define
name|GPIO39_24_EDGE
value|0x3c
end_define

begin_define
define|#
directive|define
name|GPIO39_24_RENA
value|0x40
end_define

begin_define
define|#
directive|define
name|GPIO39_24_FENA
value|0x44
end_define

begin_define
define|#
directive|define
name|GPIO39_24_DATA
value|0x48
end_define

begin_define
define|#
directive|define
name|GPIO39_24_DIR
value|0x4c
end_define

begin_define
define|#
directive|define
name|GPIO39_24_POL
value|0x50
end_define

begin_define
define|#
directive|define
name|GPIO39_24_SET
value|0x54
end_define

begin_define
define|#
directive|define
name|GPIO39_24_RESET
value|0x58
end_define

begin_define
define|#
directive|define
name|GPIO39_24_TOG
value|0x5c
end_define

begin_define
define|#
directive|define
name|GPIO51_40_INT
value|0x60
end_define

begin_define
define|#
directive|define
name|GPIO51_40_EDGE
value|0x64
end_define

begin_define
define|#
directive|define
name|GPIO51_40_RENA
value|0x68
end_define

begin_define
define|#
directive|define
name|GPIO51_40_FENA
value|0x6C
end_define

begin_define
define|#
directive|define
name|GPIO51_40_DATA
value|0x70
end_define

begin_define
define|#
directive|define
name|GPIO51_40_DIR
value|0x74
end_define

begin_define
define|#
directive|define
name|GPIO51_40_POL
value|0x78
end_define

begin_define
define|#
directive|define
name|GPIO51_40_SET
value|0x7C
end_define

begin_define
define|#
directive|define
name|GPIO51_40_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|GPIO51_40_TOG
value|0x84
end_define

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ0
value|0
end_define

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ1
value|1
end_define

begin_comment
comment|/* (NAND-flash) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ2
value|2
end_define

begin_comment
comment|/* (I2S) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ3
value|3
end_define

begin_comment
comment|/* (PCM0-RX) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ4
value|4
end_define

begin_comment
comment|/* (PCM1-RX) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ5
value|5
end_define

begin_comment
comment|/* (PCM0-TX) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ6
value|6
end_define

begin_comment
comment|/* (PCM1-TX) */
end_comment

begin_define
define|#
directive|define
name|GDMA_CHANNEL_REQ7
value|7
end_define

begin_define
define|#
directive|define
name|GDMA_CHANNEL_MEM
value|8
end_define

begin_comment
comment|/* Generic DMA Controller */
end_comment

begin_comment
comment|/* GDMA Channel n Source Address */
end_comment

begin_define
define|#
directive|define
name|GDMASA
parameter_list|(
name|n
parameter_list|)
value|(0x00 + 0x10*n)
end_define

begin_comment
comment|/* GDMA Channel n Destination Address */
end_comment

begin_define
define|#
directive|define
name|GDMADA
parameter_list|(
name|n
parameter_list|)
value|(0x04 + 0x10*n)
end_define

begin_comment
comment|/* GDMA Channel n Control Register 0 */
end_comment

begin_define
define|#
directive|define
name|GDMACT0
parameter_list|(
name|n
parameter_list|)
value|(0x08 + 0x10*n)
end_define

begin_define
define|#
directive|define
name|GDMACT0_TR_COUNT_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|GDMACT0_TR_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GDMACT0_SRC_CHAN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|GDMACT0_SRC_CHAN_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|GDMACT0_DST_CHAN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GDMACT0_DST_CHAN_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|GDMACT0_SRC_BURST_MODE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GDMACT0_DST_BURST_MODE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_1
value|0
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_2
value|1
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_4
value|2
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_8
value|3
end_define

begin_define
define|#
directive|define
name|GDMACT0_BURST_SIZE_16
value|4
end_define

begin_define
define|#
directive|define
name|GDMACT0_DONE_INT_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GDMACT0_CHAN_EN
value|(1<<1)
end_define

begin_comment
comment|/*  * In software mode, the data transfer will start when the Channel Enable bit  * is set.  * In hardware mode, the data transfer will start when the DMA Request is  * asserted. */
end_comment

begin_define
define|#
directive|define
name|GDMACT0_SWMODE
value|(1<<0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RT305XREG_H_ */
end_comment

end_unit

