begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerSHA1.h - Internal header for the SHA1 utils --------*- C++ -* ===//
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
comment|// SHA1 utils.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_SHA1_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_SHA1_H
end_define

begin_include
include|#
directive|include
file|"FuzzerDefs.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
comment|// Private copy of SHA1 implementation.
specifier|static
specifier|const
name|int
name|kSHA1NumBytes
init|=
literal|20
decl_stmt|;
comment|// Computes SHA1 hash of 'Len' bytes in 'Data', writes kSHA1NumBytes to 'Out'.
name|void
name|ComputeSHA1
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|Data
parameter_list|,
name|size_t
name|Len
parameter_list|,
name|uint8_t
modifier|*
name|Out
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|Sha1ToString
argument_list|(
argument|const uint8_t Sha1[kSHA1NumBytes]
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|Hash
argument_list|(
specifier|const
name|Unit
operator|&
name|U
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_SHA1_H
end_comment

end_unit

