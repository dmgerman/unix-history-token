begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIASourceFile.h - DIA implementation of IPDBSourceFile ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIASOURCEFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIASOURCEFILE_H
end_define

begin_include
include|#
directive|include
file|"DIASupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBSourceFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|DIASession
decl_stmt|;
name|class
name|DIASourceFile
range|:
name|public
name|IPDBSourceFile
block|{
name|public
operator|:
name|explicit
name|DIASourceFile
argument_list|(
specifier|const
name|DIASession
operator|&
name|Session
argument_list|,
name|CComPtr
operator|<
name|IDiaSourceFile
operator|>
name|DiaSourceFile
argument_list|)
block|;
name|std
operator|::
name|string
name|getFileName
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getUniqueId
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getChecksum
argument_list|()
specifier|const
name|override
block|;
name|PDB_Checksum
name|getChecksumType
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumChildren
operator|<
name|PDBSymbolCompiland
operator|>>
name|getCompilands
argument_list|()
specifier|const
name|override
block|;
name|CComPtr
operator|<
name|IDiaSourceFile
operator|>
name|getDiaFile
argument_list|()
specifier|const
block|{
return|return
name|SourceFile
return|;
block|}
name|private
operator|:
specifier|const
name|DIASession
operator|&
name|Session
block|;
name|CComPtr
operator|<
name|IDiaSourceFile
operator|>
name|SourceFile
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

