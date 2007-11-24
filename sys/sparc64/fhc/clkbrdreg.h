begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: OpenBSD: clkbrdreg.h,v 1.2 2004/10/01 15:36:30 jason Exp  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|CLK_STS1
value|0x10
end_define

begin_define
define|#
directive|define
name|CLK_STS2
value|0x20
end_define

begin_define
define|#
directive|define
name|CLK_PSTS1
value|0x30
end_define

begin_define
define|#
directive|define
name|CLK_PPRES
value|0x40
end_define

begin_define
define|#
directive|define
name|CLK_TEMP
value|0x50
end_define

begin_define
define|#
directive|define
name|CLK_IRQ
value|0x60
end_define

begin_define
define|#
directive|define
name|CLK_PSTS2
value|0x70
end_define

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_FAN
value|0x80
end_define

begin_comment
comment|/* intr enable: fan failure */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_DC
value|0x40
end_define

begin_comment
comment|/* intr enable: pwr supply DC */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_AC
value|0x20
end_define

begin_comment
comment|/* intr enable: AC pwr supply */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_IEN_BRD
value|0x10
end_define

begin_comment
comment|/* intr enable: board insert */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_POFF
value|0x08
end_define

begin_comment
comment|/* turn off system power */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_LLED
value|0x04
end_define

begin_comment
comment|/* left led (reversed) */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_MLED
value|0x02
end_define

begin_comment
comment|/* middle led */
end_comment

begin_define
define|#
directive|define
name|CLK_CTRL_RLED
value|0x01
end_define

begin_comment
comment|/* right led */
end_comment

end_unit

