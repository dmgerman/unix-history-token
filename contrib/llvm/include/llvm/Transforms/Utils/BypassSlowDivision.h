begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/BypassSlowDivision.h --------------*- C++ -*-===//
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
comment|// This file contains an optimization for div and rem on architectures that
end_comment

begin_comment
comment|// execute short instructions significantly faster than longer instructions.
end_comment

begin_comment
comment|// For example, on Intel Atom 32-bit divides are slow enough that during
end_comment

begin_comment
comment|// runtime it is profitable to check the value of the operands, and if they are
end_comment

begin_comment
comment|// positive and less than 256 use an unsigned 8-bit divide.
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
name|LLVM_TRANSFORMS_UTILS_BYPASSSLOWDIVISION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_BYPASSSLOWDIVISION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This optimization identifies DIV instructions that can be
comment|/// profitably bypassed and carried out with a shorter, faster divide.
name|bool
name|bypassSlowDivision
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|Function
operator|::
name|iterator
operator|&
name|I
argument_list|,
specifier|const
name|DenseMap
operator|<
name|unsigned
name|int
argument_list|,
name|unsigned
name|int
operator|>
operator|&
name|BypassWidth
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

