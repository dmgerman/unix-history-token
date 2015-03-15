begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostThreadPosix.h -------------------------------------*- C++ -*-===//
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
name|lldb_Host_posix_HostThreadPosix_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_posix_HostThreadPosix_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostNativeThreadBase.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostThreadPosix
range|:
name|public
name|HostNativeThreadBase
block|{
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HostThreadPosix
argument_list|)
block|;
name|public
operator|:
name|HostThreadPosix
argument_list|()
block|;
name|HostThreadPosix
argument_list|(
argument|lldb::thread_t thread
argument_list|)
block|;
name|virtual
operator|~
name|HostThreadPosix
argument_list|()
block|;
name|virtual
name|Error
name|Join
argument_list|(
name|lldb
operator|::
name|thread_result_t
operator|*
name|result
argument_list|)
block|;
name|virtual
name|Error
name|Cancel
argument_list|()
block|;
name|Error
name|Detach
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

