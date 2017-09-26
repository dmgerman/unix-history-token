begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeRegisterContextRegisterInfo.h ---------------------*- C++ -*-===//
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
name|LLDB_PLUGINS_PROCESS_UTIILTY_NATIVE_REGISTER_CONTEXT_REGISTER_INFO
end_ifndef

begin_define
define|#
directive|define
name|LLDB_PLUGINS_PROCESS_UTIILTY_NATIVE_REGISTER_CONTEXT_REGISTER_INFO
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|"RegisterInfoInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeRegisterContext.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|NativeRegisterContextRegisterInfo
range|:
name|public
name|NativeRegisterContext
block|{
name|public
operator|:
comment|///
comment|/// Construct a NativeRegisterContextRegisterInfo, taking ownership
comment|/// of the register_info_interface pointer.
comment|///
name|NativeRegisterContextRegisterInfo
argument_list|(
argument|NativeThreadProtocol&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|RegisterInfoInterface *register_info_interface
argument_list|)
block|;
name|uint32_t
name|GetRegisterCount
argument_list|()
specifier|const
name|override
block|;
name|uint32_t
name|GetUserRegisterCount
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|uint32_t reg_index
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|RegisterInfoInterface
operator|&
name|GetRegisterInfoInterface
argument_list|()
specifier|const
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|RegisterInfoInterface
operator|>
name|m_register_info_interface_up
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

