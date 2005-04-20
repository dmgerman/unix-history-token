begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|FHC_CTRL
value|(0x20)
end_define

begin_define
define|#
directive|define
name|FHC_CTRL_SLINE
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|FHC_CTRL_AOFF
value|(0x00001000)
end_define

begin_define
define|#
directive|define
name|FHC_CTRL_BOFF
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|FHC_CTRL_IXIST
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|FHC_BSR
value|(0x30)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

