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
name|CLANG_FRONTEND_MULTIPLEXCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_FRONTEND_MULTIPLEXCONSUMER_H
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
file|"llvm/ADT/OwningPtr.h"
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
name|ArrayRef
operator|<
name|ASTConsumer
operator|*
operator|>
name|C
argument_list|)
block|;
operator|~
name|MultiplexConsumer
argument_list|()
block|;
comment|// ASTConsumer
name|virtual
name|void
name|Initialize
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
block|;
name|virtual
name|void
name|HandleCXXStaticMemberVarInstantiation
argument_list|(
name|VarDecl
operator|*
name|VD
argument_list|)
block|;
name|virtual
name|bool
name|HandleTopLevelDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
block|;
name|virtual
name|void
name|HandleInterestingDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
block|;
name|virtual
name|void
name|HandleTranslationUnit
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
name|virtual
name|void
name|HandleTagDeclDefinition
argument_list|(
name|TagDecl
operator|*
name|D
argument_list|)
block|;
name|virtual
name|void
name|HandleCXXImplicitFunctionInstantiation
argument_list|(
name|FunctionDecl
operator|*
name|D
argument_list|)
block|;
name|virtual
name|void
name|HandleTopLevelDeclInObjCContainer
argument_list|(
argument|DeclGroupRef D
argument_list|)
block|;
name|virtual
name|void
name|CompleteTentativeDefinition
argument_list|(
name|VarDecl
operator|*
name|D
argument_list|)
block|;
name|virtual
name|void
name|HandleVTable
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|bool DefinitionRequired
argument_list|)
block|;
name|virtual
name|ASTMutationListener
operator|*
name|GetASTMutationListener
argument_list|()
block|;
name|virtual
name|ASTDeserializationListener
operator|*
name|GetASTDeserializationListener
argument_list|()
block|;
name|virtual
name|void
name|PrintStats
argument_list|()
block|;
comment|// SemaConsumer
name|virtual
name|void
name|InitializeSema
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
block|;
name|virtual
name|void
name|ForgetSema
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|ASTConsumer
operator|*
operator|>
name|Consumers
block|;
comment|// Owns these.
name|OwningPtr
operator|<
name|MultiplexASTMutationListener
operator|>
name|MutationListener
block|;
name|OwningPtr
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

