begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilSystemWindows.h -----------------------------------*- C++ -*-===//
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
comment|// File:		MIUtilSystemWindows.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMIUtilSystemWindows interface.
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code utility class. Used to set or retrieve information
end_comment

begin_comment
comment|//			about the current system or user.
end_comment

begin_comment
comment|//			*** If you change, remove or add functionality it must be replicated
end_comment

begin_comment
comment|//			*** for the all platforms supported; Windows, OSX, LINUX
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 29/01/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilSystemWindows
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilSystemWindows
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|bool
name|GetOSErrorMsg
argument_list|(
specifier|const
name|MIint
name|vError
argument_list|,
name|CMIUtilString
operator|&
name|vrwErrorMsg
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetOSLastError
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetExecutablesPath
argument_list|(
name|CMIUtilString
operator|&
name|vrwFileNamePath
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetLogFilesPath
argument_list|(
name|CMIUtilString
operator|&
name|vrwFileNamePath
argument_list|)
decl|const
decl_stmt|;
comment|// Overrideable:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilSystemWindows
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|CMIUtilSystemWindows
name|CMIUtilSystem
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined( _MSC_VER )
end_comment

end_unit

