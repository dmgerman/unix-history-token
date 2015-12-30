begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SplitModule.h - Split a module into partitions -----------*- C++ -*-===//
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
comment|// This file defines the function llvm::SplitModule, which splits a module
end_comment

begin_comment
comment|// into multiple linkable partitions. It can be used to implement parallel code
end_comment

begin_comment
comment|// generation for link-time optimization.
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
name|LLVM_TRANSFORMS_UTILS_SPLITMODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SPLITMODULE_H
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// Splits the module M into N linkable partitions. The function ModuleCallback
comment|/// is called N times passing each individual partition as the MPart argument.
comment|///
comment|/// FIXME: This function does not deal with the somewhat subtle symbol
comment|/// visibility issues around module splitting, including (but not limited to):
comment|///
comment|/// - Internal symbols should not collide with symbols defined outside the
comment|///   module.
comment|/// - Internal symbols defined in module-level inline asm should be visible to
comment|///   each partition.
name|void
name|SplitModule
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|,
name|unsigned
name|N
argument_list|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|MPart
argument_list|)
operator|>
name|ModuleCallback
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

