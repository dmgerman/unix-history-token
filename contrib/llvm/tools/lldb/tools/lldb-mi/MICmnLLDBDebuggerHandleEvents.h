begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBDebuggerHandleEvents.h -------------------------*- C++ -*-===//
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

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:		MICmnLLDBDebuggerHandleEvents.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnLLDBDebuggerHandleEvents interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment:	Compilers:	Visual C++ 12.
end_comment

begin_comment
comment|//							gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//				Libraries:	See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueTuple.h"
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
name|CMICmnLLDBDebugSessionInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnMIResultRecord
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnStreamStdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnMIOutOfBandRecord
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI class to take LLDB SBEvent objects, filter them and form
end_comment

begin_comment
comment|//			MI Out-of-band records from the information inside the event object.
end_comment

begin_comment
comment|//			These records are then pushed to stdout.
end_comment

begin_comment
comment|//			A singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 02/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebuggerHandleEvents
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnLLDBDebuggerHandleEvents
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLLDBDebuggerHandleEvents
operator|>
expr_stmt|;
comment|// Methods:
name|public
label|:
name|bool
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|//
name|bool
name|HandleEvent
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|,
name|bool
operator|&
name|vrbHandledEvent
argument_list|,
name|bool
operator|&
name|vrbExitAppEvent
argument_list|)
decl_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLLDBDebuggerHandleEvents
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebuggerHandleEvents
argument_list|(
specifier|const
name|CMICmnLLDBDebuggerHandleEvents
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnLLDBDebuggerHandleEvents
operator|&
operator|)
decl_stmt|;
comment|//
name|bool
name|ChkForStateChanges
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|GetProcessStdout
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|GetProcessStderr
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|HandleEventSBBreakPoint
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBBreakpointCmn
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBBreakpointAdded
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBBreakpointLocationsAdded
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBProcess
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|,
name|bool
operator|&
name|vrbExitAppEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBThread
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBThreadBitStackChanged
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBThreadSuspended
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleEventSBCommandInterpreter
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleProcessEventBroadcastBitStateChanged
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|,
name|bool
operator|&
name|vrbExitAppEvent
argument_list|)
decl_stmt|;
name|bool
name|HandleProcessEventStateRunning
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStateExited
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStateStopped
parameter_list|(
name|bool
modifier|&
name|vwrbShouldBrk
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStopReasonTrace
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStopReasonBreakpoint
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStopSignal
parameter_list|(
name|bool
modifier|&
name|vwrbShouldBrk
parameter_list|)
function_decl|;
name|bool
name|HandleProcessEventStateSuspended
argument_list|(
specifier|const
name|lldb
operator|::
name|SBEvent
operator|&
name|vEvent
argument_list|)
decl_stmt|;
name|bool
name|MiHelpGetCurrentThreadFrame
parameter_list|(
name|CMICmnMIValueTuple
modifier|&
name|vwrMiValueTuple
parameter_list|)
function_decl|;
name|bool
name|MiResultRecordToStdout
parameter_list|(
specifier|const
name|CMICmnMIResultRecord
modifier|&
name|vrMiResultRecord
parameter_list|)
function_decl|;
name|bool
name|MiOutOfBandRecordToStdout
parameter_list|(
specifier|const
name|CMICmnMIOutOfBandRecord
modifier|&
name|vrMiResultRecord
parameter_list|)
function_decl|;
name|bool
name|MiStoppedAtBreakPoint
argument_list|(
specifier|const
name|MIuint64
name|vBrkPtId
argument_list|,
specifier|const
name|lldb
operator|::
name|SBBreakpoint
operator|&
name|vBrkPt
argument_list|)
decl_stmt|;
name|bool
name|TextToStdout
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrTxt
parameter_list|)
function_decl|;
name|bool
name|TextToStderr
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrTxt
parameter_list|)
function_decl|;
name|bool
name|UpdateSelectedThread
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|ConvertPrintfCtrlCodeToString
parameter_list|(
specifier|const
name|MIchar
name|vCtrl
parameter_list|,
name|CMIUtilString
modifier|&
name|vwrStrEquivalent
parameter_list|)
function_decl|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnLLDBDebuggerHandleEvents
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

