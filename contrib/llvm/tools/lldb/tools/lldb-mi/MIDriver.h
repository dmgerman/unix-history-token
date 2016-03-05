begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIDriver.h ----------------------------------------------*- C++ -*-===//
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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<queue>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnConfig.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIDriverBase.h"
end_include

begin_include
include|#
directive|include
file|"MIDriverMgr.h"
end_include

begin_include
include|#
directive|include
file|"MICmnStreamStdin.h"
end_include

begin_include
include|#
directive|include
file|"MICmdData.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugger
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnStreamStdout
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI driver implementation class. A singleton class derived from
end_comment

begin_comment
comment|//          LLDB SBBroadcaster class. Register the instance of *this class with
end_comment

begin_comment
comment|//          the CMIDriverMgr. The CMIDriverMgr sets the driver(s) of to start
end_comment

begin_comment
comment|//          work depending on the one selected to work. A driver can if not able
end_comment

begin_comment
comment|//          to handle an instruction or 'command' can pass that command onto
end_comment

begin_comment
comment|//          another driver object registered with the Driver Manager.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIDriver
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMIDriverMgr
decl|::
name|IDriver
decl_stmt|,
name|public
name|CMIDriverBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMIDriver
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMIDriver
operator|>
expr_stmt|;
comment|// Enumerations:
name|public
label|:
comment|//++ ----------------------------------------------------------------------
comment|// Details: The MI Driver has a running state which is used to help determine
comment|//          which specific action(s) it should take or not allow.
comment|//          The driver when operational and not shutting down alternates
comment|//          between eDriverState_RunningNotDebugging and
comment|//          eDriverState_RunningDebugging. eDriverState_RunningNotDebugging
comment|//          is normally set when a breakpoint is hit or halted.
comment|//          eDriverState_RunningDebugging is normally set when "exec-continue"
comment|//          or "exec-run" is issued.
comment|//--
enum|enum
name|DriverState_e
block|{
name|eDriverState_NotRunning
init|=
literal|0
block|,
comment|// The MI Driver is not operating
name|eDriverState_Initialising
block|,
comment|// The MI Driver is setting itself up
name|eDriverState_RunningNotDebugging
block|,
comment|// The MI Driver is operational acting on any MI commands sent to it
name|eDriverState_RunningDebugging
block|,
comment|// The MI Driver is currently overseeing an inferior program that is running
name|eDriverState_ShuttingDown
block|,
comment|// The MI Driver is tearing down resources and about exit
name|eDriverState_count
comment|// Always last
block|}
enum|;
comment|// Methods:
name|public
label|:
comment|// MI system
name|bool
name|Initialize
argument_list|()
name|override
expr_stmt|;
name|bool
name|Shutdown
argument_list|()
name|override
expr_stmt|;
comment|// MI state
name|bool
name|GetExitApplicationFlag
argument_list|()
specifier|const
expr_stmt|;
name|DriverState_e
name|GetCurrentDriverState
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetDriverStateRunningNotDebugging
parameter_list|()
function_decl|;
name|bool
name|SetDriverStateRunningDebugging
parameter_list|()
function_decl|;
name|void
name|SetDriverDebuggingArgExecutable
parameter_list|()
function_decl|;
name|bool
name|IsDriverDebuggingArgExecutable
argument_list|()
specifier|const
expr_stmt|;
comment|// MI information about itself
specifier|const
name|CMIUtilString
operator|&
name|GetAppNameShort
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetAppNameLong
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetVersionDescription
argument_list|()
specifier|const
expr_stmt|;
comment|// MI do work
name|bool
name|WriteMessageToLog
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vMessage
parameter_list|)
function_decl|;
name|bool
name|SetEnableFallThru
parameter_list|(
specifier|const
name|bool
name|vbYes
parameter_list|)
function_decl|;
name|bool
name|GetEnableFallThru
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HaveExecutableFileNamePathOnCmdLine
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetExecutableFileNamePathOnCmdLine
argument_list|()
specifier|const
expr_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMIDriverMgr::IDriver
name|bool
name|DoInitialize
argument_list|()
name|override
expr_stmt|;
name|bool
name|DoShutdown
argument_list|()
name|override
expr_stmt|;
name|bool
name|DoMainLoop
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|SBError
name|DoParseArgs
argument_list|(
argument|const int argc
argument_list|,
argument|const char *argv[]
argument_list|,
argument|FILE *vpStdOut
argument_list|,
argument|bool&vwbExiting
argument_list|)
name|override
expr_stmt|;
name|CMIUtilString
name|GetError
argument_list|()
specifier|const
name|override
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetName
argument_list|()
specifier|const
name|override
expr_stmt|;
name|lldb
operator|::
name|SBDebugger
operator|&
name|GetTheDebugger
argument_list|()
name|override
expr_stmt|;
name|bool
name|GetDriverIsGDBMICompatibleDriver
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|SetId
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vId
argument_list|)
name|override
decl_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetId
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|// From CMIDriverBase
name|void
name|SetExitApplicationFlag
argument_list|(
specifier|const
name|bool
name|vbForceExit
argument_list|)
name|override
decl_stmt|;
name|bool
name|DoFallThruToAnotherDriver
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vCmd
argument_list|,
name|CMIUtilString
operator|&
name|vwErrMsg
argument_list|)
name|override
decl_stmt|;
name|bool
name|SetDriverToFallThruTo
argument_list|(
specifier|const
name|CMIDriverBase
operator|&
name|vrOtherDriver
argument_list|)
name|override
decl_stmt|;
name|FILE
operator|*
name|GetStdin
argument_list|()
specifier|const
name|override
expr_stmt|;
name|FILE
operator|*
name|GetStdout
argument_list|()
specifier|const
name|override
expr_stmt|;
name|FILE
operator|*
name|GetStderr
argument_list|()
specifier|const
name|override
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetDriverName
argument_list|()
specifier|const
name|override
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetDriverId
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|DeliverSignal
argument_list|(
name|int
name|signal
argument_list|)
name|override
decl_stmt|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|queue
operator|<
name|CMIUtilString
operator|>
name|QueueStdinLine_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMIDriver
argument_list|()
expr_stmt|;
comment|/* ctor */
name|CMIDriver
argument_list|(
specifier|const
name|CMIDriver
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMIDriver
operator|&
operator|)
decl_stmt|;
name|lldb
operator|::
name|SBError
name|ParseArgs
argument_list|(
argument|const int argc
argument_list|,
argument|const char *argv[]
argument_list|,
argument|FILE *vpStdOut
argument_list|,
argument|bool&vwbExiting
argument_list|)
expr_stmt|;
name|bool
name|DoAppQuit
parameter_list|()
function_decl|;
name|bool
name|InterpretCommand
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|)
function_decl|;
name|bool
name|InterpretCommandThisDriver
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|,
name|bool
modifier|&
name|vwbCmdYesValid
parameter_list|)
function_decl|;
name|CMIUtilString
name|WrapCLICommandIntoMICommand
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vTextLine
argument_list|)
decl|const
decl_stmt|;
name|bool
name|InterpretCommandFallThruDriver
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|,
name|bool
modifier|&
name|vwbCmdYesValid
parameter_list|)
function_decl|;
name|bool
name|ExecuteCommand
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|)
function_decl|;
name|bool
name|StartWorkerThreads
parameter_list|()
function_decl|;
name|bool
name|StopWorkerThreads
parameter_list|()
function_decl|;
name|bool
name|InitClientIDEToMIDriver
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|InitClientIDEEclipse
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|LocalDebugSessionStartupExecuteCommands
parameter_list|()
function_decl|;
name|bool
name|ExecuteCommandFile
parameter_list|(
specifier|const
name|bool
name|vbAsyncMode
parameter_list|)
function_decl|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMIDriver
argument_list|()
name|override
expr_stmt|;
comment|// Attributes:
name|private
label|:
specifier|static
specifier|const
name|CMIUtilString
name|ms_constAppNameShort
decl_stmt|;
specifier|static
specifier|const
name|CMIUtilString
name|ms_constAppNameLong
decl_stmt|;
specifier|static
specifier|const
name|CMIUtilString
name|ms_constMIVersion
decl_stmt|;
comment|//
name|bool
name|m_bFallThruToOtherDriverEnabled
decl_stmt|;
comment|// True = yes fall through, false = do not pass on command
name|CMIUtilThreadMutex
name|m_threadMutex
decl_stmt|;
name|bool
name|m_bDriverIsExiting
decl_stmt|;
comment|// True = yes, driver told to quit, false = continue working
name|void
modifier|*
name|m_handleMainThread
decl_stmt|;
comment|// *this driver is run by the main thread
name|CMICmnStreamStdin
modifier|&
name|m_rStdin
decl_stmt|;
name|CMICmnLLDBDebugger
modifier|&
name|m_rLldbDebugger
decl_stmt|;
name|CMICmnStreamStdout
modifier|&
name|m_rStdOut
decl_stmt|;
name|DriverState_e
name|m_eCurrentDriverState
decl_stmt|;
name|bool
name|m_bHaveExecutableFileNamePathOnCmdLine
decl_stmt|;
comment|// True = yes, executable given as one of the parameters to the MI Driver, false = not found
name|CMIUtilString
name|m_strCmdLineArgExecuteableFileNamePath
decl_stmt|;
name|bool
name|m_bDriverDebuggingArgExecutable
decl_stmt|;
comment|// True = the MI Driver (MI mode) is debugging executable passed as argument,
comment|// false = running via a client (e.g. Eclipse)
name|bool
name|m_bHaveCommandFileNamePathOnCmdLine
decl_stmt|;
comment|// True = file with initial commands given as one of the parameters to the MI Driver, false = not found
name|CMIUtilString
name|m_strCmdLineArgCommandFileNamePath
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

