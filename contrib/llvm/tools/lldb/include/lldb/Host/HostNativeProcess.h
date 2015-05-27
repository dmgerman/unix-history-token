begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostNativeProcess.h -------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostNativeProcess_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostNativeProcess_h_
end_define

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|HostProcessWindows
name|HostNativeProcess
typedef|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"lldb/Host/posix/HostProcessPosix.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|HostProcessPosix
name|HostNativeProcess
typedef|;
block|}
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

