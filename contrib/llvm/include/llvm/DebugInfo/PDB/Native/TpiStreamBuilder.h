begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TpiStreamBuilder.h - PDB Tpi Stream Creation -------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBTPISTREAMBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBTPISTREAMBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawConstants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryByteStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryItemStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
name|class
name|BinaryByteStream
decl_stmt|;
name|class
name|WritableBinaryStreamRef
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|BinaryItemTraits
operator|<
name|llvm
operator|::
name|codeview
operator|::
name|CVType
operator|>
block|{
specifier|static
name|size_t
name|length
argument_list|(
argument|const codeview::CVType&Item
argument_list|)
block|{
return|return
name|Item
operator|.
name|length
argument_list|()
return|;
block|}
specifier|static
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|bytes
argument_list|(
argument|const codeview::CVType&Item
argument_list|)
block|{
return|return
name|Item
operator|.
name|data
argument_list|()
return|;
block|}
expr|}
block|;
name|namespace
name|codeview
block|{
name|class
name|TypeRecord
block|; }
name|namespace
name|msf
block|{
name|class
name|MSFBuilder
block|; struct
name|MSFLayout
block|; }
name|namespace
name|pdb
block|{
name|class
name|PDBFile
block|;
name|class
name|TpiStream
block|; struct
name|TpiStreamHeader
block|;
name|class
name|TpiStreamBuilder
block|{
name|public
operator|:
name|explicit
name|TpiStreamBuilder
argument_list|(
argument|msf::MSFBuilder&Msf
argument_list|,
argument|uint32_t StreamIdx
argument_list|)
block|;
operator|~
name|TpiStreamBuilder
argument_list|()
block|;
name|TpiStreamBuilder
argument_list|(
specifier|const
name|TpiStreamBuilder
operator|&
argument_list|)
operator|=
name|delete
block|;
name|TpiStreamBuilder
operator|&
name|operator
operator|=
operator|(
specifier|const
name|TpiStreamBuilder
operator|&
operator|)
operator|=
name|delete
block|;
name|void
name|setVersionHeader
argument_list|(
argument|PdbRaw_TpiVer Version
argument_list|)
block|;
name|void
name|addTypeRecord
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Type
argument_list|,
name|Optional
operator|<
name|uint32_t
operator|>
name|Hash
argument_list|)
block|;
name|Error
name|finalizeMsfLayout
argument_list|()
block|;
name|Error
name|commit
argument_list|(
argument|const msf::MSFLayout&Layout
argument_list|,
argument|WritableBinaryStreamRef Buffer
argument_list|)
block|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
block|;
name|private
operator|:
name|uint32_t
name|calculateHashBufferSize
argument_list|()
specifier|const
block|;
name|uint32_t
name|calculateIndexOffsetSize
argument_list|()
specifier|const
block|;
name|Error
name|finalize
argument_list|()
block|;
name|msf
operator|::
name|MSFBuilder
operator|&
name|Msf
block|;
name|BumpPtrAllocator
operator|&
name|Allocator
block|;
name|size_t
name|TypeRecordBytes
operator|=
literal|0
block|;
name|Optional
operator|<
name|PdbRaw_TpiVer
operator|>
name|VerHeader
block|;
name|std
operator|::
name|vector
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|TypeRecords
block|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|TypeHashes
block|;
name|std
operator|::
name|vector
operator|<
name|TypeIndexOffset
operator|>
name|TypeIndexOffsets
block|;
name|uint32_t
name|HashStreamIndex
operator|=
name|kInvalidStreamIndex
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|BinaryByteStream
operator|>
name|HashValueStream
block|;
specifier|const
name|TpiStreamHeader
operator|*
name|Header
block|;
name|uint32_t
name|Idx
block|; }
block|; }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

