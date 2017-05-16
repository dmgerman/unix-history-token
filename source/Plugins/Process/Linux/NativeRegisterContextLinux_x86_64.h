begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextLinux_x86_64.h ---------------------*- C++ -*-===//
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_NativeRegisterContextLinux_x86_64_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextLinux_x86_64_h
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/Linux/NativeRegisterContextLinux.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/RegisterContext_x86.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/lldb-x86-register-enums.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_linux
block|{
name|class
name|NativeProcessLinux
decl_stmt|;
name|class
name|NativeRegisterContextLinux_x86_64
range|:
name|public
name|NativeRegisterContextLinux
block|{
name|public
operator|:
name|NativeRegisterContextLinux_x86_64
argument_list|(
argument|const ArchSpec&target_arch
argument_list|,
argument|NativeThreadProtocol&native_thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|uint32_t
name|GetRegisterSetCount
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|uint32_t set_index
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|GetUserRegisterCount
argument_list|()
specifier|const
name|override
block|;
name|Status
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Status
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
name|override
block|;
name|Status
name|ReadAllRegisterValues
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Status
name|WriteAllRegisterValues
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|Status
name|IsWatchpointHit
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_hit
argument_list|)
name|override
block|;
name|Status
name|GetWatchpointHitIndex
argument_list|(
argument|uint32_t&wp_index
argument_list|,
argument|lldb::addr_t trap_addr
argument_list|)
name|override
block|;
name|Status
name|IsWatchpointVacant
argument_list|(
argument|uint32_t wp_index
argument_list|,
argument|bool&is_vacant
argument_list|)
name|override
block|;
name|bool
name|ClearHardwareWatchpoint
argument_list|(
argument|uint32_t wp_index
argument_list|)
name|override
block|;
name|Status
name|ClearAllHardwareWatchpoints
argument_list|()
name|override
block|;
name|Status
name|SetHardwareWatchpointWithIndex
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|,
argument|uint32_t wp_index
argument_list|)
block|;
name|uint32_t
name|SetHardwareWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t watch_flags
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetWatchpointAddress
argument_list|(
argument|uint32_t wp_index
argument_list|)
name|override
block|;
name|uint32_t
name|NumSupportedHardwareWatchpoints
argument_list|()
name|override
block|;
name|protected
operator|:
name|void
operator|*
name|GetGPRBuffer
argument_list|()
name|override
block|{
return|return
operator|&
name|m_gpr_x86_64
return|;
block|}
name|void
operator|*
name|GetFPRBuffer
argument_list|()
name|override
block|;
name|size_t
name|GetFPRSize
argument_list|()
name|override
block|;
name|Status
name|ReadFPR
argument_list|()
name|override
block|;
name|Status
name|WriteFPR
argument_list|()
name|override
block|;
name|private
operator|:
comment|// Private member types.
expr|enum
name|class
name|XStateType
block|{
name|Invalid
block|,
name|FXSAVE
block|,
name|XSAVE
block|}
block|;   enum
name|class
name|RegSet
block|{
name|gpr
block|,
name|fpu
block|,
name|avx
block|,
name|mpx
block|}
block|;
comment|// Info about register ranges.
block|struct
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
name|num_mpx_registers
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
name|first_mpxr
block|;
name|uint32_t
name|last_mpxr
block|;
name|uint32_t
name|first_mpxc
block|;
name|uint32_t
name|last_mpxc
block|;
name|uint32_t
name|first_dr
block|;
name|uint32_t
name|gpr_flags
block|;   }
block|;
comment|// Private member variables.
name|mutable
name|XStateType
name|m_xstate_type
block|;
name|FPR
name|m_fpr
block|;
comment|// Extended States Area, named FPR for historical reasons.
name|IOVEC
name|m_iovec
block|;
name|YMM
name|m_ymm_set
block|;
name|MPX
name|m_mpx_set
block|;
name|RegInfo
name|m_reg_info
block|;
name|uint64_t
name|m_gpr_x86_64
index|[
name|k_num_gpr_registers_x86_64
index|]
block|;
name|uint32_t
name|m_fctrl_offset_in_userarea
block|;
comment|// Private member methods.
name|bool
name|IsCPUFeatureAvailable
argument_list|(
argument|RegSet feature_code
argument_list|)
specifier|const
block|;
name|bool
name|IsRegisterSetAvailable
argument_list|(
argument|uint32_t set_index
argument_list|)
specifier|const
block|;
name|bool
name|IsGPR
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|bool
name|IsFPR
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|bool
name|CopyXSTATEtoYMM
argument_list|(
argument|uint32_t reg_index
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
name|IsAVX
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|;
name|bool
name|CopyXSTATEtoMPX
argument_list|(
argument|uint32_t reg
argument_list|)
block|;
name|bool
name|CopyMPXtoXSTATE
argument_list|(
argument|uint32_t reg
argument_list|)
block|;
name|bool
name|IsMPX
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
comment|// namespace process_linux
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
comment|// #ifndef lldb_NativeRegisterContextLinux_x86_64_h
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__i386__) || defined(__x86_64__)
end_comment

end_unit

