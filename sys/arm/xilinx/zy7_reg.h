begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2013 Thomas Skibo  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Address regions of Zynq-7000.    * Reference: Zynq-7000 All Programmable SoC Technical Reference Manual.  * (v1.4) November 16, 2012.  Xilinx doc UG585.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZY7_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZY7_REG_H_
end_define

begin_comment
comment|/* PL AXI buses:  General Purpose Port #0, M_AXI_GP0. */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_PLGP0_HWBASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_PLGP0_SIZE
value|0x40000000
end_define

begin_comment
comment|/* PL AXI buses:  General Purpose Port #1, M_AXI_GP1. */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_PLGP1_HWBASE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_PLGP1_SIZE
value|0x40000000
end_define

begin_comment
comment|/* I/O Peripheral registers. */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_PSIO_HWBASE
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_PSIO_SIZE
value|0x00300000
end_define

begin_comment
comment|/* UART0 and UART1 */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_UART0_HWBASE
value|(ZYNQ7_PSIO_HWBASE)
end_define

begin_define
define|#
directive|define
name|ZYNQ7_UART0_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_UART1_HWBASE
value|(ZYNQ7_PSIO_HWBASE+0x1000)
end_define

begin_define
define|#
directive|define
name|ZYNQ7_UART1_SIZE
value|0x1000
end_define

begin_comment
comment|/* SMC Memories not mapped for now. */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_SMC_HWBASE
value|0xE1000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_SMC_SIZE
value|0x05000000
end_define

begin_comment
comment|/* SLCR, PS system, and CPU private registers combined in this region. */
end_comment

begin_define
define|#
directive|define
name|ZYNQ7_PSCTL_HWBASE
value|0xF8000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_PSCTL_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_SLCR_HWBASE
value|(ZYNQ7_PSCTL_HWBASE)
end_define

begin_define
define|#
directive|define
name|ZYNQ7_SLCR_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|ZYNQ7_DEVCFG_HWBASE
value|(ZYNQ7_PSCTL_HWBASE+0x7000)
end_define

begin_define
define|#
directive|define
name|ZYNQ7_DEVCFG_SIZE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ZY7_REG_H_ */
end_comment

end_unit

