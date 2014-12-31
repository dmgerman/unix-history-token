begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextDarwin_arm64.h -----------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextDarwin_arm64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextDarwin_arm64_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_comment
comment|// Break only in privileged or user mode
end_comment

begin_define
define|#
directive|define
name|S_RSVD
value|((uint32_t)(0u<< 1))
end_define

begin_define
define|#
directive|define
name|S_PRIV
value|((uint32_t)(1u<< 1))
end_define

begin_define
define|#
directive|define
name|S_USER
value|((uint32_t)(2u<< 1))
end_define

begin_define
define|#
directive|define
name|S_PRIV_USER
value|((S_PRIV) | (S_USER))
end_define

begin_define
define|#
directive|define
name|WCR_ENABLE
value|((uint32_t)(1u))
end_define

begin_comment
comment|// Watchpoint load/store
end_comment

begin_define
define|#
directive|define
name|WCR_LOAD
value|((uint32_t)(1u<< 3))
end_define

begin_define
define|#
directive|define
name|WCR_STORE
value|((uint32_t)(1u<< 4))
end_define

begin_decl_stmt
name|class
name|RegisterContextDarwin_arm64
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextDarwin_arm64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextDarwin_arm64
argument_list|()
block|;
name|virtual
name|void
name|InvalidateAllRegisters
argument_list|()
block|;
name|virtual
name|size_t
name|GetRegisterCount
argument_list|()
block|;
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
block|;
name|virtual
name|size_t
name|GetRegisterSetCount
argument_list|()
block|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t set
argument_list|)
block|;
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
name|reg_value
argument_list|)
block|;
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
name|reg_value
argument_list|)
block|;
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
block|;
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
block|;
name|virtual
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
block|;
name|virtual
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
block|;
name|virtual
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
block|;
name|virtual
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
comment|// mirrors<mach/arm/thread_status.h> arm_thread_state64_t
block|struct
name|GPR
block|{
name|uint64_t
name|x
index|[
literal|29
index|]
block|;
comment|// x0-x28
name|uint64_t
name|fp
block|;
comment|// x29
name|uint64_t
name|lr
block|;
comment|// x30
name|uint64_t
name|sp
block|;
comment|// x31
name|uint64_t
name|pc
block|;
comment|// pc
name|uint32_t
name|cpsr
block|;
comment|// cpsr
block|}
block|;       struct
name|VReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;     }
block|;
comment|// mirrors<mach/arm/thread_status.h> arm_neon_state64_t
block|struct
name|FPU
block|{
name|VReg
name|v
index|[
literal|32
index|]
block|;
name|uint32_t
name|fpsr
block|;
name|uint32_t
name|fpcr
block|;     }
block|;
comment|// mirrors<mach/arm/thread_status.h> arm_exception_state64_t
block|struct
name|EXC
block|{
name|uint64_t
name|far
block|;
comment|// Virtual Fault Address
name|uint32_t
name|esr
block|;
comment|// Exception syndrome
name|uint32_t
name|exception
block|;
comment|// number of arm exception token
block|}
block|;
comment|// mirrors<mach/arm/thread_status.h> arm_debug_state64_t
block|struct
name|DBG
block|{
name|uint64_t
name|bvr
index|[
literal|16
index|]
block|;
name|uint64_t
name|bcr
index|[
literal|16
index|]
block|;
name|uint64_t
name|wvr
index|[
literal|16
index|]
block|;
name|uint64_t
name|wcr
index|[
literal|16
index|]
block|;
name|uint64_t
name|mdscr_el1
block|;     }
block|;
specifier|static
name|void
name|LogDBGRegisters
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|DBG
operator|&
name|dbg
argument_list|)
block|;
name|protected
operator|:
expr|enum
block|{
name|GPRRegSet
operator|=
literal|6
block|,
comment|// ARM_THREAD_STATE64
name|FPURegSet
operator|=
literal|17
block|,
comment|// ARM_NEON_STATE64
name|EXCRegSet
operator|=
literal|7
block|,
comment|// ARM_EXCEPTION_STATE64
name|DBGRegSet
operator|=
literal|15
comment|// ARM_DEBUG_STATE64
block|}
block|;      enum
block|{
name|GPRWordCount
operator|=
sizeof|sizeof
argument_list|(
name|GPR
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
block|,
comment|// ARM_THREAD_STATE64_COUNT
name|FPUWordCount
operator|=
sizeof|sizeof
argument_list|(
name|FPU
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
block|,
comment|// ARM_NEON_STATE64_COUNT
name|EXCWordCount
operator|=
sizeof|sizeof
argument_list|(
name|EXC
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
block|,
comment|// ARM_EXCEPTION_STATE64_COUNT
name|DBGWordCount
operator|=
sizeof|sizeof
argument_list|(
name|DBG
argument_list|)
operator|/
expr|sizeof
operator|(
name|uint32_t
operator|)
comment|// ARM_DEBUG_STATE64_COUNT
block|}
block|;      enum
block|{
name|Read
operator|=
literal|0
block|,
name|Write
operator|=
literal|1
block|,
name|kNumErrors
operator|=
literal|2
block|}
block|;
name|GPR
name|gpr
block|;
name|FPU
name|fpu
block|;
name|EXC
name|exc
block|;
name|DBG
name|dbg
block|;
name|int
name|gpr_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|int
name|fpu_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|int
name|exc_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|int
name|dbg_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|void
name|InvalidateAllRegisterStates
argument_list|()
block|{
name|SetError
argument_list|(
name|GPRRegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;
name|SetError
argument_list|(
name|FPURegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;
name|SetError
argument_list|(
name|EXCRegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;     }
name|int
name|GetError
argument_list|(
argument|int flavor
argument_list|,
argument|uint32_t err_idx
argument_list|)
specifier|const
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
name|flavor
condition|)
block|{
comment|// When getting all errors, just OR all values together to see if
comment|// we got any kind of error.
case|case
name|GPRRegSet
case|:
return|return
name|gpr_errs
index|[
name|err_idx
index|]
return|;
case|case
name|FPURegSet
case|:
return|return
name|fpu_errs
index|[
name|err_idx
index|]
return|;
case|case
name|EXCRegSet
case|:
return|return
name|exc_errs
index|[
name|err_idx
index|]
return|;
case|case
name|DBGRegSet
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
argument_list|(
argument|int flavor
argument_list|,
argument|uint32_t err_idx
argument_list|,
argument|int err
argument_list|)
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
name|flavor
condition|)
block|{
case|case
name|GPRRegSet
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
name|FPURegSet
case|:
name|fpu_errs
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
name|EXCRegSet
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
name|DBGRegSet
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
default|default:
break|break;
block|}
block|}
return|return
name|false
return|;
block|}
name|bool
name|RegisterSetIsCached
argument_list|(
argument|int set
argument_list|)
specifier|const
block|{
return|return
name|GetError
argument_list|(
name|set
argument_list|,
name|Read
argument_list|)
operator|==
literal|0
return|;
block|}
name|int
name|ReadGPR
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|ReadFPU
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|ReadEXC
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|ReadDBG
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|WriteGPR
argument_list|()
block|;
name|int
name|WriteFPU
argument_list|()
block|;
name|int
name|WriteEXC
argument_list|()
block|;
name|int
name|WriteDBG
argument_list|()
block|;
comment|// Subclasses override these to do the actual reading.
name|virtual
name|int
name|DoReadGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|GPR&gpr
argument_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
name|virtual
name|int
name|DoReadFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|FPU&fpu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoReadEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|EXC&exc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoReadDBG
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|DBG&dbg
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const GPR&gpr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const FPU&fpu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const EXC&exc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteDBG
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const DBG&dbg
argument_list|)
operator|=
literal|0
block|;
name|int
name|ReadRegisterSet
argument_list|(
argument|uint32_t set
argument_list|,
argument|bool force
argument_list|)
block|;
name|int
name|WriteRegisterSet
argument_list|(
argument|uint32_t set
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetRegisterNumber
argument_list|(
argument|uint32_t reg_kind
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
specifier|static
name|int
name|GetSetForNativeRegNum
argument_list|(
argument|int reg_num
argument_list|)
block|;
specifier|static
name|size_t
name|GetRegisterInfosCount
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfos
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextDarwin_arm64_h_
end_comment

end_unit

