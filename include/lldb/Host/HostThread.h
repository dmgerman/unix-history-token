begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostThread.h --------------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostThread_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostThread_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/HostNativeThreadForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|HostNativeThreadBase
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class HostInfo HostInfo.h "lldb/Host/HostThread.h"
comment|/// @brief A class that represents a thread running inside of a process on the
comment|///        local machine.
comment|///
comment|/// HostThread allows querying and manipulation of threads running on the host
comment|/// machine.
comment|///
comment|//----------------------------------------------------------------------
name|class
name|HostThread
block|{
name|public
label|:
name|HostThread
argument_list|()
expr_stmt|;
name|HostThread
argument_list|(
argument|lldb::thread_t thread
argument_list|)
empty_stmt|;
name|Error
name|Join
argument_list|(
name|lldb
operator|::
name|thread_result_t
operator|*
name|result
argument_list|)
decl_stmt|;
name|Error
name|Cancel
parameter_list|()
function_decl|;
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
name|bool
name|IsJoinable
argument_list|()
specifier|const
expr_stmt|;
name|HostNativeThread
modifier|&
name|GetNativeThread
parameter_list|()
function_decl|;
specifier|const
name|HostNativeThread
operator|&
name|GetNativeThread
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
name|bool
name|EqualsThread
argument_list|(
name|lldb
operator|::
name|thread_t
name|thread
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|std
operator|::
name|shared_ptr
operator|<
name|HostNativeThreadBase
operator|>
name|m_native_thread
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

