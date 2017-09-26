begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- TildeExpressionResolver.h ------------*- C++ -*-===//
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
name|LLDB_UTILITY_TILDE_EXPRESSION_RESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_TILDE_EXPRESSION_RESOLVER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TildeExpressionResolver
block|{
name|public
label|:
name|virtual
operator|~
name|TildeExpressionResolver
argument_list|()
expr_stmt|;
comment|/// \brief Resolve a Tilde Expression contained according to bash rules.
comment|///
comment|/// \param Expr Contains the tilde expression to resolve.  A valid tilde
comment|///             expression must begin with a tilde and contain only non
comment|///             separator characters.
comment|///
comment|/// \param Output Contains the resolved tilde expression, or the original
comment|///               input if the tilde expression could not be resolved.
comment|///
comment|/// \returns true if \p Expr was successfully resolved, false otherwise.
name|virtual
name|bool
name|ResolveExact
argument_list|(
name|llvm
operator|::
name|StringRef
name|Expr
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Auto-complete a tilde expression with all matching values.
comment|///
comment|/// \param Expr Contains the tilde expression prefix to resolve.  See
comment|///             ResolveExact() for validity rules.
comment|///
comment|/// \param Output Contains all matching home directories, each one
comment|///               itself unresolved (i.e. you need to call ResolveExact
comment|///               on each item to turn it into a real path).
comment|///
comment|/// \returns true if there were any matches, false otherwise.
name|virtual
name|bool
name|ResolvePartial
argument_list|(
name|llvm
operator|::
name|StringRef
name|Expr
argument_list|,
name|llvm
operator|::
name|StringSet
operator|<
operator|>
operator|&
name|Output
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Resolve an entire path that begins with a tilde expression,
comment|/// replacing the username portion with the matched result.
name|bool
name|ResolveFullPath
argument_list|(
name|llvm
operator|::
name|StringRef
name|Expr
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Output
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
name|class
name|StandardTildeExpressionResolver
range|:
name|public
name|TildeExpressionResolver
block|{
name|public
operator|:
name|bool
name|ResolveExact
argument_list|(
argument|llvm::StringRef Expr
argument_list|,
argument|llvm::SmallVectorImpl<char>&Output
argument_list|)
name|override
block|;
name|bool
name|ResolvePartial
argument_list|(
argument|llvm::StringRef Expr
argument_list|,
argument|llvm::StringSet<>&Output
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef LLDB_UTILITY_TILDE_EXPRESSION_RESOLVER_H
end_comment

end_unit

