begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBStringTableBuilder.h - PDB String Table Builder -------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file creates the "/names" stream.
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBSTRINGTABLEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBSTRINGTABLEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|BinaryStreamWriter
decl_stmt|;
name|class
name|WritableBinaryStreamRef
decl_stmt|;
name|namespace
name|msf
block|{
struct_decl|struct
name|MSFLayout
struct_decl|;
block|}
name|namespace
name|pdb
block|{
name|class
name|PDBFileBuilder
decl_stmt|;
name|class
name|PDBStringTableBuilder
block|{
name|public
label|:
comment|// If string S does not exist in the string table, insert it.
comment|// Returns the ID for S.
name|uint32_t
name|insert
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|commit
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|codeview
operator|::
name|DebugStringTableSubsection
operator|&
name|getStrings
argument_list|()
block|{
return|return
name|Strings
return|;
block|}
specifier|const
name|codeview
operator|::
name|DebugStringTableSubsection
operator|&
name|getStrings
argument_list|()
specifier|const
block|{
return|return
name|Strings
return|;
block|}
name|private
label|:
name|uint32_t
name|calculateHashTableSize
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|writeHeader
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|Error
name|writeStrings
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|Error
name|writeHashTable
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|Error
name|writeEpilogue
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|codeview
operator|::
name|DebugStringTableSubsection
name|Strings
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_PDB_RAW_PDBSTRINGTABLEBUILDER_H
end_comment

end_unit

