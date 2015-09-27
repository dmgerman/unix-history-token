begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__IOAT_TEST_H__
end_ifndef

begin_define
define|#
directive|define
name|__IOAT_TEST_H__
end_define

begin_struct
struct|struct
name|ioat_test
block|{
name|uint32_t
name|channel_index
decl_stmt|;
name|uint32_t
name|num_loops
decl_stmt|;
specifier|volatile
name|uint32_t
name|num_completions
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOAT_TEST_OK
value|0
end_define

begin_define
define|#
directive|define
name|IOAT_TEST_NO_DMA_ENGINE
value|1
end_define

begin_define
define|#
directive|define
name|IOAT_TEST_NO_MEMORY
value|2
end_define

begin_define
define|#
directive|define
name|IOAT_TEST_MISCOMPARE
value|3
end_define

begin_define
define|#
directive|define
name|IOAT_DMATEST
value|_IOWR('i', 0, struct ioat_test)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IOAT_TEST_H__ */
end_comment

end_unit

