begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdMgr.h ----------------------------------------------*- C++ -*-===//
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
comment|// File:		MICmdMgr.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdMgr interface.
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
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<set>
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
file|"MICmdBase.h"
end_include

begin_include
include|#
directive|include
file|"MICmdMgrSetCmdDeleteCallback.h"
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
name|CMICmdInterpreter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmdFactory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmdInvoker
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMICmdBase
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command manager. Oversees command operations, controls command
end_comment

begin_comment
comment|//			production and the running of commands.
end_comment

begin_comment
comment|//			Command Invoker, Command Factory and Command Monitor while independant
end_comment

begin_comment
comment|//			units are overseen/managed by *this manager.
end_comment

begin_comment
comment|//			A singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 19/02/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdMgr
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmdMgr
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmdMgr
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
name|bool
name|CmdInterpret
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|,
name|bool
modifier|&
name|vwbYesValid
parameter_list|,
name|bool
modifier|&
name|vwbCmdNotInCmdFactor
parameter_list|,
name|SMICmdData
modifier|&
name|rwCmdData
parameter_list|)
function_decl|;
name|bool
name|CmdExecute
parameter_list|(
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|)
function_decl|;
name|bool
name|CmdDelete
parameter_list|(
name|SMICmdData
name|vCmdData
parameter_list|)
function_decl|;
name|bool
name|CmdRegisterForDeleteNotification
argument_list|(
name|CMICmdMgrSetCmdDeleteCallback
operator|::
name|ICallback
operator|&
name|vObject
argument_list|)
decl_stmt|;
name|bool
name|CmdUnregisterForDeleteNotification
argument_list|(
name|CMICmdMgrSetCmdDeleteCallback
operator|::
name|ICallback
operator|&
name|vObject
argument_list|)
decl_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmdMgr
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmdMgr
argument_list|(
specifier|const
name|CMICmdMgr
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmdMgr
operator|&
operator|)
decl_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdMgr
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMICmdInterpreter
modifier|&
name|m_interpretor
decl_stmt|;
name|CMICmdFactory
modifier|&
name|m_factory
decl_stmt|;
name|CMICmdInvoker
modifier|&
name|m_invoker
decl_stmt|;
name|CMICmdMgrSetCmdDeleteCallback
operator|::
name|CSetClients
name|m_setCmdDeleteCallback
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

