begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InfoStream.h - PDB Info Stream (Stream 1) Access ---------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBINFOSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBINFOSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitmaskEnum.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/MappedBlockStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NamedStreamMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawConstants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
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
name|pdb
block|{
name|class
name|InfoStreamBuilder
decl_stmt|;
name|class
name|PDBFile
decl_stmt|;
name|class
name|InfoStream
block|{
name|friend
name|class
name|InfoStreamBuilder
decl_stmt|;
name|public
label|:
name|InfoStream
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|msf
operator|::
name|MappedBlockStream
operator|>
name|Stream
argument_list|)
expr_stmt|;
name|Error
name|reload
parameter_list|()
function_decl|;
name|uint32_t
name|getStreamSize
argument_list|()
specifier|const
expr_stmt|;
name|PdbRaw_ImplVer
name|getVersion
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getSignature
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getAge
argument_list|()
specifier|const
expr_stmt|;
name|PDB_UniqueId
name|getGuid
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getNamedStreamMapByteSize
argument_list|()
specifier|const
expr_stmt|;
name|PdbRaw_Features
name|getFeatures
argument_list|()
specifier|const
expr_stmt|;
name|ArrayRef
operator|<
name|PdbRaw_FeatureSig
operator|>
name|getFeatureSignatures
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|NamedStreamMap
operator|&
name|getNamedStreams
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getNamedStreamIndex
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|iterator_range
operator|<
name|StringMapConstIterator
operator|<
name|uint32_t
operator|>>
name|named_streams
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|msf
operator|::
name|MappedBlockStream
operator|>
name|Stream
expr_stmt|;
comment|// PDB file format version.  We only support VC70.  See the enumeration
comment|// `PdbRaw_ImplVer` for the other possible values.
name|uint32_t
name|Version
decl_stmt|;
comment|// A 32-bit signature unique across all PDBs.  This is generated with
comment|// a call to time() when the PDB is written, but obviously this is not
comment|// universally unique.
name|uint32_t
name|Signature
decl_stmt|;
comment|// The number of times the PDB has been written.  Might also be used to
comment|// ensure that the PDB matches the executable.
name|uint32_t
name|Age
decl_stmt|;
comment|// Due to the aforementioned limitations with `Signature`, this is a new
comment|// signature present on VC70 and higher PDBs which is guaranteed to be
comment|// universally unique.
name|PDB_UniqueId
name|Guid
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|PdbRaw_FeatureSig
operator|>
name|FeatureSignatures
expr_stmt|;
name|PdbRaw_Features
name|Features
init|=
name|PdbFeatureNone
decl_stmt|;
name|uint32_t
name|NamedStreamMapByteSize
init|=
literal|0
decl_stmt|;
name|NamedStreamMap
name|NamedStreams
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

