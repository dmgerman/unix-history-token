begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeMetadataUtils.h - Utilities related to type metadata --*- C++ -*-==//
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
comment|//
end_comment

begin_comment
comment|// This file contains functions that make it easier to manipulate type metadata
end_comment

begin_comment
comment|// for devirtualization.
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
name|LLVM_ANALYSIS_TYPEMETADATAUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_TYPEMETADATAUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A call site that could be devirtualized.
struct|struct
name|DevirtCallSite
block|{
comment|/// The offset from the address point to the virtual function.
name|uint64_t
name|Offset
decl_stmt|;
comment|/// The call site itself.
name|CallSite
name|CS
decl_stmt|;
block|}
struct|;
comment|/// Given a call to the intrinsic @llvm.type.test, find all devirtualizable
comment|/// call sites based on the call and return them in DevirtCalls.
name|void
name|findDevirtualizableCallsForTypeTest
argument_list|(
name|SmallVectorImpl
operator|<
name|DevirtCallSite
operator|>
operator|&
name|DevirtCalls
argument_list|,
name|SmallVectorImpl
operator|<
name|CallInst
operator|*
operator|>
operator|&
name|Assumes
argument_list|,
specifier|const
name|CallInst
operator|*
name|CI
argument_list|)
decl_stmt|;
comment|/// Given a call to the intrinsic @llvm.type.checked.load, find all
comment|/// devirtualizable call sites based on the call and return them in DevirtCalls.
name|void
name|findDevirtualizableCallsForTypeCheckedLoad
argument_list|(
name|SmallVectorImpl
operator|<
name|DevirtCallSite
operator|>
operator|&
name|DevirtCalls
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|LoadedPtrs
argument_list|,
name|SmallVectorImpl
operator|<
name|Instruction
operator|*
operator|>
operator|&
name|Preds
argument_list|,
name|bool
operator|&
name|HasNonCallUses
argument_list|,
specifier|const
name|CallInst
operator|*
name|CI
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

