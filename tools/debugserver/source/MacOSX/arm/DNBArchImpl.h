begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBArchImpl.h -------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/25/07.
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
name|__DebugNubArchMachARM_h__
end_ifndef

begin_define
define|#
directive|define
name|__DebugNubArchMachARM_h__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"DNBArch.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|class
name|MachThread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DNBArchMachARM
range|:
name|public
name|DNBArchProtocol
block|{
name|public
operator|:
expr|enum
block|{
name|kMaxNumThumbITBreakpoints
operator|=
literal|4
block|}
block|;
name|DNBArchMachARM
argument_list|(
name|MachThread
operator|*
name|thread
argument_list|)
operator|:
name|m_thread
argument_list|(
name|thread
argument_list|)
block|,
name|m_state
argument_list|()
block|,
name|m_disabled_watchpoints
argument_list|()
block|,
name|m_hw_single_chained_step_addr
argument_list|(
name|INVALID_NUB_ADDRESS
argument_list|)
block|,
name|m_last_decode_pc
argument_list|(
name|INVALID_NUB_ADDRESS
argument_list|)
block|,
name|m_watchpoint_hw_index
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|m_watchpoint_did_occur
argument_list|(
name|false
argument_list|)
block|,
name|m_watchpoint_resume_single_step_enabled
argument_list|(
name|false
argument_list|)
block|,
name|m_saved_register_states
argument_list|()
block|{
name|m_disabled_watchpoints
operator|.
name|resize
argument_list|(
literal|16
argument_list|)
block|;
name|memset
argument_list|(
operator|&
name|m_dbg_save
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|m_dbg_save
argument_list|)
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|USE_ARM_DISASSEMBLER_FRAMEWORK
argument_list|)
name|ThumbStaticsInit
argument_list|(
operator|&
name|m_last_decode_thumb
argument_list|)
block|;
endif|#
directive|endif
block|}
name|virtual
operator|~
name|DNBArchMachARM
argument_list|()
block|{}
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
specifier|const
name|DNBRegisterSetInfo
operator|*
name|GetRegisterSetInfo
argument_list|(
name|nub_size_t
operator|*
name|num_reg_sets
argument_list|)
block|;
name|virtual
name|bool
name|GetRegisterValue
argument_list|(
argument|uint32_t set
argument_list|,
argument|uint32_t reg
argument_list|,
argument|DNBRegisterValue *value
argument_list|)
block|;
name|virtual
name|bool
name|SetRegisterValue
argument_list|(
argument|uint32_t set
argument_list|,
argument|uint32_t reg
argument_list|,
argument|const DNBRegisterValue *value
argument_list|)
block|;
name|virtual
name|nub_size_t
name|GetRegisterContext
argument_list|(
argument|void *buf
argument_list|,
argument|nub_size_t buf_len
argument_list|)
block|;
name|virtual
name|nub_size_t
name|SetRegisterContext
argument_list|(
argument|const void *buf
argument_list|,
argument|nub_size_t buf_len
argument_list|)
block|;
name|virtual
name|uint32_t
name|SaveRegisterState
argument_list|()
block|;
name|virtual
name|bool
name|RestoreRegisterState
argument_list|(
argument|uint32_t save_id
argument_list|)
block|;
name|virtual
name|kern_return_t
name|GetRegisterState
argument_list|(
argument|int set
argument_list|,
argument|bool force
argument_list|)
block|;
name|virtual
name|kern_return_t
name|SetRegisterState
argument_list|(
argument|int set
argument_list|)
block|;
name|virtual
name|bool
name|RegisterSetStateIsValid
argument_list|(
argument|int set
argument_list|)
specifier|const
block|;
name|virtual
name|uint64_t
name|GetPC
argument_list|(
argument|uint64_t failValue
argument_list|)
block|;
comment|// Get program counter
name|virtual
name|kern_return_t
name|SetPC
argument_list|(
argument|uint64_t value
argument_list|)
block|;
name|virtual
name|uint64_t
name|GetSP
argument_list|(
argument|uint64_t failValue
argument_list|)
block|;
comment|// Get stack pointer
name|virtual
name|void
name|ThreadWillResume
argument_list|()
block|;
name|virtual
name|bool
name|ThreadDidStop
argument_list|()
block|;
name|virtual
name|bool
name|NotifyException
argument_list|(
name|MachException
operator|::
name|Data
operator|&
name|exc
argument_list|)
block|;
specifier|static
name|DNBArchProtocol
operator|*
name|Create
argument_list|(
name|MachThread
operator|*
name|thread
argument_list|)
block|;
specifier|static
specifier|const
name|uint8_t
operator|*
name|SoftwareBreakpointOpcode
argument_list|(
argument|nub_size_t byte_size
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetCPUType
argument_list|()
block|;
name|virtual
name|uint32_t
name|NumSupportedHardwareBreakpoints
argument_list|()
block|;
name|virtual
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
block|;
name|virtual
name|uint32_t
name|EnableHardwareBreakpoint
argument_list|(
argument|nub_addr_t addr
argument_list|,
argument|nub_size_t size
argument_list|)
block|;
name|virtual
name|bool
name|DisableHardwareBreakpoint
argument_list|(
argument|uint32_t hw_break_index
argument_list|)
block|;
name|virtual
name|uint32_t
name|EnableHardwareWatchpoint
argument_list|(
argument|nub_addr_t addr
argument_list|,
argument|nub_size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|bool also_set_on_task
argument_list|)
block|;
name|virtual
name|bool
name|DisableHardwareWatchpoint
argument_list|(
argument|uint32_t hw_break_index
argument_list|,
argument|bool also_set_on_task
argument_list|)
block|;
name|virtual
name|bool
name|DisableHardwareWatchpoint_helper
argument_list|(
argument|uint32_t hw_break_index
argument_list|,
argument|bool also_set_on_task
argument_list|)
block|;
name|virtual
name|bool
name|ReenableHardwareWatchpoint
argument_list|(
argument|uint32_t hw_break_index
argument_list|)
block|;
name|virtual
name|bool
name|ReenableHardwareWatchpoint_helper
argument_list|(
argument|uint32_t hw_break_index
argument_list|)
block|;
name|virtual
name|bool
name|StepNotComplete
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetHardwareWatchpointHit
argument_list|(
name|nub_addr_t
operator|&
name|addr
argument_list|)
block|;
if|#
directive|if
name|defined
argument_list|(
name|ARM_DEBUG_STATE32
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
operator|)
typedef|typedef
name|arm_debug_state32_t
name|DBG
typedef|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|arm_debug_state_t
name|DBG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_label
name|protected
label|:
end_label

begin_function_decl
name|kern_return_t
name|EnableHardwareSingleStep
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|SetSingleStepSoftwareBreakpoints
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ConditionPassed
parameter_list|(
name|uint8_t
name|condition
parameter_list|,
name|uint32_t
name|cpsr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ARM_DISASSEMBLER_FRAMEWORK
argument_list|)
end_if

begin_function_decl
name|bool
name|ComputeNextPC
parameter_list|(
name|nub_addr_t
name|currentPC
parameter_list|,
name|arm_decoded_instruction_t
name|decodedInstruction
parameter_list|,
name|bool
name|currentPCIsThumb
parameter_list|,
name|nub_addr_t
modifier|*
name|targetPC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arm_error_t
name|DecodeInstructionUsingDisassembler
parameter_list|(
name|nub_addr_t
name|curr_pc
parameter_list|,
name|uint32_t
name|curr_cpsr
parameter_list|,
name|arm_decoded_instruction_t
modifier|*
name|decodedInstruction
parameter_list|,
name|thumb_static_data_t
modifier|*
name|thumbStaticData
parameter_list|,
name|nub_addr_t
modifier|*
name|next_pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DecodeITBlockInstructions
parameter_list|(
name|nub_addr_t
name|curr_pc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|EvaluateNextInstructionForSoftwareBreakpointSetup
parameter_list|(
name|nub_addr_t
name|currentPC
parameter_list|,
name|uint32_t
name|cpsr
parameter_list|,
name|bool
name|currentPCIsThumb
parameter_list|,
name|nub_addr_t
modifier|*
name|nextPC
parameter_list|,
name|bool
modifier|*
name|nextPCIsThumb
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
name|RegisterSetTag
block|{
name|e_regSetALL
init|=
name|REGISTER_SET_ALL
block|,
name|e_regSetGPR
block|,
comment|// ARM_THREAD_STATE
name|e_regSetVFP
block|,
comment|// ARM_VFP_STATE (ARM_NEON_STATE if defined __arm64__)
name|e_regSetEXC
block|,
comment|// ARM_EXCEPTION_STATE
name|e_regSetDBG
block|,
comment|// ARM_DEBUG_STATE (ARM_DEBUG_STATE32 if defined __arm64__)
name|kNumRegisterSets
block|}
name|RegisterSet
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|Read
init|=
literal|0
block|,
name|Write
init|=
literal|1
block|,
name|kNumErrors
init|=
literal|2
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|arm_thread_state_t
name|GPR
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|arm_neon_state_t
name|FPU
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|arm_vfp_state_t
name|FPU
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|arm_exception_state_t
name|EXC
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|DNBRegisterInfo
name|g_gpr_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|DNBRegisterInfo
name|g_vfp_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|DNBRegisterInfo
name|g_exc_registers
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|DNBRegisterSetInfo
name|g_reg_sets
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|k_num_gpr_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|k_num_vfp_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|k_num_exc_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|k_num_all_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|k_num_register_sets
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Context
block|{
name|GPR
name|gpr
decl_stmt|;
name|FPU
name|vfp
decl_stmt|;
name|EXC
name|exc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|State
block|{
name|Context
name|context
decl_stmt|;
name|DBG
name|dbg
decl_stmt|;
name|kern_return_t
name|gpr_errs
index|[
literal|2
index|]
decl_stmt|;
comment|// Read/Write errors
name|kern_return_t
name|vfp_errs
index|[
literal|2
index|]
decl_stmt|;
comment|// Read/Write errors
name|kern_return_t
name|exc_errs
index|[
literal|2
index|]
decl_stmt|;
comment|// Read/Write errors
name|kern_return_t
name|dbg_errs
index|[
literal|2
index|]
decl_stmt|;
comment|// Read/Write errors
name|State
argument_list|()
block|{
name|uint32_t
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|kNumErrors
condition|;
name|i
operator|++
control|)
block|{
name|gpr_errs
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|vfp_errs
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|exc_errs
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
name|dbg_errs
index|[
name|i
index|]
operator|=
operator|-
literal|1
expr_stmt|;
block|}
block|}
name|void
name|InvalidateRegisterSetState
parameter_list|(
name|int
name|set
parameter_list|)
block|{
name|SetError
argument_list|(
name|set
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|kern_return_t
name|GetError
argument_list|(
name|int
name|set
argument_list|,
name|uint32_t
name|err_idx
argument_list|)
decl|const
block|{
if|if
condition|(
name|err_idx
operator|<
name|kNumErrors
condition|)
block|{
switch|switch
condition|(
name|set
condition|)
block|{
comment|// When getting all errors, just OR all values together to see if
comment|// we got any kind of error.
case|case
name|e_regSetALL
case|:
return|return
name|gpr_errs
index|[
name|err_idx
index|]
operator||
name|vfp_errs
index|[
name|err_idx
index|]
operator||
name|exc_errs
index|[
name|err_idx
index|]
operator||
name|dbg_errs
index|[
name|err_idx
index|]
return|;
case|case
name|e_regSetGPR
case|:
return|return
name|gpr_errs
index|[
name|err_idx
index|]
return|;
case|case
name|e_regSetVFP
case|:
return|return
name|vfp_errs
index|[
name|err_idx
index|]
return|;
case|case
name|e_regSetEXC
case|:
return|return
name|exc_errs
index|[
name|err_idx
index|]
return|;
case|case
name|e_regSetDBG
case|:
return|return
name|dbg_errs
index|[
name|err_idx
index|]
return|;
default|default:
break|break;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
name|bool
name|SetError
parameter_list|(
name|int
name|set
parameter_list|,
name|uint32_t
name|err_idx
parameter_list|,
name|kern_return_t
name|err
parameter_list|)
block|{
if|if
condition|(
name|err_idx
operator|<
name|kNumErrors
condition|)
block|{
switch|switch
condition|(
name|set
condition|)
block|{
case|case
name|e_regSetALL
case|:
name|gpr_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
name|vfp_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
name|dbg_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
name|exc_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|e_regSetGPR
case|:
name|gpr_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|e_regSetVFP
case|:
name|vfp_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|e_regSetEXC
case|:
name|exc_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|e_regSetDBG
case|:
name|dbg_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
default|default:
break|break;
block|}
block|}
return|return
name|false
return|;
block|}
name|bool
name|RegsAreValid
argument_list|(
name|int
name|set
argument_list|)
decl|const
block|{
return|return
name|GetError
argument_list|(
name|set
argument_list|,
name|Read
argument_list|)
operator|==
name|KERN_SUCCESS
return|;
block|}
block|}
struct|;
end_struct

begin_function_decl
name|kern_return_t
name|GetGPRState
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|GetVFPState
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|GetEXCState
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|GetDBGState
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|SetGPRState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|SetVFPState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|SetEXCState
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|kern_return_t
name|SetDBGState
parameter_list|(
name|bool
name|also_set_on_task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsWatchpointEnabled
parameter_list|(
specifier|const
name|DBG
modifier|&
name|debug_state
parameter_list|,
name|uint32_t
name|hw_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_addr_t
name|GetWatchpointAddressByIndex
parameter_list|(
name|uint32_t
name|hw_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_addr_t
name|GetWatchAddress
parameter_list|(
specifier|const
name|DBG
modifier|&
name|debug_state
parameter_list|,
name|uint32_t
name|hw_index
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|disabled_watchpoint
block|{
name|public
label|:
name|disabled_watchpoint
argument_list|()
block|{
name|addr
operator|=
literal|0
expr_stmt|;
name|control
operator|=
literal|0
expr_stmt|;
block|}
name|nub_addr_t
name|addr
decl_stmt|;
name|uint32_t
name|control
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|MachThread
modifier|*
name|m_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|State
name|m_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DBG
name|m_dbg_save
decl_stmt|;
end_decl_stmt

begin_comment
comment|// armv8 doesn't keep the disabled watchpoint values in the debug register
end_comment

begin_comment
comment|// context like armv7;
end_comment

begin_comment
comment|// we need to save them aside when we disable them temporarily.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|disabled_watchpoint
operator|>
name|m_disabled_watchpoints
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nub_addr_t
name|m_hw_single_chained_step_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|m_last_decode_pc
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The following member variables should be updated atomically.
end_comment

begin_decl_stmt
name|int32_t
name|m_watchpoint_hw_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_watchpoint_did_occur
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_watchpoint_resume_single_step_enabled
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|Context
operator|>
name|SaveRegisterStates
expr_stmt|;
end_typedef

begin_decl_stmt
name|SaveRegisterStates
name|m_saved_register_states
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined (__arm__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DebugNubArchMachARM_h__
end_comment

end_unit

