begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextThreadMemory.h ---------------------------*- C++ -*-===//
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
name|lldb_RegisterContextThreadMemory_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterContextThreadMemory_h_
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
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|RegisterContextThreadMemory
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextThreadMemory
argument_list|(
argument|Thread&thread
argument_list|,
argument|lldb::addr_t register_data_addr
argument_list|)
block|;
operator|~
name|RegisterContextThreadMemory
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
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
name|override
block|;
name|bool
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|bool
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|;
comment|// These two functions are used to implement "push" and "pop" of register
comment|// states.  They are used primarily
comment|// for expression evaluation, where we need to push a new state (storing the
comment|// old one in data_sp) and then
comment|// restoring the original state by passing the data_sp we got from
comment|// ReadAllRegisters to WriteAllRegisterValues.
comment|// ReadAllRegisters will do what is necessary to return a coherent set of
comment|// register values for this thread, which
comment|// may mean e.g. interrupting a thread that is sitting in a kernel trap.  That
comment|// is a somewhat disruptive operation,
comment|// so these API's should only be used when this behavior is needed.
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
name|bool
name|CopyFromRegisterContext
argument_list|(
argument|lldb::RegisterContextSP context
argument_list|)
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
name|uint32_t
name|NumSupportedHardwareBreakpoints
argument_list|()
name|override
block|;
name|uint32_t
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
name|override
block|;
name|bool
name|ClearHardwareBreakpoint
argument_list|(
argument|uint32_t hw_idx
argument_list|)
name|override
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
name|override
block|;
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
name|override
block|;
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t hw_index
argument_list|)
name|override
block|;
name|bool
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
name|override
block|;
name|Status
name|ReadRegisterValueFromMemory
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb::addr_t src_addr
argument_list|,
argument|uint32_t src_len
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Status
name|WriteRegisterValueToMemory
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb::addr_t dst_addr
argument_list|,
argument|uint32_t dst_len
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|UpdateRegisterContext
argument_list|()
block|;
name|lldb
operator|::
name|ThreadWP
name|m_thread_wp
block|;
name|lldb
operator|::
name|RegisterContextSP
name|m_reg_ctx_sp
block|;
name|lldb
operator|::
name|addr_t
name|m_register_data_addr
block|;
name|uint32_t
name|m_stop_id
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContextThreadMemory
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_RegisterContextThreadMemory_h_
end_comment

end_unit

