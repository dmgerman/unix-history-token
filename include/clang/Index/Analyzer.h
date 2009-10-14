begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Analyzer.h - Analysis for indexing information ---------*- C++ -*-===//
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
comment|// This file declares the Analyzer interface.
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
name|LLVM_CLANG_INDEX_ANALYZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_ANALYZER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|ObjCMessageExpr
decl_stmt|;
name|namespace
name|idx
block|{
name|class
name|Program
decl_stmt|;
name|class
name|IndexProvider
decl_stmt|;
name|class
name|TULocationHandler
decl_stmt|;
comment|/// \brief Provides indexing information, like finding all references of an
comment|/// Entity across translation units.
name|class
name|Analyzer
block|{
name|Program
modifier|&
name|Prog
decl_stmt|;
name|IndexProvider
modifier|&
name|Idxer
decl_stmt|;
name|Analyzer
argument_list|(
specifier|const
name|Analyzer
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|Analyzer
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Analyzer
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|public
label|:
name|explicit
name|Analyzer
argument_list|(
name|Program
operator|&
name|prog
argument_list|,
name|IndexProvider
operator|&
name|idxer
argument_list|)
operator|:
name|Prog
argument_list|(
name|prog
argument_list|)
operator|,
name|Idxer
argument_list|(
argument|idxer
argument_list|)
block|{ }
comment|/// \brief Find all TULocations for declarations of the given Decl and pass
comment|/// them to Handler.
name|void
name|FindDeclarations
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|TULocationHandler
operator|&
name|Handler
argument_list|)
expr_stmt|;
comment|/// \brief Find all TULocations for references of the given Decl and pass
comment|/// them to Handler.
name|void
name|FindReferences
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|TULocationHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
comment|/// \brief Find methods that may respond to the given message and pass them
comment|/// to Handler.
name|void
name|FindObjCMethods
parameter_list|(
name|ObjCMessageExpr
modifier|*
name|MsgE
parameter_list|,
name|TULocationHandler
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

