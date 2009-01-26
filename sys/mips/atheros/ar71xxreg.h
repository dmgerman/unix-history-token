begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Oleksandr Tymoshenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
name|RST_RESET_PCI_CORE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RST_RESET_PCI_BUS
value|(1<< 1)
end_define

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
name|RST_RESET_FULL_CHIP
value|(1<< 24)
end_define

begin_comment
comment|/* Same as pulling 							     the reset pin */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AR71XX_REG_H_ */
end_comment

end_unit

