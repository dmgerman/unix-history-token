begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextNetBSD.h ---------------------------*- C++ -*-===//
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
name|lldb_NativeRegisterContextNetBSD_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextNetBSD_h
end_define

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeThreadProtocol.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/NetBSD/NativeProcessNetBSD.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/NativeRegisterContextRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_netbsd
block|{
name|class
name|NativeRegisterContextNetBSD
range|:
name|public
name|NativeRegisterContextRegisterInfo
block|{
name|public
operator|:
name|NativeRegisterContextNetBSD
argument_list|(
argument|NativeThreadProtocol&native_thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|RegisterInfoInterface *reg_info_interface_p
argument_list|)
block|;
comment|// This function is implemented in the NativeRegisterContextNetBSD_*
comment|// subclasses to create a new instance of the host specific
comment|// NativeRegisterContextNetBSD. The implementations can't collide as only one
comment|// NativeRegisterContextNetBSD_* variant should be compiled into the final
comment|// executable.
specifier|static
name|NativeRegisterContextNetBSD
operator|*
name|CreateHostNativeRegisterContextNetBSD
argument_list|(
argument|const ArchSpec&target_arch
argument_list|,
argument|NativeThreadProtocol&native_thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|Error
name|ReadGPR
argument_list|()
block|;
name|virtual
name|Error
name|WriteGPR
argument_list|()
block|;
name|virtual
name|Error
name|ReadFPR
argument_list|()
block|;
name|virtual
name|Error
name|WriteFPR
argument_list|()
block|;
name|virtual
name|void
operator|*
name|GetGPRBuffer
argument_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|size_t
name|GetGPRSize
argument_list|()
block|{
return|return
name|GetRegisterInfoInterface
argument_list|()
operator|.
name|GetGPRSize
argument_list|()
return|;
block|}
name|virtual
name|void
operator|*
name|GetFPRBuffer
argument_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|size_t
name|GetFPRSize
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|virtual
name|Error
name|DoReadGPR
argument_list|(
name|void
operator|*
name|buf
argument_list|)
block|;
name|virtual
name|Error
name|DoWriteGPR
argument_list|(
name|void
operator|*
name|buf
argument_list|)
block|;
name|virtual
name|Error
name|DoReadFPR
argument_list|(
name|void
operator|*
name|buf
argument_list|)
block|;
name|virtual
name|Error
name|DoWriteFPR
argument_list|(
name|void
operator|*
name|buf
argument_list|)
block|;
name|virtual
name|NativeProcessNetBSD
operator|&
name|GetProcess
argument_list|()
block|;
name|virtual
operator|::
name|pid_t
name|GetProcessPid
argument_list|()
block|; }
decl_stmt|;
block|}
comment|// namespace process_netbsd
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
comment|// #ifndef lldb_NativeRegisterContextNetBSD_h
end_comment

end_unit

