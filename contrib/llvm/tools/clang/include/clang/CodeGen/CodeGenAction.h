begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenAction.h - LLVM Code Generation Frontend Action -*- C++ -*-===//
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
name|LLVM_CLANG_CODEGEN_CODE_GEN_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_CODE_GEN_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|BackendConsumer
decl_stmt|;
name|class
name|CodeGenAction
range|:
name|public
name|ASTFrontendAction
block|{
name|private
operator|:
name|unsigned
name|Act
block|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|TheModule
block|;
name|llvm
operator|::
name|LLVMContext
operator|*
name|VMContext
block|;
name|bool
name|OwnsVMContext
block|;
name|protected
operator|:
comment|/// Create a new code generation action.  If the optional \arg _VMContext
comment|/// parameter is supplied, the action uses it without taking ownership,
comment|/// otherwise it creates a fresh LLVM context and takes ownership.
name|CodeGenAction
argument_list|(
argument|unsigned _Act
argument_list|,
argument|llvm::LLVMContext *_VMContext =
literal|0
argument_list|)
block|;
name|virtual
name|bool
name|hasIRSupport
argument_list|()
specifier|const
block|;
name|virtual
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
block|;
name|virtual
name|void
name|ExecuteAction
argument_list|()
block|;
name|virtual
name|void
name|EndSourceFileAction
argument_list|()
block|;
name|public
operator|:
operator|~
name|CodeGenAction
argument_list|()
block|;
comment|/// takeModule - Take the generated LLVM module, for use after the action has
comment|/// been run. The result may be null on failure.
name|llvm
operator|::
name|Module
operator|*
name|takeModule
argument_list|()
block|;
comment|/// Take the LLVM context used by this action.
name|llvm
operator|::
name|LLVMContext
operator|*
name|takeLLVMContext
argument_list|()
block|;
name|BackendConsumer
operator|*
name|BEConsumer
block|; }
decl_stmt|;
name|class
name|EmitAssemblyAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitAssemblyAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitBCAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitBCAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitLLVMAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitLLVMAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitLLVMOnlyAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitLLVMOnlyAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitCodeGenOnlyAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitCodeGenOnlyAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitObjAction
range|:
name|public
name|CodeGenAction
block|{
name|public
operator|:
name|EmitObjAction
argument_list|(
name|llvm
operator|::
name|LLVMContext
operator|*
name|_VMContext
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

