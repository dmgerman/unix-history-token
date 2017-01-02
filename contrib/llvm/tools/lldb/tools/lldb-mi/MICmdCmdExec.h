begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdCmdExec.h ------------------------------------------*- C++ -*-===//
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
comment|// Overview:    CMICmdCmdExecRun                interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecContinue           interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecNext               interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecStep               interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecNextInstruction    interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecStepInstruction    interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecFinish             interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecInterrupt          interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecArguments          interface.
end_comment

begin_comment
comment|//              CMICmdCmdExecAbort              interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//              To implement new MI commands derive a new command class from the
end_comment

begin_comment
comment|//              command base
end_comment

begin_comment
comment|//              class. To enable the new command for interpretation add the new
end_comment

begin_comment
comment|//              command class
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
comment|//              For an introduction to adding a new command see
end_comment

begin_comment
comment|//              CMICmdCmdSupportInfoMiCmdQuery
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
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|"lldb/API/SBCommandReturnObject.h"
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
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-run".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecRun
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
name|CMICmdCmdExecRun
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
name|CMICmdCmdExecRun
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgStart
block|;
comment|// StopAtEntry - run to first
comment|// instruction or main() if specified
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-continue".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecContinue
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
name|CMICmdCmdExecContinue
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
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdExecContinue
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-next".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecNext
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
name|CMICmdCmdExecNext
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
name|CMICmdCmdExecNext
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNumber
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-step".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecStep
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
name|CMICmdCmdExecStep
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
name|CMICmdCmdExecStep
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNumber
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-next-instruction".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecNextInstruction
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
name|CMICmdCmdExecNextInstruction
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
name|CMICmdCmdExecNextInstruction
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNumber
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-step-instruction".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecStepInstruction
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
name|CMICmdCmdExecStepInstruction
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
name|CMICmdCmdExecStepInstruction
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|;
specifier|const
name|CMIUtilString
name|m_constStrArgNumber
block|;
comment|// Not specified in MI spec but
comment|// Eclipse gives this option
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-finish".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecFinish
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
name|CMICmdCmdExecFinish
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
name|CMICmdCmdExecFinish
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CODETAG_DEBUG_SESSION_RUNNING_PROG_RECEIVED_SIGINT_PAUSE_PROGRAM
end_comment

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-interrupt".
end_comment

begin_comment
comment|// Gotchas: Using Eclipse this command is injected into the command system when
end_comment

begin_comment
comment|// a
end_comment

begin_comment
comment|//          SIGINT signal is received while running an inferior program.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecInterrupt
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
name|CMICmdCmdExecInterrupt
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
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdExecInterrupt
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|lldb
operator|::
name|SBCommandReturnObject
name|m_lldbResult
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-arguments".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecArguments
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
name|CMICmdCmdExecArguments
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
name|CMICmdCmdExecArguments
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
specifier|const
name|CMIUtilString
name|m_constStrArgArguments
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI command class. MI commands derived from the command base class.
end_comment

begin_comment
comment|//          *this class implements MI command "exec-abort".
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdCmdExecAbort
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
name|CMICmdCmdExecAbort
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
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmdCmdExecAbort
argument_list|()
name|override
block|; }
decl_stmt|;
end_decl_stmt

end_unit

