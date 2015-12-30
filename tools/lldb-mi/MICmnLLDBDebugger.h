begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBDebugger.h -------------------------------------*- C++ -*-===//
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
file|<condition_variable>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDebugger.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBListener.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBEvent.h"
end_include

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
file|"MIUtilThreadBaseStd.h"
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
name|CMIDriverBase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmnLLDBDebuggerHandleEvents
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI proxy/adapter for the LLDB public SBDebugger API. The CMIDriver
end_comment

begin_comment
comment|//          requires *this object. Command classes make calls on *this object
end_comment

begin_comment
comment|//          to facilitate their work effort. The instance runs in its own worker
end_comment

begin_comment
comment|//          thread.
end_comment

begin_comment
comment|//          A singleton class.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugger
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMIUtilThreadActiveObjBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnLLDBDebugger
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLLDBDebugger
operator|>
expr_stmt|;
comment|// Methods:
name|public
label|:
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
name|bool
name|SetDriver
parameter_list|(
specifier|const
name|CMIDriverBase
modifier|&
name|vClientDriver
parameter_list|)
function_decl|;
name|CMIDriverBase
operator|&
name|GetDriver
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBDebugger
operator|&
name|GetTheDebugger
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBListener
operator|&
name|GetTheListener
argument_list|()
expr_stmt|;
name|void
name|WaitForHandleEvent
parameter_list|()
function_decl|;
name|bool
name|CheckIfNeedToRebroadcastStopEvent
parameter_list|()
function_decl|;
name|void
name|RebroadcastStopEvent
parameter_list|()
function_decl|;
comment|// MI Commands can use these functions to listen for events they require
name|bool
name|RegisterForEvent
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vClientName
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|,
specifier|const
name|MIuint
name|vEventMask
parameter_list|)
function_decl|;
name|bool
name|UnregisterForEvent
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vClientName
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|)
function_decl|;
name|bool
name|RegisterForEvent
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vClientName
argument_list|,
specifier|const
name|lldb
operator|::
name|SBBroadcaster
operator|&
name|vBroadcaster
argument_list|,
specifier|const
name|MIuint
name|vEventMask
argument_list|)
decl_stmt|;
name|bool
name|UnregisterForEvent
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vClientName
argument_list|,
specifier|const
name|lldb
operator|::
name|SBBroadcaster
operator|&
name|vBroadcaster
argument_list|)
decl_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMIUtilThreadActiveObjBase
specifier|const
name|CMIUtilString
operator|&
name|ThreadGetName
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|// Overridden:
name|protected
label|:
comment|// From CMIUtilThreadActiveObjBase
name|bool
name|ThreadRun
argument_list|(
name|bool
operator|&
name|vrIsAlive
argument_list|)
name|override
decl_stmt|;
name|bool
name|ThreadFinish
argument_list|()
name|override
expr_stmt|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|MIuint
operator|>
name|MapBroadcastClassNameToEventMask_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|MIuint
operator|>
name|MapPairBroadcastClassNameToEventMask_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|MIuint
operator|>
name|MapIdToEventMask_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|MIuint
operator|>
name|MapPairIdToEventMask_t
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLLDBDebugger
argument_list|()
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugger
argument_list|(
specifier|const
name|CMICmnLLDBDebugger
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnLLDBDebugger
operator|&
operator|)
decl_stmt|;
name|bool
name|InitSBDebugger
parameter_list|()
function_decl|;
name|bool
name|InitSBListener
parameter_list|()
function_decl|;
name|bool
name|InitStdStreams
parameter_list|()
function_decl|;
name|bool
name|MonitorSBListenerEvents
parameter_list|(
name|bool
modifier|&
name|vrbYesExit
parameter_list|)
function_decl|;
name|bool
name|BroadcasterGetMask
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vBroadcasterClass
argument_list|,
name|MIuint
operator|&
name|vEventMask
argument_list|)
decl|const
decl_stmt|;
name|bool
name|BroadcasterRemoveMask
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|)
function_decl|;
name|bool
name|BroadcasterSaveMask
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|,
specifier|const
name|MIuint
name|vEventMask
parameter_list|)
function_decl|;
name|MIuint
name|ClientGetMaskForAllClients
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vBroadcasterClass
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ClientSaveMask
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vClientName
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|,
specifier|const
name|MIuint
name|vEventMask
parameter_list|)
function_decl|;
name|bool
name|ClientRemoveTheirMask
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vClientName
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|)
function_decl|;
name|bool
name|ClientGetTheirMask
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vClientName
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vBroadcasterClass
parameter_list|,
name|MIuint
modifier|&
name|vwEventMask
parameter_list|)
function_decl|;
name|bool
name|LoadMIFormatters
argument_list|(
name|lldb
operator|::
name|SBTypeCategory
name|miCategory
argument_list|)
decl_stmt|;
name|bool
name|RegisterMISummaryProviders
parameter_list|()
function_decl|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnLLDBDebugger
argument_list|()
name|override
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIDriverBase
modifier|*
name|m_pClientDriver
decl_stmt|;
comment|// The driver that wants to use *this LLDB debugger
name|lldb
operator|::
name|SBDebugger
name|m_lldbDebugger
expr_stmt|;
comment|// SBDebugger is the primordial object that creates SBTargets and provides access to them
name|lldb
operator|::
name|SBListener
name|m_lldbListener
expr_stmt|;
comment|// API clients can register its own listener to debugger events
specifier|const
name|CMIUtilString
name|m_constStrThisThreadId
decl_stmt|;
name|MapBroadcastClassNameToEventMask_t
name|m_mapBroadcastClassNameToEventMask
decl_stmt|;
name|MapIdToEventMask_t
name|m_mapIdToEventMask
decl_stmt|;
name|std
operator|::
name|mutex
name|m_mutexEventQueue
expr_stmt|;
name|std
operator|::
name|condition_variable
name|m_conditionEventQueueEmpty
expr_stmt|;
name|uint32_t
name|m_nLastStopId
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

