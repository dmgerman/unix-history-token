begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Utils.h - Misc utilities for indexing-----------------------------===//
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
comment|//  This header contains miscellaneous utilities for indexing related
end_comment

begin_comment
comment|//  functionality.
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
name|LLVM_CLANG_INDEX_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_UTILS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|ASTLocation
decl_stmt|;
comment|/// \brief Returns the ASTLocation that a source location points to.
comment|///
comment|/// \returns the resolved ASTLocation or an invalid ASTLocation if the source
comment|/// location could not be resolved.
name|ASTLocation
name|ResolveLocationInAST
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Decl
modifier|*
name|RelativeToDecl
init|=
literal|0
parameter_list|)
function_decl|;
block|}
comment|// end namespace idx
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

