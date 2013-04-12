begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SimplifyLibCalls.h - Library call simplifier -------------*- C++ -*-===//
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
comment|// This file exposes an interface to build some C language libcalls for
end_comment

begin_comment
comment|// optimization passes that need to call the various functions.
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
name|LLVM_TRANSFORMS_UTILS_SIMPLIFYLIBCALLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_SIMPLIFYLIBCALLS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|LibCallSimplifierImpl
decl_stmt|;
comment|/// LibCallSimplifier - This class implements a collection of optimizations
comment|/// that replace well formed calls to library functions with a more optimal
comment|/// form.  For example, replacing 'printf("Hello!")' with 'puts("Hello!")'.
name|class
name|LibCallSimplifier
block|{
comment|/// Impl - A pointer to the actual implementation of the library call
comment|/// simplifier.
name|LibCallSimplifierImpl
modifier|*
name|Impl
decl_stmt|;
name|public
label|:
name|LibCallSimplifier
argument_list|(
argument|const DataLayout *TD
argument_list|,
argument|const TargetLibraryInfo *TLI
argument_list|,
argument|bool UnsafeFPShrink
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|LibCallSimplifier
argument_list|()
expr_stmt|;
comment|/// optimizeCall - Take the given call instruction and return a more
comment|/// optimal value to replace the instruction with or 0 if a more
comment|/// optimal form can't be found.  Note that the returned value may
comment|/// be equal to the instruction being optimized.  In this case all
comment|/// other instructions that use the given instruction were modified
comment|/// and the given instruction is dead.
name|Value
modifier|*
name|optimizeCall
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|)
function_decl|;
comment|/// replaceAllUsesWith - This method is used when the library call
comment|/// simplifier needs to replace instructions other than the library
comment|/// call being modified.
name|virtual
name|void
name|replaceAllUsesWith
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|Value
operator|*
name|With
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
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

