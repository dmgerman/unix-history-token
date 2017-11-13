begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MARVELL_PXA1928_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MARVELL_PXA1928_CLOCK_H
end_define

begin_comment
comment|/*  * Clock ID values here correspond to the control register offset/4.  */
end_comment

begin_comment
comment|/* apb peripherals */
end_comment

begin_define
define|#
directive|define
name|PXA1928_CLK_RTC
value|0x00
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI0
value|0x01
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI1
value|0x02
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI2
value|0x03
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI3
value|0x04
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_OWIRE
value|0x05
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_KPC
value|0x06
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TB_ROTARY
value|0x07
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SW_JTAG
value|0x08
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TIMER1
value|0x09
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_UART0
value|0x0b
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_UART1
value|0x0c
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_UART2
value|0x0d
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_GPIO
value|0x0e
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_PWM0
value|0x0f
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_PWM1
value|0x10
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_PWM2
value|0x11
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_PWM3
value|0x12
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SSP0
value|0x13
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SSP1
value|0x14
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SSP2
value|0x15
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI4
value|0x1f
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_TWSI5
value|0x20
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_UART3
value|0x22
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_THSENS_GLOB
value|0x24
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_THSENS_CPU
value|0x26
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_THSENS_VPU
value|0x27
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_THSENS_GC
value|0x28
end_define

begin_define
define|#
directive|define
name|PXA1928_APBC_NR_CLKS
value|0x30
end_define

begin_comment
comment|/* axi peripherals */
end_comment

begin_define
define|#
directive|define
name|PXA1928_CLK_SDH0
value|0x15
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SDH1
value|0x16
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_USB
value|0x17
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_NAND
value|0x18
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_DMA
value|0x19
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SDH2
value|0x3a
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SDH3
value|0x3b
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_HSIC
value|0x3e
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_SDH4
value|0x57
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_GC3D
value|0x5d
end_define

begin_define
define|#
directive|define
name|PXA1928_CLK_GC2D
value|0x5f
end_define

begin_define
define|#
directive|define
name|PXA1928_APMU_NR_CLKS
value|0x60
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

