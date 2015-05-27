begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdGdbInfo.h --------------------------*- C++ -*-===//
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
comment|// File:        MICmdCmdGdbInfo.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdCmdGdbInfo    interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              To implement new MI commands derive a new command class from the command base
end_comment

begin_comment
comment|//              class. To enable the new command for interpretation add the new command class
end_comment

begin_comment
comment|//              to the command factory. The files of relevance are:
end_comment

begin_comment
comment|//                  MICmdCommands.cpp
end_comment

begin_comment
comment|//                  MICmdBase.h / .cpp
end_comment

begin_comment
comment|//                  MICmdCmd.h / .cpp
end_comment

begin_comment
comment|//              For an introduction to adding a new command see CMICmdCmdSupportInfoMiCmdQuery
end_comment

begin_comment
comment|//              command class as an example.
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

begin_comment
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmdBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements GDB command "info".
end_comment

begin_comment
comment|//          The design of matching the info request to a request action (or
end_comment

begin_comment
comment|//          command) is very simple. The request function which carries out
end_comment

begin_comment
comment|//          the task of information gathering and printing to stdout is part of
end_comment

begin_comment
comment|//          *this class. Should the request function become more complicated then
end_comment

begin_comment
comment|//          that request should really reside in a command type class. Then this
end_comment

begin_comment
comment|//          class instantiates a request info command for a matching request. The
end_comment

begin_comment
comment|//          design/code of *this class then does not then become bloated. Use a
end_comment

begin_comment
comment|//          lightweight version of the current MI command system.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 05/06/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdGdbInfo
range|:
name|public
name|CMICmdBase
block|{
comment|// Statics:
name|public
operator|:
comment|// Required by the CMICmdFactory when registering *this command
specifier|static
name|CMICmdBase
operator|*
name|CreateSelf
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdGdbInfo
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|virtual
name|bool
name|Execute
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|Acknowledge
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|ParseArgs
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdCmdGdbInfo
argument_list|(
name|void
argument_list|)
block|;
comment|// Typedefs:
name|private
operator|:
typedef|typedef
name|bool
argument_list|(
name|CMICmdCmdGdbInfo
operator|::
operator|*
name|FnPrintPtr
argument_list|)
argument_list|()
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|FnPrintPtr
operator|>
name|MapPrintFnNameToPrintFn_t
expr_stmt|;
end_typedef

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|GetPrintFn
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrPrintFnName
argument_list|,
name|FnPrintPtr
operator|&
name|vrwpFn
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|PrintFnSharedLibrary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Attributes:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
specifier|static
name|MapPrintFnNameToPrintFn_t
name|ms_mapPrintFnNameToPrintFn
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedPrint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_bPrintFnRecognised
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = This command has a function with a name that matches the Print argument, false = not found
end_comment

begin_decl_stmt
name|bool
name|m_bPrintFnSuccessful
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = The print function completed its task ok, false = function failed for some reason
end_comment

begin_decl_stmt
name|CMIUtilString
name|m_strPrintFnName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|m_strPrintFnError
decl_stmt|;
end_decl_stmt

unit|};
end_unit

