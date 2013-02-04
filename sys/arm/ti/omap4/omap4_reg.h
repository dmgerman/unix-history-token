begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Texas Instruments - OMAP44xx series processors  *  * Reference:  *  OMAP44xx Applications Processor  *   Technical Reference Manual  *  (omap44xx_techref.pdf)  *  *  * Note:  *  The devices are mapped into address above 0xD000_0000 as the kernel space  *  memory is at 0xC000_0000 and above.  The first 256MB after this is reserved  *  for the size of the kernel, everything above that is reserved for SoC  *  devices.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OMAP44XX_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_OMAP44XX_REG_H_
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

begin_comment
comment|/* Physical/Virtual address for SDRAM controller */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SMS_VBASE
value|0x6C000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SMS_HWBASE
value|0x6C000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SMS_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDRC_VBASE
value|0x6D000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDRC_HWBASE
value|0x6D000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDRC_SIZE
value|0x01000000UL
end_define

begin_comment
comment|/* Physical/Virtual address for I/O space */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMU_VBASE
value|0xD4000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMU_HWBASE
value|0x54000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMU_SIZE
value|0x00200000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF1_VBASE
value|0xEC000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF1_HWBASE
value|0x4C000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF1_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF2_VBASE
value|0xED000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF2_HWBASE
value|0x4D000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L3_EMIF2_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_CORE_VBASE
value|0xEA000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_CORE_HWBASE
value|0x4A000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_CORE_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_WAKEUP_VBASE
value|0xEA300000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_WAKEUP_HWBASE
value|0x4A300000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_WAKEUP_SIZE
value|0x00040000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_PERIPH_VBASE
value|0xE8000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_PERIPH_HWBASE
value|0x48000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_PERIPH_SIZE
value|0x01000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_ABE_VBASE
value|0xE9000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_ABE_HWBASE
value|0x49000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_L4_ABE_SIZE
value|0x00100000UL
end_define

begin_comment
comment|/* Physical/Virtual address for MPU Subsystem space */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_MPU_SUBSYS_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + 0x00240000UL)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MPU_SUBSYS_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + 0x00240000UL)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MPU_SUBSYS_SIZE
value|0x00004000UL
end_define

begin_comment
comment|/*  * MPU Subsystem addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SCU_OFFSET
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_CPU_OFFSET
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GBL_TIMER_OFFSET
value|0x00000200UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRV_TIMER_OFFSET
value|0x00000600UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_DIST_OFFSET
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PL310_OFFSET
value|0x00002000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CORTEXA9_SOCKET_PRCM_OFFSET
value|0x00003000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CORTEXA9_PRM_OFFSET
value|0x00003200UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CORTEXA9_CPU0_OFFSET
value|0x00003400UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CORTEXA9_CPU1_OFFSET
value|0x00003800UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCU_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_SCU_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCU_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_SCU_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCU_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_CPU_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_GIC_CPU_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_CPU_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_GIC_CPU_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_CPU_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GBL_TIMER_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_GBL_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GBL_TIMER_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_GBL_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GBL_TIMER_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRV_TIMER_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_PRV_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRV_TIMER_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_PRV_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRV_TIMER_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_DIST_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_GIC_DIST_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_DIST_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_GIC_DIST_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GIC_DIST_SIZE
value|0x00000100UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PL310_HWBASE
value|(OMAP44XX_MPU_SUBSYS_HWBASE + OMAP44XX_PL310_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PL310_VBASE
value|(OMAP44XX_MPU_SUBSYS_VBASE  + OMAP44XX_PL310_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PL310_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * L4-CORE Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SCM_OFFSET
value|0x00002000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CM_OFFSET
value|0x00004000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDMA_OFFSET
value|0x00056000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_TLL_OFFSET
value|0x00062000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_UHH_OFFSET
value|0x00064000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_OHCI_OFFSET
value|0x00064800UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_EHCI_OFFSET
value|0x00064C00UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP1_OFFSET
value|0x00074000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP5_OFFSET
value|0x00096000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCM_PADCONF_OFFSET
value|0x00100000UL
end_define

begin_comment
comment|/*  * L4-WAKEUP Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_PRM_OFFSET
value|0x00006000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCRM_OFFSET
value|0x0000A000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO1_OFFSET
value|0x00010000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER1_OFFSET
value|0x00018000UL
end_define

begin_comment
comment|/*  * L4-PERIPH Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_UART3_OFFSET
value|0x00020000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER2_OFFSET
value|0x00032000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER3_OFFSET
value|0x00034000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER4_OFFSET
value|0x00036000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER9_OFFSET
value|0x0003E000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO2_OFFSET
value|0x00055000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO3_OFFSET
value|0x00057000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO4_OFFSET
value|0x00059000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO5_OFFSET
value|0x0005B000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO6_OFFSET
value|0x0005D000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C3_OFFSET
value|0x00060000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART1_OFFSET
value|0x0006A000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART2_OFFSET
value|0x0006C000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART4_OFFSET
value|0x0006E000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C1_OFFSET
value|0x00070000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C2_OFFSET
value|0x00072000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SLIMBUS2_OFFSET
value|0x00076000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_ELM_OFFSET
value|0x00078000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER10_OFFSET
value|0x00086000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER11_OFFSET
value|0x00088000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP4_OFFSET
value|0x00096000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCSPI1_OFFSET
value|0x00098000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCSPI2_OFFSET
value|0x0009A000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS1_OFFSET
value|0x0009C000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCSD3_OFFSET
value|0x000AD000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS2_OFFSET
value|0x000B4000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCSD4_OFFSET
value|0x000D1000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCSD5_OFFSET
value|0x000D5000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C4_OFFSET
value|0x00350000UL
end_define

begin_comment
comment|/* The following are registers defined as part of the ARM MPCORE system,  * they are not SoC components rather registers that control the MPCORE core.  */
end_comment

begin_comment
comment|// #define OMAP44XX_SCU_OFFSET			0x48240000	/* Snoop control unit */
end_comment

begin_comment
comment|// #define OMAP44XX_GIC_PROC_OFFSET	0x48240100	/* Interrupt controller unit */
end_comment

begin_comment
comment|// #define OMAP44XX_MPU_TIMER_OFFSET	0x48240600
end_comment

begin_comment
comment|// #define OMAP44XX_GIC_INTR_OFFSET	0x48241000
end_comment

begin_comment
comment|// #define OMAP44XX_PL310_OFFSET		0x48242000	/* L2 Cache controller */
end_comment

begin_comment
comment|/*  * L4-ABE Physical/Virtual addresss offsets  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER5_OFFSET
value|0x00038000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER6_OFFSET
value|0x0003A000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER7_OFFSET
value|0x0003C000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER8_OFFSET
value|0x0003E000UL
end_define

begin_comment
comment|/*  * System Control Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SCM_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_SCM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCM_VBASE
value|(OMAP44XX_L4_CORE_VBASE + OMAP44XX_SCM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCM_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_CM_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_CM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CM_VBASE
value|(OMAP44XX_L4_CORE_VBASE + OMAP44XX_CM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_CM_SIZE
value|0x00001500UL
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_PRM_HWBASE
value|(OMAP44XX_L4_WAKEUP_HWBASE + OMAP44XX_PRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRM_VBASE
value|(OMAP44XX_L4_WAKEUP_VBASE + OMAP44XX_PRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_PRM_SIZE
value|0x00001600UL
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SCRM_HWBASE
value|(OMAP44XX_L4_WAKEUP_HWBASE + OMAP44XX_SCRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCRM_VBASE
value|(OMAP44XX_L4_WAKEUP_VBASE + OMAP44XX_SCRM_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCRM_SIZE
value|0x00000800UL
end_define

begin_comment
comment|/*  * Uarts  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_UART1_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_UART1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART1_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_UART1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART2_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_UART2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART2_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_UART2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART3_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_UART3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART3_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_UART3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART3_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART4_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_UART4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART4_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_UART4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_UART4_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * I2C Modules  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_I2C1_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_I2C1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C1_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_I2C1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C1_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C2_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_I2C2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C2_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_I2C2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C2_SIZE
value|0x00000080UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C3_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_I2C3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C3_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_I2C3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_I2C3_SIZE
value|0x00000080UL
end_define

begin_comment
comment|/*  * McBSP Modules  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP1_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_MCBSP1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP1_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_MCBSP1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP2_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MCBSP2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP2_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_MCBSP2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP3_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MCBSP3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP3_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_MCBSP3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP3_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP4_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MCBSP4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP4_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_MCBSP4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP4_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP5_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_MCBSP5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP5_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_MCBSP5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MCBSP5_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * USB TTL Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_USB_TLL_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_USB_TLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_TLL_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_USB_TLL_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_TLL_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * USB Host Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_USB_UHH_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_USB_UHH_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_UHH_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_USB_UHH_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_UHH_SIZE
value|0x00000700UL
end_define

begin_comment
comment|/*  * USB OHCI Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_USB_OHCI_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_USB_OHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_OHCI_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_USB_OHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_OHCI_SIZE
value|0x00000400UL
end_define

begin_comment
comment|/*  * USB EHCI Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_USB_EHCI_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_USB_EHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_EHCI_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_USB_EHCI_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_USB_EHCI_SIZE
value|0x0000400UL
end_define

begin_comment
comment|/*  * SDMA Offset  *  PA 0x4805 6000  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SDMA_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_SDMA_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDMA_VBASE
value|(OMAP44XX_L4_CORE_VBASE  + OMAP44XX_SDMA_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SDMA_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * Interrupt Controller Unit.  *  *    Refer to the omap4_intr.c file for interrupt controller (GIC)  *    implementation.  *  *    Note:  *    - 16 Interprocessor interrupts (IPI): ID[15:0]  *    - 2 private Timer/Watchdog interrupts: ID[30:29]  *    - 2 legacy nFIQ& nIRQ: one per CPU, bypasses the interrupt distributor  *      logic and directly drives interrupt requests into CPU if used in  *      legacy mode (else treated like other interrupts lines with ID28  *      and ID31 respectively)  *    - 128 hardware interrupts: ID[159:32] (rising-edge or high-level sensitive).  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_HARDIRQ
parameter_list|(
name|x
parameter_list|)
value|(32 + (x))
end_define

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_L2CACHE
value|OMAP44XX_HARDIRQ(0)
end_define

begin_comment
comment|/* L2 cache controller interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_CTI_0
value|OMAP44XX_HARDIRQ(1)
end_define

begin_comment
comment|/* Cross-trigger module 0 (CTI0) interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_CTI_1
value|OMAP44XX_HARDIRQ(2)
end_define

begin_comment
comment|/* Cross-trigger module 1 (CTI1) interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED3
value|OMAP44XX_HARDIRQ(3)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_ELM
value|OMAP44XX_HARDIRQ(4)
end_define

begin_comment
comment|/* Error location process completion */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED5
value|OMAP44XX_HARDIRQ(5)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED6
value|OMAP44XX_HARDIRQ(6)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SYS_NIRQ
value|OMAP44XX_HARDIRQ(7)
end_define

begin_comment
comment|/* External source (active low) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED8
value|OMAP44XX_HARDIRQ(8)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_L3_DBG
value|OMAP44XX_HARDIRQ(9)
end_define

begin_comment
comment|/* L3 interconnect debug error */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_L3_APP
value|OMAP44XX_HARDIRQ(10)
end_define

begin_comment
comment|/* L3 interconnect application error */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_PRCM_MPU
value|OMAP44XX_HARDIRQ(11)
end_define

begin_comment
comment|/* PRCM module IRQ */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SDMA0
value|OMAP44XX_HARDIRQ(12)
end_define

begin_comment
comment|/* System DMA request 0(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SDMA1
value|OMAP44XX_HARDIRQ(13)
end_define

begin_comment
comment|/* System DMA request 1(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SDMA2
value|OMAP44XX_HARDIRQ(14)
end_define

begin_comment
comment|/* System DMA request 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SDMA3
value|OMAP44XX_HARDIRQ(15)
end_define

begin_comment
comment|/* System DMA request 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCBSP4
value|OMAP44XX_HARDIRQ(16)
end_define

begin_comment
comment|/* McBSP module 4 IRQ */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCBSP1
value|OMAP44XX_HARDIRQ(17)
end_define

begin_comment
comment|/* McBSP module 1 IRQ */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SR1
value|OMAP44XX_HARDIRQ(18)
end_define

begin_comment
comment|/* SmartReflexâ¢ 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SR2
value|OMAP44XX_HARDIRQ(19)
end_define

begin_comment
comment|/* SmartReflexâ¢ 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPMC
value|OMAP44XX_HARDIRQ(20)
end_define

begin_comment
comment|/* General-purpose memory controller module */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SGX
value|OMAP44XX_HARDIRQ(21)
end_define

begin_comment
comment|/* 2D/3D graphics module */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCBSP2
value|OMAP44XX_HARDIRQ(22)
end_define

begin_comment
comment|/* McBSP module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCBSP3
value|OMAP44XX_HARDIRQ(23)
end_define

begin_comment
comment|/* McBSP module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_ISS5
value|OMAP44XX_HARDIRQ(24)
end_define

begin_comment
comment|/* Imaging subsystem interrupt 5 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DSS
value|OMAP44XX_HARDIRQ(25)
end_define

begin_comment
comment|/* Display subsystem module(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MAIL_U0
value|OMAP44XX_HARDIRQ(26)
end_define

begin_comment
comment|/* Mailbox user 0 request */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_C2C_SSCM
value|OMAP44XX_HARDIRQ(27)
end_define

begin_comment
comment|/* C2C status interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DSP_MMU
value|OMAP44XX_HARDIRQ(28)
end_define

begin_comment
comment|/* DSP MMU */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO1_MPU
value|OMAP44XX_HARDIRQ(29)
end_define

begin_comment
comment|/* GPIO module 1(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO2_MPU
value|OMAP44XX_HARDIRQ(30)
end_define

begin_comment
comment|/* GPIO module 2(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO3_MPU
value|OMAP44XX_HARDIRQ(31)
end_define

begin_comment
comment|/* GPIO module 3(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO4_MPU
value|OMAP44XX_HARDIRQ(32)
end_define

begin_comment
comment|/* GPIO module 4(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO5_MPU
value|OMAP44XX_HARDIRQ(33)
end_define

begin_comment
comment|/* GPIO module 5(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPIO6_MPU
value|OMAP44XX_HARDIRQ(34)
end_define

begin_comment
comment|/* GPIO module 6(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED35
value|OMAP44XX_HARDIRQ(35)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_WDT3
value|OMAP44XX_HARDIRQ(36)
end_define

begin_comment
comment|/* Watchdog timer module 3 overflow */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT1
value|OMAP44XX_HARDIRQ(37)
end_define

begin_comment
comment|/* General-purpose timer module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT2
value|OMAP44XX_HARDIRQ(38)
end_define

begin_comment
comment|/* General-purpose timer module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT3
value|OMAP44XX_HARDIRQ(39)
end_define

begin_comment
comment|/* General-purpose timer module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT4
value|OMAP44XX_HARDIRQ(40)
end_define

begin_comment
comment|/* General-purpose timer module 4 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT5
value|OMAP44XX_HARDIRQ(41)
end_define

begin_comment
comment|/* General-purpose timer module 5 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT6
value|OMAP44XX_HARDIRQ(42)
end_define

begin_comment
comment|/* General-purpose timer module 6 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT7
value|OMAP44XX_HARDIRQ(43)
end_define

begin_comment
comment|/* General-purpose timer module 7 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT8
value|OMAP44XX_HARDIRQ(44)
end_define

begin_comment
comment|/* General-purpose timer module 8 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT9
value|OMAP44XX_HARDIRQ(45)
end_define

begin_comment
comment|/* General-purpose timer module 9 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT10
value|OMAP44XX_HARDIRQ(46)
end_define

begin_comment
comment|/* General-purpose timer module 10 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_GPT11
value|OMAP44XX_HARDIRQ(47)
end_define

begin_comment
comment|/* General-purpose timer module 11 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCSPI4
value|OMAP44XX_HARDIRQ(48)
end_define

begin_comment
comment|/* McSPI module 4 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED49
value|OMAP44XX_HARDIRQ(49)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED50
value|OMAP44XX_HARDIRQ(50)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED51
value|OMAP44XX_HARDIRQ(51)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED52
value|OMAP44XX_HARDIRQ(52)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DSS_DSI1
value|OMAP44XX_HARDIRQ(53)
end_define

begin_comment
comment|/* Display Subsystem DSI1 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED54
value|OMAP44XX_HARDIRQ(54)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED55
value|OMAP44XX_HARDIRQ(55)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_I2C1
value|OMAP44XX_HARDIRQ(56)
end_define

begin_comment
comment|/* I2C module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_I2C2
value|OMAP44XX_HARDIRQ(57)
end_define

begin_comment
comment|/* I2C module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HDQ
value|OMAP44XX_HARDIRQ(58)
end_define

begin_comment
comment|/* HDQ / One-wire */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MMC5
value|OMAP44XX_HARDIRQ(59)
end_define

begin_comment
comment|/* MMC5 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED60
value|OMAP44XX_HARDIRQ(60)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_I2C3
value|OMAP44XX_HARDIRQ(61)
end_define

begin_comment
comment|/* I2C module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_I2C4
value|OMAP44XX_HARDIRQ(62)
end_define

begin_comment
comment|/* I2C module 4 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED63
value|OMAP44XX_HARDIRQ(63)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED64
value|OMAP44XX_HARDIRQ(64)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCSPI1
value|OMAP44XX_HARDIRQ(65)
end_define

begin_comment
comment|/* McSPI module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCSPI2
value|OMAP44XX_HARDIRQ(66)
end_define

begin_comment
comment|/* McSPI module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HSI_P1
value|OMAP44XX_HARDIRQ(67)
end_define

begin_comment
comment|/* HSI Port 1 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HSI_P2
value|OMAP44XX_HARDIRQ(68)
end_define

begin_comment
comment|/* HSI Port 2 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_FDIF_3
value|OMAP44XX_HARDIRQ(69)
end_define

begin_comment
comment|/* Face detect interrupt 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_UART4
value|OMAP44XX_HARDIRQ(70)
end_define

begin_comment
comment|/* UART module 4 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HSI_DMA
value|OMAP44XX_HARDIRQ(71)
end_define

begin_comment
comment|/* HSI DMA engine MPU request */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_UART1
value|OMAP44XX_HARDIRQ(72)
end_define

begin_comment
comment|/* UART module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_UART2
value|OMAP44XX_HARDIRQ(73)
end_define

begin_comment
comment|/* UART module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_UART3
value|OMAP44XX_HARDIRQ(74)
end_define

begin_comment
comment|/* UART module 3 (also infrared)(3) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_PBIAS
value|OMAP44XX_HARDIRQ(75)
end_define

begin_comment
comment|/* Merged interrupt for PBIASlite1 and 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_OHCI
value|OMAP44XX_HARDIRQ(76)
end_define

begin_comment
comment|/* OHCI controller HSUSB MP Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_EHCI
value|OMAP44XX_HARDIRQ(77)
end_define

begin_comment
comment|/* EHCI controller HSUSB MP Host Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_TLL
value|OMAP44XX_HARDIRQ(78)
end_define

begin_comment
comment|/* HSUSB MP TLL Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED79
value|OMAP44XX_HARDIRQ(79)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_WDT2
value|OMAP44XX_HARDIRQ(80)
end_define

begin_comment
comment|/* WDTIMER2 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED81
value|OMAP44XX_HARDIRQ(81)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED82
value|OMAP44XX_HARDIRQ(82)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MMC1
value|OMAP44XX_HARDIRQ(83)
end_define

begin_comment
comment|/* MMC/SD module 1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DSS_DSI2
value|OMAP44XX_HARDIRQ(84)
end_define

begin_comment
comment|/* Display subsystem DSI2 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED85
value|OMAP44XX_HARDIRQ(85)
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MMC2
value|OMAP44XX_HARDIRQ(86)
end_define

begin_comment
comment|/* MMC/SD module 2 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MPU_ICR
value|OMAP44XX_HARDIRQ(87)
end_define

begin_comment
comment|/* MPU ICR */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_C2C_GPI
value|OMAP44XX_HARDIRQ(88)
end_define

begin_comment
comment|/* C2C GPI interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_FSUSB
value|OMAP44XX_HARDIRQ(89)
end_define

begin_comment
comment|/* FS-USB - host controller Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_FSUSB_SMI
value|OMAP44XX_HARDIRQ(90)
end_define

begin_comment
comment|/* FS-USB - host controller SMI Interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCSPI3
value|OMAP44XX_HARDIRQ(91)
end_define

begin_comment
comment|/* McSPI module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HSUSB_OTG
value|OMAP44XX_HARDIRQ(92)
end_define

begin_comment
comment|/* High-Speed USB OTG controller */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_HSUSB_OTG_DMA
value|OMAP44XX_HARDIRQ(93)
end_define

begin_comment
comment|/* High-Speed USB OTG DMA controller */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MMC3
value|OMAP44XX_HARDIRQ(94)
end_define

begin_comment
comment|/* MMC/SD module 3 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED95
value|OMAP44XX_HARDIRQ(95)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MMC4
value|OMAP44XX_HARDIRQ(96)
end_define

begin_comment
comment|/* MMC4 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SLIMBUS1
value|OMAP44XX_HARDIRQ(97)
end_define

begin_comment
comment|/* SLIMBUS1 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SLIMBUS2
value|OMAP44XX_HARDIRQ(98)
end_define

begin_comment
comment|/* SLIMBUS2 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_ABE
value|OMAP44XX_HARDIRQ(99)
end_define

begin_comment
comment|/* Audio back-end interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_CORTEXM3_MMU
value|OMAP44XX_HARDIRQ(100)
end_define

begin_comment
comment|/* Cortex-M3 MMU interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DSS_HDMI
value|OMAP44XX_HARDIRQ(101)
end_define

begin_comment
comment|/* Display subsystem HDMI interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SR_IVA
value|OMAP44XX_HARDIRQ(102)
end_define

begin_comment
comment|/* SmartReflex IVA interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_IVAHD1
value|OMAP44XX_HARDIRQ(103)
end_define

begin_comment
comment|/* Sync interrupt from iCONT2 (vDMA) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_IVAHD2
value|OMAP44XX_HARDIRQ(104)
end_define

begin_comment
comment|/* Sync interrupt from iCONT1 */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED105
value|OMAP44XX_HARDIRQ(105)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED106
value|OMAP44XX_HARDIRQ(106)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_IVAHD_MAILBOX0
value|OMAP44XX_HARDIRQ(107)
end_define

begin_comment
comment|/* IVAHD mailbox interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED108
value|OMAP44XX_HARDIRQ(108)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCASP1
value|OMAP44XX_HARDIRQ(109)
end_define

begin_comment
comment|/* McASP1 transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_EMIF1
value|OMAP44XX_HARDIRQ(110)
end_define

begin_comment
comment|/* EMIF1 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_EMIF2
value|OMAP44XX_HARDIRQ(111)
end_define

begin_comment
comment|/* EMIF2 interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_MCPDM
value|OMAP44XX_HARDIRQ(112)
end_define

begin_comment
comment|/* MCPDM interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DMM
value|OMAP44XX_HARDIRQ(113)
end_define

begin_comment
comment|/* DMM interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_DMIC
value|OMAP44XX_HARDIRQ(114)
end_define

begin_comment
comment|/* DMIC interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED115
value|OMAP44XX_HARDIRQ(115)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED116
value|OMAP44XX_HARDIRQ(116)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED117
value|OMAP44XX_HARDIRQ(117)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED118
value|OMAP44XX_HARDIRQ(118)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_SYS_NIRQ2
value|OMAP44XX_HARDIRQ(119)
end_define

begin_comment
comment|/* External source 2 (active low) */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_KBD
value|OMAP44XX_HARDIRQ(120)
end_define

begin_comment
comment|/* Keyboard controller interrupt */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED121
value|OMAP44XX_HARDIRQ(121)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED122
value|OMAP44XX_HARDIRQ(122)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED123
value|OMAP44XX_HARDIRQ(123)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED124
value|OMAP44XX_HARDIRQ(124)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED125
value|OMAP44XX_HARDIRQ(125)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED126
value|OMAP44XX_HARDIRQ(126)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_IRQ_RESERVED127
value|OMAP44XX_HARDIRQ(127)
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_comment
comment|/*  * General Purpose Timers  */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER1_VBASE
value|(OMAP44XX_L4_WAKEUP_VBASE + OMAP44XX_GPTIMER1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER1_HWBASE
value|(OMAP44XX_L4_WAKEUP_HWBASE + OMAP44XX_GPTIMER1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER2_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER2_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER3_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER3_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER4_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER4_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER5_VBASE
value|(OMAP44XX_L4_ABE_VBASE + OMAP44XX_GPTIMER5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER5_HWBASE
value|(OMAP44XX_L4_ABE_HWBASE + OMAP44XX_GPTIMER5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER6_VBASE
value|(OMAP44XX_L4_ABE_VBASE + OMAP44XX_GPTIMER6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER6_HWBASE
value|(OMAP44XX_L4_ABE_HWBASE + OMAP44XX_GPTIMER6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER7_VBASE
value|(OMAP44XX_L4_ABE_VBASE + OMAP44XX_GPTIMER7_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER7_HWBASE
value|(OMAP44XX_L4_ABE_HWBASE + OMAP44XX_GPTIMER7_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER8_VBASE
value|(OMAP44XX_L4_ABE_VBASE + OMAP44XX_GPTIMER8_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER8_HWBASE
value|(OMAP44XX_L4_ABE_HWBASE + OMAP44XX_GPTIMER8_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER9_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER9_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER9_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER9_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER10_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER10_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER10_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER10_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER11_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_GPTIMER11_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER11_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPTIMER11_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPTIMER_SIZE
value|0x00001000UL
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
name|OMAP44XX_GPIO1_HWBASE
value|(OMAP44XX_L4_WAKEUP_HWBASE + OMAP44XX_GPIO1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO1_VBASE
value|(OMAP44XX_L4_WAKEUP_VBASE  + OMAP44XX_GPIO1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO1_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO2_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPIO2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO2_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_GPIO2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO2_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO3_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPIO3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO3_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_GPIO3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO3_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO4_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPIO4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO4_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_GPIO4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO4_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO5_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPIO5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO5_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_GPIO5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO5_SIZE
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO6_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_GPIO6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO6_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE  + OMAP44XX_GPIO6_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_GPIO6_SIZE
value|0x00001000UL
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
name|OMAP44XX_MMCHS1_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MMCHS1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS1_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_MMCHS1_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS2_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MMCHS2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS2_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_MMCHS2_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS3_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MMCSD3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS3_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_MMCSD3_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS4_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MMCSD4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS4_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_MMCSD4_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS5_HWBASE
value|(OMAP44XX_L4_PERIPH_HWBASE + OMAP44XX_MMCSD5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS5_VBASE
value|(OMAP44XX_L4_PERIPH_VBASE + OMAP44XX_MMCSD5_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_MMCHS_SIZE
value|0x00001000UL
end_define

begin_comment
comment|/*  * SCM - System Control Module  */
end_comment

begin_comment
comment|/* Base addresses for the SC modules */
end_comment

begin_define
define|#
directive|define
name|OMAP44XX_SCM_PADCONF_HWBASE
value|(OMAP44XX_L4_CORE_HWBASE + OMAP44XX_SCM_PADCONF_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCM_PADCONF_VBASE
value|(OMAP44XX_L4_CORE_VBASE + OMAP44XX_SCM_PADCONF_OFFSET)
end_define

begin_define
define|#
directive|define
name|OMAP44XX_SCM_PADCONF_SIZE
value|0x00001000UL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OMAP44XX_REG_H_ */
end_comment

end_unit

