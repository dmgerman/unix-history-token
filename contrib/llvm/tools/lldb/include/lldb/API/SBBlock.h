begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBBlock.h -----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBBlock_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBBlock_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBFrame.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBTarget.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBValueList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBBlock
block|{
name|public
label|:
name|SBBlock
argument_list|()
expr_stmt|;
name|SBBlock
argument_list|(
specifier|const
name|lldb
operator|::
name|SBBlock
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBBlock
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBBlock
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBBlock
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsInlined
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetInlinedName
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBFileSpec
name|GetInlinedCallSiteFile
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetInlinedCallSiteLine
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetInlinedCallSiteColumn
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBBlock
name|GetParent
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBBlock
name|GetSibling
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBBlock
name|GetFirstChild
argument_list|()
expr_stmt|;
name|uint32_t
name|GetNumRanges
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBAddress
name|GetRangeStartAddress
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBAddress
name|GetRangeEndAddress
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
name|uint32_t
name|GetRangeIndexForBlockAddress
argument_list|(
name|lldb
operator|::
name|SBAddress
name|block_addr
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SBValueList
name|GetVariables
argument_list|(
argument|lldb::SBFrame& frame
argument_list|,
argument|bool arguments
argument_list|,
argument|bool locals
argument_list|,
argument|bool statics
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBValueList
name|GetVariables
argument_list|(
argument|lldb::SBTarget& target
argument_list|,
argument|bool arguments
argument_list|,
argument|bool locals
argument_list|,
argument|bool statics
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the inlined block that contains this block.
comment|///
comment|/// @return
comment|///     If this block is inlined, it will return this block, else
comment|///     parent blocks will be searched to see if any contain this
comment|///     block and are themselves inlined. An invalid SBBlock will
comment|///     be returned if this block nor any parent blocks are inlined
comment|///     function blocks.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBBlock
name|GetContainingInlinedBlock
argument_list|()
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBFunction
decl_stmt|;
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
name|lldb_private
operator|::
name|Block
operator|*
name|GetPtr
argument_list|()
expr_stmt|;
name|void
name|SetPtr
argument_list|(
name|lldb_private
operator|::
name|Block
operator|*
name|lldb_object_ptr
argument_list|)
decl_stmt|;
name|SBBlock
argument_list|(
name|lldb_private
operator|::
name|Block
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
name|void
name|AppendVariables
argument_list|(
name|bool
name|can_create
argument_list|,
name|bool
name|get_parent_variables
argument_list|,
name|lldb_private
operator|::
name|VariableList
operator|*
name|var_list
argument_list|)
decl_stmt|;
name|lldb_private
operator|::
name|Block
operator|*
name|m_opaque_ptr
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBBlock_h_
end_comment

end_unit

