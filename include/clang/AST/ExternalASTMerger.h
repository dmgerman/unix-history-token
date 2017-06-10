begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExternalASTMerger.h - Merging External AST Interface ---*- C++ -*-===//
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
comment|//  This file declares the ExternalASTMerger, which vends a combination of ASTs
end_comment

begin_comment
comment|//  from several different ASTContext/FileManager pairs
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
name|LLVM_CLANG_AST_EXTERNALASTMERGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXTERNALASTMERGER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTImporter.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ExternalASTMerger
range|:
name|public
name|ExternalASTSource
block|{
name|public
operator|:
expr|struct
name|ImporterPair
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ASTImporter
operator|>
name|Forward
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTImporter
operator|>
name|Reverse
block|;   }
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|ImporterPair
operator|>
name|Importers
block|;
name|public
operator|:
expr|struct
name|ImporterEndpoint
block|{
name|ASTContext
operator|&
name|AST
block|;
name|FileManager
operator|&
name|FM
block|;   }
block|;
name|ExternalASTMerger
argument_list|(
specifier|const
name|ImporterEndpoint
operator|&
name|Target
argument_list|,
name|llvm
operator|::
name|ArrayRef
operator|<
name|ImporterEndpoint
operator|>
name|Sources
argument_list|)
block|;
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|)
name|override
block|;
name|void
name|FindExternalLexicalDecls
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|llvm::function_ref<bool(Decl::Kind)> IsKindWeWant
argument_list|,
argument|SmallVectorImpl<Decl *>&Result
argument_list|)
name|override
block|;
name|using
name|ExternalASTSource
operator|::
name|CompleteType
block|;
name|void
name|CompleteType
argument_list|(
argument|TagDecl *Tag
argument_list|)
name|override
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

