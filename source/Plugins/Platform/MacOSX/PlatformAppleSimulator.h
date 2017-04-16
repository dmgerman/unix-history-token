begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformAppleSimulator.h --------------------------------*- C++ -*-===//
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
name|liblldb_PlatformAppleSimulator_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformAppleSimulator_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"PlatformDarwin.h"
end_include

begin_include
include|#
directive|include
file|"PlatformiOSSimulatorCoreSimulatorSupport.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_decl_stmt
name|class
name|PlatformAppleSimulator
range|:
name|public
name|PlatformDarwin
block|{
name|public
operator|:
comment|//------------------------------------------------------------
comment|// Class Functions
comment|//------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
comment|//------------------------------------------------------------
comment|// Class Methods
comment|//------------------------------------------------------------
name|PlatformAppleSimulator
argument_list|()
block|;
name|virtual
operator|~
name|PlatformAppleSimulator
argument_list|()
block|;
name|lldb_private
operator|::
name|Error
name|LaunchProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|)
name|override
block|;
name|void
name|GetStatus
argument_list|(
argument|lldb_private::Stream&strm
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|ConnectRemote
argument_list|(
argument|lldb_private::Args&args
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|DisconnectRemote
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|DebugProcess
argument_list|(
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|protected
operator|:
name|std
operator|::
name|mutex
name|m_core_sim_path_mutex
block|;
name|llvm
operator|::
name|Optional
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|>
name|m_core_simulator_framework_path
block|;
name|llvm
operator|::
name|Optional
operator|<
name|CoreSimulatorSupport
operator|::
name|Device
operator|>
name|m_device
block|;
name|lldb_private
operator|::
name|FileSpec
name|GetCoreSimulatorPath
argument_list|()
block|;
name|void
name|LoadCoreSimulator
argument_list|()
block|;
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
name|CoreSimulatorSupport
operator|::
name|Device
name|GetSimulatorDevice
argument_list|()
block|;
endif|#
directive|endif
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformAppleSimulator
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PlatformAppleSimulator_h_
end_comment

end_unit

