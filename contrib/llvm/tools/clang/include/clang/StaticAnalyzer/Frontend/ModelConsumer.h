begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModelConsumer.h -----------------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file implements clang::ento::ModelConsumer which is an
end_comment

begin_comment
comment|/// ASTConsumer for model files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_GR_MODELCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_MODELCONSUMER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Stmt
decl_stmt|;
name|namespace
name|ento
block|{
comment|/// \brief ASTConsumer to consume model files' AST.
comment|///
comment|/// This consumer collects the bodies of function definitions into a StringMap
comment|/// from a model file.
name|class
name|ModelConsumer
range|:
name|public
name|ASTConsumer
block|{
name|public
operator|:
name|ModelConsumer
argument_list|(
name|llvm
operator|::
name|StringMap
operator|<
name|Stmt
operator|*
operator|>
operator|&
name|Bodies
argument_list|)
block|;
name|bool
name|HandleTopLevelDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
name|override
block|;
name|private
operator|:
name|llvm
operator|::
name|StringMap
operator|<
name|Stmt
operator|*
operator|>
operator|&
name|Bodies
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

