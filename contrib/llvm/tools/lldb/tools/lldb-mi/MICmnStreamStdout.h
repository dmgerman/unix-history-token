begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnStreamStdout.h -------------------------------------*- C++ -*-===//
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
comment|// File:        MICmnStreamStdout.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnStreamStdout interface.
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
file|"MIUtilThreadBaseStd.h"
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
comment|// Details: MI common code class. The MI driver requires this object.
end_comment

begin_comment
comment|//          CMICmnStreamStdout sets up and tears downs stdout for the driver.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          Singleton class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 12/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnStreamStdout
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnStreamStdout
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnStreamStdout
operator|>
expr_stmt|;
comment|// Statics:
name|public
label|:
specifier|static
name|bool
name|TextToStdout
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrTxt
parameter_list|)
function_decl|;
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
name|bool
name|Lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Write
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vText
parameter_list|,
specifier|const
name|bool
name|vbSendToLog
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|WriteMIResponse
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vText
parameter_list|,
specifier|const
name|bool
name|vbSendToLog
init|=
name|true
parameter_list|)
function_decl|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnStreamStdout
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnStreamStdout
argument_list|(
specifier|const
name|CMICmnStreamStdout
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnStreamStdout
operator|&
operator|)
decl_stmt|;
comment|//
name|bool
name|WritePriv
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vText
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vTxtForLogFile
parameter_list|,
specifier|const
name|bool
name|vbSendToLog
init|=
name|true
parameter_list|)
function_decl|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnStreamStdout
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIUtilThreadMutex
name|m_mutex
decl_stmt|;
comment|// Mutex object for sync during writing to stream
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

