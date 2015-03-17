begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilStreamStdin.h -------------------------------------*- C++ -*-===//
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
comment|// File:        MIUtilStreamStdin.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnStreamStdin interface.
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
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 10/02/2014.
end_comment

begin_comment
comment|// Changes: Factored out OS specific handling of reading stdin  - IOR 16/06/2014.
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
name|CMIUtilThreadActiveObjBase
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
comment|// Class:
name|public
label|:
comment|//++
comment|// Description: Visitor pattern. Driver(s) use this interface to get a callback
comment|//              on each new line of data received from stdin.
comment|//--
name|class
name|IStreamStdin
block|{
name|public
label|:
name|virtual
name|bool
name|ReadLine
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vStdInBuffer
parameter_list|,
name|bool
modifier|&
name|vrwbYesExit
parameter_list|)
init|=
literal|0
function_decl|;
comment|/* dtor */
name|virtual
operator|~
name|IStreamStdin
argument_list|(
argument|void
argument_list|)
block|{}
expr_stmt|;
block|}
empty_stmt|;
comment|//++
comment|// Description: Specific OS stdin handling implementations are created and used by *this
comment|//              class. Seperates out functionality and enables handler to be set
comment|//              dynamically depended on the OS detected.
comment|//--
name|class
name|IOSStdinHandler
block|{
name|public
label|:
name|virtual
name|bool
name|InputAvailable
parameter_list|(
name|bool
modifier|&
name|vwbAvail
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
specifier|const
name|MIchar
modifier|*
name|ReadLine
parameter_list|(
name|CMIUtilString
modifier|&
name|vwErrMsg
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|InterruptReadLine
parameter_list|(
name|void
parameter_list|)
block|{}
empty_stmt|;
comment|/* dtor */
name|virtual
operator|~
name|IOSStdinHandler
argument_list|(
argument|void
argument_list|)
block|{}
expr_stmt|;
block|}
empty_stmt|;
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
comment|//
specifier|const
name|CMIUtilString
modifier|&
name|GetPrompt
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
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
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetCtrlCHit
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|SetVisitor
parameter_list|(
name|IStreamStdin
modifier|&
name|vrVisitor
parameter_list|)
function_decl|;
name|bool
name|SetOSStdinHandler
parameter_list|(
name|IOSStdinHandler
modifier|&
name|vrHandler
parameter_list|)
function_decl|;
name|void
name|OnExitHandler
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Overridden:
name|public
label|:
comment|// From CMIUtilThreadActiveObjBase
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|ThreadGetName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Overridden:
name|protected
label|:
comment|// From CMIUtilThreadActiveObjBase
name|virtual
name|bool
name|ThreadRun
parameter_list|(
name|bool
modifier|&
name|vrIsAlive
parameter_list|)
function_decl|;
name|virtual
name|bool
name|ThreadFinish
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Let this thread clean up after itself
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnStreamStdin
argument_list|(
name|void
argument_list|)
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
name|bool
name|MonitorStdin
parameter_list|(
name|bool
modifier|&
name|vrwbYesExit
parameter_list|)
function_decl|;
specifier|const
name|MIchar
modifier|*
name|ReadLine
parameter_list|(
name|CMIUtilString
modifier|&
name|vwErrMsg
parameter_list|)
function_decl|;
name|bool
name|InputAvailable
parameter_list|(
name|bool
modifier|&
name|vbAvail
parameter_list|)
function_decl|;
comment|// Bytes are available on stdin
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnStreamStdin
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
specifier|const
name|CMIUtilString
name|m_constStrThisThreadname
decl_stmt|;
name|IStreamStdin
modifier|*
name|m_pVisitor
decl_stmt|;
name|CMIUtilString
name|m_strPromptCurrent
decl_stmt|;
comment|// Command line prompt as shown to the user
specifier|volatile
name|bool
name|m_bKeyCtrlCHit
decl_stmt|;
comment|// True = User hit Ctrl-C, false = has not yet
name|bool
name|m_bShowPrompt
decl_stmt|;
comment|// True = Yes prompt is shown/output to the user (stdout), false = no prompt
name|bool
name|m_bRedrawPrompt
decl_stmt|;
comment|// True = Prompt needs to be redrawn
name|IOSStdinHandler
modifier|*
name|m_pStdinReadHandler
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

