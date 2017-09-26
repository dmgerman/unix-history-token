begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_h_
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
file|"lldb/Target/ExecutionContextScope.h"
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
name|RegisterContext
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|RegisterContext
operator|>
decl_stmt|,
name|public
name|ExecutionContextScope
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|RegisterContext
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
empty_stmt|;
operator|~
name|RegisterContext
argument_list|()
name|override
expr_stmt|;
name|void
name|InvalidateIfNeeded
parameter_list|(
name|bool
name|force
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Subclasses must override these functions
comment|//------------------------------------------------------------------
name|virtual
name|void
name|InvalidateAllRegisters
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|size_t
name|GetRegisterCount
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|RegisterInfo
modifier|*
name|GetRegisterInfoAtIndex
parameter_list|(
name|size_t
name|reg
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Detect the register size dynamically.
name|uint32_t
name|UpdateDynamicRegisterSize
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|,
name|RegisterInfo
operator|*
name|reg_info
argument_list|)
decl_stmt|;
name|virtual
name|size_t
name|GetRegisterSetCount
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|RegisterSet
modifier|*
name|GetRegisterSet
parameter_list|(
name|size_t
name|reg_set
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|ReadRegister
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|WriteRegister
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
specifier|const
name|RegisterValue
modifier|&
name|reg_value
parameter_list|)
init|=
literal|0
function_decl|;
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
block|{
return|return
name|false
return|;
block|}
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
block|{
return|return
name|false
return|;
block|}
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
name|virtual
name|bool
name|ReadAllRegisterValues
argument_list|(
name|lldb_private
operator|::
name|RegisterCheckpoint
operator|&
name|reg_checkpoint
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|WriteAllRegisterValues
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterCheckpoint
operator|&
name|reg_checkpoint
argument_list|)
decl_stmt|;
name|bool
name|CopyFromRegisterContext
argument_list|(
name|lldb
operator|::
name|RegisterContextSP
name|context
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Convert from a given register numbering scheme to the lldb register
comment|/// numbering scheme
comment|///
comment|/// There may be multiple ways to enumerate the registers for a given
comment|/// architecture.  ABI references will specify one to be used with
comment|/// DWARF, the register numberings from process plugin, there may
comment|/// be a variation used for eh_frame unwind instructions (e.g. on Darwin),
comment|/// and so on.  Register 5 by itself is meaningless - RegisterKind
comment|/// enumeration tells you what context that number should be translated as.
comment|///
comment|/// Inside lldb, register numbers are in the eRegisterKindLLDB scheme;
comment|/// arguments which take a register number should take one in that
comment|/// scheme.
comment|///
comment|/// eRegisterKindGeneric is a special numbering scheme which gives us
comment|/// constant values for the pc, frame register, stack register, etc., for
comment|/// use within lldb.  They may not be defined for all architectures but
comment|/// it allows generic code to translate these common registers into the
comment|/// lldb numbering scheme.
comment|///
comment|/// This method translates a given register kind + register number into
comment|/// the eRegisterKindLLDB register numbering.
comment|///
comment|/// @param [in] kind
comment|///     The register numbering scheme (RegisterKind) that the following
comment|///     register number is in.
comment|///
comment|/// @param [in] num
comment|///     A register number in the 'kind' register numbering scheme.
comment|///
comment|/// @return
comment|///     The equivalent register number in the eRegisterKindLLDB
comment|///     numbering scheme, if possible, else LLDB_INVALID_REGNUM.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|kind
argument_list|,
name|uint32_t
name|num
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Subclasses can override these functions if desired
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|NumSupportedHardwareBreakpoints
parameter_list|()
function_decl|;
name|virtual
name|uint32_t
name|SetHardwareBreakpoint
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|ClearHardwareBreakpoint
parameter_list|(
name|uint32_t
name|hw_idx
parameter_list|)
function_decl|;
name|virtual
name|uint32_t
name|NumSupportedHardwareWatchpoints
parameter_list|()
function_decl|;
name|virtual
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|,
name|bool
name|read
argument_list|,
name|bool
name|write
argument_list|)
decl_stmt|;
name|virtual
name|bool
name|ClearHardwareWatchpoint
parameter_list|(
name|uint32_t
name|hw_index
parameter_list|)
function_decl|;
name|virtual
name|bool
name|HardwareSingleStep
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|virtual
name|Status
name|ReadRegisterValueFromMemory
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb
operator|::
name|addr_t
name|src_addr
argument_list|,
name|uint32_t
name|src_len
argument_list|,
name|RegisterValue
operator|&
name|reg_value
argument_list|)
decl_stmt|;
name|virtual
name|Status
name|WriteRegisterValueToMemory
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb
operator|::
name|addr_t
name|dst_addr
argument_list|,
name|uint32_t
name|dst_len
argument_list|,
specifier|const
name|RegisterValue
operator|&
name|reg_value
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Subclasses should not override these
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|Thread
modifier|&
name|GetThread
parameter_list|()
block|{
return|return
name|m_thread
return|;
block|}
specifier|const
name|RegisterInfo
modifier|*
name|GetRegisterInfoByName
argument_list|(
name|llvm
operator|::
name|StringRef
name|reg_name
argument_list|,
name|uint32_t
name|start_idx
operator|=
literal|0
argument_list|)
decl_stmt|;
specifier|const
name|RegisterInfo
modifier|*
name|GetRegisterInfo
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|,
name|uint32_t
name|reg_num
argument_list|)
decl_stmt|;
name|uint64_t
name|GetPC
parameter_list|(
name|uint64_t
name|fail_value
init|=
name|LLDB_INVALID_ADDRESS
parameter_list|)
function_decl|;
name|bool
name|SetPC
parameter_list|(
name|uint64_t
name|pc
parameter_list|)
function_decl|;
name|bool
name|SetPC
parameter_list|(
name|Address
name|addr
parameter_list|)
function_decl|;
name|uint64_t
name|GetSP
parameter_list|(
name|uint64_t
name|fail_value
init|=
name|LLDB_INVALID_ADDRESS
parameter_list|)
function_decl|;
name|bool
name|SetSP
parameter_list|(
name|uint64_t
name|sp
parameter_list|)
function_decl|;
name|uint64_t
name|GetFP
parameter_list|(
name|uint64_t
name|fail_value
init|=
name|LLDB_INVALID_ADDRESS
parameter_list|)
function_decl|;
name|bool
name|SetFP
parameter_list|(
name|uint64_t
name|fp
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|GetRegisterName
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
function_decl|;
name|uint64_t
name|GetReturnAddress
parameter_list|(
name|uint64_t
name|fail_value
init|=
name|LLDB_INVALID_ADDRESS
parameter_list|)
function_decl|;
name|uint64_t
name|GetFlags
parameter_list|(
name|uint64_t
name|fail_value
init|=
literal|0
parameter_list|)
function_decl|;
name|uint64_t
name|ReadRegisterAsUnsigned
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|fail_value
parameter_list|)
function_decl|;
name|uint64_t
name|ReadRegisterAsUnsigned
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|uint64_t
name|fail_value
parameter_list|)
function_decl|;
name|bool
name|WriteRegisterFromUnsigned
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|uval
parameter_list|)
function_decl|;
name|bool
name|WriteRegisterFromUnsigned
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|uint64_t
name|uval
parameter_list|)
function_decl|;
name|bool
name|ConvertBetweenRegisterKinds
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|source_rk
argument_list|,
name|uint32_t
name|source_regnum
argument_list|,
name|lldb
operator|::
name|RegisterKind
name|target_rk
argument_list|,
name|uint32_t
operator|&
name|target_regnum
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
name|override
expr_stmt|;
name|void
name|CalculateExecutionContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
name|override
decl_stmt|;
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
block|{
return|return
name|m_stop_id
return|;
block|}
name|void
name|SetStopID
parameter_list|(
name|uint32_t
name|stop_id
parameter_list|)
block|{
name|m_stop_id
operator|=
name|stop_id
expr_stmt|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from RegisterContext can see and modify these
comment|//------------------------------------------------------------------
name|Thread
modifier|&
name|m_thread
decl_stmt|;
comment|// The thread that this register context belongs to.
name|uint32_t
name|m_concrete_frame_idx
decl_stmt|;
comment|// The concrete frame index for this register
comment|// context
name|uint32_t
name|m_stop_id
decl_stmt|;
comment|// The stop ID that any data in this context is valid for
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For RegisterContext only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContext
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_RegisterContext_h_
end_comment

end_unit

