begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnMIValue.h ------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code MI Result class. Part of the CMICmnMIValueRecord
end_comment

begin_comment
comment|//          set of objects.
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
comment|//          const ==> c-string (7 bit iso c string content)
end_comment

begin_comment
comment|//          tuple ==>  "{}" | "{" result ( "," result )* "}"
end_comment

begin_comment
comment|//          list ==>  "[]" | "[" value ( "," value )* "]" | "[" result ( "," result )* "]"
end_comment

begin_comment
comment|//          More information see:
end_comment

begin_comment
comment|//          http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 24/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnMIValue
range|:
name|public
name|CMICmnBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmnMIValue
argument_list|(
name|void
argument_list|)
block|;
comment|//
specifier|const
name|CMIUtilString
operator|&
name|GetString
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnMIValue
argument_list|(
argument|void
argument_list|)
name|override
block|;
comment|// Attributes:
name|protected
operator|:
name|CMIUtilString
name|m_strValue
block|;
name|bool
name|m_bJustConstructed
block|;
comment|// True = *this just constructed with no value, false = *this has had value added to it
block|}
decl_stmt|;
end_decl_stmt

end_unit

