begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DirectoryStreamData.h ---------------------------------- *- C++ --*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_DIRECTORYSTREAMDATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_DIRECTORYSTREAMDATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/IPDBStreamData.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/PDBFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|IPDBFile
decl_stmt|;
name|class
name|DirectoryStreamData
range|:
name|public
name|IPDBStreamData
block|{
name|public
operator|:
name|DirectoryStreamData
argument_list|(
specifier|const
name|PDBFile
operator|&
name|File
argument_list|)
operator|:
name|File
argument_list|(
argument|File
argument_list|)
block|{}
name|virtual
name|uint32_t
name|getLength
argument_list|()
block|{
return|return
name|File
operator|.
name|getNumDirectoryBytes
argument_list|()
return|;
block|}
name|virtual
name|llvm
operator|::
name|ArrayRef
operator|<
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
operator|>
name|getStreamBlocks
argument_list|()
block|{
return|return
name|File
operator|.
name|getDirectoryBlockArray
argument_list|()
return|;
block|}
name|private
operator|:
specifier|const
name|PDBFile
operator|&
name|File
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

