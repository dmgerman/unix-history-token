begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextLinux.h ----------------------------*- C++ -*-===//
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
name|lldb_NativeRegisterContextLinux_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_NativeRegisterContextLinux_h
end_define

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeThreadProtocol.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Linux/NativeProcessLinux.h"
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
name|process_linux
block|{
name|class
name|NativeRegisterContextLinux
range|:
name|public
name|NativeRegisterContextRegisterInfo
block|{
name|public
operator|:
name|NativeRegisterContextLinux
argument_list|(
argument|NativeThreadProtocol&native_thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|RegisterInfoInterface *reg_info_interface_p
argument_list|)
block|;
comment|// This function is implemented in the NativeRegisterContextLinux_* subclasses
comment|// to create a new
comment|// instance of the host specific NativeRegisterContextLinux. The
comment|// implementations can't collide
comment|// as only one NativeRegisterContextLinux_* variant should be compiled into
comment|// the final
comment|// executable.
specifier|static
name|NativeRegisterContextLinux
operator|*
name|CreateHostNativeRegisterContextLinux
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
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
block|;
name|virtual
name|Status
name|ReadRegisterRaw
argument_list|(
argument|uint32_t reg_index
argument_list|,
argument|RegisterValue&reg_value
argument_list|)
block|;
name|virtual
name|Status
name|WriteRegisterRaw
argument_list|(
argument|uint32_t reg_index
argument_list|,
argument|const RegisterValue&reg_value
argument_list|)
block|;
name|virtual
name|Status
name|ReadRegisterSet
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|unsigned int regset
argument_list|)
block|;
name|virtual
name|Status
name|WriteRegisterSet
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|,
argument|unsigned int regset
argument_list|)
block|;
name|virtual
name|Status
name|ReadGPR
argument_list|()
block|;
name|virtual
name|Status
name|WriteGPR
argument_list|()
block|;
name|virtual
name|Status
name|ReadFPR
argument_list|()
block|;
name|virtual
name|Status
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
comment|// The Do*** functions are executed on the privileged thread and can perform
comment|// ptrace
comment|// operations directly.
name|virtual
name|Status
name|DoReadRegisterValue
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const char *reg_name
argument_list|,
argument|uint32_t size
argument_list|,
argument|RegisterValue&value
argument_list|)
block|;
name|virtual
name|Status
name|DoWriteRegisterValue
argument_list|(
argument|uint32_t offset
argument_list|,
argument|const char *reg_name
argument_list|,
argument|const RegisterValue&value
argument_list|)
block|;
name|virtual
name|Status
name|DoReadGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|virtual
name|Status
name|DoWriteGPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|virtual
name|Status
name|DoReadFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
block|;
name|virtual
name|Status
name|DoWriteFPR
argument_list|(
argument|void *buf
argument_list|,
argument|size_t buf_size
argument_list|)
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
comment|// #ifndef lldb_NativeRegisterContextLinux_h
end_comment

end_unit

