begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- USRFinder.h - Clang refactoring library --------------------------===//
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
comment|/// \brief Methods for determining the USR of a symbol at a location in source
end_comment

begin_comment
comment|/// code.
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
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/AST.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchFinder.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|using
name|namespace
name|clang
operator|::
name|ast_matchers
expr_stmt|;
end_expr_stmt

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
name|SourceLocation
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|namespace
name|tooling
block|{
comment|// Given an AST context and a point, returns a NamedDecl identifying the symbol
comment|// at the point. Returns null if nothing is found at the point.
specifier|const
name|NamedDecl
modifier|*
name|getNamedDeclAt
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|SourceLocation
name|Point
parameter_list|)
function_decl|;
comment|// Given an AST context and a fully qualified name, returns a NamedDecl
comment|// identifying the symbol with a matching name. Returns null if nothing is
comment|// found for the name.
specifier|const
name|NamedDecl
modifier|*
name|getNamedDeclFor
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl_stmt|;
comment|// Converts a Decl into a USR.
name|std
operator|::
name|string
name|getUSRForDecl
argument_list|(
specifier|const
name|Decl
operator|*
name|Decl
argument_list|)
expr_stmt|;
comment|// FIXME: Implement RecursiveASTVisitor<T>::VisitNestedNameSpecifier instead.
name|class
name|NestedNameSpecifierLocFinder
range|:
name|public
name|MatchFinder
operator|::
name|MatchCallback
block|{
name|public
operator|:
name|explicit
name|NestedNameSpecifierLocFinder
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|Context
argument_list|(
argument|Context
argument_list|)
block|{}
name|std
operator|::
name|vector
operator|<
name|NestedNameSpecifierLoc
operator|>
name|getNestedNameSpecifierLocations
argument_list|()
block|{
name|addMatchers
argument_list|()
block|;
name|Finder
operator|.
name|matchAST
argument_list|(
name|Context
argument_list|)
block|;
return|return
name|Locations
return|;
block|}
name|private
operator|:
name|void
name|addMatchers
argument_list|()
block|{
specifier|const
name|auto
name|NestedNameSpecifierLocMatcher
operator|=
name|nestedNameSpecifierLoc
argument_list|()
operator|.
name|bind
argument_list|(
literal|"nestedNameSpecifierLoc"
argument_list|)
block|;
name|Finder
operator|.
name|addMatcher
argument_list|(
name|NestedNameSpecifierLocMatcher
argument_list|,
name|this
argument_list|)
block|;   }
name|void
name|run
argument_list|(
argument|const MatchFinder::MatchResult&Result
argument_list|)
name|override
block|{
specifier|const
name|auto
operator|*
name|NNS
operator|=
name|Result
operator|.
name|Nodes
operator|.
name|getNodeAs
operator|<
name|NestedNameSpecifierLoc
operator|>
operator|(
literal|"nestedNameSpecifierLoc"
operator|)
block|;
name|Locations
operator|.
name|push_back
argument_list|(
operator|*
name|NNS
argument_list|)
block|;   }
name|ASTContext
operator|&
name|Context
block|;
name|std
operator|::
name|vector
operator|<
name|NestedNameSpecifierLoc
operator|>
name|Locations
block|;
name|MatchFinder
name|Finder
block|; }
decl_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_REFACTOR_RENAME_USR_FINDER_H
end_comment

end_unit

