begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyRandomTypeCollection.h -------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_LAZYRANDOMTYPECOLLECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_LAZYRANDOMTYPECOLLECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
comment|/// \brief Provides amortized O(1) random access to a CodeView type stream.
comment|/// Normally to access a type from a type stream, you must know its byte
comment|/// offset into the type stream, because type records are variable-lengthed.
comment|/// However, this is not the way we prefer to access them.  For example, given
comment|/// a symbol record one of the fields may be the TypeIndex of the symbol's
comment|/// type record.  Or given a type record such as an array type, there might
comment|/// be a TypeIndex for the element type.  Sequential access is perfect when
comment|/// we're just dumping every entry, but it's very poor for real world usage.
comment|///
comment|/// Type streams in PDBs contain an additional field which is a list of pairs
comment|/// containing indices and their corresponding offsets, roughly every ~8KB of
comment|/// record data.  This general idea need not be confined to PDBs though.  By
comment|/// supplying such an array, the producer of a type stream can allow the
comment|/// consumer much better access time, because the consumer can find the nearest
comment|/// index in this array, and do a linear scan forward only from there.
comment|///
comment|/// LazyRandomTypeCollection implements this algorithm, but additionally goes
comment|/// one step further by caching offsets of every record that has been visited at
comment|/// least once.  This way, even repeated visits of the same record will never
comment|/// require more than one linear scan.  For a type stream of N elements divided
comment|/// into M chunks of roughly equal size, this yields a worst case lookup time
comment|/// of O(N/M) and an amortized time of O(1).
name|class
name|LazyRandomTypeCollection
range|:
name|public
name|TypeCollection
block|{
name|using
name|PartialOffsetArray
operator|=
name|FixedStreamArray
operator|<
name|TypeIndexOffset
operator|>
block|;    struct
name|CacheEntry
block|{
name|CVType
name|Type
block|;
name|uint32_t
name|Offset
block|;
name|StringRef
name|Name
block|;   }
block|;
name|public
operator|:
name|explicit
name|LazyRandomTypeCollection
argument_list|(
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|LazyRandomTypeCollection
argument_list|(
argument|StringRef Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|LazyRandomTypeCollection
argument_list|(
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|LazyRandomTypeCollection
argument_list|(
argument|const CVTypeArray&Types
argument_list|,
argument|uint32_t RecordCountHint
argument_list|,
argument|PartialOffsetArray PartialOffsets
argument_list|)
block|;
name|LazyRandomTypeCollection
argument_list|(
argument|const CVTypeArray&Types
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|void
name|reset
argument_list|(
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|void
name|reset
argument_list|(
argument|StringRef Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
block|;
name|uint32_t
name|getOffsetOfType
argument_list|(
argument|TypeIndex Index
argument_list|)
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
name|private
operator|:
name|Error
name|ensureTypeExists
argument_list|(
argument|TypeIndex Index
argument_list|)
block|;
name|void
name|ensureCapacityFor
argument_list|(
argument|TypeIndex Index
argument_list|)
block|;
name|Error
name|visitRangeForType
argument_list|(
argument|TypeIndex TI
argument_list|)
block|;
name|Error
name|fullScanForType
argument_list|(
argument|TypeIndex TI
argument_list|)
block|;
name|void
name|visitRange
argument_list|(
argument|TypeIndex Begin
argument_list|,
argument|uint32_t BeginOffset
argument_list|,
argument|TypeIndex End
argument_list|)
block|;
comment|/// Number of actual records.
name|uint32_t
name|Count
operator|=
literal|0
block|;
comment|/// The largest type index which we've visited.
name|TypeIndex
name|LargestTypeIndex
operator|=
name|TypeIndex
operator|::
name|None
argument_list|()
block|;
name|BumpPtrAllocator
name|Allocator
block|;
name|StringSaver
name|NameStorage
block|;
comment|/// The type array to allow random access visitation of.
name|CVTypeArray
name|Types
block|;
name|std
operator|::
name|vector
operator|<
name|CacheEntry
operator|>
name|Records
block|;
comment|/// An array of index offsets for the given type stream, allowing log(N)
comment|/// lookups of a type record by index.  Similar to KnownOffsets but only
comment|/// contains offsets for some type indices, some of which may not have
comment|/// ever been visited.
name|PartialOffsetArray
name|PartialOffsets
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
comment|// LLVM_DEBUGINFO_CODEVIEW_LAZYRANDOMTYPECOLLECTION_H
end_comment

end_unit

