begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ProgramImpl.h - Internal Program implementation---------*- C++ -*-===//
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
comment|//  Internal implementation for the Program class
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
name|LLVM_CLANG_INDEX_PROGRAMIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_PROGRAMIMPL_H
end_define

begin_include
include|#
directive|include
file|"EntityImpl.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|idx
block|{
name|class
name|EntityListener
decl_stmt|;
name|class
name|ProgramImpl
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|FoldingSet
operator|<
name|EntityImpl
operator|>
name|EntitySetTy
expr_stmt|;
name|private
label|:
name|EntitySetTy
name|Entities
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
expr_stmt|;
name|IdentifierTable
name|Identifiers
decl_stmt|;
name|SelectorTable
name|Selectors
decl_stmt|;
name|ProgramImpl
argument_list|(
specifier|const
name|ProgramImpl
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|ProgramImpl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ProgramImpl
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|public
label|:
name|ProgramImpl
argument_list|()
operator|:
name|Identifiers
argument_list|(
argument|LangOptions()
argument_list|)
block|{ }
name|EntitySetTy
operator|&
name|getEntities
argument_list|()
block|{
return|return
name|Entities
return|;
block|}
name|IdentifierTable
modifier|&
name|getIdents
parameter_list|()
block|{
return|return
name|Identifiers
return|;
block|}
name|SelectorTable
modifier|&
name|getSelectors
parameter_list|()
block|{
return|return
name|Selectors
return|;
block|}
name|void
modifier|*
name|Allocate
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Align
init|=
literal|8
parameter_list|)
block|{
return|return
name|BumpAlloc
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
return|;
block|}
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

