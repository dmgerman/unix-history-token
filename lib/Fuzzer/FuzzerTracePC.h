begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerTracePC.h - INTERNAL - Path tracer. --------*- C++ -* ===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Trace PCs.
end_comment

begin_comment
comment|// This module implements __sanitizer_cov_trace_pc, a callback required
end_comment

begin_comment
comment|// for -fsanitize-coverage=trace-pc instrumentation.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_TRACE_PC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_TRACE_PC_H
end_define

begin_decl_stmt
name|namespace
name|fuzzer
block|{
struct|struct
name|PcCoverageMap
block|{
specifier|static
specifier|const
name|size_t
name|kMapSizeInBits
init|=
literal|65371
decl_stmt|;
comment|// Prime.
specifier|static
specifier|const
name|size_t
name|kMapSizeInBitsAligned
init|=
literal|65536
decl_stmt|;
comment|// 2^16
specifier|static
specifier|const
name|size_t
name|kBitsInWord
init|=
operator|(
sizeof|sizeof
argument_list|(
name|uintptr_t
argument_list|)
operator|*
literal|8
operator|)
decl_stmt|;
specifier|static
specifier|const
name|size_t
name|kMapSizeInWords
init|=
name|kMapSizeInBitsAligned
operator|/
name|kBitsInWord
decl_stmt|;
name|void
name|Reset
parameter_list|()
function_decl|;
specifier|inline
name|void
name|Update
parameter_list|(
name|uintptr_t
name|Addr
parameter_list|)
function_decl|;
name|size_t
name|MergeFrom
parameter_list|(
specifier|const
name|PcCoverageMap
modifier|&
name|Other
parameter_list|)
function_decl|;
name|uintptr_t
name|Map
index|[
name|kMapSizeInWords
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|512
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
comment|// Clears the current PC Map.
name|void
name|PcMapResetCurrent
parameter_list|()
function_decl|;
comment|// Merges the current PC Map into the combined one, and clears the former.
name|size_t
name|PcMapMergeInto
parameter_list|(
name|PcCoverageMap
modifier|*
name|Map
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

