begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Tsubai Masanari.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: openpicreg.h,v 1.2 2001/02/05 19:22:23 briggs Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * GLOBAL/TIMER register (IDU base + 0x1000)  */
end_comment

begin_comment
comment|/* feature reporting reg 0 */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_FEATURE
value|0x1000
end_define

begin_comment
comment|/* global config reg 0 */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_CONFIG
value|0x1020
end_define

begin_define
define|#
directive|define
name|OPENPIC_CONFIG_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OPENPIC_CONFIG_8259_PASSTHRU_DISABLE
value|0x20000000
end_define

begin_comment
comment|/* vendor ID */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_VENDOR_ID
value|0x1080
end_define

begin_comment
comment|/* processor initialization reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_PROC_INIT
value|0x1090
end_define

begin_comment
comment|/* IPI vector/priority reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_IPI_VECTOR
parameter_list|(
name|ipi
parameter_list|)
value|(0x10a0 + (ipi) * 0x10)
end_define

begin_comment
comment|/* spurious intr. vector */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_SPURIOUS_VECTOR
value|0x10e0
end_define

begin_comment
comment|/*  * INTERRUPT SOURCE register (IDU base + 0x10000)  */
end_comment

begin_comment
comment|/* interrupt vector/priority reg */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPIC_SRC_VECTOR
end_ifndef

begin_define
define|#
directive|define
name|OPENPIC_SRC_VECTOR
parameter_list|(
name|irq
parameter_list|)
value|(0x10000 + (irq) * 0x20)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OPENPIC_SENSE_LEVEL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|OPENPIC_SENSE_EDGE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OPENPIC_POLARITY_POSITIVE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|OPENPIC_POLARITY_NEGATIVE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|OPENPIC_IMASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|OPENPIC_ACTIVITY
value|0x40000000
end_define

begin_define
define|#
directive|define
name|OPENPIC_PRIORITY_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|OPENPIC_PRIORITY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|OPENPIC_VECTOR_MASK
value|0x000000ff
end_define

begin_comment
comment|/* interrupt destination cpu */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPIC_IDEST
end_ifndef

begin_define
define|#
directive|define
name|OPENPIC_IDEST
parameter_list|(
name|irq
parameter_list|)
value|(0x10010 + (irq) * 0x20)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PROCESSOR register (IDU base + 0x20000)  */
end_comment

begin_comment
comment|/* IPI command reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_IPI
parameter_list|(
name|cpu
parameter_list|,
name|ipi
parameter_list|)
value|(0x20040 + (cpu) * 0x1000 + (ipi))
end_define

begin_comment
comment|/* current task priority reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_CPU_PRIORITY
parameter_list|(
name|cpu
parameter_list|)
value|(0x20080 + (cpu) * 0x1000)
end_define

begin_define
define|#
directive|define
name|OPENPIC_CPU_PRIORITY_MASK
value|0x0000000f
end_define

begin_comment
comment|/* interrupt acknowledge reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_IACK
parameter_list|(
name|cpu
parameter_list|)
value|(0x200a0 + (cpu) * 0x1000)
end_define

begin_comment
comment|/* end of interrupt reg */
end_comment

begin_define
define|#
directive|define
name|OPENPIC_EOI
parameter_list|(
name|cpu
parameter_list|)
value|(0x200b0 + (cpu) * 0x1000)
end_define

end_unit

