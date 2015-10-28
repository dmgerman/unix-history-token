begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextLinux_mips64.h ---------------------------*- C++ -*-===//
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
name|__mips__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_RegisterContextLinux_mips64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextLinux_mips64_H_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"RegisterInfoInterface.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextLinux_mips64
range|:
name|public
name|lldb_private
operator|::
name|RegisterInfoInterface
block|{
name|public
operator|:
name|RegisterContextLinux_mips64
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|size_t
name|GetGPRSize
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
specifier|const
name|override
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
name|private
operator|:
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|m_register_info_p
block|;
name|uint32_t
name|m_register_info_count
block|;
name|uint32_t
name|m_user_register_count
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

