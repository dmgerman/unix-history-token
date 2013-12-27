begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LambdaMangleContext.h - Context for mangling lambdas ---*- C++ -*-===//
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
comment|//  This file defines the LambdaMangleContext interface, which keeps track of
end_comment

begin_comment
comment|//  the Itanium C++ ABI mangling numbers for lambda expressions.
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
name|LLVM_CLANG_LAMBDAMANGLECONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LAMBDAMANGLECONTEXT_H
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
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
comment|/// \brief Keeps track of the mangled names of lambda expressions within a
comment|/// particular context.
name|class
name|LambdaMangleContext
range|:
name|public
name|RefCountedBase
operator|<
name|LambdaMangleContext
operator|>
block|{
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FunctionProtoType
operator|*
block|,
name|unsigned
operator|>
name|ManglingNumbers
block|;
name|public
operator|:
comment|/// \brief Retrieve the mangling number of a new lambda expression with the
comment|/// given call operator within this lambda context.
name|unsigned
name|getManglingNumber
argument_list|(
name|CXXMethodDecl
operator|*
name|CallOperator
argument_list|)
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

