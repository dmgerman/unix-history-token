begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdInterpreter.h --------------------------------------*- C++ -*-===//
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
comment|// File:		MICmdInterpreter.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdInterpreter interface.
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
name|CMICmdFactory
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI command interpreter. It takes text data from the MI driver
end_comment

begin_comment
comment|//			(which got it from Stdin singleton) and validate the text to see if
end_comment

begin_comment
comment|//			matches Machine Interface (MI) format and commands defined in the
end_comment

begin_comment
comment|//			MI application.
end_comment

begin_comment
comment|//			A singleton class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 18/02/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdInterpreter
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmdInterpreter
decl|>
block|{
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmdInterpreter
operator|>
expr_stmt|;
comment|// Methods:
name|public
label|:
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
name|ValidateIsMi
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
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmdInterpreter
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmdInterpreter
argument_list|(
specifier|const
name|CMICmdInterpreter
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmdInterpreter
operator|&
operator|)
decl_stmt|;
name|bool
name|HasCmdFactoryGotMiCmd
argument_list|(
specifier|const
name|SMICmdData
operator|&
name|vCmdData
argument_list|)
decl|const
decl_stmt|;
name|bool
name|MiHasCmdTokenEndingHypthen
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|)
function_decl|;
name|bool
name|MiHasCmdTokenEndingAlpha
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|)
function_decl|;
name|bool
name|MiHasCmd
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|)
function_decl|;
name|bool
name|MiHasCmdTokenPresent
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vTextLine
parameter_list|)
function_decl|;
specifier|const
name|SMICmdData
operator|&
name|MiGetCmdData
argument_list|()
specifier|const
expr_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdInterpreter
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|SMICmdData
name|m_miCmdData
decl_stmt|;
comment|// Filled in on each new line being interpreted
name|CMICmdFactory
modifier|&
name|m_rCmdFactory
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

