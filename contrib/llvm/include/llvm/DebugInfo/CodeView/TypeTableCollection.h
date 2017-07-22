begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeTableCollection.h ---------------------------------- *- C++ --*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPETABLECOLLECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPETABLECOLLECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeCollection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
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
name|TypeTableCollection
range|:
name|public
name|TypeCollection
block|{
name|public
operator|:
name|explicit
name|TypeTableCollection
argument_list|(
name|ArrayRef
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|Records
argument_list|)
block|;
name|Optional
operator|<
name|TypeIndex
operator|>
name|getFirst
argument_list|()
name|override
block|;
name|Optional
operator|<
name|TypeIndex
operator|>
name|getNext
argument_list|(
argument|TypeIndex Prev
argument_list|)
name|override
block|;
name|CVType
name|getType
argument_list|(
argument|TypeIndex Index
argument_list|)
name|override
block|;
name|StringRef
name|getTypeName
argument_list|(
argument|TypeIndex Index
argument_list|)
name|override
block|;
name|bool
name|contains
argument_list|(
argument|TypeIndex Index
argument_list|)
name|override
block|;
name|uint32_t
name|size
argument_list|()
name|override
block|;
name|uint32_t
name|capacity
argument_list|()
name|override
block|;
name|private
operator|:
name|BumpPtrAllocator
name|Allocator
block|;
name|StringSaver
name|NameStorage
block|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Names
block|;
name|ArrayRef
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|Records
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

