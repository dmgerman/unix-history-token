begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CGBuilder.h - Choose IRBuilder implementation  ----------*- C++ -*-===//
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
name|CLANG_CODEGEN_CGBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
comment|/// \brief This is an IRBuilder insertion helper that forwards to
comment|/// CodeGenFunction::InsertHelper, which adds nesessary metadata to
comment|/// instructions.
name|template
operator|<
name|bool
name|PreserveNames
operator|>
name|class
name|CGBuilderInserter
operator|:
name|protected
name|llvm
operator|::
name|IRBuilderDefaultInserter
operator|<
name|PreserveNames
operator|>
block|{
name|public
operator|:
name|CGBuilderInserter
argument_list|()
operator|:
name|CGF
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|explicit
name|CGBuilderInserter
argument_list|(
name|CodeGenFunction
operator|*
name|CGF
argument_list|)
operator|:
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{}
name|protected
operator|:
comment|/// \brief This forwards to CodeGenFunction::InsertHelper.
name|void
name|InsertHelper
argument_list|(
argument|llvm::Instruction *I
argument_list|,
argument|const llvm::Twine&Name
argument_list|,
argument|llvm::BasicBlock *BB
argument_list|,
argument|llvm::BasicBlock::iterator InsertPt
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|operator
operator|=
operator|(
specifier|const
name|CGBuilderInserter
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|CodeGenFunction
operator|*
name|CGF
block|; }
expr_stmt|;
comment|// Don't preserve names on values in an optimized build.
ifdef|#
directive|ifdef
name|NDEBUG
define|#
directive|define
name|PreserveNames
value|false
else|#
directive|else
define|#
directive|define
name|PreserveNames
value|true
endif|#
directive|endif
typedef|typedef
name|CGBuilderInserter
operator|<
name|PreserveNames
operator|>
name|CGBuilderInserterTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|IRBuilder
operator|<
name|PreserveNames
operator|,
name|llvm
operator|::
name|ConstantFolder
operator|,
name|CGBuilderInserterTy
operator|>
name|CGBuilderTy
expr_stmt|;
undef|#
directive|undef
name|PreserveNames
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

