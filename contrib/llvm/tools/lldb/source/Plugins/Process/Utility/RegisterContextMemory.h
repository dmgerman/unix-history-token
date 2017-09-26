begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextMemory.h ---------------------------------*- C++ -*-===//
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
name|lldb_RegisterContextMemory_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterContextMemory_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|DynamicRegisterInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextMemory
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextMemory
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|DynamicRegisterInfo&reg_info
argument_list|,
argument|lldb::addr_t reg_data_addr
argument_list|)
block|;
operator|~
name|RegisterContextMemory
argument_list|()
name|override
block|;
name|void
name|InvalidateAllRegisters
argument_list|()
name|override
block|;
name|size_t
name|GetRegisterCount
argument_list|()
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
name|override
block|;
name|size_t
name|GetRegisterSetCount
argument_list|()
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
name|override
block|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// If all of the thread register are in a contiguous buffer in
comment|// memory, then the default ReadRegister/WriteRegister and
comment|// ReadAllRegisterValues/WriteAllRegisterValues will work. If thread
comment|// registers are not contiguous, clients will want to subclass this
comment|// class and modify the read/write functions as needed.
comment|//------------------------------------------------------------------
name|bool
name|ReadRegister
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb_private::RegisterValue&reg_value
argument_list|)
name|override
block|;
name|bool
name|WriteRegister
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|const lldb_private::RegisterValue&reg_value
argument_list|)
name|override
block|;
name|bool
name|ReadAllRegisterValues
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|bool
name|WriteAllRegisterValues
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|void
name|SetAllRegisterData
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
block|;
name|protected
operator|:
name|void
name|SetAllRegisterValid
argument_list|(
argument|bool b
argument_list|)
block|;
name|DynamicRegisterInfo
operator|&
name|m_reg_infos
block|;
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|m_reg_valid
block|;
name|lldb_private
operator|::
name|DataExtractor
name|m_reg_data
block|;
name|lldb
operator|::
name|addr_t
name|m_reg_data_addr
block|;
comment|// If this is valid, then we have a register
comment|// context that is stored in memmory
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContextMemory
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_RegisterContextMemory_h_
end_comment

end_unit

