begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Greg Ansley  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AT91REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_AT91REG_H_
end_define

begin_include
include|#
directive|include
file|"opt_at91.h"
end_include

begin_comment
comment|/* Where builtin peripherals start in KVM */
end_comment

begin_define
define|#
directive|define
name|AT91_BASE
value|0xd0000000
end_define

begin_comment
comment|/* A few things that we count on being the same  * throught the whole family of SOCs */
end_comment

begin_comment
comment|/* SYSC System Controler */
end_comment

begin_comment
comment|/* System Registers */
end_comment

begin_define
define|#
directive|define
name|AT91_SYS_BASE
value|0xffff000
end_define

begin_define
define|#
directive|define
name|AT91_SYS_SIZE
value|0x1000
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AT91SAM9G45
argument_list|)
operator|||
name|defined
argument_list|(
name|AT91SAM9263
argument_list|)
end_if

begin_define
define|#
directive|define
name|AT91_DBGU_BASE
value|0xfffee00
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AT91_DBGU_BASE
value|0xffff200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AT91_DBGU_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|DBGU_C1R
value|(64)
end_define

begin_comment
comment|/* Chip ID1 Register */
end_comment

begin_define
define|#
directive|define
name|DBGU_C2R
value|(68)
end_define

begin_comment
comment|/* Chip ID2 Register */
end_comment

begin_define
define|#
directive|define
name|DBGU_FNTR
value|(72)
end_define

begin_comment
comment|/* Force NTRST Register */
end_comment

begin_define
define|#
directive|define
name|AT91_CPU_VERSION_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|AT91_CPU_RM9200
value|0x09290780
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9260
value|0x019803a0
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9261
value|0x019703a0
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9263
value|0x019607a0
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9G10
value|0x819903a0
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9G20
value|0x019905a0
end_define

begin_define
define|#
directive|define
name|AT91_CPU_SAM9G45
value|0x819b05a0
end_define

begin_define
define|#
directive|define
name|AT91_ARCH
parameter_list|(
name|chipid
parameter_list|)
value|((chipid>> 20)& 0xff)
end_define

begin_define
define|#
directive|define
name|AT91_CPU
parameter_list|(
name|chipid
parameter_list|)
value|(chipid& ~AT91_CPU_VERSION_MASK)
end_define

begin_define
define|#
directive|define
name|AT91_ARCH_SAM9
value|(0x19)
end_define

begin_define
define|#
directive|define
name|AT91_ARCH_RM92
value|(0x92)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AT91REG_H_ */
end_comment

end_unit

