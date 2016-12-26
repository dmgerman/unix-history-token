begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemoryTypeTableBuilder.h ---------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MEMORYTYPETABLEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MEMORYTYPETABLEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeTableBuilder.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|MemoryTypeTableBuilder
range|:
name|public
name|TypeTableBuilder
block|{
name|public
operator|:
name|MemoryTypeTableBuilder
argument_list|()
block|{}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Records
operator|.
name|empty
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|TFunc
operator|>
name|void
name|ForEachRecord
argument_list|(
argument|TFunc Func
argument_list|)
block|{
name|uint32_t
name|Index
operator|=
name|TypeIndex
operator|::
name|FirstNonSimpleIndex
block|;
for|for
control|(
name|StringRef
name|R
range|:
name|Records
control|)
block|{
name|Func
argument_list|(
name|TypeIndex
argument_list|(
name|Index
argument_list|)
argument_list|,
name|R
argument_list|)
expr_stmt|;
operator|++
name|Index
expr_stmt|;
block|}
block|}
name|protected
operator|:
name|TypeIndex
name|writeRecord
argument_list|(
argument|llvm::StringRef Data
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Records
block|;
name|BumpPtrAllocator
name|RecordStorage
block|;
name|DenseMap
operator|<
name|StringRef
block|,
name|TypeIndex
operator|>
name|HashedRecords
block|; }
decl_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_MEMORYTYPETABLEBUILDER_H
end_comment

end_unit

