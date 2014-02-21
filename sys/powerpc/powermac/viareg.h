begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_VIAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_VIAREG_H_
end_define

begin_comment
comment|/* VIA interface registers */
end_comment

begin_define
define|#
directive|define
name|vBufB
value|0x0000
end_define

begin_comment
comment|/* register B */
end_comment

begin_define
define|#
directive|define
name|vDirB
value|0x0400
end_define

begin_comment
comment|/* data direction register */
end_comment

begin_define
define|#
directive|define
name|vDirA
value|0x0600
end_define

begin_comment
comment|/* data direction register */
end_comment

begin_define
define|#
directive|define
name|vT1C
value|0x0800
end_define

begin_comment
comment|/* Timer 1 counter Lo */
end_comment

begin_define
define|#
directive|define
name|vT1CH
value|0x0a00
end_define

begin_comment
comment|/* Timer 1 counter Hi */
end_comment

begin_define
define|#
directive|define
name|vSR
value|0x1400
end_define

begin_comment
comment|/* shift register */
end_comment

begin_define
define|#
directive|define
name|vACR
value|0x1600
end_define

begin_comment
comment|/* aux control register */
end_comment

begin_define
define|#
directive|define
name|vPCR
value|0x1800
end_define

begin_comment
comment|/* peripheral control register */
end_comment

begin_define
define|#
directive|define
name|vIFR
value|0x1a00
end_define

begin_comment
comment|/* interrupt flag register */
end_comment

begin_define
define|#
directive|define
name|vIER
value|0x1c00
end_define

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|vBufA
value|0x1e00
end_define

begin_comment
comment|/* register A */
end_comment

begin_define
define|#
directive|define
name|vPB
value|0x0000
end_define

begin_define
define|#
directive|define
name|vPB3
value|0x08
end_define

begin_define
define|#
directive|define
name|vPB4
value|0x10
end_define

begin_define
define|#
directive|define
name|vPB5
value|0x20
end_define

begin_define
define|#
directive|define
name|vSR_INT
value|0x04
end_define

begin_define
define|#
directive|define
name|vSR_OUT
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_VIAREG_H_ */
end_comment

end_unit

