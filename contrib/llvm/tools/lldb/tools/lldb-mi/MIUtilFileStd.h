begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilFileStd.h -----------------------------------------*- C++ -*-===//
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
comment|// File:		MIUtilFileStd.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMIUtilFileStd interface.
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
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code utility class. File handling.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Aidan Dodds 10/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilFileStd
range|:
name|public
name|CMICmnBase
block|{
comment|// Static:
name|public
operator|:
specifier|static
name|MIchar
name|GetSlash
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMIUtilFileStd
argument_list|(
name|void
argument_list|)
block|;
comment|//
name|bool
name|CreateWrite
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vFileNamePath
argument_list|,
name|bool
operator|&
name|vwrbNewCreated
argument_list|)
block|;
name|bool
name|Write
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vData
argument_list|)
block|;
name|bool
name|Write
argument_list|(
argument|const MIchar * vpData
argument_list|,
argument|const MIuint vCharCnt
argument_list|)
block|;
name|void
name|Close
argument_list|(
name|void
argument_list|)
block|;
name|bool
name|IsOk
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|bool
name|IsFileExist
argument_list|(
argument|const CMIUtilString& vFileNamePath
argument_list|)
specifier|const
block|;
specifier|const
name|CMIUtilString
operator|&
name|GetLineReturn
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|CMIUtilString
name|StripOffFileName
argument_list|(
argument|const CMIUtilString& vDirectoryPath
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilFileStd
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
name|CMIUtilString
name|m_fileNamePath
block|;
name|FILE
operator|*
name|m_pFileHandle
block|;
name|CMIUtilString
name|m_constCharNewLine
block|;
name|bool
name|m_bFileError
block|;
comment|// True = have a file error ATM, false = all ok
block|}
decl_stmt|;
end_decl_stmt

end_unit

