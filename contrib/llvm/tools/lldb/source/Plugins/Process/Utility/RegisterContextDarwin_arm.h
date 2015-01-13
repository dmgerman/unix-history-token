begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextDarwin_arm.h -----------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextDarwin_arm_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextDarwin_arm_h_
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
comment|// BCR address match type
end_comment

begin_define
define|#
directive|define
name|BCR_M_IMVA_MATCH
value|((uint32_t)(0u<< 21))
end_define

begin_define
define|#
directive|define
name|BCR_M_CONTEXT_ID_MATCH
value|((uint32_t)(1u<< 21))
end_define

begin_define
define|#
directive|define
name|BCR_M_IMVA_MISMATCH
value|((uint32_t)(2u<< 21))
end_define

begin_define
define|#
directive|define
name|BCR_M_RESERVED
value|((uint32_t)(3u<< 21))
end_define

begin_comment
comment|// Link a BVR/BCR or WVR/WCR pair to another
end_comment

begin_define
define|#
directive|define
name|E_ENABLE_LINKING
value|((uint32_t)(1u<< 20))
end_define

begin_comment
comment|// Byte Address Select
end_comment

begin_define
define|#
directive|define
name|BAS_IMVA_PLUS_0
value|((uint32_t)(1u<< 5))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_PLUS_1
value|((uint32_t)(1u<< 6))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_PLUS_2
value|((uint32_t)(1u<< 7))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_PLUS_3
value|((uint32_t)(1u<< 8))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_0_1
value|((uint32_t)(3u<< 5))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_2_3
value|((uint32_t)(3u<< 7))
end_define

begin_define
define|#
directive|define
name|BAS_IMVA_ALL
value|((uint32_t)(0xfu<< 5))
end_define

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
name|BCR_ENABLE
value|((uint32_t)(1u))
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
name|RegisterContextDarwin_arm
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextDarwin_arm
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|virtual
operator|~
name|RegisterContextDarwin_arm
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
name|NumSupportedHardwareBreakpoints
argument_list|()
block|;
name|virtual
name|uint32_t
name|SetHardwareBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
block|;
name|virtual
name|bool
name|ClearHardwareBreakpoint
argument_list|(
argument|uint32_t hw_idx
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
block|;      struct
name|GPR
block|{
name|uint32_t
name|r
index|[
literal|16
index|]
block|;
comment|// R0-R15
name|uint32_t
name|cpsr
block|;
comment|// CPSR
block|}
block|;       struct
name|QReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;     }
block|;      struct
name|FPU
block|{
expr|union
block|{
name|uint32_t
name|s
index|[
literal|32
index|]
block|;
name|uint64_t
name|d
index|[
literal|32
index|]
block|;
name|QReg
name|q
index|[
literal|16
index|]
block|;
comment|// the 128-bit NEON registers
block|}
name|floats
block|;
name|uint32_t
name|fpscr
block|;     }
block|;
comment|//  struct NeonReg
comment|//  {
comment|//      uint8_t bytes[16];
comment|//  };
comment|//
comment|//  struct VFPv3
comment|//  {
comment|//      union {
comment|//          uint32_t s[32];
comment|//          uint64_t d[32];
comment|//          NeonReg  q[16];
comment|//      } v3;
comment|//      uint32_t fpscr;
comment|//  };
block|struct
name|EXC
block|{
name|uint32_t
name|exception
block|;
name|uint32_t
name|fsr
block|;
comment|/* Fault status */
name|uint32_t
name|far
block|;
comment|/* Virtual Fault Address */
block|}
block|;      struct
name|DBG
block|{
name|uint32_t
name|bvr
index|[
literal|16
index|]
block|;
name|uint32_t
name|bcr
index|[
literal|16
index|]
block|;
name|uint32_t
name|wvr
index|[
literal|16
index|]
block|;
name|uint32_t
name|wcr
index|[
literal|16
index|]
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
literal|1
block|,
comment|// ARM_THREAD_STATE
name|FPURegSet
operator|=
literal|2
block|,
comment|// ARM_VFP_STATE
name|EXCRegSet
operator|=
literal|3
block|,
comment|// ARM_EXCEPTION_STATE
name|DBGRegSet
operator|=
literal|4
comment|// ARM_DEBUG_STATE
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
comment|// liblldb_RegisterContextDarwin_arm_h_
end_comment

end_unit

