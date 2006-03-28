begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 IronPort Systems  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MFIQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|MFIQ_BIO
value|1
end_define

begin_define
define|#
directive|define
name|MFIQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|MFIQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|MFIQ_COUNT
value|4
end_define

begin_struct
struct|struct
name|mfi_qstat
block|{
name|uint32_t
name|q_length
decl_stmt|;
name|uint32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|mfi_statrequest
block|{
name|uint32_t
name|ms_item
decl_stmt|;
name|struct
name|mfi_qstat
name|ms_qstat
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|MFIIO_STATS
value|_IOWR('Q', 101, union mfi_statrequest)
end_define

end_unit

