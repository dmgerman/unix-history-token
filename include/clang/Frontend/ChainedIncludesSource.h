begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ChainedIncludesSource.h - Chained PCHs in Memory ---------*- C++ -*-===//
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
comment|//  This file defines the ChainedIncludesSource class, which converts headers
end_comment

begin_comment
comment|//  to chained PCHs in memory, mainly used for testing.
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
name|LLVM_CLANG_SERIALIZATION_CHAINEDINCLUDESSOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_CHAINEDINCLUDESSOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
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
name|CompilerInstance
decl_stmt|;
name|class
name|ChainedIncludesSource
range|:
name|public
name|ExternalSemaSource
block|{
name|public
operator|:
name|virtual
operator|~
name|ChainedIncludesSource
argument_list|()
block|;
specifier|static
name|ChainedIncludesSource
operator|*
name|create
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|ExternalSemaSource
operator|&
name|getFinalReader
argument_list|()
specifier|const
block|{
return|return
operator|*
name|FinalReader
return|;
block|}
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|CompilerInstance
operator|*
operator|>
name|CIs
block|;
name|OwningPtr
operator|<
name|ExternalSemaSource
operator|>
name|FinalReader
block|;
name|protected
operator|:
comment|//===----------------------------------------------------------------------===//
comment|// ExternalASTSource interface.
comment|//===----------------------------------------------------------------------===//
name|virtual
name|Decl
operator|*
name|GetExternalDecl
argument_list|(
argument|uint32_t ID
argument_list|)
block|;
name|virtual
name|Selector
name|GetExternalSelector
argument_list|(
argument|uint32_t ID
argument_list|)
block|;
name|virtual
name|uint32_t
name|GetNumExternalSelectors
argument_list|()
block|;
name|virtual
name|Stmt
operator|*
name|GetExternalDeclStmt
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
name|virtual
name|CXXBaseSpecifier
operator|*
name|GetExternalCXXBaseSpecifiers
argument_list|(
argument|uint64_t Offset
argument_list|)
block|;
name|virtual
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|)
block|;
name|virtual
name|ExternalLoadResult
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|bool
argument_list|(
operator|*
name|isKindWeWant
argument_list|)
argument_list|(
name|Decl
operator|::
name|Kind
argument_list|)
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Result
argument_list|)
block|;
name|virtual
name|void
name|CompleteType
argument_list|(
name|TagDecl
operator|*
name|Tag
argument_list|)
block|;
name|virtual
name|void
name|CompleteType
argument_list|(
name|ObjCInterfaceDecl
operator|*
name|Class
argument_list|)
block|;
name|virtual
name|void
name|StartedDeserializing
argument_list|()
block|;
name|virtual
name|void
name|FinishedDeserializing
argument_list|()
block|;
name|virtual
name|void
name|StartTranslationUnit
argument_list|(
name|ASTConsumer
operator|*
name|Consumer
argument_list|)
block|;
name|virtual
name|void
name|PrintStats
argument_list|()
block|;
comment|/// Return the amount of memory used by memory buffers, breaking down
comment|/// by heap-backed versus mmap'ed memory.
name|virtual
name|void
name|getMemoryBufferSizes
argument_list|(
argument|MemoryBufferSizes&sizes
argument_list|)
specifier|const
block|;
comment|//===----------------------------------------------------------------------===//
comment|// ExternalSemaSource interface.
comment|//===----------------------------------------------------------------------===//
name|virtual
name|void
name|InitializeSema
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
block|;
name|virtual
name|void
name|ForgetSema
argument_list|()
block|;
name|virtual
name|void
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|)
block|;
name|virtual
name|bool
name|LookupUnqualified
argument_list|(
name|LookupResult
operator|&
name|R
argument_list|,
name|Scope
operator|*
name|S
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

