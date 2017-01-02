begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/ScopeExit.h - Execute code at scope exit --------*- C++ -*-===//
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
comment|// This file defines the make_scope_exit function, which executes user-defined
end_comment

begin_comment
comment|// cleanup logic at scope exit.
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
name|LLVM_ADT_SCOPE_EXIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SCOPE_EXIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|Callable
operator|>
name|class
name|scope_exit
block|{
name|Callable
name|ExitFunction
block|;
name|public
operator|:
name|template
operator|<
name|typename
name|Fp
operator|>
name|explicit
name|scope_exit
argument_list|(
name|Fp
operator|&&
name|F
argument_list|)
operator|:
name|ExitFunction
argument_list|(
argument|std::forward<Fp>(F)
argument_list|)
block|{}
name|scope_exit
argument_list|(
name|scope_exit
operator|&&
name|Rhs
argument_list|)
operator|:
name|ExitFunction
argument_list|(
argument|std::move(Rhs.ExitFunction)
argument_list|)
block|{}
operator|~
name|scope_exit
argument_list|()
block|{
name|ExitFunction
argument_list|()
block|; }
block|}
expr_stmt|;
block|}
comment|// end namespace detail
comment|// Keeps the callable object that is passed in, and execute it at the
comment|// destruction of the returned object (usually at the scope exit where the
comment|// returned object is kept).
comment|//
comment|// Interface is specified by p0052r2.
name|template
operator|<
name|typename
name|Callable
operator|>
name|LLVM_NODISCARD
name|detail
operator|::
name|scope_exit
operator|<
name|typename
name|std
operator|::
name|decay
operator|<
name|Callable
operator|>
operator|::
name|type
operator|>
name|make_scope_exit
argument_list|(
argument|Callable&&F
argument_list|)
block|{
return|return
name|detail
operator|::
name|scope_exit
operator|<
name|typename
name|std
operator|::
name|decay
operator|<
name|Callable
operator|>
operator|::
name|type
operator|>
operator|(
name|std
operator|::
name|forward
operator|<
name|Callable
operator|>
operator|(
name|F
operator|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

