begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RandomAccessTypeVisitor.h ------------------------------ *- C++ --*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_RANDOMACCESSTYPEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_RANDOMACCESSTYPEVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CVTypeVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDatabase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDatabaseVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDeserializer.h"
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
file|"llvm/DebugInfo/CodeView/TypeVisitorCallbackPipeline.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
decl_stmt|;
name|class
name|TypeServerHandler
decl_stmt|;
name|class
name|TypeVisitorCallbacks
decl_stmt|;
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
comment|/// RandomAccessTypeVisitor implements this algorithm, but additionally goes one
comment|/// step further by caching offsets of every record that has been visited at
comment|/// least once.  This way, even repeated visits of the same record will never
comment|/// require more than one linear scan.  For a type stream of N elements divided
comment|/// into M chunks of roughly equal size, this yields a worst case lookup time
comment|/// of O(N/M) and an amortized time of O(1).
name|class
name|RandomAccessTypeVisitor
block|{
typedef|typedef
name|FixedStreamArray
operator|<
name|TypeIndexOffset
operator|>
name|PartialOffsetArray
expr_stmt|;
name|public
label|:
name|RandomAccessTypeVisitor
argument_list|(
argument|const CVTypeArray&Types
argument_list|,
argument|uint32_t NumRecords
argument_list|,
argument|PartialOffsetArray PartialOffsets
argument_list|)
empty_stmt|;
name|Error
name|visitTypeIndex
parameter_list|(
name|TypeIndex
name|Index
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|)
function_decl|;
specifier|const
name|TypeDatabase
operator|&
name|database
argument_list|()
specifier|const
block|{
return|return
name|Database
return|;
block|}
name|private
label|:
name|Error
name|visitRangeForType
parameter_list|(
name|TypeIndex
name|TI
parameter_list|)
function_decl|;
name|Error
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
comment|/// Visited records get automatically added to the type database.
name|TypeDatabase
name|Database
decl_stmt|;
comment|/// The type array to allow random access visitation of.
specifier|const
name|CVTypeArray
modifier|&
name|Types
decl_stmt|;
comment|/// The database visitor which adds new records to the database.
name|TypeDatabaseVisitor
name|DatabaseVisitor
decl_stmt|;
comment|/// The deserializer which deserializes new records.
name|TypeDeserializer
name|Deserializer
decl_stmt|;
comment|/// The visitation callback pipeline to use.  By default this contains a
comment|/// deserializer and a type database visitor.  But the callback specified
comment|/// in the constructor is also added.
name|TypeVisitorCallbackPipeline
name|Pipeline
decl_stmt|;
comment|/// The visitor used to visit the internal pipeline for deserialization and
comment|/// database maintenance.
name|CVTypeVisitor
name|InternalVisitor
decl_stmt|;
comment|/// A vector mapping type indices to type offset.  For every record that has
comment|/// been visited, contains the absolute offset of that record in the record
comment|/// array.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|KnownOffsets
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
comment|// LLVM_DEBUGINFO_CODEVIEW_RANDOMACCESSTYPEVISITOR_H
end_comment

end_unit

