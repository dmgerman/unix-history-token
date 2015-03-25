begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdBase.h ---------------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdBase.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdBase interface.
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
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MICmnResources.h"
end_include

begin_include
include|#
directive|include
file|"MICmdInvoker.h"
end_include

begin_include
include|#
directive|include
file|"MICmdFactory.h"
end_include

begin_include
include|#
directive|include
file|"MICmdData.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIResultRecord.h"
end_include

begin_include
include|#
directive|include
file|"MICmdArgSet.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugSessionInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI command base class. MI commands derive from this base class.
end_comment

begin_comment
comment|//          The Command Factory creates command objects and passes them to the
end_comment

begin_comment
comment|//          Command Invoker. The Invoker takes ownersip of any commands created
end_comment

begin_comment
comment|//          which means it is the only object to delete them when a command is
end_comment

begin_comment
comment|//          finished working. Commands do not delete themselves.
end_comment

begin_comment
comment|//          There are two types of command implicitly defined by the state of
end_comment

begin_comment
comment|//          the m_bWaitForEventFromSBDebugger flag. There is the event type
end_comment

begin_comment
comment|//          command which registers (command fn) callbacks with the SBListener
end_comment

begin_comment
comment|//          does some work then wakes up again when called back, does more work
end_comment

begin_comment
comment|//          perhaps, ends, then the Invoker calls the command's Acknowledge
end_comment

begin_comment
comment|//          function. The other type of command is one that just does some work,
end_comment

begin_comment
comment|//          ends, then the Invoker calls the command's Acknowledge function. No
end_comment

begin_comment
comment|//          events set up.
end_comment

begin_comment
comment|//          A command's Execute(), Acknowledge() and event callback functions are
end_comment

begin_comment
comment|//          carried out in the main thread.
end_comment

begin_comment
comment|//          A command may use the argument derived object classes (CMICmdArgValBase)
end_comment

begin_comment
comment|//          to factor handling and parsing of different types of arguments
end_comment

begin_comment
comment|//          presented to a command. A command will produce an error should it
end_comment

begin_comment
comment|//          be presented with arguments or options it does not understand.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 18/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdBase
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMICmdInvoker
decl|::
name|ICmd
decl_stmt|,
name|public
name|CMICmdFactory
decl|::
name|ICmd
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMICmdBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmdInvoker::ICmd
name|virtual
specifier|const
name|SMICmdData
modifier|&
name|GetCmdData
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetErrorDescription
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|SetCmdData
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|)
function_decl|;
name|virtual
name|void
name|CmdFinishedTellInvoker
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetMIResultRecord
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetMIResultRecordExtra
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|HasMIResultRecordExtra
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|ParseArgs
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// From CMICmdFactory::ICmd
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetMiCmd
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|CMICmdFactory
operator|::
name|CmdCreatorFnPtr
name|GetCmdCreatorFn
argument_list|(
argument|void
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|MIuint
name|GetGUID
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Overrideable:
name|public
label|:
comment|/* dtor */
name|virtual
operator|~
name|CMICmdBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|virtual
name|bool
name|GetExitAppOnCommandFailure
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Methods:
name|protected
label|:
name|void
name|SetError
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|rErrMsg
parameter_list|)
function_decl|;
name|template
operator|<
name|class
name|T
operator|>
name|T
operator|*
name|GetOption
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vStrOptionName
argument_list|)
expr_stmt|;
name|bool
name|ParseValidateCmdOptions
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Attributes:
name|protected
label|:
name|CMICmdFactory
operator|::
name|CmdCreatorFnPtr
name|m_pSelfCreatorFn
expr_stmt|;
name|CMIUtilString
name|m_strCurrentErrDescription
decl_stmt|;
comment|// Reason for Execute or Acknowledge function failure
name|SMICmdData
name|m_cmdData
decl_stmt|;
comment|// Holds information/status of *this command. Used by other MI code to report or determine state of a command.
name|bool
name|m_bWaitForEventFromSBDebugger
decl_stmt|;
comment|// True = yes event type command wait, false = command calls Acknowledge() straight after Execute()
comment|// no waiting
name|CMIUtilString
name|m_strMiCmd
decl_stmt|;
comment|// The MI text identifying *this command i.e. 'break-insert'
name|CMICmnMIResultRecord
name|m_miResultRecord
decl_stmt|;
comment|// This is completed in the Acknowledge() function and returned to the Command Invoker to proceed
comment|// stdout output. Each command forms 1 response to its input.
name|CMIUtilString
name|m_miResultRecordExtra
decl_stmt|;
comment|// This is completed in the Acknowledge() function and returned to the Command Invoker to proceed
comment|// stdout output. Hack command produce more response text to help the client because of using LLDB
name|CMICmnLLDBDebugSessionInfo
modifier|&
name|m_rLLDBDebugSessionInfo
decl_stmt|;
comment|// Access to command sharing information or data across any and all command based derived classes.
name|bool
name|m_bHasResultRecordExtra
decl_stmt|;
comment|// True = Yes command produced additional MI output to its 1 line response, false = no extra MI output
comment|// formed.
name|CMICmdArgSet
name|m_setCmdArgs
decl_stmt|;
comment|// The list of arguments *this command needs to parse from the options string to carry out work.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Retrieve the command argument or option object pointer so that it can be
end_comment

begin_comment
comment|//          examined. If the option found and valid get the value (number, string or list
end_comment

begin_comment
comment|//          - see CMICmdArgValBase class) from it to use with the command's decision
end_comment

begin_comment
comment|//          making. If the argument is not found the command's error description is set
end_comment

begin_comment
comment|//          describing the error condition.
end_comment

begin_comment
comment|// Type:    Template method.
end_comment

begin_comment
comment|// Args:    vStrOptionName  - (R)   The text name of the argument or option to search for in
end_comment

begin_comment
comment|//                                  the list of the command's possible arguments or options.
end_comment

begin_comment
comment|// Return:  T * - CMICmdArgValBase derived object.
end_comment

begin_comment
comment|//              - NULL = function has failed, unable to retrieve the option/arg object.
end_comment

begin_comment
comment|// Throws:  None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|T
operator|*
name|CMICmdBase
operator|::
name|GetOption
argument_list|(
argument|const CMIUtilString&vStrOptionName
argument_list|)
block|{
name|CMICmdArgValBase
operator|*
name|pPtrBase
operator|=
name|nullptr
block|;
if|if
condition|(
operator|!
name|m_setCmdArgs
operator|.
name|GetArg
argument_list|(
name|vStrOptionName
argument_list|,
name|pPtrBase
argument_list|)
condition|)
block|{
name|SetError
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_CMD_ERR_OPTION_NOT_FOUND
argument_list|)
argument_list|,
name|m_cmdData
operator|.
name|strMiCmd
operator|.
name|c_str
argument_list|()
argument_list|,
name|vStrOptionName
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|nullptr
return|;
block|}
end_expr_stmt

begin_return
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|pPtrBase
operator|)
return|;
end_return

begin_comment
unit|}
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Retrieve the command argument or option object pointer using template function
end_comment

begin_comment
comment|//          CMICmdBase::GetOption(). Should the argument (by name) not be found the
end_comment

begin_comment
comment|//          command will exit with a failure (set in GetOption()).
end_comment

begin_comment
comment|// Type:    Preprocessor macro.
end_comment

begin_comment
comment|// Args:    a   - (R) The actual variable's name.
end_comment

begin_comment
comment|//          b   - (R) The type of variable (appended to CMICmdArgVal i.e. CMICmdArgValString).
end_comment

begin_comment
comment|//          c   - (R) The text name of the argument or option to search for in the list of
end_comment

begin_comment
comment|//                    the command's possible arguments or options.
end_comment

begin_comment
comment|// Return:  T * - CMICmdArgValBase derived object.
end_comment

begin_comment
comment|//              - NULL = function has failed, unable to retrieve the option/arg object.
end_comment

begin_comment
comment|// Throws:  None.
end_comment

begin_comment
comment|//--
end_comment

begin_define
define|#
directive|define
name|CMICMDBASE_GETOPTION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|CMICmdArgVal##b *a = CMICmdBase::GetOption<CMICmdArgVal##b>(c);                                                                        \     if (a == nullptr)                                                                                                                      \         return MIstatus::failure;
end_define

begin_comment
comment|// This comment is to stop compile warning for #define
end_comment

end_unit

