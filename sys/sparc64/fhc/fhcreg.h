begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2004 Jason L. Wright (jason@thought.net).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: OpenBSD: fhcreg.h,v 1.3 2004/09/28 16:26:03 jason Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_FHC_FHCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_FHC_FHCREG_H_
end_define

begin_define
define|#
directive|define
name|FHC_NREG
value|(6)
end_define

begin_define
define|#
directive|define
name|FHC_INTERNAL
value|(0)
end_define

begin_define
define|#
directive|define
name|FHC_IGN
value|(1)
end_define

begin_define
define|#
directive|define
name|FHC_FANFAIL
value|(2)
end_define

begin_define
define|#
directive|define
name|FHC_SYSTEM
value|(3)
end_define

begin_define
define|#
directive|define
name|FHC_UART
value|(4)
end_define

begin_define
define|#
directive|define
name|FHC_TOD
value|(5)
end_define

begin_define
define|#
directive|define
name|FHC_IMAP
value|0x0
end_define

begin_define
define|#
directive|define
name|FHC_ICLR
value|0x10
end_define

begin_define
define|#
directive|define
name|FHC_ID
value|0x00000000
end_define

begin_comment
comment|/* ID */
end_comment

begin_define
define|#
directive|define
name|FHC_RCS
value|0x00000010
end_define

begin_comment
comment|/* reset ctrl/status */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL
value|0x00000020
end_define

begin_comment
comment|/* control */
end_comment

begin_define
define|#
directive|define
name|FHC_BSR
value|0x00000030
end_define

begin_comment
comment|/* board status */
end_comment

begin_define
define|#
directive|define
name|FHC_ECC
value|0x00000040
end_define

begin_comment
comment|/* ECC control */
end_comment

begin_define
define|#
directive|define
name|FHC_JCTRL
value|0x000000f0
end_define

begin_comment
comment|/* JTAG control */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_ICS
value|0x00100000
end_define

begin_comment
comment|/* ignore centerplane sigs */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_FRST
value|0x00080000
end_define

begin_comment
comment|/* fatal error reset enable */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_LFAT
value|0x00040000
end_define

begin_comment
comment|/* AC/DC local error */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_SLINE
value|0x00010000
end_define

begin_comment
comment|/* firmware sync line */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_DCD
value|0x00008000
end_define

begin_comment
comment|/* DC/DC converter disable */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_POFF
value|0x00004000
end_define

begin_comment
comment|/* AC/DC ctlr PLL disable */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_FOFF
value|0x00002000
end_define

begin_comment
comment|/* FHC ctlr PLL disable */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_AOFF
value|0x00001000
end_define

begin_comment
comment|/* cpu a sram low pwr mode */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_BOFF
value|0x00000800
end_define

begin_comment
comment|/* cpu b sram low pwr mode */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_PSOFF
value|0x00000400
end_define

begin_comment
comment|/* disable fhc power supply */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_IXIST
value|0x00000200
end_define

begin_comment
comment|/* fhc notifies clock-board */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_XMSTR
value|0x00000100
end_define

begin_comment
comment|/* xir master enable */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_LLED
value|0x00000040
end_define

begin_comment
comment|/* left led (reversed) */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_MLED
value|0x00000020
end_define

begin_comment
comment|/* middle led */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_RLED
value|0x00000010
end_define

begin_comment
comment|/* right led */
end_comment

begin_define
define|#
directive|define
name|FHC_CTRL_BPINS
value|0x00000003
end_define

begin_comment
comment|/* spare bidir pins */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_FHC_FHCREG_H_ */
end_comment

end_unit

