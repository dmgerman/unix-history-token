begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcmciareg.h,v 1.7 1998/10/29 09:45:52 enami Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Card Configuration Registers  */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_SRESET
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_LEVIREQ
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_CFINDEX
value|0x3F
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_IREQ_ENABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_ADDR_DECODE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_OPTION_FUNC_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_PINCHANGED
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_SIGCHG
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_IOIS8
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_RESERVED1
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_AUDIO
value|0x08
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_PWRDWN
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_INTR
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_STATUS_INTRACK
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_CBVD1
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_CBVD2
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_CRDYBSY
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_CWPROT
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_RBVD1
value|0x08
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_RBVD2
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_RRDYBSY
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_PIN_RWPROT
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SOCKETCOPY
value|0x06
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SOCKETCOPY_RESERVED
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SOCKETCOPY_COPY_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SOCKETCOPY_COPY_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SOCKETCOPY_SOCKET_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_EXTSTATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_IOBASE0
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_IOBASE1
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_IOBASE2
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_IOBASE3
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_IOSIZE
value|0x12
end_define

begin_define
define|#
directive|define
name|PCCARD_CCR_SIZE
value|0x14
end_define

end_unit

