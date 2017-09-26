begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GlobalsStream.h - PDB Index of Symbols by Name ------ ----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_GLOBALS_STREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_GLOBALS_STREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/MappedBlockStream.h"
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
file|"llvm/DebugInfo/PDB/PDBTypes.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|DbiStream
decl_stmt|;
name|class
name|PDBFile
decl_stmt|;
name|class
name|GlobalsStream
block|{
name|public
label|:
name|explicit
name|GlobalsStream
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
decl_stmt|;
operator|~
name|GlobalsStream
argument_list|()
expr_stmt|;
name|Error
name|commit
parameter_list|()
function_decl|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|getHashBuckets
argument_list|()
specifier|const
block|{
return|return
name|HashBuckets
return|;
block|}
name|uint32_t
name|getNumBuckets
argument_list|()
specifier|const
block|{
return|return
name|NumBuckets
return|;
block|}
name|Error
name|reload
parameter_list|()
function_decl|;
name|private
label|:
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|HashBuckets
expr_stmt|;
name|FixedStreamArray
operator|<
name|PSHashRecord
operator|>
name|HashRecords
expr_stmt|;
name|uint32_t
name|NumBuckets
decl_stmt|;
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

