begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextHistory.h ----------------------------------------*- C++ -*-===//
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
name|lldb_RegisterContextHistory_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterContextHistory_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegisterContextHistory
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|RegisterContextHistory
operator|>
name|SharedPtr
expr_stmt|;
name|RegisterContextHistory
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|uint32_t address_byte_size
argument_list|,
argument|lldb::addr_t pc_value
argument_list|)
decl_stmt|;
comment|///
comment|// pure virtual functions from the base class that we must implement
comment|///
name|virtual
operator|~
name|RegisterContextHistory
argument_list|()
expr_stmt|;
name|virtual
name|void
name|InvalidateAllRegisters
parameter_list|()
function_decl|;
name|virtual
name|size_t
name|GetRegisterCount
parameter_list|()
function_decl|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
expr_stmt|;
name|virtual
name|size_t
name|GetRegisterSetCount
parameter_list|()
function_decl|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
expr_stmt|;
name|virtual
name|bool
name|ReadRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|WriteRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|ReadAllRegisterValues
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|WriteAllRegisterValues
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
decl_stmt|;
name|virtual
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
parameter_list|(
name|uint32_t
name|kind
parameter_list|,
name|uint32_t
name|num
parameter_list|)
function_decl|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For RegisterContextLLDB only
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|RegisterSet
name|m_reg_set0
expr_stmt|;
comment|// register set 0 (PC only)
name|lldb_private
operator|::
name|RegisterInfo
name|m_pc_reg_info
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_pc_value
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContextHistory
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_RegisterContextHistory_h_
end_comment

end_unit

