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
file|<string>
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

