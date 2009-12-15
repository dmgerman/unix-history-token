begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaConsumer.h - Abstract interface for AST semantics --*- C++ -*-===//
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
comment|//  This file defines the SemaConsumer class, a subclass of
end_comment

begin_comment
comment|//  ASTConsumer that is used by AST clients that also require
end_comment

begin_comment
comment|//  additional semantic analysis.
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
name|LLVM_CLANG_SEMA_SEMACONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMACONSUMER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Sema
decl_stmt|;
comment|/// \brief An abstract interface that should be implemented by
comment|/// clients that read ASTs and then require further semantic
comment|/// analysis of the entities in those ASTs.
name|class
name|SemaConsumer
range|:
name|public
name|ASTConsumer
block|{
name|public
operator|:
name|SemaConsumer
argument_list|()
block|{
name|ASTConsumer
operator|::
name|SemaConsumer
operator|=
name|true
block|;     }
comment|/// \brief Initialize the semantic consumer with the Sema instance
comment|/// being used to perform semantic analysis on the abstract syntax
comment|/// tree.
name|virtual
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
block|{}
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
name|virtual
name|void
name|ForgetSema
argument_list|()
block|{}
comment|// isa/cast/dyn_cast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const ASTConsumer *Consumer
argument_list|)
block|{
return|return
name|Consumer
operator|->
name|SemaConsumer
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SemaConsumer *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

