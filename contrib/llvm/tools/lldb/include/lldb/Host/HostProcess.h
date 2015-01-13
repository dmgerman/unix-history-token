begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostProcess.h ------------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostProcess_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostProcess_h_
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class HostInfo HostInfo.h "lldb/Host/HostProcess.h"
end_comment

begin_comment
comment|/// @brief A class that represents a running process on the host machine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostProcess allows querying and manipulation of processes running on the
end_comment

begin_comment
comment|/// host machine.  It is not intended to be represent a process which is
end_comment

begin_comment
comment|/// being debugged, although the native debug engine of a platform may likely
end_comment

begin_comment
comment|/// back inferior processes by a HostProcess.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostProcess is implemented using static polymorphism so that on any given
end_comment

begin_comment
comment|/// platform, an instance of HostProcess will always be able to bind statically
end_comment

begin_comment
comment|/// to the concrete Process implementation for that platform.  See HostInfo
end_comment

begin_comment
comment|/// for more details.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/windows/HostProcessWindows.h"
end_include

begin_define
define|#
directive|define
name|HOST_PROCESS_TYPE
value|HostProcessWindows
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"lldb/Host/posix/HostProcessPosix.h"
end_include

begin_define
define|#
directive|define
name|HOST_PROCESS_TYPE
value|HostProcessPosix
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|HOST_PROCESS_TYPE
name|HostProcess
typedef|;
block|}
end_decl_stmt

begin_undef
undef|#
directive|undef
name|HOST_PROCESS_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

