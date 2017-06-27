begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyRandomTypeCollection.h ---------------------------- *- C++ --*-===//
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
file|"llvm/Support/Error.h"
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
typedef|typedef
name|FixedStreamArray
operator|<
name|TypeIndexOffset
operator|>
name|PartialOffsetArray
expr_stmt|;
block|struct
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
decl_stmt|;
name|public
label|:
name|explicit
name|LazyRandomTypeCollection
parameter_list|(
name|uint32_t
name|RecordCountHint
parameter_list|)
function_decl|;
name|LazyRandomTypeCollection
argument_list|(
argument|StringRef Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
empty_stmt|;
name|LazyRandomTypeCollection
argument_list|(
argument|ArrayRef<uint8_t> Data
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
empty_stmt|;
name|LazyRandomTypeCollection
argument_list|(
argument|const CVTypeArray&Types
argument_list|,
argument|uint32_t RecordCountHint
argument_list|,
argument|PartialOffsetArray PartialOffsets
argument_list|)
empty_stmt|;
name|LazyRandomTypeCollection
argument_list|(
argument|const CVTypeArray&Types
argument_list|,
argument|uint32_t RecordCountHint
argument_list|)
empty_stmt|;
name|void
name|reset
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|,
name|uint32_t
name|RecordCountHint
argument_list|)
decl_stmt|;
name|void
name|reset
parameter_list|(
name|StringRef
name|Data
parameter_list|,
name|uint32_t
name|RecordCountHint
parameter_list|)
function_decl|;
name|uint32_t
name|getOffsetOfType
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
function_decl|;
name|CVType
name|getType
argument_list|(
name|TypeIndex
name|Index
argument_list|)
name|override
decl_stmt|;
name|StringRef
name|getTypeName
argument_list|(
name|TypeIndex
name|Index
argument_list|)
name|override
decl_stmt|;
name|bool
name|contains
argument_list|(
name|TypeIndex
name|Index
argument_list|)
name|override
decl_stmt|;
name|uint32_t
name|size
argument_list|()
name|override
expr_stmt|;
name|uint32_t
name|capacity
argument_list|()
name|override
expr_stmt|;
name|Optional
operator|<
name|TypeIndex
operator|>
name|getFirst
argument_list|()
name|override
expr_stmt|;
name|Optional
operator|<
name|TypeIndex
operator|>
name|getNext
argument_list|(
argument|TypeIndex Prev
argument_list|)
name|override
expr_stmt|;
name|private
label|:
name|Error
name|ensureTypeExists
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
function_decl|;
name|void
name|ensureCapacityFor
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
function_decl|;
name|Error
name|visitRangeForType
parameter_list|(
name|TypeIndex
name|TI
parameter_list|)
function_decl|;
name|Error
name|fullScanForType
parameter_list|(
name|TypeIndex
name|TI
parameter_list|)
function_decl|;
name|void
name|visitRange
parameter_list|(
name|TypeIndex
name|Begin
parameter_list|,
name|uint32_t
name|BeginOffset
parameter_list|,
name|TypeIndex
name|End
parameter_list|)
function_decl|;
comment|/// Number of actual records.
name|uint32_t
name|Count
init|=
literal|0
decl_stmt|;
comment|/// The largest type index which we've visited.
name|TypeIndex
name|LargestTypeIndex
init|=
name|TypeIndex
operator|::
name|None
argument_list|()
decl_stmt|;
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
name|StringSaver
name|NameStorage
decl_stmt|;
comment|/// The type array to allow random access visitation of.
name|CVTypeArray
name|Types
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|CacheEntry
operator|>
name|Records
expr_stmt|;
comment|/// An array of index offsets for the given type stream, allowing log(N)
comment|/// lookups of a type record by index.  Similar to KnownOffsets but only
comment|/// contains offsets for some type indices, some of which may not have
comment|/// ever been visited.
name|PartialOffsetArray
name|PartialOffsets
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace codeview
end_comment

begin_comment
unit|}
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

