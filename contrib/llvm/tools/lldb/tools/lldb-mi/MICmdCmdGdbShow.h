begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdGdbShow.h ---------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdGdbShow interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              To implement new MI commands, derive a new command class from the command base
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
file|"MICmdBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "gdb-show".
end_comment

begin_comment
comment|//          This command does not follow the MI documentation exactly. While *this
end_comment

begin_comment
comment|//          command is implemented it does not do anything with the gdb-set
end_comment

begin_comment
comment|//          variable past in.
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
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdGdbShow
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
argument_list|()
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdCmdGdbShow
argument_list|()
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdInvoker::ICmd
name|bool
name|Execute
argument_list|()
name|override
block|;
name|bool
name|Acknowledge
argument_list|()
name|override
block|;
name|bool
name|ParseArgs
argument_list|()
name|override
block|;
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdGdbShow
argument_list|()
name|override
block|;
comment|// Typedefs:
name|private
operator|:
typedef|typedef
name|bool
argument_list|(
name|CMICmdCmdGdbShow
operator|::
operator|*
name|FnGdbOptionPtr
argument_list|)
argument_list|(
specifier|const
name|CMIUtilString
operator|::
name|VecString_t
operator|&
name|vrWords
argument_list|)
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
name|FnGdbOptionPtr
operator|>
name|MapGdbOptionNameToFnGdbOptionPtr_t
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
name|GetOptionFn
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrGdbOptionName
argument_list|,
name|FnGdbOptionPtr
operator|&
name|vrwpFn
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|OptionFnTargetAsync
argument_list|(
specifier|const
name|CMIUtilString
operator|::
name|VecString_t
operator|&
name|vrWords
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|OptionFnPrint
argument_list|(
specifier|const
name|CMIUtilString
operator|::
name|VecString_t
operator|&
name|vrWords
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|OptionFnLanguage
argument_list|(
specifier|const
name|CMIUtilString
operator|::
name|VecString_t
operator|&
name|vrWords
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|OptionFnFallback
argument_list|(
specifier|const
name|CMIUtilString
operator|::
name|VecString_t
operator|&
name|vrWords
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|MapGdbOptionNameToFnGdbOptionPtr_t
name|ms_mapGdbOptionNameToFnGdbOptionPtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrArgNamedGdbOption
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_bGdbOptionRecognised
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = This command has a function with a name that matches the Print argument, false = not found
end_comment

begin_decl_stmt
name|bool
name|m_bGdbOptionFnSuccessful
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = The print function completed its task ok, false = function failed for some reason
end_comment

begin_decl_stmt
name|bool
name|m_bGbbOptionFnHasError
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = The option function has an error condition (not the command!), false = option function ok.
end_comment

begin_decl_stmt
name|CMIUtilString
name|m_strGdbOptionName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|m_strGdbOptionFnError
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|m_strValue
decl_stmt|;
end_decl_stmt

unit|};
end_unit

