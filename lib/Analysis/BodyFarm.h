begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== BodyFarm.h - Factory for conjuring up fake bodies -------------*- C++ -*-//
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
comment|// BodyFarm is a factory for creating faux implementations for functions/methods
end_comment

begin_comment
comment|// for analysis purposes.
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
name|LLVM_CLANG_ANALYSIS_BODYFARM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_BODYFARM_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|BodyFarm
block|{
name|public
label|:
name|BodyFarm
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
operator|:
name|C
argument_list|(
argument|C
argument_list|)
block|{}
comment|/// Factory method for creating bodies for ordinary functions.
name|Stmt
operator|*
name|getBody
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// Factory method for creating bodies for Objective-C properties.
name|Stmt
modifier|*
name|getBody
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|private
label|:
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|Optional
operator|<
name|Stmt
operator|*
operator|>
expr|>
name|BodyMap
expr_stmt|;
name|ASTContext
modifier|&
name|C
decl_stmt|;
name|BodyMap
name|Bodies
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

