begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_DIGI
value|0x114F
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_EPC
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_RIGHTSWITCH
value|0x0003
end_define

begin_comment
comment|/* For testing */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_XEM
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_XR
value|0x0005
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_CX
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_XRJ
value|0x0009
end_define

begin_comment
comment|/* Jupiter boards with */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_EPCJ
value|0x000a
end_define

begin_comment
comment|/* PLX 9060 chip for PCI  */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_XR_422
value|0x0012
end_define

begin_comment
comment|/* Xr-422 */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_920_4
value|0x0026
end_define

begin_comment
comment|/* XR-Plus 920 K, 4 port */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_920_8
value|0x0027
end_define

begin_comment
comment|/* XR-Plus 920 K, 8 port */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_920_2
value|0x0034
end_define

begin_comment
comment|/* XR-Plus 920 K, 2 port */
end_comment

begin_define
define|#
directive|define
name|PCIPORT
value|sc->vmem[0x200000]
end_define

end_unit

