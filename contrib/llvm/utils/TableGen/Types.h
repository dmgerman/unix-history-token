begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Types.h - Helper for the selection of C++ types. ---------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_UTILS_TABLEGEN_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_TYPES_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Returns the smallest unsigned integer type that can hold the given range.
comment|/// MaxSize indicates the largest size of integer to consider (in bits) and only
comment|/// supports values of at least 32.
specifier|const
name|char
modifier|*
name|getMinimalTypeForRange
parameter_list|(
name|uint64_t
name|Range
parameter_list|,
name|unsigned
name|MaxSize
init|=
literal|64
parameter_list|)
function_decl|;
comment|/// Returns the smallest unsigned integer type that can hold the given bitfield.
specifier|const
name|char
modifier|*
name|getMinimalTypeForEnumBitfield
parameter_list|(
name|uint64_t
name|Size
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

