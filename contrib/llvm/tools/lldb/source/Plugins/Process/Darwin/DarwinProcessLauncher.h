begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DarwinProcessLauncher.h ---------------------------------*- C++ -*-===//
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
name|DarwinProcessLauncher_h
end_ifndef

begin_define
define|#
directive|define
name|DarwinProcessLauncher_h
end_define

begin_comment
comment|// C headers
end_comment

begin_include
include|#
directive|include
file|<mach/machine.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|// C++ headers
end_comment

begin_include
include|#
directive|include
file|<functional>
end_include

begin_comment
comment|// LLDB headers
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"LaunchFlavor.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|darwin_process_launcher
block|{
comment|// =============================================================================
comment|/// Launches a process for debugging.
comment|///
comment|/// @param[inout] launch_info
comment|///     Specifies details about the process to launch (e.g. path, architecture,
comment|///     etc.).  On output, includes the launched ProcessID (pid).
comment|///
comment|/// @param[out] pty_master_fd
comment|///     Returns the master side of the pseudo-terminal used to communicate
comment|///     with stdin/stdout from the launched process.  May be nullptr.
comment|///
comment|/// @param[out] launch_flavor
comment|///     Contains the launch flavor used when launching the process.
comment|// =============================================================================
name|Status
name|LaunchInferior
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|int
operator|*
name|pty_master_fd
argument_list|,
name|lldb_private
operator|::
name|process_darwin
operator|::
name|LaunchFlavor
operator|*
name|launch_flavor
argument_list|)
decl_stmt|;
block|}
comment|// darwin_process_launcher
block|}
end_decl_stmt

begin_comment
comment|// lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DarwinProcessLauncher_h */
end_comment

end_unit

