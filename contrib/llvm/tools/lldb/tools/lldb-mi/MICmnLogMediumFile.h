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
parameter_list|()
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
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetFileName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetFileNamePath
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsOk
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsFileExist
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetLineReturn
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetDirectory
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vPath
parameter_list|)
function_decl|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnLogMediumFile
argument_list|()
name|override
expr_stmt|;
comment|// From CMICmnLog::IMedium
name|bool
name|Initialize
argument_list|()
name|override
expr_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetName
argument_list|()
specifier|const
name|override
expr_stmt|;
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
name|override
decl_stmt|;
specifier|const
name|CMIUtilString
operator|&
name|GetError
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|Shutdown
argument_list|()
name|override
expr_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmnLogMediumFile
argument_list|()
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
parameter_list|()
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
parameter_list|()
function_decl|;
name|char
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
name|m_constMediumFileNameFormat
decl_stmt|;
comment|//
name|CMIUtilString
name|m_strMediumFileName
decl_stmt|;
name|CMIUtilString
name|m_strMediumFileDirectory
decl_stmt|;
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

