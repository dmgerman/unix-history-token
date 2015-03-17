begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX_powerpc.h ---------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_powerpc_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_powerpc_H_
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
file|"RegisterContext_powerpc.h"
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
comment|// Internal codes for all powerpc registers.
end_comment

begin_comment
comment|// ---------------------------------------------------------------------------
end_comment

begin_enum
enum|enum
block|{
name|k_first_gpr_powerpc
block|,
name|gpr_r0_powerpc
init|=
name|k_first_gpr_powerpc
block|,
name|gpr_r1_powerpc
block|,
name|gpr_r2_powerpc
block|,
name|gpr_r3_powerpc
block|,
name|gpr_r4_powerpc
block|,
name|gpr_r5_powerpc
block|,
name|gpr_r6_powerpc
block|,
name|gpr_r7_powerpc
block|,
name|gpr_r8_powerpc
block|,
name|gpr_r9_powerpc
block|,
name|gpr_r10_powerpc
block|,
name|gpr_r11_powerpc
block|,
name|gpr_r12_powerpc
block|,
name|gpr_r13_powerpc
block|,
name|gpr_r14_powerpc
block|,
name|gpr_r15_powerpc
block|,
name|gpr_r16_powerpc
block|,
name|gpr_r17_powerpc
block|,
name|gpr_r18_powerpc
block|,
name|gpr_r19_powerpc
block|,
name|gpr_r20_powerpc
block|,
name|gpr_r21_powerpc
block|,
name|gpr_r22_powerpc
block|,
name|gpr_r23_powerpc
block|,
name|gpr_r24_powerpc
block|,
name|gpr_r25_powerpc
block|,
name|gpr_r26_powerpc
block|,
name|gpr_r27_powerpc
block|,
name|gpr_r28_powerpc
block|,
name|gpr_r29_powerpc
block|,
name|gpr_r30_powerpc
block|,
name|gpr_r31_powerpc
block|,
name|gpr_lr_powerpc
block|,
name|gpr_cr_powerpc
block|,
name|gpr_xer_powerpc
block|,
name|gpr_ctr_powerpc
block|,
name|gpr_pc_powerpc
block|,
name|k_last_gpr_powerpc
init|=
name|gpr_pc_powerpc
block|,
name|k_first_fpr
block|,
name|fpr_f0_powerpc
init|=
name|k_first_fpr
block|,
name|fpr_f1_powerpc
block|,
name|fpr_f2_powerpc
block|,
name|fpr_f3_powerpc
block|,
name|fpr_f4_powerpc
block|,
name|fpr_f5_powerpc
block|,
name|fpr_f6_powerpc
block|,
name|fpr_f7_powerpc
block|,
name|fpr_f8_powerpc
block|,
name|fpr_f9_powerpc
block|,
name|fpr_f10_powerpc
block|,
name|fpr_f11_powerpc
block|,
name|fpr_f12_powerpc
block|,
name|fpr_f13_powerpc
block|,
name|fpr_f14_powerpc
block|,
name|fpr_f15_powerpc
block|,
name|fpr_f16_powerpc
block|,
name|fpr_f17_powerpc
block|,
name|fpr_f18_powerpc
block|,
name|fpr_f19_powerpc
block|,
name|fpr_f20_powerpc
block|,
name|fpr_f21_powerpc
block|,
name|fpr_f22_powerpc
block|,
name|fpr_f23_powerpc
block|,
name|fpr_f24_powerpc
block|,
name|fpr_f25_powerpc
block|,
name|fpr_f26_powerpc
block|,
name|fpr_f27_powerpc
block|,
name|fpr_f28_powerpc
block|,
name|fpr_f29_powerpc
block|,
name|fpr_f30_powerpc
block|,
name|fpr_f31_powerpc
block|,
name|fpr_fpscr_powerpc
block|,
name|k_last_fpr
init|=
name|fpr_fpscr_powerpc
block|,
name|k_num_registers_powerpc
block|,
name|k_num_gpr_registers_powerpc
init|=
name|k_last_gpr_powerpc
operator|-
name|k_first_gpr_powerpc
operator|+
literal|1
block|,
name|k_num_fpr_registers_powerpc
init|=
name|k_last_fpr
operator|-
name|k_first_fpr
operator|+
literal|1
block|, }
enum|;
end_enum

begin_decl_stmt
name|class
name|RegisterContextPOSIX_powerpc
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextPOSIX_powerpc
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|lldb_private::RegisterInfoInterface *register_info
argument_list|)
block|;
operator|~
name|RegisterContextPOSIX_powerpc
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
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
block|;
name|protected
operator|:
name|uint64_t
name|m_gpr_powerpc
index|[
name|k_num_gpr_registers_powerpc
index|]
block|;
comment|// general purpose registers.
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
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
comment|// #ifndef liblldb_RegisterContextPOSIX_powerpc_H_
end_comment

end_unit

