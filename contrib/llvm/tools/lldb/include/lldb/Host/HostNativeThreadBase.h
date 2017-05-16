begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostNativeThreadBase.h ----------------------------------*- C++ -*-===//
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
name|lldb_Host_HostNativeThreadBase_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostNativeThreadBase_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
define|#
directive|define
name|THREAD_ROUTINE
value|__stdcall
else|#
directive|else
define|#
directive|define
name|THREAD_ROUTINE
endif|#
directive|endif
name|class
name|HostNativeThreadBase
block|{
name|friend
name|class
name|ThreadLauncher
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HostNativeThreadBase
argument_list|)
expr_stmt|;
name|public
label|:
name|HostNativeThreadBase
argument_list|()
expr_stmt|;
name|explicit
name|HostNativeThreadBase
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|HostNativeThreadBase
argument_list|()
block|{}
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
operator|=
literal|0
expr_stmt|;
name|virtual
name|Status
name|Cancel
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|IsJoinable
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|Reset
parameter_list|()
function_decl|;
name|lldb
operator|::
name|thread_t
name|Release
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|thread_t
name|GetSystemHandle
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|thread_result_t
name|GetResult
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
specifier|static
name|lldb
operator|::
name|thread_result_t
name|THREAD_ROUTINE
name|ThreadCreateTrampoline
argument_list|(
argument|lldb::thread_arg_t arg
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|thread_t
name|m_thread
expr_stmt|;
name|lldb
operator|::
name|thread_result_t
name|m_result
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

