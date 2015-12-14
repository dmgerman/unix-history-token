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

begin_enum
enum|enum
name|ioat_res
block|{
name|IOAT_TEST_OK
init|=
literal|0
block|,
name|IOAT_TEST_NO_DMA_ENGINE
block|,
name|IOAT_TEST_NO_MEMORY
block|,
name|IOAT_TEST_MISCOMPARE
block|,
name|IOAT_TEST_INVALID_INPUT
block|,
name|IOAT_NUM_RES
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ioat_test_kind
block|{
name|IOAT_TEST_FILL
init|=
literal|0
block|,
name|IOAT_TEST_DMA
block|,
name|IOAT_TEST_RAW_DMA
block|,
name|IOAT_TEST_DMA_8K
block|,
name|IOAT_TEST_MEMCPY
block|,
name|IOAT_NUM_TESTKINDS
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|test_transaction
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ioat_test
block|{
specifier|volatile
name|uint32_t
name|status
index|[
name|IOAT_NUM_RES
index|]
decl_stmt|;
name|uint32_t
name|channel_index
decl_stmt|;
name|enum
name|ioat_test_kind
name|testkind
decl_stmt|;
comment|/* HW max of 1MB */
name|uint32_t
name|buffer_size
decl_stmt|;
name|uint32_t
name|chain_depth
decl_stmt|;
name|uint32_t
name|transactions
decl_stmt|;
comment|/* 	 * If non-zero, duration is time in ms; 	 * If zero, bounded by 'transactions' above. 	 */
name|uint32_t
name|duration
decl_stmt|;
comment|/* If true, check for miscompares after a copy. */
name|bool
name|verify
decl_stmt|;
comment|/* DMA directly to/from some memory address */
name|uint64_t
name|raw_target
decl_stmt|;
name|void
modifier|*
name|raw_vtarget
decl_stmt|;
name|bool
name|raw_write
decl_stmt|;
name|bool
name|raw_is_virtual
decl_stmt|;
name|bool
name|zero_stats
decl_stmt|;
comment|/* Configure coalesce period */
name|uint16_t
name|coalesce_period
decl_stmt|;
comment|/* Internal usage -- not test inputs */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|test_transaction
argument_list|)
name|free_q
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|test_transaction
argument_list|)
name|pend_q
expr_stmt|;
specifier|volatile
name|bool
name|too_late
decl_stmt|;
block|}
struct|;
end_struct

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

