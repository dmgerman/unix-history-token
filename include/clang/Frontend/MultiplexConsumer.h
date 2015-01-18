begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MultiplexConsumer.h - AST Consumer for PCH Generation ---*- C++ -*-===//
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
comment|//  This file declares the MultiplexConsumer class, which can be used to
end_comment

begin_comment
comment|//  multiplex ASTConsumer and SemaConsumer messages to many consumers.
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
name|LLVM_CLANG_FRONTEND_MULTIPLEXCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_MULTIPLEXCONSUMER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaConsumer.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MultiplexASTMutationListener
decl_stmt|;
name|class
name|MultiplexASTDeserializationListener
decl_stmt|;
comment|// Has a list of ASTConsumers and calls each of them. Owns its children.
name|class
name|MultiplexConsumer
range|:
name|public
name|SemaConsumer
block|{
name|public
operator|:
comment|// Takes ownership of the pointers in C.
name|MultiplexConsumer
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>>
name|C
argument_list|)
block|;
operator|~
name|MultiplexConsumer
argument_list|()
block|;
comment|// ASTConsumer
name|void
name|Initialize
argument_list|(
argument|ASTContext&Context
argument_list|)
name|override
block|;
name|void
name|HandleCXXStaticMemberVarInstantiation
argument_list|(
argument|VarDecl *VD
argument_list|)
name|override
block|;
name|bool
name|HandleTopLevelDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
name|override
block|;
name|void
name|HandleInlineMethodDefinition
argument_list|(
argument|CXXMethodDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleInterestingDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
name|override
block|;
name|void
name|HandleTranslationUnit
argument_list|(
argument|ASTContext&Ctx
argument_list|)
name|override
block|;
name|void
name|HandleTagDeclDefinition
argument_list|(
argument|TagDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleTagDeclRequiredDefinition
argument_list|(
argument|const TagDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleCXXImplicitFunctionInstantiation
argument_list|(
argument|FunctionDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleTopLevelDeclInObjCContainer
argument_list|(
argument|DeclGroupRef D
argument_list|)
name|override
block|;
name|void
name|HandleImplicitImportDecl
argument_list|(
argument|ImportDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleLinkerOptionPragma
argument_list|(
argument|llvm::StringRef Opts
argument_list|)
name|override
block|;
name|void
name|HandleDetectMismatch
argument_list|(
argument|llvm::StringRef Name
argument_list|,
argument|llvm::StringRef Value
argument_list|)
name|override
block|;
name|void
name|HandleDependentLibrary
argument_list|(
argument|llvm::StringRef Lib
argument_list|)
name|override
block|;
name|void
name|CompleteTentativeDefinition
argument_list|(
argument|VarDecl *D
argument_list|)
name|override
block|;
name|void
name|HandleVTable
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|bool DefinitionRequired
argument_list|)
name|override
block|;
name|ASTMutationListener
operator|*
name|GetASTMutationListener
argument_list|()
name|override
block|;
name|ASTDeserializationListener
operator|*
name|GetASTDeserializationListener
argument_list|()
name|override
block|;
name|void
name|PrintStats
argument_list|()
name|override
block|;
comment|// SemaConsumer
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
name|override
block|;
name|void
name|ForgetSema
argument_list|()
name|override
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>>
name|Consumers
block|;
comment|// Owns these.
name|std
operator|::
name|unique_ptr
operator|<
name|MultiplexASTMutationListener
operator|>
name|MutationListener
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|MultiplexASTDeserializationListener
operator|>
name|DeserializationListener
block|; }
decl_stmt|;
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

