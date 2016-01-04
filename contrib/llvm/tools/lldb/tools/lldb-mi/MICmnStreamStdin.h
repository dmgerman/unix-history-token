begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnStreamStdin.h --------------------------------------*- C++ -*-===//
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
file|"MIUtilThreadBaseStd.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code class. Used to handle stream data from Stdin.
end_comment

begin_comment
comment|//          Singleton class using the Visitor pattern. A driver using the interface
end_comment

begin_comment
comment|//          provide can receive callbacks when a new line of data is received.
end_comment

begin_comment
comment|//          Each line is determined by a carriage return.
end_comment

begin_comment
comment|//          A singleton class.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnStreamStdin
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnStreamStdin
decl|>
block|{
comment|// Give singleton access to private constructors
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnStreamStdin
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
comment|//
specifier|const
name|CMIUtilString
operator|&
name|GetPrompt
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetPrompt
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vNewPrompt
parameter_list|)
function_decl|;
name|void
name|SetEnablePrompt
parameter_list|(
specifier|const
name|bool
name|vbYes
parameter_list|)
function_decl|;
name|bool
name|GetEnablePrompt
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|ReadLine
parameter_list|(
name|CMIUtilString
modifier|&
name|vwErrMsg
parameter_list|)
function_decl|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnStreamStdin
argument_list|()
expr_stmt|;
comment|/* ctor */
name|CMICmnStreamStdin
argument_list|(
specifier|const
name|CMICmnStreamStdin
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnStreamStdin
operator|&
operator|)
decl_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnStreamStdin
argument_list|()
name|override
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIUtilString
name|m_strPromptCurrent
decl_stmt|;
comment|// Command line prompt as shown to the user
name|bool
name|m_bShowPrompt
decl_stmt|;
comment|// True = Yes prompt is shown/output to the user (stdout), false = no prompt
specifier|static
specifier|const
name|int
name|m_constBufferSize
init|=
literal|2048
decl_stmt|;
name|char
modifier|*
name|m_pCmdBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

