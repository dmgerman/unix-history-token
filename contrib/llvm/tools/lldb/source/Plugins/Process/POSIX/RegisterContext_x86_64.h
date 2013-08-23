begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext_x86_64.h ---------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_x86_64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_x86_64_H_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Log.h"
end_include

begin_include
include|#
directive|include
file|"RegisterContextPOSIX.h"
end_include

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Internal codes for all x86_64 registers.
end_comment

begin_enum
enum|enum
block|{
name|k_first_gpr
block|,
name|gpr_rax
init|=
name|k_first_gpr
block|,
name|gpr_rbx
block|,
name|gpr_rcx
block|,
name|gpr_rdx
block|,
name|gpr_rdi
block|,
name|gpr_rsi
block|,
name|gpr_rbp
block|,
name|gpr_rsp
block|,
name|gpr_r8
block|,
name|gpr_r9
block|,
name|gpr_r10
block|,
name|gpr_r11
block|,
name|gpr_r12
block|,
name|gpr_r13
block|,
name|gpr_r14
block|,
name|gpr_r15
block|,
name|gpr_rip
block|,
name|gpr_rflags
block|,
name|gpr_cs
block|,
name|gpr_fs
block|,
name|gpr_gs
block|,
name|gpr_ss
block|,
name|gpr_ds
block|,
name|gpr_es
block|,
name|k_first_i386
block|,
name|gpr_eax
init|=
name|k_first_i386
block|,
name|gpr_ebx
block|,
name|gpr_ecx
block|,
name|gpr_edx
block|,
name|gpr_edi
block|,
name|gpr_esi
block|,
name|gpr_ebp
block|,
name|gpr_esp
block|,
name|gpr_eip
block|,
name|gpr_eflags
block|,
comment|// eRegisterKindLLDB == 33
name|k_last_i386
init|=
name|gpr_eflags
block|,
name|k_last_gpr
init|=
name|gpr_eflags
block|,
name|k_first_fpr
block|,
name|fpu_fcw
init|=
name|k_first_fpr
block|,
name|fpu_fsw
block|,
name|fpu_ftw
block|,
name|fpu_fop
block|,
name|fpu_ip
block|,
name|fpu_cs
block|,
name|fpu_dp
block|,
name|fpu_ds
block|,
name|fpu_mxcsr
block|,
name|fpu_mxcsrmask
block|,
name|fpu_stmm0
block|,
name|fpu_stmm1
block|,
name|fpu_stmm2
block|,
name|fpu_stmm3
block|,
name|fpu_stmm4
block|,
name|fpu_stmm5
block|,
name|fpu_stmm6
block|,
name|fpu_stmm7
block|,
name|fpu_xmm0
block|,
name|fpu_xmm1
block|,
name|fpu_xmm2
block|,
name|fpu_xmm3
block|,
name|fpu_xmm4
block|,
name|fpu_xmm5
block|,
name|fpu_xmm6
block|,
name|fpu_xmm7
block|,
name|fpu_xmm8
block|,
name|fpu_xmm9
block|,
name|fpu_xmm10
block|,
name|fpu_xmm11
block|,
name|fpu_xmm12
block|,
name|fpu_xmm13
block|,
name|fpu_xmm14
block|,
name|fpu_xmm15
block|,
name|k_last_fpr
init|=
name|fpu_xmm15
block|,
name|k_first_avx
block|,
name|fpu_ymm0
init|=
name|k_first_avx
block|,
name|fpu_ymm1
block|,
name|fpu_ymm2
block|,
name|fpu_ymm3
block|,
name|fpu_ymm4
block|,
name|fpu_ymm5
block|,
name|fpu_ymm6
block|,
name|fpu_ymm7
block|,
name|fpu_ymm8
block|,
name|fpu_ymm9
block|,
name|fpu_ymm10
block|,
name|fpu_ymm11
block|,
name|fpu_ymm12
block|,
name|fpu_ymm13
block|,
name|fpu_ymm14
block|,
name|fpu_ymm15
block|,
name|k_last_avx
init|=
name|fpu_ymm15
block|,
name|dr0
block|,
name|dr1
block|,
name|dr2
block|,
name|dr3
block|,
name|dr4
block|,
name|dr5
block|,
name|dr6
block|,
name|dr7
block|,
name|k_num_registers
block|,
name|k_num_gpr_registers
init|=
name|k_last_gpr
operator|-
name|k_first_gpr
operator|+
literal|1
block|,
name|k_num_fpr_registers
init|=
name|k_last_fpr
operator|-
name|k_first_fpr
operator|+
literal|1
block|,
name|k_num_avx_registers
init|=
name|k_last_avx
operator|-
name|k_first_avx
operator|+
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|RegisterContext_x86_64
range|:
name|public
name|RegisterContextPOSIX
block|{
name|public
operator|:
name|RegisterContext_x86_64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
operator|~
name|RegisterContext_x86_64
argument_list|()
block|;
name|void
name|Invalidate
argument_list|()
block|;
name|void
name|InvalidateAllRegisters
argument_list|()
block|;
name|size_t
name|GetRegisterCount
argument_list|()
block|;
name|virtual
name|size_t
name|GetGPRSize
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|GetRegisterSize
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|virtual
name|unsigned
name|GetRegisterOffset
argument_list|(
argument|unsigned reg
argument_list|)
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
block|;
name|size_t
name|GetRegisterSetCount
argument_list|()
block|;
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
name|unsigned
name|GetRegisterIndexFromOffset
argument_list|(
argument|unsigned offset
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|unsigned reg
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
name|value
argument_list|)
block|;
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
block|;
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
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|uint32_t kind
argument_list|,
argument|uint32_t num
argument_list|)
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
block|;
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
argument|lldb::addr_t
argument_list|,
argument|size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|)
block|;
name|bool
name|SetHardwareWatchpointWithIndex
argument_list|(
argument|lldb::addr_t
argument_list|,
argument|size_t size
argument_list|,
argument|bool read
argument_list|,
argument|bool write
argument_list|,
argument|uint32_t hw_index
argument_list|)
block|;
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
name|bool
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|UpdateAfterBreakpoint
argument_list|()
block|;
name|bool
name|IsWatchpointVacant
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
name|bool
name|IsWatchpointHit
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetWatchpointAddress
argument_list|(
argument|uint32_t hw_index
argument_list|)
block|;
name|bool
name|ClearWatchpointHits
argument_list|()
block|;
comment|//---------------------------------------------------------------------------
comment|// Generic floating-point registers
comment|//---------------------------------------------------------------------------
block|struct
name|MMSReg
block|{
name|uint8_t
name|bytes
index|[
literal|10
index|]
block|;
name|uint8_t
name|pad
index|[
literal|6
index|]
block|;     }
block|;      struct
name|XMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;
comment|// 128-bits for each XMM register
block|}
block|;      struct
name|FXSAVE
block|{
name|uint16_t
name|fcw
block|;
name|uint16_t
name|fsw
block|;
name|uint16_t
name|ftw
block|;
name|uint16_t
name|fop
block|;
name|uint64_t
name|ip
block|;
name|uint64_t
name|dp
block|;
name|uint32_t
name|mxcsr
block|;
name|uint32_t
name|mxcsrmask
block|;
name|MMSReg
name|stmm
index|[
literal|8
index|]
block|;
name|XMMReg
name|xmm
index|[
literal|16
index|]
block|;
name|uint32_t
name|padding
index|[
literal|24
index|]
block|;     }
block|;
comment|//---------------------------------------------------------------------------
comment|// Extended floating-point registers
comment|//---------------------------------------------------------------------------
block|struct
name|YMMHReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;
comment|// 16 * 8 bits for the high bytes of each YMM register
block|}
block|;      struct
name|YMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|32
index|]
block|;
comment|// 16 * 16 bits for each YMM register
block|}
block|;      struct
name|YMM
block|{
name|YMMReg
name|ymm
index|[
literal|16
index|]
block|;
comment|// assembled from ymmh and xmm registers
block|}
block|;      struct
name|XSAVE_HDR
block|{
name|uint64_t
name|xstate_bv
block|;
comment|// OS enabled xstate mask to determine the extended states supported by the processor
name|uint64_t
name|reserved1
index|[
literal|2
index|]
block|;
name|uint64_t
name|reserved2
index|[
literal|5
index|]
block|;     }
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
block|;
comment|// x86 extensions to FXSAVE (i.e. for AVX processors)
block|struct
name|XSAVE
block|{
name|FXSAVE
name|i387
block|;
comment|// floating point registers typical in i387_fxsave_struct
name|XSAVE_HDR
name|header
block|;
comment|// The xsave_hdr_struct can be used to determine if the following extensions are usable
name|YMMHReg
name|ymmh
index|[
literal|16
index|]
block|;
comment|// High 16 bytes of each of 16 YMM registers (the low bytes are in FXSAVE.xmm for compatibility with SSE)
comment|// Slot any extensions to the register file here
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
expr|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
block|;      struct
name|IOVEC
block|{
name|void
operator|*
name|iov_base
block|;
comment|// pointer to XSAVE
name|size_t
name|iov_len
block|;
comment|// sizeof(XSAVE)
block|}
block|;
comment|//---------------------------------------------------------------------------
comment|// Note: prefer kernel definitions over user-land
comment|//---------------------------------------------------------------------------
block|enum
name|FPRType
block|{
name|eNotValid
operator|=
literal|0
block|,
name|eFSAVE
block|,
comment|// TODO
name|eFXSAVE
block|,
name|eSOFT
block|,
comment|// TODO
name|eXSAVE
block|}
block|;
comment|// Floating-point registers
block|struct
name|FPR
block|{
comment|// Thread state for the floating-point unit of the processor read by ptrace.
expr|union
name|XSTATE
block|{
name|FXSAVE
name|fxsave
block|;
comment|// Generic floating-point registers.
name|XSAVE
name|xsave
block|;
comment|// x86 extended processor state.
block|}
name|xstate
block|;     }
block|;
name|protected
operator|:
comment|// Determines if an extended register set is supported on the processor running the inferior process.
name|virtual
name|bool
name|IsRegisterSetAvailable
argument_list|(
argument|size_t set_index
argument_list|)
block|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
block|;
name|virtual
name|bool
name|ReadRegister
argument_list|(
argument|const unsigned reg
argument_list|,
argument|lldb_private::RegisterValue&value
argument_list|)
block|;
name|virtual
name|bool
name|WriteRegister
argument_list|(
argument|const unsigned reg
argument_list|,
argument|const lldb_private::RegisterValue&value
argument_list|)
block|;
name|private
operator|:
name|uint64_t
name|m_gpr
index|[
name|k_num_gpr_registers
index|]
block|;
comment|// general purpose registers.
name|FPRType
name|m_fpr_type
block|;
comment|// determines the type of data stored by union FPR, if any.
name|FPR
name|m_fpr
block|;
comment|// floating-point registers including extended register sets.
name|IOVEC
name|m_iovec
block|;
comment|// wrapper for xsave.
name|YMM
name|m_ymm_set
block|;
comment|// copy of ymmh and xmm register halves.
name|ProcessMonitor
operator|&
name|GetMonitor
argument_list|()
block|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
block|;
name|bool
name|CopyXSTATEtoYMM
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
block|;
name|bool
name|CopyYMMtoXSTATE
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
block|;
name|bool
name|IsFPR
argument_list|(
argument|unsigned reg
argument_list|,
argument|FPRType fpr_type
argument_list|)
block|;
name|bool
name|ReadGPR
argument_list|()
block|;
name|bool
name|ReadFPR
argument_list|()
block|;
name|bool
name|WriteGPR
argument_list|()
block|;
name|bool
name|WriteFPR
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContext_x86_64_H_
end_comment

end_unit

