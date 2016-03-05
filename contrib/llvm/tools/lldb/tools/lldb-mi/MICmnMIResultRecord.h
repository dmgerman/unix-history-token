begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnMIResultRecord.h -----------------------------------*- C++ -*-===//
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
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueResult.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code MI Result Record class. A class that encapsulates
end_comment

begin_comment
comment|//          MI result record data and the forming/format of data added to it.
end_comment

begin_comment
comment|//          The syntax is as follows:
end_comment

begin_comment
comment|//          result-record ==>  [ token ] "^" result-class ( "," result )* nl
end_comment

begin_comment
comment|//          token = any sequence of digits
end_comment

begin_comment
comment|//          * = 0 to many
end_comment

begin_comment
comment|//          nl = CR | CR_LF
end_comment

begin_comment
comment|//          result-class ==> "done" | "running" | "connected" | "error" | "exit"
end_comment

begin_comment
comment|//          result ==> variable "=" value
end_comment

begin_comment
comment|//          value ==> const | tuple | list
end_comment

begin_comment
comment|//          const ==> c-string (7 bit iso c string content) i.e. "all" inc quotes
end_comment

begin_comment
comment|//          tuple ==>  "{}" | "{" result ( "," result )* "}"
end_comment

begin_comment
comment|//          list ==>  "[]" | "[" value ( "," value )* "]" | "[" result ( "," result )* "]"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          The result record can be retrieve at any time *this object is
end_comment

begin_comment
comment|//          instantiated so unless work is done on *this result record then it is
end_comment

begin_comment
comment|//          possible to return a malformed result record. If nothing has been set
end_comment

begin_comment
comment|//          or added to *this MI result record object then text "<Invalid>" will
end_comment

begin_comment
comment|//          be returned.
end_comment

begin_comment
comment|//          More information see:
end_comment

begin_comment
comment|//          http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnMIResultRecord
range|:
name|public
name|CMICmnBase
block|{
comment|// Enumerations:
name|public
operator|:
comment|//++
comment|// Details: Enumeration of the result class for *this result record
comment|//--
expr|enum
name|ResultClass_e
block|{
name|eResultClass_Done
operator|=
literal|0
block|,
name|eResultClass_Running
block|,
name|eResultClass_Connected
block|,
name|eResultClass_Error
block|,
name|eResultClass_Exit
block|}
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmnMIResultRecord
argument_list|()
block|;
comment|/* ctor */
name|CMICmnMIResultRecord
argument_list|(
argument|const CMIUtilString&vrToken
argument_list|,
argument|ResultClass_e veType
argument_list|)
block|;
comment|/* ctor */
name|CMICmnMIResultRecord
argument_list|(
argument|const CMIUtilString&vrToken
argument_list|,
argument|ResultClass_e veType
argument_list|,
argument|const CMICmnMIValueResult&vValue
argument_list|)
block|;
comment|//
specifier|const
name|CMIUtilString
operator|&
name|GetString
argument_list|()
specifier|const
block|;
name|void
name|Add
argument_list|(
specifier|const
name|CMICmnMIValue
operator|&
name|vMIValue
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnMIResultRecord
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|CMIUtilString
name|m_strResultRecord
block|;
comment|// Holds the text version of the result record to date
block|}
decl_stmt|;
end_decl_stmt

end_unit

