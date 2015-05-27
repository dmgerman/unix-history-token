begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLogMediumFile.h ------------------------------------*- C++ -*-===//
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
comment|// File:        MICmnLogMediumFile.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnLogMediumFile interface.
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
file|"MIUtilFileStd.h"
end_include

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
file|"MICmnLog.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilDateTimeStd.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code implementation class. Logs application fn trace/message/
end_comment

begin_comment
comment|//          error messages to a file. Used as part of the CMICmnLog Logger
end_comment

begin_comment
comment|//          system. When instantiated *this object is register with the Logger
end_comment

begin_comment
comment|//          which the Logger when given data to write to registered medium comes
end_comment

begin_comment
comment|//          *this medium.
end_comment

begin_comment
comment|//          Singleton class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 30/01/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLogMediumFile
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|CMICmnLog
decl|::
name|IMedium
block|{
comment|// Statics:
name|public
label|:
specifier|static
name|CMICmnLogMediumFile
modifier|&
name|Instance
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Methods:
name|public
label|:
name|bool
name|SetHeaderTxt
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vText
parameter_list|)
function_decl|;
name|bool
name|SetVerbosity
parameter_list|(
specifier|const
name|MIuint
name|veType
parameter_list|)
function_decl|;
name|MIuint
name|GetVerbosity
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CMIUtilString
modifier|&
name|GetFileName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CMIUtilString
modifier|&
name|GetFileNamePath
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsOk
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsFileExist
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CMIUtilString
modifier|&
name|GetLineReturn
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnLogMediumFile
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// From CMICmnLog::IMedium
name|virtual
name|bool
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|Write
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vData
argument_list|,
specifier|const
name|CMICmnLog
operator|::
name|ELogVerbosity
name|veType
argument_list|)
decl_stmt|;
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetError
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|Shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLogMediumFile
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLogMediumFile
argument_list|(
specifier|const
name|CMICmnLogMediumFile
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmnLogMediumFile
operator|&
operator|)
decl_stmt|;
name|bool
name|FileWriteEnglish
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vData
parameter_list|)
function_decl|;
name|bool
name|FileFormFileNamePath
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|CMIUtilString
name|MassagedData
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vData
argument_list|,
specifier|const
name|CMICmnLog
operator|::
name|ELogVerbosity
name|veType
argument_list|)
decl_stmt|;
name|bool
name|FileWriteHeader
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|MIchar
name|ConvertLogVerbosityTypeToId
argument_list|(
specifier|const
name|CMICmnLog
operator|::
name|ELogVerbosity
name|veType
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|ConvertCr
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vData
argument_list|)
decl|const
decl_stmt|;
comment|// Attributes:
name|private
label|:
specifier|const
name|CMIUtilString
name|m_constThisMediumName
decl_stmt|;
specifier|const
name|CMIUtilString
name|m_constMediumFileName
decl_stmt|;
comment|//
name|CMIUtilString
name|m_fileNamePath
decl_stmt|;
name|MIuint
name|m_eVerbosityType
decl_stmt|;
name|CMIUtilString
name|m_strDate
decl_stmt|;
name|CMIUtilString
name|m_fileHeaderTxt
decl_stmt|;
name|CMIUtilFileStd
name|m_file
decl_stmt|;
name|CMIUtilDateTimeStd
name|m_dateTime
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

