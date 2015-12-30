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
file|"llvm/ADT/Hashing.h"
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
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
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
name|class
name|Record
block|{
name|public
operator|:
name|explicit
name|Record
argument_list|(
argument|llvm::StringRef RData
argument_list|)
block|;
specifier|const
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|.
name|get
argument_list|()
return|;
block|}
name|uint16_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|private
operator|:
name|uint16_t
name|Size
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|char
index|[]
operator|>
name|Data
block|;   }
block|;
name|private
operator|:
name|class
name|RecordHash
operator|:
name|std
operator|::
name|unary_function
operator|<
name|llvm
operator|::
name|StringRef
block|,
name|size_t
operator|>
block|{
name|public
operator|:
name|size_t
name|operator
argument_list|()
operator|(
name|llvm
operator|::
name|StringRef
name|Val
operator|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|size_t
operator|>
operator|(
name|llvm
operator|::
name|hash_value
argument_list|(
name|Val
argument_list|)
operator|)
return|;
block|}
expr|}
block|;
name|public
operator|:
name|MemoryTypeTableBuilder
argument_list|()
block|{}
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
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|Record
operator|>
operator|&
name|R
operator|:
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
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
operator|++
name|Index
expr_stmt|;
block|}
block|}
name|private
operator|:
name|virtual
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
name|std
operator|::
name|unique_ptr
operator|<
name|Record
operator|>>
name|Records
block|;
name|std
operator|::
name|unordered_map
operator|<
name|llvm
operator|::
name|StringRef
block|,
name|TypeIndex
block|,
name|RecordHash
operator|>
name|HashedRecords
block|; }
block|; }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

