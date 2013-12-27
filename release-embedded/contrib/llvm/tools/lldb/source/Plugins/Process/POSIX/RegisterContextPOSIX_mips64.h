begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX_mips64.h ---------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_mips64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_mips64_H_
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

begin_include
include|#
directive|include
file|"RegisterContext_mips64.h"
end_include

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_comment
comment|// Internal codes for all mips64 registers.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_enum
enum|enum
block|{
name|k_first_gpr_mips64
block|,
name|gpr_zero_mips64
init|=
name|k_first_gpr_mips64
block|,
name|gpr_r1_mips64
block|,
name|gpr_r2_mips64
block|,
name|gpr_r3_mips64
block|,
name|gpr_r4_mips64
block|,
name|gpr_r5_mips64
block|,
name|gpr_r6_mips64
block|,
name|gpr_r7_mips64
block|,
name|gpr_r8_mips64
block|,
name|gpr_r9_mips64
block|,
name|gpr_r10_mips64
block|,
name|gpr_r11_mips64
block|,
name|gpr_r12_mips64
block|,
name|gpr_r13_mips64
block|,
name|gpr_r14_mips64
block|,
name|gpr_r15_mips64
block|,
name|gpr_r16_mips64
block|,
name|gpr_r17_mips64
block|,
name|gpr_r18_mips64
block|,
name|gpr_r19_mips64
block|,
name|gpr_r20_mips64
block|,
name|gpr_r21_mips64
block|,
name|gpr_r22_mips64
block|,
name|gpr_r23_mips64
block|,
name|gpr_r24_mips64
block|,
name|gpr_r25_mips64
block|,
name|gpr_r26_mips64
block|,
name|gpr_r27_mips64
block|,
name|gpr_gp_mips64
block|,
name|gpr_sp_mips64
block|,
name|gpr_r30_mips64
block|,
name|gpr_ra_mips64
block|,
name|gpr_sr_mips64
block|,
name|gpr_mullo_mips64
block|,
name|gpr_mulhi_mips64
block|,
name|gpr_badvaddr_mips64
block|,
name|gpr_cause_mips64
block|,
name|gpr_pc_mips64
block|,
name|gpr_ic_mips64
block|,
name|gpr_dummy_mips64
block|,
name|k_num_registers_mips64
block|,
name|k_num_gpr_registers_mips64
init|=
name|k_num_registers_mips64
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|RegisterContextPOSIX_mips64
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextPOSIX_mips64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|RegisterInfoInterface *register_info
argument_list|)
block|;
operator|~
name|RegisterContextPOSIX_mips64
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
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|unsigned reg
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
name|protected
operator|:
name|uint64_t
name|m_gpr_mips64
index|[
name|k_num_gpr_registers_mips64
index|]
block|;
comment|// general purpose registers.
name|std
operator|::
name|unique_ptr
operator|<
name|RegisterInfoInterface
operator|>
name|m_register_info_ap
block|;
comment|// Register Info Interface (FreeBSD or Linux)
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
name|bool
name|IsGPR
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|bool
name|IsFPR
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
block|;
name|virtual
name|bool
name|ReadGPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|ReadFPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|WriteGPR
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|WriteFPR
argument_list|()
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContextPOSIX_mips64_H_
end_comment

end_unit

