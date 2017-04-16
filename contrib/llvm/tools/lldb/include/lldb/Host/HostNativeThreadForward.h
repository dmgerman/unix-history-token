begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostNativeThreadForward.h -------------------------------*- C++ -*-===//
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
name|lldb_Host_HostNativeThreadForward_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostNativeThreadForward_h_
end_define

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
name|class
name|HostThreadWindows
decl_stmt|;
typedef|typedef
name|HostThreadWindows
name|HostNativeThread
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
name|class
name|HostThreadMacOSX
decl_stmt|;
typedef|typedef
name|HostThreadMacOSX
name|HostNativeThread
typedef|;
else|#
directive|else
name|class
name|HostThreadPosix
decl_stmt|;
typedef|typedef
name|HostThreadPosix
name|HostNativeThread
typedef|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

