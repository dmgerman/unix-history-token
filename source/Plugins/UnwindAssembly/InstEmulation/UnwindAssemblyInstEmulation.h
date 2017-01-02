begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UnwindAssemblyInstEmulation.h ---------------------------*- C++ -*-===//
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
name|liblldb_UnwindAssemblyInstEmulation_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UnwindAssemblyInstEmulation_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/EmulateInstruction.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RegisterValue.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/UnwindPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/UnwindAssembly.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|UnwindAssemblyInstEmulation
range|:
name|public
name|lldb_private
operator|::
name|UnwindAssembly
block|{
name|public
operator|:
operator|~
name|UnwindAssemblyInstEmulation
argument_list|()
name|override
operator|=
expr|default
block|;
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
argument_list|(
argument|lldb_private::AddressRange&func
argument_list|,
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
name|override
block|;
name|bool
name|GetNonCallSiteUnwindPlanFromAssembly
argument_list|(
argument|lldb_private::AddressRange&func
argument_list|,
argument|uint8_t *opcode_data
argument_list|,
argument|size_t opcode_size
argument_list|,
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
block|;
name|bool
name|AugmentUnwindPlanFromCallSite
argument_list|(
argument|lldb_private::AddressRange&func
argument_list|,
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
name|override
block|;
name|bool
name|GetFastUnwindPlan
argument_list|(
argument|lldb_private::AddressRange&func
argument_list|,
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
name|override
block|;
comment|// thread may be NULL in which case we only use the Target (e.g. if this is
comment|// called pre-process-launch).
name|bool
name|FirstNonPrologueInsn
argument_list|(
argument|lldb_private::AddressRange&func
argument_list|,
argument|const lldb_private::ExecutionContext&exe_ctx
argument_list|,
argument|lldb_private::Address&first_non_prologue_insn
argument_list|)
name|override
block|;
specifier|static
name|lldb_private
operator|::
name|UnwindAssembly
operator|*
name|CreateInstance
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|private
operator|:
comment|// Call CreateInstance to get an instance of this class
name|UnwindAssemblyInstEmulation
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
name|lldb_private
operator|::
name|EmulateInstruction
operator|*
name|inst_emulator
argument_list|)
operator|:
name|UnwindAssembly
argument_list|(
name|arch
argument_list|)
block|,
name|m_inst_emulator_ap
argument_list|(
name|inst_emulator
argument_list|)
block|,
name|m_range_ptr
argument_list|(
name|NULL
argument_list|)
block|,
name|m_unwind_plan_ptr
argument_list|(
name|NULL
argument_list|)
block|,
name|m_curr_row
argument_list|()
block|,
name|m_cfa_reg_info
argument_list|()
block|,
name|m_fp_is_cfa
argument_list|(
name|false
argument_list|)
block|,
name|m_register_values
argument_list|()
block|,
name|m_pushed_regs
argument_list|()
block|,
name|m_curr_row_modified
argument_list|(
name|false
argument_list|)
block|,
name|m_forward_branch_offset
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|m_inst_emulator_ap
operator|.
name|get
argument_list|()
condition|)
block|{
name|m_inst_emulator_ap
operator|->
name|SetBaton
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_inst_emulator_ap
operator|->
name|SetCallbacks
argument_list|(
name|ReadMemory
argument_list|,
name|WriteMemory
argument_list|,
name|ReadRegister
argument_list|,
name|WriteRegister
argument_list|)
expr_stmt|;
block|}
block|}
specifier|static
name|size_t
name|ReadMemory
argument_list|(
argument|lldb_private::EmulateInstruction *instruction
argument_list|,
argument|void *baton
argument_list|,
argument|const lldb_private::EmulateInstruction::Context&context
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|void *dst
argument_list|,
argument|size_t length
argument_list|)
block|;
specifier|static
name|size_t
name|WriteMemory
argument_list|(
argument|lldb_private::EmulateInstruction *instruction
argument_list|,
argument|void *baton
argument_list|,
argument|const lldb_private::EmulateInstruction::Context&context
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|const void *dst
argument_list|,
argument|size_t length
argument_list|)
block|;
specifier|static
name|bool
name|ReadRegister
argument_list|(
name|lldb_private
operator|::
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
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
name|reg_value
argument_list|)
block|;
specifier|static
name|bool
name|WriteRegister
argument_list|(
name|lldb_private
operator|::
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
name|void
operator|*
name|baton
argument_list|,
specifier|const
name|lldb_private
operator|::
name|EmulateInstruction
operator|::
name|Context
operator|&
name|context
argument_list|,
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
name|reg_value
argument_list|)
block|;
comment|//    size_t
comment|//    ReadMemory (lldb_private::EmulateInstruction *instruction,
comment|//                const lldb_private::EmulateInstruction::Context&context,
comment|//                lldb::addr_t addr,
comment|//                void *dst,
comment|//                size_t length);
name|size_t
name|WriteMemory
argument_list|(
argument|lldb_private::EmulateInstruction *instruction
argument_list|,
argument|const lldb_private::EmulateInstruction::Context&context
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|const void *dst
argument_list|,
argument|size_t length
argument_list|)
block|;
name|bool
name|ReadRegister
argument_list|(
name|lldb_private
operator|::
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
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
name|reg_value
argument_list|)
block|;
name|bool
name|WriteRegister
argument_list|(
name|lldb_private
operator|::
name|EmulateInstruction
operator|*
name|instruction
argument_list|,
specifier|const
name|lldb_private
operator|::
name|EmulateInstruction
operator|::
name|Context
operator|&
name|context
argument_list|,
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
name|reg_value
argument_list|)
block|;
specifier|static
name|uint64_t
name|MakeRegisterKindValuePair
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|&
name|reg_info
argument_list|)
block|;
name|void
name|SetRegisterValue
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|&
name|reg_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|reg_value
argument_list|)
block|;
name|bool
name|GetRegisterValue
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|&
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|reg_value
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|EmulateInstruction
operator|>
name|m_inst_emulator_ap
block|;
name|lldb_private
operator|::
name|AddressRange
operator|*
name|m_range_ptr
block|;
name|lldb_private
operator|::
name|UnwindPlan
operator|*
name|m_unwind_plan_ptr
block|;
name|lldb_private
operator|::
name|UnwindPlan
operator|::
name|RowSP
name|m_curr_row
block|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|uint64_t
operator|>
name|PushedRegisterToAddrMap
expr_stmt|;
name|uint64_t
name|m_initial_sp
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|RegisterInfo
name|m_cfa_reg_info
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_fp_is_cfa
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|lldb_private
operator|::
name|RegisterValue
operator|>
name|RegisterValueMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|RegisterValueMap
name|m_register_values
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PushedRegisterToAddrMap
name|m_pushed_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|// While processing the instruction stream, we need to communicate some state
end_comment

begin_comment
comment|// change
end_comment

begin_comment
comment|// information up to the higher level loop that makes decisions about how to
end_comment

begin_comment
comment|// push
end_comment

begin_comment
comment|// the unwind instructions for the UnwindPlan we're constructing.
end_comment

begin_comment
comment|// The instruction we're processing updated the UnwindPlan::Row contents
end_comment

begin_decl_stmt
name|bool
name|m_curr_row_modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The instruction is branching forward with the given offset. 0 value means
end_comment

begin_comment
comment|// no branching.
end_comment

begin_decl_stmt
name|uint32_t
name|m_forward_branch_offset
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_UnwindAssemblyInstEmulation_h_
end_comment

end_unit

