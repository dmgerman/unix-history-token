begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- DIAEnumSourceFiles.h - DIA Source File Enumerator impl -----*- C++ -*-==//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIAENUMSOURCEFILES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIAENUMSOURCEFILES_H
end_define

begin_include
include|#
directive|include
file|"DIASupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBEnumChildren.h"
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
name|DIAEnumSourceFiles
range|:
name|public
name|IPDBEnumChildren
operator|<
name|IPDBSourceFile
operator|>
block|{
name|public
operator|:
name|explicit
name|DIAEnumSourceFiles
argument_list|(
specifier|const
name|DIASession
operator|&
name|PDBSession
argument_list|,
name|CComPtr
operator|<
name|IDiaEnumSourceFiles
operator|>
name|DiaEnumerator
argument_list|)
block|;
name|uint32_t
name|getChildCount
argument_list|()
specifier|const
name|override
block|;
name|ChildTypePtr
name|getChildAtIndex
argument_list|(
argument|uint32_t Index
argument_list|)
specifier|const
name|override
block|;
name|ChildTypePtr
name|getNext
argument_list|()
name|override
block|;
name|void
name|reset
argument_list|()
name|override
block|;
name|DIAEnumSourceFiles
operator|*
name|clone
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
specifier|const
name|DIASession
operator|&
name|Session
block|;
name|CComPtr
operator|<
name|IDiaEnumSourceFiles
operator|>
name|Enumerator
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

