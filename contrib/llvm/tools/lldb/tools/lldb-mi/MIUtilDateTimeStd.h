begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilDateTimeStd.h -------------------------------------*- C++ -*-===//
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
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<ctime>
end_include

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
comment|// Details: MI common code utility class. Used to retrieve system local date
end_comment

begin_comment
comment|//          time.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilDateTimeStd
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilDateTimeStd
argument_list|()
expr_stmt|;
name|CMIUtilString
name|GetDate
parameter_list|()
function_decl|;
name|CMIUtilString
name|GetTime
parameter_list|()
function_decl|;
name|CMIUtilString
name|GetDateTimeLogFilename
parameter_list|()
function_decl|;
comment|// Overrideable:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilDateTimeStd
argument_list|()
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|std
operator|::
name|time_t
name|m_rawTime
expr_stmt|;
name|char
name|m_pScratch
index|[
literal|16
index|]
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

