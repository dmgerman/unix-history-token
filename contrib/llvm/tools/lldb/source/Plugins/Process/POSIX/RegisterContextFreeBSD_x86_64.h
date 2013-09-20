begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextFreeBSD_x86_64.h ---------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextFreeBSD_x86_64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextFreeBSD_x86_64_H_
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/POSIX/RegisterContext_x86_64.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextFreeBSD_x86_64
range|:
name|public
name|RegisterContext_x86_64
block|{
name|public
operator|:
name|RegisterContextFreeBSD_x86_64
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
name|size_t
name|GetGPRSize
argument_list|()
block|;
name|protected
operator|:
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
name|void
name|UpdateRegisterInfo
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

