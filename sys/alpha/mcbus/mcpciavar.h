begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, 2000 by Matthew Jacob  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * There are four PCI slots per MCPCIA PCI bus here, but some are 'hidden'-  * none seems to be higher than 6 though.  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_MAXDEV
value|6
end_define

begin_define
define|#
directive|define
name|MCPCIA_MAXSLOT
value|8
end_define

begin_comment
comment|/*  * Interrupt Stuff for MCPCIA systems.  *  * EISA interrupts (at vector 0x800) have to be shared interrupts-  * and that can be easily managed. All the PCI interrupts are deterministic  * in that they start at vector 0x900, 0x40 per PCI slot, 0x200 per  * MCPCIA, 4 MCPCIAs per GCBUS....  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_EISA_KEYB_IRQ
value|1
end_define

begin_define
define|#
directive|define
name|MCPCIA_EISA_MOUSE_IRQ
value|12
end_define

begin_define
define|#
directive|define
name|MCPCIA_VEC_EISA
value|0x800
end_define

begin_define
define|#
directive|define
name|MCPCIA_EISA_IRQ
value|16
end_define

begin_define
define|#
directive|define
name|MCPCIA_VEC_PCI
value|0x900
end_define

begin_define
define|#
directive|define
name|MCPCIA_VEC_NCR
value|0xB40
end_define

begin_define
define|#
directive|define
name|MCPCIA_NCR_IRQ
value|16
end_define

begin_define
define|#
directive|define
name|MCPCIA_VECWIDTH_PER_MCPCIA
value|0x200
end_define

begin_define
define|#
directive|define
name|MCPCIA_MID_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|MCPCIA_VECWIDTH_PER_SLOT
value|0x40
end_define

begin_define
define|#
directive|define
name|MCPCIA_SLOT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MCPCIA_VECWIDTH_PER_INTPIN
value|0x10
end_define

begin_define
define|#
directive|define
name|MCPCIA_IRQ_SHIFT
value|4
end_define

begin_comment
comment|/*  * Special Vectors  */
end_comment

begin_define
define|#
directive|define
name|MCPCIA_I2C_CVEC
value|0xA90
end_define

begin_define
define|#
directive|define
name|MCPCIA_I2C_BVEC
value|0xAA0
end_define

begin_function_decl
specifier|extern
name|void
name|mcpcia_init
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

