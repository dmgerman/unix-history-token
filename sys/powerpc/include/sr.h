begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2002 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SR_H_
end_define

begin_comment
comment|/*  * Bit definitions for segment registers.  *  * PowerPC Microprocessor Family: The Programming Environments for 32-bit  * Microprocessors, section 2.3.5  */
end_comment

begin_define
define|#
directive|define
name|SR_TYPE
value|0x80000000
end_define

begin_comment
comment|/* Type selector */
end_comment

begin_define
define|#
directive|define
name|SR_KS
value|0x40000000
end_define

begin_comment
comment|/* Supervisor-state protection key */
end_comment

begin_define
define|#
directive|define
name|SR_KP
value|0x20000000
end_define

begin_comment
comment|/* User-state protection key */
end_comment

begin_define
define|#
directive|define
name|SR_N
value|0x10000000
end_define

begin_comment
comment|/* No-execute protection */
end_comment

begin_define
define|#
directive|define
name|SR_VSID_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Virtual Segment ID mask */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SR_H_ */
end_comment

end_unit

