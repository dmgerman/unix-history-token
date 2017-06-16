begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBStringTable.h - PDB String Table -----------------------*- C++-*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBSTRINGTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBSTRINGTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugStringTableSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
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
name|class
name|BinaryStreamReader
decl_stmt|;
name|namespace
name|msf
block|{
name|class
name|MappedBlockStream
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
struct_decl|struct
name|PDBStringTableHeader
struct_decl|;
name|class
name|PDBStringTable
block|{
name|public
label|:
name|Error
name|reload
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
name|uint32_t
name|getByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getNameCount
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getHashVersion
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getSignature
argument_list|()
specifier|const
expr_stmt|;
name|Expected
operator|<
name|StringRef
operator|>
name|getStringForID
argument_list|(
argument|uint32_t ID
argument_list|)
specifier|const
expr_stmt|;
name|Expected
operator|<
name|uint32_t
operator|>
name|getIDForString
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
expr_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|name_ids
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|codeview
operator|::
name|DebugStringTableSubsectionRef
operator|&
name|getStringTable
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Error
name|readHeader
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
name|Error
name|readStrings
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
name|Error
name|readHashTable
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
name|Error
name|readEpilogue
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
specifier|const
name|PDBStringTableHeader
modifier|*
name|Header
init|=
name|nullptr
decl_stmt|;
name|codeview
operator|::
name|DebugStringTableSubsectionRef
name|Strings
expr_stmt|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|IDs
expr_stmt|;
name|uint32_t
name|ByteSize
init|=
literal|0
decl_stmt|;
name|uint32_t
name|NameCount
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace pdb
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
comment|// LLVM_DEBUGINFO_PDB_RAW_STRINGTABLE_H
end_comment

end_unit

