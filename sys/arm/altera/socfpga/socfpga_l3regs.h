begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|L3REGS_REMAP
value|0x0
end_define

begin_comment
comment|/* Remap */
end_comment

begin_define
define|#
directive|define
name|REMAP_LWHPS2FPGA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|REMAP_HPS2FPGA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|REMAP_MPUZERO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|L3REGS_L4MAIN
value|0x8
end_define

begin_comment
comment|/* L4 main peripherals security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_L4SP
value|0xC
end_define

begin_comment
comment|/* L4 SP Peripherals Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_L4MP
value|0x10
end_define

begin_comment
comment|/* L4 MP Peripherals Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_L4OSC1
value|0x14
end_define

begin_comment
comment|/* L4 OSC1 Peripherals Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_L4SPIM
value|0x18
end_define

begin_comment
comment|/* L4 SPIM Peripherals Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_STM
value|0x1C
end_define

begin_comment
comment|/* STM Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_LWHPS2FPGAREGS
value|0x20
end_define

begin_comment
comment|/* LWHPS2FPGA AXI Bridge Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_USB1
value|0x28
end_define

begin_comment
comment|/* USB1 Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_NANDDATA
value|0x2C
end_define

begin_comment
comment|/* NAND Flash Controller Data Sec */
end_comment

begin_define
define|#
directive|define
name|L3REGS_USB0
value|0x80
end_define

begin_comment
comment|/* USB0 Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_NANDREGS
value|0x84
end_define

begin_comment
comment|/* NAND Flash Controller Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_QSPIDATA
value|0x88
end_define

begin_comment
comment|/* QSPI Flash Controller Data Sec */
end_comment

begin_define
define|#
directive|define
name|L3REGS_FPGAMGRDATA
value|0x8C
end_define

begin_comment
comment|/* FPGA Manager Data Peripheral Sec */
end_comment

begin_define
define|#
directive|define
name|L3REGS_HPS2FPGAREGS
value|0x90
end_define

begin_comment
comment|/* HPS2FPGA AXI Bridge Perip. Sec */
end_comment

begin_define
define|#
directive|define
name|L3REGS_ACP
value|0x94
end_define

begin_comment
comment|/* MPU ACP Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_ROM
value|0x98
end_define

begin_comment
comment|/* ROM Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_OCRAM
value|0x9C
end_define

begin_comment
comment|/* On-chip RAM Peripheral Security */
end_comment

begin_define
define|#
directive|define
name|L3REGS_SDRDATA
value|0xA0
end_define

begin_comment
comment|/* SDRAM Data Peripheral Security */
end_comment

end_unit

