begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeDatabase.h - A collection of CodeView type records ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeCollection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeDatabase
range|:
name|public
name|TypeCollection
block|{
name|friend
name|class
name|RandomAccessTypeVisitor
block|;
name|public
operator|:
name|explicit
name|TypeDatabase
argument_list|(
argument|uint32_t Capacity
argument_list|)
block|;
comment|/// Records the name of a type, and reserves its type index.
name|TypeIndex
name|appendType
argument_list|(
argument|StringRef Name
argument_list|,
argument|const CVType&Data
argument_list|)
block|;
comment|/// Records the name of a type, and reserves its type index.
name|void
name|recordType
argument_list|(
argument|StringRef Name
argument_list|,
argument|TypeIndex Index
argument_list|,
argument|const CVType&Data
argument_list|)
block|;
comment|/// Saves the name in a StringSet and creates a stable StringRef.
name|StringRef
name|saveTypeName
argument_list|(
argument|StringRef TypeName
argument_list|)
block|;
name|StringRef
name|getTypeName
argument_list|(
argument|TypeIndex Index
argument_list|)
specifier|const
block|;
specifier|const
name|CVType
operator|&
name|getTypeRecord
argument_list|(
argument|TypeIndex Index
argument_list|)
specifier|const
block|;
name|CVType
operator|&
name|getTypeRecord
argument_list|(
argument|TypeIndex Index
argument_list|)
block|;
name|bool
name|contains
argument_list|(
argument|TypeIndex Index
argument_list|)
specifier|const
block|;
name|uint32_t
name|size
argument_list|()
specifier|const
block|;
name|uint32_t
name|capacity
argument_list|()
specifier|const
block|;
name|bool
name|empty
argument_list|()
specifier|const
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
name|Optional
operator|<
name|TypeIndex
operator|>
name|largestTypeIndexLessThan
argument_list|(
argument|TypeIndex TI
argument_list|)
specifier|const
block|;
name|private
operator|:
name|TypeIndex
name|getAppendIndex
argument_list|()
specifier|const
block|;
name|void
name|grow
argument_list|()
block|;
name|void
name|grow
argument_list|(
argument|TypeIndex Index
argument_list|)
block|;
name|BumpPtrAllocator
name|Allocator
block|;
name|uint32_t
name|Count
operator|=
literal|0
block|;
name|TypeIndex
name|LargestTypeIndex
block|;
comment|/// All user defined type records in .debug$T live in here. Type indices
comment|/// greater than 0x1000 are user defined. Subtract 0x1000 from the index to
comment|/// index into this vector.
name|SmallVector
operator|<
name|StringRef
block|,
literal|10
operator|>
name|CVUDTNames
block|;
name|SmallVector
operator|<
name|CVType
block|,
literal|10
operator|>
name|TypeRecords
block|;
name|StringSaver
name|TypeNameStorage
block|;
name|BitVector
name|ValidRecords
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

