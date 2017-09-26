begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PublicsStreamBuilder.h - PDB Publics Stream Creation -----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBPUBLICSTREAMBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBPUBLICSTREAMBUILDER_H
end_define

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
file|"llvm/Support/BinaryByteStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamWriter.h"
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
name|msf
block|{
name|class
name|MSFBuilder
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|PublicsStream
decl_stmt|;
struct_decl|struct
name|PublicsStreamHeader
struct_decl|;
name|class
name|PublicsStreamBuilder
block|{
name|public
label|:
name|explicit
name|PublicsStreamBuilder
argument_list|(
name|msf
operator|::
name|MSFBuilder
operator|&
name|Msf
argument_list|)
decl_stmt|;
operator|~
name|PublicsStreamBuilder
argument_list|()
expr_stmt|;
name|PublicsStreamBuilder
argument_list|(
specifier|const
name|PublicsStreamBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|PublicsStreamBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PublicsStreamBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|Error
name|finalizeMsfLayout
parameter_list|()
function_decl|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|commit
parameter_list|(
name|BinaryStreamWriter
modifier|&
name|PublicsWriter
parameter_list|)
function_decl|;
name|uint32_t
name|getStreamIndex
argument_list|()
specifier|const
block|{
return|return
name|StreamIdx
return|;
block|}
name|uint32_t
name|getRecordStreamIdx
argument_list|()
specifier|const
block|{
return|return
name|RecordStreamIdx
return|;
block|}
name|private
label|:
name|uint32_t
name|StreamIdx
init|=
name|kInvalidStreamIndex
decl_stmt|;
name|uint32_t
name|RecordStreamIdx
init|=
name|kInvalidStreamIndex
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|PSHashRecord
operator|>
name|HashRecords
expr_stmt|;
name|msf
operator|::
name|MSFBuilder
operator|&
name|Msf
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

