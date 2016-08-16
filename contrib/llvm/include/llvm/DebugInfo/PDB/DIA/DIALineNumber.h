begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIALineNumber.h - DIA implementation of IPDBLineNumber ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIALINENUMBER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIALINENUMBER_H
end_define

begin_include
include|#
directive|include
file|"DIASupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBLineNumber.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|DIALineNumber
range|:
name|public
name|IPDBLineNumber
block|{
name|public
operator|:
name|explicit
name|DIALineNumber
argument_list|(
name|CComPtr
operator|<
name|IDiaLineNumber
operator|>
name|DiaLineNumber
argument_list|)
block|;
name|uint32_t
name|getLineNumber
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getLineNumberEnd
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getColumnNumber
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getColumnNumberEnd
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getAddressSection
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getAddressOffset
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getRelativeVirtualAddress
argument_list|()
specifier|const
name|override
block|;
name|uint64_t
name|getVirtualAddress
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getLength
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getSourceFileId
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|getCompilandId
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isStatement
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|CComPtr
operator|<
name|IDiaLineNumber
operator|>
name|LineNumber
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

