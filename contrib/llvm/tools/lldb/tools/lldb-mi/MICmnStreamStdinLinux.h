begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnStreamStdinWindows.h --------------------------------*- C++ -*-===//
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
comment|// File:		MIUtilStreamStdin.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnStreamStdinLinux interface.
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
file|"MICmnStreamStdin.h"
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
comment|// Details:	MI common code class. Specific OS stdin handling implementation.
end_comment

begin_comment
comment|//			CMICmnStreamStdin instance is set with stdin handler before using the
end_comment

begin_comment
comment|//			the stream. An instance of this class must be set up and ready to give
end_comment

begin_comment
comment|//			to the CMICmnStreamStdin before it initialises other CMICmnStreamStdin
end_comment

begin_comment
comment|//			will give an error.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 16/06/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnStreamStdinLinux
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMICmnStreamStdin
decl|::
name|IOSStdinHandler
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmnStreamStdinLinux
decl|>
block|{
comment|// Give singleton access to private constructors
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnStreamStdinLinux
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
comment|// Overridden:
name|public
label|:
comment|// From CMICmnStreamStdin::IOSpecificReadStreamStdin
name|virtual
name|bool
name|InputAvailable
parameter_list|(
name|bool
modifier|&
name|vwbAvail
parameter_list|)
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
function_decl|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnStreamStdinLinux
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnStreamStdinLinux
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
name|virtual
operator|~
name|CMICmnStreamStdinLinux
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
specifier|const
name|MIuint
name|m_constBufferSize
decl_stmt|;
name|FILE
modifier|*
name|m_pStdin
decl_stmt|;
name|MIchar
modifier|*
name|m_pCmdBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

