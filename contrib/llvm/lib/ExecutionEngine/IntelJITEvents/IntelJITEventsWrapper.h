begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IntelJITEventsWrapper.h - Intel JIT Events API Wrapper --*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file defines a wrapper for the Intel JIT Events API. It allows for the
end_comment

begin_comment
comment|// implementation of the jitprofiling library to be swapped with an alternative
end_comment

begin_comment
comment|// implementation (for testing). To include this file, you must have the
end_comment

begin_comment
comment|// jitprofiling.h header available; it is available in Intel(R) VTune(TM)
end_comment

begin_comment
comment|// Amplifier XE 2011.
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
name|INTEL_JIT_EVENTS_WRAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|INTEL_JIT_EVENTS_WRAPPER_H
end_define

begin_include
include|#
directive|include
file|"jitprofiling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IntelJITEventsWrapper
block|{
comment|// Function pointer types for testing implementation of Intel jitprofiling
comment|// library
typedef|typedef
name|int
function_decl|(
modifier|*
name|NotifyEventPtr
function_decl|)
parameter_list|(
name|iJIT_JVM_EVENT
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|RegisterCallbackExPtr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|iJIT_ModeChangedEx
parameter_list|)
function_decl|;
typedef|typedef
name|iJIT_IsProfilingActiveFlags
function_decl|(
modifier|*
name|IsProfilingActivePtr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|FinalizeThreadPtr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|FinalizeProcessPtr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
typedef|typedef
name|unsigned
name|int
function_decl|(
modifier|*
name|GetNewMethodIDPtr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|NotifyEventPtr
name|NotifyEventFunc
decl_stmt|;
name|RegisterCallbackExPtr
name|RegisterCallbackExFunc
decl_stmt|;
name|IsProfilingActivePtr
name|IsProfilingActiveFunc
decl_stmt|;
name|GetNewMethodIDPtr
name|GetNewMethodIDFunc
decl_stmt|;
name|public
label|:
name|bool
name|isAmplifierRunning
parameter_list|()
block|{
return|return
name|iJIT_IsProfilingActive
argument_list|()
operator|==
name|iJIT_SAMPLING_ON
return|;
block|}
name|IntelJITEventsWrapper
argument_list|()
operator|:
name|NotifyEventFunc
argument_list|(
operator|::
name|iJIT_NotifyEvent
argument_list|)
operator|,
name|RegisterCallbackExFunc
argument_list|(
operator|::
name|iJIT_RegisterCallbackEx
argument_list|)
operator|,
name|IsProfilingActiveFunc
argument_list|(
operator|::
name|iJIT_IsProfilingActive
argument_list|)
operator|,
name|GetNewMethodIDFunc
argument_list|(
argument|::iJIT_GetNewMethodID
argument_list|)
block|{   }
name|IntelJITEventsWrapper
argument_list|(
argument|NotifyEventPtr NotifyEventImpl
argument_list|,
argument|RegisterCallbackExPtr RegisterCallbackExImpl
argument_list|,
argument|IsProfilingActivePtr IsProfilingActiveImpl
argument_list|,
argument|FinalizeThreadPtr FinalizeThreadImpl
argument_list|,
argument|FinalizeProcessPtr FinalizeProcessImpl
argument_list|,
argument|GetNewMethodIDPtr GetNewMethodIDImpl
argument_list|)
operator|:
name|NotifyEventFunc
argument_list|(
name|NotifyEventImpl
argument_list|)
operator|,
name|RegisterCallbackExFunc
argument_list|(
name|RegisterCallbackExImpl
argument_list|)
operator|,
name|IsProfilingActiveFunc
argument_list|(
name|IsProfilingActiveImpl
argument_list|)
operator|,
name|GetNewMethodIDFunc
argument_list|(
argument|GetNewMethodIDImpl
argument_list|)
block|{   }
comment|// Sends an event announcing that a function has been emitted
comment|//   return values are event-specific.  See Intel documentation for details.
name|int
name|iJIT_NotifyEvent
argument_list|(
argument|iJIT_JVM_EVENT EventType
argument_list|,
argument|void *EventSpecificData
argument_list|)
block|{
if|if
condition|(
operator|!
name|NotifyEventFunc
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|NotifyEventFunc
argument_list|(
name|EventType
argument_list|,
name|EventSpecificData
argument_list|)
return|;
block|}
comment|// Registers a callback function to receive notice of profiling state changes
name|void
name|iJIT_RegisterCallbackEx
parameter_list|(
name|void
modifier|*
name|UserData
parameter_list|,
name|iJIT_ModeChangedEx
name|NewModeCallBackFuncEx
parameter_list|)
block|{
if|if
condition|(
name|RegisterCallbackExFunc
condition|)
name|RegisterCallbackExFunc
argument_list|(
name|UserData
argument_list|,
name|NewModeCallBackFuncEx
argument_list|)
expr_stmt|;
block|}
comment|// Returns the current profiler mode
name|iJIT_IsProfilingActiveFlags
name|iJIT_IsProfilingActive
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|IsProfilingActiveFunc
condition|)
return|return
name|iJIT_NOTHING_RUNNING
return|;
return|return
name|IsProfilingActiveFunc
argument_list|()
return|;
block|}
comment|// Generates a locally unique method ID for use in code registration
name|unsigned
name|int
name|iJIT_GetNewMethodID
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|GetNewMethodIDFunc
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|GetNewMethodIDFunc
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|//namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//INTEL_JIT_EVENTS_WRAPPER_H
end_comment

end_unit

