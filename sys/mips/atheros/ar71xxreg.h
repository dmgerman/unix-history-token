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

begin_define
define|#
directive|define
name|AR71XX_UART_ADDR
value|0x18020000
end_define

begin_comment
comment|/* APB registers */
end_comment

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
name|AR71XX_RST_RESET
value|0x18060024
end_define

begin_define
define|#
directive|define
name|RST_RESET_CPU_COLD_RESET
value|(1<< 20)
end_define

begin_comment
comment|/* Cold reset */
end_comment

begin_define
define|#
directive|define
name|RST_RESET_FULL_CHIP_RESET
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

