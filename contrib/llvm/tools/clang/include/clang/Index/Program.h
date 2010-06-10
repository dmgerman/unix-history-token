begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Program.h - Cross-translation unit information ---------*- C++ -*-===//
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
comment|// This file declares the idx::Program interface.
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
name|LLVM_CLANG_INDEX_PROGRAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_PROGRAM_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|EntityHandler
decl_stmt|;
comment|/// \brief Top level object that owns and maintains information
comment|/// that is common across translation units.
name|class
name|Program
block|{
name|void
modifier|*
name|Impl
decl_stmt|;
name|Program
argument_list|(
specifier|const
name|Program
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|Program
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Program
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|friend
name|class
name|Entity
decl_stmt|;
name|friend
name|class
name|GlobalSelector
decl_stmt|;
name|public
label|:
name|Program
argument_list|()
expr_stmt|;
operator|~
name|Program
argument_list|()
expr_stmt|;
comment|/// \brief Traverses the AST and passes all the entities to the Handler.
name|void
name|FindEntities
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
name|EntityHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

