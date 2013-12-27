begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Texas Instruments - OMAP3xxx series processors  *  * Reference:  *  OMAP35x Applications Processor  *   Technical Reference Manual  *  (omap35xx_techref.pdf)  *  *  * Note:  *  The devices are mapped into address above 0xD000_0000 as the kernel space  *  memory is at 0xC000_0000 and above.  The first 256MB after this is reserved  *  for the size of the kernel, everything above that is reserved for SoC  *  devices.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OMAP35XX_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_OMAP35XX_REG_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for uint32_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OMAP35XX_SDRAM0_START
value|0x80000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRAM1_START
value|0xA0000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRAM_BANKS
value|2
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRAM_BANK_SIZE
value|0x20000000UL
end_define

begin_comment
comment|/* Physical/Virtual address for SDRAM controller */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_SMS_VBASE
value|0x6C000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SMS_HWBASE
value|0x6C000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SMS_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_VBASE
value|0x6D000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_HWBASE
value|0x6D000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_SIZE
value|0x01000000UL
end_define

begin_comment
comment|/* Physical/Virtual address for I/O space */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_L3_VBASE
value|0xD0000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L3_HWBASE
value|0x68000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L3_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_CORE_VBASE
value|0xE8000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_CORE_HWBASE
value|0x48000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_CORE_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_WAKEUP_VBASE
value|0xE8300000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_WAKEUP_HWBASE
value|0x48300000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_WAKEUP_SIZE
value|0x00040000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_PERIPH_VBASE
value|0xE9000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_PERIPH_HWBASE
value|0x49000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_L4_PERIPH_SIZE
value|0x00100000UL
end_define

begin_comment
comment|/*  * L4-CORE Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_SCM_OFFSET
value|0x00002000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_OFFSET
value|0x00004000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDMA_OFFSET
value|0x00056000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C3_OFFSET
value|0x00060000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_TLL_OFFSET
value|0x00062000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_UHH_OFFSET
value|0x00064000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_EHCI_OFFSET
value|0x00064800UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART1_OFFSET
value|0x0006A000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART2_OFFSET
value|0x0006C000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C1_OFFSET
value|0x00070000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C2_OFFSET
value|0x00072000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP1_OFFSET
value|0x00074000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER10_OFFSET
value|0x00086000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER11_OFFSET
value|0x00088000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP5_OFFSET
value|0x00096000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMU1_OFFSET
value|0x000BD400UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_OFFSET
value|0x00200000UL
end_define

begin_comment
comment|/*  * L4-WAKEUP Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_PRM_OFFSET
value|0x00006000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO1_OFFSET
value|0x00010000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER1_OFFSET
value|0x00018000UL
end_define

begin_comment
comment|/*  * L4-PERIPH Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_UART3_OFFSET
value|0x00020000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP2_OFFSET
value|0x00022000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP3_OFFSET
value|0x00024000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP4_OFFSET
value|0x00026000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SIDETONE_MCBSP2_OFFSET
value|0x00028000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SIDETONE_MCBSP3_OFFSET
value|0x0002A000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER2_OFFSET
value|0x00032000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER3_OFFSET
value|0x00034000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER4_OFFSET
value|0x00036000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER5_OFFSET
value|0x00038000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER6_OFFSET
value|0x0003A000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER7_OFFSET
value|0x0003C000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER8_OFFSET
value|0x0003E000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER9_OFFSET
value|0x00040000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO2_OFFSET
value|0x00050000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO3_OFFSET
value|0x00052000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO4_OFFSET
value|0x00054000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO5_OFFSET
value|0x00056000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO6_OFFSET
value|0x00058000UL
end_define

begin_comment
comment|/*  * System Control Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_SCM_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_SCM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_SCM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_REVISION
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_SYSCONFIG
value|0x00000010UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_PADCONFS_BASE
value|0x00000030UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_DEVCONF0
value|0x00000274UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SCM_MEM_DFTRW0
value|0x00000278UL
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_CM_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_CM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_CM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_SIZE
value|0x00001500UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CORE_OFFSET
value|0x00000A00UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CORE_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_FCLKEN1_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0000UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_FCLKEN3_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0008UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN1_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0010UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN2_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0014UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN3_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0018UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST1_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0020UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST2_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0024UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST3_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0028UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE1_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0030UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE2_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0034UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE3_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0038UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0040UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTCTRL_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x0048UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTST_CORE
value|(OMAP35XX_CM_CORE_OFFSET + 0x004CUL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_WKUP_OFFSET
value|0x00000C00UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_WKUP_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_FCLKEN_WKUP
value|(OMAP35XX_CM_WKUP_OFFSET + 0x0000UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN_WKUP
value|(OMAP35XX_CM_WKUP_OFFSET + 0x0010UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST_WKUP
value|(OMAP35XX_CM_WKUP_OFFSET + 0x0020UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE_WKUP
value|(OMAP35XX_CM_WKUP_OFFSET + 0x0030UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL_WKUP
value|(OMAP35XX_CM_WKUP_OFFSET + 0x0040UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_PLL_OFFSET
value|0x00000D00UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_PLL_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKEN_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0000UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKEN2_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0004UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST_CKGEN
value|(OMAP35XX_CM_PLL_OFFSET + 0x0020UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST2_CKGEN
value|(OMAP35XX_CM_PLL_OFFSET + 0x0024UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0030UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE2_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0034UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL1_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0040UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL2_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0044UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL3_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0048UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL4_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x004CUL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL5_PLL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0050UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKOUT_CTRL
value|(OMAP35XX_CM_PLL_OFFSET + 0x0070UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_PER_OFFSET
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_PER_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_FCLKEN_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0000UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0010UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0020UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0030UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSEL_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0040UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_SLEEPDEP_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0044UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTCTRL_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x0048UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTST_PER
value|(OMAP35XX_CM_PER_OFFSET + 0x004CUL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_USBHOST_OFFSET
value|0x00001400UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_USBHOST_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_FCLKEN_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0000UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_ICLKEN_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0010UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_IDLEST_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0020UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_AUTOIDLE_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0030UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_SLEEPDEP_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0044UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTCTRL_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x0048UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_CM_CLKSTST_USBHOST
value|(OMAP35XX_CM_USBHOST_OFFSET + 0x004CUL)
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_PRM_HWBASE
value|(OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_PRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_VBASE
value|(OMAP35XX_L4_WAKEUP_VBASE + OMAP35XX_PRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_SIZE
value|0x00001600UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_CLKCTRL_OFFSET
value|0x00000D00UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_CLKCTRL_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_CLKSEL
value|(OMAP35XX_PRM_CLKCTRL_OFFSET + 0x0040UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_CLKOUT_CTRL
value|(OMAP35XX_PRM_CLKCTRL_OFFSET + 0x0070UL)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_GLOBAL_OFFSET
value|0x00001200UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_GLOBAL_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_PRM_CLKSRC_CTRL
value|(OMAP35XX_PRM_GLOBAL_OFFSET + 0x0070UL)
end_define

begin_comment
comment|/*  * Uarts  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_UART1_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_UART1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART1_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_UART1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART2_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_UART2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART2_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_UART2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART3_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_UART3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART3_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_UART3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_UART3_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * I2C Modules  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_I2C1_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C1_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C1_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C2_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C2_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C2_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C3_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_I2C3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C3_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_I2C3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C3_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_IE
value|0x04
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_STAT
value|0x08
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_WE
value|0x0C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SYSS
value|0x10
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_BUF
value|0x14
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_CNT
value|0x18
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_DATA
value|0x1C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SYSC
value|0x20
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_CON
value|0x24
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_OA0
value|0x28
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SA
value|0x2C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_PSC
value|0x30
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SCLL
value|0x34
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SCLH
value|0x38
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SYSTEST
value|0x3C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_BUFSTAT
value|0x40
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_OA1
value|0x44
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_OA2
value|0x48
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_OA3
value|0x4C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_ACTOA
value|0x50
end_define

begin_define
define|#
directive|define
name|OMAP35XX_I2C_SBLOCK
value|0x54
end_define

begin_comment
comment|/*  * McBSP Modules  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP1_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_MCBSP1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP1_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_MCBSP1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP2_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP2_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP3_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP3_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP3_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP4_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_MCBSP4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP4_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_MCBSP4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP4_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP5_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_MCBSP5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP5_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_MCBSP5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP5_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_DRR
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_DXR
value|0x0008
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SPCR2
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SPCR1
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCR2
value|0x0018
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCR1
value|0x001C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCR2
value|0x0020
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCR1
value|0x0024
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SRGR2
value|0x0028
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SRGR1
value|0x002C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_MCR2
value|0x0030
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_MCR1
value|0x0034
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERA
value|0x0038
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERB
value|0x003C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERA
value|0x0040
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERB
value|0x0044
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_PCR
value|0x0048
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERC
value|0x004C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERD
value|0x0050
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERC
value|0x0054
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERD
value|0x0058
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERE
value|0x005C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERF
value|0x0060
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERE
value|0x0064
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERF
value|0x0068
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERG
value|0x006C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCERH
value|0x0070
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERG
value|0x0074
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCERH
value|0x0078
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RINTCLR
value|0x0080
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XINTCLR
value|0x0084
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_ROVFLCLR
value|0x0088
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SYSCONFIG
value|0x008C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_THRSH2
value|0x0090
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_THRSH1
value|0x0094
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_IRQSTATUS
value|0x00A0
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_IRQENABLE
value|0x00A4
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_WAKEUPEN
value|0x00A8
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XCCR
value|0x00AC
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RCCR
value|0x00B0
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_XBUFFSTAT
value|0x00B4
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_RBUFFSTAT
value|0x00B8
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_SSELCR
value|0x00BC
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MCBSP_STATUS
value|0x00C0
end_define

begin_comment
comment|/*  * USB TTL Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USBTLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_USBTLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_REVISION
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_SYSCONFIG
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_SYSSTATUS
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_IRQSTATUS
value|0x0018
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_IRQENABLE
value|0x001C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_TLL_SHARED_CONF
value|0x0030
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_TLL_CHANNEL_CONF
parameter_list|(
name|i
parameter_list|)
value|(0x0040 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0800 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0801 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_PRODUCT_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0802 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_PRODUCT_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0803 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0804 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0805 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_FUNCTION_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0806 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0807 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0808 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_INTERFACE_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0809 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_OTG_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x080A + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_OTG_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_OTG_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE
parameter_list|(
name|i
parameter_list|)
value|(0x080D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_RISE_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL
parameter_list|(
name|i
parameter_list|)
value|(0x0810 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0811 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_EN_FALL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0812 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0813 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0814 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_DEBUG
parameter_list|(
name|i
parameter_list|)
value|(0x0815 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER
parameter_list|(
name|i
parameter_list|)
value|(0x0816 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0817 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_SCRATCH_REGISTER_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0818 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_EXTENDED_SET_ACCESS
parameter_list|(
name|i
parameter_list|)
value|(0x082F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN
parameter_list|(
name|i
parameter_list|)
value|(0x0830 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0831 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0832 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0833 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VCONTROL_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0834 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0835 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0836 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_UTMI_VSTATUS_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0837 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_USB_INT_LATCH_NOCLR
parameter_list|(
name|i
parameter_list|)
value|(0x0838 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN
parameter_list|(
name|i
parameter_list|)
value|(0x083B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x083C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_INT_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x083D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x083E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USBTLL_ULPI_VENDOR_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x083F + (0x100 * (i)))
end_define

begin_comment
comment|/*  * USB Host Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_USB_TLL_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_TLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_TLL_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_TLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_TLL_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_EHCI_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_EHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_EHCI_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_EHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_EHCI_SIZE
value|0x00000400UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_UHH_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_USB_UHH_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_UHH_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_USB_UHH_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_USB_UHH_SIZE
value|0x00000400UL
end_define

begin_comment
comment|/*  * SDRAM Controler (SDRC)  *  PA 0x6D00_0000  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_SYSCONFIG
value|(OMAP35XX_SDRC_VBASE + 0x10)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_SYSSTATUS
value|(OMAP35XX_SDRC_VBASE + 0x14)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_CS_CFG
value|(OMAP35XX_SDRC_VBASE + 0x40)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_SHARING
value|(OMAP35XX_SDRC_VBASE + 0x44)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_ERR_ADDR
value|(OMAP35XX_SDRC_VBASE + 0x48)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_ERR_TYPE
value|(OMAP35XX_SDRC_VBASE + 0x4C)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_DLLA_CTRL
value|(OMAP35XX_SDRC_VBASE + 0x60)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_DLLA_STATUS
value|(OMAP35XX_SDRC_VBASE + 0x64)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_POWER_REG
value|(OMAP35XX_SDRC_VBASE + 0x70)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_MCFG
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0x80 + (0x30 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_MR
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0x84 + (0x30 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_EMR2
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0x8C + (0x30 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_ACTIM_CTRLA
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0x9C + (0x28 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_ACTIM_CTRLB
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0xA0 + (0x28 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_RFR_CTRL
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0xA4 + (0x30 * (p)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDRC_MANUAL
parameter_list|(
name|p
parameter_list|)
value|(OMAP35XX_SDRC_VBASE + 0xA8 + (0x30 * (p)))
end_define

begin_comment
comment|/*  * SDMA Offset  *  PA 0x4805 6000  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_SDMA_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_SDMA_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDMA_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_SDMA_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_SDMA_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * Interrupt Controller Unit.  *  PA 0x4820_0000  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_INTCPS_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_VBASE
value|(OMAP35XX_L4_CORE_VBASE  + OMAP35XX_INTCPS_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_SYSCONFIG
value|(OMAP35XX_INTCPS_VBASE + 0x10)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_SYSSTATUS
value|(OMAP35XX_INTCPS_VBASE + 0x14)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_SIR_IRQ
value|(OMAP35XX_INTCPS_VBASE + 0x40)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_SIR_FIQ
value|(OMAP35XX_INTCPS_VBASE + 0x44)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_CONTROL
value|(OMAP35XX_INTCPS_VBASE + 0x48)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_PROTECTION
value|(OMAP35XX_INTCPS_VBASE + 0x4C)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_IDLE
value|(OMAP35XX_INTCPS_VBASE + 0x50)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_IRQ_PRIORITY
value|(OMAP35XX_INTCPS_VBASE + 0x60)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_FIQ_PRIORITY
value|(OMAP35XX_INTCPS_VBASE + 0x64)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_THRESHOLD
value|(OMAP35XX_INTCPS_VBASE + 0x68)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_ITR
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x80 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_MIR
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x84 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_MIR_CLEAR
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x88 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_MIR_SET
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x8C + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_ISR_SET
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x90 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_ISR_CLEAR
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x94 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_PENDING_IRQ
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x98 + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_PENDING_FIQ
parameter_list|(
name|n
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x9C + (0x20 * (n)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_INTCPS_ILR
parameter_list|(
name|m
parameter_list|)
value|(OMAP35XX_INTCPS_VBASE + 0x100 + (0x4 * (m)))
end_define

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_EMUINT
value|0
end_define

begin_comment
comment|/* MPU emulation(2) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_COMMTX
value|1
end_define

begin_comment
comment|/* MPU emulation(2) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_COMMRX
value|2
end_define

begin_comment
comment|/* MPU emulation(2) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_BENCH
value|3
end_define

begin_comment
comment|/* MPU emulation(2) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP2_ST
value|4
end_define

begin_comment
comment|/* Sidetone MCBSP2 overflow */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP3_ST
value|5
end_define

begin_comment
comment|/* Sidetone MCBSP3 overflow */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SSM_ABORT
value|6
end_define

begin_comment
comment|/* MPU subsystem secure state-machine abort (2) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SYS_NIRQ
value|7
end_define

begin_comment
comment|/* External source (active low) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED8
value|8
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SMX_DBG
value|9
end_define

begin_comment
comment|/* SMX error for debug */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SMX_APP
value|10
end_define

begin_comment
comment|/* SMX error for application */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_PRCM_MPU
value|11
end_define

begin_comment
comment|/* PRCM module IRQ */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SDMA0
value|12
end_define

begin_comment
comment|/* System DMA request 0(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SDMA1
value|13
end_define

begin_comment
comment|/* System DMA request 1(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SDMA2
value|14
end_define

begin_comment
comment|/* System DMA request 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SDMA3
value|15
end_define

begin_comment
comment|/* System DMA request 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP1
value|16
end_define

begin_comment
comment|/* McBSP module 1 IRQ (3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP2
value|17
end_define

begin_comment
comment|/* McBSP module 2 IRQ (3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SR1
value|18
end_define

begin_comment
comment|/* SmartReflexâ¢ 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SR2
value|19
end_define

begin_comment
comment|/* SmartReflexâ¢ 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPMC
value|20
end_define

begin_comment
comment|/* General-purpose memory controller module */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SGX
value|21
end_define

begin_comment
comment|/* 2D/3D graphics module */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP3
value|22
end_define

begin_comment
comment|/* McBSP module 3(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP4
value|23
end_define

begin_comment
comment|/* McBSP module 4(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_CAM0
value|24
end_define

begin_comment
comment|/* Camera interface request 0 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_DSS
value|25
end_define

begin_comment
comment|/* Display subsystem module(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MAIL_U0
value|26
end_define

begin_comment
comment|/* Mailbox user 0 request */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP5_IRQ1
value|27
end_define

begin_comment
comment|/*  McBSP module 5 (3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_IVA2_MMU
value|28
end_define

begin_comment
comment|/* IVA2 MMU */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO1_MPU
value|29
end_define

begin_comment
comment|/* GPIO module 1(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO2_MPU
value|30
end_define

begin_comment
comment|/* GPIO module 2(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO3_MPU
value|31
end_define

begin_comment
comment|/* GPIO module 3(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO4_MPU
value|32
end_define

begin_comment
comment|/* GPIO module 4(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO5_MPU
value|33
end_define

begin_comment
comment|/* GPIO module 5(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPIO6_MPU
value|34
end_define

begin_comment
comment|/* GPIO module 6(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_USIM
value|35
end_define

begin_comment
comment|/* USIM interrupt (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_WDT3
value|36
end_define

begin_comment
comment|/* Watchdog timer module 3 overflow */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT1
value|37
end_define

begin_comment
comment|/* General-purpose timer module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT2
value|38
end_define

begin_comment
comment|/* General-purpose timer module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT3
value|39
end_define

begin_comment
comment|/* General-purpose timer module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT4
value|40
end_define

begin_comment
comment|/* General-purpose timer module 4 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT5
value|41
end_define

begin_comment
comment|/* General-purpose timer module 5(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT6
value|42
end_define

begin_comment
comment|/* General-purpose timer module 6(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT7
value|43
end_define

begin_comment
comment|/* General-purpose timer module 7(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT8
value|44
end_define

begin_comment
comment|/* General-purpose timer module 8(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT9
value|45
end_define

begin_comment
comment|/* General-purpose timer module 9 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT10
value|46
end_define

begin_comment
comment|/* General-purpose timer module 10 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT11
value|47
end_define

begin_comment
comment|/* General-purpose timer module 11 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SPI4
value|48
end_define

begin_comment
comment|/* McSPI module 4 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SHA1MD5_2
value|49
end_define

begin_comment
comment|/* SHA-1/MD5 crypto-accelerator 2 (HS devices only)(4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_FPKA_IRQREADY_N
value|50
end_define

begin_comment
comment|/* PKA crypto-accelerator (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SHA2MD5
value|51
end_define

begin_comment
comment|/* SHA-2/MD5 crypto-accelerator 1 (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RNG
value|52
end_define

begin_comment
comment|/* RNG module (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MG
value|53
end_define

begin_comment
comment|/* MG function (3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP4_TX
value|54
end_define

begin_comment
comment|/* McBSP module 4 transmit(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP4_RX
value|55
end_define

begin_comment
comment|/* McBSP module 4 receive(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_I2C1
value|56
end_define

begin_comment
comment|/* I2C module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_I2C2
value|57
end_define

begin_comment
comment|/* I2C module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_HDQ
value|58
end_define

begin_comment
comment|/* HDQ / One-wire */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP1_TX
value|59
end_define

begin_comment
comment|/* McBSP module 1 transmit(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP1_RX
value|60
end_define

begin_comment
comment|/* McBSP module 1 receive(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_I2C3
value|61
end_define

begin_comment
comment|/* I2C module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_McBSP2_TX
value|62
end_define

begin_comment
comment|/* McBSP module 2 transmit(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_McBSP2_RX
value|63
end_define

begin_comment
comment|/* McBSP module 2 receive(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_FPKA_IRQRERROR_N
value|64
end_define

begin_comment
comment|/* PKA crypto-accelerator (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SPI1
value|65
end_define

begin_comment
comment|/* McSPI module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SPI2
value|66
end_define

begin_comment
comment|/* McSPI module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED67
value|67
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED68
value|68
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED69
value|69
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED70
value|70
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED71
value|71
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_UART1
value|72
end_define

begin_comment
comment|/* UART module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_UART2
value|73
end_define

begin_comment
comment|/* UART module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_UART3
value|74
end_define

begin_comment
comment|/* UART module 3 (also infrared)(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_PBIAS
value|75
end_define

begin_comment
comment|/* Merged interrupt for PBIASlite1 and 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_OHCI
value|76
end_define

begin_comment
comment|/* OHCI controller HSUSB MP Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_EHCI
value|77
end_define

begin_comment
comment|/* EHCI controller HSUSB MP Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_TLL
value|78
end_define

begin_comment
comment|/* HSUSB MP TLL Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_PARTHASH
value|79
end_define

begin_comment
comment|/* SHA2/MD5 crypto-accelerator 1 (HS devices only) (4) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED80
value|80
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP5_TX
value|81
end_define

begin_comment
comment|/* McBSP module 5 transmit(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP5_RX
value|82
end_define

begin_comment
comment|/* McBSP module 5 receive(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MMC1
value|83
end_define

begin_comment
comment|/* MMC/SD module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MS
value|84
end_define

begin_comment
comment|/* MS-PROâ¢ module */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED85
value|85
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MMC2
value|86
end_define

begin_comment
comment|/* MMC/SD module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MPU_ICR
value|87
end_define

begin_comment
comment|/* MPU ICR */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_RESERVED
value|88
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP3_TX
value|89
end_define

begin_comment
comment|/* McBSP module 3 transmit(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MCBSP3_RX
value|90
end_define

begin_comment
comment|/* McBSP module 3 receive(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_SPI3
value|91
end_define

begin_comment
comment|/* McSPI module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_HSUSB_MC_NINT
value|92
end_define

begin_comment
comment|/* High-Speed USB OTG controller */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_HSUSB_DMA_NINT
value|93
end_define

begin_comment
comment|/* High-Speed USB OTG DMA controller */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_MMC3
value|94
end_define

begin_comment
comment|/* MMC/SD module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_IRQ_GPT12
value|95
end_define

begin_comment
comment|/* General-purpose timer module 12 */
end_comment

begin_comment
comment|/*  * General Purpose Timers  */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER1_VBASE
value|(OMAP35XX_L4_WAKEUP_VBASE + OMAP35XX_GPTIMER1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER1_HWBASE
value|(OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_GPTIMER1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER2_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER2_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER3_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER3_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER4_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER4_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER5_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER5_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER6_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER6_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER7_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER7_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER7_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER7_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER8_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER8_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER8_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER8_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER9_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE + OMAP35XX_GPTIMER9_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER9_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPTIMER9_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER10_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_GPTIMER10_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER10_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_GPTIMER10_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER11_VBASE
value|(OMAP35XX_L4_CORE_VBASE + OMAP35XX_GPTIMER11_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER11_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + OMAP35XX_GPTIMER11_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER12_VBASE
value|0x48304000UL
end_define

begin_comment
comment|/* GPTIMER12 */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/* Timer register offsets */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TIOCP_CFG
value|0x010
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TISTAT
value|0x014
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TISR
value|0x018
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TIER
value|0x01C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TWER
value|0x020
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TCLR
value|0x024
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TCRR
value|0x028
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TLDR
value|0x02C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TTGR
value|0x030
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TWPS
value|0x034
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TMAR
value|0x038
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TCAR1
value|0x03C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TSICR
value|0x040
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TCAR2
value|0x044
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TPIR
value|0x048
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TNIR
value|0x04C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TCVR
value|0x050
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TOCR
value|0x054
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPTIMER_TOWR
value|0x058
end_define

begin_comment
comment|/* Bit values */
end_comment

begin_define
define|#
directive|define
name|MAT_IT_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|OVF_IT_FLAG
value|0x02
end_define

begin_define
define|#
directive|define
name|TCAR_IT_FLAG
value|0x04
end_define

begin_comment
comment|/*  * GPIO - General Purpose IO  */
end_comment

begin_comment
comment|/* Base addresses for the GPIO modules */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_GPIO1_HWBASE
value|(OMAP35XX_L4_WAKEUP_HWBASE + OMAP35XX_GPIO1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO1_VBASE
value|(OMAP35XX_L4_WAKEUP_VBASE  + OMAP35XX_GPIO1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO2_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO2_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO3_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO3_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO3_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO4_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO4_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO4_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO5_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO5_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO5_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO6_HWBASE
value|(OMAP35XX_L4_PERIPH_HWBASE + OMAP35XX_GPIO6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO6_VBASE
value|(OMAP35XX_L4_PERIPH_VBASE  + OMAP35XX_GPIO6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO6_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/* Register offsets within the banks above */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SYSCONFIG
value|0x010
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SYSSTATUS
value|0x014
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_IRQSTATUS1
value|0x018
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_IRQENABLE1
value|0x01C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_WAKEUPENABLE
value|0x020
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_IRQSTATUS2
value|0x028
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_IRQENABLE2
value|0x02C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_CTRL
value|0x030
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_OE
value|0x034
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_DATAIN
value|0x038
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_DATAOUT
value|0x03C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_LEVELDETECT0
value|0x040
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_LEVELDETECT1
value|0x044
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_RISINGDETECT
value|0x048
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_FALLINGDETECT
value|0x04C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_DEBOUNCENABLE
value|0x050
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_DEBOUNCINGTIME
value|0x054
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_CLEARIRQENABLE1
value|0x060
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SETIRQENABLE1
value|0x064
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_CLEARIRQENABLE2
value|0x070
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SETIRQENABLE2
value|0x074
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_CLEARWKUENA
value|0x080
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SETWKUENA
value|0x084
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_CLEARDATAOUT
value|0x090
end_define

begin_define
define|#
directive|define
name|OMAP35XX_GPIO_SETDATAOUT
value|0x094
end_define

begin_comment
comment|/*  * MMC/SD/SDIO  */
end_comment

begin_comment
comment|/* Base addresses for the MMC/SD/SDIO modules */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS1_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + 0x0009C000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS1_VBASE
value|(OMAP35XX_L4_CORE_VBASE + 0x0009C000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS2_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + 0x000B4000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS2_VBASE
value|(OMAP35XX_L4_CORE_VBASE + 0x000B4000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS3_HWBASE
value|(OMAP35XX_L4_CORE_HWBASE + 0x000AD000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS3_VBASE
value|(OMAP35XX_L4_CORE_VBASE + 0x000AD000)
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_SIZE
value|0x00000200UL
end_define

begin_comment
comment|/* Register offsets within each of the MMC/SD/SDIO controllers */
end_comment

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_SYSCONFIG
value|0x010
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_SYSSTATUS
value|0x014
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_CSRE
value|0x024
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_SYSTEST
value|0x028
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_CON
value|0x02C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_PWCNT
value|0x030
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_BLK
value|0x104
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_ARG
value|0x108
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_CMD
value|0x10C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_RSP10
value|0x110
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_RSP32
value|0x114
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_RSP54
value|0x118
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_RSP76
value|0x11C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_DATA
value|0x120
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_PSTATE
value|0x124
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_HCTL
value|0x128
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_SYSCTL
value|0x12C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_STAT
value|0x130
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_IE
value|0x134
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_ISE
value|0x138
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_AC12
value|0x13C
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_CAPA
value|0x140
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_CUR_CAPA
value|0x148
end_define

begin_define
define|#
directive|define
name|OMAP35XX_MMCHS_REV
value|0x1FC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OMAP35XX_REG_H_ */
end_comment

end_unit

