begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Ted Faber  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Ted Faber.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: pcic_p.h,v 1.3 1998/01/20 21:11:03 nate Exp $  */
end_comment

begin_comment
comment|/* PCI/CardBus Device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6729
value|0x11001013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_CLPD6832
value|0x11101013ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_O2MICRO
value|0x673A1217ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1130
value|0xAC12104Cul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_PCIC_TI1131
value|0xAC15104Cul
end_define

begin_comment
comment|/* CL-PD6832 CardBus defines */
end_comment

begin_define
define|#
directive|define
name|CLPD6832_IO_BASE0
value|0x002c
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_LIMIT0
value|0x0030
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_BASE1
value|0x0034
end_define

begin_define
define|#
directive|define
name|CLPD6832_IO_LIMIT1
value|0x0038
end_define

begin_define
define|#
directive|define
name|CLPD6832_BRIDGE_CONTROL
value|0x003c
end_define

begin_define
define|#
directive|define
name|CLPD6832_LEGACY_16BIT_IOADDR
value|0x0044
end_define

begin_define
define|#
directive|define
name|CLPD6832_SOCKET
value|0x004c
end_define

begin_comment
comment|/* Configuration constants */
end_comment

begin_define
define|#
directive|define
name|CLPD6832_BCR_MGMT_IRQ_ENA
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CLPD6832_BCR_ISA_IRQ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CLPD6832_COMMAND_DEFAULTS
value|0x00000045
end_define

begin_define
define|#
directive|define
name|CLPD6832_NUM_REGS
value|2
end_define

begin_comment
comment|/* End of CL-PD6832 defines */
end_comment

end_unit

