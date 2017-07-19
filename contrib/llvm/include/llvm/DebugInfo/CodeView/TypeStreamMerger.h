begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeStreamMerger.h ---------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
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
name|TypeIndex
decl_stmt|;
name|class
name|TypeTableBuilder
decl_stmt|;
comment|/// \brief Merge one set of type records into another.  This method assumes
comment|/// that all records are type records, and there are no Id records present.
comment|///
comment|/// \param Dest The table to store the re-written type records into.
comment|///
comment|/// \param SourceToDest A vector, indexed by the TypeIndex in the source
comment|/// type stream, that contains the index of the corresponding type record
comment|/// in the destination stream.
comment|///
comment|/// \param Types The collection of types to merge in.
comment|///
comment|/// \returns Error::success() if the operation succeeded, otherwise an
comment|/// appropriate error code.
name|Error
name|mergeTypeRecords
argument_list|(
name|TypeTableBuilder
operator|&
name|Dest
argument_list|,
name|SmallVectorImpl
operator|<
name|TypeIndex
operator|>
operator|&
name|SourceToDest
argument_list|,
specifier|const
name|CVTypeArray
operator|&
name|Types
argument_list|)
decl_stmt|;
comment|/// \brief Merge one set of id records into another.  This method assumes
comment|/// that all records are id records, and there are no Type records present.
comment|/// However, since Id records can refer back to Type records, this method
comment|/// assumes that the referenced type records have also been merged into
comment|/// another type stream (for example using the above method), and accepts
comment|/// the mapping from source to dest for that stream so that it can re-write
comment|/// the type record mappings accordingly.
comment|///
comment|/// \param Dest The table to store the re-written id records into.
comment|///
comment|/// \param Types The mapping to use for the type records that these id
comment|/// records refer to.
comment|///
comment|/// \param SourceToDest A vector, indexed by the TypeIndex in the source
comment|/// id stream, that contains the index of the corresponding id record
comment|/// in the destination stream.
comment|///
comment|/// \param Ids The collection of id records to merge in.
comment|///
comment|/// \returns Error::success() if the operation succeeded, otherwise an
comment|/// appropriate error code.
name|Error
name|mergeIdRecords
argument_list|(
name|TypeTableBuilder
operator|&
name|Dest
argument_list|,
name|ArrayRef
operator|<
name|TypeIndex
operator|>
name|Types
argument_list|,
name|SmallVectorImpl
operator|<
name|TypeIndex
operator|>
operator|&
name|SourceToDest
argument_list|,
specifier|const
name|CVTypeArray
operator|&
name|Ids
argument_list|)
decl_stmt|;
comment|/// \brief Merge a unified set of type and id records, splitting them into
comment|/// separate output streams.
comment|///
comment|/// \param DestIds The table to store the re-written id records into.
comment|///
comment|/// \param DestTypes the table to store the re-written type records into.
comment|///
comment|/// \param SourceToDest A vector, indexed by the TypeIndex in the source
comment|/// id stream, that contains the index of the corresponding id record
comment|/// in the destination stream.
comment|///
comment|/// \param IdsAndTypes The collection of id records to merge in.
comment|///
comment|/// \returns Error::success() if the operation succeeded, otherwise an
comment|/// appropriate error code.
name|Error
name|mergeTypeAndIdRecords
argument_list|(
name|TypeTableBuilder
operator|&
name|DestIds
argument_list|,
name|TypeTableBuilder
operator|&
name|DestTypes
argument_list|,
name|SmallVectorImpl
operator|<
name|TypeIndex
operator|>
operator|&
name|SourceToDest
argument_list|,
specifier|const
name|CVTypeArray
operator|&
name|IdsAndTypes
argument_list|)
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
comment|// LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_comment

end_unit

