begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilDebug.h -------------------------------------------*- C++ -*-===//
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
comment|// File:        MIUtilDebug.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMIUtilDebug interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_define
define|#
directive|define
name|MI_USE_DEBUG_TRACE_FN
end_define

begin_comment
comment|// Undefine to compile out fn trace code
end_comment

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLog
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI debugging aid utility class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors:
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilDebug
block|{
comment|// Statics:
name|public
label|:
specifier|static
name|void
name|ShowDlgWaitForDbgAttach
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|WaitForDbgAttachInfinteLoop
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilDebug
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Overrideable:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilDebug
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI debug utility class. Used to indicate the current function
end_comment

begin_comment
comment|//          depth in the call stack. It uses the CMIlCmnLog logger to output
end_comment

begin_comment
comment|//          the current fn trace information.
end_comment

begin_comment
comment|//          Use macro MI_TRACEFN( "Some fn name" ) and implement the scope of
end_comment

begin_comment
comment|//          the functions you wish to build up a trace off.
end_comment

begin_comment
comment|//          Use preprocessor definition MI_USE_DEBUG_TRACE_FN to turn off or on
end_comment

begin_comment
comment|//          tracing code.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 07/03/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilDebugFnTrace
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilDebugFnTrace
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vFnName
argument_list|)
expr_stmt|;
comment|// Overrideable:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilDebugFnTrace
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
specifier|const
name|CMIUtilString
name|m_strFnName
decl_stmt|;
specifier|static
name|CMICmnLog
modifier|&
name|ms_rLog
decl_stmt|;
specifier|static
name|MIuint
name|ms_fnDepthCnt
decl_stmt|;
comment|// Increment count as fn depth increases, decrement count as fn stack pops off
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: Take the given text and send it to the server's Logger to output to the
end_comment

begin_comment
comment|//          trace file.
end_comment

begin_comment
comment|// Type:    Compile preprocess.
end_comment

begin_comment
comment|// Args:    x   - (R) Message (may be seen by user).
end_comment

begin_comment
comment|//--
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MI_USE_DEBUG_TRACE_FN
end_ifdef

begin_define
define|#
directive|define
name|MI_TRACEFN
parameter_list|(
name|x
parameter_list|)
value|CMIUtilDebugFnTrace __MITrace(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MI_TRACEFN
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MI_USE_DEBUG_TRACE_FN
end_comment

end_unit

