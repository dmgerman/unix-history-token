begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIX_x86.h ------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextPOSIX_x86_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextPOSIX_x86_h_
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
file|"RegisterContext_x86.h"
end_include

begin_include
include|#
directive|include
file|"RegisterInfoInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb-x86-register-enums.h"
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
name|RegisterContextPOSIX_x86
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextPOSIX_x86
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|lldb_private::RegisterInfoInterface *register_info
argument_list|)
block|;
operator|~
name|RegisterContextPOSIX_x86
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
name|size_t
name|GetFXSAVEOffset
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
specifier|static
name|uint32_t
name|g_contained_eax
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_ebx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_ecx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_edx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_edi
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_esi
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_ebp
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_esp
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_eax
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_ebx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_ecx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_edx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_edi
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_esi
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_ebp
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_esp
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rax
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rbx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rcx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rdx
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rdi
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rsi
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rbp
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_rsp
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r8
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r9
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r10
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r11
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r12
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r13
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r14
index|[]
block|;
specifier|static
name|uint32_t
name|g_contained_r15
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rax
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rbx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rcx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rdx
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rdi
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rsi
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rbp
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_rsp
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r8
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r9
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r10
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r11
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r12
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r13
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r14
index|[]
block|;
specifier|static
name|uint32_t
name|g_invalidate_r15
index|[]
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
name|num_avx_registers
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
name|first_st
block|;
name|uint32_t
name|last_st
block|;
name|uint32_t
name|first_mm
block|;
name|uint32_t
name|last_mm
block|;
name|uint32_t
name|first_xmm
block|;
name|uint32_t
name|last_xmm
block|;
name|uint32_t
name|first_ymm
block|;
name|uint32_t
name|last_ymm
block|;
name|uint32_t
name|first_dr
block|;
name|uint32_t
name|gpr_flags
block|;   }
block|;
name|uint64_t
name|m_gpr_x86_64
index|[
name|lldb_private
operator|::
name|k_num_gpr_registers_x86_64
index|]
block|;
comment|// 64-bit
comment|// general
comment|// purpose
comment|// registers.
name|RegInfo
name|m_reg_info
block|;
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
name|bool
name|IsAVX
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
name|FPRType
name|GetFPRType
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
comment|// liblldb_RegisterContextPOSIX_x86_h_
end_comment

end_unit

