begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2006 by Juniper Networks. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_OCP85XX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_OCP85XX_H_
end_define

begin_comment
comment|/*  * Local access registers.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_LAWBAR
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc08 + 0x20 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_LAWSR
parameter_list|(
name|n
parameter_list|)
value|(CCSRBAR_VA + 0xc10 + 0x20 * (n))
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_PCI0
value|0
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_PCI1
value|1
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_PCI2
value|2
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_LBC
value|4
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM_INTL
value|11
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RIO
value|12
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM1
value|15
end_define

begin_define
define|#
directive|define
name|OCP85XX_TGTIF_RAM2
value|22
end_define

begin_comment
comment|/*  * Power-On Reset configuration.  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR
value|(CCSRBAR_VA + 0xe000c)
end_define

begin_define
define|#
directive|define
name|OCP85XX_PORDEVSR2
value|(CCSRBAR_VA + 0xe0014)
end_define

begin_comment
comment|/*  * OCP Bus Definitions  */
end_comment

begin_define
define|#
directive|define
name|OCP85XX_I2C0_OFF
value|0x03000
end_define

begin_define
define|#
directive|define
name|OCP85XX_I2C1_OFF
value|0x03100
end_define

begin_define
define|#
directive|define
name|OCP85XX_I2C_SIZE
value|0x15
end_define

begin_define
define|#
directive|define
name|OCP85XX_UART0_OFF
value|0x04500
end_define

begin_define
define|#
directive|define
name|OCP85XX_UART1_OFF
value|0x04600
end_define

begin_define
define|#
directive|define
name|OCP85XX_UART_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|OCP85XX_LBC_OFF
value|0x05000
end_define

begin_define
define|#
directive|define
name|OCP85XX_LBC_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PCI0_OFF
value|0x08000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PCI1_OFF
value|0x09000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PCI2_OFF
value|0x0A000
end_define

begin_define
define|#
directive|define
name|OCP85XX_PCI_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|OCP85XX_TSEC0_OFF
value|0x24000
end_define

begin_define
define|#
directive|define
name|OCP85XX_TSEC1_OFF
value|0x25000
end_define

begin_define
define|#
directive|define
name|OCP85XX_TSEC2_OFF
value|0x26000
end_define

begin_define
define|#
directive|define
name|OCP85XX_TSEC3_OFF
value|0x27000
end_define

begin_define
define|#
directive|define
name|OCP85XX_TSEC_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|OCP85XX_OPENPIC_OFF
value|0x40000
end_define

begin_define
define|#
directive|define
name|OCP85XX_OPENPIC_SIZE
value|0x200B4
end_define

begin_define
define|#
directive|define
name|OCP85XX_QUICC_OFF
value|0x80000
end_define

begin_define
define|#
directive|define
name|OCP85XX_QUICC_SIZE
value|0x20000
end_define

begin_comment
comment|/*  * PIC definitions  */
end_comment

begin_define
define|#
directive|define
name|ISA_IRQ_START
value|0
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_START
value|(ISA_IRQ_START + 16)
end_define

begin_define
define|#
directive|define
name|ISA_IRQ
parameter_list|(
name|n
parameter_list|)
value|(ISA_IRQ_START + (n))
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_EXT
parameter_list|(
name|n
parameter_list|)
value|(PIC_IRQ_START + (n))
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_INT
parameter_list|(
name|n
parameter_list|)
value|(PIC_IRQ_START + 16 + (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_OCP85XX_H */
end_comment

end_unit

