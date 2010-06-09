begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Indexer.h - IndexProvider implementation ---------------*- C++ -*-===//
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
comment|//  IndexProvider implementation.
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
name|LLVM_CLANG_INDEX_INDEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_INDEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Index/IndexProvider.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/Entity.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/GlobalSelector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

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
name|Program
decl_stmt|;
name|class
name|TranslationUnit
decl_stmt|;
comment|/// \brief Maps information to TranslationUnits.
name|class
name|Indexer
range|:
name|public
name|IndexProvider
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|TranslationUnit
operator|*
operator|,
literal|4
operator|>
name|TUSetTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ASTContext
operator|*
operator|,
name|TranslationUnit
operator|*
operator|>
name|CtxTUMapTy
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Entity
operator|,
name|TUSetTy
operator|>
name|MapTy
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|GlobalSelector
operator|,
name|TUSetTy
operator|>
name|SelMapTy
expr_stmt|;
name|explicit
name|Indexer
argument_list|(
name|Program
operator|&
name|prog
argument_list|)
operator|:
name|Prog
argument_list|(
argument|prog
argument_list|)
block|{ }
name|Program
operator|&
name|getProgram
argument_list|()
specifier|const
block|{
return|return
name|Prog
return|;
block|}
comment|/// \brief Find all Entities and map them to the given translation unit.
name|void
name|IndexAST
parameter_list|(
name|TranslationUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
name|virtual
name|void
name|GetTranslationUnitsFor
parameter_list|(
name|Entity
name|Ent
parameter_list|,
name|TranslationUnitHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
name|virtual
name|void
name|GetTranslationUnitsFor
parameter_list|(
name|GlobalSelector
name|Sel
parameter_list|,
name|TranslationUnitHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
name|private
label|:
name|Program
modifier|&
name|Prog
decl_stmt|;
name|MapTy
name|Map
decl_stmt|;
name|CtxTUMapTy
name|CtxTUMap
decl_stmt|;
name|SelMapTy
name|SelMap
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace idx
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

