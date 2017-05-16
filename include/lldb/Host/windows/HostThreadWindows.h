begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostThreadWindows.h -------------------------------------*- C++ -*-===//
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
name|lldb_Host_windows_HostThreadWindows_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_windows_HostThreadWindows_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostNativeThreadBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostThreadWindows
range|:
name|public
name|HostNativeThreadBase
block|{
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HostThreadWindows
argument_list|)
block|;
name|public
operator|:
name|HostThreadWindows
argument_list|()
block|;
name|HostThreadWindows
argument_list|(
argument|lldb::thread_t thread
argument_list|)
block|;
name|virtual
operator|~
name|HostThreadWindows
argument_list|()
block|;
name|void
name|SetOwnsHandle
argument_list|(
argument|bool owns
argument_list|)
block|;
name|virtual
name|Status
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
name|Status
name|Cancel
argument_list|()
block|;
name|virtual
name|void
name|Reset
argument_list|()
block|;
name|lldb
operator|::
name|tid_t
name|GetThreadId
argument_list|()
specifier|const
block|;
name|private
operator|:
name|bool
name|m_owns_handle
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

