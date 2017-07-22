begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX_arm.h ------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_arm_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_arm_h_
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
file|"RegisterInfoInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb-arm-register-enums.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Log.h"
end_include

begin_decl_stmt
name|class
name|ProcessMonitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextPOSIX_arm
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextPOSIX_arm
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|lldb_private::RegisterInfoInterface *register_info
argument_list|)
block|;
operator|~
name|RegisterContextPOSIX_arm
argument_list|()
name|override
block|;
name|void
name|Invalidate
argument_list|()
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
argument|size_t set
argument_list|)
name|override
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
name|override
block|;
name|protected
operator|:
expr|struct
name|RegInfo
block|{
name|uint32_t
name|num_registers
block|;
name|uint32_t
name|num_gpr_registers
block|;
name|uint32_t
name|num_fpr_registers
block|;
name|uint32_t
name|last_gpr
block|;
name|uint32_t
name|first_fpr
block|;
name|uint32_t
name|last_fpr
block|;
name|uint32_t
name|first_fpr_v
block|;
name|uint32_t
name|last_fpr_v
block|;
name|uint32_t
name|gpr_flags
block|;   }
block|;    struct
name|QReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;   }
block|;    struct
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
block|;   }
block|;
name|uint32_t
name|m_gpr_arm
index|[
name|lldb_private
operator|::
name|k_num_gpr_registers_arm
index|]
block|;
comment|// 32-bit general
comment|// purpose
comment|// registers.
name|RegInfo
name|m_reg_info
block|;   struct
name|RegisterContextPOSIX_arm
operator|::
name|FPU
name|m_fpr
block|;
comment|// floating-point registers including extended register sets.
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
comment|// Determines if an extended register set is supported on the processor
comment|// running the inferior process.
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
comment|// liblldb_RegisterContextPOSIX_arm_h_
end_comment

end_unit

