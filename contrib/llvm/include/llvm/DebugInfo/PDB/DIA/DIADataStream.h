begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIADataStream.h - DIA implementation of IPDBDataStream ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_DIA_DIADATASTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_DIA_DIADATASTREAM_H
end_define

begin_include
include|#
directive|include
file|"DIASupport.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBDataStream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|DIADataStream
range|:
name|public
name|IPDBDataStream
block|{
name|public
operator|:
name|explicit
name|DIADataStream
argument_list|(
name|CComPtr
operator|<
name|IDiaEnumDebugStreamData
operator|>
name|DiaStreamData
argument_list|)
block|;
name|uint32_t
name|getRecordCount
argument_list|()
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
name|override
block|;
name|llvm
operator|::
name|Optional
operator|<
name|RecordType
operator|>
name|getItemAtIndex
argument_list|(
argument|uint32_t Index
argument_list|)
specifier|const
name|override
block|;
name|bool
name|getNext
argument_list|(
argument|RecordType&Record
argument_list|)
name|override
block|;
name|void
name|reset
argument_list|()
name|override
block|;
name|DIADataStream
operator|*
name|clone
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|CComPtr
operator|<
name|IDiaEnumDebugStreamData
operator|>
name|StreamData
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

