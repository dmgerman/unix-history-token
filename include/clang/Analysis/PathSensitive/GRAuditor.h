begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- GRAuditor.h - Observers of the creation of ExplodedNodes------*- C++ -*-//
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
comment|//  This file defines GRAuditor and its primary subclasses, an interface
end_comment

begin_comment
comment|//  to audit the creation of ExplodedNodes.  This interface can be used
end_comment

begin_comment
comment|//  to implement simple checkers that do not mutate analysis state but
end_comment

begin_comment
comment|//  instead operate by perfoming simple logical checks at key monitoring
end_comment

begin_comment
comment|//  locations (e.g., function calls).
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
name|LLVM_CLANG_ANALYSIS_GRAUDITOR
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GRAUDITOR
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/ExplodedGraph.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|template
operator|<
name|typename
name|STATE
operator|>
name|class
name|GRAuditor
block|{
name|public
operator|:
typedef|typedef
name|ExplodedNode
operator|<
name|STATE
operator|>
name|NodeTy
expr_stmt|;
typedef|typedef
name|typename
name|STATE
operator|::
name|ManagerTy
name|ManagerTy
expr_stmt|;
name|virtual
operator|~
name|GRAuditor
argument_list|()
block|{}
name|virtual
name|bool
name|Audit
argument_list|(
name|NodeTy
operator|*
name|N
argument_list|,
name|ManagerTy
operator|&
name|M
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

