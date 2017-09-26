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
name|LLVM_CLANG_CODEGEN_CODEGENACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_CODEGENACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
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
comment|// Let BackendConsumer access LinkModule.
name|friend
name|class
name|BackendConsumer
block|;
comment|/// Info about module to link into a module we're generating.
block|struct
name|LinkModule
block|{
comment|/// The module to link in.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|Module
block|;
comment|/// If true, we set attributes on Module's functions according to our
comment|/// CodeGenOptions and LangOptions, as though we were generating the
comment|/// function ourselves.
name|bool
name|PropagateAttrs
block|;
comment|/// If true, we use LLVM module internalizer.
name|bool
name|Internalize
block|;
comment|/// Bitwise combination of llvm::LinkerFlags used when we link the module.
name|unsigned
name|LinkFlags
block|;   }
block|;
name|unsigned
name|Act
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|TheModule
block|;
comment|/// Bitcode modules to link in to our module.
name|SmallVector
operator|<
name|LinkModule
block|,
literal|4
operator|>
name|LinkModules
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
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|loadModule
argument_list|(
argument|llvm::MemoryBufferRef MBRef
argument_list|)
block|;
name|protected
operator|:
comment|/// Create a new code generation action.  If the optional \p _VMContext
comment|/// parameter is supplied, the action uses it without taking ownership,
comment|/// otherwise it creates a fresh LLVM context and takes ownership.
name|CodeGenAction
argument_list|(
argument|unsigned _Act
argument_list|,
argument|llvm::LLVMContext *_VMContext = nullptr
argument_list|)
block|;
name|bool
name|hasIRSupport
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|StringRef InFile
argument_list|)
name|override
block|;
name|void
name|ExecuteAction
argument_list|()
name|override
block|;
name|void
name|EndSourceFileAction
argument_list|()
name|override
block|;
name|public
operator|:
operator|~
name|CodeGenAction
argument_list|()
name|override
block|;
comment|/// Take the generated LLVM module, for use after the action has been run.
comment|/// The result may be null on failure.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
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
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitBCAction
range|:
name|public
name|CodeGenAction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitLLVMAction
range|:
name|public
name|CodeGenAction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitLLVMOnlyAction
range|:
name|public
name|CodeGenAction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitCodeGenOnlyAction
range|:
name|public
name|CodeGenAction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
argument_list|)
block|; }
decl_stmt|;
name|class
name|EmitObjAction
range|:
name|public
name|CodeGenAction
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
name|nullptr
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

